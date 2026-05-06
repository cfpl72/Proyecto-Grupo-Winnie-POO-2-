#include "pch.h"
#include "Persistance.h"


bool Persistance::persistance::exists(String^ filePath) {
	return File::Exists(filePath);
}

void Persistance::persistance::SaveDataToText(String^ filePath, Object^ ObjectData) {
	StreamWriter^ writer = gcnew StreamWriter(filePath,true);

	if(ObjectData->GetType() == Usuario^)

}

