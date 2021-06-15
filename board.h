#pragma once

#include "square.h"
#include "vertex.h"

class Board{
    private:
        int rowsNumber;
        int columnsNumber;
        Vertex topLeftVertex, topRightVertex, bottomLeftVertex, bottomRightVertex;
        Square** squares = nullptr;
    public:
        Board();
        Board(int, int, Vertex, Vertex, Vertex, Vertex);
        void drawBoard();
        Square **getBoard();
        int getRowsNumber();
        int getColumnsNumber();
};
