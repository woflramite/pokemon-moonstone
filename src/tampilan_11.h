#include "load_11.h"
#include "pemain_11.h"
#include "stack_11.h"
#include "queue_11.h"
#include <stdio.h>

Pemain Player;
Stack S;
Queue Q;

void InfoPemain ();
// Menampilkan informasi Pemain yang meliputi sebagai berikut:
// Nama, daftar Pokemon beserta HP, Uang, EXP, Level, Posisi
// I.S. Sembarang
// F.S. Menampilkan informasi pemain

void MenuUtama();
// Menampilkan menu utama juga menerima input pilihan
// I.S. Sembarang
// F.S. Pilihan user dikerjakan

void TampilTas();
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "N/A" */

void printTabelStack();
// I.S. List tidak mungkin kosong
// F.S. Informasi nama dan HP Pokemon ditampilkan dalam
// 		tabel tersebut

int ndigit(int X);
// Menghasilkan jumlah digit suatu bilangan

void printIsiTas();
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "N/A" */

void TampilToko();
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "N/A" */

void printIsiToko();
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "N/A" */

void TampilBantuan();

void TampilTentang();

void MainMap();

void SwitchPeta();

bool IsGameOver();

void InfoPokemon();

void TampilBattle();

void TampilAbout();

void TampilPause();