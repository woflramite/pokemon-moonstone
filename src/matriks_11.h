// Definisi ABSTRACT DATA TYPE MATRIKS

#ifndef MATRIKS_H
#define MATRIKS_H

#include "boolean_11.h"
//Definisi ABSTRACT DATA TYPE MATRIKS
//************ Definisi TYPE MATRIKS dengan indeks integer ************
#define BrsMin 1
#define BrsMax 100
#define KolMin 1
#define KolMax 100

typedef int indeks;
typedef float el_type;

typedef struct
{
	el_type Mem [BrsMax+1][KolMax+1];
	int NbrsEff;
	int NkolEff;
} MATRIKS;

int i,j;

//********** DEFINISI PROTOTIPE PRIMITIF **********
//*** Konstruktor membentuk MATRIKS ***
void MakeMatriks (MATRIKS *M, int NB, int NK);
//Membentuk sebuah MATRIKS "kosong" berukuran NB x NK di "ujung kiri" memori
//I.S. NB dan NK adalah valid untuk memori matriks yang dibuat
//F.S. sebuah matriks sesuai dengan def di atas terbentuk
bool IsIdxValid (indeks i, indeks j);
//Mengirimkan true jika i, j adalah indeks yang valid

//*** Untuk sebuah matriks M yang terdefinisi: ***
indeks FirstIdxBrs (MATRIKS M);
//Mengirimkan indeks baris terkecil M 
indeks FirstIdxKol (MATRIKS M);
//Mengirimkan indeks kolom terkecil M 
indeks LastIdxBrs (MATRIKS M);
//Mengirimkan indeks baris terbesar M 
indeks LastIdxKol (MATRIKS M);
//Mengirimkan indeks kolom terbesar M 
int GetNBrsEff (MATRIKS M);
//Mengirimkan banyaknya baris efektif M 
int GetNKolEff (MATRIKS M);
//Mengirimkan banyaknya kolom efektif M 
el_type GetElmt (MATRIKS M, indeks i, indeks j);
//Mengirimkan elemen M dengan nomor baris i dan nomor kolom j 

//*** Operasi mengubah nilai elemen matriks : Set / Assign ***
void SetBrsEff (MATRIKS *M, int NB);
//I.S. M sudah terdefinisi
//F.S. Nilai M.NBrsEff diisi dengan NB
void SetKolEff (MATRIKS *M, int NK);
//I.S. M sudah terdefinisi
//F.S. Nilai M.NKolEff
void SetEl (MATRIKS *M, int i, int j, el_type X);
//I.S. M sudah terdefinisi
//F.S. M(i,j) bernilai X
//Proses: Mengisi M(i,j) dengan X

//********** Assignment MATRIKS **********
void AssignMatriks(MATRIKS Min, MATRIKS * MHsl);
//Melakukan assignment MHsl = Min

//********** KELOMPOK BACA/TULIS **********
void BacaMATRIKS (MATRIKS *M, int NB, int NK);
//I.S. IsIdxValid(NB,NK)
//F.S. M terdefinisi nilai elemen efektifnya dan berukuran NB x NK 
//Melakukan MakeMatriks(M,NB,NK) dan mengisi nilai efektifnya 
//dari pembacaan dengan traversal per baris 
void TulisMATRIKS (MATRIKS M);
//I.S. M terdefinisi
//F.S. Sama dengan I.S. dan nilai M(i,j) ditulis ke layar
//Menulis nilai setiap indeks dan elemen M ke layar 
//dengan traversal per baris 

//********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE **********
MATRIKS tambah (MATRIKS M1, MATRIKS M2);
//Prekondisi: M1 berukuran sama dengan M2 
//Mengirim hasil penjumlahan matriks: M1 + M2

MATRIKS kurang (MATRIKS M1, MATRIKS M2);
//Prekondisi: M1 berukuran sama dengan M2 
//Mengirim hasil pengurangan matriks: M1 - M2 

MATRIKS dotproduct (MATRIKS M1, MATRIKS M2);
//Prekondisi: Ukuran baris efektif M2 = ukuran kolom efektif M1 
//Mengirim hasil perkalian matriks: salinan M1 . M2 

MATRIKS crossproduct (MATRIKS M1, MATRIKS M2);
//Prekondisi: Ukuran baris efektif M2 = ukuran kolom efektif M1
//Mengirim hasil perkalian matriks: salinan M1 * M2

MATRIKS factorproduct (MATRIKS M1, int K);
//Mengalikan setiap elemen M dengan K

//********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS **********
bool IsEqual (MATRIKS M1, MATRIKS M2);
//Mengirimkan true jika M1 = M2 
//yaitu NBElmt(M1)=NBElmt(M2) dan 
//untuk setiap i,j yang merupakan indeks baris dan kolom 
//M1(i,j) = M2(i,j)

bool IsStrongEQ (MATRIKS M1, MATRIKS M2);
//Mengirimkan true jika M1 "strongly equal" M2
//yaitu FirstIdx(M1) == FirstIdx(M2) dan LastIdx(M1) == LastIdx(M2) dan
//untuk setiap i,j yang merupakan indeks baris dan kolom 
//M1(i,j) = M2(i,j)

bool NEQ (MATRIKS M1, MATRIKS M2);
//Mengirimkan true jika not strongEQ(M1,M2)

bool EQSize (MATRIKS M1, MATRIKS M2);
//Mengirimkan true jika ukuran efektiff matriks M1 sama dengan ukuran
//efektif M2
//yaitu GetNBrsEff(M1) = GetNBrsEff(M2) dan GetNKolEff(M1) = GetNKolEff(M2)

//********** KELOMPOK TEST TERHADAP MATRIKS **********
bool IsIdentitas (MATRIKS M);
//Mengirimkan true jika M adalah matriks satuan: dimana ukuran baris dan kolom sama
//dan setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0

//********** ALGORITMA LOAD **********

void LoadPeta(MATRIKS * M, int Peta);
// Mengisi matriks untuk peta
// I.S. Matriks M sembarang
// F.S. Matriks M berisi mapping peta

void LoadMatchup(MATRIKS * M);
// Mengisi matriks untuk matchup
// I.S. Matriks M sembarang
// F.S. Matriks M berisi matchup type

void PrintPeta(MATRIKS Peta);
// Menampilkan peta
// I.S. Matriks Peta sembarang
// F.S. Peta ditampilkan

void GambarKarakter(float P);
// Menggambar karater
// I.S. P kemungkinan nilai ASCII R,S,M,X,J
// F.S. P dicetak sebagai gambar tertentu

#endif

