#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <string>

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
    };
};

#endif
