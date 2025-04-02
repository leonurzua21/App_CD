#pragma once
using namespace System;
using namespace System::IO::Ports;
using namespace System::Windows::Forms;
using namespace System::IO;

ref class Comunicacion
{
public:
    SerialPort^ puerto; // Instancia del puerto serie
public:
    Comunicacion() // Constructor de la clase
    {
        puerto = nullptr; // Inicializamos como null para garantizar que no se abra por accidente
    }
    // M�todo para intentar conectar el puerto serie
    bool placa()
    {
        array<String^>^ puertosDisponibles = SerialPort::GetPortNames();
        array<SerialPort^>^ serialPorts = {
            gcnew SerialPort("COM4"),
            gcnew SerialPort("COM5"),
            gcnew SerialPort("COM6"),
            gcnew SerialPort("COM7")
        };
        
        bool conectado = false;

        for each (SerialPort ^ port in serialPorts)
        {
            if (Array::IndexOf(puertosDisponibles, port->PortName) >= 0)
            {
                try
                {
                    if (!port->IsOpen)
                    {
                        port->Open();
                        puerto = port; // Asignamos el puerto que se conect�
						puerto->BaudRate = 115200; //Bits por segundo
                        MessageBox::Show("Conexi�n exitosa a: " + puerto->PortName /*obtiene el nombre del puerto*/);
                        conectado = true;
                        break;
                    }
                }
                catch (Exception^ ex)
                {
                    MessageBox::Show("Error al conectar, puerto ocupado: " + ex->Message);
                }
            }
        }

        if (!conectado)
        {
            //MessageBox::Show("No se pudo conectar a ninguno de los puertos disponibles.");
			MessageBox::Show("No se encontr� ninguna placa de desarrollo");
        }

        return conectado; // Retorna si la conexi�n fue exitosa
    }

    SerialPort^ obtenerPuerto() // M�todo para obtener el puerto conectado
    {
        return puerto; // Devuelve el puerto conectado
    }

    bool estaAbierto() // M�todo para verificar si el puerto est� abierto

    {
        return puerto != nullptr && puerto->IsOpen;
    }
};