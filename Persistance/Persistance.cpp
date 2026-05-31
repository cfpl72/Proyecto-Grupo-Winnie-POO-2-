#include "pch.h"
#include "Persistance.h"

namespace Persistance {

    // =========================
    // PACIENTES
    // =========================
    void PersistanceManager::SavePacientes(String^ filePath, Dictionary<int, Paciente^>^ dic) {
        StreamWriter^ writer = nullptr;

        try {
            writer = gcnew StreamWriter(filePath);

            for each (auto kv in dic) {
                Paciente^ p = kv.Value;

                writer->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}|{5}|{6}",
                    p->id,
                    p->verificationToken,
                    p->nombre,
                    p->apellido,
                    p->edad,
                    p->alergias,
                    p->sintomas
                ));
            }
        }
        catch (Exception^ ex) {
            Console::WriteLine("ERROR (SavePacientes): " + ex->Message);
        }
        finally {
            if (writer != nullptr) writer->Close();
        }
    }

    Dictionary<int, Paciente^>^ PersistanceManager::LoadPacientes(String^ filePath) {
        Dictionary<int, Paciente^>^ dic = gcnew Dictionary<int, Paciente^>();
        StreamReader^ reader = nullptr;

        try {
            if (!File::Exists(filePath)) return dic;

            reader = gcnew StreamReader(filePath);

            while (!reader->EndOfStream) {
                String^ linea = reader->ReadLine();
                auto campos = linea->Split('|');

                if (campos->Length < 7) continue;

                Paciente^ p = gcnew Paciente(
                    Convert::ToInt32(campos[0]),
                    campos[1]
                );

                // Asignaciones manuales (clave por tu modelo)
                p->nombre = campos[2];
                p->apellido = campos[3];
                p->edad = Convert::ToInt32(campos[4]);
                p->alergias = campos[5];
                p->sintomas = campos[6];

                if (!dic->ContainsKey(p->id))
                    dic->Add(p->id, p);
            }
        }
        catch (Exception^ ex) {
            Console::WriteLine("ERROR (LoadPacientes): " + ex->Message);
        }
        finally {
            if (reader != nullptr) reader->Close();
        }

        return dic;
    }

    // =========================
    // MEDICAMENTOS
    // =========================
    void PersistanceManager::SaveMedicamentos(String^ filePath, Dictionary<int, Medicamento^>^ dic) {
        StreamWriter^ writer = nullptr;

        try {
            writer = gcnew StreamWriter(filePath);

            for each (auto kv in dic) {
                Medicamento^ m = kv.Value;

                writer->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}",
                    m->id,
                    m->nombre,
                    m->principioActivo,
                    m->precio,
                    m->stock
                ));
            }
        }
        catch (Exception^ ex) {
            Console::WriteLine("ERROR (SaveMedicamentos): " + ex->Message);
        }
        finally {
            if (writer != nullptr) writer->Close();
        }
    }

    Dictionary<int, Medicamento^>^ PersistanceManager::LoadMedicamentos(String^ filePath) {
        Dictionary<int, Medicamento^>^ dic = gcnew Dictionary<int, Medicamento^>();
        StreamReader^ reader = nullptr;

        try {
            if (!File::Exists(filePath)) return dic;

            reader = gcnew StreamReader(filePath);

            while (!reader->EndOfStream) {
                String^ linea = reader->ReadLine();
                auto campos = linea->Split('|');

                if (campos->Length < 5) continue;

                Medicamento^ m = gcnew Medicamento(
                    Convert::ToInt32(campos[0]),
                    campos[1],
                    campos[2],
                    Convert::ToDouble(campos[3]),
                    Convert::ToInt32(campos[4])
                );

                if (!dic->ContainsKey(m->id))
                    dic->Add(m->id, m);
            }
        }
        catch (Exception^ ex) {
            Console::WriteLine("ERROR (LoadMedicamentos): " + ex->Message);
        }
        finally {
            if (reader != nullptr) reader->Close();
        }

        return dic;
    }

    // =========================
    // VENTAS
    // =========================
    void PersistanceManager::SaveVentas(String^ filePath, Dictionary<int, Venta^>^ dic) {
        StreamWriter^ writer = nullptr;

        try {
            writer = gcnew StreamWriter(filePath);

            for each (auto kv in dic) {
                Venta^ v = kv.Value;

                writer->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}|{5}|{6}",
                    v->id,
                    v->idPaciente,
                    v->idMedicamento,
                    v->cantidadVendida,
                    v->precioMedicamento,
                    v->totalVenta,
                    v->nombreMedicamento
                ));
            }
        }
        catch (Exception^ ex) {
            Console::WriteLine("ERROR (SaveVentas): " + ex->Message);
        }
        finally {
            if (writer != nullptr) writer->Close();
        }
    }

    Dictionary<int, Venta^>^ PersistanceManager::LoadVentas(String^ filePath) {
        Dictionary<int, Venta^>^ dic = gcnew Dictionary<int, Venta^>();
        StreamReader^ reader = nullptr;

        try {
            if (!File::Exists(filePath)) return dic;

            reader = gcnew StreamReader(filePath);

            while (!reader->EndOfStream) {
                String^ linea = reader->ReadLine();
                auto campos = linea->Split('|');

                if (campos->Length < 7) continue;

                // ⚠️ Venta necesita un Medicamento para construirse
                Medicamento^ dummy = gcnew Medicamento(
                    Convert::ToInt32(campos[2]),
                    campos[6],      // nombreMedicamento
                    "",             // principioActivo (no persistido)
                    Convert::ToDouble(campos[4]),
                    0               // stock irrelevante aquí
                );

                Venta^ v = gcnew Venta(
                    Convert::ToInt32(campos[0]),
                    Convert::ToInt32(campos[1]),
                    Convert::ToInt32(campos[3]),
                    dummy,
                    DateTime::Now   // no estás persistiendo fecha aún
                );

                if (!dic->ContainsKey(v->id))
                    dic->Add(v->id, v);
            }
        }
        catch (Exception^ ex) {
            Console::WriteLine("ERROR (LoadVentas): " + ex->Message);
        }
        finally {
            if (reader != nullptr) reader->Close();
        }

        return dic;
    }

    // =========================
    // HISTORIAL RECETAS
    // =========================

    void PersistanceManager::CrearHistorialSiNoExiste(String^ filePath) {
        try {
            if (!File::Exists(filePath)) {
                FileStream^ fs = File::Create(filePath);
                fs->Close();
            }
        }
        catch (Exception^ ex) {
            Console::WriteLine("ERROR (CrearHistorial): " + ex->Message);
        }
    }

    void PersistanceManager::SaveHistorialRecetas(String^ filePath, List<Receta^>^ lista) {
        StreamWriter^ writer = nullptr;

        try {
            writer = gcnew StreamWriter(filePath); // overwrite

            for each(Receta ^ r in lista) {
                writer->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}",
                    r->idReceta,
                    r->medicamento->nombre,
                    r->dosis,
                    r->fechaEmision.ToString("dd/MM/yyyy"),
                    r->entregado ? 1 : 0
                ));
            }
        }
        catch (Exception^ ex) {
            Console::WriteLine("ERROR (SaveHistorialRecetas): " + ex->Message);
        }
        finally {
            if (writer != nullptr) writer->Close();
        }
    }

    void PersistanceManager::AppendReceta(
        String^ filePath,
        int idReceta,
        int dosis,
        DateTime fecha,
        String^ nombreMedicamento,
        bool entregado
    ) {
        StreamWriter^ writer = nullptr;

        try {
            writer = gcnew StreamWriter(filePath, true); // append

            writer->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}",
                idReceta,
                nombreMedicamento,
                dosis,
                fecha.ToString("dd/MM/yyyy"),
                entregado ? 1 : 0
            ));
        }
        catch (Exception^ ex) {
            Console::WriteLine("ERROR (AppendReceta): " + ex->Message);
        }
        finally {
            if (writer != nullptr) writer->Close();
        }
    }


    List<Receta^>^ PersistanceManager::LoadHistorialRecetas(String^ filePath) {
        List<Receta^>^ lista = gcnew List<Receta^>();
        StreamReader^ reader = nullptr;

        try {
            if (!File::Exists(filePath)) return lista;

            reader = gcnew StreamReader(filePath);

            while (!reader->EndOfStream) {
                String^ linea = reader->ReadLine();
                auto campos = linea->Split('|');

                if (campos->Length < 5) continue;

                Receta^ r = gcnew Receta();

                // ID
                r->idReceta = Convert::ToInt32(campos[0]);

                // Medicamento (dummy, igual que en ventas)
                Medicamento^ m = gcnew Medicamento(
                    0,                      // id no persistido aquí
                    campos[1],              // nombre
                    "",                     // principio activo
                    0,                      // precio
                    0                       // stock
                );
                r->medicamento = m;

                // Dosis
                r->dosis = Convert::ToInt32(campos[2]);

                // Fecha
                r->fechaEmision = DateTime::ParseExact(
                    campos[3],
                    "dd/MM/yyyy",
                    nullptr
                );

                // Entregado
                r->entregado = (campos[4] == "1");

                lista->Add(r);
            }
        }
        catch (Exception^ ex) {
            Console::WriteLine("ERROR (LoadHistorialRecetas): " + ex->Message);
        }
        finally {
            if (reader != nullptr) reader->Close();
        }

        return lista;
    }
}