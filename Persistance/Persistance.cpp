#include "pch.h"
#include "Persistance.h"


bool Persistance::persistance::exists(String^ filePath) {
	return File::Exists(filePath);
}


