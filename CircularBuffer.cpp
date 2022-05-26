/*Copyright 2022 Mandar Kapadia */
#include "CircularBuffer.h"


CircularBuffer::CircularBuffer(int capacity) {
    if (capacity < 1) {
        throw std::invalid_argument("Cannot have capacity less then 1");
    }
    length = capacity;

    CircularArray = new int16_t[capacity];
    back = -1;
    front = -1;

    _size = 0;
}
bool CircularBuffer::isEmpty() {
    return(_size == 0);
}
bool CircularBuffer::isFull() {
    return(length <= _size);
}
void CircularBuffer::enqueue(int16_t x) {
    if (this->isFull()) {
        throw std::runtime_error("array is full cannot fill more");
    } else {
        if (front == -1) {
            front = 0;
        }
        back = (back+1)%length;
        CircularArray[back] = x;
        _size++;
    }
}
int16_t CircularBuffer::dequeue() {
    if (this->isEmpty()) {
        throw std::runtime_error("cannot dequeue if there is an empty array");
    } else {
        int16_t temp = CircularArray[front];
        _size--;

        if (front == back) {
            front = -1;
            back = -1;
        } else {
            front = (front +1)%length;
        }
        return temp;
    }
}
int16_t CircularBuffer::peek() {
    if (this->isEmpty()) {
        throw std::runtime_error("cannot peek if there is an empty array");
    }
    return(CircularArray[front]);
}
size_t CircularBuffer::size() {
    return(static_cast<size_t>(_size));
}
void CircularBuffer::empty() {
    if (this->isEmpty()) {
        return;
    } else {
         back = -1;
         front = -1;
         _size = 0;
    }
}
CircularBuffer::~CircularBuffer() {
    delete[] CircularArray;
}
