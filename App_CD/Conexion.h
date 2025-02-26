#pragma once

using namespace System;
using namespace System::Configuration;
using namespace System::Data;
using namespace System::Data::SqlClient;

ref class conexion
{
    SqlConnection^ cn;
    SqlConnectionStringBuilder^ st;
public:
    conexion();

protected:
    void Conectar()
	{

		st = gcnew SqlConnectionStringBuilder();
		st->DataSource = "DESKTOP-GJGNJ95\\SQLEXPRESS";
		st->InitialCatalog = "pba";
		st->IntegratedSecurity = "True";
        

        cn = gcnew SqlConnection(Convert::ToString(st));
    }
public:
    void Insertar(String^ nombre, String^ apellido, String^ UserName, String^ UserPass)
    {
        if (cn == nullptr)
        {
            Conectar();
        }

        String^ enviardatos = "Insert into Usuario values (@nombre,@apellido,@usuario,@pass)";
        SqlCommand^ ejecutar = gcnew SqlCommand(enviardatos, cn);
        ejecutar->Parameters->AddWithValue("@nombre",nombre);
        ejecutar->Parameters->AddWithValue("@apellido",apellido);
        ejecutar->Parameters->AddWithValue("@usuario",UserName);
        ejecutar->Parameters->AddWithValue("@pass",UserPass);

        cn->Open();
        ejecutar->ExecuteNonQuery();
        cn->Close();


    }
};