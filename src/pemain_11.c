#include "pemain_11.h"
#include "tampilan_11.h"
#include "mesinkata_11.h"
#include "boolean_11.h"
#include "load_11.h"
#include "strings_11.h"
#include <stdio.h>
#include <conio.h>

Pemain Player;
ArrayTingkat A;
int LvLama;
Queue StarterQ;
char skip;
Stack S;
bool pass;

void LoadArrayTingkat (ArrayTingkat * A)
{
	int i=1;
	Tingkat CTingkat;
	
	STARTKATA(5);
	while (!EndKata)
	{
		CTingkat.NoTingkat = strtoval(CKata);
		ADVKATA();
		CTingkat.minEXP = strtoval(CKata);
		ADVKATA();
		if (!EndKata)
		{
			ADVKATA();
		}
		else
		{
			CTingkat.NoTingkat = strtoval(CKata);
			ADVKATA();
			CTingkat.minEXP = strtoval(CKata);
			ADVKATA();
		}
		Tab(*A)[i]=CTingkat;
		i++;
	}
	Neff(*A) = i-1;
}

void AssignLevel()
{
	bool found = false;
	int i=1; int prec=0;
	
	while ((!found) && (i<=Neff(A)))
	{
		if (EXPPemain(Player) < MinEXP(A,i))
		{
			found = true;
			LevelPemain(Player) = Tab(A)[prec].NoTingkat;
		}
		else
		{
			prec++;
			i++;
		}
	}
}

void PrintArray()
{
	int i = 1;
	for (i=1; i<=Neff(A); i++)
	{
		printf("%d\n",MinEXP(A,i));
	}
}

bool IsLevelUp()
{
	bool found = false;
	
	return LevelPemain(Player) > LvLama;
}

void AskIdentity()
{
	printf("> Hi! Sorry to keep you waiting\n");
	skip = getch();
	printf("> Welcome to the world of Pokemon!\n");
	skip = getch();
	printf("> My name is Birch,\n");
	printf("> But everyone calls me the Pokemon Professor.\n");
	skip = getch();
	printf("> This world is widely inhabited by creatures known as Pokemon.\n");
	skip = getch();
	printf("> We humans live alongside Pokemon at times as friendly playmates, and at times as cooperative workmates.\n");
	skip = getch();
	printf("> And sometimes, we band together and battle others like us.\n");
	skip = getch();
	printf("> But despite our closeness, we don't know everything about Pokemon.\n");
	skip = getch();
	printf("> In fact, there are many, many secrets surrounding Pokemon.\n");
	skip = getch();
	printf("> To unravel Pokemon mysteries, I've been undertaking research.\n");
	printf("> That's what I do.\n");
	skip = getch();
	printf("> And you are...\n");
	printf("> What's your name?\n");
	do
	{
		printf("> ");
		scanKata(&NamaPemain(Player));
		if (NamaPemain(Player).Length == 0)
		{
			printf("> I'm sorry, what is your name again?\n");
		}
	} while (NamaPemain(Player).Length == 0);
	printf("> So, it's "); printKata(NamaPemain(Player)); printf("\n");
	printf("> Ah, okay! You're "); printKata(NamaPemain(Player)); printf(" who's moving to my hometown of LITTLEROOT\n");
	printf("> I get it now.\n");
	skip = getch();
	system("cls");
	printf("> All right, are you ready?\n");
	printf("> Your very own adventure is about to unfold.\n");
	printf("> Take courage, and leap into the world of Pokemon where dreams, adventure, and friendship await!\n");
	printf("> Now, choose your own starter!\n");
	do
	{
		pass = false;
		InfoPokemon();
		printf("> Do you choose this Pokemon? (Y/N)\n");
		do
		{
			skip = getch();
			if ((skip == 'Y') || (skip == 'y'))
			{
				Push(&S,InfoHead(StarterQ));
				pass = true;
			}
			else if ((skip == 'N') || (skip == 'n'))
			{
				SwitchTurn(&StarterQ);
				pass = true;
			}
			else
			{
				printf("> Wrong input! Consider retyping your command\n");
			}
		} while (!pass);
	}
	while ((skip!='Y') && (skip!='y'));
	printf("> So, "); printKata(NamaPemain(Player));
	printf(". I'd like you to have the Pokemon you chose earlier.\n");
	printf("> "); printKata(NamaPemain(Player)); printf(" received the "); printKata(InfoTop(S).nama); printf("\n");
	printf("> If you work hard, you will become a good Pokemon trainer!\n");
}

void LoadGame();