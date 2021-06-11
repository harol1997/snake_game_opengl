#include "circle.h"
#include <GL/freeglut.h>
#include <math.h>
#include <iostream>
Circle::Circle(Vertex center, float radio){
    this->center = center;
    this->radio = radio;
}

void Circle::drawCircle(float r, float g, float b){
    
    float alphaRad;
    
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);

    for(int alpha = 0; alpha<360; alpha++){
        alphaRad = alpha*M_PI/180;
        glVertex2f(this->center.getX()+this->radio*cos(alphaRad),
                    this->center.getY()+this->radio*sin(alphaRad));
    }

    glEnd();
    
}

void Circle::drawCircle(){
    float alphaRad;
    
    glColor3f(0.0,0.4,0.2);
    glBegin(GL_POLYGON);

    for(int alpha = 0; alpha<360; alpha++){
        alphaRad = alpha*M_PI/180;
        glVertex2f(this->center.getX()+this->radio*cos(alphaRad),
                    this->center.getY()+this->radio*sin(alphaRad));
    }

    glEnd();
}