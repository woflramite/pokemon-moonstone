#ifndef ENCOUNTER_H
#define ENCOUNTER_H

#include "stack_11.h"
#include "queue_11.h"
#include "pokemon_11.h"
#include "list_11.h"
#include "kata_11.h"
#include "boolean_11.h"
#include "point_11.h"

int RandomRange(int batasatas, int batasbawah);
// Menghasilkan nilai dengan batasan tertentu secara random

void Attack(Pokedex P1, Pokedex *P2);
// I.S. Pokemon 1 dan Pokemon 2 belum mati
// F.S. Pokemon 2 mengalami pengurangan HP dengan nilai acak

void InBattle();
// I.S. Stack, Queue tidak kosong. ObtainedEXP sembarang
// F.S. Nilai ObtainedEXP dipilih secara acak

void UseItem();

void Tangkap();

void Kabur();

bool IsSemak();

bool IsMart();
#endif
