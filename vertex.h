# pragma once

class Vertex{
    private:
        float x, y;

    public:
        Vertex(float, float);
        Vertex();
        float getX();
        float getY();
        static float getDistance(Vertex, Vertex);//get Distance between two vertex
};