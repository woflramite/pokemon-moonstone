#ifndef PEMAIN_H
#define PEMAIN_H

#include "kata_11.h"
#include "stack_11.h"
#include "point_11.h"

typedef struct
{
	int NoTingkat;
	long minEXP;
} Tingkat;

typedef struct
{
	Kata Nama;
	Stack Party;
	long Uang;
	long EXP;
	Tingkat Level;
	Point Posisi;
} Pemain;

typedef struct 
{
	Tingkat T[20];
	int Neff;
} ArrayTingkat;

#define NamaPemain(P) (P).Nama
#define UangPemain(P) (P).Uang
#define EXPPemain(P) (P).EXP
#define LevelPemain(P) (P).Level.NoTingkat
#define PosisiPemain(P) (P).Posisi
#define Tab(A) (A).T
#define Neff(A) (A).Neff
#define MinEXP(A,i) (A).T[i].minEXP

void LoadArrayTingkat (ArrayTingkat * A);

void AssignLevel ();

bool IsLevelUp();

void AskIdentity();

void LoadGame();

void PrintArray();
#endif // PEMAIN_H