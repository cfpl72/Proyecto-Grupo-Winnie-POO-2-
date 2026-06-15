#include "pch.h"
#include "Controller.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;

namespace Controller {

    // =========================
    // PACIENTES
    // =========================
    Dictionary<int, Paciente^>^ ServicioPacientes::LeerTodos() {
        return repo->LoadPacientes(filePath);
    }

    Paciente^ ServicioPacientes::ObtenerPorId(int id) {
        auto dic = LeerTodos();
        return dic->ContainsKey(id) ? dic[id] : nullptr;
    }

    bool ServicioPacientes::RegistrarPaciente(int id, String^ token, String^ nombre,
        String^ apellido, int edad, String^ alergias, String^ sintomas) {
        auto dic = LeerTodos();
        if (dic->ContainsKey(id)) return false;
        Paciente^ p = gcnew Paciente(id, token);
        p->nombre = nombre;
        p->apellido = apellido;
        p->edad = edad;
        p->alergias = alergias;
        p->sintomas = sintomas;
        dic->Add(id, p);
        repo->SavePacientes(filePath, dic);
        return true;
    }

    void ServicioPacientes::ModificarPaciente(int id, String^ atributo, String^ nuevoValor) {
        auto dic = LeerTodos();
        if (!dic->ContainsKey(id)) return;
        Paciente^ p = dic[id];
        if (atributo == "nombre")   p->nombre = nuevoValor;
        else if (atributo == "apellido") p->apellido = nuevoValor;
        else if (atributo == "edad")     p->edad = Convert::ToInt32(nuevoValor);
        else if (atributo == "alergias") p->alergias = nuevoValor;
        else if (atributo == "sintomas") p->sintomas = nuevoValor;
        repo->SavePacientes(filePath, dic);
    }

    void ServicioPacientes::EliminarPaciente(int id) {
        auto dic = LeerTodos();
        if (dic->ContainsKey(id)) {
            dic->Remove(id);
            repo->SavePacientes(filePath, dic);
        }
    }

    List<String^>^ ServicioPacientes::ObtenerNombresPacientes() {
        auto dic = LeerTodos();
        List<String^>^ nombres = gcnew List<String^>();
        for each (auto kv in dic)
            nombres->Add(kv.Value->nombre + " " + kv.Value->apellido);
        return nombres;
    }

    // =========================
    // MEDICAMENTOS
    // =========================
    Dictionary<int, Medicamento^>^ ServicioMedicamentos::ObtenerDiccionarioCompleto() {
        return repo->LoadMedicamentos(filePath);
    }

    List<Medicamento^>^ ServicioMedicamentos::ObtenerInventarioCompleto() {
        auto dic = ObtenerDiccionarioCompleto();
        List<Medicamento^>^ lista = gcnew List<Medicamento^>();
        for each (auto kv in dic)
            lista->Add(kv.Value);
        return lista;
    }

    bool ServicioMedicamentos::RegistrarMedicamento(int id, String^ nombre,
        String^ principioActivo, double precio, int stock) {
        auto dic = ObtenerDiccionarioCompleto();
        if (dic->ContainsKey(id)) return false;
        Medicamento^ m = gcnew Medicamento(id, nombre, principioActivo, precio, stock);
        dic->Add(id, m);
        repo->SaveMedicamentos(filePath, dic);
        return true;
    }

    bool ServicioMedicamentos::ActualizarMedicamento(int id, double nuevoPrecio, int nuevoStock) {
        auto dic = ObtenerDiccionarioCompleto();
        if (!dic->ContainsKey(id)) return false;
        Medicamento^ m = dic[id];
        m->ActualizarPrecio(nuevoPrecio);
        m->ActualizarStock(nuevoStock);
        repo->SaveMedicamentos(filePath, dic);
        return true;
    }

    bool ServicioMedicamentos::EliminarMedicamento(int id) {
        auto dic = ObtenerDiccionarioCompleto();
        if (!dic->ContainsKey(id)) return false;
        dic->Remove(id);
        repo->SaveMedicamentos(filePath, dic);
        return true;
    }

    // =========================
    // VENTAS
    // =========================
    List<Venta^>^ ServicioVentas::ObtenerTodasLasVentas() {
        auto dic = repo->LoadVentas(filePath);
        List<Venta^>^ lista = gcnew List<Venta^>();
        for each (auto kv in dic)
            lista->Add(kv.Value);
        return lista;
    }

