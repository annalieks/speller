#include "timer.h"

void Timer::startTimer()
{
    start = std::chrono::system_clock::now();
    is_running = true;
}

void Timer::stopTimer()
{
    end = std::chrono::system_clock::now();
    is_running = false;
}

unsigned long Timer::getPassedTime()
{
    if(is_running)
        stopTimer();

    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}