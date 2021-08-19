#include "Screen.h"

Screen::Screen(const int width, const int height):
    _windowWidth(width), _windowHeight(height)
{
    this->hasInitialize = initWindow();
}

Screen::~Screen()
{
    glfwDestroyWindow(_mainWindow);
    glfwTerminate();
}

bool Screen::initWindow()
{
    if (!glfwInit())
    {
        std::cout << "SCREEN_H: GLFW did not initialize" << std::endl;
        return false;
    }

    _mainWindow = glfwCreateWindow(_windowWidth, _windowHeight, "Project Farm", NULL, NULL);
    if (!_mainWindow)
    {
        std::cout << "SCREEN_H: GLFW Window did not initialize" << std::endl;
        return false;
    }

    glfwMakeContextCurrent(_mainWindow);

    glfwSwapInterval(1);
    
    return true;
}

bool Screen::shouldWindowClose()
{
    return glfwWindowShouldClose(_mainWindow);
}

void Screen::clear()
{
    int width, height;
    glfwGetFramebufferSize(_mainWindow, &width, &height);
    glViewport(0,0,width,height);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Screen::swapBuffers()
{
    glfwSwapBuffers(_mainWindow);
}