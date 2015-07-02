#include<stdio.h>
#include<conio.h>
#include<ctime>
#include <stdlib.h>
#include <windows.h>
#include"moverule.h"
#include"tools.h"
#include"pages.h"
#include"pressP.h"
void main()
{
	int hub[10][10], chx = 1, chy = 0, sw = 0, tg=0, y = 0, tempsw = 1, temp1x = 0, temp1y = 0, temp2x = 0, temp2y = 0, firstmove = 0, tempPx, tempPy, keyRead, tempKN, tempbish, tempR1, tempQ, tempK, clockstart = 0;
	char temp1moh = '_', temp2moh = '_', temp1mohS, temp1p, charRead1, charRead2, tempLp, tempRp, tempFp, temp2Fp, tempFP, temp2FP, fplayer[15], splayer[15];
	char saveList[20][10];
	int saveCounter = 0, firstpoint = 0, secondpoint = 0;
	//===============
	long int timeP1=0, timeP2=0, turnTime;
	//=================
	hubvalue(hub);
	splash(fplayer, splayer, clockstart);
	safhe(hub, fplayer, splayer);
	teamturn(y, fplayer, splayer);
	menu();
	turnTime = clock();
	while (sw == 0)
	{
		if (_kbhit())
		{
			charRead1 = getch();
			if (int(charRead1) == -32)
			{
				charRead2 = getch();
				movekey(charRead2, chx, chy, keyRead);
			}
			switch (int(charRead1))
			{
			case 52:
				sw += 1;
				break;
			case 83:
			case 115:
				save(hub,saveList,saveCounter);
				break;
			case 112:
			case 80:
				firstpressmove(firstmove, chy, chx, y);
				firstpress(tempsw, y, temp1x, temp1y, chx, chy, tempPx, tempPy, temp1moh, hub, temp1p, tempLp, tempRp, temp2Fp, tempFp, tempFP, temp2FP);
				secendpress(temp1mohS, tempQ, keyRead, tempKN, tempbish, tempR1, temp2moh, temp2y, temp2x, tempK, splayer, fplayer, tempsw, y, temp1x, temp1y, chx, chy, tempPx, tempPy, temp1moh, hub, temp1p, tempLp, tempRp, temp2Fp, tempFp, tempFP, temp2FP,firstpoint, secondpoint,turnTime, ((y == -1) ? timeP1 : timeP2),timeP1,timeP2);
				break;
			case 78:
			case int('n'):
				hubvalue(hub);
				gotoxy(0, 0);
				turnTime = clock();
				safhe(hub, fplayer, splayer);
				firstmove = 0;
				break;
			case int('l') :
				clrscr();
				loadpage(hub,fplayer,splayer);
				break;
			}
			//******************* P Rule ************************************
			Prule(temp1p, temp1x, temp1y, chx, chy, tempPx, tempPy, tempLp, tempRp, tempFp, temp2Fp, tempFP, temp2FP, hub, temp2x, temp2y, keyRead, tempsw);
			endrule(sw, temp1moh, temp2moh, tg);
			movelimit(chx,chy);
			gotoxy(chx, chy);
		}
		clock(turnTime, temp1p, chx, chy, clockstart);
		if ((clock() - turnTime) >= 20000)
		{
			
			if (y == -1)
				timeP1 += 20000;
			if (y == 1)
				timeP2 += 20000;
			turnTime = clock();
			changeturn(tempsw, y, temp1p);
			tempsw =1;
			gotoxy(0, 11);
			teamturn(y, fplayer, splayer);
			gotoxy(15, 11);
			printf("Time is out!");
			gotoxy(chx, chy);
		}
	}
	lastsplash(sw, temp1moh, temp2moh, tg, fplayer, splayer);
}
