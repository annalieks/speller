#include "timer.h"

void Timer::startTimer() {
  start = std::chrono::system_clock::now();
    isRunning = true;
}

void Timer::stopTimer() {
  end = std::chrono::system_clock::now();
    isRunning = false;
}

uint64_t Timer::getPassedTime() {
  if (isRunning) {
      stopTimer();
  }

  return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}