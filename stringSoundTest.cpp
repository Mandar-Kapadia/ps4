/*Copyright 2022 Mandar Kapadia */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>
#include"StringSound.h"
#include"CircularBuffer.h"

BOOST_AUTO_TEST_CASE(constructor) {
  std::vector<sf::Int16> temp;

  temp.push_back(0);
  temp.push_back(500);
  temp.push_back(700);
  temp.push_back(600);

  BOOST_REQUIRE_NO_THROW(StringSound gs = StringSound(temp));
  StringSound gs = StringSound(temp);
  BOOST_REQUIRE(gs.sample() == 0);

}
BOOST_AUTO_TEST_CASE(tic) {
  std::vector<sf::Int16> temp;

  temp.push_back(0);
  temp.push_back(500);
  temp.push_back(7000);
  temp.push_back(600);
  StringSound gs = StringSound(temp);
  gs.tic();
  BOOST_REQUIRE(gs.sample() == 500);
  gs.tic();
  BOOST_REQUIRE(gs.sample() == 7000);
  gs.tic();
  BOOST_REQUIRE(gs.sample() == 600);
  gs.tic();
  BOOST_REQUIRE(gs.sample() == 249);
}
BOOST_AUTO_TEST_CASE(timeFunction) {
  std::vector<sf::Int16> temp;

  temp.push_back(0);
  temp.push_back(500);
  temp.push_back(7000);
  temp.push_back(600);
  StringSound gs = StringSound(temp);
  gs.tic();
  BOOST_REQUIRE(gs.time() == 1);
  gs.tic();
  BOOST_REQUIRE(gs.time() == 2);
  gs.tic();
  BOOST_REQUIRE(gs.time() == 3);
  gs.tic();
  BOOST_REQUIRE(gs.time() == 4);
}
BOOST_AUTO_TEST_CASE(negitiveInput) {

 BOOST_REQUIRE_THROW(StringSound(-5) , std::invalid_argument);
}
