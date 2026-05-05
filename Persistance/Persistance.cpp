#include "pch.h"
#include "Persistance.h"


/* namespace Persistance {
	public ref class persistance
	{
	public:
		static bool exists(String^ filePath);

		static void SaveDataToText(String^ filePath, Object^ ObjectData);
		static Object^ LoadDataFromText(String^ filePath, Type^ tipo);

		static void SaveDataToXML(String^ filePath, Object^ ObjectData);
		static Object^ LoadDataFromXML(String^ filePath, Type^ tipo);

		static void SaveDataToBinary(String^ filePath, Object^ ObjectData);
		static Object^ LoadDataFromBinary(String^ filePath, Type^ tipo);
	};
}
*/

 bool Persistance::persistance::exists(String^ filePath) {
	 return File::Exists(filePath);
}