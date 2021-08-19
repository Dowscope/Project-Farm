#include "EventsManager.h"

EventsManager::EventsManager()
{
}

EventsManager::~EventsManager()
{
}

void EventsManager::pollEvents()
{
    glfwPollEvents();
}
