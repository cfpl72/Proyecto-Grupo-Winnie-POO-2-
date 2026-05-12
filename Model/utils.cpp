#include "pch.h"
#include "utils.h"
using namespace System;
using namespace System::Security::Cryptography;

String^ WinniePOO_Modelos::Utils::GetMD5Hash(String^ input) {
	// 1. Convertir el string de entrada en un array de bytes
	array<Byte>^ inputBytes = Text::Encoding::UTF8->GetBytes(input);
	// 2. Instanciar el proveedor de servicios MD5
	MD5^ md5Hasher = MD5::Create();
	// 3. Calcular el hash
	array<Byte>^ data = md5Hasher->ComputeHash(inputBytes);
	// 4. Crear un StringBuilder para recolectar los bytes y crear el string
	Text::StringBuilder^ sBuilder = gcnew Text::StringBuilder();
	// 5. Formatear cada byte como un string hexadecimal
	for (int i = 0; i < data->Length; i++) {
		sBuilder->Append(data[i].ToString("x2"));
	}
	// 6. Retornar el string hexadecimal
	return sBuilder->ToString();
};
