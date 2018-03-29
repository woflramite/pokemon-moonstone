#include "encounter_11.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <time.h>
#include <conio.h>
#include "load_11.h"
#include "strings_11.h"
#include "tampilan_11.h"

Pemain Player;
Stack S;
Queue Q;
char key;
List ListToko,ListTas;
MATRIKS Peta1,Peta2,Peta3,Peta4,MatchUp,CurrentMap;
Pokedex WildPoke;
addressList PRef;
addressList P;
bool tangkap=false;
bool kabur=false;
int LvLama;
MATRIKS Matchup;


int RandomRange(int batasatas, int batasbawah)
{	
	srand(time(NULL));
	return ((rand() % (batasatas - batasbawah + 1)) + batasbawah);	
}

void Attack(Pokedex P1, Pokedex *P2)
{
	int attack; char dummy;
	attack = RandomRange(P1.atasattack, P1.bawahattack) * MatchUp.Mem[(*P2).tipe][P1.tipe];
	
	printf("> ");
	printKata(P1.nama);
	printf(" used Attack!\n");
	if (MatchUp.Mem[(*P2).tipe][P1.tipe] == 2)
	{
		printf("> It's super effective\n");
	}
	else if (MatchUp.Mem[(*P2).tipe][P1.tipe] == 0.5)
	{
		printf("> It's not very effective\n");
	}
	if (attack > 0.8*P1.atasattack*MatchUp.Mem[(*P2).tipe][P1.tipe])
	{
		printf("> It's critical hit\n");
	}
	(*P2).HP = (*P2).HP - attack;
	dummy = getch();
	if ((*P2).HP<=0)
	{
		(*P2).HP = 0;
	}
	TampilBattle();
	dummy = getch();
}

void InBattle()
{
	
	bool win;
	bool pass=false;
	infotype X;
	char battlecommand[50];
	long ObtainedEXP;
	long ObtainedMoney;
	
	
	system("cls");
	win = false;
	WildPoke = InfoHead(Q);
	printf("> Wild ");
	printKata(WildPoke.nama);
	printf(" appeared\n");
	printf("> Go, ");
	printKata(InfoTop(S).nama);
	printf("!\n");
	key=getch();
	do 
	{
		kabur = false;
		tangkap = false;
		system("cls");
		TampilBattle();
		printf("\n");
		printf("> What should "); printKata(InfoTop(S).nama); printf(" do?\n");
		printf("> Fight\n");
		printf("> Bag\n");
		printf("> Run\n");
		printf("\n");
		do
		{
			printf("> ");
			fgets(battlecommand, 50, stdin);
			if ((strlen(battlecommand)>0) && (battlecommand[strlen(battlecommand) - 1] == '\n')) battlecommand[strlen(battlecommand)-1] = 0;
			if ((strcmp(battlecommand,"Fight") == 0) || (strcmp(battlecommand,"Bag") == 0) || (strcmp(battlecommand,"Run") == 0))
			{
				pass = true;
			}
			else
			{
				printf("> Wrong input! Repeat!\n");
			}
		} while (!pass);
		
		if (strcmp(battlecommand,"Fight") == 0)
		{
			Attack(InfoTop(S),&WildPoke);
			if (WildPoke.HP > 0)
			{
				Attack(WildPoke,&InfoTop(S));
				if (InfoTop(S).HP <= 0)
				{
					InfoTop(S).HP = 0;
					printf("> ");
					printKata(InfoTop(S).nama);
					printf(" fainted. ");
					Pop(&S,&X);
					if (!IsStackEmpty(S))
					{
						printKata(InfoTop(S).nama);
						printf(" Go for it!\n");
					}
					else
					{
						printf("\n> "); printKata(NamaPemain(Player));
						printf(" ran out of Pokemon. "); printKata(NamaPemain(Player));
						printf(" was whited out!\n");
						key = getch();
					}
				}
			}
			else if (WildPoke.HP <= 0)
			{
				WildPoke.HP = 0;
				win = true;
				ObtainedEXP = RandomRange(WildPoke.bawahexp, WildPoke.atasexp);
				ObtainedMoney = RandomRange(WildPoke.bawahmoney, WildPoke.atasmoney);
				printf("> "); printKata(WildPoke.nama);
				printf(" fainted. Obtained %d EXP and %d Pokedollar\n",ObtainedEXP,ObtainedMoney);
				EXPPemain(Player)+=ObtainedEXP;
				UangPemain(Player)+=ObtainedMoney;
				key = getch();
				LvLama = LevelPemain(Player);
				AssignLevel();
				if (IsLevelUp())
				{
					printf("> ");
					printKata(NamaPemain(Player));
					printf(" reached level %d\n",LevelPemain(Player));
					key = getch();
				}
			}
			SwitchTurn(&Q);
		}
		else if (strcmp(battlecommand,"Bag")==0)
		{
			UseItem();
		}
		else if (strcmp(battlecommand,"Run")==0)
		{	
			Kabur();
		}
	} while (!win && (!IsStackEmpty(S)) && !kabur && !tangkap);
}

