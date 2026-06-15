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

        if (atributo == "nombre") p->nombre = nuevoValor;
        else if (atributo == "apellido") p->apellido = nuevoValor;
        else if (atributo == "edad") p->edad = Convert::ToInt32(nuevoValor);
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

    bool ServicioVentas::RegistrarVenta(int idVenta, int idPaciente, int idMedicamento, int cantidad) {

        Controller::ServicioMedicamentos^ servMedicamentos = gcnew ServicioMedicamentos();

        auto dic = repo->LoadVentas(filePath);

        if (dic->ContainsKey(idVenta)) return false;

        // Medicamento dummy (por dependencia del constructor)
        Dictionary<int, Medicamento^>^ dummyDic = servMedicamentos->ObtenerDiccionarioCompleto();

        Venta^ v = gcnew Venta(idVenta, idPaciente, cantidad, idMedicamento, 1, "Paracetamol", DateTime::Now);

        dic->Add(idVenta, v);
        repo->SaveVentas(filePath, dic);

        return true;
    }

    bool ServicioVentas::ModificarVenta(int idVenta, int nuevaCantidadVendida) {
        auto dic = repo->LoadVentas(filePath);

        if (!dic->ContainsKey(idVenta)) return false;

        Venta^ v = dic[idVenta];
        v->cantidadVendida = nuevaCantidadVendida;
        v->totalVenta = v->precioMedicamento * nuevaCantidadVendida;

        repo->SaveVentas(filePath, dic);
        return true;
    }

    bool ServicioVentas::EliminarVenta(int idVenta) {
        auto dic = repo->LoadVentas(filePath);

        if (dic->ContainsKey(idVenta)) {
            dic->Remove(idVenta);
            repo->SaveVentas(filePath, dic);
            return true;
        }

        return false;
    }

    String^ ServicioVentas::MostrarBoletaVenta(int idVenta) {
        Venta^ v = LeerVenta(idVenta);

        if (v == nullptr) return "Venta no encontrada.";

        return "Venta ID: " + v->id +
            "\nPaciente: " + v->idPaciente +
            "\nMedicamento: " + v->nombreMedicamento +
            "\nCantidad: " + v->cantidadVendida +
            "\nTotal: " + v->totalVenta;
    }


    // =========================
    // HISTORIAL RECETAS
    // =========================

    // Helper para ruta
    String^ ServicioPacientes::GetHistorialPath(int idPaciente) {

        String^ basePath = Environment::CurrentDirectory;

        String^ folder = basePath + "\\Repositorio_Historial_Recetas";

        // Crear carpeta si no existe
        if (!Directory::Exists(folder)) {
            Directory::CreateDirectory(folder);
        }

        return folder + "\\Historial_Recetas_" + idPaciente + ".txt";
    }

    // CREATE
    void ServicioPacientes::RegistrarReceta(int idPaciente, int idReceta, int dosis,
        DateTime fecha, String^ nombreMedicamento, bool entregado) {

        String^ path = GetHistorialPath(idPaciente);

        repo->CrearHistorialSiNoExiste(path);
        repo->AppendReceta(path, idReceta, dosis, fecha, nombreMedicamento, entregado);
    }

    // READ
    List<Receta^>^ ServicioPacientes::ObtenerHistorial(int idPaciente) {
        String^ path = GetHistorialPath(idPaciente);
        return repo->LoadHistorialRecetas(path);
    }

    // UPDATE
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

    // DELETE
    void ServicioPacientes::EliminarReceta(int idPaciente, int idReceta) {

        String^ path = GetHistorialPath(idPaciente);
        auto lista = repo->LoadHistorialRecetas(path);

        List<Receta^>^ nueva = gcnew List<Receta^>();

        for each (Receta ^ r in lista) {
            if (r->idReceta != idReceta) {
                nueva->Add(r);
            }
        }

        repo->SaveHistorialRecetas(path, nueva);
    }

    // Funciones Personalizadas

    List<String^>^ ServicioPacientes::ExaminarHistorialReceta(int idPaciente) {

        List<String^>^ resultado = gcnew List<String^>();

        String^ path = GetHistorialPath(idPaciente);

        auto lista = repo->LoadHistorialRecetas(path);

        for each (Receta ^ r in lista) {

            // Formato ID tipo REC-001
            String^ idFormateado = "REC-" + r->idReceta.ToString("D3");

            // Medicamento
            String^ medicamento = r->medicamento->nombre;
           
            // Dosis (simplificada)
            String^ dosis = r->dosis + " c/12h";

            // Fecha
            String^ fecha = r->fechaEmision.ToString("dd/MM/yyyy");

            // Estado
            String^ estado = r->entregado ? "Entregado" : "Pendiente";

            // Línea final
            String^ linea = idFormateado + ", " +
                medicamento + ", " +
                dosis + ", " +
                fecha + ", " +
                estado;

            resultado->Add(linea);
        }

        return resultado;
    }
    List<String^>^ ServicioPacientes::ObtenerNombresPacientes() {

        List<String^>^ lista = gcnew List<String^>();

        auto dic = repo->LoadPacientes(filePath);

        for each (auto kv in dic) {
            Paciente^ p = kv.Value;


            String^ nombre = p->nombre + " " + p->apellido;

            lista->Add(nombre);
        }

        return lista;
    }

    // =========================
    // AUTENTICACIÓN (LOGIN)
    // =========================
    bool ServicioAutenticacion::ValidarAcceso(String^ rol, String^ usuarioDNI, String^ password) {
        try {
            // Convertimos el DNI de String a entero
            int dni = Convert::ToInt32(usuarioDNI);

            if (rol == "Paciente") {
                // Buscamos al paciente por su DNI
                Paciente^ p = pacientesService->ObtenerPorId(dni);

                // Si existe y la contraseña (token) coincide, damos luz verde
                if (p != nullptr && p->verificationToken == password) {
                    return true;
                }
            }
            else if (rol == "Operador de Ventas" || rol == "Farmacéutico") {
                // Como no hay .txt para Operador y Farmacéutico,
                // he creado un usuario para que puedas hacer pruebas.
                // Podrás entrar a estos roles con DNI: 12345678 y Contraseña: admin
                if (usuarioDNI == "12345678" && password == "admin") {
                    return true;
                }
            }
        }
        catch (FormatException^) {
            // Si el usuario escribe letras en lugar de números en el DNI, falla limpiamente
            return false;
        }

        return false; // Si nada coincide, acceso denegado
    }
}

