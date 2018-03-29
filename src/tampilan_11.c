#include "tampilan_11.h"
#include "stack_11.h"
#include "strings_11.h"
#include "matriks_11.h"
#include "encounter_11.h"
#include "load_11.h"
#include <strings.h>
#include <conio.h>
#include <stdio.h>

Stack S;
Queue Q,StarterQ;
char key;
List ListToko,ListTas;
char command[50];
MATRIKS CurrentMap,Peta1,Peta2,Peta3,Peta4,MatchUp;
int i;
Pokedex WildPoke;

void InfoPemain ()
// Menampilkan informasi Pemain yang meliputi sebagai berikut:
// Nama, daftar Pokemon beserta HP, Uang, EXP, Level, Posisi
// I.S. Sembarang
// F.S. Menampilkan informasi pemain
{
	system("cls");
	printf("+----------------------+------------------------------------------------------+\n");
	printf("|Player Name:          |");	printKata(Player.Nama);
	for (i=Player.Nama.Length; i<=53; i++)
	{
		printf(" ");
	}
	printf("|\n");
	printf("+----------------------+------------------------------------------------------+\n");
	printf("|Active Pokemon        |"); printKata(NamaTop(S)); printf("/HP(%d)",HPTop(S));
	for (i=NamaTop(S).Length+ndigit(HPTop(S))+5; i<=53; i++)
	{
		printf(" ");
	}
	printf("|\n");
	printf("+----------------------+------------------------------------------------------+\n");
	if (!IsStackEmpty(S))
	{
		printf("|Party Pokemon         |"); printKata(NamaTop(S)); printf("/HP(%d)",HPTop(S));
		for(i=NamaTop(S).Length+ndigit(HPTop(S))+5; i<=53; i++) 
		{
			printf(" ");
		}
		printf("|\n");
		printTabelStack(S);
	}
	else
	{
		printf("|Party Pokemon         |"); printKata(NamaTop(S)); printf("/HP(%d)",HPTop(S));
		for (i=NamaTop(S).Length+ndigit(HPTop(S))+5; i<=53; i++)
		{
			printf(" ");
		}
		printf("|\n");
	}
	printf("+----------------------+------------------------------------------------------+\n");
	printf("|Money                 |"); printf("%d",Player.Uang); 
	for(i=ndigit(Player.Uang); i<=53; i++) 
	{
		printf(" ");
	}
	printf("|\n");
	printf("+----------------------+------------------------------------------------------+\n");
	printf("|EXP                   |"); printf("%d",Player.EXP); 
	for(i=ndigit(Player.EXP); i<=53; i++) 
	{
		printf(" ");
	}
	printf("|\n");
	printf("+----------------------+------------------------------------------------------+\n");
	printf("|Level                 |");	printf("%d",Player.Level.NoTingkat);
	for(i=ndigit(Player.Level.NoTingkat); i<=53; i++)
	{
		printf(" ");
	}
	printf("|\n");
	printf("+----------------------+------------------------------------------------------+\n");
	printf("|Position              |"); TulisPoint(Player.Posisi);
	for(i=(ndigit(Absis(Player.Posisi))+ndigit(Ordinat(Player.Posisi))+3); i<=53; i++)
	{
		printf(" ");
	}
	printf("|\n");
	printf("+----------------------+------------------------------------------------------+\n");
}

int ndigit(int X)
// Menghasilkan jumlah digit suatu bilangan
{
	int bump=0;
	if (X==0)
	{
		return 1;
	}
	else
	{
		while (X!=0)
		{
			bump++;
			X/=10;
		}
		return (bump);
	}
}