void UseItem()
{
	bool pass=false;
	Kata Pokeball,Potion;
	Katacpy(&Pokeball,"pokeball");
	Katacpy(&Potion,"potion");
	infotypeList ItemX;
	char NamaItem[50];
	
	system("cls");
	TampilTas();
	printf("\n");
	pass = false;
	do
	{
		printf("> Which item would you choose?\n");
		printf("> ");
		fgets(NamaItem, 50, stdin);
		if ((strlen(NamaItem)>0) && (NamaItem[strlen(NamaItem) - 1] == '\n')) NamaItem[strlen(NamaItem)-1] = 0;
		Katacpy(&NamaItem(ItemX),NamaItem);
		if (IsExisted(ListTas,ItemX))
		{
			PRef = Search(ListTas,ItemX);
			if (Katacmp(JenisInfo(PRef),Pokeball) == 0)
			{
				Tangkap();
				JumlahInfo(PRef)--;
				if (JumlahInfo(PRef) == 0)
				{
					DeleteP(&ListTas,Info(PRef));
				}
			}
			else if (Katacmp(JenisInfo(PRef),Potion) == 0)
			{
				if (InfoTop(S).HP < InfoTop(S).HPMax)
				{
					if (InfoTop(S).HP+EfekInfo(PRef) <= InfoTop(S).HPMax)
					{
						InfoTop(S).HP+=EfekInfo(PRef);
						printf("> ");
						printKata(InfoTop(S).nama);
						printf("'s HP was restored by %d points\n",EfekInfo(PRef));
						key = getch();
					}
					else
					{
						printf("> ");
						printKata(InfoTop(S).nama);
						printf("'s HP was restored by %d points\n",InfoTop(S).HPMax-InfoTop(S).HP);
						InfoTop(S).HP=InfoTop(S).HPMax;
						key = getch();
					}
					JumlahInfo(PRef)--;
					if (JumlahInfo(PRef) == 0)
					{
						DeleteP(&ListTas,Info(PRef));
					}
				}
				else
				{
					printf("> "); printKata(InfoTop(S).nama);
					printf("'s HP is full!\n");
				}
			}
			pass = true;
		}
		else if (strcmp(NamaItem,"Cancel") == 0)
		{
			printf("> Cancel using item\n");
			pass = true;
			key = getch();
		}
		else
		{
			printf("> Wrong Input! Consider retyping your command!\n");
		}
	} while (!pass);
}

void Tangkap()
{
	int x, CR;
	char dummy;
	
	x = RandomRange(100,1);
	CR = WildPoke.catchrate + EfekInfo(PRef);
	if (x < CR)
	{
		Push(&S,WildPoke);
		printf("> Gotcha! ");
		printKata(WildPoke.nama);
		printf(" was caught!\n");
		SwitchTurn(&Q);
		tangkap=true;
	}
	else
	{
		printf("> Aww! It appeared to be caught!\n");
	}
	dummy = getch();
}

void Kabur() 
{
	int x;
	x = RandomRange(1,0);
	infotype X;
	
	if (x==1)
	{
		kabur = true;
		printf("> Got away safely\n");
		SwitchTurn(&Q);
	}
	else
	{
		printf("> Can't escape!\n");
		Attack(WildPoke,&InfoTop(S));
		if (InfoTop(S).HP <= 0)
		{
			InfoTop(S).HP = 0;
			printf("> ");
			printKata(InfoTop(S).nama);
			printf(" fainted. ");
			Pop(&S,&X);
			if (!IsStackEmpty(S))
			{
				printKata(InfoTop(S).nama);
				printf(" Go for it!\n");
			}
			else
			{
				printf("\n> "); printKata(NamaPemain(Player));
				printf(" ran out of Pokemon. "); printKata(NamaPemain(Player));
				printf(" was whited out!\n");
				key = getch();
			}
		}
		kabur = false;
	}
}

bool IsSemak()
{
	return (CurrentMap.Mem[Ordinat(PosisiPemain(Player))][Absis(PosisiPemain(Player))]==18);
}

bool IsMart()
{
	return (CurrentMap.Mem[Ordinat(PosisiPemain(Player))][Absis(PosisiPemain(Player))]==12);
}