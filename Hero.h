#pragma once
#include <string>

class Hero {
public:
    Hero(const std::string& nom, int pvInit, int attaque, int defence, int vitesse);
    virtual ~Hero() = default;

    // affichage / infos
    void afficherStats() const;

    const std::string& getNom() const;
    int getPV() const;
    int getPVInit() const;
    int getAttaque() const;
    int getDefence() const;
    int getVitesse() const;

    bool estVivant() const;
    void resetPVInitiaux();

    // requis (polymorphisme)
    virtual int getClasse() const = 0;
    virtual int calculerDegats(const Hero& cible) const = 0;

    // requis (pdf)
    virtual void perdrePV(int montant);
    virtual void effetDebutTour(); // optionnel
    virtual void effetFinTour();   // optionnel

protected:
    std::string nom;
    int pv;
    int pvInit;
    int attaque;
    int defence;
    int vitesse;
};
