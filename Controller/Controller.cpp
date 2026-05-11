#include "pch.h"
#include "Controller.h"



Dictionary<int,Paciente^>^ Controller::PacienteController::LeerTodos() { //Retorna una lista con todos los pacientes registrados

    Dictionary<int, Paciente^>^ dic = gcnew Dictionary<int,Paciente^ > ();
    array<String^>^ lineas = File::ReadAllLines(filePath);

    for each (String ^ linea in lineas) {

        array<String^>^ campos = linea->Split('|');

        for (int i = 0; i < campos->Length; i++)
            campos[i] = campos[i]->Trim();

        if (campos[0] == "PACIENTE") {

            Paciente^ p = gcnew Paciente(Int32::Parse(campos[1]), campos[2]);

            p->nombre = campos[3];
            p->apellido = campos[4];
            p->edad = Int32::Parse(campos[5]);
            p->alergias = campos[6];
            p->sintomas = campos[7];

            dic->Add(p->id, p);
        }
    }

    return dic;
}

Paciente^ Controller::PacienteController::ObtenerPorId(int id) {
    return repo->LeerPaciente(filePath, id);
}

void Controller::PacienteController::Registrar(Paciente^ p) {

    if (p == nullptr) return;

    Dictionary<int, Paciente^>^ dic = LeerTodos();

    // Validación del paciente
    String^ error;

    if (!ValidarPaciente(p, error)) {
        Console::WriteLine("Error: " + error);
        return;
    }

    // Agregar al diccionario
    dic->Add(p->id, p);

    // Guardar TODO el estado actualizado
    repo->GuardarPacientes(filePath, dic);
}

void Controller::PacienteController::Modificar(int id, String^ atributo, String^ nuevoValor) {

    Dictionary<int, Paciente^>^ dic = LeerTodos();

    if (!dic->ContainsKey(id)) return;

    Paciente^ p = dic[id];

    if (atributo == "nombre") p->nombre = nuevoValor;
    else if (atributo == "apellido") p->apellido = nuevoValor;
    else if (atributo == "edad") p->edad = Int32::Parse(nuevoValor);
    else if (atributo == "alergias") p->alergias = nuevoValor;
    else if (atributo == "sintomas") p->sintomas = nuevoValor;

    repo->GuardarPacientes(filePath, dic);
}

void Controller::PacienteController::Eliminar(int id) {

    Dictionary<int, Paciente^>^ diccionario = LeerTodos();

    if (diccionario->ContainsKey(id)) {
        diccionario->Remove(id);
    }

    repo->GuardarPacientes(filePath, diccionario);
}

bool Controller::PacienteController::ValidarPaciente(Paciente^ p, String^% error) {

    if (p == nullptr) {
        error = "Paciente nulo";
        return false;
    }

    if (p->id <= 0) {
        error = "ID inválido";
        return false;
    }

    if (String::IsNullOrWhiteSpace(p->nombre)) {
        error = "Nombre vacío";
        return false;
    }

    if (p->edad < 0) {
        error = "Edad inválida";
        return false;
    }

    return true;
}

//=========================Requerimientos Operador de Ventas===========================================================//
List<Medicamento^>^ Controller::OperadorDeVentasController::ObtenerInventarioCompleto() {
    Dictionary<int, Medicamento^>^ dic = repo->LeerMedicamentos("Medicamentos.txt");
    List<Medicamento^>^ lista = gcnew List<Medicamento^>();
    for each (KeyValuePair<int, Medicamento^> kvp in dic) {
        lista->Add(kvp.Value);
    }
    return lista;
} 
//Función Testeada (Requerimiento para cargar tablas)

List<Venta^>^ Controller::OperadorDeVentasController::ObtenerTodasLasVentas() {
    Dictionary<int, Venta^>^ dic = repo->LeerVentas("Ventas.txt");
    List<Venta^>^ lista = gcnew List<Venta^>();
    for each (KeyValuePair<int, Venta^> kvp in dic) {
        lista->Add(kvp.Value);
    }
    return lista;
} 
//Función Testeada (Requerimiento para cargar tablas)

bool Controller::OperadorDeVentasController::BotonActualizar(int id, double nuevoPrecio, int nuevoStock) {
    Dictionary<int, Medicamento^>^ dic = repo->LeerMedicamentos("Medicamentos.txt");

    if (!dic->ContainsKey(id)) {
		Console::WriteLine("Error: No se encontró el medicamento con ID " + id);
        return false;
    }

    Medicamento^ m = dic[id];

    m->precio = nuevoPrecio;
    m->stock = nuevoStock;

    repo->GuardarMedicamentos("Medicamentos.txt", dic);
	Console::WriteLine("Medicamento con ID " + id + " actualizado: Precio = " + nuevoPrecio + ", Stock = " + nuevoStock);
    return true;
};
//Función Testeada (Requerimiento para actualizar precio y stock desde la tabla)


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



