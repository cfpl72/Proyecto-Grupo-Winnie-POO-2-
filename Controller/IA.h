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
                Console::WriteLine("=== INICIO GenerarRecomendacion ===");

                HttpClient^ cliente = gcnew HttpClient();
                cliente->DefaultRequestHeaders->Add("Authorization", "Bearer " + apiKey);
                Console::WriteLine("HttpClient creado y header agregado");

                // Construcción del prompt
                String^ prompt ="Eres un sistema de farmacia robótica inteligente. " +
                    "SOLO puedes recomendar medicamentos que estén en esta lista: [" + listaMedicamentosStock + "]. " +
                    "Si ningún medicamento de la lista sirve para los síntomas, di que no hay stock disponible. " +
                    "Paciente presenta: " + sintomas + ". Historial: " + historial + ". " +

                    "Responde EXACTAMENTE en este formato:" +

                    "[INICIO_RECOMENDACION]" +
                    "Texto de recomendación médica profesional" +
                    "[FIN_RECOMENDACION]" +

                    "[INICIO_RECETA]" +
                    "id|nombre|principioActivo|dosis (número entero)" +
                    "(Al final de cada receta añade un [SEPARADOR]" +
                    "[FIN_RECETA]" +

                    "No agregues nada fuera de estas etiquetas.";

                Console::WriteLine("✔ Prompt construido:");
                Console::WriteLine(prompt);

                // JSON
                String^ cuerpoJson = "{\"model\": \"gpt-4o-mini\", \"messages\": [{\"role\": \"user\", \"content\": \"" + prompt + "\"}]}";
                Console::WriteLine("JSON enviado:");
                Console::WriteLine(cuerpoJson);

                StringContent^ contenido = gcnew StringContent(cuerpoJson, Encoding::UTF8, "application/json");

                Console::WriteLine("Enviando request...");
                auto tarea = cliente->PostAsync(apiUrl, contenido);
                tarea->Wait();

                Console::WriteLine("Request completado");

                auto response = tarea->Result;

                Console::WriteLine("Status code: " + response->StatusCode.ToString());

                String^ respuestaRaw = response->Content->ReadAsStringAsync()->Result;

                Console::WriteLine("Respuesta RAW:");
                Console::WriteLine(respuestaRaw);

                JObject^ datos = JObject::Parse(respuestaRaw);
                Console::WriteLine("JSON parseado correctamente");

                // Validación antes de acceder
                if (datos["choices"] != nullptr && datos["choices"]->HasValues) {
                    // Convertir a JArray para usar el indexador por entero y evitar boxing implícito
                    JArray^ choices = (JArray^)datos["choices"];

                    if (choices != nullptr && choices->Count > 0 && choices[0]["message"] != nullptr && choices[0]["message"]["content"] != nullptr) {
                        String^ resultado = choices[0]["message"]["content"]->ToString();

                        Console::WriteLine("Contenido extraído:");
                        Console::WriteLine(resultado);

                        return resultado;
                    }
                    else {
                        Console::WriteLine("Estructura inesperada en 'choices'");
                        return "Error en respuesta: estructura inesperada";
                    }
                }
                else {
                    Console::WriteLine("No se encontró 'choices' en la respuesta");
                    return "Error en respuesta: " + respuestaRaw;
                }
            }
            catch (Exception^ ex) {
                Console::WriteLine("EXCEPCIÓN:");
                Console::WriteLine(ex->Message);
                return "Error: " + ex->Message;
            }
        }
    };

}


