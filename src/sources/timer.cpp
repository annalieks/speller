#include "timer.h"

void timer::startTimer()
{
    start = std::chrono::system_clock::now();
    is_running = true;
}

void timer::stopTimer()
{
    end = std::chrono::system_clock::now();
    is_running = false;
}

unsigned long timer::getPassedTime()
{
    if(is_running)
        stopTimer();

    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}