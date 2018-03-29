#ifndef LOAD_H
#define LOAD_H

#include "matriks_11.h"
#include "queue_11.h"
#include "list_11.h"
#include "stack_11.h"
#include "pemain_11.h"
#include "point_11.h"
#include "pemain_11.h"

#define PetaA 11
#define PetaB 12
#define PetaC 13
#define PetaD 14

void Load();
// Melakukan loading semua file eksternal
// I.S. Sembarang
// F.S. List, matriks, queue menjadi terisi sesuai *.txt

void Save();

void LoadPlayer();

void fprintPokemon(Pokedex X);

void fprintItem(Item X);


#endif // LOAD_H