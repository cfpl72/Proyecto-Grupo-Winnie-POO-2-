#include "pch.h"
#include "Controller.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace WinniePOO_Modelos;
using namespace Persistance;
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

    // ── SEED MEDICAMENTOS ────────────────────────────────────────────────────
    // Solo inserta datos si el archivo está vacío o no existe.
    // Llámalo en OperadorVentas_Load ANTES de ActualizarTablas().
    void ServicioMedicamentos::SeedMedicamentosDemo() {
        auto dic = ObtenerDiccionarioCompleto();
        if (dic->Count > 0) return; // ya hay datos, no hacer nada

        dic->Add(101, gcnew Medicamento(101, "Aspirina", "Acido Acetilsalicilico", 1.50, 200));
        dic->Add(102, gcnew Medicamento(102, "Panadol", "Paracetamol", 2.00, 150));
        dic->Add(103, gcnew Medicamento(103, "Amoxil", "Amoxicilina", 8.50, 50));
        dic->Add(104, gcnew Medicamento(104, "Ibuprofeno", "Ibuprofeno 400mg", 3.20, 120));
        dic->Add(105, gcnew Medicamento(105, "Loratadina", "Loratadina 10mg", 4.00, 80));

        repo->SaveMedicamentos(filePath, dic);
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
        auto dic = repo->LoadVentas(filePath);
        if (dic->ContainsKey(idVenta)) return false;

        Medicamento^ dummy = gcnew Medicamento(idMedicamento, "Temp", "", 0, 0);
        // FIX: DateTime::Now es un valor (DateTime), no un puntero (DateTime^).
        // El constructor de Venta recibe DateTime^, así que lo tomamos por dirección.
        DateTime ahora = DateTime::Now;
        Venta^ v = gcnew Venta(idVenta, idPaciente, cantidad, dummy, % ahora);

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

        return "=== BOLETA DE VENTA ===" +
            "\nVenta ID   : " + v->id +
            "\nPaciente   : " + v->idPaciente +
            "\nMedicamento: " + v->nombreMedicamento +
            "\nCantidad   : " + v->cantidadVendida +
            "\nPrecio Unit: S/ " + v->precioMedicamento.ToString("F2") +
            "\nTotal      : S/ " + v->totalVenta.ToString("F2");
    }

    // ── SEED VENTAS ──────────────────────────────────────────────────────────
    // Solo inserta datos si el archivo está vacío o no existe.
    // Llámalo en OperadorVentas_Load ANTES de ActualizarTablas().
    void ServicioVentas::SeedVentasDemo() {
        auto dic = repo->LoadVentas(filePath);
        if (dic->Count > 0) return; // ya hay datos, no hacer nada

        // Medicamentos dummy que coinciden con los IDs del seed de medicamentos
        Medicamento^ asp = gcnew Medicamento(101, "Aspirina", "Acido Acetilsalicilico", 1.50, 200);
        Medicamento^ pan = gcnew Medicamento(102, "Panadol", "Paracetamol", 2.00, 150);
        Medicamento^ amox = gcnew Medicamento(103, "Amoxil", "Amoxicilina", 8.50, 50);

        DateTime f1 = DateTime(2026, 5, 3, 14, 30, 0);
        DateTime f2 = DateTime(2026, 5, 3, 15, 10, 0);
        DateTime f3 = DateTime(2026, 5, 3, 15, 45, 0);

        dic->Add(5001, gcnew Venta(5001, 11111111, 2, asp, % f1));
        dic->Add(5002, gcnew Venta(5002, 22222222, 5, pan, % f2));
        dic->Add(5003, gcnew Venta(5003, 33333333, 1, amox, % f3));

        repo->SaveVentas(filePath, dic);
    }

    // =========================
    // HISTORIAL RECETAS
    // =========================
    String^ ServicioPacientes::GetHistorialPath(int idPaciente) {
        String^ folder = Environment::CurrentDirectory + "\\Repositorio_Historial_Recetas";
        if (!Directory::Exists(folder)) Directory::CreateDirectory(folder);
        return folder + "\\Historial_Recetas_" + idPaciente + ".txt";
    }

    void ServicioPacientes::RegistrarReceta(int idPaciente, int idReceta, int dosis,
        DateTime fecha, String^ nombreMedicamento, bool entregado) {
        String^ path = GetHistorialPath(idPaciente);
        repo->CrearHistorialSiNoExiste(path);
        repo->AppendReceta(path, idReceta, dosis, fecha, nombreMedicamento, entregado);
    }

    List<Receta^>^ ServicioPacientes::ObtenerHistorial(int idPaciente) {
        return repo->LoadHistorialRecetas(GetHistorialPath(idPaciente));
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
            if (r->idReceta != idReceta) nueva->Add(r);
        }
        repo->SaveHistorialRecetas(path, nueva);
    }

    List<String^>^ ServicioPacientes::ExaminarHistorialReceta(int idPaciente) {
        List<String^>^ resultado = gcnew List<String^>();
        auto lista = repo->LoadHistorialRecetas(GetHistorialPath(idPaciente));
        for each (Receta ^ r in lista) {
            String^ linea = "REC-" + r->idReceta.ToString("D3") + ", " +
                r->medicamento->nombre + ", " +
                r->dosis + " c/12h, " +
                r->fechaEmision.ToString("dd/MM/yyyy") + ", " +
                (r->entregado ? "Entregado" : "Pendiente");
            resultado->Add(linea);
        }
        return resultado;
    }

    List<String^>^ ServicioPacientes::ObtenerNombresPacientes() {
        List<String^>^ lista = gcnew List<String^>();
        auto dic = repo->LoadPacientes(filePath);
        for each (auto kv in dic) {
            Paciente^ p = kv.Value;
            lista->Add(p->nombre + " " + p->apellido);
        }
        return lista;
    }

    // =========================
    // AUTENTICACIÓN (LOGIN)
    // =========================
    bool ServicioAutenticacion::ValidarAcceso(String^ rol, String^ usuarioDNI, String^ password) {
        try {
            int dni = Convert::ToInt32(usuarioDNI);
            if (rol == "Paciente") {
                Paciente^ p = pacientesService->ObtenerPorId(dni);
                if (p != nullptr && p->verificationToken == password) return true;
            }
            else if (rol == "Operador de Ventas" || rol == "Farmaceutico") {
                if (usuarioDNI == "12345678" && password == "admin") return true;
            }
        }
        catch (FormatException^) { return false; }
        return false;
    }
}