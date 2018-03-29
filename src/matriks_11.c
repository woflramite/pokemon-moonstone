// Realisasi ABSTRACT DATA TYPE MATRIKS

#include <stdio.h>
#include <stdlib.h>
#include "pemain_11.h"
#include "matriks_11.h"
#include "boolean_11.h"
#include "mesinkata_11.h"

int Pilihan;
Pemain Player;
int i,j,k;

//********** DEFINISI PROTOTIPE PRIMITIF **********
//*** Konstruktor membentuk MATRIKS ***
void MakeMatriks (MATRIKS *M, int NB, int NK)
//Membentuk sebuah MATRIKS "kosong" berukuran NB x NK di "ujung kiri" memori
//I.S. NB dan NK adalah valid untuk memori matriks yang dibuat
//F.S. sebuah matriks sesuai dengan def di atas terbentuk
{
	//Kamus Lokal
	int i,j;
	//Algoritma
	if ((NB<=BrsMax) && (NB>=BrsMin) && (NK<=BrsMax) && (NB>=BrsMin))
	{
		for (i=1; i<=NB; i++)
		{
			for (j=1; j<=NK; j++)
			{
				printf("Isi matriks ke-(%d,%d) : ",i,j);
				scanf("%d",&(*M).Mem[i][j]);
			}
		}
	}
	else
	{
		printf("Masukan jummlah baris atau kolom tidak valid\n");
	}
	(*M).NbrsEff=NB;
	(*M).NkolEff=NK;
}
bool IsIdxValid (indeks i, indeks j)
//Mengirimkan true jika i, j adalah indeks yang valid
{
	return ((i>=BrsMin) && (i<=BrsMax) && (j>=KolMin) && (j<=KolMax));
}

//*** Untuk sebuah matriks M yang terdefinisi: ***
indeks FirstIdxBrs (MATRIKS M)
//Mengirimkan indeks baris terkecil M 
{
	return BrsMin;
}
indeks FirstIdxKol (MATRIKS M)
//Mengirimkan indeks kolom terkecil M 
{
	return KolMin;
}
indeks LastIdxBrs (MATRIKS M)
//Mengirimkan indeks baris terbesar M 
{
	return BrsMin+M.NbrsEff-1;
}
indeks LastIdxKol (MATRIKS M)
//Mengirimkan indeks kolom terbesar M 
{
	return KolMin+M.NkolEff-1;
}
int GetNBrsEff (MATRIKS M)
//Mengirimkan banyaknya baris efektif M 
{
	return M.NbrsEff;
}
int GetNKolEff (MATRIKS M)
//Mengirimkan banyaknya kolom efektif M 
{
	return M.NkolEff;
}
el_type GetElmt (MATRIKS M, indeks i, indeks j)
//Mengirimkan elemen M dengan nomor baris i dan nomor kolom j 
{
	return M.Mem[i][j];
}

//*** Operasi mengubah nilai elemen matriks : Set / Assign ***
void SetBrsEff (MATRIKS *M, int NB)
//I.S. M sudah terdefinisi
//F.S. Nilai M.NBrsEff diisi dengan NB
{
	if ((NB<=BrsMax) && (NB>=BrsMin))
	{
		(*M).NbrsEff=NB;
	}
	else
	{
		printf ("Jumlah baris tidak sesuai\n");
	}
}
void SetKolEff (MATRIKS *M, int NK)
//I.S. M sudah terdefinisi
//F.S. Nilai M.NKolEff
{
	if ((NK<=KolMax) && (NK>=KolMin))
	{
		(*M).NkolEff=NK;
	}
	else
	{
		printf ("Jumlah kolom tidak sesuai\n");
	}
}
void SetEl (MATRIKS *M, int i, int j, el_type X)
//I.S. M sudah terdefinisi
//F.S. M(i,j) bernilai X
//Proses: Mengisi M(i,j) dengan X
{
	if (IsIdxValid(i,j))
	{
		(*M).Mem[i][j]=X;
	}
	else
	{
		printf ("Indeks tidak valid\n");
	}
}

