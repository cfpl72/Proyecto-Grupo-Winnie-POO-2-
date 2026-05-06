#include "pch.h"
#include "Persistance.h"


bool Persistance::persistance::exists(String^ filePath) {
	return File::Exists(filePath);
}


//=======================Métodos del registro de Pacientes================================
void Persistance::persistance::RegistrarPaciente(String^ filePath, Paciente^ p) {

    FileStream^ fileStream = nullptr;
    StreamWriter^ writer = nullptr;

    try {
        fileStream = gcnew FileStream(filePath, FileMode::Append, FileAccess::Write);
        writer = gcnew StreamWriter(fileStream);

        writer->WriteLine("PACIENTE|{0}|{1}|{2}|{3}|{4}|{5}|{6}",
            p->id,
            p->verificationToken,
            p->nombre,
            p->apellido,
            p->edad,
            p->alergias,
            p->sintomas
        );
    }
    catch (Exception^ ex) {
        Console::WriteLine("Error saving paciente: " + ex->Message);
    }
    finally {
        if (writer != nullptr) writer->Close();
        if (fileStream != nullptr) fileStream->Close();
    }
}
void Persistance::persistance::GuardarPacientes(String^ filePath, Dictionary<int, Paciente^>^ diccionario) {

    List<String^>^ lineas = gcnew List<String^>();

    for each (KeyValuePair<int, Paciente^> kvp in diccionario) {

        Paciente^ p = kvp.Value;

        lineas->Add(String::Format("PACIENTE|{0}|{1}|{2}|{3}|{4}|{5}|{6}",
            p->id,
            p->verificationToken,
            p->nombre,
            p->apellido,
            p->edad,
            p->alergias,
            p->sintomas
        ));
    }

    File::WriteAllLines(filePath, lineas->ToArray());
}
Paciente^ Persistance::persistance::LeerPaciente(String^ filePath, int idPaciente) {
    array<String^>^ lineas = File::ReadAllLines(filePath);

    for each(String ^ linea in lineas) {
        array<String^>^ campos = linea->Split('|');

        for (int i = 0; i < campos->Length; i++)
            campos[i] = campos[i]->Trim();

        if (campos[0] == "PACIENTE" && Int32::Parse(campos[1]) == idPaciente) {

            Paciente^ p = gcnew Paciente(Int32::Parse(campos[1]), campos[2]);

            p->nombre = campos[3];
            p->apellido = campos[4];
            p->edad = Int32::Parse(campos[5]);
            p->alergias = campos[6];
            p->sintomas = campos[7];

            return p;
        }
    }

    return nullptr;
}
void Persistance::persistance::EliminarPaciente(String^ filePath, int idPaciente) {

    try {
        array<String^>^ lineas = File::ReadAllLines(filePath);

        List<String^>^ nuevasLineas = gcnew List<String^>();

        for (int i = 0; i < lineas->Length; i++) {

            array<String^>^ campos = lineas[i]->Split('|');

            // Limpiar espacios
            for (int j = 0; j < campos->Length; j++) {
                campos[j] = campos[j]->Trim();
            }

            // Si NO es el paciente, lo conservamos
            if (Int32::Parse(campos[1]) != idPaciente) {
                nuevasLineas->Add(lineas[i]);
            }
        }

        // Sobrescribir archivo sin el paciente eliminado
        File::WriteAllLines(filePath, nuevasLineas->ToArray());
    }
    catch (Exception^ ex) {
        Console::WriteLine("Error al eliminar paciente: " + ex->Message);
    }
}

// ================= MEDICAMENTOS =================
void Persistance::persistance::GuardarMedicamentos(String^ filePath, Dictionary<int, Medicamento^>^ diccionario) {

    List<String^>^ lineas = gcnew List<String^>();

    for each (KeyValuePair<int, Medicamento^> kvp in diccionario) {

        Medicamento^ m = kvp.Value;

        lineas->Add(String::Format("MEDICAMENTO|{0}|{1}|{2}|{3}|{4}",
            m->idMedicamento,
            m->nombre,
            m->precio,
            m->stock,
            m->principioActivo
        ));
    }

    File::WriteAllLines(filePath, lineas->ToArray());
}
Dictionary<int, Medicamento^>^ Persistance::persistance::LeerMedicamentos(String^ filePath) {

    Dictionary<int, Medicamento^>^ dic = gcnew Dictionary<int, Medicamento^>();

    if (!File::Exists(filePath)) return dic;

    array<String^>^ lineas = File::ReadAllLines(filePath);

    for each (String ^ linea in lineas) {

        array<String^>^ campos = linea->Split('|');

        for (int i = 0; i < campos->Length; i++)
            campos[i] = campos[i]->Trim();

        if (campos[0] == "MEDICAMENTO") {

            int id = Int32::Parse(campos[1]);
            String^ nombre = campos[2];
            double precio = Double::Parse(campos[3]);
            int stock = Int32::Parse(campos[4]);
            String^ principio = campos[5];

            Medicamento^ m = gcnew Medicamento(id, nombre, principio, precio, stock);

            dic->Add(id, m);
        }
    }

    return dic;
}

// ================= VENTAS =================
void Persistance::persistance::GuardarVentas(String^ filePath, Dictionary<int, Venta^>^ diccionario) {

    List<String^>^ lineas = gcnew List<String^>();

    for each (KeyValuePair<int, Venta^> kvp in diccionario) {

        Venta^ v = kvp.Value;

        lineas->Add(String::Format("VENTA|{0}|{1}|{2}|{3}|{4}",
            v->id,
            v->idPaciente,
            v->idMedicamento,
            v->cantidadVendida,
            v->fecha->ToString("yyyy-MM-dd")
        ));
    }

    File::WriteAllLines(filePath, lineas->ToArray());
}
Dictionary<int, Venta^>^ Persistance::persistance::LeerVentas(String^ filePath) {

    Dictionary<int, Venta^>^ dic = gcnew Dictionary<int, Venta^>();

    if (!File::Exists(filePath)) return dic;

    array<String^>^ lineas = File::ReadAllLines(filePath);

    for each (String ^ linea in lineas) {

        array<String^>^ campos = linea->Split('|');

        for (int i = 0; i < campos->Length; i++)
            campos[i] = campos[i]->Trim();

        if (campos[0] == "VENTA") {

            int id = Int32::Parse(campos[1]);
            int idPaciente = Int32::Parse(campos[2]);
            int idMedicamento = Int32::Parse(campos[3]);
            int cantidad = Int32::Parse(campos[4]);
            DateTime fecha = DateTime::Parse(campos[5]);

            // ⚠️ IMPORTANTE: aquí no tienes el objeto Medicamento completo
            // así que creamos uno dummy (esto es una limitación del diseño actual)

            Medicamento^ dummy = gcnew Medicamento(idMedicamento, "N/A", "N/A", 0, 0);

            Venta^ v = gcnew Venta(id, idPaciente, cantidad, fecha, dummy);

            dic->Add(id, v);
        }
    }

    return dic;
}