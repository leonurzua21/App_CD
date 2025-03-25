#pragma once

using namespace System;
using namespace System::Configuration;
using namespace System::Data;
using namespace MySql::Data;
using namespace MySqlClient;

ref class conexion
{
    MySqlConnection^ conecta;
    MySqlConnectionStringBuilder^ st;
public:
    conexion();

protected:
    void Conectar()
	{
<<<<<<< HEAD
		st = gcnew SqlConnectionStringBuilder();
		st->DataSource = "192.168.1.73"; //Base de datos remota
		st->InitialCatalog = "Casa_dom";
		st->UserID = "Test";
		st->Password = "pbadatab2024!";       
=======
        st = gcnew MySqlConnectionStringBuilder();
        st->Server = "bvyfz6mfmtdrhrb6tfow-mysql.services.clever-cloud.com";
        st->Database = "bvyfz6mfmtdrhrb6tfow";
        st->UserID = "u1rkvy1adcgozdfu";
        st->Password = "nL9p8U0gipad3TVVINH1";
        st->SslMode = MySqlSslMode::Required;
>>>>>>> c867218 (Conexion remota Lista)

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
        MySqlCommand^ ejecutar = gcnew MySqlCommand(enviardatos, conecta);
        ejecutar->Parameters->AddWithValue("@nombre",nombre);
        ejecutar->Parameters->AddWithValue("@apellido",apellido);
        ejecutar->Parameters->AddWithValue("@usuario",UserName);
        ejecutar->Parameters->AddWithValue("@pass",UserPass);

<<<<<<< HEAD
        conecta->Open();
        ejecutar->ExecuteNonQuery();
        conecta->Close();
=======
        try {
            conecta->Open();
            ejecutar->ExecuteNonQuery();
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error: " + ex->Message);
        }
        finally {
            conecta->Close();
        }
>>>>>>> c867218 (Conexion remota Lista)
    }
};