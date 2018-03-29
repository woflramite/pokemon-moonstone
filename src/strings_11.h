// PENGOLAHAN KATA

#ifndef STRINGS_H
#define STRINGS_H

#include "kata_11.h"

int Katacmp(Kata Kata1, Kata Kata2);
// Mengembalikan -1 jika Kata1 < Kata2, 0 jika Kata1 = Kata2, dan 1 jika
// Kata1 > Kata 2

int minLen(Kata Kata1, Kata Kata2);
// Mengembalikan nilai terkecil panjang dua kata

int maxLen(Kata Kata1, Kata Kata2);
// Mengembalikan nilai terbesar panjang dua kata

int Katalen(Kata CKata);
// Mengembalikan jumlah huruf pada suatu kata

void scanKata(Kata * CKata);
// I.S. CKata sembarang
// F.S. CKata berisi kata sesuai input user
// Proses: Menerima input menggunakan scanf dan memasukkannya ke dalam CKata.TabKata

int strtoval(Kata CKata);
// Mengubah string "ABC" menjadi integer 100A + 10B + C

Kata switchtoblnk (Kata CKata);
// Mengubah string dengan karakter '_' menjadi ' '

void printKata(Kata CKata);
// I.S. CKata sembarang
// F.S. CKata ditulis ke layar

void fprintKata(Kata CKata);
// I.S. CKata sembarang
// F.S. CKata ditulis ke file eksternal

void Katacpy (Kata * CKata, char * str);
// I.S. CKata sembarang
// F.S. Kata yang terdapat pada str disalin ke Kata

#endif //STRINGS_H