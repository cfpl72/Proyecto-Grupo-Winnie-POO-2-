#pragma once
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
        String^ apiKey = "apikey";
        String^ apiUrl = "https://api.openai.com/v1/responses";

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
                String^ cuerpoJson = "{\"model\": \"gpt-4.1\", \"input\": \"" + prompt + "\"}";
                StringContent^ contenido = gcnew StringContent(cuerpoJson, Encoding::UTF8, "application/json");

                auto tarea = cliente->PostAsync(apiUrl, contenido);
                tarea->Wait();

                String^ respuestaRaw = tarea->Result->Content->ReadAsStringAsync()->Result;

                Console::WriteLine("Respuesta RAW:");
                Console::WriteLine(respuestaRaw);


                JObject^ datos = JObject::Parse(respuestaRaw);
                if (datos["output"] != nullptr &&
                    datos["output"]->HasValues &&
                    datos["output"][0]["content"] != nullptr &&
                    datos["output"][0]["content"]->HasValues &&
                    datos["output"][0]["content"][0]["text"] != nullptr)
                {
                    return datos["output"][0]["content"][0]["text"]->ToString();
                }
                else if (datos["error"] != nullptr)
                {
                    return "Error API: " + datos["error"]["message"]->ToString();
                }
                else
                {
                    return "Respuesta inesperada: " + datos->ToString();
                }
            }
            catch (Exception^ ex) {
                return "Error: " + ex->Message;
            }
        }
    };

}


