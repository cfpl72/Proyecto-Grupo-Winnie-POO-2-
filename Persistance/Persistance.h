#pragma once
using namespace WinniePOO_Modelos;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Xml::Serialization;
using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace System::IO;

namespace Persistance {
	public ref class persistance
	{
	public:
		static bool exists(String^ filePath);

		static void RegistrarPaciente(String^ filePath, Paciente^ p);
		static void ModificarPaciente(String^ filePath, int idPaciente, String^ opAtributo, String^ nuevoValor);
		String^ Persistance::persistance::LeerPaciente(String^ filePath, int idPaciente);
		void Persistance::persistance::EliminarPaciente(String^ filePath, int idPaciente);

		static void RegistrarMedicamento(String^ filePath, Medicamento^ med);

		static void RegistrarVenta(String^ filePath, Venta^ v);


		/*
		static Object^ LoadDataFromText(String^ filePath, Type^ tipo);

		static void SaveDataToXML(String^ filePath, Object^ ObjectData);
		static Object^ LoadDataFromXML(String^ filePath, Type^ tipo);

		static void SaveDataToBinary(String^ filePath, Object^ ObjectData);
		static Object^ LoadDataFromBinary(String^ filePath, Type^ tipo);
		*/


	};
}
