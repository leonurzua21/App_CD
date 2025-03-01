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
		SerialPort^ puerto = gcnew SerialPort("COM4");

        try
        {
            // Si el puerto no está abierto, intenta abrirlo
            if (!puerto->IsOpen)
            {
                puerto->Open();
                MessageBox::Show("Conectado");
            }
            else
            {
                MessageBox::Show("Ya está conectado");
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
