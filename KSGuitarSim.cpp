/*
  Copyright 2015 Fred Martin, 
  Y. Rykalova, 2020
  J. Daly 2022
*/
#include <SFML/Graphics.hpp>//NOLINT
#include <SFML/System.hpp>//NOLINT
#include <SFML/Audio.hpp>//NOLINT
#include <SFML/Window.hpp>//NOLINT

#include <math.h>//NOLINT
#include <limits.h>//NOLINT
#include <algorithm>//NOLINT
#include <iostream>//NOLINT
#include <string>//NOLINT
#include <exception>//NOLINT
#include <stdexcept>//NOLINT
#include <vector>//NOLINT

#include "CircularBuffer.h"//NOLINT
#include "StringSound.h"//NOLINT

#define CONCERT_A 220.0
#define SAMPLES_PER_SEC 44100
using namespace std;//NOLINT
vector<sf::Int16> makeSamples(StringSound& gs);
std::vector< std::vector<sf::Int16> >VectorOfSamples(double(*func)(int));
int main() {
    std::vector<int> name = {16, 22, 28, 4, 30, 17, 31, 19, 24, 33, 20, 34, 8, 35, 14, 15, 56, 46, 55, 25, 23, 3, 2, 5, 21, 6, 1, 12, 9, 13, 10, 49, 50, 48, 52, 51, 57};//NOLINT
    sf::RenderWindow window(sf::VideoMode(300, 200), "SFML Plucked String Sound Lite");//NOLINT
    sf::Event event;
    std::vector< std::vector<sf::Int16> >samples2;
    std::vector<sf::SoundBuffer>soundBuffers(37 , sf::SoundBuffer());
    std::vector<sf::Sound>sounds(37 , sf::Sound());

    samples2 = VectorOfSamples([](int i) { return (440.0 * pow(2 , (i - 24.0)/12) ); });//NOLINT


    for (int i = 0 ; i < 37 ; i++) {
        if (!soundBuffers[i].loadFromSamples(&samples2[i][0], samples2[i].size(), 2, SAMPLES_PER_SEC))//NOLINT
            throw std::runtime_error("sf::SoundBuffer: failed to load from samples.");//NOLINT
        sounds[i].setBuffer(soundBuffers[i]);
    }

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                for (int i = 0; i < name.size(); i++) {
                    if (event.key.code == name[i]) {
                        sounds[i].play();
                        break;
                    }
                }
            default:
                break;
            }

            window.clear();
            window.display();
        }
    }
    return 0;
}
vector<sf::Int16> makeSamples(StringSound& gs) {
    std::vector<sf::Int16> samples;

    gs.pluck();
    int duration = 8;  // seconds
    int i;
    for (i= 0; i < SAMPLES_PER_SEC * duration; i++) {
        gs.tic();
        samples.push_back(gs.sample());
    }

    return samples;
}
std::vector< std::vector<sf::Int16> >VectorOfSamples(double(*func)(int)) {
    std::vector< std::vector<sf::Int16> >VectorOfSamples;
    for (int i = 0 ; i < 37 ; i++) {
        StringSound gs(func(i));
        VectorOfSamples.push_back(makeSamples(gs));
    }
    return VectorOfSamples;
}
