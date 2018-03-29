// Nama/NIM : Balya Ibnu Sulistiyono/18215005
// File : PP08-18215005-141116-01.h
// Tanggal : 14 November 2016
// Deskripsi : Body ADT List

#include <stdio.h>
#include <stdlib.h>
#include "list_11.h"
#include "strings_11.h"
#include "boolean_11.h"
#include "mesinkata_11.h"

// ******************* MODUL LIST BERKAIT *******************

/* PROTOTYPE */
  
/* ***************** TEST LIST KOSONG ***************** */
bool IsListEmpty (List L)
/* Mengirim true jika list kosong */
{
	return First(L) == NilList;
}

/* ***************** PEMBUATAN LIST KOSONG ***************** */
void CreateList (List * L)
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */  
{
	First(*L) = NilList;;
}

/* ***************** Manajemen Memori ***************** */
void Alokasi (addressList * P, infotypeList X)
/* Mengirimkan addressList hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressList tidak NilList, dan misalnya menghasilkan P,
   maka Info(P) = X, Next(P) = NilList */
/* Jika alokasi gagal, mengirimkan NilList */
{
	/* Kamus Lokal */
	
	/* Algoritma */
	*P = (addressList) malloc(sizeof(ElmtList));
	while (P==NilList)
	{
		*P = (addressList) malloc(sizeof(ElmtList));
	}
	Info(*P) = X;
	Next(*P) = NilList;
}

void Dealokasi (addressList * P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressList P */
{
	free (*P);
}
  
/* ***************** PENCARIAN SEBUAH ELEMEN LIST ***************** */
addressList Search (List L, infotypeList X)
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan addressList elemen tersebut */
/* Jika tidak ada, mengirimkan NilList */
{
	/* Kamus Lokal */
	bool found;
	addressList P;
	/* Algoritma */
	P = First(L);
	found = false;
	while ((P!=NilList) && !(found))
	{
		if (Katacmp(X.Nama,Info(P).Nama) == 0)
		{
			found = true;
		}
		else
		{
			P = Next(P);
		}
	}
	return P;
}

addressList SearchGreater (List L, infotypeList X)
/* Mencari apakah ada elemen list dengan Info(P) > X */
/* Jika ada, mengirimkan addressList elemen tersebut */
/* Jika tidak ada, mengirimkan NilList */
{
	/* Kamus Lokal */
	bool found;
	addressList P;
	/* Algoritma */
	P = First(L);
	found = false;
	while ((P!=NilList) && !(found))
	{
		if (Katacmp(X.Nama,Info(P).Nama) == -1)
		{
			found = true;
		}
		else
		{
			P = Next(P);
		}
	}
	return P;
}

addressList SearchPrec (List L, addressList P)
/* Mencari addressList Prec dari suksesor P */
/* Prekondisi: addressList P ada di list tersebut */
{
	/* Kamus Lokal */
	addressList PFound;
	addressList Prec = NilList;
	bool found = false;
	/* Algoritma */
	PFound = First(L);
	while ((PFound!=NilList) && (!found))
	{
		if (PFound==P)
		{
			found = true;
		}
		else
		{
			Prec = PFound;
			PFound = Next(PFound);
		}
	}
	return Prec;
}

bool FSearch (List L, addressList P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
	/* Kamus Lokal */
	bool found;
	addressList PFound;
	infotypeList X;
	/* Algoritma */
	PFound = First(L);
	found = false;
	while (!(PFound==NilList) && !(found))
	{
		if (PFound == P)
		{
			found = true;
		}
		else
		{
			P = Next(P);
		}
	}
	return found;
}

bool IsExisted (List L, infotypeList X)
/* Menghasilkan true jika ada elemen list yang bernama info(X) */
{
	/* Kamus Lokal */
	addressList PFound;
	bool found;
	/* Algoritma */
	PFound = First(L);
	found = false;
	while ((PFound!=NilList) && !found)
	{
		if (Katacmp(X.Nama,Info(PFound).Nama) == 0)
		{
			found = true;
		}
		else
		{
			PFound = Next(PFound);
		}
	}
	return found;
}

/* ***************** PRIMITIF BERDASARKAN ALAMAT ***************** */

/* *** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT *** */
void InsertFirst (List *L, addressList P)
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-addressList P sebagai elemen pertama */
{
	Next(P) = First(*L);
	First(*L) = P;
}
void InsertAfter (List *L, addressList P, addressList Prec)  
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	Next(P) = Next(Prec);
	Next(Prec) = P;
}
void InsertLast (List *L, addressList P)
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	/* Kamus Lokal */
	addressList Last;
	/* Algoritma */
	if (IsListEmpty(*L))
	{
		InsertFirst(&(*L),P);
	}
	else
	{
		Last = First(*L);
		while (Next(Last) != NilList)
		{
			Last = Next(Last);
		}
		InsertAfter(&(*L),P,Last);
	}
}