    Venta^ ServicioVentas::LeerVenta(int idVenta) {
        auto dic = repo->LoadVentas(filePath);
        return dic->ContainsKey(idVenta) ? dic[idVenta] : nullptr;
    }

    // FIX: Descuenta stock del medicamento al registrar la venta.
    bool ServicioVentas::RegistrarVenta(int idVenta, int idPaciente, int idMedicamento, int cantidad) {
        // Verificar que la venta no exista ya
        auto dicVentas = repo->LoadVentas(filePath);
        if (dicVentas->ContainsKey(idVenta)) return false;

        // Obtener datos reales del medicamento
        ServicioMedicamentos^ servMed = gcnew ServicioMedicamentos();
        auto dicMed = servMed->ObtenerDiccionarioCompleto();
        if (!dicMed->ContainsKey(idMedicamento)) return false;

        Medicamento^ med = dicMed[idMedicamento];

        // Verificar stock suficiente
        if (med->stock < cantidad) return false;

        // Crear la venta con datos reales del medicamento
        Venta^ v = gcnew Venta(
            idVenta,
            idPaciente,
            cantidad,
            idMedicamento,
            med->precio,
            med->nombre,
            DateTime::Now
        );
        dicVentas->Add(idVenta, v);
        repo->SaveVentas(filePath, dicVentas);

        // Descontar stock
        med->ActualizarStock(med->stock - cantidad);
        servMed->ActualizarMedicamento(idMedicamento, med->precio, med->stock);

        return true;
    }

    bool ServicioVentas::ModificarVenta(int idVenta, int nuevaCantidadVendida) {
        auto dic = repo->LoadVentas(filePath);
        if (!dic->ContainsKey(idVenta)) return false;

        Venta^ v = dic[idVenta];
        int diferencia = nuevaCantidadVendida - v->cantidadVendida;

        // Verificar stock si se aumenta la cantidad
        if (diferencia > 0) {
            ServicioMedicamentos^ servMed = gcnew ServicioMedicamentos();
            auto dicMed = servMed->ObtenerDiccionarioCompleto();
            if (!dicMed->ContainsKey(v->idMedicamento)) return false;
            Medicamento^ med = dicMed[v->idMedicamento];
            if (med->stock < diferencia) return false;
            // Ajustar stock
            servMed->ActualizarMedicamento(v->idMedicamento, med->precio, med->stock - diferencia);
        }
        else if (diferencia < 0) {
            // Devolver stock
            ServicioMedicamentos^ servMed = gcnew ServicioMedicamentos();
            auto dicMed = servMed->ObtenerDiccionarioCompleto();
            if (dicMed->ContainsKey(v->idMedicamento)) {
                Medicamento^ med = dicMed[v->idMedicamento];
                servMed->ActualizarMedicamento(v->idMedicamento, med->precio, med->stock + (-diferencia));
            }
        }

        v->cantidadVendida = nuevaCantidadVendida;
        v->totalVenta = v->precioMedicamento * nuevaCantidadVendida;
        repo->SaveVentas(filePath, dic);
        return true;
    }

    // FIX: Al eliminar la venta, se devuelve el stock al medicamento.
    bool ServicioVentas::EliminarVenta(int idVenta) {
        auto dic = repo->LoadVentas(filePath);
        if (!dic->ContainsKey(idVenta)) return false;

        Venta^ v = dic[idVenta];

        // Devolver stock
        ServicioMedicamentos^ servMed = gcnew ServicioMedicamentos();
        auto dicMed = servMed->ObtenerDiccionarioCompleto();
        if (dicMed->ContainsKey(v->idMedicamento)) {
            Medicamento^ med = dicMed[v->idMedicamento];
            servMed->ActualizarMedicamento(v->idMedicamento, med->precio, med->stock + v->cantidadVendida);
        }

        dic->Remove(idVenta);
        repo->SaveVentas(filePath, dic);
        return true;
    }

