#pragma once

#include <iostream>
#include <list>
#include "square.h"
#include "vertex.h"  // Here It is used for snake positions

class Snake{
    private:
        unsigned char lastDirection;
        std::list<Vertex> positions; // body
        Square **squares; // all board's squares
        void initBodySnake(int, int, int);
        void changePosition(int, int); // to change position in Board
        float speed;  //  (-) snake is faster
        float speedRate;  // variacion de la velocidad
        float minusSpeed;

    public:
        unsigned char getLastDirection();
        Snake(Square**);
        Snake(int, int, int, Square**, unsigned char, float, float);
        void drawBody();
        void eat();
        void move(unsigned char);
        std::list<Vertex> getPositions();//get Body
        float getSpeed();
        void slowDown();
};