//********** Assignment MATRIKS **********
void AssignMatriks(MATRIKS Min, MATRIKS * MHsl)
//Melakukan assignment MHsl = Min
{
	*MHsl = Min;
}

//********** KELOMPOK BACA/TULIS **********
void BacaMATRIKS (MATRIKS *M, int NB, int NK)
//I.S. IsIdxValid(NB,NK)
//F.S. M terdefinisi nilai elemen efektifnya dan berukuran NB x NK 
//Melakukan MakeMatriks(M,NB,NK) dan mengisi nilai efektifnya 
//dari pembacaan dengan traversal per baris
{
	if (IsIdxValid(NB,NK))
	{
		MakeMatriks(&(*M), NB, NK);
	}
	else
	{
		printf("Masukan jumlah baris atau jumlah kolom salah!\n");
	}
}
void TulisMATRIKS (MATRIKS M)
//I.S. M terdefinisi
//F.S. Sama dengan I.S. dan nilai M(i,j) ditulis ke layar
//Menulis nilai setiap indeks dan elemen M ke layar 
//dengan traversal per baris 
{
	//Kamus Lokal
	int i,j;
	//Algoritma
	for (i=FirstIdxBrs(M); i<=LastIdxBrs(M); i++)
	{
		for (j=FirstIdxKol(M); j<=LastIdxKol(M); j++)
		{
			printf("%.1f ", GetElmt(M,i,j));
		}
		printf("\n");
	}
}

//********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE **********
MATRIKS tambah (MATRIKS M1, MATRIKS M2)
//Prekondisi: M1 berukuran sama dengan M2 
//Mengirim hasil penjumlahan matriks: M1 + M2
{
	//Kamus Lokal
	int i,j;
	MATRIKS MHsl;
	//Algoritma
	if (EQSize(M1,M2))
	{
		for (i=FirstIdxBrs(M1); i<=LastIdxBrs(M1); i++)
		{
			for (j=FirstIdxKol(M1); j<=LastIdxKol(M1); j++)
			{
				MHsl.Mem[i][j] = M1.Mem[i][j]+M2.Mem[i][j];
			}
		}
		MHsl.NbrsEff = M1.NbrsEff;
		MHsl.NkolEff = M1.NkolEff;
	}
	return MHsl;
}

MATRIKS kurang (MATRIKS M1, MATRIKS M2)
//Prekondisi: M1 berukuran sama dengan M2 
//Mengirim hasil pengurangan matriks: M1 - M2
{
	//Kamus Lokal
	int i,j;
	MATRIKS MHsl;
	//Algoritma
	if (EQSize(M1,M2))
	{
		for (i=FirstIdxBrs(M1); i<=LastIdxBrs(M1); i++)
		{
			for (j=FirstIdxKol(M1); j<=LastIdxKol(M1); j++)
			{
				MHsl.Mem[i][j] = M1.Mem[i][j]-M2.Mem[i][j];
			}
		}
		MHsl.NbrsEff = M1.NbrsEff;
		MHsl.NkolEff = M1.NkolEff;
	}
	return MHsl;
}

MATRIKS dotproduct (MATRIKS M1, MATRIKS M2)
//Prekondisi : Ukuran baris efektif M2 = ukuran kolom efektif M1 
//Mengirim hasil perkalian matriks: salinan M1 . M2 
{
	//Kamus Lokal
	int i,j;
	MATRIKS MHsl;
	//Algoritma
	if (EQSize(M1,M2))
	{
		for (i=FirstIdxBrs(M1); i<=LastIdxBrs(M1); i++)
		{
			for (j=FirstIdxKol(M1); j<=LastIdxKol(M1); j++)
			{
				MHsl.Mem[i][j] = M1.Mem[i][j]*M2.Mem[i][j];
			}
		}
		MHsl.NbrsEff = M1.NbrsEff;
		MHsl.NkolEff = M1.NkolEff;
	}
	return MHsl;
}

