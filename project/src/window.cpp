#include "window.hpp"

namespace MusicVisualizer {

const int numLines = 100; 
const float maxAmplitude = 300;

Window::Window(size_t width, size_t height, std::string windowTitle)
    :  width(width),
       height(height),
       windowTitle(windowTitle),
       window(sf::VideoMode(width, height), windowTitle) {}


void Window::startMusicHelper(const std::string& pathToFile) {
    /*
        Helper function to start music
    */
    result = ma_sound_init_from_file(pathToFile, 0, NULL, NULL, &sound);
    if (result != MA_SUCCESS) {
        std::cerr << "Failed to load music" << std::endl;
        return;
    }
    
    ma_sound_start(&sound);
}

void Window::run() {
    startMusicHelper("/home/kropiva/Downloads/ambient-128950.wav");
    std::vector<sf::Vertex> lines(numLines);

    while (window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::White);

        float currentVolume = 0.0f;
        ma_uint64 totalSamplesRead = 0;
        float buffer[4096];
        while (totalSamplesRead < 4096) {
            ma_uint64 samplesRead = ma_sound_read_pcm_frames(&sound, buffer, 4096);
            if (samplesRead == 0)
                break;
            
            for (ma_uint64 i = 0; i < samplesRead; ++i) {
                currentVolume += std::fabs(buffer[i]);
            }
            
            totalSamplesRead += samplesRead;
        }

        currentVolume /= totalSamplesRead;
        currentVolume *= maxAmplitude;

        for (int i = 0; i < numLines; ++i) {
            float x = static_cast<float>(i) * (800.0f / numLines); 
            float y = 600 - currentVolume; 

            lines[i].position = sf::Vector2f(x, y);
            lines[i].color = sf::Color::Green;
        }

        window.draw(&lines[0], lines.size(), sf::LinesStrip);

        window.display();
    }

    ma_sound_uninit(&sound);
}

};