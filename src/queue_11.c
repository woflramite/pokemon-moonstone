// NIM/Nama : 18215005/Balya Ibnu Sulistiyono
// Nama File : PP07-18215005-071116-01.c
// Tanggal :  7 November 2016
// Deskripsi : Body ADT Queue

#include "mesinkata_11.h"
#include "strings_11.h"
#include "boolean_11.h"
#include "queue_11.h"
#include <stdio.h>
#include <stdlib.h>

// Modul ADT Queue - Alternatif I
// *** Deklarasi Queue yang diimplementasi dengan tabel kontigu ***
// *** HEAD dan TAIL adalah alamat elemen pertama dan terakhir ***
// *** Queue mampu menampung MaxElQ buah elemen ***

// *** Predikat Pemeriksaan Kondisi Queue ***
bool IsEmpty (Queue Q)
// Mengirim true jika kosong 
{
	return (HEAD(Q) == Nil && TAIL(Q) == Nil);
}
bool IsFull (Queue Q)
// Mengirim true jika tabel penampung elemen Q sudah penuh yaitu mengandung
// MaxElQ elemen 
{
	return (TAIL(Q) == MaxElQ(Q));
}
int NBElmt (Queue Q)
// Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. 
{
	return TAIL(Q);
}

// *** Konstruktor *** 
void CreateEmpty (Queue *Q, int Max)
// I.S. Max terdefinisi
// F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sebagai berikut:
//		Jika alokasi berhasil, tabel memori dialokasi berukuran Max 
//		atau : jika alokasi gagal, Q kosong dengan Maksimum elemen = 0
// Proses : Melakukan alokasi memori dan membuat sebuah Q kosong 
{
	(*Q).T = (infotype *) malloc (sizeof(infotype) * (Max+1));
	if ((*Q).T != NULL)
	{
		HEAD(*Q) = Nil;
		TAIL(*Q) = Nil;
		MaxElQ(*Q) = Max;
	}
	else
	{
		MaxElQ(*Q) = Nil;
	}
}

// *** Destruktor *** 
void DeAlokasi (Queue *Q)
// Proses : Mengembalikan memori Q 
// I.S. Q pernah dialokasi 
// F.S. Q menjadi tidak terdefinisi lagi, MaxElQ(Q) diset 0
{
	MaxElQ(*Q) = Nil;
	free((*Q).T);
}
// *** Operator-Operator Dasar Queue *** 
void Add (Queue *Q, infotype X)
// Proses : Menambahkan X pada Q dengan aturan FIFO
// I.S. Q mungkin kosong, tabel penampung elemen TIDAK penuh 
// F.S. X menjadi TAIL yang baru, TAIL "maju"
{
	if (!(IsFull(*Q)))
	{
		if (IsEmpty(*Q))
		{
			HEAD(*Q)++;
		}
		TAIL(*Q)++;
		(*Q).T[TAIL(*Q)] = X;
	}
}
void Del (Queue *Q, infotype *X)
// Proses: Menghapus elemen pertama pada Q dengan aturan FIFO
// I.S. Q tidak kosong 
// F.S. X = nilai elemen HEAD pada I.S.,
//		Jika Queue masih isi : HEAD diset tetap = 1, elemen-elemen setelah
//		HEAD yang lama digeser ke "kiri", TAIL = TAIL - 1;
//		Jika Queue menjadi kosong, HEAD = TAIL = Nil.
{
	// Kamus Lokal
	int i;
	// Algoritma
	if (!(IsEmpty(*Q)))
	{
		*X = InfoHead(*Q);
		for (i = HEAD(*Q); i < TAIL(*Q); i++)
		{
			(*Q).T[i] = (*Q).T[i+1];
		}
		TAIL(*Q)--;
		if (TAIL(*Q) == Nil)
		{
			HEAD(*Q) = Nil;
		}
	}
}

// *** Prosedur-Prosedur Tambahan ***
void CetakElemen (Queue Q)
// I.S. Q tidak kosong
// F.S. Elemen pada queue dicetak ke layar
{
	// Kamus Lokal
	int i;
	// Algoritma
	for (i = HEAD(Q); i < TAIL(Q); i++)
	{
		printKata(Q.T[i].nama);
		printf(" ");
	}
	printKata(Q.T[i].nama);
	printf("\n");
}

void SwitchTurn (Queue * Q)
// I.S. Q tidak kosong
// F.S. Elemen pada Queue yang ada di depan dipindah ke belakang
{
	// Kamus Lokal
	infotype X;
	// Algoritma
	Del(&(*Q),&X);
	Add(&(*Q),X);
}

int ConvertType (Kata CKata)
// Mengubah tipe menjadi bilangan angka
{
	Kata BUG, ELECTR, FIRE, GRASS, POISON, PSYCHIC, WATER;
	Katacpy(&BUG,"BUG");
	Katacpy(&ELECTR,"ELECTRIC");
	Katacpy(&FIRE,"FIRE");
	Katacpy(&GRASS,"GRASS");
	Katacpy(&POISON,"POISON");
	Katacpy(&WATER,"WATER");
	Katacpy(&PSYCHIC,"PSYCHIC");
	
	if (Katacmp(CKata,BUG)==0)
	{
		return 1;
	}
	else if (Katacmp(CKata,ELECTR) == 0)
	{
		return 2;
	}
	else if (Katacmp(CKata,FIRE) == 0)
	{
		return 3;
	}
	else if (Katacmp(CKata,GRASS) == 0)
	{
		return 4;
	}
	else if (Katacmp(CKata,POISON) == 0)
	{
		return 5;
	}
	else if (Katacmp(CKata,PSYCHIC) == 0)
	{
		return 6;
	}
	else if (Katacmp(CKata,WATER) ==0)
	{
		return 7;
	}
}

void LoadQueuePokemon (Queue * Q, Queue * StarterQ)
// I.S. Q kosong
// F.S. Elemen pada Queue terisi oleh infotype bertipe Pokemon
{
	// Kamus Lokal
	int i = 1;
	int j = 1;
	Pokedex CPokemon;
	// Algoritma
	int Pilihan = 3;
	CreateEmpty(&(*Q),7);
	CreateEmpty(&(*StarterQ),3);
	STARTKATA(31);
	while (!EndKata)
	{
		CPokemon.nama = CKata;
		ADVKATA();
		CPokemon.tipe = ConvertType(CKata);
		CPokemon.tipeKata = CKata;
		ADVKATA();
		CPokemon.HP = strtoval(CKata);
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
		ADVKATA();		
		Add(&(*Q),CPokemon);
		Add(&(*StarterQ),CPokemon);
	}
	STARTKATA(32);
	while (!EndKata)
	{
		CPokemon.nama = CKata;
		ADVKATA();
		CPokemon.tipe = ConvertType(CKata);
		CPokemon.tipeKata = CKata;
		ADVKATA();
		CPokemon.HP = strtoval(CKata);
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
		ADVKATA();
		Add(&(*Q),CPokemon);
	}
}