namespace Controller1 {

    using namespace WinniePOO_Modelos1;
    using namespace Persistance1;

    // =========================
    // PACIENTES
    // =========================

    Dictionary<int, Paciente^>^ ServicioPacientes::LeerTodos() {
        return repo->GetAllPacientes();
    }

    Paciente^ ServicioPacientes::ObtenerPorId(int id) {
        return repo->GetPacienteById(id);
    }

    bool ServicioPacientes::RegistrarPaciente(int id, String^ token, String^ nombre,
        String^ apellido, int edad, String^ alergias, String^ sintomas) {

        // Verificación directa en BD
        if (repo->GetPacienteById(id) != nullptr)
            return false;

        Paciente^ p = gcnew Paciente(id, token);
        p->nombre = nombre;
        p->apellido = apellido;
        p->edad = edad;
        p->alergias = alergias;
        p->sintomas = sintomas;

        return repo->InsertPaciente(p);
    }

    void ServicioPacientes::ModificarPaciente(int id, String^ atributo, String^ nuevoValor) {

        Paciente^ p = repo->GetPacienteById(id);

        if (p == nullptr) return;

        if (atributo == "nombre") p->nombre = nuevoValor;
        else if (atributo == "apellido") p->apellido = nuevoValor;
        else if (atributo == "edad") p->edad = Convert::ToInt32(nuevoValor);
        else if (atributo == "alergias") p->alergias = nuevoValor;
        else if (atributo == "sintomas") p->sintomas = nuevoValor;

        repo->UpdatePaciente(p);
    }

    void ServicioPacientes::EliminarPaciente(int id) {
        repo->DeletePaciente(id);
    }

