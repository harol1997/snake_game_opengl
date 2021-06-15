#include "score.h"
#include <GL/freeglut.h>
#include <iostream>
#include <string>
#include <cstring>

Score::Score(){
    this->score = 0;
}

void Score::drawScore(Vertex position, float r, float g, float b){

}

void Score::drawScore(){
    glColor3f(0.f, 0.f, 0.f);
    
    glRasterPos2f(-1.f, .9f);
    std::string strScore = "Score: "+std::to_string(this->score);
    char scoreChar[strScore.size()];
    strcpy(scoreChar, strScore.c_str());
    unsigned char scoreToDraw[strScore.size()];
    strcpy((char*)scoreToDraw, scoreChar);
    
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, scoreToDraw);
    
}

void Score::setScore(int score){
    this->score = score;
}

int Score::getScore(){
    return this->score;
}