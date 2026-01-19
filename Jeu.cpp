#include "Jeu.h"
#include "Guerrier.h"
#include "Mage.h"
#include "Archer.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>

static int randInRange(int a, int b) { return a + (rand() % (b - a + 1)); }

Hero* genererHeroAleatoire() {
    // stats dans [50,100] en prenant en compte stat principale (pdf)
    int pv  = randInRange(50, 100);
    int att = randInRange(50, 100);
    int def = randInRange(50, 100);
    int vit = randInRange(50, 100);

    int type = randInRange(1, 3); // 1 G, 2 M, 3 A

    auto clamp50_100 = [](int x) { return std::max(50, std::min(100, x)); };

    if (type == 1) {             // Guerrier -> défense
        def = clamp50_100(def + 15);
        return new Guerrier("Guerrier", pv, att, def, vit);
    }
    if (type == 2) {             // Mage -> attaque
        att = clamp50_100(att + 15);
        return new Mage("Mage", pv, att, def, vit);
    }
    // Archer -> vitesse
    vit = clamp50_100(vit + 15);
    return new Archer("Archer", pv, att, def, vit);
}

static void attaquer(Hero* attaquant, Hero* defenseur) {
    // cas Archer: esquive
    if (auto* a = dynamic_cast<Archer*>(defenseur)) {
        if (a->esquive()) {
            std::cout << defenseur->getNom() << " esquive !\n";
            return;
        }
    }

    int dmg = attaquant->calculerDegats(*defenseur);
    defenseur->perdrePV(dmg);

    std::cout << attaquant->getNom() << " inflige " << dmg
              << " -> PV " << defenseur->getNom()
              << ": " << defenseur->getPV() << "/" << defenseur->getPVInit() << "\n";
}

int combat(Hero* h1, Hero* h2) {
    // pdf: commence via vitesse + alternance + effets début/fin + retourne 1/2
    Hero* premier = h1;
    Hero* second  = h2;

    if (h2->getVitesse() > h1->getVitesse()) {
        premier = h2;
        second  = h1;
    }

    std::cout << "\n--- Duel: " << h1->getNom() << " vs " << h2->getNom() << " ---\n";

    while (h1->estVivant() && h2->estVivant()) {
        premier->effetDebutTour();
        attaquer(premier, second);
        premier->effetFinTour();

        if (!second->estVivant()) break;
        std::swap(premier, second);
    }

    int gagnant = h1->estVivant() ? 1 : 2;

    // pdf: le gagnant regagne ses PV initiaux après chaque combat
    if (gagnant == 1) h1->resetPVInitiaux();
    else h2->resetPVInitiaux();

    std::cout << "Vainqueur du duel: " << (gagnant == 1 ? h1->getNom() : h2->getNom()) << "\n";
    return gagnant;
}

int combatEquipes(Joueur& j1, Joueur& j2) {
    // pdf: affrontement des héros sélectionnés dans l’ordre; premier joueur sans vivant perd
    const auto& e1 = j1.getEquipe();
    const auto& e2 = j2.getEquipe();

    int i = 0, j = 0;

    std::cout << "\n=== Combat d'equipes: " << j1.getNom() << " vs " << j2.getNom() << " ===\n";

    while (i < (int)e1.size() && j < (int)e2.size()) {
        Hero* h1 = e1[i];
        Hero* h2 = e2[j];

        if (!h1->estVivant()) { i++; continue; }
        if (!h2->estVivant()) { j++; continue; }

        int res = combat(h1, h2);

        // perdant reste à 0 PV -> on avance son index
        if (res == 1) j++;
        else i++;
    }

    int gagnant = (j >= (int)e2.size()) ? 1 : 2;
    std::cout << "Gagnant de l'affrontement: " << (gagnant == 1 ? j1.getNom() : j2.getNom()) << "\n";
    return gagnant;
}
