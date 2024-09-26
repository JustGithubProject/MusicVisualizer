#include "window.hpp"

namespace MusicVisualizer {

Window::Window(size_t width, size_t height, std::string windowTitle)
    :  width(width),
       height(height),
       windowTitle(windowTitle),
       window(sf::VideoMode(width, height), windowTitle) {}


void Window::run() {
    std::string pathToFile = "/home/kropiva/Downloads/output.wav";
    // Window::startMusicHelper(pathToFile);
    if (!buffer.loadFromFile(pathToFile)) {
        std::cerr << "Failed to load file" << std::endl;
        return;
    }
    const sf::Int16* samples = buffer.getSamples();
    size_t sampleCount = buffer.getSampleCount();
    unsigned int sampleRate = buffer.getSampleRate();

    sound.setBuffer(buffer);
    sound.play();

    while (window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();

        sf::Time currentTime = sound.getPlayingOffset();
        size_t currentSample = currentTime.asSeconds() * sampleRate;

        // Amount of samples to display
        size_t samplesToDisplay = window.getSize().x;
        std::vector<sf::Vertex> vertices(samplesToDisplay * 2);

        for (std::size_t i = 0; i < samplesToDisplay; ++i) {
            if (currentSample + i < sampleCount) {
                float amplitude = samples[currentSample + i] / 32768.0f; 
                float x = static_cast<float>(i);
                float y = window.getSize().y / 2 * (1 - amplitude);

                vertices[i * 2] = sf::Vertex(sf::Vector2f(x, window.getSize().y / 2), sf::Color::White);
                vertices[i * 2 + 1] = sf::Vertex(sf::Vector2f(x, y), sf::Color::White);
            }
        }

        window.draw(&vertices[0], vertices.size(), sf::Lines);

        window.display();
    }
}

};