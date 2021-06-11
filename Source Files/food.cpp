#include "food.h"
#include "vertex.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "square.h"
#include "circle.h"

Food::Food(){

}

Food Food::generateFood(Snake snake, int rowNumbers, int columnNumbers){

    int row = rand()%(rowNumbers-2) + 1;
    int column = rand()%(columnNumbers-2) + 1;

    Vertex foodPosition(row, column);  // position in board

    Food food(foodPosition);

    return food;

}


void Food::drawFood(Board board){
    // 0.03 0.33 1

    Square square = board.getBoard()[(int)this->position.getX()][(int)this->position.getY()];

    Circle circle(square.getMiddlePoint(), square.getL()/2);
    circle.drawCircle(0.03f, 0.33f, 1.0f);

}

Food::Food(Vertex position){
    this->position = position;
}

int Food::getColumn(){  // getColumn
    return this->position.getY();
}

int Food::getRow(){
    return this->position.getX();
}


Vertex Food::getPosition(){
    return this->position;
}