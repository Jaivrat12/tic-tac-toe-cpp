#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <process.h>

int n, x, y;
char ch;

int FixPos[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
char val[8];

void Play();
void Info();
void PvP();
void TicTacToeStruct(int, int);
void IndexedBlocks();
void CheckWin();

void MainMenu()
{
  clrscr();
  gotoxy(28, 5);
  cout << "=} TIC TAC TOE {=";
  gotoxy(32, 9);
  cout << "MAIN MENU (Press 1-3)";
  gotoxy(32, 11);
  cout << "1. Play\n";
  gotoxy(32, 12);
  cout << "2. Instructions\n";
  gotoxy(32, 13);
  cout << "3. Exit\n";
Input:
  ch = getche();
  switch (ch)
  {
  case '1':
    Play();
    break;
  case '2':
    Info();
    getch();
    MainMenu();
  case '3':
    exit(0);

  default:
    cout << "CHOOSE FROM 1-3 ONLY  >:(\n";
    goto Input;
  }
}

void Play()
{
Play:
  clrscr();
  gotoxy(32, 11);
  cout << "=} Play {=\n";
  gotoxy(32, 13);
  cout << "1. Player vs Player\n";
  gotoxy(32, 14);
  cout << "2. Player vs Computer\n";
  gotoxy(32, 15);
  cout << "3. Go Back to Main Menu\n";
Input1:
  ch = getche();
  switch (ch)
  {
  case '1':
    PvP();
    break;
  case '2':
    cout << "This Mode is Not Avaiable Right Now :(\n";
    getch();
    goto Play;
  case '3':
    MainMenu();

    // default: cout<<"CHOOSE FROM 1-3 ONLY  >:(\n";
    // goto Input1;
  }
  getch();
}

void Info()
{
  clrscr();
  gotoxy(30, 2);
  cout << "Instructions\n";
  TicTacToeStruct(80, -40);
  IndexedBlocks();
  gotoxy(1, 8);
  cout << "You have to enter(input) a number\neach time ranging from 1-9, these\nnumbers are assigned on the blocks\nas shown here in the figure: ";
  gotoxy(12, 14);
  cout << "RULES:";
  cout << "\n\nRules are simple...If you get your\nselected character{Cross(X) or\nZero(O)} 3 in a row vertically,\nhorizontally or diagonally, then,\nYou Win!";
}

void IndexedBlocks()
{
  int counter = 1;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      gotoxy(40 + j * 12, 7 + i * 6);
      cout << counter;
      counter++;
    }
  }
}

void TicTacToeStruct(int x, int y)
{
  line(300 + x, 100 + y, 300 + x, 400 + y);
  line(400 + x, 100 + y, 400 + x, 400 + y);
  line(200 + x, 200 + y, 500 + x, 200 + y);
  line(200 + x, 300 + y, 500 + x, 300 + y);
}

void DrawCross(int x, int y)
{
  line(220 + x, 120 + y, 280 + x, 180 + y);
  line(280 + x, 120 + y, 220 + x, 180 + y);
}

void DrawCircle(int x, int y)
{
  circle(250 + x, 150 + y, 40);
}

int Turn()
{
Start:
  cout << "Choose from 1-9: ";
  cin >> n;
  switch (n)
  {
  case 1:
    x = 0;
    y = 0;
    break;
  case 2:
    x = 100;
    y = 0;
    break;
  case 3:
    x = 200;
    y = 0;
    break;
  case 4:
    x = 0;
    y = 100;
    break;
  case 5:
    x = 100;
    y = 100;
    break;
  case 6:
    x = 200;
    y = 100;
    break;
  case 7:
    x = 0;
    y = 200;
    break;
  case 8:
    x = 100;
    y = 200;
    break;
  case 9:
    x = 200;
    y = 200;
    break;
  default:
    cout << "CHOOSE BETWEEN 1-9 ONLY   >:(\n";
  }
  if (n > 9)
  {
    goto Start;
  }
  if (FixPos[n - 1] == 1)
  {
    cout << "This Position is already assigned!!!";
    goto Start;
  }
  return n;
}

void Turn_X()
{
  int posX;
  cout << "Cross'(X) Turn:\n";
  posX = Turn() - 1;
  DrawCross(x, y);
  FixPos[posX] = 1;
  val[posX] = 'X';
  CheckWin();
}

void Turn_O()
{
  int posO;
  cout << "O's(o) Turn:\n";
  posO = Turn() - 1;
  DrawCircle(x, y);
  FixPos[posO] = 1;
  val[posO] = 'O';
  CheckWin();
}

void CheckWin()
{
  if (val[0] == val[1] == val[2] == 'X' || val[3] == val[4] == val[5] == 'X' || val[6] == val[7] == val[8] == 'X' || val[0] == val[3] == val[6] == 'X' || val[1] == val[4] == val[7] == 'X' || val[2] == val[5] == val[8] == 'X' || val[0] == val[4] == val[8] == 'X' || val[2] == val[4] == val[6] == 'X')
  {
    cout << "X Wins!!!";
    getch();
    MainMenu();
  }
  else if (val[0] == val[1] == val[2] == 'O' || val[3] == val[4] == val[5] == 'O' || val[6] == val[7] == val[8] == 'O' || val[0] == val[3] == val[6] == 'O' || val[1] == val[4] == val[7] == 'O' || val[2] == val[5] == val[8] == 'O' || val[0] == val[4] == val[8] == 'O' || val[2] == val[4] == val[6] == 'O')
  {
    cout << "O Wins!!!";
    getch();
    MainMenu();
  }
}

void PvP()
{
  clrscr();
  int XsTurn = 1;
  TicTacToeStruct(0, 0);
  for (int i = 0; i < 9; i++)
  {
    if (XsTurn == 1)
    {
      Turn_X();
    }
    else
    {
      Turn_O();
    }
    XsTurn = !XsTurn;
  }
  for (i = 0; i <= 8; i++)
  {
    cout << val[i];
  }
}

int main()
{
  clrscr();
  int gdriver = DETECT, gmode;
  initgraph(&gdriver, &gmode, "C://turboc3//bgi");
  MainMenu();
  getch();
  closegraph();
  return 0;
}