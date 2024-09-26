#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <cmath>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

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
        sf::SoundBuffer buffer;
        sf::Sound sound;

    };
};

#endif
