#include<stdio.h>
#include<conio.h>
#include<ctime>
#include <stdlib.h>
#include <windows.h>
#include"moverule.h"
#include"tools.h"
#include"pages.h"


void firstpress(int &tempsw, int &y, int &temp1x, int &temp1y, int &chx, int &chy, int &tempPx, int &tempPy, char &temp1moh, int hub[][10], char &temp1p, char &tempLp, char &tempRp, char &temp2Fp, char &tempFp, char &tempFP, char &temp2FP)
{
	if (tempsw == 1)
	{
		temp1x = chy;
		temp1y = chx / 2;
		tempPx = chx;
		tempPy = chy;
		temp1moh = hub[chy][chx / 2];
		temp1p = temp1moh;
		tempLp = hub[chy + 1][(chx / 2) - 1];
		tempRp = hub[chy + 1][(chx / 2) + 1];
		tempFp = hub[chy + 1][(chx / 2)];
		temp2Fp = hub[chy + 2][(chx / 2)];
		tempFP = hub[chy - 1][chx / 2];
		temp2FP = hub[chy - 2][chx / 2];
		if (int(temp1moh) > 96 && y == -1)
			tempsw = tempsw*(-1);
		if (int(temp1moh) < 94 && y == 1)
			tempsw = tempsw*(-1);
	}
}

void secendpress(char &temp1mohS, int &tempQ, int &keyRead, int &tempKN, int &tempbish, int & tempR1, char &temp2moh, int &temp2y, int &temp2x, int &tempK, char splayer[], char fplayer[], int &tempsw, int &y, int &temp1x, int &temp1y, int &chx, int &chy, int &tempPx, int &tempPy, char &temp1moh, int hub[][10], char &temp1p, char &tempLp, char &tempRp, char &temp2Fp, char &tempFp, char &tempFP, char &temp2FP, int &firstpoint, int &secondpoint, long int &turnTime, long int &timeP,  long int timeP1, long int timeP2)
{
	if (tempsw == (-1))
	{
		
			temp2x = chy;
			temp2y = chx / 2;
			temp2moh = hub[temp2x][temp2y];
			// ghanon--ejaze nemide mohre khodi ro bezanim!!
			if (temp1moh <= 94 && temp2moh <= 94)
				return;
			if (temp1moh >= 98 && temp2moh >= 98)
				return;
			nrule(temp1p, chx, chy, tempPx, tempPy, keyRead, tempKN);
			if (tempKN == 0)
				return;
			Brule(temp1p, chx, chy, tempPx, tempPy, keyRead, tempbish, hub);
			if (tempbish == 0)
				return;
			R1rule(temp1p, chx, chy, tempPx, tempPy, keyRead, tempKN, tempR1, hub);
			if (tempR1 == 0)
				return;
			tempQ = Qrule(temp1p, chx, chy, tempPx, tempPy, keyRead, hub);
			if (tempQ == 0)
				return;
			krule(temp1p, chx, chy, tempPx, tempPy, tempK, hub);
			if (tempK == 0)
				return;
			hub[chy][chx / 2] = temp1moh;
			temp1mohS = temp1moh;
			hub[temp1x][temp1y] = '_';
			changeturn(tempsw, y, temp1p);
			timeP += clock() - turnTime;
			turnTime = clock();
			clrscr();
			safhe(hub, fplayer, splayer);
			teamturn(y, fplayer, splayer);
			menu();
			point(firstpoint,secondpoint,temp2moh,fplayer,splayer,chx,chy,timeP1,timeP2);
		}
}

void wrongpress(int &chy, int &chx, int &y)
{
	if (int(chy) >= 2 && int(chy) < 6)
	{
		chy = 1;
		y = -1;
		gotoxy(0, 23);
		printf("ARE U KIDDING ME?! :| F player starts!! we choose number' %d P'for you! dont press p again for choose it! just go to a free hub and press p!", chx - (chx / 2));
	}
}