MATRIKS crossproduct (MATRIKS M1, MATRIKS M2)
//Prekondisi: Ukuran baris efektif M2 = ukuran kolom efektif M1
//Mengirim hasil perkalian matriks: salinan M1 * M2
{
	//Kamus Lokal
	MATRIKS MHasil;
	int i,j,k;
	//Algoritma
	for (i=FirstIdxBrs(M1); i<=LastIdxBrs(M1); i++)
	{
		for (j=FirstIdxKol(M2); j<=LastIdxKol(M2); j++)
		{
			MHasil.Mem[i][j]=0;
			for (k=FirstIdxKol(M1); k<=LastIdxKol(M1); k++)
			{
				MHasil.Mem[i][j]=MHasil.Mem[i][j]+M1.Mem[i][k]*M2.Mem[k][j];
			}
		}
	}
	MHasil.NbrsEff=GetNBrsEff(M1);
	MHasil.NkolEff=GetNKolEff(M2);
	return MHasil;
}

MATRIKS factorproduct (MATRIKS M1, int K)
//Mengalikan setiap elemen M dengan K
{
	//Kamus Lokal
	int i,j;
	MATRIKS MHsl;
	//Algoritma
	for (i=FirstIdxBrs(M1); i<=LastIdxBrs(M1); i++)
	{
		for (j=FirstIdxKol(M1); j<=LastIdxKol(M1); j++)
		{
			MHsl.Mem[i][j]=K*M1.Mem[i][j];
		}
	}
	MHsl.NbrsEff=GetNBrsEff(M1);
	MHsl.NkolEff=GetNKolEff(M1);
	return MHsl;
}

