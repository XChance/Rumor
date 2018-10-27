#include "../Header Files/Automaton.h"
#include <iostream>

Automaton::Automaton() : people(WIDTH * HEIGHT){
    cellVertices.reserve(WIDTH * HEIGHT * 4);
    cellForEach([&](int x, int y){
        addQuad(x, y);
    });

    cellForEach([&](int x, int y){
        setCellColor(x, y, getCellColor(people[getCellIndex(x, y)]));
    });
}

void Automaton::update() {
    std::vector<Person> peopleCopy = people;
    cellForEach([&](int x, int y) {
        int index = getCellIndex(x, y);

        int rand = Random::get().intInRange(0, 9);
        sf::Vector2i personPos = getNewCellPos(rand);
        int newX = x + personPos.x;
        int newY = y + personPos.y;

        if(!(newX >= WIDTH || newX <= 0 || newY >= HEIGHT || newY <= 0)) {
            Person &neighbor = people[getCellIndex(newX, newY)];
            peopleCopy[index].update(neighbor);
        }

    });

    people = peopleCopy;

    cellForEach([&](int x, int y) {
        setCellColor(x, y, getCellColor(people[getCellIndex(x, y)]));
    });

}

void Automaton::render(sf::RenderWindow &renderWindow) {
    renderWindow.draw(cellVertices.data(), cellVertices.size(), sf::Quads);
}

void Automaton::setCellColor(int xIndex, int yIndex, sf::Color color) {
    int index = getCellIndex(xIndex, yIndex) * 4;
    for (int i = 0; i < 4; i++) {
        cellVertices[index + i].color = color;
    }
}

sf::Color Automaton::getCellColor(Person &person) {
    if(!person.getKnow()){
        return sf::Color(80, 160, 130);
    }else {

        int tempBelief = (int) person.getBelief();
        if (tempBelief >= 300) {
            return sf::Color(0, 100, 255);
        } else {
            if(tempBelief >= 50) {
                return sf::Color(0, 0, tempBelief);
            }else{
                return sf::Color(0, 0, 0);
            }
        }

    }

}

void Automaton::addQuad(int xIndex, int yIndex) {
    sf::Vertex topLeft;
    sf::Vertex topRight;
    sf::Vertex bottomLeft;
    sf::Vertex bottomRight;

    float pixelX = xIndex * CELL_SIZE;
    float pixelY = yIndex * CELL_SIZE;

    topLeft.position = { pixelX, pixelY };
    topRight.position = { pixelX + CELL_SIZE, pixelY };
    bottomLeft.position = { pixelX, pixelY + CELL_SIZE };
    bottomRight.position = { pixelX + CELL_SIZE, pixelY + CELL_SIZE };

    cellVertices.push_back(topLeft);
    cellVertices.push_back(bottomLeft);
    cellVertices.push_back(bottomRight);
    cellVertices.push_back(topRight);
}

sf::Vector2i Automaton::getNewCellPos(int i) {
    sf::Vector2i newPos;
    switch(i){
        case 0:
            newPos.x = -1;
            newPos.y = -1;
            break;
        case 1:
            newPos.x = 0;
            newPos.y = -1;
            break;
        case 2:
            newPos.x = 1;
            newPos.y = -1;
            break;
        case 3:
            newPos.x = -1;
            newPos.y = 0;
            break;
        case 4:
            newPos.x = 0;
            newPos.y = 0;
            break;
        case 5:
            newPos.x = 1;
            newPos.y = 0;
            break;
        case 6:
            newPos.x = -1;
            newPos.y = 1;
            break;
        case 7:
            newPos.x = 0;
            newPos.y = 1;
            break;
        case 9:
            newPos.x = 1;
            newPos.y = 1;
            break;
    }

    return newPos;

}
