/*Copyright 2022 Mandar Kapadia */
#include"StringSound.h"
StringSound::StringSound(double frequency) {
    // add int a unique point of sample_rate/frequency size
    if (frequency < 0) {
        throw std::invalid_argument("negitive frequency");
    }
    cb = std::make_unique<CircularBuffer>(ceil(sampling_rate/frequency));
    // setting the time to 0;
    timeCounter = 0;
}
StringSound::StringSound(std::vector<sf::Int16> init) {
    // making a new pointer the size of the vector
    cb = std::make_unique<CircularBuffer>(init.size());
    // adding all the elements in the vector to the buffer and cast it
    for (auto i : init) {
        cb->enqueue(static_cast<int16_t>(i));
    }
    // setting the time to 0;
    timeCounter = 0;
}
StringSound::~StringSound() {
    // deletes the object and the array
    cb.reset();
}
void StringSound::pluck() {
    // empty which checks if the function is empty if not then make it empty
    cb->empty();
    // run a for loop and enqueue random valules from -32768 to 32768
    // till full
    while (!cb->isFull()) {
        cb->enqueue(static_cast<int16_t>(-32768 +
        (rand() % static_cast<int>(32768 - (-32768) + 1))));//NOLINT
    }
}
void StringSound::tic() {
    // get the first value of array and remove it.
    int16_t firstValue = cb->dequeue();
    // get second element
    int16_t secondValue = cb->peek();

    // get the algorithm
    int KSA = (decayFactor * ((firstValue + secondValue)/2));

    // enqueue
    cb->enqueue(static_cast<int16_t>(KSA));

    // add to time
    timeCounter++;
}
sf::Int16 StringSound::sample() {
    sf::Int16 sample = static_cast<sf::Int16>(cb->peek());

    return(sample);
}
int StringSound::time() {
    return(timeCounter);
}
