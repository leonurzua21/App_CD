#pragma once
using namespace System;
using namespace System::Configuration;
using namespace MySql::Data;
using namespace MySqlClient;

ref class Consultar
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
		ts->Server = "bvyfz6mfmtdrhrb6tfow-mysql.services.clever-cloud.com";
		ts->Database = "bvyfz6mfmtdrhrb6tfow";
		ts->UserID = "u1rkvy1adcgozdfu";
		ts->Password = "nL9p8U0gipad3TVVINH1";
		ts->SslMode = MySqlSslMode::Required;

		connect = gcnew MySqlConnection(Convert::ToString(ts));
	}
public:
	static bool CredencialesExists(String^ userName, String ^ userPass)  //Ingresa con usuario y contraseña, metodo utilizado en la clase Acceso.h
	{ //Abre una conexión a la BD y verifica si el usuario y contraseña existe
		ObtenerDatos();
		
        String^ query = "SELECT COUNT(*) FROM usuario WHERE usuario = '" + userName + "' AND pass = '" + userPass + "'"; //Consulta el conteo de los usuarios registrados en la tabla Usuario
		MySqlCommand^ cmd = gcnew MySqlCommand(query, connect);
		connect->Open();
		int count = Convert::ToInt32(cmd->ExecuteScalar());
<<<<<<< HEAD
		connect->Close();
		if (count > 0)
			return true;
		else
			return false;
	}
public:
	static bool UsuarioExists(String^ userName)  //Ingresa con nombre de usuario, metodo utilizado en la clase Registro.h
	{ //Abre una conexión a la BD y verifica si el usuario existe
		ObtenerDatos();

		String^ query = "SELECT COUNT(*) FROM usuario WHERE usuario = @userName"; //Consulta el conteo de los usuarios registrados en la tabla Usuario
		MySqlCommand^ cmd = gcnew MySqlCommand(query, connect);
		cmd->Parameters->AddWithValue("@userName", userName);  // Asignar parámetro para el nombre de usuari

		connect->Open();
		int count = Convert::ToInt32(cmd->ExecuteScalar());
=======
>>>>>>> c867218 (Conexion remota Lista)
		connect->Close();
		if (count > 0)
			return true;
		else
			return false;
	}
};