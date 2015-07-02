//Highscore 0
//SaveoLoad 90
#include<stdio.h>
#include<conio.h>
#include<ctime>
#include <stdlib.h>
#include <windows.h>
#include"moverule.h"
#include"tools.h"
#include"pressP.h"""
//++++++++++ Move Rule
void Prule(char &temp1p, int &temp1x, int temp1y, int &chx, int &chy, int &tempPx, int &tempPy, char tempLp, char tempRp, char tempFp, char temp2Fp, char tempFP, char temp2FP, int arr[][10], int temp2x, int temp2y, int keyRead, int tempsw)
{
	//ghanun-baraye avalin harekat har sarbaz az khne khodesh k nahayatan mitone dota khune b samt jolo bere
	if (temp1p == 'p' && temp1x == 1)
	{
		if (chy > 3)
			chy--;
	}
	if (temp1p == 'P' && temp1x == 6)
	{
		if (chy < 4)
			chy++;
	}
	//ghanun-mohreye p ejaze ja b ja shodan darmehvar x haro nadare baraye zadan mohere tempswP tarif ikonam
	if (temp1p == 'p' || temp1p == 'P')
	{
		if (chx > tempPx)
		{
			chx = chx - 2;
			//	tempsw = -1;
		}
		if (chx < tempPx)
		{
			chx = chx + 2;
			//	tempsw = -1;
		}

	}
	//ghanun-sarbaz p agar harekat avalesh nabashe nemitune bishtar az ye khune jabeja beshe
	if (temp1p == 'p')
	{
		if (temp1x != 1)
		{
			if (chy > tempPy + 1)
				chy--;
			if (chy < tempPy)
				chy++;
		}

	}
	if (temp1p == 'P')
	{
		if (temp1x != 6)
		{
			if (chy < tempPy - 1)
				chy++;
			if (chy > tempPy)
				chy--;
		}

	}


}

void nrule(char &temp1p, int &chx, int &chy, int &tempPx, int &tempPy, int keyRead, int &tempKN)
{
	if (temp1p == 'n' || temp1p == 'N')
	{
		if ((chx == tempPx + 2 && chy == tempPy + 2) || (chx == tempPx - 2 && chy == tempPy + 2) || (chx == tempPx + 2 && chy == tempPy - 2) || (chx == tempPx - 2 && chy == tempPy - 2) || (chx == tempPx + 4 && chy == tempPy + 1) || (chx == tempPx + 4 && chy == tempPy - 1) || (chx == tempPx - 4 && chy == tempPy + 1) || (chx == tempPx - 4 && chy == tempPy - 1))
			tempKN = 1;
		else
		{
			tempKN = 0;

			for (int i = 0; i < 5; i++)
			{
				setTextColore(4, 0);
				gotoxy(33, 10);
				printf("Wrong move!! Knight just can move in 'L' shape");
				sleep(80);
				setTextColore(7, 5);
				gotoxy(33, 10);
				printf("Wrong move!! Knight just can move in 'L' shape");
				sleep(80);
			}
		}


	}

}

