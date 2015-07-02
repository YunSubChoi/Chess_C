#include<stdio.h>
#include<conio.h>
#include<ctime>
#include <stdlib.h>
#include <windows.h>
#include"moverule.h"
#include"tools.h"

void hubvalue(int hub[][10])
{

	hub[0][0] = 'r', hub[0][1] = 'n', hub[0][2] = 'b', hub[0][3] = 'q', hub[0][4] = 'k', hub[0][5] = 'b', hub[0][6] = 'n', hub[0][7] = 'r', hub[0][8] = '8', hub[0][9] = ' ';
	hub[1][0] = 'p', hub[1][1] = 'p', hub[1][2] = 'p', hub[1][3] = 'p', hub[1][4] = 'p', hub[1][5] = 'p', hub[1][6] = 'p', hub[1][7] = 'p', hub[1][8] = '7', hub[1][9] = ' ';
	hub[2][0] = '_', hub[2][1] = '_', hub[2][2] = '_', hub[2][3] = '_', hub[2][4] = '_', hub[2][5] = '_', hub[2][6] = '_', hub[2][7] = '_', hub[2][8] = '6', hub[2][9] = ' ';
	hub[3][0] = '_', hub[3][1] = '_', hub[3][2] = '_', hub[3][3] = '_', hub[3][4] = '_', hub[3][5] = '_', hub[3][6] = '_', hub[3][7] = '_', hub[3][8] = '5', hub[3][9] = ' ';
	hub[4][0] = '_', hub[4][1] = '_', hub[4][2] = '_', hub[4][3] = '_', hub[4][4] = '_', hub[4][5] = '_', hub[4][6] = '_', hub[4][7] = '_', hub[4][8] = '4', hub[4][9] = ' ';
	hub[5][0] = '_', hub[5][1] = '_', hub[5][2] = '_', hub[5][3] = '_', hub[5][4] = '_', hub[5][5] = '_', hub[5][6] = '_', hub[5][7] = '_', hub[5][8] = '3', hub[5][9] = ' ';
	hub[6][0] = 'P', hub[6][1] = 'P', hub[6][2] = 'P', hub[6][3] = 'P', hub[6][4] = 'P', hub[6][5] = 'P', hub[6][6] = 'P', hub[6][7] = 'P', hub[6][8] = '2', hub[6][9] = ' ';
	hub[7][0] = 'R', hub[7][1] = 'N', hub[7][2] = 'B', hub[7][3] = 'K', hub[7][4] = 'Q', hub[7][5] = 'B', hub[7][6] = 'N', hub[7][7] = 'R', hub[7][8] = '1', hub[7][9] = ' ';

}

void safhe(int arr[][10], char Fplayer[], char Splayer[])
{

	//mohre ha(gheyr sarbaz)-Team2
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (int(arr[i][j] > 96))
			{
				setTextColore(0, 7);

			}
			else if (int(arr[i][j] == 95))
			{
				setTextColore(7, 5);
			}
			else if (int(arr[i][j] < 95))
			{
				setTextColore(7, 0);

			}
			printf("|%c", arr[i][j]);
			setTextColore(7, 5);
		}
		printf("\n");
	}
	gotoxy(20, 0);
	puts(Fplayer);
	gotoxy(20, 7);
	puts(Splayer);
	printf("\n A B C D E F G H");
}

void teamturn(int &tt, char fplayer[], char splayer[])
{
	if (tt == (-1))
	{
		printf("\nTeam Turn: ");
		puts(fplayer);
	}
	else if (tt == (1))
	{
		printf("\nTeam Turn: ");
		puts(splayer);
	}
	else printf("\nTeam (?) Turn! \n\n");


}

void menu()
{
	printf(" MENU\n\n_Click the # of the action you want to do.\n");
	printf("_Press 'N' for New.\n");
	printf("_Press 'S' To Save Game. \n");
	printf("_Press 'NUM 4' To QUIT.\n");

}

void splash(char Fplayer[], char Splayer[], int &clockstart)

