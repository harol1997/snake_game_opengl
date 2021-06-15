#include "board.h"
#include "vertex.h"
#include <GL/freeglut.h>
#include <math.h>

Board::Board(){

}

Board::Board(int rowsNumber, int columnsNumber, Vertex v1, Vertex v2, Vertex v3, Vertex v4){
    this->rowsNumber = rowsNumber;
    this->columnsNumber = columnsNumber;
    this->topLeftVertex = v1;
    this->topRightVertex = v2;
    this->bottomLeftVertex = v3;
    this->bottomRightVertex = v4;

    this->squares = new Square*[rowsNumber];
    for(int row=0; row<rowsNumber; row++){
        this->squares[row] = new Square[columnsNumber];
    }
}

void Board::drawBoard(){


    float posx = this->topLeftVertex.getX(), posy = this->topLeftVertex.getY();  //  left corner initial
    float posxf = this->topRightVertex.getX(), posyf = this->topRightVertex.getY();  // right corner initial

    float posxx = this->bottomLeftVertex.getX(), posyy = this->bottomLeftVertex.getY();  //left corner final
    float posxxf = this->bottomRightVertex.getX(), posyyf = this->bottomRightVertex.getY();  // right corner final

    float rateColumns = (abs(posxf) + abs(posx))/this->columnsNumber;
    float rateRows = (abs(posyy) + abs(posy))/this->rowsNumber;
    
    float screenCoordenates[] = {posx, posy,
                                posx + rateColumns, posy,
                                posx + rateColumns, posy - rateRows, 
                                posx, posy -rateRows};
    
    for(int row=0; row<this->rowsNumber; row++){
        for(int column=0; column<this->columnsNumber; column++){
            Vertex v1(screenCoordenates[0], screenCoordenates[1]);
            Vertex v2(screenCoordenates[2], screenCoordenates[3]);   
            Vertex v3(screenCoordenates[4], screenCoordenates[5]);
            Vertex v4(screenCoordenates[6], screenCoordenates[7]);

            Square square(v1, v2, v3, v4);
            this->squares[row][column] = square;
            if((row==0 || row==this->getRowsNumber()-1)) square.drawSolidSquare(0.53f, 0.5f, 0.51f);
            else if((column==0 || column==this->getColumnsNumber()-1))square.drawSolidSquare(0.53f, 0.5f, 0.51f);
            else square.drawSolidSquare(0.8549f, 0.8549f, 0.8549f);

            screenCoordenates[0] = screenCoordenates[0]+rateColumns;
            screenCoordenates[2] = screenCoordenates[2]+rateColumns;
            screenCoordenates[4] = screenCoordenates[4]+rateColumns;
            screenCoordenates[6] = screenCoordenates[6]+rateColumns;    
        }
        
        screenCoordenates[0] = posx;  // x
        screenCoordenates[1] = screenCoordenates[1]-rateRows;  // y
        screenCoordenates[2] = posx + rateColumns;  // x
        screenCoordenates[3] = screenCoordenates[3]-rateRows;  // y
        screenCoordenates[4] = posx + rateColumns;  // x
        screenCoordenates[5] = screenCoordenates[5]-rateRows;  // y
        screenCoordenates[6] = posx;  // x
        screenCoordenates[7] = screenCoordenates[7]-rateRows;  // y
    }
}

Square **Board::getBoard(){
    return this->squares; 
}

int Board::getRowsNumber(){
    return this->rowsNumber;
}

int Board::getColumnsNumber(){
    return this->columnsNumber;
}
