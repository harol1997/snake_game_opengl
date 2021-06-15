
#include "gameWindow.h"
#include "board.h"
#include "snake.h"
#include "food.h"
#include "score.h"
#include "square.h"
#include <iostream>
#include <GL/freeglut.h>
#include <unistd.h>
#include <thread>


//globals objects
Vertex vp1(-1.f, .8f), vp2(1.f, .8f), vp3(-1.f, -1.f), vp4(1.f, -1.f);  //Game panel vertex
Vertex vs1(-1.f, 1.0f), vs2(1.f, 1.f), vs3(-1.f, .9f), vs4(1.f, .9f);  //Score panel vertex

Board board(50, 50, vp1, vp2, vp3, vp4);
Square scoreBoard(vs1, vs2, vs3, vs4);  // board to Score
Score score;
Snake snake(board.getBoard());
bool existFood = false;
int a = 1;
Food food;
char lastKey = ' ';
//globals objects

// functions to use just in this module

void frame(){  // initialize window game
    Window::initWindow();
    board.drawBoard();
    snake.drawBody();//initialize to snake
    scoreBoard.drawSolidSquare(.8549f, 0.8549f, 0.8549f);
    score.drawScore();
    glFlush();
}

void generateFoodThread(){
    food = Food::generateFood(snake, 50, 50);    
    existFood = true;
}

void generateFoodInGame(){
    if(!existFood){
            std::thread foodThread(generateFoodThread);  // now, it is not necesary, maybe i will change this part
            foodThread.join();
        }
        else{
            food.drawFood(board);
            Square snakeSquare = board.getBoard()[(int)snake.getPositions().front().getX()][(int)snake.getPositions().front().getY()];
            Square foodSquare = board.getBoard()[food.getRow()][food.getColumn()];
            
            if(Square::Compare(snakeSquare, foodSquare)){
                
                snake.eat();
                existFood = false;
                snake.slowDown();
                snake.drawBody();
                score.setScore(score.getScore()+1);
                scoreBoard.drawSolidSquare(.8549f, 0.8549f, 0.8549f);
                score.drawScore();
                
                glFlush();
            }
        }
}

void loop(int i){   // to glutTimerFunc()
    
    if(i==0){
        scoreBoard.drawSolidSquare(.8549f, 0.8549f, 0.8549f);
        score.drawScore();
        snake.move(snake.getLastDirection());
        snake.drawBody();
        
        glFlush();
        //glutSwapBuffers();

        generateFoodInGame();

        bool lost = false;
        
        for(int i=0; i<board.getRowsNumber(); i++){
            int snakeHeaderX = snake.getPositions().front().getX(); 
            int snakeHeaderY = snake.getPositions().front().getY();
            if(i == snakeHeaderX && (snakeHeaderY == 0 || snakeHeaderY == board.getColumnsNumber()-1)){
                lost = true;
                break;
            }
        }
        if(!lost){
            for(int i=0; i<board.getColumnsNumber(); i++){
                int snakeHeaderX = snake.getPositions().front().getX(); 
                int snakeHeaderY = snake.getPositions().front().getY();
                if(i == snakeHeaderY && (snakeHeaderX == 0 || snakeHeaderX == board.getRowsNumber()-1)){
                    lost = true;
                    break;
                }
            }
        }

        if(lost) glutTimerFunc(snake.getSpeed(), loop, 1);
        else glutTimerFunc(snake.getSpeed(), loop, 0);
        
    }
}

void keyEvent(unsigned char key, int x, int y){  // to glutKeyFunc()
    
    if(lastKey != key){
        snake.move(key);
        snake.drawBody();
        glFlush();
        generateFoodInGame();
        lastKey = key;
    }    
}

// functions to use just in this module


void Window::initWindow(){
    glClearColor(0.8549f, 0.8549f, 0.8549f, 1.0f);  // similar color , clean background color
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // clear the color buffer
}

Window::Window(int width, int height, int* arg, char** args){  // first, you have to call gluInit()
    this->width = width;
    this->height = height; 
    glutInit(arg, args);
    glutInitWindowPosition(500, 500);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
    glutInitWindowPosition(100, 100);  
    glutInitWindowSize(600,600); 
}

Window::Window(){
    this->height = 500;
    this->width = 500;
}

void Window::startGame(const std::string title){
    glutCreateWindow(title.c_str());
    glutDisplayFunc(frame);  // initialize my frame
    glutKeyboardFunc(keyEvent);
    glutTimerFunc(snake.getSpeed(), loop, 0);
    glutMainLoop();
}