{
	setTextColore(7, 5);
	for (int i = 1; i <= 80; i++)
		printf("*");
	for (int i = 1; i <= 20; i++)
	{
		printf("*");
		for (int j = 1; j <= 78; j++)
			printf(" ");
		printf("*");
	}

	gotoxy(28, 20);
	printf("*CHESS - MEHDI AKBARIAN*\n");
	for (int i = 1; i <= 80; i++)
		printf("*");

	gotoxy(25, 0);
	printf("*");
	gotoxy(0, 5);
	printf("*                                      ###                        \n");
	printf("*                                    #######                      \n");
	printf("*             ### ## ## ###            ###          ### ## ## ### \n");
	printf("*              ## ## ## ##         ###########       ## ## ## ##  \n");
	printf("*              ###########          #########        ###########  \n");
	printf("*                #######            #########          #######    \n");
	printf("*                #######             #######           #######    \n");
	printf("*                #######             #######           #######    \n");
	printf("*                #######             #######           #######    \n");
	printf("*                #######             #######           #######    \n");
	printf("*               ##########          #########        ##########   \n");
	printf("*      ...... ##############......#############.....#############..... \n");

	gotoxy(4, 3);
	printf("Player 1 Name: ");
	gets(Fplayer);
	gotoxy(35, 3);
	printf("Player 2 Name: ");
	gets(Splayer);

	gotoxy(60, 3);
	for (int i = 0; i <= 3; i++)
	{
		gotoxy(35, 19);
		printf("||    ");
		sleep(50);
		gotoxy(35, 19);
		printf(" ||   ");
		sleep(50);
		gotoxy(35, 19);
		printf("  ||  ");
		sleep(50);
		gotoxy(35, 19);
		printf("   || ");
		sleep(50);
		gotoxy(35, 19);
		printf("    ||");
		sleep(50);
	}
	clockstart = clock();
	clrscr();
}

void lastsplash(int sw, char temp1moh, char temp2moh, int tg, char Fplayer[], char Splayer[])
{
	if (sw == 2)
	{
		gotoxy(30, 5);
		printf("                                 \n");
		gotoxy(30, 6);
		printf("                                 \n");
		gotoxy(30, 7);
		printf("               ### ## ## ###     \n");
		gotoxy(30, 8);
		printf("                ## ## ## ##      \n");
		gotoxy(30, 9);
		printf("                ###########      \n");
		gotoxy(30, 10);
		printf("                  #######        \n");
		gotoxy(30, 11);
		printf("                  #######      #  \n");
		gotoxy(30, 12);
		printf("                  #######      ###          # \n");
		gotoxy(30, 13);
		printf("                  #######      #############   #\n");
		gotoxy(30, 14);
		printf("                  #######      ################## \n");
		gotoxy(30, 15);
		printf("                 ##########    #############   #\n");
		gotoxy(30, 16);
		printf("               ##############  ###          #\n");
		gotoxy(30, 17);
		printf("               ##############  #             \n");
		if (int(temp1moh) >= 75 && int(temp1moh) <= 82 && int(temp2moh == 113))
		{
			gotoxy(0, 21);
			printf("player %S win! time:%d", Splayer, tg);
			sleep(1000);
		}
		if (int(temp1moh) >= 98 && int(temp1moh) <= 116 && int(temp2moh) == 81)
		{
			gotoxy(0, 21);
			printf("Player %s win! time:%d", Fplayer, tg);
			sleep(1000);
		}
		gotoxy(25, 23);
		printf("GAME OVER!press any key...!");
		getch();
	}
}

void clock(int tg, int temp1p, int chx, int chy, int clockstart)
{
	
		double tt = (clock() - tg) / 1000.0;
		gotoxy(0, 19);
		printf("run time: %.2f", tt);
		gotoxy(chx, chy);
		sleep(50);
}

void point(int &firstpoint, int &secondpoint, char temp2moh, char fplayer[], char splayer[], int chx, int chy, long int timeP1, long int timeP2)
{
while (true)
{
char tempchar = temp2moh;
switch (temp2moh){
case 'P':
firstpoint += 1;
break;
case'R':
firstpoint += 5;
break;
case'N':
case'B':
firstpoint += 3;
break;
case'K':
firstpoint += 100;
break;
case'Q':
firstpoint += 10;
break;
//=============
case 'p':
secondpoint += 1;
break;
case'r':
secondpoint += 5;
break;
case'n':
case'b':
secondpoint += 3;
break;
case'k':
secondpoint += 100;
break;
case'q':
secondpoint += 10;
break;
}
gotoxy(0, 20);
printf("player %s point : %d and time: %d ", fplayer, firstpoint,timeP1/1000);
gotoxy(0, 21);
printf("player %s point : %d and time: %d", splayer, secondpoint,timeP2/1000);
gotoxy(chx, chy);
break;
}
} 

void loadpage(int arr[][10], char fplayer[],char splayer[])
{
	gotoxy(0, 0);
	FILE *loadopen,*loadfinder;
	char savename[11], savechoose[10];
	int n = 3;
	loadfinder = fopen("saveList.dat", "rb");
	if (!loadfinder)
	{
		printf("No saved game!");
		getch();
		return;
	}
	gotoxy(0, 2);
	while (!feof(loadfinder))
	{
		fread(savename, sizeof(char) * 10, 1, loadfinder);
		printf("%s", savename);
		printf("\n");
		n--;
	}
	fclose(loadfinder);
	
	gotoxy(0, 0);
	printf("write save name:");
	scanf("%s",savechoose);
	loadopen = fopen(savechoose, "rb");
	fread(arr, sizeof(int), 80, loadopen);
	gotoxy(0, 0);

	safhe(arr, fplayer, splayer);
	menu();
}