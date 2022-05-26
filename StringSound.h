/*Copyright 2022 Mandar Kapadia */
#include "CircularBuffer.h"
#include <vector>
#include<memory>
class StringSound {
 public:
     explicit StringSound(double frequency);
     explicit StringSound(std::vector<sf::Int16> init);
     StringSound (const StringSound &obj) = delete;  // no copy constructor;
     ~StringSound();
     void pluck();
     void tic();
     sf::Int16 sample();
     int time();
 private:
     const int sampling_rate = 44100;
     const double decayFactor = 0.996;
     std::unique_ptr<CircularBuffer> cb;
     int timeCounter;
};
