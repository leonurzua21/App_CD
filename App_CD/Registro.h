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
			this->txbNombre = (gcnew System::Windows::Forms::TextBox());
			this->txbApellido = (gcnew System::Windows::Forms::TextBox());
			this->txbUserName = (gcnew System::Windows::Forms::TextBox());
			this->txbUserPass = (gcnew System::Windows::Forms::TextBox());
			this->btnCompletar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txbNombre
			// 
			this->txbNombre->Location = System::Drawing::Point(133, 51);
			this->txbNombre->Name = L"txbNombre";
			this->txbNombre->Size = System::Drawing::Size(100, 20);
			this->txbNombre->TabIndex = 0;
			// 
			// txbApellido
			// 
			this->txbApellido->Location = System::Drawing::Point(133, 87);
			this->txbApellido->Name = L"txbApellido";
			this->txbApellido->Size = System::Drawing::Size(100, 20);
			this->txbApellido->TabIndex = 1;
			// 
			// txbUserName
			// 
			this->txbUserName->Location = System::Drawing::Point(133, 129);
			this->txbUserName->Name = L"txbUserName";
			this->txbUserName->Size = System::Drawing::Size(100, 20);
			this->txbUserName->TabIndex = 2;
			// 
			// txbUserPass
			// 
			this->txbUserPass->Location = System::Drawing::Point(133, 168);
			this->txbUserPass->Name = L"txbUserPass";
			this->txbUserPass->Size = System::Drawing::Size(100, 20);
			this->txbUserPass->TabIndex = 3;
			// 
			// btnCompletar
			// 
			this->btnCompletar->Location = System::Drawing::Point(110, 247);
			this->btnCompletar->Name = L"btnCompletar";
			this->btnCompletar->Size = System::Drawing::Size(168, 23);
			this->btnCompletar->TabIndex = 4;
			this->btnCompletar->Text = L"Completar registro";
			this->btnCompletar->UseVisualStyleBackColor = true;
			this->btnCompletar->Click += gcnew System::EventHandler(this, &Registro::btnCompletar_Click);
			// 
			// Registro
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(430, 340);
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
				conexion procesardatos;
				procesardatos.Insertar(txbNombre->Text, txbApellido->Text, txbUserName->Text, txbUserPass->Text);
				MessageBox::Show("Registro exitoso " + UserName  +"\n" + "Ya puede cerrar esta ventana ");
				txbNombre->Clear();
				txbApellido->Clear();
				txbUserName->Clear();
				txbUserPass->Clear(); //Limpia los campos de texto
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
