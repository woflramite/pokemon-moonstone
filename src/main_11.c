#include <stdio.h>
#include <conio.h>
#include <strings.h>
#include "load_11.h"
#include "init_11.h"
#include "tampilan_11.h"

Pemain Player;
Stack S;
Queue Q,StarterQ;
char key;
List ListToko,ListTas;
MATRIKS CurrentMap,Peta1,Peta2,Peta3,Peta4,MatchUp;
bool LoadBerhasil;
int i;
char dummy,command[50];

int main ()
{
	do
	{
		Load();
		system("cls");
		printf("> Choose \"Load File\" for demo edition!\n");
		MenuUtama();
		if (strcmp(command,"New Game") == 0)
		{
			Initialise();
			system("cls");
			AskIdentity();
			system("cls");
			PrintPeta(CurrentMap);
			do
			{
				MainMap();
			} while (!IsGameOver());
		}
		else if (strcmp(command,"Load Game") == 0)
		{
			
			system("cls");
			LoadPlayer();
			dummy = getch();
			system("cls");
			if (LoadBerhasil)
			{
				PrintPeta(CurrentMap);
				do
				{
					MainMap();
				} while (!IsGameOver()); 
			}
		}
		else if (strcmp(command,"Help") == 0)
		{
			system("cls");
			TampilBantuan();
			printf("> Press any key to continue\n");
			key = getch();
		}
		else if (strcmp(command,"About") == 0)
		{
			system("cls");
			TampilAbout();
			printf("> Press any key to continue\n");
			key = getch();
		}
		else if (strcmp(command,"Exit") == 0)
		{
			system("cls");
			printf("> Good bye!\n");
		}
	} while (strcmp(command,"Exit")!=0);
	return 0;
}