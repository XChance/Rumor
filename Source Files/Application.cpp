#include <iostream>
#include"../Header Files/Application.h"

//Constructor, sets up renderWindow
Application::Application() : renderWindow(sf::VideoMode(WIDTH, HEIGHT), "Rumor") {
    renderWindow.setVerticalSyncEnabled(true);
    renderWindow.setFramerateLimit(30);

    windowView = renderWindow.getDefaultView();

    if(!font.loadFromFile("../Resources/Arial.ttf")){}

    steps = 0;
    stepsAmt = sf::Text(std::to_string(steps), font, 18);
    stepsAmt.setFillColor(sf::Color::Black);

    paused = true;
}

//Program loop
void Application::run() {
    while(renderWindow.isOpen()){
        if(!paused) {
            update();
        }
        render();
        pollEvents();
    }
}

//Updates automaton
void Application::update() {
    automaton.update();
    steps++;
}

//Wipes screen, redraws automaton each frame
void Application::render() {
    renderWindow.clear(sf::Color(80, 160, 130));

    renderWindow.setView(windowView);

    automaton.render(renderWindow);

    stepsAmt.setString(std::to_string(steps));

    renderWindow.draw(stepsAmt);

    renderWindow.display();
}

//Checks using SFML Event if user has tried to close program
//Also checks arrow keys for zooming in and out of frame by influencing windowView
void Application::pollEvents() {
    sf::Event windowEvent;

    while (renderWindow.pollEvent(windowEvent)) {
        if (windowEvent.type == sf::Event::Closed) {
            renderWindow.close();
        }else if (windowEvent.type == sf::Event::KeyReleased) {
            if (windowEvent.key.code == sf::Keyboard::Space) {
                paused = !paused;
            } else if (windowEvent.key.code == sf::Keyboard::Up) {
                windowView.zoom(0.95f);
            } else if (windowEvent.key.code == sf::Keyboard::Down) {
                windowView.zoom(1.05f);
            }
        }
    }

}