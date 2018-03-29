#include "mesinkata_11.h"
#include "mesinkar_11.h"
#include "kata_11.h"
#include <stdio.h>

bool EndKata;
bool EndLine;
Kata CKata;
char CC;
int Pilihan;

void IgnoreBlank()
// Mengabaikan satu atau beberapa BLANK
// I.S. : CC sembarang
// F.S. : CC != BLANK atau CC = MARK
{
	while ((CC==BLANK) && (CC!=MARK))
	{
		ADV();
	}
}

void IgnoreDash()
// Mengabaikan satu atau beberapa DASH
// I.S. : CC sembarang
// F.S. : CC != DASH atau CC = MARK
{
	while ((CC==DASH) && (CC!=MARK))
	{
		ADV();
	}
}

void IgnoreNewLine()
// Mengabaikan satu atau beberapa LF
// I.S. : CC sembarang
// F.S. : CC != LF atau CC = MARK
{
	while ((CC==NEWLINE) && (CC!=MARK))
	{
		if (CC==NEWLINE)
		{
			EndLine=true;
		}
		ADV();
	}
}

void IgnoreGreater()
// Mengabaikan satu atau beberapa >
// I.S. : CC sembarang
// F.S. : CC != > atau CC = MARK
{
	while ((CC=='>') && (CC!=MARK))
	{
		ADV();
	}
}

void STARTKATA(int Pilihan)
// I.S. CC sembarang
// F.S. EndKata = true dan CC = MARK
//		atau EndKata = false, CKata adalah kata yang sudah diakuisisi
//		CC karakter pertama sesudah karakter terakhir kata
{
	START(Pilihan);
	while ((CC==BLANK) || (CC==NEWLINE) || (CC==DASH) || (CC=='>'))
	{
		IgnoreBlank();
		IgnoreNewLine();
		IgnoreDash();
		IgnoreGreater();
	}
	if (CC == MARK)
	{
		EndKata = true;
	}
	else
	{
		EndKata = false;
		SalinKata();
	}
}

void ADVKATA()
// I.S. CC adalah karakter pertama kata yang akan diakuisisi
// F.S. CKata adalah kata terakhir yang sudah diakuisisi,
//		CC adalah karakter pertama kata berikutnya, mungkin MARK
// Proses Akuisisi kata menggunakan procedure SalinKata
{
	int i;
	while ((CC==BLANK) || (CC==NEWLINE) || (CC==DASH) || (CC=='>'))
	{
		IgnoreBlank();
		IgnoreDash();
		IgnoreNewLine();
		IgnoreGreater();
	}
	if (CC == MARK)
	{
		EndKata = true;
	}
	else
	{
		SalinKata();
	}
}

void SalinKata()
// Mengakuisisi kata, menyimpan dalam CKata
// I.S. CC adalah karakter pertama dari kata
// F.S. CKata berisi kata yang sudah diakuisisi;
//		CC = BLANK atau CC = MARK
//		CC adalah karakter sesudah karakter terakhir yang diakuisisi
{
	// Kamus Lokal
	int i = 1;
	// Algoritma
	for (;;)
	{
		CKata.TabKata[i] = CC;
		ADV();
		
		if ((CC == NEWLINE) || (CC == BLANK) || (CC == MARK ) || (CC == DASH) || (CC == '>'))
		{
			if (CC==NEWLINE)
			{
				EndLine = true;
			}
			break;
		}
		else
		{
			i++;
		}
	}
	CKata.Length = i;
}