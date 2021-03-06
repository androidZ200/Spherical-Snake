#pragma once
using namespace System::Threading;
#include <SFML/Graphics.hpp>
#include "GameClassic.h"
#include "GameZen.h"
#include "GameOfflineMultiplayer.h"
#include "KeysController.h"
#include "MouseController.h"
#include "HyperDrawer.h"
#include "SphericalDrawer.h"
#include <string>
#include "Player.h"
#include <time.h>
#include <iostream>

namespace Snake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� StartForm
	/// </summary>
	public ref class StartForm : public System::Windows::Forms::Form
	{
	public:
		StartForm(void)
		{
			InitializeComponent();
			srand(time(0));
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~StartForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonStartClassic;
	private: System::Windows::Forms::Button^ buttonCreateServer;
	private: System::Windows::Forms::Button^ buttonConnect;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ buttonStartDzen;
	private: System::Windows::Forms::Button^ buttonToPlayers;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	protected:



	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonStartClassic = (gcnew System::Windows::Forms::Button());
			this->buttonCreateServer = (gcnew System::Windows::Forms::Button());
			this->buttonConnect = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonStartDzen = (gcnew System::Windows::Forms::Button());
			this->buttonToPlayers = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// buttonStartClassic
			// 
			this->buttonStartClassic->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonStartClassic->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->buttonStartClassic->FlatAppearance->BorderSize = 0;
			this->buttonStartClassic->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonStartClassic->ForeColor = System::Drawing::Color::White;
			this->buttonStartClassic->Location = System::Drawing::Point(13, 29);
			this->buttonStartClassic->Name = L"buttonStartClassic";
			this->buttonStartClassic->Size = System::Drawing::Size(164, 38);
			this->buttonStartClassic->TabIndex = 0;
			this->buttonStartClassic->Text = L"��������";
			this->buttonStartClassic->UseVisualStyleBackColor = false;
			this->buttonStartClassic->Click += gcnew System::EventHandler(this, &StartForm::buttonStartClassic_Click);
			// 
			// buttonCreateServer
			// 
			this->buttonCreateServer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonCreateServer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->buttonCreateServer->Enabled = false;
			this->buttonCreateServer->FlatAppearance->BorderSize = 0;
			this->buttonCreateServer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonCreateServer->ForeColor = System::Drawing::Color::White;
			this->buttonCreateServer->Location = System::Drawing::Point(12, 114);
			this->buttonCreateServer->Name = L"buttonCreateServer";
			this->buttonCreateServer->Size = System::Drawing::Size(165, 38);
			this->buttonCreateServer->TabIndex = 1;
			this->buttonCreateServer->Text = L"������� ������";
			this->buttonCreateServer->UseVisualStyleBackColor = false;
			// 
			// buttonConnect
			// 
			this->buttonConnect->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonConnect->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->buttonConnect->Enabled = false;
			this->buttonConnect->FlatAppearance->BorderSize = 0;
			this->buttonConnect->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonConnect->ForeColor = System::Drawing::Color::White;
			this->buttonConnect->Location = System::Drawing::Point(187, 114);
			this->buttonConnect->Name = L"buttonConnect";
			this->buttonConnect->Size = System::Drawing::Size(164, 38);
			this->buttonConnect->TabIndex = 2;
			this->buttonConnect->Text = L"��������������";
			this->buttonConnect->UseVisualStyleBackColor = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(31, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(91, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"��������� ����:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(30, 91);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(96, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"���� � ��������:";
			// 
			// buttonStartDzen
			// 
			this->buttonStartDzen->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonStartDzen->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->buttonStartDzen->FlatAppearance->BorderSize = 0;
			this->buttonStartDzen->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonStartDzen->ForeColor = System::Drawing::Color::White;
			this->buttonStartDzen->Location = System::Drawing::Point(187, 29);
			this->buttonStartDzen->Name = L"buttonStartDzen";
			this->buttonStartDzen->Size = System::Drawing::Size(164, 38);
			this->buttonStartDzen->TabIndex = 5;
			this->buttonStartDzen->Text = L"����";
			this->buttonStartDzen->UseVisualStyleBackColor = false;
			this->buttonStartDzen->Click += gcnew System::EventHandler(this, &StartForm::buttonStartDzen_Click);
			// 
			// buttonToPlayers
			// 
			this->buttonToPlayers->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonToPlayers->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->buttonToPlayers->FlatAppearance->BorderSize = 0;
			this->buttonToPlayers->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonToPlayers->ForeColor = System::Drawing::Color::White;
			this->buttonToPlayers->Location = System::Drawing::Point(13, 162);
			this->buttonToPlayers->Name = L"buttonToPlayers";
			this->buttonToPlayers->Size = System::Drawing::Size(165, 38);
			this->buttonToPlayers->TabIndex = 6;
			this->buttonToPlayers->Text = L"�� ����� ����������";
			this->buttonToPlayers->UseVisualStyleBackColor = false;
			this->buttonToPlayers->Click += gcnew System::EventHandler(this, &StartForm::buttonToPlayers_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(31, 220);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(69, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"���������:";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->ForeColor = System::Drawing::Color::White;
			this->checkBox1->Location = System::Drawing::Point(34, 239);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(137, 17);
			this->checkBox1->TabIndex = 8;
			this->checkBox1->Text = L"���������� �������";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->ForeColor = System::Drawing::Color::White;
			this->checkBox2->Location = System::Drawing::Point(33, 262);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(168, 17);
			this->checkBox2->TabIndex = 9;
			this->checkBox2->Text = L"����������� � ���� �����";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Checked = true;
			this->checkBox3->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox3->ForeColor = System::Drawing::Color::White;
			this->checkBox3->Location = System::Drawing::Point(33, 285);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(133, 17);
			this->checkBox3->TabIndex = 10;
			this->checkBox3->Text = L"���������� ������";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// StartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->ClientSize = System::Drawing::Size(363, 311);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->buttonToPlayers);
			this->Controls->Add(this->buttonStartDzen);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonConnect);
			this->Controls->Add(this->buttonCreateServer);
			this->Controls->Add(this->buttonStartClassic);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"StartForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void buttonStartClassic_Click(System::Object^ sender, System::EventArgs^ e) {
		IGame* game = new GameClassic(new Player(new SnakeBody(SkinGenerate::Generate()), GetKeys(), GetDrawer(700)));
		LoopGame(game);
		MessageBox::Show("Length: " + game->GetSnake(0)->size().ToString());
		delete game;
	}
	private: System::Void buttonStartDzen_Click(System::Object^ sender, System::EventArgs^ e) {
		IGame* game = new GameZen(new Player(new SnakeBody(SkinGenerate::Generate()), GetKeys(), GetDrawer(700)));
		LoopGame(game);
		MessageBox::Show("Length: " + game->GetSnake(0)->size().ToString());
		delete game;
	}
	private: System::Void buttonToPlayers_Click(System::Object^ sender, System::EventArgs^ e) {
		KeysController* con1 = new KeysController(ControlKeys(sf::Keyboard::Right, sf::Keyboard::Left));
		KeysController* con2 = new KeysController(ControlKeys(sf::Keyboard::D, sf::Keyboard::A));
		GameOfflineMultiplayer* game = new GameOfflineMultiplayer(
			new Player(new SnakeBody(new SkinBlueWave()), con1, GetDrawer(600)),
			new Player(new SnakeBody(new SkinLava()), con2, GetDrawer(600)));
		LoopGame(game);
		if (game->isWinPlayerOne()) MessageBox::Show("����� ����� �������");
		else MessageBox::Show("������� ����� �������");
		delete game;
	}
	private: void LoopGame(IGame* game) {
		this->Visible = false;
		sf::Clock time;
		while (game->isPlaying()) {
			time.restart();
			game->Tick();
			int t = time.getElapsedTime().asMilliseconds();
			Thread::Sleep(Math::Max(40 - t, 0));
			std::cout << "1";
		}
		this->Visible = true;
	}
	private: IController* GetKeys() {
		if(checkBox3->Checked) return new MouseController();
		KeysController* con = new KeysController(ControlKeys(sf::Keyboard::Right, sf::Keyboard::Left));
		con->AddKeys(ControlKeys(sf::Keyboard::D, sf::Keyboard::A));
		return con;
	}
	private: SFMLDrawer* GetDrawer(int size) {
		SFMLDrawer* drw;
		if (!checkBox2->Checked) drw = new HyperDrawer(size, checkBox1->Checked);
		else drw = new SphericalDrawer(size, checkBox1->Checked);
		return drw;
	}
	};
}
