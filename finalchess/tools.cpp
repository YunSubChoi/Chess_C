#include<stdio.h>
#include<conio.h>
#include<ctime>
#include <stdlib.h>
#include <windows.h>
#include"tools.h"

void setTextColore(int textColor, int backColor = 0)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int colorAttribute = backColor << 4 | textColor;
	SetConsoleTextAttribute(consoleHandle, colorAttribute);
}

void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorCoord;
	cursorCoord.X = x;
	cursorCoord.Y = y;
	int colorAttribute = 8 << 4 | 9;
	SetConsoleCursorPosition(consoleHandle, cursorCoord);
}

void clrscr()
{
	system("cls");
}

void sleep(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}

void save(int arr[][10], char saveList[][10], int &saveCounter)
{
	FILE *savefile, *saveTemp;
	int temp;
	gotoxy(40, 10);
	printf("save name: ");
	gets(saveList[saveCounter]);
	strcat(saveList[saveCounter], ".dat");
	savefile = fopen(saveList[saveCounter], "w+b");
	if (!savefile)
	{
		gotoxy(25, 5);
		printf("cant save!");
	}
	fwrite(arr, sizeof(int), 80, savefile);
	fclose(savefile);
	saveTemp = fopen("saveList.dat", "ab");
	fwrite(saveList[saveCounter], sizeof(char), 10, saveTemp);
	fclose(saveTemp);
	if (savefile)
	{
		gotoxy(40, 10);
		printf("           saved!");
	}
}

void changeturn(int &tempsw, int &y, char &temp1p)
{
	tempsw = tempsw*(-1);
	y *= (-1);
	temp1p = '?';
}

void movekey(int charRead2, int &chx, int &chy, int keyRead)
{
	switch (int(charRead2))
	{
	case 75:

		chx -= 2;
		keyRead = 4;
		break;

	case 77:

		chx += 2;
		keyRead = 2;
		break;
	case 72:

		chy -= 1;
		keyRead = 1;
		break;
	case 80:

		chy += 1;
		keyRead = 3;
		break;
	}

}