#pragma once
using namespace System;
using namespace System::IO::Ports;
using namespace System::Windows::Forms;
using namespace System::IO;

ref class Comunicacion
{
public:
    Comunicacion();

public:
    void arduino()
    {
        // Obtener la lista de puertos COM disponibles en la computadora
        array<String^>^ puertosDisponibles = SerialPort::GetPortNames();

        // Crear objetos SerialPort
        array<SerialPort^>^ puertos = {
            gcnew SerialPort("COM4"),
            gcnew SerialPort("COM5"),
            gcnew SerialPort("COM6"),
            gcnew SerialPort("COM7")
        };

        bool conectado = false;

        for each (SerialPort ^ puerto in puertos)
        {
            if (Array::IndexOf(puertosDisponibles, puerto->PortName) >= 0)
            {
                try
                {
                    if (!puerto->IsOpen)
                    {
                        puerto->Open();
                        MessageBox::Show("Conectado a " + puerto->PortName);
                        conectado = true;
                        break;
                    }
                }
                catch (UnauthorizedAccessException^ ex)
                {
                    MessageBox::Show("Acceso denegado al puerto: " + ex->Message);
                }
                catch (ArgumentOutOfRangeException^ ex)
                {
                    MessageBox::Show("Error de configuración del puerto: " + ex->Message);
                }
                catch (IOException^ ex)
                {
                    MessageBox::Show("Error al intentar abrir el puerto: " + ex->Message);
                }
                catch (Exception^ ex)
                {
                    MessageBox::Show("Error al conectar: " + ex->Message);
                }
            }
        }

        if (!conectado)
        {
            MessageBox::Show("No se pudo conectar a ninguno de los puertos disponibles.");
        }
    }
};

