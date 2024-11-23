#include "Position.h"
#include <cstdlib> // Pour rand() et srand()
#include <ctime>   // Pour initialiser srand()


////---------> V�rifier si deux positions sont �gales
bool Position::operator==(const Position& other) const 
{
    return x == other.x && y == other.y;
}

////---------> V�rifier si deux positions sont diff�rentes
bool Position::operator!=(const Position& other) const 
{
    return !(*this == other);
}


////---------> V�rifier si les positions partagent au moins une coordonn�e
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
