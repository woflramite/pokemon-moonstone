// NIM/Nama : 18215005/Balya Ibnu Sulistiyono
// Nama File : PP07-18215005-071116-01.h
// Tanggal :  7 November 2016
// Deskripsi : Header ADT Queue

// Modul ADT Queue - Alternatif I
// *** Deklarasi Queue yang diimplementasi dengan tabel kontigu ***
// *** HEAD dan TAIL adalah alamat elemen pertama dan terakhir ***
// *** Queue mampu menampung MaxEl buah elemen ***
#ifndef QUEUE_H
#define QUEUE_H

// *** Konstanta ***
#define Nil 0
#include "pokemon_11.h"
#include "kata_11.h"
#include "boolean_11.h"

// *** Definisi elemen dan address ***
// Sudah dilakukan di stack_11.h

// *** Definisi Type Queue ***
typedef Pokedex infotype;
typedef int address;
typedef struct
{
	infotype * T;
	address HEAD;
	address TAIL;
	int MaxElQ;
} Queue;

// Definisi Queue kosong: Head = Nil; Tail = Nil.
// Catatan implementasi: T[0] tidak pernah dipakai

// Definisi akses dengan Selektor : Isilah dengan selektor yang tepat
// *** Selektor ***
#define HEAD(Q) (Q).HEAD
#define TAIL(Q) (Q).TAIL
#define MaxElQ(Q) (Q).MaxElQ
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]

// *** Predikat Pemeriksaan Kondisi Queue ***
bool IsEmpty (Queue Q);
// Mengirim true jika kosong 
bool IsFull (Queue Q);
// Mengirim true jika tabel penampung elemen Q sudah penuh yaitu mengandung
// MaxEl elemen 
int NBElmt (Queue Q);
// Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. 

// *** Konstruktor *** 
void CreateEmpty (Queue *Q, int Max);
// I.S. Max terdefinisi
// F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sebagai berikut:
//		Jika alokasi berhasil, tabel memori dialokasi berukuran Max 
//		atau : jika alokasi gagal, Q kosong dengan Maksimum elemen = 0
// Proses : Melakukan alokasi memori dan membuat sebuah Q kosong 

// *** Destruktor *** 
void DeAlokasi (Queue *Q);
// Proses : Mengembalikan memori Q 
// I.S. Q pernah dialokasi 
// F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0

// *** Operator-Operator Dasar Queue *** 
void Add (Queue *Q, infotype X);
// Proses : Menambahkan X pada Q dengan aturan FIFO
// I.S. Q mungkin kosong, tabel penampung elemen TIDAK penuh 
// F.S. X menjadi TAIL yang baru, TAIL "maju"
void Del (Queue *Q, infotype *X);
// Proses: Menghapus elemen pertama pada Q dengan aturan FIFO
// I.S. Q tidak kosong 
// F.S. X = nilai elemen HEAD pada I.S.,
//		Jika Queue masih isi : HEAD diset tetap = 1, elemen-elemen setelah
//		HEAD yang lama digeser ke "kiri", TAIL = TAIL - 1;
//		Jika Queue menjadi kosong, HEAD = TAIL = Nil.


// *** Prosedur-Prosedur Tambahan ***
void CetakElemen (Queue Q);
// I.S. Q tidak kosong
// F.S. Elemen pada queue dicetak ke layar

void SwitchTurn (Queue * Q);
// I.S. Q tidak kosong
// F.S. Elemen pada Queue yang ada di depan dipindah ke belakang

void LoadQueuePokemon (Queue * Q, Queue * StarterQ);
// I.S. Q kosong
// F.S. Elemen pada Queue terisi oleh infotype bertipe Pokemon

#endif //QUEUE_H
