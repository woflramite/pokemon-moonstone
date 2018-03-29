// Nama/NIM : Balya Ibnu Sulistiyono/18215005
// File : PP08-18215005-141116-01.h
// Tanggal : 14 November 2016
// Deskripsi : Header ADT List


// ******************* MODUL LIST BERKAIT *******************

#ifndef LIST_H
#define LIST_H
#include "item_11.h"
#include "boolean_11.h"

#define NilList NULL
typedef Item infotypeList;
typedef struct tElmtlist *addressList;
typedef struct tElmtlist
{
	infotypeList info;
	addressList next;
} ElmtList;

typedef struct
{
	addressList First;
} List;

#define First(L) ((L).First)
#define Next(P) (P)->next
#define Info(P) (P)->info
#define NamaInfo(P) (P)->info.Nama
#define JenisInfo(P) (P)->info.Jenis
#define HargaInfo(P) (P)->info.Harga
#define EfekInfo(P) (P)->info.Efek
#define JumlahInfo(P) (P)->info.Jumlah

/* PROTOTYPE */
  
/* ***************** TEST LIST KOSONG ***************** */
bool IsListEmpty (List L);
/* Mengirim true jika list kosong */
  

/* ***************** PEMBUATAN LIST KOSONG ***************** */
void CreateList (List * L);
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */  

/* ***************** Manajemen Memori ***************** */
void Alokasi (addressList * P, infotypeList X);
/* Mengirimkan addressList hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressList tidak NilList, dan misalnya menghasilkan P, maka Info(P); = X, Next(P); = NilList */
/* Jika alokasi gagal, mengirimkan NilList */

void Dealokasi (addressList * P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressList P */
  
/* ***************** PENCARIAN SEBUAH ELEMEN LIST ***************** */
addressList Search (List L, infotypeList X);
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan addressList elemen tersebut */
/* Jika tidak ada, mengirimkan NilList */

addressList SearchGreater (List L, infotypeList X);
/* Mencari apakah ada elemen list dengan Info(P) > X */
/* Jika ada, mengirimkan addressList elemen tersebut */
/* Jika tidak ada, mengirimkan NilList */

addressList SearchPrec (List L, addressList P);
/* Mencari addressList Prec dari suksesor P */
/* Prekondisi: addressList P ada di list tersebut */

bool FSearch (List L, addressList P);
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */

bool IsExisted (List L, infotypeList X);
/* Mencari apakah ada elemen list yang bernama X */
/* Menghasilkan true jika ada elemen list yang bernama info(X) */
/* ***************** PRIMITIF BERDASARKAN ALAMAT ***************** */

/* *** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT *** */
void InsertFirst (List *L, addressList P);
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-addressList P sebagai elemen pertama */
void InsertAfter (List *L, addressList P, addressList Prec);  
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, addressList P);
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAlfabetis (List *L, addressList P);
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan setelah addressList dengan nama info < nama */

/* *** PENGHAPUSAN SEBUAH ELEMEN *** */

void DeleteFirst (List *L, addressList *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong); */
/* First element yang baru adalah suksesor elemen pertama yang lama */
void DeleteAfter (addressList Prec, addressList *P);
/* I.S. List tidak kosong, Prec adalah elemen list, Next(Prec) != NilList*/
/* F.S. Next(Prec), yaitu elemen beralamat P dihapus dari List. Next(P) = NilList */
/* Menghapus suksesor Prec, P adalah @ suksesor Prec sebelum penghapusan, Next
   (Prec) yang baru adalah suksesor dari suksesor Prec sebelum penghapusan */
void DeleteP (List *L, infotypeList X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressList P, dengan Info(P); = X */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P); = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DeleteLast (List *L, addressList *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong); */
/* Last element baru adalah predesesor elemen pertama yang lama, jika ada */
  
/* ***************** PROSES SEMUA ELEMEN LIST ***************** */
void LoadTokoList (List * L);
/* I.S. List sembarang */
/* F.S. List terisi alfabetis berdasarkan nama item */

#endif //LIST_H