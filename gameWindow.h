#pragma once

#include <iostream>

class Window{
    private:
        int width, height;
        
    public:
        Window(int, int);
        Window();
        void createWindow(const std::string);
        static void initWindow();
        
};

void frame();
void keyEvent(unsigned char, int, int);
void loop();