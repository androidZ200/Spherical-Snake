#pragma once
using namespace System::Threading;
#include <SFML/Graphics.hpp>
#include "GameSpace.h"
#include <string>

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
			//
			//TODO: добавьте код конструктора
			//
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
	private: System::Windows::Forms::Button^ buttonStart;
	private: System::Windows::Forms::Button^ buttonCreateServer;
	private: System::Windows::Forms::Button^ buttonConnect;
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
			this->buttonStart = (gcnew System::Windows::Forms::Button());
			this->buttonCreateServer = (gcnew System::Windows::Forms::Button());
			this->buttonConnect = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// buttonStart
			// 
			this->buttonStart->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonStart->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->buttonStart->FlatAppearance->BorderSize = 0;
			this->buttonStart->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonStart->ForeColor = System::Drawing::Color::White;
			this->buttonStart->Location = System::Drawing::Point(13, 13);
			this->buttonStart->Name = L"buttonStart";
			this->buttonStart->Size = System::Drawing::Size(211, 38);
			this->buttonStart->TabIndex = 0;
			this->buttonStart->Text = L"Одиночная игра";
			this->buttonStart->UseVisualStyleBackColor = false;
			this->buttonStart->Click += gcnew System::EventHandler(this, &StartForm::buttonStart_Click);
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
			this->buttonCreateServer->Location = System::Drawing::Point(13, 57);
			this->buttonCreateServer->Name = L"buttonCreateServer";
			this->buttonCreateServer->Size = System::Drawing::Size(211, 38);
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
			this->buttonConnect->Location = System::Drawing::Point(13, 101);
			this->buttonConnect->Name = L"buttonConnect";
			this->buttonConnect->Size = System::Drawing::Size(211, 38);
			this->buttonConnect->TabIndex = 2;
			this->buttonConnect->Text = L"Присоединиться";
			this->buttonConnect->UseVisualStyleBackColor = false;
			// 
			// StartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->ClientSize = System::Drawing::Size(236, 152);
			this->Controls->Add(this->buttonConnect);
			this->Controls->Add(this->buttonCreateServer);
			this->Controls->Add(this->buttonStart);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"StartForm";
			this->ResumeLayout(false);

		}
#pragma endregion

		GameSpace* game;
		Object^ locker = gcnew Object();
		sf::CircleShape* cir;
		bool isPause = false;
		bool isPausePressed = false;
		const int radius = 8;

	private: System::Void buttonStart_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Visible = false;
		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;
		sf::RenderWindow window(sf::VideoMode(600, 600), "", sf::Style::Default, settings);
		game = new GameSpace(SkinGenerate::Generate());
		cir = new sf::CircleShape(radius);
		Thread^ t = gcnew Thread(gcnew ThreadStart(this, &StartForm::LoopGame));
		t->Start();
		isPause = false;
		
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					window.close();
					game->Stop();
				}
				else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) game->Stop();
				else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Pause && !isPausePressed) {
					isPause = !isPause;
					isPausePressed = true;
				}
				else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Pause) isPausePressed = false;
			}
			if (!game->isPlaying()) window.close();

			window.clear(sf::Color::Color(28, 28, 28));
			int i = 0;
			Monitor::Enter(locker);
				for (auto x = game->Snake()->begin(); x != game->Snake()->end(); ++x, ++i)
					DrawCircle(&window, mult(game->Snake()->GetMatrix(), *x), game->Snake()->GetColor(i));
				DrawCircle(&window, mult(game->Snake()->GetMatrix(), game->GetEatPosition()), sf::Color::Red);
			Monitor::Exit(locker);
			window.display();
			window.setTitle(std::to_string(game->GetCount()));
		}
		t->Join();
		delete cir;
		this->Visible = true;
		MessageBox::Show("Length: " + game->Snake()->size().ToString());
		delete game;
	}

	private: void LoopGame() {
		sf::Clock time;
		while (game->isPlaying()) {
			time.restart();
			if (!isPause) {
				Monitor::Enter(locker);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) ||
						sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) game->Snake()->Rotate(false);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) ||
						sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) game->Snake()->Rotate(true);
					game->Snake()->Move();
					game->Check();
				Monitor::Exit(locker);
			}
			int t = time.getElapsedTime().asMilliseconds();
			Thread::Sleep(Math::Max(40 - t, 0));
		}
	}
	private: Vector mult(const Matrix& mat, const Vector& vec) {
		Vector res(mat.size());
		for (int i = 0; i < res.GetSize(); i++) {
			res[i] = 0;
			for (int j = 0; j < mat.size(); j++)
				res[i] += mat(j, i) * vec[j];
		}
		return res;
	}
	private: void DrawCircle(sf::RenderWindow* window, Vector coord, sf::Color col) {
		double len = acos(coord[2]);
		if (len * len < 8) {
			coord[2] = 0;
			if (len > 0.01)	coord.normalize();
			double R = 0;
			if (len < 0.01) R = radius;
			else R = radius * len / Math::Sin(len);
			cir->setRadius(R);
			cir->setPosition((coord[0] * len + 1.75) * 171 - R, (-coord[1] * len + 1.75) * 171 - R);
			cir->setFillColor(col);
			window->draw(*cir);
		}
	}
	};
}
