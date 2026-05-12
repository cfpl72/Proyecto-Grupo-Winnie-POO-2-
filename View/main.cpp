#include "pch.h"
#include "LoginForm.h"


using namespace System;
using namespace WinniePOO_Modelos;
using namespace WinniePOOview;
using namespace Controller;


void MenuUsuarios(ServicioUsuarios^ servicioUsuarios);
void MenuVentas(ServicioVenta^ servicioVentas, ServicioUsuarios^ servicioUsuarios);

/*int main() {

    ServicioUsuarios^ servicioUsuarios = gcnew ServicioUsuarios();
    ServicioVenta^ servicioVentas = gcnew ServicioVenta();

    int opcion;

    do {
        Console::WriteLine("\n====== SISTEMA FARMACIA ======");
        Console::WriteLine("1. Gestionar Usuarios");
        Console::WriteLine("2. Gestionar Ventas");
        Console::WriteLine("0. Salir");
        Console::Write("Seleccione una opcion: ");
        opcion = Convert::ToInt32(Console::ReadLine());

        switch (opcion) {
        case 1:
            MenuUsuarios(servicioUsuarios);
            break;
        case 2:
            MenuVentas(servicioVentas, servicioUsuarios);
            break;
        }

    } while (opcion != 0);

    Console::WriteLine("Saliendo del sistema...");
    return 0;
}
*/
//Main de Respaldo

// ================== MENU USUARIOS ==================
void MenuUsuarios(ServicioUsuarios^ servicioUsuarios) {

    int op;

    do {
        Console::WriteLine("\n--- CRUD USUARIOS ---");
        Console::WriteLine("1. Registrar Paciente");
        Console::WriteLine("2. Listar Usuarios");
        Console::WriteLine("3. Modificar Usuario");
        Console::WriteLine("4. Eliminar Usuario");
        Console::WriteLine("5. Listar Pacientes");
        Console::WriteLine("0. Volver");
        Console::Write("Opcion: ");
        op = Convert::ToInt32(Console::ReadLine());

        switch (op) {

        case 1: {
            Paciente^ p = gcnew Paciente();

            Console::Write("ID: ");
            p->id = Convert::ToInt32(Console::ReadLine());

            Console::Write("Nombre: ");
            p->nombre = Console::ReadLine();

            Console::Write("Apellido: ");
            p->apellido = Console::ReadLine();

            Console::Write("Contrasenia: ");
            p->contrasenia = Console::ReadLine();

            Console::Write("Edad: ");
            p->edad = Convert::ToInt32(Console::ReadLine());

            Console::Write("Alergias: ");
            p->alergias = Console::ReadLine();

            Console::Write("Sintomas: ");
            p->sintomas = Console::ReadLine();

            servicioUsuarios->RegistrarUsuario(p);
            break;
        }

        case 2:
            servicioUsuarios->ListarUsuarios();
            break;

        case 3: {
            int id;
            Console::Write("ID a modificar: ");
            id = Convert::ToInt32(Console::ReadLine());

            String^ nombre, ^ apellido, ^ pass;

            Console::Write("Nuevo nombre: ");
            nombre = Console::ReadLine();

            Console::Write("Nuevo apellido: ");
            apellido = Console::ReadLine();

            Console::Write("Nueva contrasenia: ");
            pass = Console::ReadLine();

            servicioUsuarios->ModificarUsuario(id, nombre, apellido, pass);
            break;
        }

        case 4: {
            int id;
            Console::Write("ID a eliminar: ");
            id = Convert::ToInt32(Console::ReadLine());

            servicioUsuarios->EliminarUsuario(id);
            break;
        }

        case 5:
            servicioUsuarios->ListarPacientes();
            break;
        }

    } while (op != 0);
}

// ================== MENU VENTAS ==================
void MenuVentas(ServicioVenta^ servicioVentas, ServicioUsuarios^ servicioUsuarios) {

    int op;

    do {
        Console::WriteLine("\n--- CRUD VENTAS ---");
        Console::WriteLine("1. Registrar Venta");
        Console::WriteLine("2. Listar Ventas");
        Console::WriteLine("3. Modificar Venta");
        Console::WriteLine("4. Eliminar Venta");
        Console::WriteLine("5. Buscar Venta por ID");
        Console::WriteLine("6. Historial por Paciente");
        Console::WriteLine("0. Volver");
        Console::Write("Opcion: ");
        op = Convert::ToInt32(Console::ReadLine());

        switch (op) {

        case 1: {
            int idVenta, idPaciente, cantidad;

            Console::Write("ID Venta: ");
            idVenta = Convert::ToInt32(Console::ReadLine());

            Console::Write("ID Paciente: ");
            idPaciente = Convert::ToInt32(Console::ReadLine());

            Console::Write("Cantidad: ");
            cantidad = Convert::ToInt32(Console::ReadLine());

            // Medicamento simple simulado
            Medicamento^ med = gcnew Medicamento(
                1,
                "Paracetamol",
                "Acetaminofen",
                5.0,
                100
            );

            servicioVentas->RegistrarNuevaVenta(
                idVenta,
                idPaciente,
                med,
                cantidad,
                DateTime::Now
            );

            break;
        }

        case 2:
            servicioVentas->ListarVentas();
            break;

        case 3: {
            int id, cantidad;

            Console::Write("ID Venta: ");
            id = Convert::ToInt32(Console::ReadLine());

            Console::Write("Nueva cantidad: ");
            cantidad = Convert::ToInt32(Console::ReadLine());

            Medicamento^ med = gcnew Medicamento(
                2,
                "Ibuprofeno",
                "Ibuprofeno",
                8.0,
                50
            );

            servicioVentas->ModificarVenta(id, cantidad, med);
            break;
        }

        case 4: {
            int id;
            Console::Write("ID Venta: ");
            id = Convert::ToInt32(Console::ReadLine());

            servicioVentas->EliminarVenta(id);
            break;
        }

        case 5: {
            int id;
            Console::Write("ID Venta: ");
            id = Convert::ToInt32(Console::ReadLine());

            Venta^ v = servicioVentas->ObtenerVenta(id);
            if (v != nullptr) {
                Console::WriteLine("Venta -> ID: " + v->id +
                    " | Cantidad: " + v->cantidadVendida);
            }
            break;
        }

        case 6: {
            int idPaciente;
            Console::Write("ID Paciente: ");
            idPaciente = Convert::ToInt32(Console::ReadLine());

            servicioVentas->VerHistorialPaciente(idPaciente);
            break;
        }

        }

    } while (op != 0);
}

int main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    LoginForm form;
    Application::Run(% form);
    return 0;
}
//Main para activar la lógica de formularios