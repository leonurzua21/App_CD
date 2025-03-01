#pragma once
using namespace System;
using namespace System::IO::Ports;
using namespace System::Windows::Forms;
using namespace System::IO; // Agregar esta línea para definir IOException

ref class Comunicacion
{
public:
	Comunicacion();

public:
	void arduino()
    {
        // Obtener la lista de puertos COM disponibles en la computadora
        array<String^> ^ puertosDisponibles = SerialPort::GetPortNames();

        // Verificar si COM4 y COM5 están disponibles
        bool puertoCOM4Disponible = Array::IndexOf(puertosDisponibles, "COM4") >= 0;
        bool puertoCOM5Disponible = Array::IndexOf(puertosDisponibles, "COM5") >= 0;
        bool puertoCOM6Disponible = Array::IndexOf(puertosDisponibles, "COM6") >= 0;
        bool puertoCOM7Disponible = Array::IndexOf(puertosDisponibles, "COM7") >= 0;

        // Crear objetos SerialPort
        SerialPort^ puerto0 = gcnew SerialPort("COM4");
        SerialPort^ puerto1 = gcnew SerialPort("COM5");
        SerialPort^ puerto2 = gcnew SerialPort("COM6");
        SerialPort^ puerto3 = gcnew SerialPort("COM7");

        try
        {
            // Validar si ambos puertos están disponibles
         if (puertoCOM4Disponible)
         {
         // Comprobar si el puerto COM4 no está abierto y abrirlo
            if (!puerto0->IsOpen)
            {
                puerto0->Open();
                MessageBox::Show("Conectado a COM4");
            }
         }

        // Validar si COM5 está disponible
        if (puertoCOM5Disponible)
        {
            // Comprobar si el puerto COM5 no está abierto y abrirlo
            if (!puerto1->IsOpen)
            {
                puerto1->Open();
                MessageBox::Show("Conectado a COM5");
            }
            //else
            //{
            //    MessageBox::Show("No se realizo ninguna conexión");
            //}
            }
        if (puertoCOM6Disponible)
        {
            // Comprobar si el puerto COM5 no está abierto y abrirlo
            if (!puerto2->IsOpen)
            {
                puerto2->Open();
                MessageBox::Show("Conectado a COM6");
            }
        }
        if (puertoCOM7Disponible)
        {
            // Comprobar si el puerto COM5 no está abierto y abrirlo
            if (!puerto3->IsOpen)
            {
                puerto3->Open();
                MessageBox::Show("Conectado a COM7");
            }
        }
       
    }
        catch (UnauthorizedAccessException^ ex)
        {
            // Captura la excepción si no se tiene permiso para acceder al puerto
            MessageBox::Show("Acceso denegado al puerto: " + ex->Message);
        }
        catch (ArgumentOutOfRangeException^ ex)
        {
            // Captura la excepción si hay un error con el puerto
            MessageBox::Show("Error de configuración del puerto: " + ex->Message);
        }
        catch (IOException^ ex)
        {
            // Captura la excepción si hay un error de I/O
            MessageBox::Show("Error al intentar abrir el puerto: " + ex->Message);
        }
        catch (Exception^ ex)
        {
            // Captura cualquier otra excepción general
            MessageBox::Show("Error al conectar: " + ex->Message);
        }
	}
};
