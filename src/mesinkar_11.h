#ifndef MESINKAR_H
#define MESINKAR_H

#include "boolean_11.h"
#include "kata_11.h"

//******Mesin Karakter dengan asersi dan primitif read******
//** Pita karakter diambil dari file "pitakar.txt"

//Prosedur-prosedur dan fungsi-fungsi

void START(int Pilihan);
//I.S. : sembarang
//F.S. : CC adalah karakter pertama pita
//Jika CC==MARK, EOP menyala (true)
//Jika CC!=MARK, EOP padam (false)

void ADV();
//I.S. : CC!=MARK
//F.S. : CC adalah karakter berikutnya dari CC pada I.S.
//Jika CC==MARK, EOP menyala (true)

bool EOP();
//Menghasilkan true jika CC=MARK

#endif //MESINKAR_H