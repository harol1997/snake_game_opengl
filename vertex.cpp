#include <math.h>
#include "vertex.h"

Vertex::Vertex(float x, float y){
    this->x = x;
    this->y = y;
}

Vertex::Vertex(){
    
}

float Vertex::getX(){
    return this->x;
}

float Vertex::getY(){
    return this->y;
}

float Vertex::getDistance(Vertex v1, Vertex v2){
    return (float)sqrt((float)pow( v1.x - v2.x , 2) + (float)pow(v1.y - v2.y, 2));
}