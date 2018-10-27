#include <iostream>
#include "../Header Files/Person.h"

Person::Person() {
    int temp = Random::get().floatInRange(0, 10000);

    if(temp <= 0.5){
        rumor.belief = Random::get().intInRange(10, 30);
        rumor.knowRumor = true;
    }else{
        rumor.belief = 0;
        rumor.knowRumor = false;
    }

    reputation = Random::get().floatInRange(10, 65);
    spreadAmt = 0;
}

void Person::update(Person &person) {
    if(spreadAmt < 4){
    switch(person.rumor.knowRumor) {
        case true:
            if ((rumor.belief < MAX_REP - 50) && person.rumor.belief >= 50) {
                rumor.belief += (person.rumor.belief - person.reputation);
                rumor.knowRumor = true;
            }else{
                rumor.belief += Random::get().intInRange(0, 1);
                rumor.knowRumor = true;
            }
                person.spreadAmt++;
            break;
        case false:
            if (rumor.knowRumor) {
                person.rumor.knowRumor = true;

                if(rumor.belief >= 50) {
                    person.rumor.belief += rumor.belief;
                }else{
                    person.rumor.belief += Random::get().intInRange(0, 1);
                }
                spreadAmt++;
            }
            break;
        }
    }

    if(rumor.belief >= MAX_REP){
        rumor.belief = MAX_REP;
    }else if(rumor.belief < MIN_REP){
        rumor.belief = MIN_REP;
    }

    if(person.rumor.belief >= MAX_REP){
        person.rumor.belief = MAX_REP;
    }else if(person.rumor.belief < MIN_REP){
        person.rumor.belief = MIN_REP;
    }

}

float Person::getBelief() {
    return rumor.belief;
}

bool Person::getKnow() {
    return rumor.knowRumor;
}