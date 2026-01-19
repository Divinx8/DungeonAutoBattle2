#pragma once
#include "Hero.h"
#include "Joueur.h"

// Fonctions non membres demandées
Hero* genererHeroAleatoire();
int combat(Hero* h1, Hero* h2);
int combatEquipes(Joueur& j1, Joueur& j2);
