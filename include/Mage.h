#pragma once
#include "Hero.h"

class Mage : public Hero {
public:
    Mage(const std::string& nom, int pvInit, int attaque, int defence, int vitesse)
        : Hero(nom, pvInit, attaque, defence, vitesse) {}

    int getClasse() const override { return 2; }
    int calculerDegats(const Hero& cible) const override;
};
