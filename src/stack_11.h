#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "boolean_11.h"
#include "pokemon_11.h"
#include "kata_11.h"
#define Nil 0
#define MaxEl 20

// MODUL STACK
// Deklarasi stack yang diimplementasi dengan tabel kontigu alokasi stack
// dan ukuran sama
// TOP adalah alamat elemen puncak
typedef Pokedex infotype;
typedef int address; 
typedef struct { 
	infotype T[MaxEl+1]; 
	address TOP;
} Stack;

//Elemen yang dipakai menyimpan nilai Stack T[1] .. T[MaxEl]
//Jika S adalah Stack maka akses elemen:
//S.T[(S.TOP)] untuk mengakses elemen TOP
//S.TOP adalah alamat elemen TOP
//Definisi akses dengan Selektor: Istilah dengan selektor yang tepat

#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]
#define NamaTop(S) (S).T[(S).TOP].nama
#define HPTop(S) (S).T[(S).TOP].HP

// ********* Prototype *********

// *** Konstruktor/Kreator ***
void CreateStack (Stack *S);
// I.S. Sembarang 
// F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl
// jadi indeksnya antara 1..MaxEl
// Ciri stack kosong : TOP bernilai Nil

// ********* Predikat untuk test keadaan KOLEKSI *********
bool IsStackEmpty (Stack S);
// Mengirim true jika Stack kosong: lihat definisi di atas
bool IsStackFull (Stack S);
// Mengirim true jika tabel penampung nilai elemen stack penuh

// ********* Operator Dasar Stack *********
void Push (Stack *S, infotype X);
// Menambahkan X sebagai elemen Stack S.
// I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh
// F.S. X menjadi TOP yang baru, TOP bertambah 1

void Pop (Stack *S, infotype *X);
// Menghapus X dari Stack S.
// I.S. S  tidak kosong
// F.S. X adalah nilai elemen TOP yang lama, TOP berkurang

#endif // STACK_H