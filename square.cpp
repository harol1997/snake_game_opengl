#include "square.h"
#include "vertex.h"
#include <GL/freeglut.h>

Square::Square(Vertex v1, Vertex v2, Vertex v3, Vertex v4){
    this->v1 = v1;
    this->v2 = v2;
    this->v3 = v3;
    this->v4 = v4;

}

Square::Square(){

}

void Square::drawSquare(){  // you have to degine glCOlor, glBegin , glENd and GLSwap where you will use this function
    
    glVertex2f(v1.getX(), v1.getY());
    glVertex2f(v2.getX(), v2.getY());

    glVertex2f(v2.getX(), v2.getY());
    glVertex2f(v3.getX(), v3.getY());

    glVertex2f(v3.getX(), v3.getY());
    glVertex2f(v4.getX(), v4.getY());

    glVertex2f(v4.getX(), v4.getY());
    glVertex2f(v1.getX(), v1.getY());   
}

void Square::drawOneSquare(){
    
    //draw the new square
    glColor3f(0.8549f, 0.8549f, 0.8549f);
    glBegin(GL_QUADS);
    
    glVertex2f(v1.getX(), v1.getY());
    glVertex2f(v2.getX(), v2.getY());
    glVertex2f(v3.getX(), v3.getY());
    glVertex2f(v4.getX(), v4.getY());
    
    glEnd();

    //draw the new square

    //draw the square lines
    
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);

    glVertex2f(v1.getX(), v1.getY());
    glVertex2f(v2.getX(), v2.getY());

    glVertex2f(v2.getX(), v2.getY());
    glVertex2f(v3.getX(), v3.getY());

    glVertex2f(v3.getX(), v3.getY());
    glVertex2f(v4.getX(), v4.getY());

    glVertex2f(v4.getX(), v4.getY());
    glVertex2f(v1.getX(), v1.getY());
    
    glEnd();

    //draw the square lines

    glutSwapBuffers();
}

Vertex Square::getV1(){
    return this->v1;
}

Vertex Square::getV2(){
    return this->v2;
}

Vertex Square::getV3(){
    return this->v3;
}

Vertex Square::getV4(){
    return this->v4;
}

float Square::getL(){
    return Vertex::getDistance(this->v1, this->v2);
}
