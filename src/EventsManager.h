#ifndef EVENTSMANAGER_H
#define EVENTSMANAGER_H

#include <GLFW/glfw3.h>

class EventsManager
{
private:
public:
    EventsManager();
    ~EventsManager();
    void pollEvents();
};


#endif