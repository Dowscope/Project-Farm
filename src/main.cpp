
#include "Screen.h"
#include "EventsManager.h"

// Declare MAIN functions
bool init();
void cleanup();
void mainLoop();

// Declare game objects
Screen* screen;
EventsManager* eventManager;

// MAIN function
int main(int argc, char const *argv[])
{
    init();
    mainLoop();
    cleanup();
    return 0;
}

// Initialize the game
bool init() 
{
    screen = new Screen(800, 600);
    if (!screen->hasInitialize) 
    {
        std::cout << "MAIN_CPP: Screen did not initialize" << std::endl;
        return false;
    }

    eventManager = new EventsManager();

    return true;
}

// Clean up before quiting game
void cleanup()
{
    delete screen;
}

// MAIN LOOP
void mainLoop()
{
    while(!screen->shouldWindowClose())
    {
        screen->clear();
        screen->swapBuffers();
        eventManager->pollEvents();
    }
}