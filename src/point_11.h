// Definisi ABSTRACT DATA TYPE POINT

#ifndef POINT_H
#define POINT_H

#include "boolean_11.h"

typedef struct
{
	int X; // absis
	int Y; // ordinat
} Point;

// DEFINISI PROTOTIPE PRIMITIF
// ** Konstruktor membentuk Point **
Point MakePoint (int X, int Y);
// Membentuk sebuah Point dari komponen-komponennya

// ** Operasi terhadap komponen : Selektor Get dan Set **
#define Absis(P) (P).X // berfungsi seperti GetAbsis(P)
#define Ordinat(P) (P).Y // berfungsi seperti GetOrdinat(P)

void SetAbsis (Point *P, int newX);
// Mengubah nilai komponen Absis dari P 
void SetOrdinat (Point *P, int newY);
// Mengubah nilai komponen Ordinat dari P 

// ** Destruktor/Dealokator : tidak perlu **

// *** Kelompok Interaksi dengan I/O device, BACA/TULIS ***
void BacaPoint (Point *P);
// MakePoint(x,y) membentuk P dari x dan y yang dibaca
void TulisPoint (Point P);
// Nilai P ditulis ke layar dengan format "(X,Y)"

// Kelompok Operasi Aritmatika terhadap Type
Point tambahPoint(Point P1, Point P2);
// Menghasilkan Point yang bernilai P1+P2 
// Melakukan operasi penjumlahan vektor
Point kurangPoint(Point P1, Point P2);
// Menghasilkan Point yang bernilai P1-P2 
Point kaliPoint(Point P1, Point P2);
// Operasi perkalian P1.P2, melakukan operasi dot product

// ** Kelompok operasi relasional terhadap Point **
bool EQPoint(Point P1, Point P2);
// Mengirimkan true jika P1 = P2 (absis dan ordinatnya sama)
bool NEQPoint(Point P1, Point P2);
// Mengirimkan true jika P1 tidak sama dengan P2 
bool IsSmaller (Point P1, Point P2);
// Mengirimkan true jika P1 lebih kiri-bawah daripada P2 
bool IsGreater (Point P1, Point P2);
// Mengirimkan true jika P1 lebih kanan-atas daripada P2

// ** Kelompok menentukan di mana P berada **
bool IsOrigin (Point P);
// Menghasilkan true jika P adalah titik origin
bool IsOnSbX (Point P);
// Menghasilkan true jika P berada pada sumbu X
bool IsOnSbY (Point P);
// Menghasilkan true jika P berada pada sumbu Y
int Kuadran (Point P);
// Menghasilkan kuadran dari P: 1, 2, 3, atau 4
// Precondition: P bukan titik origin dan P tidak terletak
//				 di salah satu sumbu

// ** Kelompk Operasi Lain terhadap TYPE **
Point NextX (Point P);
// Mengirim salinan P dengan absis ditambah satu
Point NextY (Point P);
// Mengirim salinan P dengan ordinat ditambah satu
Point PlusDelta (Point P, int deltaX, int deltaY);
// Mengirim salinan P yang absisnya Absis(P) + DeltaX dan 
// Ordinatnya adaah Ordinat(P) + DeltaY
Point MirrorOf (Point P, bool SbX, bool SbY);
// Menghasilkan salinan P yang dicerminkan
// tergantung nilai SbX dan SbY 
// Jika SbX bernilai true, maka dicerminkan terhadap sumbu X
// Jika SbY bernilai true, maka dicerminkan terhadap sumbu Y
float Jarak0 (Point P);
// Menghitung jarak P ke (0,0)
void Geser (Point *P, int DeltaX, int DeltaY);
// I.S. P terdefinisi
// F.S. P absis P digeser sebesar DeltaX dan ordinat P digeser
//		sebesar DeltaY 


#endif // POINT_H