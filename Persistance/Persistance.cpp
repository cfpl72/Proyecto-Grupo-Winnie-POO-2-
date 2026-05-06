#include "pch.h"
#include "Persistance.h"


bool Persistance::persistance::exists(String^ filePath) {
	return File::Exists(filePath);
}

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