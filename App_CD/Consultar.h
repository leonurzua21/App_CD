#pragma once
using namespace System;
using namespace System::Configuration;
using namespace System::Data;
using namespace System::Data::SqlClient;

ref class Consultar
{
	static SqlConnection^ connect;
	static SqlConnectionStringBuilder^ ts;
public:
	Consultar();
protected:
	static void 
		ObtenerDatos()
	{
		ts = gcnew SqlConnectionStringBuilder();
		ts->DataSource = "DESKTOP-GJGNJ95\\SQLEXPRESS";
		ts->InitialCatalog = "pba";
		ts->IntegratedSecurity = "True";

		connect = gcnew SqlConnection(Convert::ToString(ts));
	}
public:
	static bool UserExists(String^ user) 
	{ //Abre una conexión a la BD y verifica si el usuario existe
		ObtenerDatos();
		
		String^ query = "SELECT COUNT(*) FROM Usuario WHERE nombre = '" + user + "'";
		SqlCommand^ cmd = gcnew SqlCommand(query, connect);
		connect->Open();
		int count = (int)cmd->ExecuteScalar();
		connect->Close();
		if (count > 0)
			return true;
		else
			return false;
		}
};