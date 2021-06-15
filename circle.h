#pragma once

#include "vertex.h"

class Circle{

    private:
        float radio;
        Vertex center;
        

    public:
        Circle(Vertex, float radio);
        void drawCircle();
        void drawCircle(float, float, float);

};