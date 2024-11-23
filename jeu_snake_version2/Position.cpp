#include "Position.h"
#include <cstdlib> // Pour rand() et srand()
#include <ctime>   // Pour initialiser srand()


////---------> Vérifier si deux positions sont égales
bool Position::operator==(const Position& other) const 
{
    return x == other.x && y == other.y;
}

////---------> Vérifier si deux positions sont différentes
bool Position::operator!=(const Position& other) const 
{
    return !(*this == other);
}


////---------> Vérifier si les positions partagent au moins une coordonnée
bool Position::ouLogique(const Position& other) const 
{
    return x == other.x || y == other.y;
}


////---------> generer une position aleatoire en fct de width et height fournis
 void Position::genererPositionAleatoire(int width, int height)
{
     this->x = rand() % (width - 2) + 1;
     this->y = rand() % (height - 2) + 1;
}


////---------> pour mettre a jour une position donnee
void Position::changerPosition(Position newOne)
{
    this->x = newOne.x;
    this->y = newOne.y;
}


////---------> pour translater le x par une valeur
void Position::deplacerX(int val)
{
    this->x = this->x + val;
}


////---------> pour translater le y par une valeur
void Position::deplacerY(int val)
{
    this->y = this->y + val;
}
