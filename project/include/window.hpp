#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <cmath>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <miniaudio.h>

namespace MusicVisualizer {
class Window {
    public:
        Window(size_t width, size_t height, std::string windowTitle);

        void run();
    private:
        size_t width;
        size_t height;
        std::string windowTitle;
        sf::RenderWindow window;
        ma_engine engine;
        ma_sound sound;

        void startMusicHelper(const std::string& pathToFile);
    };
};

#endif
