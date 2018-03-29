#ifndef POKEMON_H
#define POKEMON_H
#include "kata_11.h"

typedef struct {
	Kata nama;
	int tipe;
	Kata tipeKata;
	int HP;
	int HPMax;
	int bawahattack;
	int atasattack;
	int bawahexp;
	int atasexp;
	int bawahmoney;
	int atasmoney;
	int catchrate;
} Pokedex;

#endif // POKEMON_H