// Projekt ASCII.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include "iostream"
#include <conio.h>
#include "windows.h"
#include <math.h>


using namespace std;

//*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//
void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int wherex()
{

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.X;
}

int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.Y;
}
const int GORA = 72, DOL = 80, LEWO = 75, PRAWO = 77;


void Wstep();
void WczytanieDanych	(float &size, char &znak);
void Rysuj	(float &size, int &x, int &y, char &znak);
void Przesuwanie	(float size, float &x, float &y, char znak);



//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void Wstep()
{
	cout << "\t=========================================================== \n"
		"\t========== Program rysowania figury znakiem ASCII ========= \n"
		"\t=========================================================== \n"
		"\t========================  FIGURA  ========================= \n"
		"\t=========================================================== \n"
		"\t======================  x       x  ======================== \n"
		"\t======================  x x   x x   =======================  \n"
		"\t======================  x   x   x  ========================  \n"
		"\t======================  x       x  ========================  \n"
		"\t======================  x       x  ======================== \n"
		"\t=========================================================== \n"
		"\t==================== Program umozliwia: =================== \n"
		"\t== wybor znaku kodu ASCII ================================= \n"
		"\t== wczytanie poczatkowych rozmiarow figury ================ \n"
		"\t== przesuwanie firury klawiszami strzalek ================= \n"
		"\t== powiekszanie oraz zmianiszanie figury za pomoca + i - == \n"
		"\t== ograniczenie przesuwania figury do rozmiaru ekranu ===== \n"
		"\t=========================================================== \n"
		"\t====== Wcisnij dowolny klawisz aby rozpoczac program ====== \n"
		"\t=========================================================== " << endl;

	cout << " autor: Marcin Dymek" << endl;
	cout << " numer programu: 78, numer indeksu s15661" << endl << endl << endl;
	_getch();

}



//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void WczytanieDanych(float &size, char &znak)
{
	system("cls");
	int max = 22, min = 5, rozmiar;

	do
	{
		cout << "Ppodaj rozmiar figury w przedziale od 5 do 22: " << endl;
			cin >> rozmiar;

	} while (rozmiar < min || rozmiar > max);
		size = rozmiar;

		cout << "Podaj znak kodu ASCII z klawiatury: " << endl;
			cin >> znak;
			
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void Rysuj(float size, int &x, int &y, char znak)
{
	float i, j;
	int k;

	system("cls");

	for (i = x, j = y, k = 0; k < size; i--, k++)
	{
		gotoxy(i, j), cout << znak;
	}

	for (i = x, j = y, k = 0; k < (size / 2); i++, j++, k++)
	{
		gotoxy(i, j), cout << znak;
	}

	for (i = x + (size / 2), j = y + (size / 2), k = 0; k < (size / 2); i++, j++, k++)
	{
		gotoxy(i, j), cout << znak;
	}

	for (i = x, j = (y + size) - 1, k = 0; k < size; i++, k++)
	{
		gotoxy(i, j), cout << znak;
	}
	gotoxy(10, 25), cout << "strzalki: przesuwanie; +/-: powieksz, zmniejsz; ESC: wyjscie";
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void Przesuwanie(float size, int &x, int &y, char znak) // przesuwanie figury klawiszami strza³ek
{
	int zmiana = 0, max = 23;
	char klawisz;

	do
	{
		klawisz = _getch();

		switch (klawisz)
		{
		case GORA:
		{
			y--; zmiana = 1;
			if (y < 1)
			{
				y++;
				zmiana = 0;
			}
			break;
		}

		case DOL:
		{
			y++; zmiana = 1;
			if (y > max - (size - 2))
			{
				y--;
				zmiana = 0;
			}
			break;
		}
		case LEWO:
		{
			x--; zmiana = 1;
			if (x < 1)
			{
				x++;
				zmiana = 0;
			}
			break;
		}
		case PRAWO:
		{
			x++; zmiana = 1;
			if (x > 80 - size)
			{
				x--;
				zmiana = 0;
			}
			break;
		}
		case '+':
		{
			size++; zmiana = 1;
			if (size < 5 || size > max)
			{
				size--; y--;
				zmiana = 0;
			}
			break;
		}

		case '-':
		{
			size--;
			zmiana = 1;
			if (size < 5 || size > max)
			{
				size++;
				zmiana = 0;
			}
			break;
		}

		}

		if (zmiana)
		{
			Rysuj(size, &x, &y, znak); zmiana = 0;
		}

	} while (klawisz != 27);

}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

int main()

{
	system("cls");
	float size,
	char znak;
	int rozmiar, x, y;
		
	Wstep();
	WczytanieDanych(size, znak);
	Rysuj(size, x, y, znak);
	_getch();
	Przesuwanie(size, x, y, znak);

	system("pause");

	return 0;

}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//