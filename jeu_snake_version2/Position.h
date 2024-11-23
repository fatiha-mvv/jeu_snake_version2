#pragma once
class Position 
{
private:
    int x, y;  // Coordonnées sur la grille de jeu

public:
    // Constructeur par défaut
    Position() : x(0), y(0) {}

    // Constructeur avec des valeurs spécifiques
    Position(int x, int y) : x(x), y(y) {}

    // Vérifier si deux positions sont égales
    bool operator==(const Position& other)const;

    // Vérifier si deux positions sont différentes
    bool operator!=(const Position& other)const;

    // Vérifier si les positions partagent au moins une coordonnée
    bool ouLogique(const Position& other)const;

    //generer position aleatoire en fonction de parametres renseignés
    void genererPositionAleatoire(int width, int height);

    // autres fonctions ..
    void changerPosition(Position newOne);
    void deplacerX(int val);
    void deplacerY(int val);
};