void MenuUtama()
// Menampilkan menu utama juga menerima input pilihan
// I.S. Sembarang
// F.S. Pilihan user dikerjakan
{
	bool pass = false;
	
	// print HEADER
	printf("> New Game\n");
	printf("> Load Game\n");
	printf("> Help\n");
	printf("> About\n");
	//printf("> Hall of Fame\n");
	printf("> Exit\n\n");
	do
	{
		printf("> ");
		fgets(command, 50, stdin);
		if ((strlen(command)>0) && (command[strlen(command) - 1] == '\n')) command[strlen(command)-1] = 0;
		if ((strcmp(command,"New Game")==0) || (strcmp(command,"Help")==0) || (strcmp(command,"About")==0) || (strcmp(command,"Exit")==0) || (strcmp(command,"Load Game")==0))
		{
			pass = true;
		}
		else
		{
			printf("> Wrong input! Consider retyping the command!\n");
		}
	} while (!pass);
	
}

void TampilTas()
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "N/A" */
{
	printf("+---------------------------------------------------------------------------+\n");
	printf("|                                   ITEMS                                   |\n");
	printf("+---------------------+-------------------+----------------+----------------+\n");
	printf("|      Item Name      |     Item Type     |     Effect     |     Amount     |\n");
	printf("+---------------------+-------------------+----------------+----------------+\n");
	printIsiTas();
	printf("+---------------------+-------------------+----------------+----------------+\n");
}

void printIsiTas()
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "N/A" */
{
	/* Kamus Lokal */
	addressList P;
	/* Algoritma */
	P = First(ListTas);
	if (P == NilList)
	{
		printf("|         N/A         |        N/A        |      N/A       |      N/A       |\n");
	}
	while (P!=NilList)
	{
		printf("|"); printKata(NamaInfo(P)); for (i=NamaInfo(P).Length; i<21; i++) printf(" ");
		printf("|"); printKata(JenisInfo(P)); for (i=JenisInfo(P).Length; i<19; i++) printf(" ");
		printf("|"); printf("%d",EfekInfo(P)); for (i=ndigit(EfekInfo(P)); i<16; i++) printf(" ");
		printf("|"); printf("%d",JumlahInfo(P)); for (i=ndigit(JumlahInfo(P)); i<16; i++) printf(" ");
		printf("|\n");
		P = Next(P);
	}
}

void printTabelStack()
// I.S. List tidak mungkin kosong
// F.S. Informasi nama dan HP Pokemon ditampilkan dalam
// 		tabel tersebut
{
	Stack StackDummy;
	StackDummy = S;
	infotype X;
	
	if (!IsStackEmpty(StackDummy))
	{
		Pop(&StackDummy,&X);
		while (!IsStackEmpty(StackDummy))
		{
			printf("|                      +------------------------------------------------------+\n");
			printf("|                      |");
			printKata(NamaTop(StackDummy)); printf("/HP(%d)",HPTop(StackDummy));
			for (i=NamaTop(StackDummy).Length+ndigit(HPTop(StackDummy))+5; i<=53; i++) printf(" ");
			printf("|\n");
			Pop(&StackDummy,&X);
		}
	}
}

