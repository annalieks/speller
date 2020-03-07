#ifndef SPELLER_TIMER_H
#define SPELLER_TIMER_H
#include <chrono>

class Timer
{
private:
    std::chrono::time_point<std::chrono::system_clock> start;
    std::chrono::time_point<std::chrono::system_clock> end;
    bool is_running;

public:
    Timer() : is_running(false) {}
    ~Timer() = default;

    void startTimer();
    void stopTimer();
    unsigned long getPassedTime();
};

#endif //SPELLER_TIMER_H