void InsertAlfabetis (List *L, addressList P)
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan setelah addressList dengan nama info < nama */
{
	/* Kamus Lokal */
	addressList Prec, PGreater, PEqual;
	/* Algoritma */
	if (IsExisted(*L,Info(P)))
	{
		PEqual = Search(*L,Info(P));
		Info(PEqual).Jumlah += Info(P).Jumlah;
	}
	else
	{
		PGreater = SearchGreater(*L,Info(P));
		if (PGreater == NilList)
		{
			InsertLast(&(*L),P);
		}
		else
		{
			Prec = SearchPrec(*L,PGreater);
			if (Prec==NilList)
			{			
				InsertFirst(&(*L),P);
			}
			else
			{
				InsertAfter(&(*L),P,Prec);
			}
		}
	}
}

/* *** PENGHAPUSAN SEBUAH ELEMEN *** */

void DeleteFirst (List *L, addressList *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yang baru adalah suksesor elemen pertama yang lama */
{
	*P = First(*L);
	First(*L) = Next(First(*L));
	Next(*P) = NilList;
	Dealokasi(&(*P));
}

void DeleteAfter (addressList Prec, addressList *P)
/* I.S. List tidak kosong, Prec adalah elemen list, Next(Prec) != NilList*/
/* F.S. Next(Prec), yaitu elemen beralamat P dihapus dari List. Next(P) = NilList */
/* Menghapus suksesor Prec, P adalah @ suksesor Prec sebelum penghapusan, Next
   (Prec) yang baru adalah suksesor dari suksesor Prec sebelum penghapusan */
{
	*P = Next(Prec);
	Next(Prec) = Next(Next(Prec));
	Next(*P) = NilList;
	Dealokasi(&(*P));
}

void DeleteP (List *L, infotypeList X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressList P, dengan Info(P) = X */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	/* Kamus Lokal */
	addressList PFound, Prec;
	/* Algoritma */
	PFound = Search(*L,X);
	if (PFound = First(*L))
	{
		DeleteFirst(&(*L),&PFound);
	}
	else
	{
		Prec = First(*L);
		while (Next(Prec) != PFound)
		{
			Prec = Next(Prec);
		}
		DeleteAfter(Prec,&PFound);
	}
}
void DeleteLast (List *L, addressList *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yang lama, jika ada */
{
	/* Kamus Lokal */
	addressList Last, PrecLast;
	/* Algoritma */
	Last = First(*L);
	PrecLast = NilList;
	while (Next(Last)!=NilList)
	{
		PrecLast = Last;
		Last = Next(Last);
	}
	*P = Last;
	if (PrecLast == NilList)
	{
		First(*L) = NilList;
	}
	else
	{
		Next(PrecLast) = NilList;
	}
	Dealokasi(&(*P));
}
  
/* ***************** PROSES SEMUA ELEMEN LIST ***************** */
void LoadTokoList (List * L)
/* I.S. List sembarang */
/* F.S. List terisi alfabetis berdasarkan nama item */
{
	/* Kamus Lokal */
	addressList P;
	infotypeList CItem;
	/* Algoritma */
	CreateList(&(*L));
	STARTKATA(4);
	while (!EndKata)
	{
		CItem.Jenis = CKata;
		ADVKATA();
		CItem.Nama = CKata;
		ADVKATA();
		CItem.Harga = strtoval(CKata);
		ADVKATA();
		CItem.Efek = strtoval(CKata);
		ADVKATA();
		Alokasi(&P,CItem);
		InsertAlfabetis(&(*L),P);
	}
}