    // =========================
    // MEDICAMENTOS
    // =========================
    Dictionary<int, Medicamento^>^ ServicioMedicamentos::ObtenerDiccionarioCompleto() {
        return repo->GetAllMedicamentos();
    }

    List<Medicamento^>^ ServicioMedicamentos::ObtenerInventarioCompleto() {
        auto dic = repo->GetAllMedicamentos();
        List<Medicamento^>^ lista = gcnew List<Medicamento^>();

        for each (auto kv in dic)
            lista->Add(kv.Value);

        return lista;
    }

    bool ServicioMedicamentos::RegistrarMedicamento(int id, String^ nombre,
        String^ principioActivo, double precio, int stock) {

        if (repo->GetMedicamentoById(id) != nullptr)
            return false;

        Medicamento^ m = gcnew Medicamento(id, nombre, principioActivo, precio, stock);

        return repo->InsertMedicamento(m);
    }

    bool ServicioMedicamentos::ActualizarMedicamento(int id, double nuevoPrecio, int nuevoStock) {

        Medicamento^ m = repo->GetMedicamentoById(id);

        if (m == nullptr) return false;

        m->ActualizarPrecio(nuevoPrecio);
        m->ActualizarStock(nuevoStock);

        return repo->UpdateMedicamento(id, nuevoPrecio, nuevoStock);
    }

    bool ServicioMedicamentos::EliminarMedicamento(int id) {
        return repo->DeleteMedicamento(id);
    }

    // =========================
    // VENTAS
    // =========================
    List<Venta^>^ ServicioVentas::ObtenerTodasLasVentas() {

        auto dic = repo->GetAllVentas();
        List<Venta^>^ lista = gcnew List<Venta^>();

        for each (auto kv in dic)
            lista->Add(kv.Value);

        return lista;
    }

    Venta^ ServicioVentas::LeerVenta(int idVenta) {
        return repo->GetVentaById(idVenta);
    }

    bool ServicioVentas::RegistrarVenta(int idVenta, int idPaciente, int idMedicamento, int cantidad) {

        Controller1::ServicioMedicamentos^ servMed = gcnew ServicioMedicamentos();

        // ❌ Ya no usamos diccionario de ventas
        if (repo->GetVentaById(idVenta) != nullptr)
            return false;

        // Obtener medicamento real
        auto dicMed = servMed->ObtenerDiccionarioCompleto();

        if (!dicMed->ContainsKey(idMedicamento))
            return false;

        Medicamento^ med = dicMed[idMedicamento];

        // Validar stock
        if (med->stock < cantidad)
            return false;

        // Crear venta con nuevo modelo
        Venta^ v = gcnew Venta(
            idVenta,
            idPaciente,
            cantidad,
            idMedicamento,
            med->precio,
            med->nombre,
            DateTime::Now
        );

        // Guardar en SQL
        bool ok = repo->InsertVenta(v);

        if (!ok) return false;

        // Actualizar stock
        servMed->ActualizarMedicamento(
            idMedicamento,
            med->precio,
            med->stock - cantidad
        );

        return true;
    }

    bool ServicioVentas::ModificarVenta(int idVenta, int nuevaCantidadVendida) {

        Venta^ v = repo->GetVentaById(idVenta);

        if (v == nullptr) return false;

        v->cantidadVendida = nuevaCantidadVendida;
        v->totalVenta = v->precioMedicamento * nuevaCantidadVendida;

        // ⚠️ No tienes UPDATE en SQL aún → solo lógico
        Console::WriteLine("⚠ Modificación local (no persistida en SQL)");

        return true;
    }

    bool ServicioVentas::EliminarVenta(int idVenta) {
        return repo->DeleteVenta(idVenta);
    }

    String^ ServicioVentas::MostrarBoletaVenta(int idVenta) {
        Venta^ v = LeerVenta(idVenta);

        if (v == nullptr) return "Venta no encontrada.";

        return "Venta ID: " + v->id +
            "\nPaciente: " + v->idPaciente +
            "\nMedicamento: " + v->nombreMedicamento +
            "\nCantidad: " + v->cantidadVendida +
            "\nTotal: " + v->totalVenta;
    }


