
#include "gameWindow.h"
#include "board.h"
#include "snake.h"
#include <iostream>
#include <GL/freeglut.h>
#include <unistd.h>

//globals objects
Board board(50, 50, 0.04f);
Snake snake(board.getBoard());
float timeRate = 100.0;
//globals objects

void frame(){
    Window::initWindow();
    board.drawBoard();
    snake.drawBody();//initialize to snake   
}

void loop(int i){
    board.drawBoard();
    snake.move(snake.getLastDirection());
    snake.drawBody();
    glutTimerFunc(timeRate, loop, 0);
}

void loop2(){
    Window::initWindow();
    
}

void keyEvent(unsigned char key, int x, int y){
    //Window::initWindow();
    board.drawBoard();
    snake.move(key);
    snake.drawBody();
}

void Window::initWindow(){
    glClearColor(0.8549f, 0.8549f, 0.8549f, 1.0f);  // similar color , clean background color
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // clear the color buffer
    glutSwapBuffers();
}

Window::Window(int width, int height){  // first, you have to call gluInit()
    this->width = width;
    this->height = height; 
}

Window::Window(){
    this->height = 500;
    this->width = 500;
}

void Window::createWindow(const std::string title){
    glutInitWindowPosition(500, 500);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  
    glutInitWindowPosition(100, 100);  
    glutInitWindowSize(600,600); 
    glutCreateWindow(title.c_str());
    glutDisplayFunc(frame);  // initialize my frame
    glutKeyboardFunc(keyEvent);
    glutTimerFunc(timeRate, loop, 0);
    //glutIdleFunc(loop2);
}
