/*#pragma once
#using <System.dll>
#using <System.Net.Http.dll>
// Asegúrate de haber agregado la referencia a Newtonsoft.Json.dll como hicimos antes

using namespace System;
using namespace System::Net::Http;
using namespace System::Text;
using namespace Newtonsoft::Json::Linq;

namespace IA_CLASS {

    // IA.h
    public ref class IA {
    private:
        String^ apiKey = "AIzaSyBEUPOmEdMBDE9a9P13rUGuhhgkol0O438";
        String^ apiUrl = "https://api.openai.com/v1/chat/completions";

    public:
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
                String^ cuerpoJson = "{\"model\": \"gpt-3.5-turbo\", \"messages\": [{\"role\": \"user\", \"content\": \"" + prompt + "\"}]}";
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

}*/


