#include "pch.h"
#include "Persistance.h"


bool Persistance::persistance::exists(String^ filePath) {
	return File::Exists(filePath);
}

void Persistance::persistance::SaveDataToText(String^ filePath, Object^ ObjectData) {
	
	//Inicializa los objetos necesarios para la gestión de archivos de texto. fileStream lee y writer modifica
	FileStream^ fileStream = nullptr;
	StreamWriter^ writer = nullptr;

	try {
		fileStream = gcnew FileStream(filePath, FileMode::Create, FileAccess::Write); //Inicializa el objeto en RAM
		writer = gcnew StreamWriter(fileStream);

		//========================Guardar PACIENTE========================================================
		if (ObjectData != nullptr && ObjectData->GetType() == Paciente::typeid) {
			Paciente^ p = (Paciente^)ObjectData;

			writer->WriteLine("{0}|{1}|{2}|{3}|{4}|{5}|{6}",
				p->id,
				p->verificationToken,
				p->nombre,
				p->apellido,
				p->edad,
				p->alergias,
				p->sintomas
			);
		}

		//========================Guardar MEDICAMENTO========================================================
		else if (ObjectData != nullptr && ObjectData->GetType() == Medicamento::typeid) {
			Medicamento^ med = (Medicamento^)ObjectData;

			writer->WriteLine("{0}|{1}|{2}|{3}|{4}",
				med->idMedicamento,
				med->nombre,
				med->precio,
				med->stock,
				med->principioActivo
			);
		}

		//========================Guardar VENTA========================================================
		Venta^ v = dynamic_cast<Venta^>(ObjectData);
		if (v != nullptr) {

			writer->WriteLine("{0}|{1}|{2}|{3}|{4}|{5}",
				"VENTA",
				v->id,
				v->idPaciente,
				v->idMedicamento,
				v->cantidadVendida,
				v->fecha->ToString("yyyy-MM-dd")
			);
		}

	}
	catch (Exception^ ex) { //Manejo del error en caso de una excepción
		Console::WriteLine("Error saving data: " + ex->Message);
	}
	finally { //Código que se ejecuta sí o sí
		if (writer != nullptr) {
			writer->Close();
		}
		if (fileStream != nullptr) {
			fileStream->Close();
		}
	}


}

