#pragma once
#include <string.h>
#include <regex>	
#include <iostream>
#include "Registro.h"
#include "Consultar.h"
#include "AppUsuario.h"


namespace AppCD {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;
	using namespace AppCD;
	
	
	/// <summary>
	/// Resumen de Acceso
	/// </summary>
	public ref class Acceso : public System::Windows::Forms::Form
	{
	public:
		Acceso(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~Acceso()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txbUserName;
	protected:

	private: System::Windows::Forms::TextBox^ txbPass;
	private: System::Windows::Forms::Button^ btnAcceder;
	private: System::Windows::Forms::Button^ btnRegistro;
	private: System::Windows::Forms::Label^ lblNombreUsuario;
	private: System::Windows::Forms::Label^ lblContrase�a;
	protected:


	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txbUserName = (gcnew System::Windows::Forms::TextBox());
			this->txbPass = (gcnew System::Windows::Forms::TextBox());
			this->btnAcceder = (gcnew System::Windows::Forms::Button());
			this->btnRegistro = (gcnew System::Windows::Forms::Button());
			this->lblNombreUsuario = (gcnew System::Windows::Forms::Label());
			this->lblContrase�a = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txbUserName
			// 
			this->txbUserName->Location = System::Drawing::Point(166, 87);
			this->txbUserName->Name = L"txbUserName";
			this->txbUserName->Size = System::Drawing::Size(100, 20);
			this->txbUserName->TabIndex = 0;
			// 
			// txbPass
			// 
			this->txbPass->Location = System::Drawing::Point(166, 166);
			this->txbPass->Name = L"txbPass";
			this->txbPass->Size = System::Drawing::Size(100, 20);
			this->txbPass->TabIndex = 1;
			// 
			// btnAcceder
			// 
			this->btnAcceder->Location = System::Drawing::Point(166, 237);
			this->btnAcceder->Name = L"btnAcceder";
			this->btnAcceder->Size = System::Drawing::Size(75, 23);
			this->btnAcceder->TabIndex = 2;
			this->btnAcceder->Text = L"Acceder";
			this->btnAcceder->UseVisualStyleBackColor = true;
			this->btnAcceder->Click += gcnew System::EventHandler(this, &Acceso::btnAcceder_Click);
			// 
			// btnRegistro
			// 
			this->btnRegistro->Location = System::Drawing::Point(351, 293);
			this->btnRegistro->Name = L"btnRegistro";
			this->btnRegistro->Size = System::Drawing::Size(75, 23);
			this->btnRegistro->TabIndex = 3;
			this->btnRegistro->Text = L"Registrarse";
			this->btnRegistro->UseVisualStyleBackColor = true;
			this->btnRegistro->Click += gcnew System::EventHandler(this, &Acceso::btnRegistro_Click);
			// 
			// lblNombreUsuario
			// 
			this->lblNombreUsuario->AutoSize = true;
			this->lblNombreUsuario->Location = System::Drawing::Point(51, 93);
			this->lblNombreUsuario->Name = L"lblNombreUsuario";
			this->lblNombreUsuario->Size = System::Drawing::Size(96, 13);
			this->lblNombreUsuario->TabIndex = 4;
			this->lblNombreUsuario->Text = L"Nombre de usuario";
			// 
			// lblContrase�a
			// 
			this->lblContrase�a->AutoSize = true;
			this->lblContrase�a->Location = System::Drawing::Point(54, 172);
			this->lblContrase�a->Name = L"lblContrase�a";
			this->lblContrase�a->Size = System::Drawing::Size(61, 13);
			this->lblContrase�a->TabIndex = 5;
			this->lblContrase�a->Text = L"Contrase�a";
			// 
			// Acceso
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(463, 370);
			this->Controls->Add(this->lblContrase�a);
			this->Controls->Add(this->lblNombreUsuario);
			this->Controls->Add(this->btnRegistro);
			this->Controls->Add(this->btnAcceder);
			this->Controls->Add(this->txbPass);
			this->Controls->Add(this->txbUserName);
			this->Name = L"Acceso";
			this->Text = L"Acceso";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

    private: System::Void btnAcceder_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ User = txbUserName->Text;
		String^ Pass = txbPass->Text;

		if (!String::IsNullOrEmpty(User) && !String::IsNullOrEmpty(Pass)) //Compara la expresi�n regular con las cadenas de texto proporcionadas por el usuario
		{
			if (Consultar::UserExists(User, Pass)) //Verfica Si el usuario existe en la BD
			{
				MessageBox::Show("Bienvenid@ " + User);
				txbUserName->Clear();
				txbPass->Clear(); //Limpia los campos de texto

				AppCD::AppUsuario^ vistaprincipal = gcnew AppCD::AppUsuario();
				vistaprincipal->Show(); //Muestra el formulario de control de la casa domotica
				AppCD::Acceso^ ocultarformulario = gcnew AppCD::Acceso();
				ocultarformulario->Close();
			}
			else
			{
				MessageBox::Show("Usuario o contrase�a incorrectos.\nSi no est� registrado, haga clic en el bot�n de Registro.");
			}
		}
		else
		{
			MessageBox::Show("Favor de llenar todos los campos");
		}
    }
	private: System::Void btnRegistro_Click(System::Object^ sender, System::EventArgs^ e) {
		AppCD::Registro^ form2 = gcnew AppCD::Registro();
		form2->Show();
	}
};
}
