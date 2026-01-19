#pragma once
#include "Hero.h"

class Guerrier : public Hero {
public:
    Guerrier(const std::string& nom, int pvInit, int attaque, int defence, int vitesse)
        : Hero(nom, pvInit, attaque, defence, vitesse) {}

    int getClasse() const override { return 1; }
    int calculerDegats(const Hero& cible) const override;
};
