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

float Vertex::getDistance(Vertex v1, Vertex v2){  // when vertex are board coordenates
    return (float)sqrt(pow( v1.x - v2.x , 2) + pow(v1.y - v2.y, 2));
}

bool Vertex::Compare(Vertex v1, Vertex v2){ // when vertex are board coordenates
    return v1.x == v2.x && v1.y == v2.y;
}