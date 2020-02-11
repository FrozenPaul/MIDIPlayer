// MidiTestPlayer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
//#include <cxxmidi/MyNoteCallaback.hpp>
//#include <MidiTestPlayer/MyNoteCallaback.h>
#pragma warning (push)

#pragma warning(disable : 4083)
#include <cxxmidi/file.hpp>
#include <cxxmidi/output/default.hpp>
#include <cxxmidi/player/synchronous.hpp>
#pragma warning(pop) 

#include <cxxmidi/MyNoteCallaback.hpp>

int main(int /*argc*/, char** /*argv*/)
{
	CxxMidi::Output::Default output;
	for (int i = 0; i < output.getPortCount(); i++)
		std::cout << i << ": " << output.getPortName(i) << std::endl;
	output.openPort(0);

	CxxMidi::File file("C://Users//User//Downloads//Unravel (1).mid");

	CxxMidi::Player::Synchronous player(&output);
	player.setFile(&file);

	//struct MyCallback : public CxxMidi::Callback
	//{
	//	void operator()  () override
	//	{
	//		{
	//			
	//			//std::cout << player_.currentTimePos()<< "  " << std::endl;

	//		}
	//	}
	//	MyCallback(CxxMidi::Player::Synchronous& p)
	//		: player_(p) {}
	//	CxxMidi::Player::Synchronous& player_;
	//};

	//MyCallback callback(player);

	struct MyNoteCallback : CxxMidi::MyNoteCallaback
	{
		void operator() (CxxMidi::Note note,bool is_pressed) override
		{
			{
				std::cout << "Note :" << CxxMidi::Note::name(note) << " is pressed : " << is_pressed << std::endl;
			}
		}
		MyNoteCallback(CxxMidi::Player::Synchronous& p)
			: player_(p) {}
		CxxMidi::Player::Synchronous& player_;
	};

	MyNoteCallback note_callback(player);
	player.repeatCallback(&note_callback);

	//player.setCallbackHeartbeat(&callback);
	player.setSpeed(0.5);
	player.play();
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
