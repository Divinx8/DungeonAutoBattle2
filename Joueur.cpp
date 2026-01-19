#include "Joueur.h"
#include <iostream>

Joueur::Joueur(const std::string& nom_) : nom(nom_) {}

const std::string& Joueur::getNom() const { return nom; }

bool Joueur::ajouterHero(Hero* h) {
    if (!h) return false;
    if ((int)roster.size() >= 6) return false;
    roster.push_back(h);
    return true;
}

void Joueur::afficherRoster() const {
    std::cout << "Roster de " << nom << ":\n";
    for (int i = 0; i < (int)roster.size(); i++) {
        std::cout << "  [" << i << "] ";
        roster[i]->afficherStats();
    }
}

void Joueur::selectionnerEquipe() {
    equipe.clear();
    std::cout << "\nSelection equipe (max 3) pour " << nom << "\n";
    afficherRoster();

    while ((int)equipe.size() < 3) {
        std::cout << "Choisir index hero (0.."<< (int)roster.size()-1 << ") ou -1 pour finir: ";
        int idx;
        std::cin >> idx;

        if (idx == -1) break;
        if (idx < 0 || idx >= (int)roster.size()) {
            std::cout << "Index invalide.\n";
            continue;
        }

        // éviter doublons
        bool deja = false;
        for (Hero* h : equipe) if (h == roster[idx]) deja = true;
        if (deja) {
            std::cout << "Deja selectionne.\n";
            continue;
        }

        equipe.push_back(roster[idx]);
        std::cout << "Ajoute: " << roster[idx]->getNom() << "\n";
    }

    std::cout << "Equipe finale (" << equipe.size() << "):\n";
    for (Hero* h : equipe) {
        std::cout << "  - ";
        h->afficherStats();
    }
}

const std::vector<Hero*>& Joueur::getEquipe() const { return equipe; }

void Joueur::libererHeros() {
    for (Hero* h : roster) delete h;
    roster.clear();
    equipe.clear();
}