void R1rule(char &temp1p, int &chx, int &chy, int &tempPx, int &tempPy, int keyRead, int &tempKN, int &tempR1, int arr[][10])
{
	int i = 0, j = 0;
	int chu;
	if (temp1p == 'r')
	{
		if (chy > tempPy)
		{
			do
			{
				j++;
				if (chx > tempPx)
				{
					chx = tempPx;
				}
				if (chx < tempPx)
				{
					chx = tempPx;
				}
				if (arr[tempPy + j][tempPx / 2] == '_')
				{
					tempR1 = 1;
				}
				if (arr[tempPy + j][tempPx / 2] != '_' && arr[tempPy + j][tempPx / 2] < 94)
				{
					tempR1 = 1;
					chy = tempPy + j;
					break;

				}
				if (arr[tempPy + j][tempPx / 2] > 95)
				{
					tempR1 = 0;
					break;
				}

			} while ((tempPy + j) != chy);
		}
		else if (chy < tempPy)
		{
			do
			{
				j++;
				if (chx > tempPx)
				{
					chx = tempPx;
				}
				if (chx < tempPx)
				{
					chx = tempPx;
				}
				if (arr[tempPy - j][tempPx / 2] == '_')
				{
					tempR1 = 1;
				}
				if (arr[tempPy - j][tempPx / 2] != '_' && arr[tempPy - j][tempPx / 2] < 94)
				{
					tempR1 = 1;
					chy = tempPy - j;
					break;
				}
				if (arr[tempPy - j][tempPx / 2] > 95)
				{
					tempR1 = 0;
					break;
				}

			} while ((tempPy - j) != chy);
		}
		else if (chx > tempPx)
		{
			do
			{
				i += 2;
				if (chy > tempPy)
				{
					chy = tempPy;
				}
				if (chy < tempPy)
				{
					chy = tempPy;
				}
				if (arr[tempPy][(tempPx + i) / 2] == '_')
				{
					tempR1 = 1;
				}
				if (arr[tempPy][(tempPx + i) / 2] != '_' && arr[tempPy][(tempPx + i) / 2] < 94)
				{
					tempR1 = 1;
					chx = (tempPx)+i;
					break;
				}
				if (arr[tempPy][(tempPx + i) / 2] > 95)
				{
					tempR1 = 0;
					break;
				}

			} while (tempPx + i != chx);

		}
		else if (chx < tempPx)
		{
			do
			{
				i += 2;
				if (chy > tempPy)
				{
					chy = tempPy;
				}
				if (chy < tempPy)
				{
					chy = tempPy;
				}
				if (arr[tempPy][(tempPx - i) / 2] == '_')
				{
					tempR1 = 1;
				}
				if (arr[tempPy][(tempPx - i) / 2] != '_' &&arr[tempPy][(tempPx - i) / 2] < 94)
				{
					tempR1 = 1;
					chx = (tempPx)-i;
					break;
				}
				if (arr[tempPy][(tempPx - i) / 2] > 95)
				{
					tempR1 = 0;
					break;
				}

			} while (tempPx - i != chx);

		}
	}
	if (temp1p == 'R')
	{
		if (chy > tempPy)
		{
			do
			{
				j++;
				if (chx > tempPx)
				{
					chx = tempPx;
				}
				if (chx < tempPx)
				{
					chx = tempPx;
				}
				if (arr[tempPy + j][tempPx / 2] == '_')
				{
					tempR1 = 1;
				}
				if (arr[tempPy + j][tempPx / 2] != '_' && arr[tempPy + j][tempPx / 2] > 95)
				{
					tempR1 = 1;
					chy = tempPy + j;
					break;
				}
				if (arr[tempPy + j][tempPx / 2] < 94)
				{
					tempR1 = 0;
					break;
				}

			} while ((tempPy + j) != chy);
		}
		else if (chy < tempPy)
		{
			do
			{
				j++;
				if (chx > tempPx)
				{
					chx = tempPx;
				}
				if (chx < tempPx)
				{
					chx = tempPx;
				}
				if (arr[tempPy - j][tempPx / 2] == '_')
				{
					tempR1 = 1;
				}
				if (arr[tempPy - j][tempPx / 2] != '_' && arr[tempPy - j][tempPx / 2] > 95)
				{
					tempR1 = 1;
					chy = tempPy - j;
					break;
				}
				if (arr[tempPy - j][tempPx / 2] <94)
				{
					tempR1 = 0;
					break;
				}

			} while ((tempPy - j) != chy);
		}
		if (chx > tempPx)
		{
			do
			{
				i += 2;
				if (chy > tempPy)
				{
					chy = tempPy;
				}
				if (chy < tempPy)
				{
					chy = tempPy;
				}
				if (arr[tempPy][(tempPx + i) / 2] == '_')
				{
					tempR1 = 1;
				}
				if (arr[tempPy][(tempPx + i) / 2] != '_' &&arr[tempPy][(tempPx + i) / 2] >95)
				{
					tempR1 = 1;
					chx = (tempPx)+i;
					break;
				}
				if (arr[tempPy][(tempPx + i) / 2] < 94)
				{
					chu = arr[tempPy][(tempPx + i) / 2];
					tempR1 = 0;
					break;
				}

			} while (tempPx + i != chx);

		}
		else if (chx < tempPx)
		{
			do
			{
				i += 2;
				if (chy > tempPy)
				{
					chy = tempPy;
				}
				if (chy < tempPy)
				{
					chy = tempPy;
				}
				if (arr[tempPy][(tempPx - i) / 2] == '_')
				{
					tempR1 = 1;
				}
				if (arr[tempPy][(tempPx - i) / 2] != '_' &&arr[tempPy][(tempPx - i) / 2] > 95)
				{
					tempR1 = 1;
					chx = tempPx - i;
					break;
				}
				if (arr[tempPy][(tempPx - i) / 2] < 94)
				{
					tempR1 = 0;
					break;
				}

			} while (tempPx - i != chx);

		}
	}
}

