#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Jeu.h"
#include "Joueur.h"

int main() {
    // pdf: srand(time(0)) une seule fois
    srand((unsigned)time(0));

    Joueur j1("Joueur1");
    Joueur j2("Joueur2");

    // pdf: 6 héros max
    for (int i = 0; i < 6; i++) j1.ajouterHero(genererHeroAleatoire());
    for (int i = 0; i < 6; i++) j2.ajouterHero(genererHeroAleatoire());

    // pdf: sélectionner jusqu'à 3 héros (ordre fixé)
    j1.selectionnerEquipe();
    j2.selectionnerEquipe();

    // pdf: combat d'équipes
    combatEquipes(j1, j2);

    // nettoyage mémoire (pointeurs)
    j1.libererHeros();
    j2.libererHeros();

    return 0;
}
