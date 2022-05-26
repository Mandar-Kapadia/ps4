/*Copyright 2022 Mandar Kapadia */
#ifndef _USERS_MANDARKAPADIA_PROGRAMMING_C_C___COMPUTING_4_PS4_CIRCULARBUFFER_H_
#define _USERS_MANDARKAPADIA_PROGRAMMING_C_C___COMPUTING_4_PS4_CIRCULARBUFFER_H_

#include <SFML/System.hpp>//NOLINT
#include <SFML/Window.hpp>//NOLINT
#include <SFML/Graphics.hpp>//NOLINT
#include <SFML/Audio.hpp>//NOLINT
#include<iostream>//NOLINT
#include<string>//NOLINT
#include<memory>//NOLINT
#include<vector>//NOLINT
#include<math.h>//NOLINT
#include<algorithm>//NOLINT
#include <stdint.h>//NOLINT
#include <boost/test/unit_test.hpp>//NOLINT

class CircularBuffer{
 public:
        size_t size();
        explicit CircularBuffer(int capacity);
        bool isEmpty();
        bool isFull();
        void enqueue(int16_t x);
        int16_t dequeue();
        int16_t peek();
        ~CircularBuffer();
        void empty();
 private:
        int front;
        int back;

        int length;
        int _size;

        int16_t* CircularArray;
};


#endif//  _USERS_MANDARKAPADIA_PROGRAMMING_C_C___COMPUTING_4_PS4_CIRCULARBUFFER_H_ //NOLINT
