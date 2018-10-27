#ifndef PREDATOR_AND_PREY_APPLICATION_H
#define PREDATOR_AND_PREY_APPLICATION_H

#include "SFML/Graphics.hpp"
#include "Automaton.h"

class Application{
public:
    Application();

    void run();

    static const int WIDTH = 800, HEIGHT = 800;

private:
    void update();
    void render();
    void pollEvents();

    sf::RenderWindow renderWindow;

    sf::View windowView;

    sf::Font font;
    sf::Text stepsAmt;

    //The object that handles the Automaton's logic
    Automaton automaton;
    bool paused;
    int steps;
};

#endif //PREDATOR_AND_PREY_APPLICATION_H