void TampilToko()
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "N/A" */
{
	Item Cart;
	int N;
	char NamaItem[50];
	addressList PRef,P;
	
	printf("+---------------------------------------------------------------------------+\n");
	printf("|                                 PokeMart                                  |\n");
	printf("+---------------------------------------------------------------------------+\n");
	printf("|      Item Name      |     Item Type     |      Price     |     Effect     |\n");
	printf("+---------------------+-------------------+----------------+----------------+\n");
	printIsiToko();
	printf("+---------------------+-------------------+----------------+----------------+\n");
	printf("> Is there anything I can help you with? (Y/N)\n");
	do
	{
		printf("> ");
		scanf(" %c",&key);
		if ((key == 'Y') || (key == 'y'))
		{
			scanf("%c",&key);
			printf("> Item name: ");
			fgets(NamaItem, 50, stdin);
			if ((strlen(NamaItem)>0) && (NamaItem[strlen(NamaItem) - 1] == '\n')) NamaItem[strlen(NamaItem)-1] = 0;
			Katacpy(&NamaItem(Cart),NamaItem);
			if (IsExisted(ListToko,Cart))
			{
				PRef = Search(ListToko,Cart);
				printf("> "); printKata(NamaInfo(PRef)); printf("? Certainly.\n");
				printf("> How many would you like?\n");
				printf("> Amount: ");
				scanf("%d",&N);
				if (N*HargaInfo(PRef) <= UangPemain(Player))
				{
					if (N>0)
					{
						Alokasi(&P,Cart);
						NamaInfo(P) = NamaInfo(PRef);
						JenisInfo(P) = JenisInfo(PRef);
						EfekInfo(P) = EfekInfo(PRef);
						HargaInfo(P) = HargaInfo(PRef);
						JumlahInfo(P) = N;
						InsertAlfabetis(&ListTas,P);
						UangPemain(Player)-=JumlahInfo(P)*HargaInfo(P);
						printf("> Thank for shopping with us!\n");
					}
					else
					{
						printf("> Purchase is canceled\n");
					}
				}
				else
				{
					printf("> Your money is insufficient\n");
				}
			}
			else
			{
				printf("> Sorry, we don't sell that item\n");
			}
			printf("> Do you want to buy other items?\n");
		}
		else if ((key == 'N') || (key=='n'))
		{
			printf("> Please come again!\n");
		}
		else
		{
			printf("> Wrong input, please try again\n");
		}
	} while ((key != 'N') && (key!='n'));
}

void printIsiToko()
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "N/A" */
{
	/* Kamus Lokal */
	addressList P;
	/* Algoritma */
	P = First(ListToko);
	if (P == NilList)
	{
		printf("|         N/A         |        N/A        |      N/A       |      N/A       |\n");
	}
	while (P!=NilList)
	{
		printf("|"); printKata(NamaInfo(P)); for (i=NamaInfo(P).Length; i<21; i++) printf(" ");
		printf("|"); printKata(JenisInfo(P)); for (i=JenisInfo(P).Length; i<19; i++) printf(" ");
		printf("|"); printf("%d",HargaInfo(P)); for (i=ndigit(HargaInfo(P)); i<16; i++) printf(" ");
		printf("|"); printf("%d",EfekInfo(P)); for (i=ndigit(EfekInfo(P)); i<16; i++) printf(" ");
		printf("|\n");
		P = Next(P);
	}
}

void MainMap()
{
	int X;
	
	key = getch();
	if (((key=='W') || (key=='w')) && (Player.Posisi.Y>1))
	{
		Player.Posisi.Y--;
		if (IsSemak())
		{
			X = RandomRange(1,0);
			if (X==1)
			{
				InBattle();
			}
		}
		if (IsMart())
		{
			system("cls");
			TampilToko();
		}
		SwitchPeta();
	}
	else if (((key=='A') || (key=='a')) && (Player.Posisi.X>1))
	{
		Player.Posisi.X--;
		if (IsSemak())
		{
			X = RandomRange(1,0);
			if (X==1)
			{
				InBattle();
			}
		}
		if (IsMart())
		{
			system("cls");
			TampilToko();
		}
		SwitchPeta();
	}
	else if (((key=='S') || (key=='s')) && (Player.Posisi.Y<10))
	{
		Player.Posisi.Y++;
		if (IsSemak())
		{
			X = RandomRange(1,0);
			if (X==1)
			{
				InBattle();
			}
		}
		if (IsMart())
		{
			system("cls");
			TampilToko();
		}
		SwitchPeta();
	}
	else if (((key=='D') || (key=='d')) && (Player.Posisi.X<10))
	{
		Player.Posisi.X++;
		if (IsSemak())
		{
			X = RandomRange(1,0);
			if (X==1)
			{
				InBattle();
			}
		}
		if (IsMart())
		{
			system("cls");
			TampilToko();
		}
		SwitchPeta();
	}
	else if (key==' ')
	{
		system("cls");
		TampilPause();
	}
	system("cls");
	PrintPeta(CurrentMap);
	
}

