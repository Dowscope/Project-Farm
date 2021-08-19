#ifndef  SCREEN_H
#define SCREEN_H

#include <GLFW/glfw3.h>
#include <iostream>

class Screen
{
private:
    int _windowWidth, _windowHeight;
    GLFWwindow* _mainWindow;
public:
    bool hasInitialize = false;
public:
    Screen(const int width, const int height);
    ~Screen();
    bool initWindow();
    bool shouldWindowClose();
    void clear();
    void swapBuffers();
};

#endif