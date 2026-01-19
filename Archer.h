#pragma once
#include "Hero.h"

class Archer : public Hero {
public:
    Archer(const std::string& nom, int pvInit, int attaque, int defence, int vitesse)
        : Hero(nom, pvInit, attaque, defence, vitesse) {}

    int getClasse() const override { return 3; }

    bool esquive() const;
    int calculerDegats(const Hero& cible) const override;
};