void SwitchPeta()
{
	if (IsEqual(CurrentMap,Peta1))
	{
		if (CurrentMap.Mem[Ordinat(PosisiPemain(Player))][Absis(PosisiPemain(Player))] == 23)
		{
			if (Absis(PosisiPemain(Player)) == 10)
			{
				CurrentMap = Peta2;
				Absis(PosisiPemain(Player)) = 1;
			}
			if (Ordinat(PosisiPemain(Player)) == 10)
			{
				CurrentMap = Peta3;
				Ordinat(PosisiPemain(Player)) = 1;
			}
		}
	}
	else if (IsEqual(CurrentMap,Peta2))
	{
		if (CurrentMap.Mem[Ordinat(PosisiPemain(Player))][Absis(PosisiPemain(Player))] == 23)
		{
			if (Absis(PosisiPemain(Player)) == 1)
			{
				CurrentMap = Peta1;
				Absis(PosisiPemain(Player)) = 10;
			}
			if (Ordinat(PosisiPemain(Player)) == 10)
			{
				CurrentMap = Peta4;
				Ordinat(PosisiPemain(Player)) = 1;
			}
		}
	}
	else if (IsEqual(CurrentMap,Peta3))
	{
		if (CurrentMap.Mem[Ordinat(PosisiPemain(Player))][Absis(PosisiPemain(Player))] == 23)
		{
			if (Absis(PosisiPemain(Player)) == 10)
			{
				CurrentMap = Peta4;
				Absis(PosisiPemain(Player)) = 1;
			}
			if (Ordinat(PosisiPemain(Player)) == 1)
			{
				CurrentMap = Peta1;
				Ordinat(PosisiPemain(Player)) = 10;
			}
		}
	}
	else if (IsEqual(CurrentMap,Peta4))
	{
		if (CurrentMap.Mem[Ordinat(PosisiPemain(Player))][Absis(PosisiPemain(Player))] == 23)
		{
			if (Absis(PosisiPemain(Player)) == 1)
			{
				CurrentMap = Peta3;
				Absis(PosisiPemain(Player)) = 10;
			}
			if (Ordinat(PosisiPemain(Player)) == 1)
			{
				CurrentMap = Peta2;
				Ordinat(PosisiPemain(Player)) = 10;
			}
		}
	}
}

bool IsGameOver()
{
	return IsStackEmpty(S);
}

void InfoPokemon()
{
	InfoHead(StarterQ);
	printf("+---------------+------------------------------------------+\n");
	printf("| Pokemon Name  |"); printKata(InfoHead(StarterQ).nama);
	for (i=InfoHead(StarterQ).nama.Length; i<42; i++) printf(" "); printf("|\n");
	printf("+---------------+------------------------------------------+\n");
	printf("| Type          |"); printKata(InfoHead(StarterQ).tipeKata);
	for (i=InfoHead(StarterQ).tipeKata.Length; i<42; i++) printf(" "); printf("|\n");
	printf("+---------------+------------------------------------------+\n");
}

void TampilBattle()
{
	printf("+--------------------+--------------------+--------------------+\n");
	printf("|       Status       |    Your Pokemon    |    Wild Pokemon    |\n");
	printf("+--------------------+--------------------+--------------------+\n");
	printf("| Pokemon Name       |"); printKata(InfoTop(S).nama); for (i=InfoTop(S).nama.Length; i<20; i++) printf(" ");
	printf("|"); printKata(WildPoke.nama); for (i=WildPoke.nama.Length; i<20; i++) printf(" "); printf("|\n");
	printf("+--------------------+--------------------+--------------------+\n");
	printf("| Type               |"); printKata(InfoTop(S).tipeKata); for (i=InfoTop(S).tipeKata.Length; i<20; i++) printf(" ");
	printf("|"); printKata(WildPoke.tipeKata); for (i=WildPoke.tipeKata.Length; i<20; i++) printf(" "); printf("|\n");
	printf("+--------------------+--------------------+--------------------+\n");
	printf("| HP                 |"); printf("%d/%d",InfoTop(S).HP,InfoTop(S).HPMax); for (i=ndigit(InfoTop(S).HP)+ndigit(InfoTop(S).HPMax)+1; i<20; i++) printf(" ");
	printf("|"); printf("%d/%d",WildPoke.HP,WildPoke.HPMax); for (i=ndigit(WildPoke.HP)+ndigit(WildPoke.HPMax)+1; i<20; i++) printf(" "); printf("|\n");
	printf("+--------------------+--------------------+--------------------+\n");
}

