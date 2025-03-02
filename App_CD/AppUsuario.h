#pragma once
#include "Comunicacion.h"
#include <array>

namespace AppCD {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de AppUsuario
	/// </summary>
	public ref class AppUsuario : public System::Windows::Forms::Form
	{
	public:
		AppUsuario(void)
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
		~AppUsuario()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:
	private: System::Windows::Forms::Label^ lblcomunicacion;
	private: System::Windows::Forms::ComboBox^ cboPlaca;
	private: System::Windows::Forms::Button^ btnConectar;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnOnOffLEDS;



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
			this->lblcomunicacion = (gcnew System::Windows::Forms::Label());
			this->cboPlaca = (gcnew System::Windows::Forms::ComboBox());
			this->btnConectar = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnOnOffLEDS = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblcomunicacion
			// 
			this->lblcomunicacion->AutoSize = true;
			this->lblcomunicacion->Location = System::Drawing::Point(12, 9);
			this->lblcomunicacion->Name = L"lblcomunicacion";
			this->lblcomunicacion->Size = System::Drawing::Size(31, 13);
			this->lblcomunicacion->TabIndex = 1;
			this->lblcomunicacion->Text = L"COM";
			// 
			// cboPlaca
			// 
			this->cboPlaca->FormattingEnabled = true;
			this->cboPlaca->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"Arduino Uno" });
			this->cboPlaca->Location = System::Drawing::Point(12, 25);
			this->cboPlaca->Name = L"cboPlaca";
			this->cboPlaca->Size = System::Drawing::Size(121, 21);
			this->cboPlaca->TabIndex = 2;
			this->cboPlaca->SelectedIndexChanged += gcnew System::EventHandler(this, &AppUsuario::cboPlaca_SelectedIndexChanged);
			// 
			// btnConectar
			// 
			this->btnConectar->Location = System::Drawing::Point(15, 61);
			this->btnConectar->Name = L"btnConectar";
			this->btnConectar->Size = System::Drawing::Size(75, 23);
			this->btnConectar->TabIndex = 3;
			this->btnConectar->Text = L"Conectar";
			this->btnConectar->UseVisualStyleBackColor = true;
			this->btnConectar->Click += gcnew System::EventHandler(this, &AppUsuario::btnConectar_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(294, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Luces LEDS";
			// 
			// btnOnOffLEDS
			// 
			this->btnOnOffLEDS->Location = System::Drawing::Point(286, 61);
			this->btnOnOffLEDS->Name = L"btnOnOffLEDS";
			this->btnOnOffLEDS->Size = System::Drawing::Size(75, 23);
			this->btnOnOffLEDS->TabIndex = 5;
			this->btnOnOffLEDS->Text = L"OFF";
			this->btnOnOffLEDS->UseVisualStyleBackColor = true;
			this->btnOnOffLEDS->Click += gcnew System::EventHandler(this, &AppUsuario::btnOnOffLEDS_Click);
			// 
			// AppUsuario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(596, 308);
			this->Controls->Add(this->btnOnOffLEDS);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnConectar);
			this->Controls->Add(this->cboPlaca);
			this->Controls->Add(this->lblcomunicacion);
			this->Name = L"AppUsuario";
			this->Text = L"AppUsuario";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
    private: System::Void cboPlaca_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {  
		array<String^>^ desarrolladores = gcnew cli::array<String^> { "Arduino Uno","Arduino Leonardo"}; //Se pueden agregar más argumentos en el arreglo si desea agregar más placas de desarrollo ARDUINO

        // Mostrar el valor seleccionado  
        MessageBox::Show("Placa seleccionada: " + desarrolladores[0]); //Accede al elemento 0 del arreglo declarado
    }
	private: System::Void btnConectar_Click(System::Object^ sender, System::EventArgs^ e) {
		Comunicacion^ objComunicacion = gcnew Comunicacion();
		objComunicacion->arduino();

	}
private: System::Void btnOnOffLEDS_Click(System::Object^ sender, System::EventArgs^ e) {
	bool encendido = 0;
	bool apagado = 0;
	
	if (encendido == 0 && btnOnOffLEDS->Text->Equals("OFF"))
	{
		btnOnOffLEDS->Text = "ON";  // Cambia el texto del botón a "ON"
		encendido = 1;  // Cambia el estado a encendido
	}
	else {
		btnOnOffLEDS->Text ="OFF";  // Cambia el texto del botón a "OFF"
		apagado = 1;  // Cambia el estado a apagado
	}	
}
};
}