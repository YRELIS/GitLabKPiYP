// ochko.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <iostream>
using namespace std;

int koloda[9] = {  6, 7, 8, 9, 10, 2, 3, 4, 11 };
int karta() { return  rand() % 9; }

int main()
{
	setlocale(LC_ALL, "Russian");
	int igrok, komp, kart;
	char  ans, buf;
	time_t t;
	srand((unsigned)time(&t));
	do
	{
		cout << "\n****************** 21 ОЧКО ***************\n\n";
		cout << "\t\tКарта 6 = 6 \n \t\tКарта 7 = 7\n \t\tКарта 8 = 8\n \t\tКарта 9 = 9\n \t\tКарта 10 = 10\n\t\tКарта валет = 2\n \t\tКарта дама = 3\n \t\tКарта король = 4\n \t\tКарта туз = 11\n\n" << endl;
		komp = 0; igrok = 0;
		do
		{
			kart = karta();
			printf("Ваша карта: %d ", koloda[kart]);
			igrok += koloda[kart];
			printf("\tСумма = %d\n", igrok);
			if (igrok>21)
			{
				printf("У Вас перебор, Вы проиграли!\n ");
				break;
			}

			cout << "взять еще? ('y' - да, 'n' - нет) : ";
			ans = getchar();
			buf = getchar();
		} while (ans != 'n');

		if (igrok <= 21)
		{
			printf("\nКарты компьютера:");
			do
			{
				kart = karta();
				printf(" %d", koloda[kart]);
				komp += koloda[kart];
			} while (komp<17);
			printf("\t Сумма = %d", komp);
			if (igrok>komp) printf(" \n\nПоздравляем, Вы выиграли! \n");
			if (igrok == komp) printf(" \n\nНичья! \n");
			if (igrok<komp && komp <= 21)  printf(" \n\nВы проиграли! \n");
			if (igrok<komp && komp>21) printf("\n\nУ компьютера перебор, Вы выиграли! \n");
			
		}
		printf(" \nиграть еще? ('y' - да, 'n' - нет) : ");
		ans = getchar();
		buf = getchar();
		system("cls");
	} while (ans != 'n');

	printf(" \n Для выхода нажмите Enter! \n ");
	_getch();
}