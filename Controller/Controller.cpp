#include "pch.h"
#include "Controller.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace WinniePOO_Modelos;
using namespace Persistance;

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

        auto dic = repo->LoadVentas(filePath);

        if (dic->ContainsKey(idVenta)) return false;

        // Medicamento dummy (por dependencia del constructor)
        Medicamento^ dummy = gcnew Medicamento(idMedicamento, "Temp", "", 0, 0);

        Venta^ v = gcnew Venta(idVenta, idPaciente, cantidad, dummy, DateTime::Now);

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

}
/*bool Controller::OperadorDeVentasController::Modificar(int id, String^ atributo, String^ nuevoValor) {
    Dictionary<int, Medicamento^>^ dic = repo->LeerMedicamentos("Medicamentos.txt");

    if (!dic->ContainsKey(id)) return false;

    Medicamento^ m = dic[id];

    if (atributo == "nombre") m->nombre = nuevoValor;
    else if (atributo == "precio") m->precio = Convert::ToDouble(nuevoValor);
    else if (atributo == "principio activo") m->principioActivo = nuevoValor;
    else if (atributo == "alergias") m->stock = Convert::ToInt32(nuevoValor);

    repo->GuardarMedicamentos("Medicamentos.txt", dic);
    return true;
};*/
//Función modificar provisional 



/*bool Controller::OperadorDeVentasController::Modificar(int id, String^ atributo, String^ nuevoValor) {
    Dictionary<int, Medicamento^>^ dic = repo->LeerMedicamentos("Medicamentos.txt");

    if (!dic->ContainsKey(id)) return false;

    Medicamento^ m = dic[id];

    if (atributo == "nombre") m->nombre = nuevoValor;
    else if (atributo == "precio") m->precio = Convert::ToDouble(nuevoValor);
    else if (atributo == "principio activo") m->principioActivo = nuevoValor;
    else if (atributo == "alergias") m->stock = Convert::ToInt32(nuevoValor);

    repo->GuardarMedicamentos("Medicamentos.txt", dic);
    return true;
};*/
//Función modificar provisional 



/*bool Controller::OperadorDeVentasController::Modificar(int id, String^ atributo, String^ nuevoValor) {
    Dictionary<int, Medicamento^>^ dic = repo->LeerMedicamentos("Medicamentos.txt");

    if (!dic->ContainsKey(id)) return false;

    Medicamento^ m = dic[id];

    if (atributo == "nombre") m->nombre = nuevoValor;
    else if (atributo == "precio") m->precio = Convert::ToDouble(nuevoValor);
    else if (atributo == "principio activo") m->principioActivo = nuevoValor;
    else if (atributo == "alergias") m->stock = Convert::ToInt32(nuevoValor);

    repo->GuardarMedicamentos("Medicamentos.txt", dic);
    return true;
};*/
//Función modificar provisional 



/*bool Controller::OperadorDeVentasController::Modificar(int id, String^ atributo, String^ nuevoValor) {
    Dictionary<int, Medicamento^>^ dic = repo->LeerMedicamentos("Medicamentos.txt");

    if (!dic->ContainsKey(id)) return false;

    Medicamento^ m = dic[id];

    if (atributo == "nombre") m->nombre = nuevoValor;
    else if (atributo == "precio") m->precio = Convert::ToDouble(nuevoValor);
    else if (atributo == "principio activo") m->principioActivo = nuevoValor;
    else if (atributo == "alergias") m->stock = Convert::ToInt32(nuevoValor);

    repo->GuardarMedicamentos("Medicamentos.txt", dic);
    return true;
};*/
//Función modificar provisional 



/*bool Controller::OperadorDeVentasController::Modificar(int id, String^ atributo, String^ nuevoValor) {
    Dictionary<int, Medicamento^>^ dic = repo->LeerMedicamentos("Medicamentos.txt");

    if (!dic->ContainsKey(id)) return false;

    Medicamento^ m = dic[id];

    if (atributo == "nombre") m->nombre = nuevoValor;
    else if (atributo == "precio") m->precio = Convert::ToDouble(nuevoValor);
    else if (atributo == "principio activo") m->principioActivo = nuevoValor;
    else if (atributo == "alergias") m->stock = Convert::ToInt32(nuevoValor);

    repo->GuardarMedicamentos("Medicamentos.txt", dic);
    return true;
};*/
//Función modificar provisional 



