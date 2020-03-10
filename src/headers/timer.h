#ifndef SPELLER_TIMER_H
#define SPELLER_TIMER_H

#include <chrono>

class Timer {
 private:
  std::chrono::time_point<std::chrono::system_clock> start;
  std::chrono::time_point<std::chrono::system_clock> end;
  bool isRunning;

 public:
  Timer() : isRunning(false) {}
  ~Timer() = default;
  void startTimer();
  void stopTimer();
  unsigned long getPassedTime();
};

#endif  // SPELLER_TIMER_H
