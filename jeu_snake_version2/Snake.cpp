#include "Snake.h"
#include <iostream>
#include <vector>
#include "Utilities.h"

////---------> constructeur 
Snake::Snake(Position startPos)
{
    body.push_back(startPos); // Initialize the snake with one segment
    currentDirection = Direction::RIGHT; // Default direction
}


////---------> faire bouger le serpent
void Snake::move()
{
    // retourner la position actuelle de la tete
    Position newHead = this->body.front(); 
    // mettre a jour la position de la tete
    switch (currentDirection) 
    {
    case Direction::UP:    newHead.deplacerY(-1); break;
    case Direction::DOWN:  newHead.deplacerY(+1); break;
    case Direction::LEFT:  newHead.deplacerX(-1); break;
    case Direction::RIGHT: newHead.deplacerX(+1); break;
    }

    //La nouvelle position de la tête(newHead) est ajoutée au début du vecteur body
    body.insert(body.begin(), newHead);

    //Supprime le dernier élément du vecteur body, qui correspond au segment de la queue
    body.pop_back();
}


////---------> aggrandir la taille de serpent en ajoutant un nouveau  segment au corps de serpent
void Snake::grow()
{
    body.push_back(body.back());
}


////---------> pour verifier les collisions avec le corps de serpent lui meme
bool Snake::checkSelfCollision() const
{
    Position head = this->body.front();
    // verifier si la tete de serpent se collise avec d'autres partie du cors de snake
    for (size_t i = 1; i < body.size(); ++i) 
    {
        if (body[i] == head) 
        {
            return true; // si collision 
        }
    }
    return false;
}


////---------> pour verifier une collision avec une position donnee
bool Snake::checkCollisionWithPosition(const Position& pos) const
{
    return this->body.front() == pos; //si collision retourne true
}


////---------> pour vérifier si une position donnée `p` se trouve dans le corps du serpent
bool Snake::comparer(Position& p)const
{
    return std::find(this->body.begin(), this->body.end(), p) != this->body.end();       
}

////---------> pour vérifier si la tête du serpent partage une coordonnée 
//(x ou y) avec la position donnée `p`
bool Snake::comparerHeadou(Position&p) const
{
    return this->body.front().ouLogique(p);
}


////---------> initialisation
void Snake::initialiserPos(Position p)
{
    this->body.front().changerPosition(p);
}


////---------> pour comparer position de head avec position v (et logique )
bool Snake::comparerHeadet(Position& p) const
{
    return this->body.front()==(p);
}


////---------> pour changer la direction du serpent sauf si la nouvelle direction 
//est opposée à la direction actuelle
void Snake::seDeplacerVersDirection(Direction newDirection)
{
    if ((currentDirection == Direction::UP && newDirection == Direction::DOWN) ||
        (currentDirection == Direction::DOWN && newDirection == Direction::UP) ||
        (currentDirection == Direction::LEFT && newDirection == Direction::RIGHT) ||
        (currentDirection == Direction::RIGHT && newDirection == Direction::LEFT)) 
    {
        return; // Ignore if the new direction is opposite to the current one
    }
    currentDirection = newDirection;
}

