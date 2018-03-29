#include "init_11.h"

MATRIKS CurrentMap,Peta1,Peta2,Peta3,Peta4,MatchUp;
Stack S;
Queue Q, StarterQ;
List ListToko,ListTas;
Pemain Player;
char key;

void Initialise()
// Melakukan inisialisasi terhadap semua variabel
// I.S. Semua variabel sembarang
// F.S. Semua variabel terinisialisasi
{
	CreateStack(&S);
	Player.Posisi.X = 6;
	Player.Posisi.Y = 6;
	CurrentMap=Peta1;
	CreateList(&ListTas);
	UangPemain(Player) = 100000;
	AssignLevel();
}