void TampilBantuan()
{
	char dummy;
	
	printf("> Hello, I am May, Prof. Birch's daughter and I am going to teach you anything about being a Pokemon Trainer\n");
	dummy = getch();
	printf("> First thing first, you will need to walk around using 'W','A','S', and 'D'\n");
	printf("> Press SPACE if you want to either check your info, use your items, or save your game\n");
	dummy = getch();
	printf("\n");
	printf("> Do not walk over bushes if you do not like encountering wild Pokemon\n");
	printf("> But what will that do good? You'll need to toughen up yourself to become a Pokemon Trainer\n");
	dummy = getch();
	printf("\n");
	printf("> During battle, there will be two tables showing your Pokemon and wild Pokemon status\n");
	printf("> You are able to choose either 'Fight', 'Bag', or 'Run'\n");
	dummy = getch();
	printf("\n");
	printf("> If you choose 'Fight', your Pokemon will start attacking wild Pokemon at random rate\n");
	printf("> Your Pokemon (or wild Pokemon) might have advantage over their typing. For example,\n");
	printf("> FIRE type Pokemon will be super effective against GRASS and BUG type. However, GRASS type Pokemon will\n");
	printf("> be not very effective against FIRE and BUG type\n");
	printf("> Don't worry memorising all those typing. You'll get used to that\n");
	dummy = getch();
	printf("\n");
	printf("> If you choose 'Bag', the ITEMS table will show up, showing all your items retrieved\n");
	printf("> Potion-type items will recover your Pokemon HP according to their effect value\n");
	printf("> Pokeball-type items will help you catch Pokemon. Greater effect will increase the wild Pokemon catch rate\n");
	printf("> Type 'Cancel' if you change your mind\n");
	printf("> But do not forget to buy at the nearest PokeMart around you!\n");
	dummy = getch();
	printf("\n");
	printf("> If you choose 'Run', there will be 50:50 chance if you succeed in fleeing\n");
	printf("> You will not receive any EXP\n");
	dummy = getch();
	printf("\n");
	printf("> There will be PokeMart around you. You can shop there and buy important items,\n");
	printf("> either for battling Pokemon, or for catching 'em all!\n");
	printf("> If you want to cancel a purchase, just buy zero amount for items you wanted to buy!\n");
	dummy = getch();
	printf("\n");
	printf("> You are good to go!\n");
}

void TampilAbout()
{
	printf("> Balya Ibnu Sulistiyono (18215005)\n");
	printf("> Airinnisa Nur Hidayati (18215020)\n");
	printf("> Fathia Andita Resapati (18215031)\n");
}

void TampilPause()
{
	char command[50];
	bool pass=false;
	char dummy;
	
	printf("> Player Info\n");
	printf("> Bag\n");
	printf("> Save\n");
	printf("\n");
	do
	{	
		printf("> ");
		fgets(command,50,stdin);
		if ((strlen(command)>0) && (command[strlen(command) - 1] == '\n')) command[strlen(command)-1] = 0;
		if (strcmp(command,"Player Info") == 0)
		{
			InfoPemain();
			pass = true;
		}
		else if (strcmp(command,"Bag") == 0)
		{
			UseItem();
			pass = true;
		}
		else if (strcmp(command,"Save") == 0)
		{
			Save();
			pass = true;
		}
		else if (strcmp(command,"Cancel") == 0)
		{
			pass = true;
		}
		else
		{
			printf("> Wrong input! Consider retyping your command!\n");
		}
	} while (!pass);
	dummy = getch();
}