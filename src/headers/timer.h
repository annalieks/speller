#ifndef SPELLER_TIMER_H
#define SPELLER_TIMER_H
#include <chrono>

class timer
{
private:
    std::chrono::time_point<std::chrono::system_clock> start;
    std::chrono::time_point<std::chrono::system_clock> end;
    bool is_running;

public:
    timer() : is_running(false) {}
    ~timer() = default;

    void startTimer();
    void stopTimer();
    unsigned long getPassedTime();
};

#endif //SPELLER_TIMER_H
