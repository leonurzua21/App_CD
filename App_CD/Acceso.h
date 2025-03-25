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
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
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
	private: System::Windows::Forms::Label^ lblContraseña;
	protected:


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txbUserName = (gcnew System::Windows::Forms::TextBox());
			this->txbPass = (gcnew System::Windows::Forms::TextBox());
			this->btnAcceder = (gcnew System::Windows::Forms::Button());
			this->btnRegistro = (gcnew System::Windows::Forms::Button());
			this->lblNombreUsuario = (gcnew System::Windows::Forms::Label());
			this->lblContraseña = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txbUserName
			// 
			this->txbUserName->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->txbUserName->Location = System::Drawing::Point(163, 73);
			this->txbUserName->Name = L"txbUserName";
			this->txbUserName->Size = System::Drawing::Size(100, 20);
			this->txbUserName->TabIndex = 0;
			// 
			// txbPass
			// 
			this->txbPass->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->txbPass->Location = System::Drawing::Point(163, 152);
			this->txbPass->Name = L"txbPass";
			this->txbPass->Size = System::Drawing::Size(100, 20);
			this->txbPass->TabIndex = 1;
			// 
			// btnAcceder
			// 
			this->btnAcceder->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnAcceder->Location = System::Drawing::Point(163, 223);
			this->btnAcceder->Name = L"btnAcceder";
			this->btnAcceder->Size = System::Drawing::Size(75, 23);
			this->btnAcceder->TabIndex = 2;
			this->btnAcceder->Text = L"Acceder";
			this->btnAcceder->UseVisualStyleBackColor = true;
			this->btnAcceder->Click += gcnew System::EventHandler(this, &Acceso::btnAcceder_Click);
			// 
			// btnRegistro
			// 
			this->btnRegistro->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnRegistro->Location = System::Drawing::Point(344, 266);
			this->btnRegistro->Name = L"btnRegistro";
			this->btnRegistro->Size = System::Drawing::Size(75, 23);
			this->btnRegistro->TabIndex = 3;
			this->btnRegistro->Text = L"Registrarse";
			this->btnRegistro->UseVisualStyleBackColor = true;
			this->btnRegistro->Click += gcnew System::EventHandler(this, &Acceso::btnRegistro_Click);
			// 
			// lblNombreUsuario
			// 
			this->lblNombreUsuario->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblNombreUsuario->AutoSize = true;
			this->lblNombreUsuario->Location = System::Drawing::Point(48, 79);
			this->lblNombreUsuario->Name = L"lblNombreUsuario";
			this->lblNombreUsuario->Size = System::Drawing::Size(96, 13);
			this->lblNombreUsuario->TabIndex = 4;
			this->lblNombreUsuario->Text = L"Nombre de usuario";
			// 
			// lblContraseña
			// 
			this->lblContraseña->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblContraseña->AutoSize = true;
			this->lblContraseña->Location = System::Drawing::Point(51, 158);
			this->lblContraseña->Name = L"lblContraseña";
			this->lblContraseña->Size = System::Drawing::Size(61, 13);
			this->lblContraseña->TabIndex = 5;
			this->lblContraseña->Text = L"Contraseña";
			// 
			// Acceso
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(456, 343);
			this->Controls->Add(this->lblContraseña);
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

		if (!String::IsNullOrEmpty(User) && !String::IsNullOrEmpty(Pass)) //Compara la expresión regular con las cadenas de texto proporcionadas por el usuario
		{
			if (Consultar::CredencialesExists(User,Pass)) //Verfica Si el usuario existe en la BD
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
				MessageBox::Show("Usuario o contraseña incorrectos.\nSi no está registrado, haga clic en el botón de Registro.");
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
