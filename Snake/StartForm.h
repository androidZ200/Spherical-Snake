#pragma once
using namespace System::Threading;
#include <SFML/Graphics.hpp>
#include "GameClassic.h"
#include "GameZen.h"
#include <string>
#include "Player.h"
#include <time.h>

namespace Snake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для StartForm
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
		/// Освободить все используемые ресурсы.
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
	protected:



	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
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
			this->buttonStartClassic->Text = L"Классика";
			this->buttonStartClassic->UseVisualStyleBackColor = false;
			this->buttonStartClassic->Click += gcnew System::EventHandler(this, &StartForm::buttonStartClassic_Click);
			// 
			// buttonCreateServer
			// 
			this->buttonCreateServer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonCreateServer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->buttonCreateServer->FlatAppearance->BorderSize = 0;
			this->buttonCreateServer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonCreateServer->ForeColor = System::Drawing::Color::White;
			this->buttonCreateServer->Location = System::Drawing::Point(12, 114);
			this->buttonCreateServer->Name = L"buttonCreateServer";
			this->buttonCreateServer->Size = System::Drawing::Size(165, 38);
			this->buttonCreateServer->TabIndex = 1;
			this->buttonCreateServer->Text = L"Создать сервер";
			this->buttonCreateServer->UseVisualStyleBackColor = false;
			// 
			// buttonConnect
			// 
			this->buttonConnect->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonConnect->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->buttonConnect->FlatAppearance->BorderSize = 0;
			this->buttonConnect->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonConnect->ForeColor = System::Drawing::Color::White;
			this->buttonConnect->Location = System::Drawing::Point(187, 114);
			this->buttonConnect->Name = L"buttonConnect";
			this->buttonConnect->Size = System::Drawing::Size(164, 38);
			this->buttonConnect->TabIndex = 2;
			this->buttonConnect->Text = L"Присоединиться";
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
			this->label1->Text = L"Одиночная игра:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(30, 91);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(96, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Игра с друзьями:";
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
			this->buttonStartDzen->Text = L"Дзэн";
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
			this->buttonToPlayers->Text = L"На одном компьютере";
			this->buttonToPlayers->UseVisualStyleBackColor = false;
			// 
			// StartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->ClientSize = System::Drawing::Size(363, 212);
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
		IGame* game = new GameClassic(new Player(new SnakeBody(SkinGenerate::Generate())));
		LoopGame(game);
		delete game;
	}
	private: System::Void buttonStartDzen_Click(System::Object^ sender, System::EventArgs^ e) {
		IGame* game = new GameZen(new Player(new SnakeBody(SkinGenerate::Generate())));
		LoopGame(game);
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
		}
		this->Visible = true;
		MessageBox::Show("Length: " + game->GetSnake(0)->size().ToString());
	}
	};
}
