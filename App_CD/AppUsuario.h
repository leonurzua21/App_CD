#pragma once
#include "Comunicacion.h"

namespace AppCD {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
	using namespace System::IO;


	/// <summary>
	/// Resumen de AppUsuario
	/// </summary>
	public ref class AppUsuario : public System::Windows::Forms::Form
	{
	private:
	Comunicacion^ objComunicacion;  // Instancia única de Comunicacion para no abrir más de un puerto serie
	SerialPort^ puerto; // Instancia del puerto series
	//Hacer globales todas las variables de todos los metodos
	//Pendiente

	private: System::Windows::Forms::Label^ lblLuzEstacionamiento;
	private: System::Windows::Forms::Label^ lblLCD;
	private: System::Windows::Forms::TextBox^ txbTextoLCD;
	private: System::Windows::Forms::Button^ btnColorRojo;


	private: System::Windows::Forms::Button^ btnColorVerde;
	private: System::Windows::Forms::Button^ btnColorAzul;
	private: System::Windows::Forms::Label^ lblencendertodo;
	private: System::Windows::Forms::Button^ btnencendertodo;



	private: System::Windows::Forms::Button^ btnEnviarLCD;

	public:
		AppUsuario(void)
		{
			InitializeComponent();
			objComunicacion = gcnew Comunicacion(); // Inicializa la instancia de Comunicacion
			
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
	private: System::Windows::Forms::Label^ lblLuzSala;
	private: System::Windows::Forms::Button^ btnLuzSala;
	private: System::Windows::Forms::Label^ lblPuertaEntrada;
	private: System::Windows::Forms::Button^ btnEntradaPrincipal;


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
			this->lblLuzSala = (gcnew System::Windows::Forms::Label());
			this->btnLuzSala = (gcnew System::Windows::Forms::Button());
			this->lblPuertaEntrada = (gcnew System::Windows::Forms::Label());
			this->btnEntradaPrincipal = (gcnew System::Windows::Forms::Button());
			this->lblLuzEstacionamiento = (gcnew System::Windows::Forms::Label());
			this->lblLCD = (gcnew System::Windows::Forms::Label());
			this->txbTextoLCD = (gcnew System::Windows::Forms::TextBox());
			this->btnEnviarLCD = (gcnew System::Windows::Forms::Button());
			this->btnColorRojo = (gcnew System::Windows::Forms::Button());
			this->btnColorVerde = (gcnew System::Windows::Forms::Button());
			this->btnColorAzul = (gcnew System::Windows::Forms::Button());
			this->lblencendertodo = (gcnew System::Windows::Forms::Label());
			this->btnencendertodo = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblcomunicacion
			// 
			this->lblcomunicacion->AutoSize = true;
			this->lblcomunicacion->Location = System::Drawing::Point(12, 9);
			this->lblcomunicacion->Name = L"lblcomunicacion";
			this->lblcomunicacion->Size = System::Drawing::Size(97, 13);
			this->lblcomunicacion->TabIndex = 1;
			this->lblcomunicacion->Text = L"Placa de desarrollo";
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
			// lblLuzSala
			// 
			this->lblLuzSala->AutoSize = true;
			this->lblLuzSala->Location = System::Drawing::Point(295, 9);
			this->lblLuzSala->Name = L"lblLuzSala";
			this->lblLuzSala->Size = System::Drawing::Size(46, 13);
			this->lblLuzSala->TabIndex = 4;
			this->lblLuzSala->Text = L"Luz sala";
			// 
			// btnLuzSala
			// 
			this->btnLuzSala->Location = System::Drawing::Point(286, 25);
			this->btnLuzSala->Name = L"btnLuzSala";
			this->btnLuzSala->Size = System::Drawing::Size(75, 23);
			this->btnLuzSala->TabIndex = 5;
			this->btnLuzSala->Text = L"ON";
			this->btnLuzSala->UseVisualStyleBackColor = true;
			this->btnLuzSala->Click += gcnew System::EventHandler(this, &AppUsuario::btnLuzSala_Click);
			// 
			// lblPuertaEntrada
			// 
			this->lblPuertaEntrada->AutoSize = true;
			this->lblPuertaEntrada->Location = System::Drawing::Point(297, 51);
			this->lblPuertaEntrada->Name = L"lblPuertaEntrada";
			this->lblPuertaEntrada->Size = System::Drawing::Size(44, 13);
			this->lblPuertaEntrada->TabIndex = 6;
			this->lblPuertaEntrada->Text = L"Entrada";
			// 
			// btnEntradaPrincipal
			// 
			this->btnEntradaPrincipal->Location = System::Drawing::Point(286, 67);
			this->btnEntradaPrincipal->Name = L"btnEntradaPrincipal";
			this->btnEntradaPrincipal->Size = System::Drawing::Size(75, 23);
			this->btnEntradaPrincipal->TabIndex = 7;
			this->btnEntradaPrincipal->Text = L"ON";
			this->btnEntradaPrincipal->UseVisualStyleBackColor = true;
			this->btnEntradaPrincipal->Click += gcnew System::EventHandler(this, &AppUsuario::btnEntradaPrincipal_Click);
			// 
			// lblLuzEstacionamiento
			// 
			this->lblLuzEstacionamiento->AutoSize = true;
			this->lblLuzEstacionamiento->Location = System::Drawing::Point(283, 102);
			this->lblLuzEstacionamiento->Name = L"lblLuzEstacionamiento";
			this->lblLuzEstacionamiento->Size = System::Drawing::Size(105, 13);
			this->lblLuzEstacionamiento->TabIndex = 8;
			this->lblLuzEstacionamiento->Text = L"Luz Estacionamiento";
			// 
			// lblLCD
			// 
			this->lblLCD->AutoSize = true;
			this->lblLCD->Location = System::Drawing::Point(283, 165);
			this->lblLCD->Name = L"lblLCD";
			this->lblLCD->Size = System::Drawing::Size(68, 13);
			this->lblLCD->TabIndex = 9;
			this->lblLCD->Text = L"Entrada LCD";
			// 
			// txbTextoLCD
			// 
			this->txbTextoLCD->Location = System::Drawing::Point(274, 181);
			this->txbTextoLCD->Name = L"txbTextoLCD";
			this->txbTextoLCD->Size = System::Drawing::Size(100, 20);
			this->txbTextoLCD->TabIndex = 10;
			// 
			// btnEnviarLCD
			// 
			this->btnEnviarLCD->Location = System::Drawing::Point(274, 207);
			this->btnEnviarLCD->Name = L"btnEnviarLCD";
			this->btnEnviarLCD->Size = System::Drawing::Size(100, 23);
			this->btnEnviarLCD->TabIndex = 11;
			this->btnEnviarLCD->Text = L"Enviar a LCD";
			this->btnEnviarLCD->UseVisualStyleBackColor = true;
			this->btnEnviarLCD->Click += gcnew System::EventHandler(this, &AppUsuario::btnEnviarLCD_Click);
			// 
			// btnColorRojo
			// 
			this->btnColorRojo->Location = System::Drawing::Point(208, 130);
			this->btnColorRojo->Name = L"btnColorRojo";
			this->btnColorRojo->Size = System::Drawing::Size(75, 23);
			this->btnColorRojo->TabIndex = 13;
			this->btnColorRojo->Text = L"ROJO";
			this->btnColorRojo->UseVisualStyleBackColor = true;
			this->btnColorRojo->Click += gcnew System::EventHandler(this, &AppUsuario::btnColorRojo_Click);
			// 
			// btnColorVerde
			// 
			this->btnColorVerde->Location = System::Drawing::Point(289, 130);
			this->btnColorVerde->Name = L"btnColorVerde";
			this->btnColorVerde->Size = System::Drawing::Size(75, 23);
			this->btnColorVerde->TabIndex = 14;
			this->btnColorVerde->Text = L"VERDE";
			this->btnColorVerde->UseVisualStyleBackColor = true;
			this->btnColorVerde->Click += gcnew System::EventHandler(this, &AppUsuario::btnColorVerde_Click);
			// 
			// btnColorAzul
			// 
			this->btnColorAzul->Location = System::Drawing::Point(370, 130);
			this->btnColorAzul->Name = L"btnColorAzul";
			this->btnColorAzul->Size = System::Drawing::Size(75, 23);
			this->btnColorAzul->TabIndex = 15;
			this->btnColorAzul->Text = L"AZUL";
			this->btnColorAzul->UseVisualStyleBackColor = true;
			this->btnColorAzul->Click += gcnew System::EventHandler(this, &AppUsuario::btnColorAzul_Click);
			// 
			// lblencendertodo
			// 
			this->lblencendertodo->AutoSize = true;
			this->lblencendertodo->Location = System::Drawing::Point(591, 25);
			this->lblencendertodo->Name = L"lblencendertodo";
			this->lblencendertodo->Size = System::Drawing::Size(115, 13);
			this->lblencendertodo->TabIndex = 16;
			this->lblencendertodo->Text = L"Encender/apagar todo";
			// 
			// btnencendertodo
			// 
			this->btnencendertodo->Location = System::Drawing::Point(623, 51);
			this->btnencendertodo->Name = L"btnencendertodo";
			this->btnencendertodo->Size = System::Drawing::Size(75, 23);
			this->btnencendertodo->TabIndex = 17;
			this->btnencendertodo->Text = L"ON";
			this->btnencendertodo->UseVisualStyleBackColor = true;
			this->btnencendertodo->Click += gcnew System::EventHandler(this, &AppUsuario::btnencendertodo_Click);
			// 
			// AppUsuario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(832, 347);
			this->Controls->Add(this->btnencendertodo);
			this->Controls->Add(this->lblencendertodo);
			this->Controls->Add(this->btnColorAzul);
			this->Controls->Add(this->btnColorVerde);
			this->Controls->Add(this->btnColorRojo);
			this->Controls->Add(this->btnEnviarLCD);
			this->Controls->Add(this->txbTextoLCD);
			this->Controls->Add(this->lblLCD);
			this->Controls->Add(this->lblLuzEstacionamiento);
			this->Controls->Add(this->btnEntradaPrincipal);
			this->Controls->Add(this->lblPuertaEntrada);
			this->Controls->Add(this->btnLuzSala);
			this->Controls->Add(this->lblLuzSala);
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
	objComunicacion->arduino(); // Llama al método arduino de la instancia de Comunicacion
}
private: System::Void btnLuzSala_Click(System::Object^ sender, System::EventArgs^ e) {
	if (objComunicacion->estaAbierto()) // Verifica si el puerto está abierto
	{
		puerto = objComunicacion->obtenerPuerto(); // Obtiene el puerto desde la instancia de Comunicacion
		if (btnLuzSala->Text->Equals("ON"))
		{
			btnLuzSala->Text = "OFF";  // Cambia el texto del botón a "ON"
			puerto->Write("a");  // Envía el valor 1 al puerto serie
		}
		else
		{
			btnLuzSala->Text = "ON";  // Cambia el texto del botón a "OFF"
			puerto->Write("d");  // Envía el valor 0 al puerto serie
		}
	}
	else
	{
		MessageBox::Show("No se ha establecido una conexión con el puerto.");
	}
}
private: System::Void btnEntradaPrincipal_Click(System::Object^ sender, System::EventArgs^ e) {
	if (objComunicacion->estaAbierto()) // Verifica si el puerto está abierto
	{
		puerto = objComunicacion->obtenerPuerto(); // Obtiene el puerto desde la instancia de Comunicacion
		if (btnEntradaPrincipal->Text->Equals("ON"))
		{
			btnEntradaPrincipal->Text = "OFF";  // Cambia el texto del botón a "ON"
			puerto->Write("1");  // Envía el valor 1 al puerto serie
		}
		else
		{
			btnEntradaPrincipal->Text = "ON";  // Cambia el texto del botón a "OFF"
			puerto->Write("0");  // Envía el valor 0 al puerto serie
		}
	}
	else
	{
		MessageBox::Show("No se ha establecido una conexión con el puerto.");
	}
}
private: System::Void btnEnviarLCD_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ mensajeLCD = txbTextoLCD->Text; // Obtiene el texto ingresado en el TextBox
	puerto = objComunicacion->obtenerPuerto(); // Obtiene el puerto desde la instancia de Comunicacion

	if (objComunicacion->estaAbierto()) // Verifica si el puerto está abierto
	{
		MessageBox::Show("Mensaje enviado: " + mensajeLCD); // Muestra el mensaje en un MessageBox
		puerto->Write(mensajeLCD);
		//puerto->Write("m");
	}
	else
	{
		MessageBox::Show("No se ha establecido una conexión con el puerto.");
	}
}
private: System::Void btnColorRojo_Click(System::Object^ sender, System::EventArgs^ e) {
	if (objComunicacion->estaAbierto()) // Verifica si el puerto está abierto
	{
		puerto = objComunicacion->obtenerPuerto(); // Obtiene el puerto desde la instancia de Comunicacion
		if (btnColorRojo->Text->Equals("ROJO"))
		{
			btnColorRojo->Text = "OFF";  // Cambia el texto del botón a "ON"
			puerto->Write("r");  // Envía el valor 1 al puerto serie
		}
		else
		{
			btnColorRojo->Text = "ROJO";  // Cambia el texto del botón a "OFF"
			puerto->Write("r");  // Envía el valor 0 al puerto serie
		}
	}
	else
	{
		MessageBox::Show("No se ha establecido una conexión con el puerto.");
	}
}
	private: System::Void btnColorVerde_Click(System::Object^ sender, System::EventArgs^ e) {
	if (objComunicacion->estaAbierto()) // Verifica si el puerto está abierto
		{
			puerto = objComunicacion->obtenerPuerto(); // Obtiene el puerto desde la instancia de Comunicacion
			if (btnColorVerde->Text->Equals("VERDE"))
			{
				btnColorVerde->Text = "OFF";  // Cambia el texto del botón a "ON"
				puerto->Write("g");  // Envía el valor 1 al puerto serie
			}
			else
			{
				btnColorVerde->Text = "VERDE";  // Cambia el texto del botón a "OFF"
				puerto->Write("g");  // Envía el valor 0 al puerto serie
			}
		}
		else
		{
			MessageBox::Show("No se ha establecido una conexión con el puerto.");
		}
	}
private: System::Void btnColorAzul_Click(System::Object^ sender, System::EventArgs^ e) {
	if (objComunicacion->estaAbierto()) // Verifica si el puerto está abierto
	{
		puerto = objComunicacion->obtenerPuerto(); // Obtiene el puerto desde la instancia de Comunicacion
		if (btnColorAzul->Text->Equals("AZUL"))
		{
			btnColorAzul->Text = "OFF";  // Cambia el texto del botón a "ON"
			puerto->Write("b");  // Envía el valor 1 al puerto serie
		}
		else
		{
			btnColorAzul->Text = "AZUL";  // Cambia el texto del botón a "OFF"
			puerto->Write("b");  // Envía el valor 0 al puerto serie	
		}
	}
	else
	{
		MessageBox::Show("No se ha establecido una conexión con el puerto.");
	}
}
private: System::Void btnencendertodo_Click(System::Object^ sender, System::EventArgs^ e) {

	if (objComunicacion->estaAbierto()) // Verifica si el puerto está abierto
	{
		puerto = objComunicacion->obtenerPuerto(); // Obtiene el puerto desde la instancia de Comunicacion
		if (btnencendertodo->Text->Equals("ON"))
		{
			btnencendertodo->Text = "OFF";  // Cambia el texto del botón a "ON"
			puerto->Write("t");  // Envía el valor 1 al puerto serie
		}
		else
		{
			btnencendertodo->Text = "ON";  // Cambia el texto del botón a "OFF"
			puerto->Write("f");  // Envía el valor 0 al puerto serie
		}
	}
	else
	{
		MessageBox::Show("No se ha establecido una conexión con el puerto.");
	}
}
};
}