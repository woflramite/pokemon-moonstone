// PENGOLAHAN KATA

#include "strings_11.h"
#include "boolean_11.h"
#include "kata_11.h"
#include <strings.h>
#include <stdio.h>

FILE *f;

int Katacmp(Kata Kata1, Kata Kata2)
// Mengembalikan -1 jika Kata1 < Kata2, 0 jika Kata1 = Kata2, dan 1 jika
// Kata1 > Kata 2
{
	// Kamus Lokal
	int i=1;
	// Algoritma
	while ((Kata1.TabKata[i]==Kata2.TabKata[i]) && (i<minLen(Kata1,Kata2)))
	{
		i++;
	}
	if (Kata1.TabKata[i]<Kata2.TabKata[i])
	{
		return -1;
	}
	else
	if (Kata1.TabKata[i]==Kata2.TabKata[i])
	{
		if (Kata1.Length == Kata2.Length)
		{
			return 0;
		}
		else
		{
			if (Kata1.Length < Kata2.Length)
			{
				return -1;
			}
			else
			{
				return 1;
			}
		}
	}
	else
	{
		return 1;
	}
}

int minLen(Kata Kata1, Kata Kata2)
// Mengembalikan nilai terkecil panjang dua kata
{
	return (Kata1.Length < Kata2.Length ? Kata1.Length : Kata2.Length);
}

int maxLen(Kata Kata1, Kata Kata2)
// Mengembalikan nilai terbesar panjang dua kata
{
	return (Kata1.Length > Kata2.Length ? Kata1.Length : Kata2.Length);
}

int Katalen(Kata CKata)
// Mengembalikan jumlah huruf pada suatu kata
{
	return CKata.Length;
}

void scanKata(Kata * CKata)
// I.S. CKata sembarang
// F.S. CKata berisi kata sesuai input user
// Proses: Menerima input menggunakan scanf dan memasukkannya ke dalam CKata.TabKata
{
	int i = 1;
	char str[51];
	
	fgets(str,51,stdin);
	if ((strlen(str)>0) && (str[strlen(str) - 1] == '\n')) str[strlen(str)-1] = 0;
	Katacpy(&(*CKata),str);
}

int strtoval(Kata CKata)
// Mengubah string "ABC" menjadi integer 100A + 10B + C
{
	// Kamus Lokal
	int i;
	int bil = 0;
	// Algoritma
	for (i=1; i<=CKata.Length; i++)
	{
		bil = bil*10 + CKata.TabKata[i]-'0';
	}
	return bil;
}

Kata switchtoblnk (Kata CKata)
// Mengubah string dengan karakter '_' menjadi ' '
{
	// Kamus Lokal
	int i;
	// Algoritma
	for (i=1; i<=CKata.Length; i++)
	{
		if (CKata.TabKata[i]=='_')
		{
			CKata.TabKata[i]=' ';
		}
	}
	return CKata; 
}

void printKata(Kata CKata)
// I.S. CKata sembarang
// F.S. CKata ditulis ke layar
{
	// Kamus Lokal
	int i;
	// Algoritma
	for (i=1; i<=CKata.Length; i++)
	{
		printf("%c",CKata.TabKata[i]);
	}
}

void fprintKata(Kata CKata)
// I.S. CKata sembarang
// F.S. CKata ditulis ke file eksternal
{
	// Kamus Lokal
	int i;
	// Algoritma
	for (i=1; i<=CKata.Length; i++)
	{
		fprintf(f,"%c",CKata.TabKata[i]);
	}
}

void Katacpy (Kata * CKata, char * str)
// I.S. CKata sembarang
// F.S. Kata yang terdapat pada str disalin ke Kata
{
	// Kamus Lokal
	int istr=0;
	int iKata=1;
	// Algoritma
	
	while ((str[istr]!='\0') && (iKata<=50))
	{
		(*CKata).TabKata[iKata] = str[istr];
		iKata++;
		istr++;
	}
	(*CKata).Length = iKata-1;
}