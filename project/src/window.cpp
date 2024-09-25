#include "window.hpp"

namespace MusicVisualizer {

Window::Window(size_t width, size_t height, std::string windowTitle)
    :  width(width),
       height(height),
       windowTitle(windowTitle),
       window(sf::VideoMode(width, height), windowTitle) {}

void Window::run() {
    sf::Music music;
    if (!music.openFromFile("/home/kropiva/Downloads/ambient-128950.wav"))
        std::exit(0);
    music.play();
    while (window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::White);
        window.display();
    }
}

};