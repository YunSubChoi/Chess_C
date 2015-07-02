void gotoxy(int x, int y);
void setTextColore(int textColor, int backColor);
void clrscr();
void sleep(unsigned int mseconds);
void keyread(int &chx, int &chy, int &keyRead, int &sw, int &firstmove, int &y, char charRead1, char charRead2);
void changeturn(int &tempsw, int &y, char &temp1p);
void movekey(int charRead2, int &chx, int &chy, int keyRead);
void save(int arr[][10], char saveList[][10], int &saveCounter);