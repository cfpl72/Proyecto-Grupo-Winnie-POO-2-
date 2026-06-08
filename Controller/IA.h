#pragma once
#using <System.dll>
#using <System.Net.Http.dll>
#using <System.IO.dll>
// Asegúrate de haber agregado la referencia a Newtonsoft.Json.dll como hicimos antes

using namespace System;
using namespace System::Net::Http;
using namespace System::Text;
using namespace Newtonsoft::Json::Linq;
using namespace System::IO;

namespace IA_CLASS {

    // IA.h
    public ref class IA {
    private:
        String^ apiKey ;
        String^ apiUrl = "https://api.openai.com/v1/chat/completions";

    public:

        // Constructor de la clase que lee el apiKey desde un archivo local
        IA() {
            try {
                String^ ruta = "C:\\Users\\music\\OneDrive\\Escritorio\\apiKey.txt";

                if (File::Exists(ruta)) {
                    apiKey = File::ReadAllText(ruta)->Trim();
                }
                else {
                    throw gcnew Exception("No se encontró el archivo apiKey.txt");
                }
            }
            catch (Exception^ ex) {
                apiKey = "";
                Console::WriteLine("Error al leer API Key: " + ex->Message);
            }
        }

        // Ahora recibe la lista de medicamentos del sistema
        String^ GenerarRecomendacion(String^ sintomas, String^ historial, String^ listaMedicamentosStock) {
            try {
                HttpClient^ cliente = gcnew HttpClient();
                cliente->DefaultRequestHeaders->Add("Authorization", "Bearer " + apiKey);

                // PROMPT DINÁMICO: Aquí es donde ocurre la magia
                String^ prompt = "Eres un sistema de farmacia robótica inteligente. " +
                    "SOLO puedes recomendar medicamentos que estén en esta lista: [" + listaMedicamentosStock + "]. " +
                    "Si ningún medicamento de la lista sirve para los síntomas, di que no hay stock disponible. " +
                    "Paciente presenta: " + sintomas + ". Historial: " + historial + ". " +
                    "Responde de forma breve y profesional.";

                // Construcción del JSON
                String^ cuerpoJson = "{\"model\": \"gpt-4o-mini\", \"messages\": [{\"role\": \"user\", \"content\": \"" + prompt + "\"}]}";
                StringContent^ contenido = gcnew StringContent(cuerpoJson, Encoding::UTF8, "application/json");

                auto tarea = cliente->PostAsync(apiUrl, contenido);
                tarea->Wait();

                String^ respuestaRaw = tarea->Result->Content->ReadAsStringAsync()->Result;
                JObject^ datos = JObject::Parse(respuestaRaw);
                return datos["choices"]["message"]["content"]->ToString();
            }
            catch (Exception^ ex) {
                return "Error: " + ex->Message;
            }
        }
    };

}


