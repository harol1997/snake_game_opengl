#pragma once

#include "snake.h"
#include "vertex.h"
#include "board.h"

class Food{
    private:
        Vertex position; // position in board
    public:
        Food();
        Food(Vertex);
        static Food generateFood(Snake, int, int);
        void drawFood(Board);
        int getColumn();  // column
        int getRow();  // row
        Vertex getPosition();
};