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
	private: System::Windows::Forms::PictureBox^ pboLogoAcceso;

	private: System::Windows::Forms::PictureBox^ pboFlechaIniciosesion;
	private: System::Windows::Forms::Label^ lblSesion;
	private: System::Windows::Forms::Label^ lblRegistroCuenta;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Acceso::typeid));
			this->txbUserName = (gcnew System::Windows::Forms::TextBox());
			this->txbPass = (gcnew System::Windows::Forms::TextBox());
			this->btnAcceder = (gcnew System::Windows::Forms::Button());
			this->btnRegistro = (gcnew System::Windows::Forms::Button());
			this->lblNombreUsuario = (gcnew System::Windows::Forms::Label());
			this->lblContraseña = (gcnew System::Windows::Forms::Label());
			this->pboLogoAcceso = (gcnew System::Windows::Forms::PictureBox());
			this->pboFlechaIniciosesion = (gcnew System::Windows::Forms::PictureBox());
			this->lblSesion = (gcnew System::Windows::Forms::Label());
			this->lblRegistroCuenta = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pboLogoAcceso))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pboFlechaIniciosesion))->BeginInit();
			this->SuspendLayout();
			// 
			// txbUserName
			// 
			this->txbUserName->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->txbUserName->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txbUserName->Location = System::Drawing::Point(260, 289);
			this->txbUserName->Name = L"txbUserName";
			this->txbUserName->Size = System::Drawing::Size(130, 27);
			this->txbUserName->TabIndex = 0;
			// 
			// txbPass
			// 
			this->txbPass->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->txbPass->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txbPass->Location = System::Drawing::Point(260, 370);
			this->txbPass->Name = L"txbPass";
			this->txbPass->Size = System::Drawing::Size(130, 27);
			this->txbPass->TabIndex = 1;
			// 
			// btnAcceder
			// 
			this->btnAcceder->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnAcceder->BackColor = System::Drawing::SystemColors::Control;
			this->btnAcceder->FlatAppearance->BorderColor = System::Drawing::SystemColors::ControlText;
			this->btnAcceder->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnAcceder->ForeColor = System::Drawing::Color::ForestGreen;
			this->btnAcceder->Location = System::Drawing::Point(263, 412);
			this->btnAcceder->Name = L"btnAcceder";
			this->btnAcceder->Size = System::Drawing::Size(127, 40);
			this->btnAcceder->TabIndex = 2;
			this->btnAcceder->Text = L"Ingresar";
			this->btnAcceder->UseVisualStyleBackColor = false;
			this->btnAcceder->Click += gcnew System::EventHandler(this, &Acceso::btnAcceder_Click);
			// 
			// btnRegistro
			// 
			this->btnRegistro->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnRegistro->BackColor = System::Drawing::SystemColors::Control;
			this->btnRegistro->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnRegistro->ForeColor = System::Drawing::Color::ForestGreen;
			this->btnRegistro->Location = System::Drawing::Point(16, 455);
			this->btnRegistro->Name = L"btnRegistro";
			this->btnRegistro->Size = System::Drawing::Size(134, 37);
			this->btnRegistro->TabIndex = 3;
			this->btnRegistro->Text = L"Registrarse";
			this->btnRegistro->UseVisualStyleBackColor = false;
			this->btnRegistro->Click += gcnew System::EventHandler(this, &Acceso::btnRegistro_Click);
			// 
			// lblNombreUsuario
			// 
			this->lblNombreUsuario->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblNombreUsuario->AutoSize = true;
			this->lblNombreUsuario->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblNombreUsuario->ForeColor = System::Drawing::Color::ForestGreen;
			this->lblNombreUsuario->Location = System::Drawing::Point(258, 254);
			this->lblNombreUsuario->Margin = System::Windows::Forms::Padding(0);
			this->lblNombreUsuario->Name = L"lblNombreUsuario";
			this->lblNombreUsuario->Size = System::Drawing::Size(66, 23);
			this->lblNombreUsuario->TabIndex = 4;
			this->lblNombreUsuario->Text = L"Usuario";
			// 
			// lblContraseña
			// 
			this->lblContraseña->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblContraseña->AutoSize = true;
			this->lblContraseña->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblContraseña->ForeColor = System::Drawing::Color::ForestGreen;
			this->lblContraseña->Location = System::Drawing::Point(258, 334);
			this->lblContraseña->Margin = System::Windows::Forms::Padding(0);
			this->lblContraseña->Name = L"lblContraseña";
			this->lblContraseña->Size = System::Drawing::Size(95, 23);
			this->lblContraseña->TabIndex = 5;
			this->lblContraseña->Text = L"Contraseña";
			// 
			// pboLogoAcceso
			// 
			this->pboLogoAcceso->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pboLogoAcceso->BackColor = System::Drawing::SystemColors::Control;
			this->pboLogoAcceso->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pboLogoAcceso.Image")));
			this->pboLogoAcceso->Location = System::Drawing::Point(260, 0);
			this->pboLogoAcceso->Margin = System::Windows::Forms::Padding(0);
			this->pboLogoAcceso->Name = L"pboLogoAcceso";
			this->pboLogoAcceso->Size = System::Drawing::Size(140, 140);
			this->pboLogoAcceso->TabIndex = 6;
			this->pboLogoAcceso->TabStop = false;
			// 
			// pboFlechaIniciosesion
			// 
			this->pboFlechaIniciosesion->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pboFlechaIniciosesion->BackColor = System::Drawing::SystemColors::Control;
			this->pboFlechaIniciosesion->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pboFlechaIniciosesion.Image")));
			this->pboFlechaIniciosesion->Location = System::Drawing::Point(200, 175);
			this->pboFlechaIniciosesion->Name = L"pboFlechaIniciosesion";
			this->pboFlechaIniciosesion->Size = System::Drawing::Size(42, 42);
			this->pboFlechaIniciosesion->TabIndex = 7;
			this->pboFlechaIniciosesion->TabStop = false;
			// 
			// lblSesion
			// 
			this->lblSesion->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblSesion->AutoSize = true;
			this->lblSesion->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSesion->ForeColor = System::Drawing::Color::ForestGreen;
			this->lblSesion->Location = System::Drawing::Point(255, 183);
			this->lblSesion->Margin = System::Windows::Forms::Padding(0);
			this->lblSesion->Name = L"lblSesion";
			this->lblSesion->Size = System::Drawing::Size(140, 29);
			this->lblSesion->TabIndex = 8;
			this->lblSesion->Text = L"Iniciar Sesión";
			// 
			// lblRegistroCuenta
			// 
			this->lblRegistroCuenta->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblRegistroCuenta->AutoSize = true;
			this->lblRegistroCuenta->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblRegistroCuenta->ForeColor = System::Drawing::Color::ForestGreen;
			this->lblRegistroCuenta->Location = System::Drawing::Point(12, 422);
			this->lblRegistroCuenta->Name = L"lblRegistroCuenta";
			this->lblRegistroCuenta->Size = System::Drawing::Size(147, 23);
			this->lblRegistroCuenta->TabIndex = 9;
			this->lblRegistroCuenta->Text = L"¿No tienes cuenta\?";
			// 
			// Acceso
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(681, 513);
			this->Controls->Add(this->lblRegistroCuenta);
			this->Controls->Add(this->lblSesion);
			this->Controls->Add(this->pboFlechaIniciosesion);
			this->Controls->Add(this->pboLogoAcceso);
			this->Controls->Add(this->lblContraseña);
			this->Controls->Add(this->lblNombreUsuario);
			this->Controls->Add(this->btnRegistro);
			this->Controls->Add(this->btnAcceder);
			this->Controls->Add(this->txbPass);
			this->Controls->Add(this->txbUserName);
			this->Name = L"Acceso";
			this->Text = L"Iniciar sesión";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pboLogoAcceso))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pboFlechaIniciosesion))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

    private: System::Void btnAcceder_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ User = txbUserName->Text;
		String^ Pass = txbPass->Text;

		if (!String::IsNullOrEmpty(User) && !String::IsNullOrEmpty(Pass)) //Compara la expresión regular con las cadenas de texto proporcionadas por el usuario
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
