#include "circle.h"
#include <GL/freeglut.h>
#include <math.h>
#include <iostream>
Circle::Circle(float centerX, float centerY, float radio){
    this->centerX = centerX;
    this->centerY = centerY;
    this->radio = radio;
}

void Circle::drawCircle(){
    
    float alphaRad;
    
    glColor3f(0.0,0.4,0.2);
    glBegin(GL_POLYGON);

    for(int alpha = 0; alpha<360; alpha++){
        alphaRad = alpha*M_PI/180;
        glVertex2f(this->centerX+this->radio*cos(alphaRad),
                    this->centerY+this->radio*sin(alphaRad));
    }

    glEnd();
    glutSwapBuffers();
}