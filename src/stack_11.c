// MODUL STACK
// Deklarasi stack yang diimplementasi dengan tabel kontigu alokasi stack
// dan ukuran sama
// TOP adalah alamat elemen puncak
#include "stack_11.h"
#include "boolean_11.h"
#include <stdio.h>

//Elemen yang dipakai menyimpan nilai Stack T[1] .. T[MaxEl]
//Jika S adalah Stack maka akses elemen:
//S.T[(S.TOP)] untuk mengakses elemen TOP
//S.TOP adalah alamat elemen TOP
//Definisi akses dengan Selektor: Istilah dengan selektor yang tepat

// ********* Prototype *********

// *** Konstruktor/Kreator ***
void CreateStack (Stack *S)
// I.S. Sembarang 
// F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl
// jadi indeksnya antara 1..MaxEl
// Ciri stack kosong : TOP bernilai Nil
{
	(*S).TOP = Nil;
}

// ********* Predikat untuk test keadaan KOLEKSI *********
bool IsStackEmpty (Stack S)
// Mengirim true jika Stack kosong: lihat definisi di atas
{
	return (S.TOP == Nil);
}
bool IsStackFull (Stack S)
// Mengirim true jika tabel penampung nilai elemen stack penuh
{
	return (S.TOP == MaxEl);
}


// ********* Operator Dasar Stack *********
void Push (Stack *S, infotype X)
// Menambahkan X sebagai elemen Stack S.
// I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh
// F.S. X menjadi TOP yang baru, TOP bertambah 1
{
	(*S).TOP++;
	(*S).T[(*S).TOP] = X;
}
void Pop (Stack *S, infotype *X)
// Menghapus X dari Stack S.
// I.S. S  tidak kosong
// F.S. X adalah nilai elemen TOP yang lama, TOP berkurang
{
	*X = (*S).T[(*S).TOP];
	(*S).TOP--;
}