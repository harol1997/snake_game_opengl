#include "snake.h"
#include <math.h>

Snake::Snake(Square **squares){
    this->squares = squares;
    this->lastDirection = 'd';
    this->initBodySnake(3, 4, 4);
}

Snake::Snake(int initialSize, int initialRow, int initialColumn, Square **squares, unsigned char lastDirection){
    this->squares = squares;
    this->lastDirection = lastDirection;
    this->initBodySnake(initialSize, initialRow, initialColumn);
}

void Snake::initBodySnake(int initialSize, int initialRow, int initialColumn){
    for(int i=0; i<initialSize; i++){
        Vertex position(initialRow, initialColumn);
        this->positions.push_front(position);
        initialColumn++;
    }
}

void Snake::drawBody(){
    std::list<Vertex>::iterator it;  // to looping positions list
    
    for(it=this->positions.begin(); it!= this->positions.end(); it++){
        Square square = this->squares[(int)(*it).getX()][(int)(*it).getY()];
        float centerX = (square.getV2().getX() + square.getV4().getX())/2;
        float centerY = (square.getV2().getY() + square.getV4().getY())/2;
        
        Circle circle(centerX, centerY, square.getL()/2.0);
        circle.drawCircle();
    }
}

void Snake::move(unsigned char direction){
    switch (direction){
    case 'w':
        if(lastDirection != 's'){
            this->changePosition(-1,0);  // minus row
            lastDirection = 'w';
        }
        break;
    
    case 's':
        if(lastDirection != 'w'){
            this->changePosition(1,0);  // plus row
            lastDirection = 's';
        }
        break;
    
    case 'a':
        if(lastDirection != 'd'){
            this->changePosition(0,-1);
            lastDirection = 'a';
        }
        break;

    case 'd':
        if(lastDirection != 'a'){
            this->changePosition(0,1);
            lastDirection = 'd';
        }
        break;
    
    }
}

void Snake::changePosition(int minusX, int minusY){  //minusX is row, minusY is column
    Vertex lastPosition = this->positions.back();
    Square squareEraser = this->squares[(int)lastPosition.getX()][(int)lastPosition.getY()];
    squareEraser.drawOneSquare();

    this->positions.pop_back();
    Vertex firstPosition = this->positions.front();
    Vertex newPosition(firstPosition.getX()+minusX, firstPosition.getY()+minusY);
    this->positions.push_front(newPosition);
}

unsigned char Snake::getLastDirection(){
    return this->lastDirection;
}

std::list<Vertex> Snake::getPositions(){
    return this->positions;
}
