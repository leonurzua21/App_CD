#pragma once
#include "Consultar.h"

using namespace System;
using namespace System::Configuration;
using namespace System::Data;
using namespace MySql::Data;
using namespace MySqlClient;

ref class conexion //Clase para la conexión a la base de datos
{
    MySqlConnection^ conecta;
    MySqlConnectionStringBuilder^ st;
public:
    conexion();

protected:
    void Conectar()
	{
        st = gcnew MySqlConnectionStringBuilder();
        st->Server = "bvyfz6mfmtdrhrb6tfow-mysql.services.clever-cloud.com"; //Servidor donde se aloja la base de datos
		st->Database = "bvyfz6mfmtdrhrb6tfow"; //Nombre de la base de datos
		st->UserID = "u1rkvy1adcgozdfu"; //Usuario de la base de datos
		st->Password = "nL9p8U0gipad3TVVINH1"; //Contraseña de la base de datos
		st->SslMode = MySqlSslMode::Required; //Modo de seguridad

        conecta = gcnew MySqlConnection(Convert::ToString(st));
    }
public:
    void Insertar(String^ nombre, String^ apellido, String^ UserName, String^ UserPass)
    {
        if (conecta == nullptr)
        {
            Conectar();
        }

        String^ enviardatos = "INSERT INTO usuario (nombre,apellido,usuario,pass) values (@nombre,@apellido,@usuario,@pass)";
		MySqlCommand^ ejecutar = gcnew MySqlCommand(enviardatos, conecta); // Crear el comando SQL
		ejecutar->Parameters->AddWithValue("@nombre", nombre); // Asignar parametro para el nombre
		ejecutar->Parameters->AddWithValue("@apellido", apellido); // Asignar parametro para el apellido
		ejecutar->Parameters->AddWithValue("@usuario", UserName); // Asignar parametro para el nombre de usuario
		ejecutar->Parameters->AddWithValue("@pass", UserPass); // Asignar parametro para la contrase�a

        try {
			conecta->Open(); // Abrir la conexión a la base de datos
			ejecutar->ExecuteNonQuery(); // Ejecutar la consulta
        }
        catch (Exception^ ex) {
			Console::WriteLine("Error: " + ex->Message); // Manejo de excepciones
        }
        finally {
			conecta->Close(); // Cerrar la conexión
        }
    }
};