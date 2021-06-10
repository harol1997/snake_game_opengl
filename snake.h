#pragma once

#include <iostream>
#include <list>
#include "circle.h"
#include "square.h"
#include "vertex.h"  // Here It is used for snake positions

class Snake{
    private:
        unsigned char lastDirection;
        std::list<Vertex> positions; // body
        Square **squares; // all board's squares
        void initBodySnake(int, int, int);
        void changePosition(int, int); // to change position in Board

    public:
        unsigned char getLastDirection();
        Snake(Square**);
        Snake(int, int, int, Square**, unsigned char);
        void drawBody();
        void eat();
        void move(unsigned char);
        void increase();
};