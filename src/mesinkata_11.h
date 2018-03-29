#include "mesinkar_11.h"
#include "matriks_11.h"

#ifndef MESINKATA_H
#define MESINKATA_H

#include "boolean_11.h"
#include "kata_11.h"

extern bool EndKata;
extern bool EndLine;
extern Kata CKata;
extern int i,j;
extern int Pilihan;

void IgnoreBlank();
// Mengabaikan satu atau beberapa BLANK
// I.S. : CC sembarang
// F.S. : CC != BLANK atau CC = MARK

void IgnoreDash();
// Mengabaikan satu atau beberapa DASH
// I.S. : CC sembarang
// F.S. : CC != DASH atau CC = MARK

void IgnoreNewLine();
// Mengabaikan satu atau beberapa LF
// I.S. : CC sembarang
// F.S. : CC != LF atau CC = MARK

void IgnoreGreater();
// Mengabaikan satu atau beberapa >
// I.S. : CC sembarang
// F.S. : CC != LF atau CC = MARK

void STARTKATA(int Pilihan);
// I.S. CC sembarang
// F.S. EndKata = true dan CC = MARK
//		atau EndKata = false, CKata adalah kata yang sudah diakuisisi
//		CC karakter pertama sesudah karakter terakhir kata

void ADVKATA();
// I.S. CC adalah karakter pertama kata yang akan diakuisisi
// F.S. CKata adalah kata terakhir yang sudah diakuisisi,
//		CC adalah karakter pertama kata berikutnya, mungkin MARK
// Proses Akuisisi kata menggunakan procedure SalinKata

void SalinKata();
// Mengakuisisi kata, menyimpan dalam CKata
// I.S. CC adalah karakter pertama dari kata
// F.S. CKata berisi kata yang sudah diakuisisi;
//		CC = BLANK atau CC = MARK
//		CC adalah karakter sesudah karakter terakhir yang diakuisisi

#endif //MESINKATA_H