    String^ ServicioVentas::MostrarBoletaVenta(int idVenta) {
        Venta^ v = LeerVenta(idVenta);
        if (v == nullptr) return "Venta no encontrada.";
        return "=== BOLETA DE VENTA ===" +
            "\nVenta ID     : " + v->id.ToString() +
            "\nPaciente ID  : " + v->idPaciente.ToString() +
            "\nMedicamento  : " + v->nombreMedicamento +
            "\nCantidad     : " + v->cantidadVendida.ToString() +
            "\nPrecio Unit. : S/. " + v->precioMedicamento.ToString("F2") +
            "\nTOTAL        : S/. " + v->totalVenta.ToString("F2") +
            "\nFecha        : " + v->fecha->ToString("dd/MM/yyyy HH:mm");
    }

    // =========================
    // HISTORIAL RECETAS
    // =========================
    String^ ServicioPacientes::GetHistorialPath(int idPaciente) {
        String^ basePath = Environment::CurrentDirectory;
        String^ folder = basePath + "\\Repositorio_Historial_Recetas";
        if (!Directory::Exists(folder))
            Directory::CreateDirectory(folder);
        return folder + "\\Historial_Recetas_" + idPaciente.ToString() + ".txt";
    }

    void ServicioPacientes::RegistrarReceta(int idPaciente, int idReceta, int dosis,
        DateTime fecha, String^ nombreMedicamento, bool entregado) {
        String^ path = GetHistorialPath(idPaciente);
        repo->CrearHistorialSiNoExiste(path);
        repo->AppendReceta(path, idReceta, dosis, fecha, nombreMedicamento, entregado);
    }

    List<Receta^>^ ServicioPacientes::ObtenerHistorial(int idPaciente) {
        String^ path = GetHistorialPath(idPaciente);
        return repo->LoadHistorialRecetas(path);
    }

    void ServicioPacientes::ModificarReceta(int idPaciente, int idReceta,
        int nuevaDosis, bool nuevoEstado) {
        String^ path = GetHistorialPath(idPaciente);
        auto lista = repo->LoadHistorialRecetas(path);
        for each (Receta ^ r in lista) {
            if (r->idReceta == idReceta) {
                r->dosis = nuevaDosis;
                r->entregado = nuevoEstado;
            }
        }
        repo->SaveHistorialRecetas(path, lista);
    }

    void ServicioPacientes::EliminarReceta(int idPaciente, int idReceta) {
        String^ path = GetHistorialPath(idPaciente);
        auto lista = repo->LoadHistorialRecetas(path);
        List<Receta^>^ nueva = gcnew List<Receta^>();
        for each (Receta ^ r in lista) {
            if (r->idReceta != idReceta)
                nueva->Add(r);
        }
        repo->SaveHistorialRecetas(path, nueva);
    }

    List<String^>^ ServicioPacientes::ExaminarHistorialReceta(int idPaciente) {
        List<String^>^ resultado = gcnew List<String^>();
        String^ path = GetHistorialPath(idPaciente);
        auto lista = repo->LoadHistorialRecetas(path);
        for each (Receta ^ r in lista) {
            String^ idFmt = "REC-" + r->idReceta.ToString("D3");
            String^ medicamento = r->medicamento->nombre;
            String^ dosis = r->dosis.ToString() + " c/12h";
            String^ fecha = r->fechaEmision.ToString("dd/MM/yyyy");
            String^ estado = r->entregado ? "Entregado" : "Pendiente";
            resultado->Add(idFmt + ", " + medicamento + ", " + dosis + ", " + fecha + ", " + estado);
        }
        return resultado;
    }

    // =========================
    // AUTENTICACION
    // FIX: credenciales separadas por rol; Operador: 12345678/operador, Farmaceutico: 87654321/farmaceutico
    // =========================
    bool ServicioAutenticacion::ValidarAcceso(String^ rol, String^ usuarioDNI, String^ password) {
        try {
            if (rol == "Paciente") {
                int dni = Convert::ToInt32(usuarioDNI);
                Paciente^ p = pacientesService->ObtenerPorId(dni);
                // El token almacenado es la contraseña tal como la ingresó en el registro
                if (p != nullptr && p->verificationToken == password)
                    return true;
            }
            else if (rol == "Operador de Ventas") {
                if (usuarioDNI == "12345678" && password == "operador")
                    return true;
            }
            else if (rol->StartsWith("Farmac")) {   // evita problemas de encoding con la é
                if (usuarioDNI == "87654321" && password == "farma")
                    return true;
            }
        }
        catch (FormatException^) {
            return false;
        }
        return false;
    }

} // FIN DEL NAMESPACE CONTROLLER