void Brule(char &temp1p, int &chx, int &chy, int &tempPx, int &tempPy, int keyRead, int &tempbish, int arr[][10])
{
	int chxb, tempxb, i = 1;
	char chu;
	chxb = (chx / 2);
	tempxb = (tempPx / 2);
	if (temp1p == 'b')
	{
		if (abs(chxb - tempxb) != (abs(chy - tempPy)))
		{
			tempbish = 0;
		}

		if (abs(chxb - tempxb) == (abs(chy - tempPy)))
		{
			while ((tempPy + i) != chy && tempPy<chy)
			{
				if (chy > tempPy)
				{
					if (chx > tempPx)
					{
						if (arr[tempPy + i][(tempPx / 2) + i] != '_' && int(arr[tempPy + i][(tempPx / 2) + i]) > 94)
						{
							tempbish = 0;
							break;
						}
						if (arr[tempPy + i][(tempPx / 2) + i] != '_' && int(arr[tempPy + i][(tempPx / 2) + i]) < 94)
						{
							tempbish = 1;
							chy = tempPy + i;
							chx = tempPx + 2 * i;
							break;
						}

						if (arr[tempPy + i][(tempPx / 2) + i] == '_')
							tempbish = 1;

					}
					if (chx < tempPx)
					{
						if (arr[tempPy + i][(tempPx / 2) - i] != '_'&& int(arr[tempPy + i][(tempPx / 2) - i]) > 94)
						{
							//chu = arr[tempPy + i][(tempPx / 2) - i];
							tempbish = 0;
							break;
						}
						if (arr[tempPy + i][(tempPx / 2) - i] != '_' && int(arr[tempPy + i][(tempPx / 2) - i]) < 94)
						{
							tempbish = 1;
							chy = tempPy + i;
							chx = tempPx - 2 * i;
							break;
						}
						if (arr[tempPy + i][(tempPx / 2) - i] == '_')
							tempbish = 1;
					}
				}
				i++;
			}
			while ((tempPy - i) != chy && tempPy>chy)
			{
				if (chy < tempPy)
				{
					if (chx > tempPx)
					{
						if (arr[tempPy - i][(tempPx / 2) + i] != '_'&& int(arr[tempPy - i][(tempPx / 2) + i])>94)
						{
							chu = arr[tempPy - i][(tempPx / 2) + i];
							tempbish = 0;
							break;
						}
						if (arr[tempPy - i][(tempPx / 2) + i] != '_' && int(arr[tempPy - i][(tempPx / 2) + i])<94)
						{
							tempbish = 1;
							chy = tempPy + i;
							chx = tempPx + 2 * i;
							break;
						}
						if (arr[tempPy - i][(tempPx / 2) + i] == '_')
							tempbish = 1;
					}
					if (chx < tempPx)
					{
						if (arr[tempPy - i][(tempPx / 2) - i] != '_'&& int(arr[tempPy - i][(tempPx / 2) - i])>94)
						{
							tempbish = 0;
							break;
						}
						if (arr[tempPy - i][(tempPx / 2) - i] != '_' && int(arr[tempPy - i][(tempPx / 2) - i])<94)
						{
							tempbish = 1;
							chy = tempPy - i;
							chx = tempPx - 2 * i;
							break;
						}
						if (arr[tempPy - i][(tempPx / 2) - i] == '_')
							tempbish = 1;
					}
				}

				i++;
			}
		}


	}
	if (temp1p == 'B')
	{
		if (abs(chxb - tempxb) != (abs(chy - tempPy)))
		{
			tempbish = 0;

		}

		if (abs(chxb - tempxb) == (abs(chy - tempPy)))
		{
			while ((tempPy + i) != chy && tempPy<chy)
			{
				if (chy > tempPy)
				{
					if (chx > tempPx)
					{
						if (arr[tempPy + i][(tempPx / 2) + i] != '_' && int(arr[tempPy + i][(tempPx / 2) + i]) < 94)
						{
							tempbish = 0;
							break;
						}
						if (arr[tempPy + i][(tempPx / 2) + i] != '_' && int(arr[tempPy + i][(tempPx / 2) + i]) > 96)
						{
							tempbish = 1;
							chy = tempPy + i;
							chx = tempPx + 2 * i;
							break;
						}

						if (arr[tempPy + i][(tempPx / 2) + i] == '_')
							tempbish = 1;

					}
					if (chx < tempPx)
					{
						if (arr[tempPy + i][(tempPx / 2) - i] != '_'&& int(arr[tempPy + i][(tempPx / 2) - i]) < 94)
						{
							tempbish = 0;
							break;
						}
						if (arr[tempPy + i][(tempPx / 2) - i] != '_' && int(arr[tempPy + i][(tempPx / 2) - i]) > 96)
						{
							tempbish = 1;
							chy = tempPy + i;
							chx = tempPx - 2 * i;
							break;
						}
						if (arr[tempPy + i][(tempPx / 2) - i] == '_')
							tempbish = 1;
					}
				}
				i++;
			}
			while ((tempPy - i) != chy && tempPy>chy)
			{

				if (chy < tempPy)
				{
					if (chx > tempPx)
					{
						if (arr[tempPy - i][(tempPx / 2) + i] != '_'&& int(arr[tempPy - i][(tempPx / 2) + i])<94)
						{

							chu = arr[tempPy - i][(tempPx / 2) + i];
							tempbish = 0;
							break;
						}
						if (arr[tempPy - i][(tempPx / 2) + i] != '_' && int(arr[tempPy - i][(tempPx / 2) + i]>96))
						{
							tempbish = 1;
							chy = tempPy - i;
							chx = tempPx + 2 * i;

							break;
						}
						if (arr[tempPy - i][(tempPx / 2) + i] == '_')
							tempbish = 1;
					}
					if (chx < tempPx)
					{
						if (arr[tempPy - i][(tempPx / 2) - i] != '_'&& int(arr[tempPy - i][(tempPx / 2) - i])<94)
						{
							chu = arr[tempPy - i][(tempPx / 2) - i];
							tempbish = 0;
							break;
						}
						if (arr[tempPy - i][(tempPx / 2) - i] != '_' && int(arr[tempPy - i][(tempPx / 2) - i])>96)
						{
							tempbish = 1;
							chy = tempPy - i;
							chx = tempPx - 2 * i;
							break;
						}
						if (arr[tempPy - i][(tempPx / 2) - i] == '_')
							tempbish = 1;
					}
				}
				i++;
			}
		}
	}
}

