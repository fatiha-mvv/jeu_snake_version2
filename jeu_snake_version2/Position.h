#pragma once
class Position 
{
private:
    int x, y;  // Coordonn�es sur la grille de jeu

public:
    // Constructeur par d�faut
    Position() : x(0), y(0) {}

    // Constructeur avec des valeurs sp�cifiques
    Position(int x, int y) : x(x), y(y) {}

    // V�rifier si deux positions sont �gales
    bool operator==(const Position& other)const;

    // V�rifier si deux positions sont diff�rentes
    bool operator!=(const Position& other)const;

    // V�rifier si les positions partagent au moins une coordonn�e
    bool ouLogique(const Position& other)const;

    //generer position aleatoire en fonction de parametres renseign�s
    void genererPositionAleatoire(int width, int height);

    // autres fonctions ..
    void changerPosition(Position newOne);
    void deplacerX(int val);
    void deplacerY(int val);
};