    // =========================
    // HISTORIAL RECETAS
    // =========================

    // Helper para ruta
    String^ ServicioPacientes::GetHistorialPath(int idPaciente) {

        String^ basePath = Environment::CurrentDirectory;

        String^ folder = basePath + "\\Repositorio_Historial_Recetas";

        // Crear carpeta si no existe
        if (!Directory::Exists(folder)) {
            Directory::CreateDirectory(folder);
        }

        return folder + "\\Historial_Recetas_" + idPaciente + ".txt";
    }

    void ServicioPacientes::RegistrarReceta(int idPaciente, int idReceta, int idMedicamento, int dosis, DateTime fecha, bool entregado) {
        repo->InsertReceta(idReceta, idPaciente, idMedicamento, dosis, fecha, entregado);
    }

    List<Receta^>^ ServicioPacientes::ObtenerHistorial(int idPaciente) {
        List<Receta^>^ lista = repo->GetAllRecetas();
        List<Receta^>^ filtrado = gcnew List<Receta^>();
        for each (Receta ^ r in lista) {
            if (r->idPaciente == idPaciente) {
                filtrado->Add(r);
            }
        }
        return filtrado;
    }

    void ServicioPacientes::ModificarReceta(int idReceta, int nuevaDosis, bool nuevoEstado) {
        Receta^ r = repo->GetRecetaById(idReceta);
        if (r == nullptr)return;
        r->dosis = nuevaDosis;
        if (nuevoEstado)repo->MarcarRecetaComoEntregada(idReceta);
    }

    void ServicioPacientes::EliminarReceta(int idReceta) {
        repo->DeleteReceta(idReceta);
    }

    List<String^>^ ServicioPacientes::ExaminarHistorialReceta(int idPaciente) {
        List<String^>^ resultado = gcnew List<String^>();
        auto lista = repo->GetAllRecetas();
        for each (Receta ^ r in lista) {
            if (r->idPaciente != idPaciente)continue;
            String^ idFormateado = "REC-" + r->idReceta.ToString("D3");
            String^ medicamento = "MED-" + r->idMedicamento.ToString();
            String^ dosis = r->dosis + " c/12h";
            String^ fecha = r->fechaEmision.ToString("dd/MM/yyyy");
            String^ estado = r->entregado ? "Entregado" : "Pendiente";
            String^ linea = idFormateado + ", " + medicamento + ", " + dosis + ", " + fecha + ", " + estado;
            resultado->Add(linea);
        }
        return resultado;
    }

    List<String^>^ ServicioPacientes::ObtenerNombresPacientes() {
        List<String^>^ lista = gcnew List<String^>();
        auto dic = repo->GetAllPacientes();
        for each (auto kv in dic) {
            Paciente^ p = kv.Value;
            String^ nombre = p->nombre + " " + p->apellido;
            lista->Add(nombre);
        }
        return lista;
    }

    // =========================
    // AUTENTICACIÓN (LOGIN)
    // =========================
    bool ServicioAutenticacion::ValidarAcceso(String^ rol, String^ usuarioDNI, String^ password) {
        try {
            // Convertimos el DNI de String a entero
            int dni = Convert::ToInt32(usuarioDNI);

            if (rol == "Paciente") {
                // Buscamos al paciente por su DNI
                Paciente^ p = pacientesService->ObtenerPorId(dni);

                // Si existe y la contraseña (token) coincide, damos luz verde
                if (p != nullptr && p->verificationToken == password) {
                    return true;
                }
            }
            else if (rol == "Operador de Ventas" || rol == "Farmacéutico") {
                // Como no hay .txt para Operador y Farmacéutico,
                // he creado un usuario para que puedas hacer pruebas.
                // Podrás entrar a estos roles con DNI: 12345678 y Contraseña: admin
                if (usuarioDNI == "12345678" && password == "admin") {
                    return true;
                }
            }
        }
        catch (FormatException^) {
            // Si el usuario escribe letras en lugar de números en el DNI, falla limpiamente
            return false;
        }

        return false; // Si nada coincide, acceso denegado
    }
}