#ifndef RUMOR_PERSON_H
#define RUMOR_PERSON_H

#include "../Header Files/Random.h"
#include "../Header Files/Rumor.h"

class Person {
public:
    Person();

    void update(Person &person);

    float getBelief();
    bool getKnow();

private:

    float reputation;
    const static int MAX_REP = 300, MIN_REP = 0;

    Rumor rumor;
    int spreadAmt;
};


#endif //RUMOR_PERSON_H
