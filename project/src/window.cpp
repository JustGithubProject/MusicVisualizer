#include "window.hpp"

namespace MusicVisualizer {

Window::Window(size_t width, size_t height, std::string windowTitle)
    :  width(width),
       height(height),
       windowTitle(windowTitle),
       window(sf::VideoMode(width, height), windowTitle) {}

void Window::run() {
    while (window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.display();
    }
}

};