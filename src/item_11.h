#ifndef ITEM_H
#define ITEM_H
#include "kata_11.h"

typedef struct
{
	Kata Jenis;
	Kata Nama;
	int Harga;
	int Efek;
	int Jumlah;
} Item;

#define NamaItem(X) (X).Nama
#define JenisItem(X) (X).Jenis
#define HargaItem(X) (X).Harga
#define EfekItem(X) (X).Efek
#define JumlahItem(X) (X).Jumlah

#endif // ITEM_H