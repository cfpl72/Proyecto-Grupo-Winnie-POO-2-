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
void Persistance::persistance::ModificarPaciente(String^ filePath, int idPaciente, String^ opAtributo, String^ nuevoValor) {

    try {
        // Leer todas las líneas del archivo
        array<String^>^ lineas = File::ReadAllLines(filePath);

        for (int i = 0; i < lineas->Length; i++) {
            array<String^>^ campos = lineas[i]->Split('|');

            // Limpiar espacios por si acaso
            for (int j = 0; j < campos->Length; j++) {
                campos[j] = campos[j]->Trim();
            }

            // Verificar si es el paciente buscado
            if (Int32::Parse(campos[0]) == idPaciente) {

                // Según el atributo, modificar el campo correspondiente
                if (opAtributo == "verificationToken") campos[1] = nuevoValor;
                else if (opAtributo == "nombre") campos[2] = nuevoValor;
                else if (opAtributo == "apellido") campos[3] = nuevoValor;
                else if (opAtributo == "edad") campos[4] = nuevoValor;
                else if (opAtributo == "Alergias") campos[5] = nuevoValor;
                else if (opAtributo == "Fiebre") campos[6] = nuevoValor;

                // Reconstruir la línea
                lineas[i] = String::Join(" | ", campos);

                break; // ya encontramos y modificamos
            }
        }

        // Sobrescribir el archivo completo
        File::WriteAllLines(filePath, lineas);
    }
    catch (Exception^ ex) {
        Console::WriteLine("Error al modificar paciente: " + ex->Message);
    }
}
String^ Persistance::persistance::LeerPaciente(String^ filePath, int idPaciente) {

    try {
        array<String^>^ lineas = File::ReadAllLines(filePath);

        for (int i = 0; i < lineas->Length; i++) {

            array<String^>^ campos = lineas[i]->Split('|');

            // Limpiar espacios
            for (int j = 0; j < campos->Length; j++) {
                campos[j] = campos[j]->Trim();
            }

            // Comparar como número (más seguro)
            if (Int32::Parse(campos[0]) == idPaciente) {
                return lineas[i];
            }
        }

        // Si no se encuentra
        return nullptr;
    }
    catch (Exception^ ex) {
        Console::WriteLine("Error al leer paciente: " + ex->Message);
        return nullptr;
    }
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
            if (Int32::Parse(campos[0]) != idPaciente) {
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

//=======================Métodos del registro de Medicamentos================================
void Persistance::persistance::RegistrarMedicamento(String^ filePath, Medicamento^ med) {

    FileStream^ fileStream = nullptr;
    StreamWriter^ writer = nullptr;

    try {
        fileStream = gcnew FileStream(filePath, FileMode::Append, FileAccess::Write);
        writer = gcnew StreamWriter(fileStream);

        writer->WriteLine("MEDICAMENTO|{0}|{1}|{2}|{3}|{4}",
            med->idMedicamento,
            med->nombre,
            med->precio,
            med->stock,
            med->principioActivo
        );
    }
    catch (Exception^ ex) {
        Console::WriteLine("Error saving medicamento: " + ex->Message);
    }
    finally {
        if (writer != nullptr) writer->Close();
        if (fileStream != nullptr) fileStream->Close();
    }
}


//=======================Métodos del registro de Ventas================================
void Persistance::persistance::RegistrarVenta(String^ filePath, Venta^ v) {

    FileStream^ fileStream = nullptr;
    StreamWriter^ writer = nullptr;

    try {
        fileStream = gcnew FileStream(filePath, FileMode::Append, FileAccess::Write);
        writer = gcnew StreamWriter(fileStream);

        writer->WriteLine("VENTA|{0}|{1}|{2}|{3}|{4}|{5}",
            v->id,
            v->idPaciente,
            v->idMedicamento,
            v->cantidadVendida,
            v->fecha->ToString("yyyy-MM-dd")
        );
    }
    catch (Exception^ ex) {
        Console::WriteLine("Error saving venta: " + ex->Message);
    }
    finally {
        if (writer != nullptr) writer->Close();
        if (fileStream != nullptr) fileStream->Close();
    }
}