//********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS **********
bool IsEqual (MATRIKS M1, MATRIKS M2)
//Mengirimkan true jika M1 = M2 
//yaitu NBElmt(M1)=NBElmt(M2) dan 
//untuk setiap i,j yang merupakan indeks baris dan kolom 
//M1(i,j) = M2(i,j)
{
	//Kamus Lokal
	int i,j,err;
	//Algoritma
	err=0;
	if (GetNBrsEff(M1)==GetNBrsEff(M2) && (GetNKolEff(M1)==GetNKolEff(M2)))
	{
		for (i=FirstIdxBrs(M1); i<=LastIdxBrs(M1); i++)
		{
			for (j=FirstIdxKol(M1); j<=LastIdxKol(M1); j++)
			{
				if (GetElmt(M1,i,j)!=GetElmt(M2,i,j))
				{
					err++;
				}
			}
		}
		if (err>0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

bool IsStrongEQ (MATRIKS M1, MATRIKS M2)
//Mengirimkan true jika M1 "strongly equal" M2
//yaitu FirstIdx(M1) == FirstIdx(M2) dan LastIdx(M1) == LastIdx(M2) dan
//untuk setiap i,j yang merupakan indeks baris dan kolom 
//M1(i,j) = M2(i,j)
{
	//Kamus Lokal
	bool FirstIdx, LastIdx;
	//Algoritma
	FirstIdx = ((FirstIdxBrs(M1)==FirstIdxBrs(M2)) && (FirstIdxKol(M1)==FirstIdxKol(M2)));
	LastIdx = ((LastIdxBrs(M1)==LastIdxBrs(M2)) && (LastIdxKol(M1)==LastIdxKol(M2)));
	return (IsEqual(M1,M2) && FirstIdx && LastIdx);
}

bool NEQ (MATRIKS M1, MATRIKS M2)
//Mengirimkan true jika not strongEQ(M1,M2)
{
	return (!IsStrongEQ(M1,M2));
}

bool EQSize (MATRIKS M1, MATRIKS M2)
//Mengirimkan true jika ukuran efektiff matriks M1 sama dengan ukuran
//efektif M2
//yaitu GetNBrsEff(M1) = GetNBrsEff(M2) dan GetNKolEff(M1) = GetNKolEff(M2)
{
	return ((GetNBrsEff(M1) == GetNBrsEff(M2)) && (GetNKolEff(M1) == GetNKolEff(M2)));
}

//********** KELOMPOK TEST TERHADAP MATRIKS **********
bool IsIdentitas (MATRIKS M)
//Mengirimkan true jika M adalah matriks satuan: dimana ukuran baris dan kolom sama
//dan setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0
{
	//Kamus Lokal
	int i,j,err;
	//Algoritma
	if (GetNBrsEff(M)==GetNKolEff(M))
	{
		err=0;
		for (i=FirstIdxBrs(M); i<=LastIdxBrs(M); i++)
		{
			for (j=FirstIdxKol(M); j<=LastIdxKol(M);j++)
			{
				if ((i==j) && (GetElmt(M,i,j)!=1))
				{
					err++;
				}
				else
				if ((i!=j) && (GetElmt(M,i,j)!=0))
				{
					err++;
				}
			}
		}
		if (err>0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

// ********** ALGORITMA LOAD **********

void LoadPeta(MATRIKS * M, int Peta)
// Mengisi matriks untuk peta
// I.S. Matriks M sembarang
// F.S. Matriks M berisi mapping peta
{
	// Kamus Lokal
	int i = 1;
	int j = 1;

	// Algoritma
	STARTKATA(Peta);
	while (!EndKata)
	{
		j = 1;
		EndLine = false;
		while (!EndLine)
		{
			(*M).Mem[i][j] = CKata.TabKata[1]-'A';
			j++;
			ADVKATA();
			if (EndLine)
			{
				(*M).Mem[i][j] = CKata.TabKata[1]-'A';
			}
		}
		i++;
		ADVKATA();
	}
	(*M).NbrsEff = i-1;
	(*M).NkolEff = j;
}

void LoadMatchup(MATRIKS * M)
// Mengisi matriks untuk matchup
// I.S. Matriks M sembarang
// F.S. Matriks M berisi matchup type
{
	// Kamus Lokal
	int i = 1;
	int k;
	int j;
	
	STARTKATA(2);
	while (!EndKata)
	{
		j=1;
		EndLine = false;
		while (!EndLine)
		{
			if ((CKata.TabKata[1]=='1') || (CKata.TabKata[1]=='2'))
			{
				(*M).Mem[i][j] = CKata.TabKata[1]-'0';
			}
			else
			{
				(*M).Mem[i][j] = 0.5;
			}
			j++;
			ADVKATA();
			if (EndLine)
			{
				if ((CKata.TabKata[1]=='1') || (CKata.TabKata[1]=='2'))
				{
					(*M).Mem[i][j] = CKata.TabKata[1]-'0';
				}
				else
				{
					(*M).Mem[i][j] = 0.5;
				}
			}
		}
		i++;
		ADVKATA();
	}
	(*M).NbrsEff = i-1;
	(*M).NkolEff = j;
}

void PrintPeta(MATRIKS Peta)
// Menampilkan peta
// I.S. Matriks Peta sembarang
// F.S. Peta ditampilkan
{
	for (i=1; i<=Peta.NbrsEff; i++)
	{
		for (k=1; k<=4; k++)
		{
			for (j=1; j<=Peta.NkolEff; j++)
			{
				GambarKarakter(Peta.Mem[i][j]);
				GambarKarakter(Peta.Mem[i][j]);
				GambarKarakter(Peta.Mem[i][j]);
				GambarKarakter(Peta.Mem[i][j]);
				GambarKarakter(Peta.Mem[i][j]);
				GambarKarakter(Peta.Mem[i][j]);
			}
			printf("\n");
		}
	}
}

void GambarKarakter(float P)
// Menggambar karater
// I.S. P kemungkinan nilai ASCII R,S,M,X,J
// F.S. P dicetak sebagai gambar tertentu
{
	if ((Player.Posisi.X == j) && (Player.Posisi.Y == i))
	{
		printf("O");
	}
	else
	if (P == 9)
	{
		printf("%c",219);
	}
	else if (P == 18)
	{
		printf("%c",176);
	}
	else if (P == 17)
	{
		printf("%c",177);
	}
	else if (P == 12)
	{
		printf("#");
	}
	else if (P == 23)
	{
		printf("%c",219);
	}
	else
	{
		printf("%c",177);
	}
}