#include "pch.h"
#include "Controller.h"


//=========================Requerimientos Servicio de Pacientes===========================================================//
Dictionary<int,Paciente^>^ Controller::ServicioPacientes::LeerTodos() { //Retorna una lista con todos los pacientes registrados

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

Paciente^ Controller::ServicioPacientes::ObtenerPorId(int id) {
    return repo->LeerPaciente(filePath, id);
}

void Controller::ServicioPacientes::Registrar(Paciente^ p) {

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

void Controller::ServicioPacientes::Modificar(int id, String^ atributo, String^ nuevoValor) {

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

void Controller::ServicioPacientes::Eliminar(int id) {

    Dictionary<int, Paciente^>^ diccionario = LeerTodos();

    if (diccionario->ContainsKey(id)) {
        diccionario->Remove(id);
    }

    repo->GuardarPacientes(filePath, diccionario);
}

bool Controller::ServicioPacientes::ValidarPaciente(Paciente^ p, String^% error) {

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



//=========================Requerimientos Servicio de Medicamentos===========================================================//
List<Medicamento^>^ Controller::ServicioMedicamentos::ObtenerInventarioCompleto() {
    Dictionary<int, Medicamento^>^ dic = ObtenerDiccionarioCompleto();
    List<Medicamento^>^ lista = gcnew List<Medicamento^>();

    for each (KeyValuePair<int, Medicamento^> kvp in dic) {
        lista->Add(kvp.Value);
    }

    return lista;
}

Dictionary<int, Medicamento^>^ Controller::ServicioMedicamentos::ObtenerDiccionarioCompleto() {
    Dictionary<int, Medicamento^>^ dic = repo->LeerMedicamentos("Medicamentos.txt");
    return dic;
} //Función para obtener el diccionario directamente

bool Controller::ServicioMedicamentos::ActualizarMedicamento(int id, double nuevoPrecio, int nuevoStock) {
    Dictionary<int, Medicamento^>^ dic = repo->LeerMedicamentos("Medicamentos.txt");

    if (!dic->ContainsKey(id)) return false;

    Medicamento^ m = dic[id];
    m->precio = nuevoPrecio;
    m->stock = nuevoStock;

    repo->GuardarMedicamentos(filePath, dic);
    return true;
}


//=========================Requerimientos Servicio de Ventas===========================================================//
bool Controller::ServicioVentas::RegistrarVenta(int idVenta, int idPaciente, int idMedicamento, int cantidad) {

    Controller::ServicioMedicamentos^ sm = gcnew Controller::ServicioMedicamentos("Medicamentos.txt");

    Dictionary<int, Venta^>^ dicVentas = repo->LeerVentas(filePath);
    Dictionary<int, Medicamento^>^ dicMed = sm->ObtenerDiccionarioCompleto();

    // =========================
    // VALIDACIONES
    // =========================

    if (dicVentas->ContainsKey(idVenta)) {
        Console::WriteLine("ERROR: Ya existe una venta con ese ID");
        return false;
    }

    if (!dicMed->ContainsKey(idMedicamento)) {
        Console::WriteLine("ERROR: Medicamento no encontrado");
        return false;
    }

    if (cantidad <= 0) {
        Console::WriteLine("ERROR: Cantidad inválida");
        return false;
    }

    Medicamento^ med = dicMed[idMedicamento];

    if (med->stock < cantidad) {
        Console::WriteLine("ERROR: Stock insuficiente");
        return false;
    }

    // =========================
    // ACTUALIZAR STOCK
    // =========================
    med->stock -= cantidad;

    // =========================
    // CREAR VENTA
    // =========================

    // 🔥 snapshot del medicamento
    Medicamento^ medSnapshot = gcnew Medicamento(
        med->id,
        med->nombre,
        med->principioActivo,
        med->precio,
        0
    );

    Venta^ nuevaVenta = gcnew Venta(
        idVenta,
        idPaciente,
        cantidad,
        medSnapshot,
        DateTime::Now
    );

    // =========================
    // GUARDAR
    // =========================

    dicVentas->Add(idVenta, nuevaVenta);

    repo->GuardarVentas(filePath, dicVentas);
    sm->ActualizarMedicamento(med->id, med->precio, med->stock);

    return true;
}

List<Venta^>^ Controller::ServicioVentas::ObtenerTodasLasVentas() {
    Dictionary<int, Venta^>^ dic = repo->LeerVentas(filePath);
    List<Venta^>^ lista = gcnew List<Venta^>();

    for each (KeyValuePair<int, Venta^> kvp in dic) {
        lista->Add(kvp.Value);
    }

    return lista;
}

//Elimina la venta y actualiza el stock del medicamento previamente vendido
bool Controller::ServicioVentas::EliminarVenta(int idVenta) {
    Controller::ServicioMedicamentos^ sm = gcnew Controller::ServicioMedicamentos("Medicamentos.txt");
    Dictionary<int, Venta^>^ diccionarioVen = repo->LeerVentas(filePath);
    Dictionary<int, Medicamento^>^ diccionarioMed = sm->ObtenerDiccionarioCompleto();

    if (diccionarioVen->ContainsKey(idVenta)) {
        Venta^ venta = diccionarioVen[idVenta];
        

        //Se actualiza el stock del nuevo medicamento en la base de datos
        int idMed = venta->idMedicamento;
        double nuevoPrecio = venta->precioMedicamento;
        int nuevoStock = diccionarioMed[idMed]->stock + venta->cantidadVendida; //Devuelve la cantidad vendida al stock del medicamento

        sm->ActualizarMedicamento(idMed, nuevoPrecio, nuevoStock);
        diccionarioVen->Remove(idVenta);
        repo->GuardarVentas(filePath, diccionarioVen);
        return true;
    }
    else {
        Console::WriteLine("ERROR: ID no encontrado.");
        return false;
    }

    
}

bool Controller::ServicioVentas::ModificarVenta(int idVenta, int nuevaCantidadVendida) {
    Controller::ServicioMedicamentos^ sm = gcnew Controller::ServicioMedicamentos("Medicamentos.txt");
    Dictionary<int, Venta^>^ diccionarioVen = repo->LeerVentas(filePath);
    Dictionary<int, Medicamento^>^ diccionarioMed = sm->ObtenerDiccionarioCompleto();
    
    if (!diccionarioVen->ContainsKey(idVenta)) {
        Console::WriteLine("ERROR: No se encontró ID de la venta específicada");
        return false;
    }

    //Se duplica el puntero
    Venta^ venta = diccionarioVen[idVenta];
    int antiguaCantidadVendida = venta->cantidadVendida;
    int diferenciaCantidades = nuevaCantidadVendida - antiguaCantidadVendida;

    //Se modifica la cantidad Vendida
    if (nuevaCantidadVendida <= 0) {
        Console::WriteLine("ERROR: la nueva cantidad vendida no puede ser menor a 0");
        return false;
    }
    venta->cantidadVendida = nuevaCantidadVendida;
    venta->totalVenta = venta->totalVenta + (diferenciaCantidades * venta->precioMedicamento);

    //Se ajustan los atributos del medicamento especificado

    if (!diccionarioMed->ContainsKey(venta->idMedicamento)) {
        Console::WriteLine("ERROR: ID del medicamento no está registrado en la base de datos");
        return false;
    }

    Medicamento^ med = diccionarioMed[venta->idMedicamento];
    int nuevoStock = med->stock - (diferenciaCantidades);

    if (nuevoStock < 0) {
        Console::WriteLine("ERROR: El nuevo stock es inválido (<0)");
        return false;
    }

    med->stock = nuevoStock;

    //Se sube a la persistencia los cambios incorporados   
    repo->GuardarVentas("Ventas.txt", diccionarioVen);
    sm->ActualizarMedicamento(med->id, med->precio, med->stock);
    return true;
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



