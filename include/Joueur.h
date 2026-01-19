#pragma once
#include <string>
#include <vector>
#include "Hero.h"

class Joueur {
public:
    explicit Joueur(const std::string& nom);

    const std::string& getNom() const;

    bool ajouterHero(Hero* h);                 // max 6
    void afficherRoster() const;

    void selectionnerEquipe();                 // choisir jusqu'à 3 héros
    const std::vector<Hero*>& getEquipe() const;

    void libererHeros();                       // delete de tous les héros (fin de programme)

private:
    std::string nom;
    std::vector<Hero*> roster;                 // 6 max
    std::vector<Hero*> equipe;                 // 3 max (pointeurs vers roster)
};
