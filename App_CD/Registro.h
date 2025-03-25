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
			this->SuspendLayout();
			// 
			// txbNombre
			// 
			this->txbNombre->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->txbNombre->Location = System::Drawing::Point(131, 30);
			this->txbNombre->Name = L"txbNombre";
			this->txbNombre->Size = System::Drawing::Size(100, 20);
			this->txbNombre->TabIndex = 0;
			// 
			// txbApellido
			// 
			this->txbApellido->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->txbApellido->Location = System::Drawing::Point(131, 66);
			this->txbApellido->Name = L"txbApellido";
			this->txbApellido->Size = System::Drawing::Size(100, 20);
			this->txbApellido->TabIndex = 1;
			// 
			// txbUserName
			// 
			this->txbUserName->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->txbUserName->Location = System::Drawing::Point(131, 108);
			this->txbUserName->Name = L"txbUserName";
			this->txbUserName->Size = System::Drawing::Size(100, 20);
			this->txbUserName->TabIndex = 2;
			this->toolTip1->SetToolTip(this->txbUserName, L"El nombre de usuario deberá ser de 10 caracteres alfanúmericos");
			// 
			// txbUserPass
			// 
			this->txbUserPass->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->txbUserPass->Location = System::Drawing::Point(131, 147);
			this->txbUserPass->Name = L"txbUserPass";
			this->txbUserPass->Size = System::Drawing::Size(100, 20);
			this->txbUserPass->TabIndex = 3;
			this->toolTip1->SetToolTip(this->txbUserPass, L"La contraseña deberá contener 10 caracteres alfanumericos, incluido un caracter e"
				L"special");
			// 
			// btnCompletar
			// 
			this->btnCompletar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnCompletar->Location = System::Drawing::Point(108, 226);
			this->btnCompletar->Name = L"btnCompletar";
			this->btnCompletar->Size = System::Drawing::Size(168, 23);
			this->btnCompletar->TabIndex = 4;
			this->btnCompletar->Text = L"Completar registro";
			this->btnCompletar->UseVisualStyleBackColor = true;
			this->btnCompletar->Click += gcnew System::EventHandler(this, &Registro::btnCompletar_Click);
			// 
			// lblNombreUsuario
			// 
			this->lblNombreUsuario->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblNombreUsuario->AutoSize = true;
			this->lblNombreUsuario->Location = System::Drawing::Point(52, 36);
			this->lblNombreUsuario->Name = L"lblNombreUsuario";
			this->lblNombreUsuario->Size = System::Drawing::Size(44, 13);
			this->lblNombreUsuario->TabIndex = 5;
			this->lblNombreUsuario->Text = L"Nombre";
			// 
			// lblApellidoUsuario
			// 
			this->lblApellidoUsuario->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblApellidoUsuario->AutoSize = true;
			this->lblApellidoUsuario->Location = System::Drawing::Point(52, 66);
			this->lblApellidoUsuario->Name = L"lblApellidoUsuario";
			this->lblApellidoUsuario->Size = System::Drawing::Size(44, 13);
			this->lblApellidoUsuario->TabIndex = 6;
			this->lblApellidoUsuario->Text = L"Apellido";
			// 
			// lblUsuario
			// 
			this->lblUsuario->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblUsuario->AutoSize = true;
			this->lblUsuario->Location = System::Drawing::Point(29, 108);
			this->lblUsuario->Name = L"lblUsuario";
			this->lblUsuario->Size = System::Drawing::Size(96, 13);
			this->lblUsuario->TabIndex = 7;
			this->lblUsuario->Text = L"Nombre de usuario";
			// 
			// lblContraseñaUsuario
			// 
			this->lblContraseñaUsuario->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblContraseñaUsuario->AutoSize = true;
			this->lblContraseñaUsuario->Location = System::Drawing::Point(55, 147);
			this->lblContraseñaUsuario->Name = L"lblContraseñaUsuario";
			this->lblContraseñaUsuario->Size = System::Drawing::Size(61, 13);
			this->lblContraseñaUsuario->TabIndex = 8;
			this->lblContraseñaUsuario->Text = L"Contraseña";
			// 
			// Registro
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(426, 299);
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