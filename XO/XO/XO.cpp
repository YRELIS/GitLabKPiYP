// XO.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;

static char game_arr[10] = "123456789";
bool player = 1;

void first_win() 
{
	cout << "первый игрок(X) победил!";
	system("pause >nul");
	exit(0);
}

void second_win() 
{
	cout << "второй игрок(O) победил!";
	system("pause >nul");
	exit(0);
}

void test_win()
{
	for (int i = 0; i < 3; ++i)
		if (game_arr[i] == 'X' && game_arr[i + 3] == 'X' && game_arr[i + 6] == 'X') first_win();
	for (int i = 0; i < 9; i += 3)
		if (game_arr[i] == 'X' && game_arr[i + 1] == 'X' && game_arr[i + 2] == 'X') first_win();
	for (int i = 0; i < 3; ++i)
		if (game_arr[i] == 'O' && game_arr[i + 3] == 'O' && game_arr[i + 6] == 'O') second_win();
	for (int i = 0; i < 9; i += 3)
		if (game_arr[i] == 'O' && game_arr[i + 1] == 'O' && game_arr[i + 2] == 'O') second_win();
	if (game_arr[0] == 'X' && game_arr[4] == 'X' && game_arr[8] == 'X')  first_win();
	if (game_arr[0] == 'O' && game_arr[4] == 'O' && game_arr[8] == 'O')  second_win();
	if (game_arr[2] == 'X' && game_arr[4] == 'X' && game_arr[6] == 'X')  first_win();
	if (game_arr[2] == 'O' && game_arr[4] == 'O' && game_arr[6] == 'O')  second_win();
}

void write(char arr[])
{

	for (int i = 0; i < 9;i += 3) 
	{
		cout <<  arr[i] << "\t " << arr[i+1] << "\t " << arr[i+2] << "\t\n " << endl;
	}
}

void step()
{
	HANDLE Elisei = GetStdHandle(STD_OUTPUT_HANDLE);
	int newstep;
	if (player) 
	{
		SetConsoleTextAttribute(Elisei, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "игрок(X) ходит: ";
		cin >> newstep;
		if (game_arr[newstep - 1] != 'X' && game_arr[newstep - 1] != 'O') {

			game_arr[newstep - 1] = 'X';
			player = !player;
			SetConsoleTextAttribute(Elisei, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		}else {
			cout << "туда уже ходили!";
			system("pause >nul");
		}
	}
	else
	{
		cout << "компьютер(O) ходит: ";
		newstep = rand()%9;
		if (game_arr[newstep - 1] != 'X' && game_arr[newstep - 1] != 'O') {
			game_arr[newstep - 1] = 'O';
			player = !player;
		}
	}
}

void loop() 
{
	while (true) 
	{
		write(game_arr);
		test_win();
		step();
		system("cls");
	}
}

void main()
{
	HANDLE Elisei = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(Elisei, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	system("chcp 1251 >nul");
	loop();
}
