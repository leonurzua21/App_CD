#pragma once
using namespace System;
using namespace System::Configuration;
using namespace MySql::Data;
using namespace MySqlClient;

ref class Consultar //Clase que se encarga de consultar la base de datos
{
	static MySqlConnection^ connect;
	static MySqlConnectionStringBuilder^ ts;
public:
	Consultar();
protected:
	static void 
		ObtenerDatos()
	{
		ts = gcnew MySqlConnectionStringBuilder();
		ts->Server = "bvyfz6mfmtdrhrb6tfow-mysql.services.clever-cloud.com"; //Servidor donde se aloja la base de datos
		ts->Database = "bvyfz6mfmtdrhrb6tfow"; //Nombre de la base de datos
		ts->UserID = "u1rkvy1adcgozdfu"; //Usuario de la base de datos
		ts->Password = "nL9p8U0gipad3TVVINH1"; //Contraseña de la base de datos
		ts->SslMode = MySqlSslMode::Required; //Modo de seguridad

		connect = gcnew MySqlConnection(Convert::ToString(ts));
	}
public:
	static bool CredencialesExists(String^ userName, String ^ userPass)  //Ingresa con usuario y contraseña, metodo utilizado en la clase Acceso.h
	{ //Abre una conexión a la BD y verifica si el usuario y contraseña existe
		ObtenerDatos();
		
        String^ query = "SELECT COUNT(*) FROM usuario WHERE usuario = '" + userName + "' AND pass = '" + userPass + "'"; //Consulta el conteo de los usuarios registrados en la tabla Usuario
		MySqlCommand^ cmd = gcnew MySqlCommand(query, connect);
		connect->Open(); // Abrir la conexión a la base de datos
		int count = Convert::ToInt32(cmd->ExecuteScalar()); // Ejecutar la consulta
		connect->Close(); // Cerrar la conexión
		if (count > 0) // Si el conteo es mayor a 0, significa que el usuario y contraseña son correctos
			return true;
		else
			return false;
	}
public:
	static bool UsuarioExists(String^ userName)  //Ingresa con nombre de usuario, metodo utilizado en la clase Registro.h
	{ //Abre una conexión a la BD y verifica si el usuario existe
		ObtenerDatos();

		String^ query = "SELECT COUNT(*) FROM usuario WHERE usuario = @userName"; //Consulta el conteo de los usuarios registrados en la tabla Usuario
		MySqlCommand^ cmd = gcnew MySqlCommand(query, connect); // Crear el comando SQL
		cmd->Parameters->AddWithValue("@userName", userName);  // Asignar parámetro para el nombre de usuario

		connect->Open(); // Abrir la conexión a la base de datos
		int count = Convert::ToInt32(cmd->ExecuteScalar()); // Ejecutar la consulta
		connect->Close(); // Cerrar la conexión
		if (count > 0) // Si el conteo es mayor a 0, significa que el usuario ya existe
			return true;
		else
			return false;
	}
};