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

	private: System::Windows::Forms::Panel^ panelControl;
	private: System::Windows::Forms::Button^ btnLuzEntradaPrincipal;

	private: System::Windows::Forms::Label^ lblPuertaEntrada;


	private: System::Windows::Forms::Label^ lblLuzEstacionamiento;
	private: System::Windows::Forms::Label^ lblLuzSala;
	private: System::Windows::Forms::Button^ btnencendertodo;
	private: System::Windows::Forms::Button^ btnLuzSala;
	private: System::Windows::Forms::Button^ btnLuzEstacionamiento;

	private: System::Windows::Forms::Label^ lblencendertodo;
	private: System::Windows::Forms::TableLayoutPanel^ TablePanelDivisionPantalla;






	private: System::Windows::Forms::Label^ lblLCD;
	private: System::Windows::Forms::Button^ btnEnviarLCD;
	private: System::Windows::Forms::Button^ btnPuertaCuartoUno;
	private: System::Windows::Forms::Label^ lblPuertaCuartoUno;
	private: System::Windows::Forms::Button^ btnVentiladorSala;
	private: System::Windows::Forms::Label^ lblVentiladorSala;


	private: System::Windows::Forms::Button^ btnPuertaCuartoDos;
	private: System::Windows::Forms::Label^ lblPuertaCuartoDos;

	private: System::Windows::Forms::Panel^ panelConexion;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ btnConectar;
	private: System::Windows::Forms::Label^ lblcomunicacion;
	private: System::Windows::Forms::ComboBox^ cboPlaca;
	private: System::Windows::Forms::Label^ lblEquipoDos;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnVentiladorPasillo;
	private: System::Windows::Forms::TextBox^ txbTextoLCD;

	public:
		AppUsuario(void)
		{
			InitializeComponent();
			/**********************Inicia componente Combobox "CboPlaca"*********************************/
			//Se agregan los elementos a manera de arreglo para que el usuario los pueda visualizar al momento de inicializar el combobox "cboPlaca"
			array<String^>^ desarrolladores = gcnew cli::array<String^>{ "Arduino Uno", "Arduino Leonardo", "ESP32" }; //Se pueden agregar más argumentos en el arreglo si desea agregar más placas de desarrollo ARDUINO
			cboPlaca->Items->AddRange(desarrolladores); //Agrega los elementos declarados en forma de arreglo en el combobox
			/**********************Termina componente Combobox "CboPlaca"*********************************/
			objComunicacion = gcnew Comunicacion(); // Inicializa la instancia de la clase "Comunicacion.h"
			//
			//TODO: agregar código de constructor aquí
			//
		}
		//Agregar variales globales aquí
		String^ LuzApagada = "..\\x64\\Debug\\Images\\Redimensionado\\Luz apagada.png";
		String^ LuzEncendida = "..\\x64\\Debug\\Images\\Redimensionado\\Luz encendida.png";
		String^ PuertaCerrada = "..\\x64\\Debug\\Images\\Redimensionado\\Puerta cerrada.png";
		String^ PuertaAbierta = "..\\x64\\Debug\\Images\\Redimensionado\\Puerta abierta.png";
		String^ VentiladorApagado = "..\\x64\\Debug\\Images\\Redimensionado\\Ventilador apagado.png";
		String^ VentiladorEncendido = "..\\x64\\Debug\\Images\\Redimensionado\\Ventilador encendido.png";

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AppUsuario::typeid));
			this->panelControl = (gcnew System::Windows::Forms::Panel());
			this->btnPuertaCuartoDos = (gcnew System::Windows::Forms::Button());
			this->lblPuertaCuartoDos = (gcnew System::Windows::Forms::Label());
			this->btnVentiladorSala = (gcnew System::Windows::Forms::Button());
			this->lblVentiladorSala = (gcnew System::Windows::Forms::Label());
			this->btnPuertaCuartoUno = (gcnew System::Windows::Forms::Button());
			this->lblPuertaCuartoUno = (gcnew System::Windows::Forms::Label());
			this->txbTextoLCD = (gcnew System::Windows::Forms::TextBox());
			this->lblLCD = (gcnew System::Windows::Forms::Label());
			this->btnLuzEntradaPrincipal = (gcnew System::Windows::Forms::Button());
			this->btnEnviarLCD = (gcnew System::Windows::Forms::Button());
			this->lblPuertaEntrada = (gcnew System::Windows::Forms::Label());
			this->lblLuzEstacionamiento = (gcnew System::Windows::Forms::Label());
			this->lblLuzSala = (gcnew System::Windows::Forms::Label());
			this->btnencendertodo = (gcnew System::Windows::Forms::Button());
			this->btnLuzSala = (gcnew System::Windows::Forms::Button());
			this->btnLuzEstacionamiento = (gcnew System::Windows::Forms::Button());
			this->lblencendertodo = (gcnew System::Windows::Forms::Label());
			this->TablePanelDivisionPantalla = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panelConexion = (gcnew System::Windows::Forms::Panel());
			this->lblEquipoDos = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnConectar = (gcnew System::Windows::Forms::Button());
			this->lblcomunicacion = (gcnew System::Windows::Forms::Label());
			this->cboPlaca = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnVentiladorPasillo = (gcnew System::Windows::Forms::Button());
			this->panelControl->SuspendLayout();
			this->TablePanelDivisionPantalla->SuspendLayout();
			this->panelConexion->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelControl
			// 
			this->panelControl->BackColor = System::Drawing::SystemColors::Control;
			this->panelControl->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelControl.BackgroundImage")));
			this->panelControl->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->panelControl->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelControl->Controls->Add(this->btnVentiladorPasillo);
			this->panelControl->Controls->Add(this->label1);
			this->panelControl->Controls->Add(this->btnPuertaCuartoDos);
			this->panelControl->Controls->Add(this->lblPuertaCuartoDos);
			this->panelControl->Controls->Add(this->btnVentiladorSala);
			this->panelControl->Controls->Add(this->lblVentiladorSala);
			this->panelControl->Controls->Add(this->btnPuertaCuartoUno);
			this->panelControl->Controls->Add(this->lblPuertaCuartoUno);
			this->panelControl->Controls->Add(this->txbTextoLCD);
			this->panelControl->Controls->Add(this->lblLCD);
			this->panelControl->Controls->Add(this->btnLuzEntradaPrincipal);
			this->panelControl->Controls->Add(this->btnEnviarLCD);
			this->panelControl->Controls->Add(this->lblPuertaEntrada);
			this->panelControl->Controls->Add(this->lblLuzEstacionamiento);
			this->panelControl->Controls->Add(this->lblLuzSala);
			this->panelControl->Controls->Add(this->btnencendertodo);
			this->panelControl->Controls->Add(this->btnLuzSala);
			this->panelControl->Controls->Add(this->btnLuzEstacionamiento);
			this->panelControl->Controls->Add(this->lblencendertodo);
			this->panelControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelControl->ForeColor = System::Drawing::SystemColors::Control;
			this->panelControl->Location = System::Drawing::Point(524, 3);
			this->panelControl->Name = L"panelControl";
			this->panelControl->Size = System::Drawing::Size(515, 598);
			this->panelControl->TabIndex = 1;
			// 
			// btnPuertaCuartoDos
			// 
			this->btnPuertaCuartoDos->BackColor = System::Drawing::Color::Transparent;
			this->btnPuertaCuartoDos->FlatAppearance->BorderSize = 0;
			this->btnPuertaCuartoDos->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnPuertaCuartoDos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 1.5F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnPuertaCuartoDos->ForeColor = System::Drawing::Color::Transparent;
			this->btnPuertaCuartoDos->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnPuertaCuartoDos.Image")));
			this->btnPuertaCuartoDos->Location = System::Drawing::Point(234, 131);
			this->btnPuertaCuartoDos->Margin = System::Windows::Forms::Padding(0);
			this->btnPuertaCuartoDos->Name = L"btnPuertaCuartoDos";
			this->btnPuertaCuartoDos->Size = System::Drawing::Size(56, 54);
			this->btnPuertaCuartoDos->TabIndex = 23;
			this->btnPuertaCuartoDos->Text = L"OPEN";
			this->btnPuertaCuartoDos->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->btnPuertaCuartoDos->UseVisualStyleBackColor = false;
			this->btnPuertaCuartoDos->Click += gcnew System::EventHandler(this, &AppUsuario::btnPuertaCuartoDos_Click);
			// 
			// lblPuertaCuartoDos
			// 
			this->lblPuertaCuartoDos->AutoSize = true;
			this->lblPuertaCuartoDos->BackColor = System::Drawing::Color::Transparent;
			this->lblPuertaCuartoDos->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 12));
			this->lblPuertaCuartoDos->ForeColor = System::Drawing::SystemColors::Window;
			this->lblPuertaCuartoDos->Location = System::Drawing::Point(325, 35);
			this->lblPuertaCuartoDos->Name = L"lblPuertaCuartoDos";
			this->lblPuertaCuartoDos->Size = System::Drawing::Size(16, 19);
			this->lblPuertaCuartoDos->TabIndex = 22;
			this->lblPuertaCuartoDos->Text = L"3";
			// 
			// btnVentiladorSala
			// 
			this->btnVentiladorSala->BackColor = System::Drawing::Color::Transparent;
			this->btnVentiladorSala->FlatAppearance->BorderSize = 0;
			this->btnVentiladorSala->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnVentiladorSala->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 1.5F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnVentiladorSala->ForeColor = System::Drawing::Color::Transparent;
			this->btnVentiladorSala->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnVentiladorSala.Image")));
			this->btnVentiladorSala->Location = System::Drawing::Point(159, 56);
			this->btnVentiladorSala->Margin = System::Windows::Forms::Padding(0);
			this->btnVentiladorSala->Name = L"btnVentiladorSala";
			this->btnVentiladorSala->Size = System::Drawing::Size(56, 54);
			this->btnVentiladorSala->TabIndex = 21;
			this->btnVentiladorSala->Text = L"ON";
			this->btnVentiladorSala->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->btnVentiladorSala->UseVisualStyleBackColor = false;
			this->btnVentiladorSala->Click += gcnew System::EventHandler(this, &AppUsuario::btnVentiladorSala_Click);
			// 
			// lblVentiladorSala
			// 
			this->lblVentiladorSala->AutoSize = true;
			this->lblVentiladorSala->BackColor = System::Drawing::Color::Transparent;
			this->lblVentiladorSala->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblVentiladorSala->ForeColor = System::Drawing::SystemColors::Window;
			this->lblVentiladorSala->Location = System::Drawing::Point(174, 35);
			this->lblVentiladorSala->Name = L"lblVentiladorSala";
			this->lblVentiladorSala->Size = System::Drawing::Size(14, 19);
			this->lblVentiladorSala->TabIndex = 20;
			this->lblVentiladorSala->Text = L"1";
			// 
			// btnPuertaCuartoUno
			// 
			this->btnPuertaCuartoUno->BackColor = System::Drawing::Color::Transparent;
			this->btnPuertaCuartoUno->FlatAppearance->BorderSize = 0;
			this->btnPuertaCuartoUno->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnPuertaCuartoUno->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 1.5F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnPuertaCuartoUno->ForeColor = System::Drawing::Color::Transparent;
			this->btnPuertaCuartoUno->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnPuertaCuartoUno.Image")));
			this->btnPuertaCuartoUno->Location = System::Drawing::Point(305, 56);
			this->btnPuertaCuartoUno->Margin = System::Windows::Forms::Padding(0);
			this->btnPuertaCuartoUno->Name = L"btnPuertaCuartoUno";
			this->btnPuertaCuartoUno->Size = System::Drawing::Size(56, 54);
			this->btnPuertaCuartoUno->TabIndex = 19;
			this->btnPuertaCuartoUno->Text = L"OPEN";
			this->btnPuertaCuartoUno->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->btnPuertaCuartoUno->UseVisualStyleBackColor = false;
			this->btnPuertaCuartoUno->Click += gcnew System::EventHandler(this, &AppUsuario::btnPuertaCuartoUno_Click);
			// 
			// lblPuertaCuartoUno
			// 
			this->lblPuertaCuartoUno->AutoSize = true;
			this->lblPuertaCuartoUno->BackColor = System::Drawing::Color::Transparent;
			this->lblPuertaCuartoUno->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 12));
			this->lblPuertaCuartoUno->ForeColor = System::Drawing::SystemColors::Window;
			this->lblPuertaCuartoUno->Location = System::Drawing::Point(248, 110);
			this->lblPuertaCuartoUno->Name = L"lblPuertaCuartoUno";
			this->lblPuertaCuartoUno->Size = System::Drawing::Size(17, 19);
			this->lblPuertaCuartoUno->TabIndex = 18;
			this->lblPuertaCuartoUno->Text = L"5";
			// 
			// txbTextoLCD
			// 
			this->txbTextoLCD->Location = System::Drawing::Point(178, 469);
			this->txbTextoLCD->Margin = System::Windows::Forms::Padding(0);
			this->txbTextoLCD->Name = L"txbTextoLCD";
			this->txbTextoLCD->Size = System::Drawing::Size(163, 20);
			this->txbTextoLCD->TabIndex = 10;
			// 
			// lblLCD
			// 
			this->lblLCD->AutoSize = true;
			this->lblLCD->BackColor = System::Drawing::Color::Transparent;
			this->lblLCD->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 12));
			this->lblLCD->ForeColor = System::Drawing::SystemColors::Window;
			this->lblLCD->Location = System::Drawing::Point(215, 437);
			this->lblLCD->Name = L"lblLCD";
			this->lblLCD->Size = System::Drawing::Size(89, 19);
			this->lblLCD->TabIndex = 9;
			this->lblLCD->Text = L"Entrada LCD";
			// 
			// btnLuzEntradaPrincipal
			// 
			this->btnLuzEntradaPrincipal->BackColor = System::Drawing::Color::Transparent;
			this->btnLuzEntradaPrincipal->FlatAppearance->BorderSize = 0;
			this->btnLuzEntradaPrincipal->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLuzEntradaPrincipal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 1.5F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnLuzEntradaPrincipal->ForeColor = System::Drawing::Color::Transparent;
			this->btnLuzEntradaPrincipal->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnLuzEntradaPrincipal.Image")));
			this->btnLuzEntradaPrincipal->Location = System::Drawing::Point(159, 131);
			this->btnLuzEntradaPrincipal->Margin = System::Windows::Forms::Padding(0);
			this->btnLuzEntradaPrincipal->Name = L"btnLuzEntradaPrincipal";
			this->btnLuzEntradaPrincipal->Size = System::Drawing::Size(56, 54);
			this->btnLuzEntradaPrincipal->TabIndex = 7;
			this->btnLuzEntradaPrincipal->Text = L"ON";
			this->btnLuzEntradaPrincipal->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->btnLuzEntradaPrincipal->UseVisualStyleBackColor = false;
			this->btnLuzEntradaPrincipal->Click += gcnew System::EventHandler(this, &AppUsuario::btnLuzEntradaPrincipal_Click);
			// 
			// btnEnviarLCD
			// 
			this->btnEnviarLCD->BackColor = System::Drawing::Color::Transparent;
			this->btnEnviarLCD->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnEnviarLCD->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnEnviarLCD->ForeColor = System::Drawing::SystemColors::Window;
			this->btnEnviarLCD->Location = System::Drawing::Point(199, 512);
			this->btnEnviarLCD->Margin = System::Windows::Forms::Padding(0);
			this->btnEnviarLCD->Name = L"btnEnviarLCD";
			this->btnEnviarLCD->Size = System::Drawing::Size(117, 30);
			this->btnEnviarLCD->TabIndex = 11;
			this->btnEnviarLCD->Text = L"Enviar a LCD";
			this->btnEnviarLCD->UseVisualStyleBackColor = false;
			this->btnEnviarLCD->Click += gcnew System::EventHandler(this, &AppUsuario::btnEnviarLCD_Click);
			// 
			// lblPuertaEntrada
			// 
			this->lblPuertaEntrada->AutoSize = true;
			this->lblPuertaEntrada->BackColor = System::Drawing::Color::Transparent;
			this->lblPuertaEntrada->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 12));
			this->lblPuertaEntrada->ForeColor = System::Drawing::SystemColors::Window;
			this->lblPuertaEntrada->Location = System::Drawing::Point(174, 110);
			this->lblPuertaEntrada->Name = L"lblPuertaEntrada";
			this->lblPuertaEntrada->Size = System::Drawing::Size(17, 19);
			this->lblPuertaEntrada->TabIndex = 6;
			this->lblPuertaEntrada->Text = L"4";
			// 
			// lblLuzEstacionamiento
			// 
			this->lblLuzEstacionamiento->AutoSize = true;
			this->lblLuzEstacionamiento->BackColor = System::Drawing::Color::Transparent;
			this->lblLuzEstacionamiento->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 12));
			this->lblLuzEstacionamiento->ForeColor = System::Drawing::SystemColors::Window;
			this->lblLuzEstacionamiento->Location = System::Drawing::Point(248, 35);
			this->lblLuzEstacionamiento->Name = L"lblLuzEstacionamiento";
			this->lblLuzEstacionamiento->Size = System::Drawing::Size(16, 19);
			this->lblLuzEstacionamiento->TabIndex = 8;
			this->lblLuzEstacionamiento->Text = L"2";
			// 
			// lblLuzSala
			// 
			this->lblLuzSala->AutoSize = true;
			this->lblLuzSala->BackColor = System::Drawing::Color::Transparent;
			this->lblLuzSala->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 12));
			this->lblLuzSala->ForeColor = System::Drawing::SystemColors::Window;
			this->lblLuzSala->Location = System::Drawing::Point(325, 306);
			this->lblLuzSala->Name = L"lblLuzSala";
			this->lblLuzSala->Size = System::Drawing::Size(16, 19);
			this->lblLuzSala->TabIndex = 4;
			this->lblLuzSala->Text = L"6";
			// 
			// btnencendertodo
			// 
			this->btnencendertodo->BackColor = System::Drawing::Color::Transparent;
			this->btnencendertodo->FlatAppearance->BorderSize = 0;
			this->btnencendertodo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnencendertodo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 1.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnencendertodo->ForeColor = System::Drawing::Color::Transparent;
			this->btnencendertodo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnencendertodo.Image")));
			this->btnencendertodo->Location = System::Drawing::Point(166, 392);
			this->btnencendertodo->Margin = System::Windows::Forms::Padding(0);
			this->btnencendertodo->Name = L"btnencendertodo";
			this->btnencendertodo->Size = System::Drawing::Size(49, 45);
			this->btnencendertodo->TabIndex = 17;
			this->btnencendertodo->Text = L"ON";
			this->btnencendertodo->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->btnencendertodo->UseVisualStyleBackColor = false;
			this->btnencendertodo->Click += gcnew System::EventHandler(this, &AppUsuario::btnencendertodo_Click);
			// 
			// btnLuzSala
			// 
			this->btnLuzSala->BackColor = System::Drawing::Color::Transparent;
			this->btnLuzSala->FlatAppearance->BorderSize = 0;
			this->btnLuzSala->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLuzSala->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 1.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLuzSala->ForeColor = System::Drawing::Color::Transparent;
			this->btnLuzSala->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnLuzSala.Image")));
			this->btnLuzSala->Location = System::Drawing::Point(304, 337);
			this->btnLuzSala->Margin = System::Windows::Forms::Padding(0);
			this->btnLuzSala->Name = L"btnLuzSala";
			this->btnLuzSala->Size = System::Drawing::Size(56, 37);
			this->btnLuzSala->TabIndex = 5;
			this->btnLuzSala->Text = L"ON";
			this->btnLuzSala->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->btnLuzSala->UseVisualStyleBackColor = false;
			this->btnLuzSala->Click += gcnew System::EventHandler(this, &AppUsuario::btnLuzSala_Click);
			// 
			// btnLuzEstacionamiento
			// 
			this->btnLuzEstacionamiento->BackColor = System::Drawing::Color::Transparent;
			this->btnLuzEstacionamiento->FlatAppearance->BorderSize = 0;
			this->btnLuzEstacionamiento->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLuzEstacionamiento->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 1.5F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnLuzEstacionamiento->ForeColor = System::Drawing::Color::Transparent;
			this->btnLuzEstacionamiento->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnLuzEstacionamiento.Image")));
			this->btnLuzEstacionamiento->Location = System::Drawing::Point(234, 56);
			this->btnLuzEstacionamiento->Margin = System::Windows::Forms::Padding(0);
			this->btnLuzEstacionamiento->Name = L"btnLuzEstacionamiento";
			this->btnLuzEstacionamiento->Size = System::Drawing::Size(56, 54);
			this->btnLuzEstacionamiento->TabIndex = 13;
			this->btnLuzEstacionamiento->Text = L"ON";
			this->btnLuzEstacionamiento->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->btnLuzEstacionamiento->UseVisualStyleBackColor = false;
			this->btnLuzEstacionamiento->Click += gcnew System::EventHandler(this, &AppUsuario::btnLuzEstacionamiento_Click);
			// 
			// lblencendertodo
			// 
			this->lblencendertodo->BackColor = System::Drawing::Color::Transparent;
			this->lblencendertodo->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 12));
			this->lblencendertodo->ForeColor = System::Drawing::SystemColors::Control;
			this->lblencendertodo->Location = System::Drawing::Point(155, 353);
			this->lblencendertodo->Name = L"lblencendertodo";
			this->lblencendertodo->Size = System::Drawing::Size(73, 34);
			this->lblencendertodo->TabIndex = 16;
			this->lblencendertodo->Text = L"ON/OFF";
			// 
			// TablePanelDivisionPantalla
			// 
			this->TablePanelDivisionPantalla->ColumnCount = 2;
			this->TablePanelDivisionPantalla->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->TablePanelDivisionPantalla->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->TablePanelDivisionPantalla->Controls->Add(this->panelControl, 1, 0);
			this->TablePanelDivisionPantalla->Controls->Add(this->panelConexion, 0, 0);
			this->TablePanelDivisionPantalla->Dock = System::Windows::Forms::DockStyle::Fill;
			this->TablePanelDivisionPantalla->ForeColor = System::Drawing::SystemColors::Control;
			this->TablePanelDivisionPantalla->Location = System::Drawing::Point(0, 0);
			this->TablePanelDivisionPantalla->Name = L"TablePanelDivisionPantalla";
			this->TablePanelDivisionPantalla->RowCount = 1;
			this->TablePanelDivisionPantalla->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->TablePanelDivisionPantalla->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				593)));
			this->TablePanelDivisionPantalla->Size = System::Drawing::Size(1042, 604);
			this->TablePanelDivisionPantalla->TabIndex = 18;
			// 
			// panelConexion
			// 
			this->panelConexion->Controls->Add(this->lblEquipoDos);
			this->panelConexion->Controls->Add(this->groupBox1);
			this->panelConexion->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelConexion->ForeColor = System::Drawing::SystemColors::WindowText;
			this->panelConexion->Location = System::Drawing::Point(3, 3);
			this->panelConexion->Name = L"panelConexion";
			this->panelConexion->Size = System::Drawing::Size(515, 598);
			this->panelConexion->TabIndex = 2;
			// 
			// lblEquipoDos
			// 
			this->lblEquipoDos->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 26));
			this->lblEquipoDos->ForeColor = System::Drawing::SystemColors::WindowText;
			this->lblEquipoDos->Location = System::Drawing::Point(112, 262);
			this->lblEquipoDos->Name = L"lblEquipoDos";
			this->lblEquipoDos->Size = System::Drawing::Size(310, 114);
			this->lblEquipoDos->TabIndex = 1;
			this->lblEquipoDos->Text = L"EQUIPO NO. 2 Diseño de software";
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(156)), static_cast<System::Int32>(static_cast<System::Byte>(185)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->groupBox1->Controls->Add(this->btnConectar);
			this->groupBox1->Controls->Add(this->lblcomunicacion);
			this->groupBox1->Controls->Add(this->cboPlaca);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox1->Location = System::Drawing::Point(0, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(515, 100);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			// 
			// btnConectar
			// 
			this->btnConectar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnConectar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnConectar.Image")));
			this->btnConectar->Location = System::Drawing::Point(217, 60);
			this->btnConectar->Name = L"btnConectar";
			this->btnConectar->Size = System::Drawing::Size(52, 34);
			this->btnConectar->TabIndex = 3;
			this->btnConectar->UseVisualStyleBackColor = true;
			this->btnConectar->Click += gcnew System::EventHandler(this, &AppUsuario::btnConectar_Click);
			// 
			// lblcomunicacion
			// 
			this->lblcomunicacion->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblcomunicacion->AutoSize = true;
			this->lblcomunicacion->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblcomunicacion->ForeColor = System::Drawing::SystemColors::WindowText;
			this->lblcomunicacion->Location = System::Drawing::Point(186, 0);
			this->lblcomunicacion->Name = L"lblcomunicacion";
			this->lblcomunicacion->Size = System::Drawing::Size(131, 19);
			this->lblcomunicacion->TabIndex = 1;
			this->lblcomunicacion->Text = L"Placa de desarrollo";
			// 
			// cboPlaca
			// 
			this->cboPlaca->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->cboPlaca->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboPlaca->FormattingEnabled = true;
			this->cboPlaca->Location = System::Drawing::Point(190, 27);
			this->cboPlaca->Name = L"cboPlaca";
			this->cboPlaca->Size = System::Drawing::Size(121, 21);
			this->cboPlaca->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::Window;
			this->label1->Location = System::Drawing::Point(325, 110);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(16, 19);
			this->label1->TabIndex = 24;
			this->label1->Text = L"6";
			// 
			// btnVentiladorPasillo
			// 
			this->btnVentiladorPasillo->BackColor = System::Drawing::Color::Transparent;
			this->btnVentiladorPasillo->FlatAppearance->BorderSize = 0;
			this->btnVentiladorPasillo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnVentiladorPasillo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 1.5F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnVentiladorPasillo->ForeColor = System::Drawing::Color::Transparent;
			this->btnVentiladorPasillo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnVentiladorPasillo.Image")));
			this->btnVentiladorPasillo->Location = System::Drawing::Point(305, 131);
			this->btnVentiladorPasillo->Margin = System::Windows::Forms::Padding(0);
			this->btnVentiladorPasillo->Name = L"btnVentiladorPasillo";
			this->btnVentiladorPasillo->Size = System::Drawing::Size(56, 54);
			this->btnVentiladorPasillo->TabIndex = 25;
			this->btnVentiladorPasillo->Text = L"ON";
			this->btnVentiladorPasillo->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->btnVentiladorPasillo->UseVisualStyleBackColor = false;
			this->btnVentiladorPasillo->Click += gcnew System::EventHandler(this, &AppUsuario::btnVentiladorPasillo_Click);
			// 
			// AppUsuario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1042, 604);
			this->Controls->Add(this->TablePanelDivisionPantalla);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AppUsuario";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AppUsuario";
			this->panelControl->ResumeLayout(false);
			this->panelControl->PerformLayout();
			this->TablePanelDivisionPantalla->ResumeLayout(false);
			this->panelConexion->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void btnConectar_Click(System::Object^ sender, System::EventArgs^ e) {
	if (cboPlaca->Text->Equals("")) //Si el usuario solo conecta la placa de desarrollo e intenta conectarla sin antes seleccionar una opción en el combobox, se aplica esta regla
	{
		MessageBox::Show("Seleccione una placa de desarrollo en lista", "Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		
	}
	else //Si selecciona un elemento del combobox "CboPlaca", procederá a conectarse
	{
		MessageBox::Show("Placa seleccionada: " + cboPlaca->SelectedItem, "Información", MessageBoxButtons::OK, MessageBoxIcon::Information); //Accede al elemento seleccionado por el usuario
		if (objComunicacion->placa()) // Verifica si la placa esta conectada
		{
			puerto = objComunicacion->obtenerPuerto(); // Obtiene el puerto desde la instancia de Comunicacion
		}
	}
}
private: System::Void btnLuzSala_Click(System::Object^ sender, System::EventArgs^ e) { //Conectado a PIN 2 ARDUINO
	
	if (objComunicacion->estaAbierto()) // Verifica si el puerto está abierto
	{ 
		puerto = objComunicacion->obtenerPuerto(); // Obtiene el puerto desde la instancia de Comunicacion
		if (btnLuzSala->Text->Equals("ON"))
		{
			btnLuzSala->Image = Image::FromFile(LuzApagada);
			btnLuzSala->Text = "OFF";  // Cambia el texto del botón a "ON"
			puerto->Write("a");  // Envía el valor a al puerto serie
		}
		else
		{
			btnLuzSala->Image = Image::FromFile(LuzEncendida);
			btnLuzSala->Text = "ON";  // Cambia el texto del botón a "OFF"
			puerto->Write("b");  // Envía el valor b al puerto serie
		}
	}
	else
	{
		MessageBox::Show("No se ha establecido una conexión con el puerto.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void btnLuzEntradaPrincipal_Click(System::Object^ sender, System::EventArgs^ e) { //Conectado a PIN 3 ARDUINO
	if (objComunicacion->estaAbierto()) // Verifica si el puerto está abierto
	{
		puerto = objComunicacion->obtenerPuerto(); // Obtiene el puerto desde la instancia de Comunicacion
		if (btnLuzEntradaPrincipal->Text->Equals("ON"))
		{
			btnLuzEntradaPrincipal->Image = Image::FromFile(LuzApagada);
			btnLuzEntradaPrincipal->Text = "OFF";  // Cambia el texto del botón a "ON"
			puerto->Write("c");  // Envía el valor c al puerto serie
		}
		else
		{
			btnLuzEntradaPrincipal->Image = Image::FromFile(LuzEncendida);
			btnLuzEntradaPrincipal->Text = "ON";  // Cambia el texto del botón a "OFF"
			puerto->Write("d");  // Envía el valor d al puerto serie
		}
	}
	else
	{
		MessageBox::Show("No se ha establecido una conexión con el puerto.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

private: System::Void btnLuzEstacionamiento_Click(System::Object^ sender, System::EventArgs^ e) { //Conectado a PIN 4 ARDUINO
	if (objComunicacion->estaAbierto()) // Verifica si el puerto está abierto
	{
		puerto = objComunicacion->obtenerPuerto(); // Obtiene el puerto desde la instancia de Comunicacion
		if (btnLuzEstacionamiento->Text->Equals("ON"))
		{
			btnLuzEstacionamiento->Image = Image::FromFile(LuzApagada);
			btnLuzEstacionamiento->Text = "OFF";  // Cambia el texto del botón a "ON"
			puerto->Write("e");  // Envía el valor e al puerto serie
		}
		else
		{
			btnLuzEstacionamiento->Image = Image::FromFile(LuzEncendida);
			btnLuzEstacionamiento->Text = "ON";  // Cambia el texto del botón a "OFF"
			puerto->Write("f");  // Envía el valor f al puerto serie
		}
	}
	else
	{
		MessageBox::Show("No se ha establecido una conexión con el puerto.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

private: System::Void btnEnviarLCD_Click(System::Object^ sender, System::EventArgs^ e) { //Conectado a entradas análogas (SDA, SCL) ARDUINO
	String^ mensajeLCD = txbTextoLCD->Text; // Obtiene el texto ingresado en el TextBox
	if (objComunicacion->estaAbierto()) // Verifica si el puerto está abierto
	{
		puerto = objComunicacion->obtenerPuerto(); // Obtiene el puerto desde la instancia de Comunicacion
		puerto->Write("m" + mensajeLCD);
		MessageBox::Show("Mensaje enviado: " + mensajeLCD, "Información", MessageBoxButtons::OK, MessageBoxIcon::Information); // Muestra el mensaje en un MessageBo
	}
	else
	{
		MessageBox::Show("No se ha establecido una conexión con el puerto.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

private: System::Void btnencendertodo_Click(System::Object^ sender, System::EventArgs^ e) {

	if (objComunicacion->estaAbierto()) // Verifica si el puerto está abierto
	{
		puerto = objComunicacion->obtenerPuerto(); // Obtiene el puerto desde la instancia de Comunicacion
		if (btnencendertodo->Text->Equals("ON"))
		{
			btnencendertodo->Text = "OFF";  // Cambia el texto del botón a "ON"
			puerto->Write("h");  // Envía el valor h al puerto serie
		}
		else
		{
			btnencendertodo->Text = "ON";  // Cambia el texto del botón a "OFF"
			puerto->Write("l");  // Envía el valor l al puerto serie
		}
	}
	else
	{
		MessageBox::Show("No se ha establecido una conexión con el puerto.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void btnPuertaCuartoUno_Click(System::Object^ sender, System::EventArgs^ e) { //Conectado a PIN 6 ARDUINO
	if (objComunicacion->estaAbierto()) // Verifica si el puerto está abierto
	{
		puerto = objComunicacion->obtenerPuerto(); // Obtiene el puerto desde la instancia de Comunicacion
		if (btnPuertaCuartoUno->Text->Equals("OPEN"))
		{
			btnPuertaCuartoUno->Image = Image::FromFile(PuertaCerrada);
			btnPuertaCuartoUno->Text = "CLOSE";  // Cambia el texto del botón a "OPEN"
			puerto->Write("i");  // Envía el valor i al puerto serie
		}
		else
		{
			btnPuertaCuartoUno->Image = Image::FromFile(PuertaAbierta);
			btnPuertaCuartoUno->Text = "OPEN";  // Cambia el texto del botón a "CLOSE"
			puerto->Write("j");  // Envía el valor j al puerto serie
		}
	}
	else
	{
		MessageBox::Show("No se ha establecido una conexión con el puerto.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

private: System::Void btnPuertaCuartoDos_Click(System::Object^ sender, System::EventArgs^ e) { //Conectado a PIN 7 ARDUINO
	if (objComunicacion->estaAbierto()) // Verifica si el puerto está abierto
	{
		puerto = objComunicacion->obtenerPuerto(); // Obtiene el puerto desde la instancia de Comunicacion
		if (btnPuertaCuartoDos->Text->Equals("OPEN"))
		{
			btnPuertaCuartoDos->Image = Image::FromFile(PuertaCerrada);
			btnPuertaCuartoDos->Text = "CLOSE";  // Cambia el texto del botón a "OPEN"
			puerto->Write("p");  // Envía el valor p al puerto serie
		}
		else
		{
			btnPuertaCuartoDos->Image = Image::FromFile(PuertaAbierta);
			btnPuertaCuartoDos->Text = "OPEN";  // Cambia el texto del botón a "CLOSE"
			puerto->Write("q");  // Envía el valor q al puerto serie
		}
	}
	else
	{
		MessageBox::Show("No se ha establecido una conexión con el puerto.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

private: System::Void btnVentiladorSala_Click(System::Object^ sender, System::EventArgs^ e) { //Conectado a PIN 12 ARDUINO
	if (objComunicacion->estaAbierto()) // Verifica si el puerto está abierto
	{
		puerto = objComunicacion->obtenerPuerto(); // Obtiene el puerto desde la instancia de Comunicacion
		if (btnVentiladorSala->Text->Equals("ON"))
		{
			btnVentiladorSala->Image = Image::FromFile(VentiladorApagado);
			btnVentiladorSala->Text = "OFF";  // Cambia el texto del botón a "ON"
			puerto->Write("r");  // Envía el valor n al puerto serie
		}
		else
		{
			btnVentiladorSala->Image = Image::FromFile(VentiladorEncendido);
			btnVentiladorSala->Text = "ON";  // Cambia el texto del botón a "OFF"
			puerto->Write("s");  // Envía el valor o al puerto serie
		}
	}
	else
	{
		MessageBox::Show("No se ha establecido una conexión con el puerto.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

private: System::Void btnVentiladorPasillo_Click(System::Object^ sender, System::EventArgs^ e) { //Conectado a PIN 13 ARDUINO
	if (objComunicacion->estaAbierto()) // Verifica si el puerto está abierto
	{
		puerto = objComunicacion->obtenerPuerto(); // Obtiene el puerto desde la instancia de Comunicacion
		if (btnVentiladorSala->Text->Equals("ON"))
		{
			btnVentiladorSala->Image = Image::FromFile(VentiladorApagado);
			btnVentiladorSala->Text = "OFF";  // Cambia el texto del botón a "ON"
			puerto->Write("t");  // Envía el valor n al puerto serie
		}
		else
		{
			btnVentiladorSala->Image = Image::FromFile(VentiladorEncendido);
			btnVentiladorSala->Text = "ON";  // Cambia el texto del botón a "OFF"
			puerto->Write("u");  // Envía el valor o al puerto serie
		}
	}
	else
	{
		MessageBox::Show("No se ha establecido una conexión con el puerto.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
};
}