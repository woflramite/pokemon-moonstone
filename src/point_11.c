// Realisasi ABSTRACT DATA TYPE POINT

#include <stdio.h>
#include <math.h>
#include "point_11.h"

// DEFINISI PROTOTIPE PRIMITIF
// ** Konstruktor membentuk Point **
Point MakePoint (int X, int Y)
// Membentuk sebuah Point dari komponen-komponennya
{
	// Kamus Lokal
	Point P;
	// Algoritma
	Absis(P) = X;
	Ordinat(P) = Y;
	return P;
}

// ** Operasi terhadap komponen : Selektor Get dan Set **
void SetAbsis (Point *P, int newX)
// Mengubah nilai komponen Absis dari P 
{
	Absis(*P) = newX;
}
void SetOrdinat (Point *P, int newY)
// Mengubah nilai komponen Ordinat dari P 
{
	Ordinat(*P) = newY;
}

// ** Destruktor/Dealokator : tidak perlu **

// *** Kelompok Interaksi dengan I/O device, BACA/TULIS ***
void BacaPoint (Point *P)
// MakePoint(x,y) membentuk P dari x dan y yang dibaca
{
	// Kamus Lokal
	int X,Y;
	// Algoritma
	printf("X:");
	scanf("%d",&X);
	printf("Y:");
	scanf("%d",&Y);
	*P = MakePoint(X,Y);
}
void TulisPoint (Point P)
// Nilai P ditulis ke layar dengan format "(X,Y)"
{
	printf("(%d,%d)", Absis(P), Ordinat(P));
}

// Kelompok Operasi Aritmatika terhadap Type
Point tambahPoint(Point P1, Point P2)
// Menghasilkan Point yang bernilai P1+P2 
// Melakukan operasi penjumlahan vektor
{
	// Kamus Lokal
	Point P;
	// Algoritma
	Absis(P) = Absis(P1) + Absis(P2);
	Ordinat(P) = Ordinat(P1) + Ordinat(P2);
	return P;
}
Point kurangPoint(Point P1, Point P2)
// Menghasilkan Point yang bernilai P1-P2 
{
	// Kamus Lokal
	Point P;
	// Algoritma
	Absis(P) = Absis(P1) - Absis(P2);
	Ordinat(P) = Ordinat(P1) - Ordinat(P2);
	return P;
}
Point kaliPoint(Point P1, Point P2)
// Operasi perkalian P1.P2, melakukan operasi dot product
{
	// Kamus Lokal
	Point P;
	// Algoritma
	Absis(P) = Absis(P1) * Absis(P2);
	Ordinat(P) = Ordinat(P1) * Ordinat(P2);
	return P;
}

// ** Kelompok operasi relasional terhadap Point **
bool EQPoint(Point P1, Point P2)
// Mengirimkan true jika P1 = P2 (absis dan ordinatnya sama)
{
	return ((Absis(P1)==Absis(P2)) && (Ordinat(P1)==Ordinat(P2)));
}
bool NEQPoint(Point P1, Point P2)
// Mengirimkan true jika P1 tidak sama dengan P2 
{
	return (!(EQPoint(P1,P2)));
}
bool IsSmaller (Point P1, Point P2)
// Mengirimkan true jika P1 lebih kiri-bawah daripada P2 
{
	return ((Absis(P1)<Absis(P2)) || (Ordinat(P1)<Ordinat(P2)));
}
bool IsGreater (Point P1, Point P2)
// Mengirimkan true jika P1 lebih kanan-atas daripada P2
{
	return ((!IsGreater(P1,P2)) && (!EQPoint(P1,P2)));
}

// ** Kelompok menentukan di mana P berada **
bool IsOrigin (Point P)
{
	return (IsOnSbX(P) && IsOnSbY(P));
}
// Menghasilkan true jika P adalah titik origin
bool IsOnSbX (Point P)
{
	return (Absis(P)==0);
}
// Menghasilkan true jika P berada pada sumbu X
bool IsOnSbY (Point P)
{
	return (Ordinat(P)==0);
}
// Menghasilkan true jika P berada pada sumbu Y
int Kuadran (Point P)
// Menghasilkan kuadran dari P: 1, 2, 3, atau 4
// Precondition: P bukan titik origin dan P tidak terletak
//				 di salah satu sumbu
{
	if (!IsOnSbX(P) && !IsOnSbY(P))
	{
		if ((Absis(P)>0) && (Ordinat(P)>0))
		{
			return 1;
		}
		else
		if ((Absis(P)<0) && (Ordinat(P)>0))
		{
			return 2;
		}
		else
		if ((Absis(P)<0) && (Ordinat(P)<0))
		{
			return 3;
		}
		else 
		if ((Absis(P)>0) && (Ordinat(P)<0))
		{
			return 4;
		}
	}
	else
	{
		return false;
	}
}

// ** Kelompk Operasi Lain terhadap TYPE **
Point NextX (Point P)
// Mengirim salinan P dengan absis ditambahPoint satu
{
	Absis(P)++;
}
Point NextY (Point P)
// Mengirim salinan P dengan ordinat ditambahPoint satu
{
	Ordinat(P)++;
}
Point PlusDelta (Point P, int deltaX, int deltaY)
// Mengirim salinan P yang absisnya Absis(P) + DeltaX dan 
// Ordinatnya adaah Ordinat(P) + DeltaY
{
	// Kamus Lokal
	Point hasil;
	// Algoritma
	Absis(hasil) = Absis(P) + deltaX;
	Ordinat(hasil) = Ordinat(hasil) + deltaY;
	return hasil;
}
Point MirrorOf (Point P, bool SbX, bool SbY)
// Menghasilkan salinan P yang dicerminkan
// tergantung nilai SbX dan SbY 
// Jika SbX bernilai true, maka dicerminkan terhadap sumbu X
// Jika SbY bernilai true, maka dicerminkan terhadap sumbu Y
{
	if (SbX)
	{
		Absis(P) = -Absis(P);
	}
	if (SbY)
	{
		Ordinat(P) = -Ordinat(P);
	}
	return P;
}
float Jarak0 (Point P)
// Menghitung jarak P ke (0,0)
{
	return sqrt(Absis(P)*Absis(P) + Ordinat(P)*Ordinat(P));
}
void Geser (Point *P, int DeltaX, int DeltaY)
// I.S. P terdefinisi
// F.S. P absis P digeser sebesar DeltaX dan ordinat P digeser
//		sebesar DeltaY 
{
	*P = PlusDelta(*P, DeltaX, DeltaY);
}