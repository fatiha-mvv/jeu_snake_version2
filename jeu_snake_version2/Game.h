#pragma once
#include "Joueur.h"
#include "HistoryGame.h"

class Game
{
private:
    Joueur joueur;  // Le joueur de game
    HistoryGame historique;  // Historique de game
public:
    //constructeur de Game
    Game(const std::string& nomJoueur, const std::string& nomFichierHistorique);

    // fonction pour dessiner le terrain de jeu
    void draw(const Snake& snake, const Position& food, int width, int height);

    //juste pour l'affichage et l'esthetique de jeu
    static void afficherCadre();
    static void afficherCentre(const std::string& texte);
    static  void afficherFinCadre();
    static void afficherIntroduction();
};




