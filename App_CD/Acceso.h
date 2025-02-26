#pragma once
#include <string.h>
#include <regex>	
#include <iostream>
#include "Registro.h"


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
	private: System::Windows::Forms::TextBox^ txbUser;
	private: System::Windows::Forms::TextBox^ txbPass;
	private: System::Windows::Forms::Button^ btnAcceder;
	private: System::Windows::Forms::Button^ btnRegistro;
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
			this->txbUser = (gcnew System::Windows::Forms::TextBox());
			this->txbPass = (gcnew System::Windows::Forms::TextBox());
			this->btnAcceder = (gcnew System::Windows::Forms::Button());
			this->btnRegistro = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txbUser
			// 
			this->txbUser->Location = System::Drawing::Point(166, 87);
			this->txbUser->Name = L"txbUser";
			this->txbUser->Size = System::Drawing::Size(100, 20);
			this->txbUser->TabIndex = 0;
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
			// Acceso
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(463, 370);
			this->Controls->Add(this->btnRegistro);
			this->Controls->Add(this->btnAcceder);
			this->Controls->Add(this->txbPass);
			this->Controls->Add(this->txbUser);
			this->Name = L"Acceso";
			this->Text = L"Acceso";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnAcceder_Click(System::Object^ sender, System::EventArgs^ e) {		
		String^ User = txbUser->Text;
		String^ Pass = txbPass->Text;

		 
		if (!String::IsNullOrEmpty(User) && !String::IsNullOrEmpty(Pass)) //Compara la expresión regular con las cadenas de texto proporcionadas por el usuario
		{
			MessageBox::Show("Bienvenido " + User);
		}
		else
		{
			MessageBox::Show("Llene todos los campos");
		}
	}
	private: System::Void btnRegistro_Click(System::Object^ sender, System::EventArgs^ e) {
		AppCD::Registro^ form2 = gcnew AppCD::Registro();
		form2->Show();
	}
};
}
