#pragma once
#include "Conexion.h"

namespace AppCD {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::Text::RegularExpressions;

	/// <summary>
	/// Resumen de Registro
	/// </summary>
	public ref class Registro : public System::Windows::Forms::Form
	{
	public:
		Registro(void)
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
		~Registro()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txbNombre;
	private: System::Windows::Forms::TextBox^ txbApellido;
	private: System::Windows::Forms::TextBox^ txbUserName;
	private: System::Windows::Forms::TextBox^ txbUserPass;


	protected:

	protected:



	private: System::Windows::Forms::Button^ btnCompletar;
	private: System::Windows::Forms::Label^ lblNombreUsuario;
	private: System::Windows::Forms::Label^ lblApellidoUsuario;
	private: System::Windows::Forms::Label^ lblUsuario;
	private: System::Windows::Forms::Label^ lblContraseñaUsuario;
	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::PictureBox^ pboLogoRegistro;
	private: System::Windows::Forms::PictureBox^ pboFlechaRegistro;
	private: System::Windows::Forms::Label^ lblRegistro;


	private: System::ComponentModel::IContainer^ components;






	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Registro::typeid));
			this->txbNombre = (gcnew System::Windows::Forms::TextBox());
			this->txbApellido = (gcnew System::Windows::Forms::TextBox());
			this->txbUserName = (gcnew System::Windows::Forms::TextBox());
			this->txbUserPass = (gcnew System::Windows::Forms::TextBox());
			this->btnCompletar = (gcnew System::Windows::Forms::Button());
			this->lblNombreUsuario = (gcnew System::Windows::Forms::Label());
			this->lblApellidoUsuario = (gcnew System::Windows::Forms::Label());
			this->lblUsuario = (gcnew System::Windows::Forms::Label());
			this->lblContraseñaUsuario = (gcnew System::Windows::Forms::Label());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->pboLogoRegistro = (gcnew System::Windows::Forms::PictureBox());
			this->pboFlechaRegistro = (gcnew System::Windows::Forms::PictureBox());
			this->lblRegistro = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pboLogoRegistro))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pboFlechaRegistro))->BeginInit();
			this->SuspendLayout();
			// 
			// txbNombre
			// 
			this->txbNombre->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->txbNombre->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txbNombre->Location = System::Drawing::Point(268, 246);
			this->txbNombre->Name = L"txbNombre";
			this->txbNombre->Size = System::Drawing::Size(130, 27);
			this->txbNombre->TabIndex = 0;
			// 
			// txbApellido
			// 
			this->txbApellido->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->txbApellido->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txbApellido->Location = System::Drawing::Point(268, 309);
			this->txbApellido->Name = L"txbApellido";
			this->txbApellido->Size = System::Drawing::Size(130, 27);
			this->txbApellido->TabIndex = 1;
			// 
			// txbUserName
			// 
			this->txbUserName->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->txbUserName->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txbUserName->Location = System::Drawing::Point(268, 366);
			this->txbUserName->Name = L"txbUserName";
			this->txbUserName->Size = System::Drawing::Size(130, 27);
			this->txbUserName->TabIndex = 2;
			this->toolTip1->SetToolTip(this->txbUserName, L"El nombre de usuario deberá ser de 10 caracteres alfanúmericos");
			// 
			// txbUserPass
			// 
			this->txbUserPass->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->txbUserPass->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txbUserPass->Location = System::Drawing::Point(268, 441);
			this->txbUserPass->Name = L"txbUserPass";
			this->txbUserPass->Size = System::Drawing::Size(130, 27);
			this->txbUserPass->TabIndex = 3;
			this->toolTip1->SetToolTip(this->txbUserPass, L"La contraseña deberá contener 10 caracteres alfanumericos, incluido un caracter e"
				L"special");
			// 
			// btnCompletar
			// 
			this->btnCompletar->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->btnCompletar->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnCompletar->ForeColor = System::Drawing::Color::ForestGreen;
			this->btnCompletar->Location = System::Drawing::Point(0, 479);
			this->btnCompletar->Name = L"btnCompletar";
			this->btnCompletar->Size = System::Drawing::Size(681, 34);
			this->btnCompletar->TabIndex = 4;
			this->btnCompletar->Text = L"Completar registro";
			this->btnCompletar->UseVisualStyleBackColor = true;
			this->btnCompletar->Click += gcnew System::EventHandler(this, &Registro::btnCompletar_Click);
			// 
			// lblNombreUsuario
			// 
			this->lblNombreUsuario->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblNombreUsuario->AutoSize = true;
			this->lblNombreUsuario->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblNombreUsuario->ForeColor = System::Drawing::Color::ForestGreen;
			this->lblNombreUsuario->Location = System::Drawing::Point(264, 220);
			this->lblNombreUsuario->Name = L"lblNombreUsuario";
			this->lblNombreUsuario->Size = System::Drawing::Size(69, 23);
			this->lblNombreUsuario->TabIndex = 5;
			this->lblNombreUsuario->Text = L"Nombre";
			// 
			// lblApellidoUsuario
			// 
			this->lblApellidoUsuario->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblApellidoUsuario->AutoSize = true;
			this->lblApellidoUsuario->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblApellidoUsuario->ForeColor = System::Drawing::Color::ForestGreen;
			this->lblApellidoUsuario->Location = System::Drawing::Point(264, 283);
			this->lblApellidoUsuario->Name = L"lblApellidoUsuario";
			this->lblApellidoUsuario->Size = System::Drawing::Size(70, 23);
			this->lblApellidoUsuario->TabIndex = 6;
			this->lblApellidoUsuario->Text = L"Apellido";
			// 
			// lblUsuario
			// 
			this->lblUsuario->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblUsuario->AutoSize = true;
			this->lblUsuario->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblUsuario->ForeColor = System::Drawing::Color::ForestGreen;
			this->lblUsuario->Location = System::Drawing::Point(264, 340);
			this->lblUsuario->Name = L"lblUsuario";
			this->lblUsuario->Size = System::Drawing::Size(150, 23);
			this->lblUsuario->TabIndex = 7;
			this->lblUsuario->Text = L"Nombre de usuario";
			// 
			// lblContraseñaUsuario
			// 
			this->lblContraseñaUsuario->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblContraseñaUsuario->AutoSize = true;
			this->lblContraseñaUsuario->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblContraseñaUsuario->ForeColor = System::Drawing::Color::ForestGreen;
			this->lblContraseñaUsuario->Location = System::Drawing::Point(265, 405);
			this->lblContraseñaUsuario->Name = L"lblContraseñaUsuario";
			this->lblContraseñaUsuario->Size = System::Drawing::Size(95, 23);
			this->lblContraseñaUsuario->TabIndex = 8;
			this->lblContraseñaUsuario->Text = L"Contraseña";
			// 
			// pboLogoRegistro
			// 
			this->pboLogoRegistro->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pboLogoRegistro->BackColor = System::Drawing::SystemColors::Control;
			this->pboLogoRegistro->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pboLogoRegistro.Image")));
			this->pboLogoRegistro->Location = System::Drawing::Point(258, 0);
			this->pboLogoRegistro->Margin = System::Windows::Forms::Padding(0);
			this->pboLogoRegistro->Name = L"pboLogoRegistro";
			this->pboLogoRegistro->Size = System::Drawing::Size(140, 140);
			this->pboLogoRegistro->TabIndex = 9;
			this->pboLogoRegistro->TabStop = false;
			// 
			// pboFlechaRegistro
			// 
			this->pboFlechaRegistro->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pboFlechaRegistro->BackColor = System::Drawing::SystemColors::Control;
			this->pboFlechaRegistro->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pboFlechaRegistro.Image")));
			this->pboFlechaRegistro->Location = System::Drawing::Point(210, 152);
			this->pboFlechaRegistro->Name = L"pboFlechaRegistro";
			this->pboFlechaRegistro->Size = System::Drawing::Size(42, 42);
			this->pboFlechaRegistro->TabIndex = 10;
			this->pboFlechaRegistro->TabStop = false;
			// 
			// lblRegistro
			// 
			this->lblRegistro->AutoSize = true;
			this->lblRegistro->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblRegistro->ForeColor = System::Drawing::Color::ForestGreen;
			this->lblRegistro->Location = System::Drawing::Point(271, 165);
			this->lblRegistro->Name = L"lblRegistro";
			this->lblRegistro->Size = System::Drawing::Size(90, 29);
			this->lblRegistro->TabIndex = 12;
			this->lblRegistro->Text = L"Registro";
			// 
			// Registro
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(681, 513);
			this->Controls->Add(this->lblRegistro);
			this->Controls->Add(this->pboFlechaRegistro);
			this->Controls->Add(this->pboLogoRegistro);
			this->Controls->Add(this->lblContraseñaUsuario);
			this->Controls->Add(this->lblUsuario);
			this->Controls->Add(this->lblApellidoUsuario);
			this->Controls->Add(this->lblNombreUsuario);
			this->Controls->Add(this->btnCompletar);
			this->Controls->Add(this->txbUserPass);
			this->Controls->Add(this->txbUserName);
			this->Controls->Add(this->txbApellido);
			this->Controls->Add(this->txbNombre);
			this->Name = L"Registro";
			this->Text = L"Registro";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pboLogoRegistro))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pboFlechaRegistro))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnCompletar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ Nombre_usuario = txbNombre->Text;
		String^ Apellido_usuario = txbApellido->Text;
		String^ UserName = txbUserName->Text;
		String^ UserPass = txbUserPass->Text;

		String^ patron_User = "^[0-9,A-z]{10}$";
		String^ patron_Pass = "^[0-9,A-z]{9}([!#$%&.?¿]{1})$";

		///*Regex^ regexUser = gcnew Regex(patron_User);
		//Regex^ regexUser = gcnew Regex(patron_Pass);*/

		if (!String::IsNullOrEmpty(Nombre_usuario) && !String::IsNullOrEmpty(Apellido_usuario) && !String::IsNullOrEmpty(UserName) && !String::IsNullOrEmpty(UserPass)) //Compara la expresión regular con las cadenas de texto proporcionadas por el usuario
		{
			if (Regex::IsMatch(UserName, patron_User) && Regex::IsMatch(UserPass, patron_Pass))
			{

				if (!Consultar::UsuarioExists(UserName)) //Verfica Si el usuario existe en la BD 
					//Metodo proveniente de la clase Consultar
				{
					conexion procesardatos;
					procesardatos.Insertar(txbNombre->Text, txbApellido->Text, txbUserName->Text, txbUserPass->Text);
					MessageBox::Show("Registro exitoso " + UserName + "\n" + "Ya puede cerrar esta ventana ");
					txbNombre->Clear();
					txbApellido->Clear();
					txbUserName->Clear();
					txbUserPass->Clear(); //Limpia los campos de texto
				}
				else
				{
					MessageBox::Show("Usuario existente, elija otro");
				}
			}
			else
			{
				MessageBox::Show("Revise usuario y contraseña de nuevo");
			}
			
		}
		else
		{
			MessageBox::Show("Favor de llenar todos los campos ");
		}
	}
};
}