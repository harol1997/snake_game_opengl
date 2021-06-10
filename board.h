#pragma once

#include "square.h"

class Board{
    private:
        int rowsNumber;
        int columnsNumber;
        float rate;
        Square** squares = nullptr;
    public:
        Board();
        Board(int, int, float);
        void drawBoard();
        Square **getBoard();
};
