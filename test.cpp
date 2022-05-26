/*Copyright 2022 Mandar Kapadia */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include "CircularBuffer.h"



BOOST_AUTO_TEST_CASE(constructor) {
    BOOST_REQUIRE_THROW(CircularBuffer(-5) , std::invalid_argument);
    BOOST_REQUIRE_THROW(CircularBuffer(0) , std::invalid_argument);
    CircularBuffer test1(5);
    BOOST_REQUIRE(test1.size() == 0);
}
BOOST_AUTO_TEST_CASE(size) {
    CircularBuffer test1(5);
    BOOST_REQUIRE(test1.size() == 0);
    test1.enqueue(5);
    BOOST_REQUIRE(test1.size() == 1);
    test1.dequeue();
    BOOST_REQUIRE(test1.size() == 0);
}
BOOST_AUTO_TEST_CASE(Empty) {
    CircularBuffer test1(5);
    BOOST_REQUIRE(test1.isEmpty() == true);
    test1.enqueue(5);
    BOOST_REQUIRE(test1.isEmpty() == false);
    test1.dequeue();
    BOOST_REQUIRE(test1.isEmpty() == true);
}
BOOST_AUTO_TEST_CASE(Full) {
    CircularBuffer test1(1);
    BOOST_REQUIRE(test1.isFull() == false);
    test1.enqueue(5);
    BOOST_REQUIRE(test1.isFull() == true);
    test1.dequeue();
    BOOST_REQUIRE(test1.isFull() == false);
}
BOOST_AUTO_TEST_CASE(enqueue) {
    CircularBuffer test1(1);
    test1.enqueue(5);
    BOOST_REQUIRE(test1.size() == 1);
    BOOST_REQUIRE_THROW(test1.enqueue(5) , std::runtime_error);
}
BOOST_AUTO_TEST_CASE(dequeue) {
    CircularBuffer test1(1);
    BOOST_REQUIRE_THROW(test1.dequeue() , std::runtime_error);
    test1.enqueue(5);
    BOOST_REQUIRE(test1.dequeue() == 5);
    BOOST_REQUIRE(test1.size() == 0);
}
BOOST_AUTO_TEST_CASE(peek) {
    CircularBuffer test1(1);
    BOOST_REQUIRE_THROW(test1.peek() , std::runtime_error);
    test1.enqueue(5);
    BOOST_REQUIRE(test1.peek() == 5);
    BOOST_REQUIRE(test1.size() == 1);
}
BOOST_AUTO_TEST_CASE(empty) {
    CircularBuffer test1(1);
    test1.enqueue(5);
    test1.empty();
    BOOST_REQUIRE_THROW(test1.dequeue() , std::runtime_error);
}
