#include "load_11.h"
#include "strings_11.h"
#include "pemain_11.h"
#include "mesinkata_11.h"
#include "strings_11.h"
#include "boolean_11.h"
#include <stdio.h>

Stack S;
addressList P;
Queue Q, StarterQ;
List ListToko,ListTas;
MATRIKS Peta1,Peta2,Peta3,Peta4,MatchUp,CurrentMap;
ArrayTingkat A;
FILE *f;
Pemain Player;
bool LoadBerhasil;

void Load()
// Melakukan loading semua file eksternal
// I.S. Sembarang
// F.S. List, matriks, queue menjadi terisi sesuai *.txt
{
	LoadPeta(&Peta1,PetaA);
	LoadPeta(&Peta2,PetaB);
	LoadPeta(&Peta3,PetaC);
	LoadPeta(&Peta4,PetaD);
	LoadMatchup(&MatchUp);
	LoadQueuePokemon(&Q,&StarterQ);
	LoadTokoList(&ListToko);
	CreateList(&ListTas);
	LoadArrayTingkat(&A);
}

void Save()
{
	Stack StackDummy;
	Pokedex X;
	
	StackDummy = S;
	
	f  = fopen("SaveFile.txt","w");
	if (f == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	
	fprintKata(NamaPemain(Player));
	fprintf(f," %d ",UangPemain(Player));
	fprintf(f,"%d ",EXPPemain(Player));
	fprintf(f,"%d ",LevelPemain(Player));
	fprintf(f,"%d %d ",Absis(PosisiPemain(Player)),Ordinat(PosisiPemain(Player)));
	if (IsEqual(CurrentMap,Peta1))
	{
		fprintf(f,"Peta1\n");
	}
	else if (IsEqual(CurrentMap,Peta2))
	{
		fprintf(f,"Peta2\n");
	}
	else if (IsEqual(CurrentMap,Peta3))
	{
		fprintf(f,"Peta3\n");
	}
	else if (IsEqual(CurrentMap,Peta4))
	{
		fprintf(f,"Peta4\n");
	}
	while (!IsStackEmpty(StackDummy))
	{
		fprintPokemon(InfoTop(StackDummy));
		Pop(&StackDummy,&X);
	}
	fprintf(f,"\n");
	P = First(ListTas);
	while (P!=Nil)
	{
		fprintItem(Info(P));
		P = Next(P);
	}
	fprintf(f,"\n.");
	fclose(f);
}

void LoadPlayer()
{
	Stack StackDummy;
	infotypeList CItem;
	infotype CPokemon;
	Kata KataPeta1,KataPeta2,KataPeta3,KataPeta4;
	
	Katacpy(&KataPeta1,"Peta1");
	Katacpy(&KataPeta2,"Peta2");
	Katacpy(&KataPeta3,"Peta3");
	Katacpy(&KataPeta4,"Peta4");
	
	STARTKATA(6);
	if (EndKata)
	{
		printf("> Empty file. Create new adventure!\n");
		LoadBerhasil = false;
	}
	else
	{
		CreateStack(&S);
		CreateStack(&StackDummy);
		CreateList(&ListTas);
		
		printf("> Loading player data...\n");
		NamaPemain(Player) = CKata;
		ADVKATA();
		UangPemain(Player) = strtoval(CKata);
		ADVKATA();
		EXPPemain(Player) = strtoval(CKata);
		ADVKATA();
		LevelPemain(Player) = strtoval(CKata);
		ADVKATA();
		Absis(PosisiPemain(Player)) = strtoval(CKata);
		ADVKATA();
		Ordinat(PosisiPemain(Player)) = strtoval(CKata);
		ADVKATA();
		if (Katacmp(KataPeta1,CKata)==0)
		{
			CurrentMap=Peta1;
		}
		else if (Katacmp(KataPeta2,CKata) == 0)
		{ 
			CurrentMap=Peta2;
		}
		else if (Katacmp(KataPeta3,CKata) == 0)
		{ 
			CurrentMap=Peta3;
		}
		else if (Katacmp(KataPeta4,CKata) == 0)
		{ 
			CurrentMap=Peta4;
		}
		printf("> Loading party Pokemon data...\n");
		ADVKATA();
		
		EndLine = false;
		while (!EndLine)
		{
			CPokemon.nama = CKata;
			ADVKATA();
			CPokemon.tipeKata = CKata;
			ADVKATA();
			CPokemon.tipe = strtoval(CKata);
			ADVKATA();
			CPokemon.HP = strtoval(CKata);
			ADVKATA();
			CPokemon.HPMax = strtoval(CKata);
			ADVKATA();
			CPokemon.bawahattack = strtoval(CKata);
			ADVKATA();
			CPokemon.atasattack = strtoval(CKata);
			ADVKATA();
			CPokemon.bawahexp = strtoval(CKata);
			ADVKATA();
			CPokemon.atasexp = strtoval(CKata);
			ADVKATA();
			CPokemon.bawahmoney = strtoval(CKata);
			ADVKATA();
			CPokemon.atasmoney = strtoval(CKata);
			ADVKATA();
			CPokemon.catchrate = strtoval(CKata);
			Push(&StackDummy,CPokemon);
			if (!EndLine)
			{
				ADVKATA();
			}
		}
		
		printf("> Grooming your Pokemon...\n");
		while (!IsStackEmpty(StackDummy))
		{
			Push(&S,InfoTop(StackDummy));
			Pop(&StackDummy,&CPokemon);
		}
		printf("> Loading item data...\n");
		while (!EndKata)
		{
			EndLine = false;
			CItem.Nama = CKata;
			ADVKATA();
			CItem.Jenis = CKata;
			ADVKATA();
			CItem.Harga = strtoval(CKata);
			ADVKATA();
			CItem.Efek = strtoval(CKata);
			ADVKATA();
			CItem.Jumlah = strtoval(CKata);
			Alokasi(&P,CItem);
			InsertAlfabetis(&ListTas,P);
			if (!EndLine)
			{
				ADVKATA();
			}
		}
		ADVKATA();
		LoadBerhasil = true;
	}
}

void fprintPokemon(Pokedex X)
{
	fprintKata(X.nama); fprintf(f," ");
	fprintKata(X.tipeKata); fprintf(f," ");
	fprintf(f, "%d %d %d %d %d %d %d ",X.tipe,X.HP,X.HPMax,X.bawahattack,X.atasattack,X.bawahexp,X.atasexp);
	fprintf(f, "%d %d %d ",X.bawahmoney, X.atasmoney, X.catchrate);
}

void fprintItem(Item X)
{
	fprintKata(NamaItem(X)); fprintf(f," "); fprintKata(JenisItem(X)); fprintf(f," ");
	fprintf(f,"%d %d %d ",HargaItem(X),EfekItem(X),JumlahItem(X));
}