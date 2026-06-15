#include "pch.h"
#include "Persistance.h"

using namespace System::Data;
using namespace System::Data::SqlClient;

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
                    1,
                    1.5,
                    "A",
                    DateTime::Now// no estás persistiendo fecha aún
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

namespace Persistance1 {

    // =========================
    // 🔌 CONNECTION STRING
    // =========================
    String^ PersistanceManager::GetConnectionString() {
        return "Server=idb1inf53.clzlex5tfzm6.us-east-1.rds.amazonaws.com;Database=FarmaciaDB;User Id=admin;Password=Ch2DXr8sbtJxrGV;";
    }

    // =========================
    // Pacientes
    // =========================

    bool PersistanceManager::InsertPaciente(Paciente^ p) {

        SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());

        try {
            conn->Open();

            String^ query = "INSERT INTO Pacientes (id, verificationToken, nombre, apellido, edad, alergias, sintomas) "
                "VALUES (@id, @token, @nombre, @apellido, @edad, @alergias, @sintomas)";

            SqlCommand^ cmd = gcnew SqlCommand(query, conn);

            cmd->Parameters->AddWithValue("@id", p->id);
            cmd->Parameters->AddWithValue("@token", p->verificationToken);
            cmd->Parameters->AddWithValue("@nombre", p->nombre);
            cmd->Parameters->AddWithValue("@apellido", p->apellido);
            cmd->Parameters->AddWithValue("@edad", p->edad);
            cmd->Parameters->AddWithValue("@alergias", p->alergias);
            cmd->Parameters->AddWithValue("@sintomas", p->sintomas);

            cmd->ExecuteNonQuery();

            Console::WriteLine("✔ INSERT Paciente ID: " + p->id);
            return true;
        }
        catch (Exception^ ex) {
            Console::WriteLine("❌ INSERT ERROR: " + ex->Message);
            return false;
        }
        finally {
            conn->Close();
        }
    }

    Dictionary<int, Paciente^>^ PersistanceManager::GetAllPacientes() {

        auto dic = gcnew Dictionary<int, Paciente^>();

        SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());

        try {
            conn->Open();

            SqlCommand^ cmd = gcnew SqlCommand("SELECT * FROM Pacientes", conn);
            SqlDataReader^ r = cmd->ExecuteReader();

            while (r->Read()) {

                Paciente^ p = gcnew Paciente(
                    r->GetInt32(0),
                    r->GetString(1)
                );

                p->nombre = r->GetString(2);
                p->apellido = r->GetString(3);
                p->edad = r->GetInt32(4);
                p->alergias = r->GetString(5);
                p->sintomas = r->GetString(6);

                dic[p->id] = p;
            }

            r->Close();
        }
        catch (Exception^ ex) {
            Console::WriteLine("❌ GET ALL ERROR: " + ex->Message);
        }
        finally {
            conn->Close();
        }

        return dic;
    }

    Paciente^ PersistanceManager::GetPacienteById(int id) {

        SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());

        try {
            conn->Open();

            SqlCommand^ cmd = gcnew SqlCommand("SELECT * FROM Pacientes WHERE id=@id", conn);
            cmd->Parameters->AddWithValue("@id", id);

            SqlDataReader^ r = cmd->ExecuteReader();

            if (r->Read()) {

                Paciente^ p = gcnew Paciente(
                    r->GetInt32(0),
                    r->GetString(1)
                );

                p->nombre = r->GetString(2);
                p->apellido = r->GetString(3);
                p->edad = r->GetInt32(4);
                p->alergias = r->GetString(5);
                p->sintomas = r->GetString(6);

                r->Close();
                return p;
            }

            r->Close();
        }
        catch (Exception^ ex) {
            Console::WriteLine("❌ GET BY ID ERROR: " + ex->Message);
        }
        finally {
            conn->Close();
        }

        return nullptr;
    }

    bool PersistanceManager::UpdatePaciente(Paciente^ p) {

        SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());

        try {
            conn->Open();

            String^ query = "UPDATE Pacientes SET "
                "verificationToken=@token, nombre=@nombre, apellido=@apellido, edad=@edad, alergias=@alergias, sintomas=@sintomas "
                "WHERE id=@id";

            SqlCommand^ cmd = gcnew SqlCommand(query, conn);

            cmd->Parameters->AddWithValue("@id", p->id);
            cmd->Parameters->AddWithValue("@token", p->verificationToken);
            cmd->Parameters->AddWithValue("@nombre", p->nombre);
            cmd->Parameters->AddWithValue("@apellido", p->apellido);
            cmd->Parameters->AddWithValue("@edad", p->edad);
            cmd->Parameters->AddWithValue("@alergias", p->alergias);
            cmd->Parameters->AddWithValue("@sintomas", p->sintomas);

            int rows = cmd->ExecuteNonQuery();

            Console::WriteLine("✔ UPDATE rows: " + rows);
            return rows > 0;
        }
        catch (Exception^ ex) {
            Console::WriteLine("❌ UPDATE ERROR: " + ex->Message);
            return false;
        }
        finally {
            conn->Close();
        }
    }

    bool PersistanceManager::DeletePaciente(int id) {

        SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());

        try {
            conn->Open();

            SqlCommand^ cmd = gcnew SqlCommand("DELETE FROM Pacientes WHERE id=@id", conn);
            cmd->Parameters->AddWithValue("@id", id);

            int rows = cmd->ExecuteNonQuery();

            Console::WriteLine("✔ DELETE rows: " + rows);
            return rows > 0;
        }
        catch (Exception^ ex) {
            Console::WriteLine("❌ DELETE ERROR: " + ex->Message);
            return false;
        }
        finally {
            conn->Close();
        }
    }

    // =========================
    // MEDICAMENTOS
    // =========================

    bool PersistanceManager::InsertMedicamento(Medicamento^ m) {

        SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());

        try {
            conn->Open();

            String^ query = "INSERT INTO Medicamentos (id, nombre, principioActivo, precio, stock) "
                "VALUES (@id, @nombre, @principio, @precio, @stock)";

            SqlCommand^ cmd = gcnew SqlCommand(query, conn);

            cmd->Parameters->AddWithValue("@id", m->id);
            cmd->Parameters->AddWithValue("@nombre", m->nombre);
            cmd->Parameters->AddWithValue("@principio", m->principioActivo);
            cmd->Parameters->AddWithValue("@precio", m->precio);
            cmd->Parameters->AddWithValue("@stock", m->stock);

            cmd->ExecuteNonQuery();

            Console::WriteLine("✔ INSERT OK ID: " + m->id);
            return true;
        }
        catch (Exception^ ex) {
            Console::WriteLine("❌ INSERT ERROR: " + ex->Message);
            return false;
        }
        finally {
            conn->Close();
        }
    }

    Dictionary<int, Medicamento^>^ PersistanceManager::GetAllMedicamentos() {

        Dictionary<int, Medicamento^>^ dic = gcnew Dictionary<int, Medicamento^>();

        SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());

        try {
            conn->Open();

            SqlCommand^ cmd = gcnew SqlCommand("SELECT * FROM Medicamentos", conn);
            SqlDataReader^ r = cmd->ExecuteReader();

            while (r->Read()) {

                Medicamento^ m = gcnew Medicamento(
                    r->GetInt32(0),
                    r->GetString(1),
                    r->GetString(2),
                    Convert::ToDouble(r->GetDecimal(3)),
                    r->GetInt32(4)
                );

                dic[m->id] = m;
            }

            r->Close();
        }
        catch (Exception^ ex) {
            Console::WriteLine("❌ GET ALL ERROR: " + ex->Message);
        }
        finally {
            conn->Close();
        }

        return dic;
    }

    Medicamento^ PersistanceManager::GetMedicamentoById(int id) {

        SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());

        try {
            conn->Open();

            SqlCommand^ cmd = gcnew SqlCommand("SELECT * FROM Medicamentos WHERE id=@id", conn);
            cmd->Parameters->AddWithValue("@id", id);

            SqlDataReader^ r = cmd->ExecuteReader();

            if (r->Read()) {

                Medicamento^ m = gcnew Medicamento(
                    r->GetInt32(0),
                    r->GetString(1),
                    r->GetString(2),
                    Convert::ToDouble(r->GetDecimal(3)),
                    r->GetInt32(4)
                );

                r->Close();
                return m;
            }

            r->Close();
        }
        catch (Exception^ ex) {
            Console::WriteLine("❌ GET BY ID ERROR: " + ex->Message);
        }
        finally {
            conn->Close();
        }

        return nullptr;
    }

    bool PersistanceManager::UpdateMedicamento(int id, double precio, int stock) {

        SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());

        try {
            conn->Open();

            String^ query = "UPDATE Medicamentos SET precio=@precio, stock=@stock WHERE id=@id";

            SqlCommand^ cmd = gcnew SqlCommand(query, conn);

            cmd->Parameters->AddWithValue("@id", id);
            cmd->Parameters->AddWithValue("@precio", precio);
            cmd->Parameters->AddWithValue("@stock", stock);

            int rows = cmd->ExecuteNonQuery();

            Console::WriteLine("✔ UPDATE rows: " + rows);
            return rows > 0;
        }
        catch (Exception^ ex) {
            Console::WriteLine("❌ UPDATE ERROR: " + ex->Message);
            return false;
        }
        finally {
            conn->Close();
        }
    }

    bool PersistanceManager::DeleteMedicamento(int id) {

        SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());

        try {
            conn->Open();

            SqlCommand^ cmd = gcnew SqlCommand("DELETE FROM Medicamentos WHERE id=@id", conn);
            cmd->Parameters->AddWithValue("@id", id);

            int rows = cmd->ExecuteNonQuery();

            Console::WriteLine("✔ DELETE rows: " + rows);
            return rows > 0;
        }
        catch (Exception^ ex) {
            Console::WriteLine("❌ DELETE ERROR: " + ex->Message);
            return false;
        }
        finally {
            conn->Close();
        }
    }

    // =========================
    // VENTAS
    // =========================

    bool PersistanceManager::InsertVenta(Venta^ v) {

        SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());

        try {
            conn->Open();

            String^ query = "INSERT INTO Ventas (id, idPaciente, idMedicamento, cantidadVendida, precioMedicamento, totalVenta, nombreMedicamento, fecha) "
                "VALUES (@id, @idPaciente, @idMed, @cantidad, @precio, @total, @nombre, @fecha)";

            SqlCommand^ cmd = gcnew SqlCommand(query, conn);

            cmd->Parameters->AddWithValue("@id", v->id);
            cmd->Parameters->AddWithValue("@idPaciente", v->idPaciente);
            cmd->Parameters->AddWithValue("@idMed", v->idMedicamento);
            cmd->Parameters->AddWithValue("@cantidad", v->cantidadVendida);
            cmd->Parameters->AddWithValue("@precio", v->precioMedicamento);
            cmd->Parameters->AddWithValue("@total", v->totalVenta);
            cmd->Parameters->AddWithValue("@nombre", v->nombreMedicamento);
            cmd->Parameters->AddWithValue("@fecha", v->fecha);

            cmd->ExecuteNonQuery();

            Console::WriteLine("✔ INSERT Venta ID: " + v->id);
            return true;
        }
        catch (Exception^ ex) {
            Console::WriteLine("❌ INSERT ERROR: " + ex->Message);
            return false;
        }
        finally {
            conn->Close();
        }
    }

    Dictionary<int, Venta^>^ PersistanceManager::GetAllVentas() {

        Dictionary<int, Venta^>^ dic = gcnew Dictionary<int, Venta^>();

        SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());

        try {
            conn->Open();

            SqlCommand^ cmd = gcnew SqlCommand("SELECT * FROM Ventas", conn);
            SqlDataReader^ r = cmd->ExecuteReader();

            while (r->Read()) {

                int id = r->GetInt32(0);
                int idPaciente = r->GetInt32(1);
                int idMedicamento = r->GetInt32(2);
                int cantidad = r->GetInt32(3);
                double precio = Convert::ToDouble(r->GetDecimal(4));
                double total = Convert::ToDouble(r->GetDecimal(5));
                String^ nombre = r->GetString(6);
                DateTime fecha = r->GetDateTime(7);

                Venta^ v = gcnew Venta(
                    id,
                    idPaciente,
                    cantidad,
                    idMedicamento,
                    precio,
                    nombre,
                    fecha
                );

                dic[id] = v;
            }

            r->Close();
        }
        catch (Exception^ ex) {
            Console::WriteLine("❌ GET ALL ERROR: " + ex->Message);
        }
        finally {
            conn->Close();
        }

        return dic;
    }

    Venta^ PersistanceManager::GetVentaById(int id) {

        SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());

        try {
            conn->Open();

            SqlCommand^ cmd = gcnew SqlCommand("SELECT * FROM Ventas WHERE id=@id", conn);
            cmd->Parameters->AddWithValue("@id", id);

            SqlDataReader^ r = cmd->ExecuteReader();

            if (r->Read()) {

                int idPaciente = r->GetInt32(1);
                int idMedicamento = r->GetInt32(2);
                int cantidad = r->GetInt32(3);
                double precio = Convert::ToDouble(r->GetDecimal(4));
                String^ nombre = r->GetString(6);
                DateTime fecha = r->GetDateTime(7);

                Venta^ v = gcnew Venta(
                    id,
                    idPaciente,
                    cantidad,
                    idMedicamento,
                    precio,
                    nombre,
                    fecha
                );

                r->Close();
                return v;
            }

            r->Close();
        }
        catch (Exception^ ex) {
            Console::WriteLine("❌ GET ERROR: " + ex->Message);
        }
        finally {
            conn->Close();
        }

        return nullptr;
    }

    bool PersistanceManager::DeleteVenta(int id) {

        SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());

        try {
            conn->Open();

            SqlCommand^ cmd = gcnew SqlCommand("DELETE FROM Ventas WHERE id=@id", conn);
            cmd->Parameters->AddWithValue("@id", id);

            int rows = cmd->ExecuteNonQuery();

            Console::WriteLine("✔ DELETE rows: " + rows);
            return rows > 0;
        }
        catch (Exception^ ex) {
            Console::WriteLine("❌ DELETE ERROR: " + ex->Message);
            return false;
        }
        finally {
            conn->Close();
        }
    }

    // =========================
    // HISTORIAL RECETAS
    // =========================

    bool PersistanceManager::InsertReceta(int idReceta, int idPaciente, int idMedicamento, int dosis, DateTime fecha, bool entregado) {
        SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());
        try {
            conn->Open();
            String^ query = "INSERT INTO Recetas (idReceta,idPaciente,idMedicamento,dosis,fechaEmision,entregado) VALUES (@id,@idPaciente,@idMed,@dosis,@fecha,@entregado)";
            SqlCommand^ cmd = gcnew SqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@id", idReceta);
            cmd->Parameters->AddWithValue("@idPaciente", idPaciente);
            cmd->Parameters->AddWithValue("@idMed", idMedicamento);
            cmd->Parameters->AddWithValue("@dosis", dosis);
            cmd->Parameters->AddWithValue("@fecha", fecha);
            cmd->Parameters->AddWithValue("@entregado", entregado);
            cmd->ExecuteNonQuery();
            return true;
        }
        catch (Exception^ ex) {
            Console::WriteLine("ERROR INSERT RECETA: " + ex->Message);
            return false;
        }
        finally { conn->Close(); }
    }

    List<Receta^>^ PersistanceManager::GetAllRecetas() {
        List<Receta^>^ lista = gcnew List<Receta^>();
        SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());
        try {
            conn->Open();
            SqlCommand^ cmd = gcnew SqlCommand("SELECT * FROM Recetas", conn);
            SqlDataReader^ r = cmd->ExecuteReader();
            while (r->Read()) {
                Receta^ rec = gcnew Receta();
                rec->idReceta = r->GetInt32(0);
                rec->idPaciente = r->GetInt32(1);
                rec->idMedicamento = r->GetInt32(2);
                rec->dosis = r->GetInt32(3);
                rec->fechaEmision = r->GetDateTime(4);
                rec->entregado = r->GetBoolean(5);
                lista->Add(rec);
            }
            r->Close();
        }
        catch (Exception^ ex) {
            Console::WriteLine("ERROR GET RECETAS: " + ex->Message);
        }
        finally { conn->Close(); }
        return lista;
    }

    Receta^ PersistanceManager::GetRecetaById(int idReceta) {
        SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());
        try {
            conn->Open();
            SqlCommand^ cmd = gcnew SqlCommand("SELECT * FROM Recetas WHERE idReceta=@id", conn);
            cmd->Parameters->AddWithValue("@id", idReceta);
            SqlDataReader^ r = cmd->ExecuteReader();
            if (r->Read()) {
                Receta^ rec = gcnew Receta();
                rec->idReceta = r->GetInt32(0);
                rec->idPaciente = r->GetInt32(1);
                rec->idMedicamento = r->GetInt32(2);
                rec->dosis = r->GetInt32(3);
                rec->fechaEmision = r->GetDateTime(4);
                rec->entregado = r->GetBoolean(5);
                r->Close();
                return rec;
            }
            r->Close();
        }
        catch (Exception^ ex) {
            Console::WriteLine("ERROR GET RECETA: " + ex->Message);
        }
        finally { conn->Close(); }
        return nullptr;
    }

    bool PersistanceManager::MarcarRecetaComoEntregada(int idReceta) {
        SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());
        try {
            conn->Open();
            SqlCommand^ cmd = gcnew SqlCommand("UPDATE Recetas SET entregado=1 WHERE idReceta=@id", conn);
            cmd->Parameters->AddWithValue("@id", idReceta);
            int rows = cmd->ExecuteNonQuery();
            return rows > 0;
        }
        catch (Exception^ ex) {
            Console::WriteLine("ERROR UPDATE RECETA: " + ex->Message);
            return false;
        }
        finally { conn->Close(); }
    }

    bool PersistanceManager::DeleteReceta(int idReceta) {
        SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());
        try {
            conn->Open();
            SqlCommand^ cmd = gcnew SqlCommand("DELETE FROM Recetas WHERE idReceta=@id", conn);
            cmd->Parameters->AddWithValue("@id", idReceta);
            int rows = cmd->ExecuteNonQuery();
            return rows > 0;
        }
        catch (Exception^ ex) {
            Console::WriteLine("ERROR DELETE RECETA: " + ex->Message);
            return false;
        }
        finally { conn->Close(); }
    }
}