int Qrule(char &temp1p, int &chx, int &chy, int &tempPx, int &tempPy, int keyRead, int arr[][10])
{
	if (temp1p == 'k' || temp1p == 'K')
	{
		if (chx > tempPx + 2 || chx < tempPx - 2 || chy> tempPy + 1 || chy < tempPy - 1)
			return(0);
		else
			return(1);

	}

}

void krule(char &temp1p, int &chx, int &chy, int &tempPx, int &tempPy, int &tempK, int arr[][10])
{
	int j = 1, ksw = 0;
	if (temp1p == 'q')
	{

		if (2 * abs(chy - tempPy) == abs(chx - tempPx))
		{
			while ((tempPy + j) != chy && tempPy < chy)
			{
				if (chy > tempPy)
				{
					if (chx > tempPx)
					{
						if (arr[tempPy + j][(tempPx / 2) + j] != '_' && int(arr[tempPy + j][(tempPx / 2) + j]) > 94)
						{
							tempK = 0;
							break;
						}
						if (arr[tempPy + j][(tempPx / 2) + j] != '_' && int(arr[tempPy + j][(tempPx / 2) + j]) < 94)
						{

							chy = tempPy + j;
							chx = tempPx + 2 * j;
							tempK = 1;
							ksw = 1;
							break;
						}

						if (arr[tempPy + j][(tempPx / 2) + j] == '_')
						{
							tempK = 1;
							ksw = 1;
						}


					}
					if (chx < tempPx)
					{
						if (arr[tempPy + j][(tempPx / 2) - j] != '_'&& int(arr[tempPy + j][(tempPx / 2) - j]) > 94)
						{
							//chu = arr[tempPy + i][(tempPx / 2) - i];
							tempK = 0;
							break;
						}
						if (arr[tempPy + j][(tempPx / 2) - j] != '_' && int(arr[tempPy + j][(tempPx / 2) - j]) < 94)
						{

							chy = tempPy + j;
							chx = tempPx - 2 * j;
							tempK = 1;
							ksw = 1;
							break;
						}
						if (arr[tempPy + j][(tempPx / 2) - j] == '_')
						{
							ksw = 1;
							tempK = 1;
						}
					}
				}
				j++;
			}
			while ((tempPy - j) != chy && tempPy > chy)
			{
				if (chy < tempPy)
				{
					if (chx > tempPx)
					{
						if (arr[tempPy - j][(tempPx / 2) + j] != '_'&& int(arr[tempPy - j][(tempPx / 2) + j]) > 94)
						{

							tempK = 0;
							break;
						}
						if (arr[tempPy - j][(tempPx / 2) + j] != '_' && int(arr[tempPy - j][(tempPx / 2) + j]) < 94)
						{
							chy = tempPy + j;
							chx = tempPx + 2 * j;
							tempK = 1;
							ksw = 1;
							break;
						}
						if (arr[tempPy - j][(tempPx / 2) + j] == '_')
						{
							tempK = 1;
							ksw = 1;
						}
					}
					if (chx < tempPx)
					{
						if (arr[tempPy - j][(tempPx / 2) - j] != '_'&& int(arr[tempPy - j][(tempPx / 2) - j]) > 94)
						{
							tempK = 0;
							break;
						}
						if (arr[tempPy - j][(tempPx / 2) - j] != '_' && int(arr[tempPy - j][(tempPx / 2) - j]) < 94)
						{

							chy = tempPy - j;
							chx = tempPx - 2 * j;
							tempK = 1;
							ksw = 1;
							break;
						}
						if (arr[tempPy - j][(tempPx / 2) - j] == '_')
						{
							tempK = 1;
							ksw = 1;
						}
					}
				}

				j++;

			}
		}
		if (2 * abs(chy - tempPy) != abs(chx - tempPx))
		{
			if (chy == tempPy)
			{
				if (chx > tempPx || chx < tempPx)
				{
					if (chx > tempPx)
					{
						for (int i = 2; (tempPx + i) != chx; i += 2)
						{
							if (arr[chy][(tempPx + i) / 2] < 94)
							{
								chx = tempPx + i;
								tempK = 1;
								ksw = 1;
								break;
							}
							if (arr[chy][(tempPx + i) / 2] > 95)
							{
								tempK = 0;
								break;
							}
							if (arr[chy][(tempPx + i) / 2] == '_')
							{
								tempK = 1;
								ksw = 1;
							}
						}
					}
					if (chx < tempPx)
					{
						for (int i = 2; (tempPx - i) != chx; i += 2)
						{
							if (arr[chy][(tempPx - i) / 2] < 94)
							{
								chx = tempPx - i;
								tempK = 1;
								ksw = 1;
								break;
							}
							if (arr[chy][(tempPx - i) / 2] > 95)
							{
								tempK = 0;
								break;
							}
							if (arr[chy][(tempPx - i) / 2] == '_')
							{
								tempK = 1;
								ksw = 1;
							}
						}
					}
				}
			}

			if (chx == tempPx)
			{
				if (chy > tempPy || chy < tempPy)
				{
					if (chy > tempPy)
					{
						for (int i = 1; (tempPy + i) != chy; i++)
						{
							if (arr[tempPy + i][tempPx / 2] < 94)
							{
								chy = tempPy + i;
								tempK = 1;
								ksw = 1;
								break;
							}
							if (arr[tempPy + i][tempPx / 2] > 95)
							{
								tempK = 0;
								break;
							}
							if (arr[tempPy + i][tempPx / 2] == '_')
							{
								tempK = 1;
								ksw = 1;
							}
						}
					}
					if (chy < tempPy)
					{
						for (int i = 1; (tempPy - i) != chy; i++)
						{
							if (arr[tempPy - i][tempPx / 2] < 94)
							{
								chy = tempPy - i;
								tempK = 1;
								ksw = 1;
								break;
							}
							if (arr[tempPy - i][tempPx / 2] > 95)
							{
								tempK = 0;
								break;
							}
							if (arr[tempPy - i][tempPx / 2] == '_')
							{
								tempK = 1;
								ksw = 1;
							}
						}
					}
				}
			}
		}
		if (ksw == 0)
		{
			tempK = 0;
		}
	}


	if (temp1p == 'Q')
	{
		if (2 * abs(chy - tempPy) == abs(chx - tempPx))
		{
			while ((tempPy + j) != chy && tempPy < chy)
			{
				if (chy > tempPy)
				{
					if (chx > tempPx)
					{
						if (arr[tempPy + j][(tempPx / 2) + j] != '_' && int(arr[tempPy + j][(tempPx / 2) + j]) < 94)
						{
							tempK = 0;
							break;
						}
						if (arr[tempPy + j][(tempPx / 2) + j] != '_' && int(arr[tempPy + j][(tempPx / 2) + j]) > 95)
						{

							chy = tempPy + j;
							chx = tempPx + 2 * j;
							ksw = 1;
							tempK = 1;
							break;
						}

						if (arr[tempPy + j][(tempPx / 2) + j] == '_')
						{
							tempK = 1;
							ksw = 1;
						}

					}
					if (chx < tempPx)
					{
						if (arr[tempPy + j][(tempPx / 2) - j] != '_'&& int(arr[tempPy + j][(tempPx / 2) - j]) < 94)
						{
							tempK = 0;
							break;
						}
						if (arr[tempPy + j][(tempPx / 2) - j] != '_' && int(arr[tempPy + j][(tempPx / 2) - j]) > 95)
						{

							chy = tempPy + j;
							chx = tempPx - 2 * j;
							ksw = 1;
							tempK = 1;
							break;
						}
						if (arr[tempPy + j][(tempPx / 2) - j] == '_')
						{
							tempK = 1;
							ksw = 1;
						}
					}
				}
				j++;
			}
			while ((tempPy - j) != chy && tempPy > chy)
			{
				if (chy < tempPy)
				{
					if (chx > tempPx)
					{
						if (arr[tempPy - j][(tempPx / 2) + j] != '_'&& int(arr[tempPy - j][(tempPx / 2) + j]) < 94)
						{

							tempK = 0;
							break;
						}
						if (arr[tempPy - j][(tempPx / 2) + j] != '_' && int(arr[tempPy - j][(tempPx / 2) + j]) > 95)
						{
							chy = tempPy + j;
							chx = tempPx + 2 * j;
							tempK = 1;
							ksw = 1;
							break;
						}
						if (arr[tempPy - j][(tempPx / 2) + j] == '_')
						{
							tempK = 1;
							ksw = 1;
						}
					}
					if (chx < tempPx)
					{
						if (arr[tempPy - j][(tempPx / 2) - j] != '_'&& int(arr[tempPy - j][(tempPx / 2) - j]) < 94)
						{
							tempK = 0;
							break;
						}
						if (arr[tempPy - j][(tempPx / 2) - j] != '_' && int(arr[tempPy - j][(tempPx / 2) - j]) > 95)
						{

							chy = tempPy - j;
							chx = tempPx - 2 * j;
							tempK = 1;
							ksw = 1;
							break;
						}
						if (arr[tempPy - j][(tempPx / 2) - j] == '_')
						{
							tempK = 1;
							ksw = 1;
						}
					}
				}

				j++;

			}
		}
		if (2 * abs(chy - tempPy) != abs(chx - tempPx))
		{
			if (chy == tempPy)
			{
				if (chx > tempPx || chx < tempPx)
				{
					if (chx > tempPx)
					{
						for (int i = 2; (tempPx + i) != chx; i += 2)
						{
							if (arr[chy][(tempPx + i) / 2] > 95)
							{
								chx = tempPx + i;
								tempK = 1;
								ksw = 1;
								break;
							}
							if (arr[chy][(tempPx + i) / 2] < 94)
							{
								tempK = 0;
								break;
							}
							if (arr[chy][(tempPx + i) / 2] == '_')
							{
								tempK = 1;
								ksw = 1;
							}
						}
					}
					if (chx < tempPx)
					{
						for (int i = 2; (tempPx - i) != chx; i += 2)
						{
							if (arr[chy][(tempPx - i) / 2] > 94)
							{
								chx = tempPx - i;
								tempK = 1;
								ksw = 1;
								break;
							}
							if (arr[chy][(tempPx - i) / 2] < 95)
							{
								tempK = 0;
								break;
							}
							if (arr[chy][(tempPx - i) / 2] == '_')
							{
								tempK = 1;
								ksw = 1;
							}
						}
					}
				}

			}
			if (chx == tempPx)
			{
				if (chy > tempPy || chy < tempPy)
				{
					if (chy > tempPy)
					{
						for (int i = 1; (tempPy + i) != chy; i++)
						{
							if (arr[tempPy + i][tempPx / 2] > 95)
							{
								chy = tempPy + i;
								tempK = 1;
								ksw = 1;
								break;
							}
							if (arr[tempPy + i][tempPx / 2] < 94)
							{
								tempK = 0;
								break;
							}
							if (arr[tempPy + i][tempPx / 2] == '_')
							{
								tempK = 1;
								ksw = 1;
							}
						}
					}
					if (chy < tempPy)
					{
						for (int i = 1; (tempPy - i) != chy; i++)
						{
							if (arr[tempPy - i][tempPx / 2] > 95)
							{
								chy = tempPy - i;
								tempK = 1;
								ksw = 1;
								break;
							}
							if (arr[tempPy - i][tempPx / 2] < 94)
							{
								tempK = 0;
								break;
							}
							if (arr[tempPy - i][tempPx / 2] == '_')
							{
								tempK = 1;
								ksw = 1;
							}

						}
					}
				}
			}
			if (ksw == 0)
			{
				tempK = 0;
			}
		}
	}
}

int endrule(int &sw, int temp1moh, int temp2moh, int tg)
{
	if (int(temp1moh) >= 75 && int(temp1moh) <= 82 && temp2moh == 'k')
	{
		sw += 2;
	}
	if (int(temp1moh) >= 98 && int(temp1moh) <= 116 && temp2moh == 'K')
	{
		sw += 2;
	}
	return(sw);
}

void movelimit(int &chx, int &chy)
{
	if (chx >= 17)
		chx -= 2;
	if (chy >= 8)
		chy--;
	if (chx < 0)
		chx += 2;
	if (chy < 0)
		chy++;
}

void firstpressmove(int &firstmove, int &chy, int &chx, int &y)
{
	while (firstmove == 0)
	{
		if (6 <= int(chy) && int(chy) < 9)
			y = 1;
		if (0 <= int(chy) && int(chy) < 2)
			y = -1;
		firstmove++;
		wrongpress(chy, chx, y);
	}
}