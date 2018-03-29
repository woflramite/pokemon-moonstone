#include "mesinkar_11.h"
#include <assert.h>
#include <fcntl.h>
#include <stdio.h>

//Kamus Umum
extern char CC;
#define pita "pitakar.txt"
#define matchup "ability.txt"
#define peta1 "peta.txt"
#define peta2 "peta2.txt"
#define peta3 "peta3.txt"
#define peta4 "peta4.txt"
#define poke1 "pokemon-permainan-baru.txt"
#define poke2 "pokemon.txt"
#define toko "toko.txt"
#define SaveFile "SaveFile.txt"
#define mappingLevel "pemetaan-level.txt"
int _handle;
extern int Pilihan;

void START(int Pilihan)
//I.S. : sembarang
//F.S. : CC adalah karakter pertama pita
//Jika CC==MARK, EOP menyala (true)
//Jika CC!=MARK, EOP padam (false)
{
	if (Pilihan == 11)
	{
		_handle = open(peta1, O_RDONLY);
	}
	else
	if (Pilihan == 12)
	{
		_handle = open(peta2, O_RDONLY);
	}
	else
	if (Pilihan == 13)
	{
		_handle = open(peta3, O_RDONLY);
	}
	else
	if (Pilihan == 14)
	{
		_handle = open(peta4, O_RDONLY);
	}
	else
	if (Pilihan == 2)
	{
		_handle = open(matchup, O_RDONLY);
	}
	else
	if (Pilihan == 31)
	{
		_handle = open(poke1, O_RDONLY);
	}
	else
	if (Pilihan == 32)
	{
		_handle = open(poke2, O_RDONLY);
	}
	else
	if (Pilihan == 4)
	{
		_handle = open(toko, O_RDONLY);
	}
	else
	if (Pilihan == 5)
	{
		_handle = open(mappingLevel, O_RDONLY);
	}
	else
	if (Pilihan == 6)
	{
		_handle = open(SaveFile, O_RDONLY);
	}
	else
	{
		_handle = open(pita, O_RDONLY);
	}
	assert(_handle != -1);
	assert(read(_handle,&CC,1) != -1);
}

void ADV()
//I.S. : CC!=MARK
//F.S. : CC adalah karakter berikutnya dari CC pada I.S.
//Jika CC==MARK, EOP menyala (true)
{
	assert(!EOP());
	assert(read(_handle,&CC,1) != -1);
	if (CC==MARK)
	{
		assert(close(_handle) != -1);
	}
}

bool EOP()
//Menghasilkan true jika CC=MARK
{
	return (CC==MARK);
}