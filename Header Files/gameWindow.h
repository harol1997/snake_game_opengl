#pragma once

#include <iostream>

class Window{
    private:
        int width, height;
        
    public:
        Window(int, int, int*, char**);
        Window();
        void startGame(const std::string);
        static void initWindow();
        
};
