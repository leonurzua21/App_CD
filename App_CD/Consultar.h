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
<<<<<<< HEAD
		ts = gcnew SqlConnectionStringBuilder();
		ts->DataSource = "DESKTOP-GJGNJ95\\SQLEXPRESS";
		ts->InitialCatalog = "Casa_dom";
		ts->IntegratedSecurity = "True";
=======
		ts = gcnew MySqlConnectionStringBuilder();
		ts->Server = "bvyfz6mfmtdrhrb6tfow-mysql.services.clever-cloud.com";
		ts->Database = "bvyfz6mfmtdrhrb6tfow";
		ts->UserID = "u1rkvy1adcgozdfu";
		ts->Password = "nL9p8U0gipad3TVVINH1";
		ts->SslMode = MySqlSslMode::Required;
>>>>>>> c867218 (Conexion remota Lista)

		connect = gcnew MySqlConnection(Convert::ToString(ts));
	}
public:
	static bool UserExists(String^ userName, String^ userPass)  //Ingresa con nombre de usuario
	{ //Abre una conexión a la BD y verifica si el usuario existe
		ObtenerDatos();
		
        String^ query = "SELECT COUNT(*) FROM usuario WHERE usuario = '" + userName + "' AND pass = '" + userPass + "'"; //Consulta el conteo de los usuarios registrados en la tabla Usuario
		MySqlCommand^ cmd = gcnew MySqlCommand(query, connect);
		connect->Open();
		int count = Convert::ToInt32(cmd->ExecuteScalar());
		connect->Close();
		if (count > 0)
			return true;
		else
			return false;
	}
};