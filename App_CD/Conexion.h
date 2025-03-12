#pragma once

using namespace System;
using namespace System::Configuration;
using namespace System::Data;
using namespace System::Data::SqlClient;

ref class conexion
{
    SqlConnection^ conecta;
    SqlConnectionStringBuilder^ st;
public:
    conexion();

protected:
    void Conectar()
	{
		st = gcnew SqlConnectionStringBuilder();
		st->DataSource = "DESKTOP-GJGNJ95\\SQLEXPRESS";
		st->InitialCatalog = "Casa_dom";
		st->IntegratedSecurity = "True";
       

        conecta = gcnew SqlConnection(Convert::ToString(st));
    }
public:
    void Insertar(String^ nombre, String^ apellido, String^ UserName, String^ UserPass)
    {
        if (conecta == nullptr)
        {
            Conectar();
        }

        String^ enviardatos = "Insert into Usuario values (@nombre,@apellido,@usuario,@pass)";
        SqlCommand^ ejecutar = gcnew SqlCommand(enviardatos, conecta);
        ejecutar->Parameters->AddWithValue("@nombre",nombre);
        ejecutar->Parameters->AddWithValue("@apellido",apellido);
        ejecutar->Parameters->AddWithValue("@usuario",UserName);
        ejecutar->Parameters->AddWithValue("@pass",UserPass);

        conecta->Open();
        ejecutar->ExecuteNonQuery();
        conecta->Close();
    }
};