#include "Hero.h"
#include <iostream>
#include <algorithm>

Hero::Hero(const std::string& nom_, int pvInit_, int attaque_, int defence_, int vitesse_)
    : nom(nom_), pv(pvInit_), pvInit(pvInit_), attaque(attaque_), defence(defence_), vitesse(vitesse_) {
      // Garantit des points de vie initiaux valides (au moins 1)
    pvInit = std::max(1, pvInit);
    pv = pvInit;

    // Garantit des statistiques cohérentes
    attaque = std::max(1, attaque);
    defence = std::max(0, defence);
    vitesse = std::max(0, vitesse);
}

void Hero::afficherStats() const {
// Affichage formaté des statistiques actuelles du héros
    std::cout << nom
              << " | PV: " << pv << "/" << pvInit
              << " | ATK: " << attaque
              << " | DEF: " << defence
              << " | VIT: " << vitesse
              << "\n";
}

// Accesseurs simples (getters)

const std::string& Hero::getNom() const { return nom; }
int Hero::getPV() const { return pv; }
int Hero::getPVInit() const { return pvInit; }
int Hero::getAttaque() const { return attaque; }
int Hero::getDefence() const { return defence; }
int Hero::getVitesse() const { return vitesse; }

bool Hero::estVivant() const { return pv > 0; }

void Hero::resetPVInitiaux() { pv = pvInit; }

void Hero::perdrePV(int montant) {
    montant = std::max(0, montant);
    pv = std::max(0, pv - montant);
}

void Hero::effetDebutTour() {}
void Hero::effetFinTour() {}
