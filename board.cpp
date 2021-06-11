#include "board.h"
#include "vertex.h"
#include <GL/freeglut.h>

Board::Board(){

}

Board::Board(int rowsNumber, int columnsNumber, float rate){
    this->rowsNumber = rowsNumber;
    this->columnsNumber = columnsNumber;
    this->rate = rate;

    this->squares = new Square*[rowsNumber];
    for(int row=0; row<rowsNumber; row++){
        this->squares[row] = new Square[columnsNumber];
    }
}

void Board::drawBoard(){
    float screenCoordenates[] = {-1.f, 1.f,
                                -1.0f + rate, 1.f,
                                -1.0f + rate, 1.f - rate, 
                                -1.f, 1.f - rate};
    
    
    

    for(int row=0; row<this->rowsNumber; row++){
        for(int column=0; column<this->columnsNumber; column++){
            Vertex v1(screenCoordenates[0], screenCoordenates[1]);
            Vertex v2(screenCoordenates[2], screenCoordenates[3]);   
            Vertex v3(screenCoordenates[4], screenCoordenates[5]);
            Vertex v4(screenCoordenates[6], screenCoordenates[7]);

            Square square(v1, v2, v3, v4);
            this->squares[row][column] = square;
            
            if((row==0 || row==this->getRowsNumber()-1)) square.drawSolidSquare();
            else if((column==0 || column==this->getColumnsNumber()-1))square.drawSolidSquare();
            else square.drawSquare();

            screenCoordenates[0] = screenCoordenates[0]+rate;
            screenCoordenates[2] = screenCoordenates[2]+rate;
            screenCoordenates[4] = screenCoordenates[4]+rate;
            screenCoordenates[6] = screenCoordenates[6]+rate;    
        }
        
        screenCoordenates[0] = -1.0f;
        screenCoordenates[1] = screenCoordenates[1]-rate;
        screenCoordenates[2] = -1.0f + rate;
        screenCoordenates[3] = screenCoordenates[3]-rate;
        screenCoordenates[4] = -1.0f + rate;
        screenCoordenates[5] = screenCoordenates[5]-rate;
        screenCoordenates[6] = -1.0f;
        screenCoordenates[7] = screenCoordenates[7]-rate;
    }

    
    glutSwapBuffers();
    
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
