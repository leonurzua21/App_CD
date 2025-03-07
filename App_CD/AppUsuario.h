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
	SerialPort^ puerto; // Instancia del puerto serie
	int RGBrojo = 0;
	int RGBazul = 0;
	int RGBverde = 0; 
	//Hacer globales todas las variables de todos los metodos
	//Pendiente

	private: System::Windows::Forms::Label^ lblLuzEstacionamiento;
	private: System::Windows::Forms::Label^ lblLCD;
	private: System::Windows::Forms::TextBox^ txbTextoLCD;
	private: System::Windows::Forms::Button^ btnEnviarLCD;
	private: System::Windows::Forms::TrackBar^ tbRojo;
	private: System::Windows::Forms::TrackBar^ tbVerde;
	private: System::Windows::Forms::TrackBar^ tbAzul;






	private: System::Windows::Forms::Label^ lblRed;
	private: System::Windows::Forms::Label^ lblGreen;
	private: System::Windows::Forms::Label^ lblBlue;
	private: System::Windows::Forms::PictureBox^ pboRGB;
	private: System::Windows::Forms::Label^ lblSegRojo;
	private: System::Windows::Forms::Label^ lblSegVerde;
	private: System::Windows::Forms::Label^ lblSegAzul;

	public:
		AppUsuario(void)
		{
			InitializeComponent();
            // Agregar las líneas correctas en el constructor
            tbRojo->Minimum = 0;
            tbRojo->Maximum = 255;
            tbVerde->Minimum = 0;
            tbVerde->Maximum = 255;
            tbAzul->Minimum = 0;
            tbAzul->Maximum = 255;
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
			this->tbRojo = (gcnew System::Windows::Forms::TrackBar());
			this->tbVerde = (gcnew System::Windows::Forms::TrackBar());
			this->tbAzul = (gcnew System::Windows::Forms::TrackBar());
			this->lblRed = (gcnew System::Windows::Forms::Label());
			this->lblGreen = (gcnew System::Windows::Forms::Label());
			this->lblBlue = (gcnew System::Windows::Forms::Label());
			this->pboRGB = (gcnew System::Windows::Forms::PictureBox());
			this->lblSegRojo = (gcnew System::Windows::Forms::Label());
			this->lblSegVerde = (gcnew System::Windows::Forms::Label());
			this->lblSegAzul = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbRojo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbVerde))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbAzul))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pboRGB))->BeginInit();
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
			this->lblLCD->Location = System::Drawing::Point(273, 236);
			this->lblLCD->Name = L"lblLCD";
			this->lblLCD->Size = System::Drawing::Size(68, 13);
			this->lblLCD->TabIndex = 9;
			this->lblLCD->Text = L"Entrada LCD";
			// 
			// txbTextoLCD
			// 
			this->txbTextoLCD->Location = System::Drawing::Point(274, 262);
			this->txbTextoLCD->Name = L"txbTextoLCD";
			this->txbTextoLCD->Size = System::Drawing::Size(100, 20);
			this->txbTextoLCD->TabIndex = 10;
			// 
			// btnEnviarLCD
			// 
			this->btnEnviarLCD->Location = System::Drawing::Point(274, 288);
			this->btnEnviarLCD->Name = L"btnEnviarLCD";
			this->btnEnviarLCD->Size = System::Drawing::Size(100, 23);
			this->btnEnviarLCD->TabIndex = 11;
			this->btnEnviarLCD->Text = L"Enviar a LCD";
			this->btnEnviarLCD->UseVisualStyleBackColor = true;
			this->btnEnviarLCD->Click += gcnew System::EventHandler(this, &AppUsuario::btnEnviarLCD_Click);
			// 
			// tbRojo
			// 
			this->tbRojo->Location = System::Drawing::Point(249, 118);
			this->tbRojo->Name = L"tbRojo";
			this->tbRojo->Size = System::Drawing::Size(210, 45);
			this->tbRojo->TabIndex = 12;
			this->tbRojo->Scroll += gcnew System::EventHandler(this, &AppUsuario::tbRed_Scroll);
			// 
			// tbVerde
			// 
			this->tbVerde->Location = System::Drawing::Point(249, 153);
			this->tbVerde->Name = L"tbVerde";
			this->tbVerde->Size = System::Drawing::Size(210, 45);
			this->tbVerde->TabIndex = 13;
			this->tbVerde->Scroll += gcnew System::EventHandler(this, &AppUsuario::tbGreen_Scroll);
			// 
			// tbAzul
			// 
			this->tbAzul->Location = System::Drawing::Point(249, 188);
			this->tbAzul->Name = L"tbAzul";
			this->tbAzul->Size = System::Drawing::Size(210, 45);
			this->tbAzul->TabIndex = 14;
			this->tbAzul->Scroll += gcnew System::EventHandler(this, &AppUsuario::tbBlue_Scroll);
			// 
			// lblRed
			// 
			this->lblRed->AutoSize = true;
			this->lblRed->Location = System::Drawing::Point(208, 118);
			this->lblRed->Name = L"lblRed";
			this->lblRed->Size = System::Drawing::Size(15, 13);
			this->lblRed->TabIndex = 15;
			this->lblRed->Text = L"R";
			// 
			// lblGreen
			// 
			this->lblGreen->AutoSize = true;
			this->lblGreen->Location = System::Drawing::Point(208, 153);
			this->lblGreen->Name = L"lblGreen";
			this->lblGreen->Size = System::Drawing::Size(15, 13);
			this->lblGreen->TabIndex = 16;
			this->lblGreen->Text = L"G";
			// 
			// lblBlue
			// 
			this->lblBlue->AutoSize = true;
			this->lblBlue->Location = System::Drawing::Point(208, 188);
			this->lblBlue->Name = L"lblBlue";
			this->lblBlue->Size = System::Drawing::Size(14, 13);
			this->lblBlue->TabIndex = 17;
			this->lblBlue->Text = L"B";
			// 
			// pboRGB
			// 
			this->pboRGB->Location = System::Drawing::Point(440, 51);
			this->pboRGB->Name = L"pboRGB";
			this->pboRGB->Size = System::Drawing::Size(135, 50);
			this->pboRGB->TabIndex = 18;
			this->pboRGB->TabStop = false;
			// 
			// lblSegRojo
			// 
			this->lblSegRojo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->lblSegRojo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSegRojo->Location = System::Drawing::Point(475, 113);
			this->lblSegRojo->Name = L"lblSegRojo";
			this->lblSegRojo->Size = System::Drawing::Size(76, 35);
			this->lblSegRojo->TabIndex = 19;
			// 
			// lblSegVerde
			// 
			this->lblSegVerde->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->lblSegVerde->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSegVerde->Location = System::Drawing::Point(475, 153);
			this->lblSegVerde->Name = L"lblSegVerde";
			this->lblSegVerde->Size = System::Drawing::Size(76, 35);
			this->lblSegVerde->TabIndex = 20;
			// 
			// lblSegAzul
			// 
			this->lblSegAzul->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->lblSegAzul->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSegAzul->Location = System::Drawing::Point(475, 198);
			this->lblSegAzul->Name = L"lblSegAzul";
			this->lblSegAzul->Size = System::Drawing::Size(76, 35);
			this->lblSegAzul->TabIndex = 21;
			// 
			// AppUsuario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(832, 347);
			this->Controls->Add(this->lblSegAzul);
			this->Controls->Add(this->lblSegVerde);
			this->Controls->Add(this->lblSegRojo);
			this->Controls->Add(this->pboRGB);
			this->Controls->Add(this->lblBlue);
			this->Controls->Add(this->lblGreen);
			this->Controls->Add(this->lblRed);
			this->Controls->Add(this->tbAzul);
			this->Controls->Add(this->tbVerde);
			this->Controls->Add(this->tbRojo);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbRojo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbVerde))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbAzul))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pboRGB))->EndInit();
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
			puerto->Write("b");  // Envía el valor 0 al puerto serie
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
private: System::Void tbRed_Scroll(System::Object^ sender, System::EventArgs^ e) { //Luz estacionamiento
	puerto = objComunicacion->obtenerPuerto(); // Obtiene el puerto desde la instancia de Comunicacion
	if (objComunicacion->estaAbierto()) // Verifica si el puerto está abierto
	{
		RGBrojo = tbRojo->Value;
		lblSegRojo->Text = RGBrojo.ToString();
		puerto->Write("r");
		ActualizarColor();
	}
	else
	{
		MessageBox::Show("No se ha establecido una conexión con el puerto.");
	}
}
private: System::Void tbGreen_Scroll(System::Object^ sender, System::EventArgs^ e) { //Luz estacionamiento
	puerto = objComunicacion->obtenerPuerto(); // Obtiene el puerto desde la instancia de Comunicacion
	if (objComunicacion->estaAbierto()) // Verifica si el puerto está abierto
	{
		RGBverde = tbVerde->Value;
		lblSegVerde->Text = RGBverde.ToString();
		puerto->Write("g");
		ActualizarColor();
	}
	else
	{
		MessageBox::Show("No se ha establecido una conexión con el puerto.");
	}
}
private: System::Void tbBlue_Scroll(System::Object^ sender, System::EventArgs^ e) { //Luz estacionamiento
	puerto = objComunicacion->obtenerPuerto(); // Obtiene el puerto desde la instancia de Comunicacion
	if (objComunicacion->estaAbierto()) // Verifica si el puerto está abierto
	{
		RGBazul = tbAzul->Value;
		lblSegAzul->Text = RGBazul.ToString();
		puerto->Write("b");
		ActualizarColor();
	}
	else
	{
		MessageBox::Show("No se ha establecido una conexión con el puerto.");
	}
}
private: void ActualizarColor() //Color RGB en PictureBox
{
	Color colorRGB = (gcnew Color)->FromArgb(RGBrojo, RGBverde, RGBazul);
	colorRGB = Color::FromArgb(RGBrojo, RGBverde, RGBazul);
	pboRGB->BackColor = colorRGB;
	lblSegRojo->Text = RGBrojo.ToString();
	lblSegVerde->Text = RGBverde.ToString();
	lblSegAzul->Text = RGBazul.ToString();
}
};
}