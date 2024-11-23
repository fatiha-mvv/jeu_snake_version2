#pragma once
#include <vector>
#include <iostream>
#include "Utilities.h"
#include "Position.h"

class Snake
{
private:
    std::vector<Position> body; //representatn le corps de serpent (vecteur des positions)
    Direction currentDirection; //direction actuelle
public:
    // Constructor de Snake
    Snake(Position startPos);
    void seDeplacerVersDirection(Direction newDirection);
    void move();
    void grow();
    bool checkSelfCollision() const;
    bool checkCollisionWithPosition(const Position& pos) const;
    bool comparer(Position&)const;
    bool comparerHeadet(Position&)const;
    bool comparerHeadou(Position&)const;
    void initialiserPos(Position);
};

