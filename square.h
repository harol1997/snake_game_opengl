#pragma once

#include "vertex.h"

class Square{

    private:
        Vertex v1, v2, v3, v4;

    public:
        Square();
        Square(Vertex, Vertex, Vertex, Vertex);
        void drawSquare();
        void drawOneSquare();
        Vertex getV1();
        Vertex getV2();
        Vertex getV3();
        Vertex getV4();
        float getL();  // distance between two vertex;    
};