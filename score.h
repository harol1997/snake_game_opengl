#include "vertex.h"
#include <iostream>

class Score{
    private:
        int score;
        Vertex position;
    public:
        Score();
        void drawScore(Vertex, float, float, float);
        void drawScore();
        void setScore(int);
        int getScore();
};