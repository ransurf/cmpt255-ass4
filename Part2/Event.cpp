/*
 * Event.cpp
 *
 * Class Description: Models an event (arrival or departure)
 * Class Invariant:  Must be of type Departure or Arrival (D or A).
 * Last Modified: March 2022
 * Author: Daehyung Kwak
 */
#include <iostream>
#include "Event.h"

using namespace std;

// Description: Default constructor for event class
Event::Event(){
    this->type = ARRIVAL;
    this->time = 0;
    this->length = 0;
}

// Description: Parametrized constructor for departure event
Event::Event(int time){
    this->type = DEPARTURE;
    this->time = time;
    this->length = 0;
}

// Description: Parametrized constructor for event class
Event::Event(char type, int time, int length){
    this->type = type;
    this->time = time;
    this->length = length;
}

// Description: Returns type of event (arrival or departure)
// Post-Condition: Nothing changed
char Event::getType() const {
    return this->type;
}

// Description: Returns time of event
// Post-Condition: Nothing changed
int Event::getTime() const {
    return this->time;
}

// Description: Returns length of event
// Post-Condition: Nothing changed
int Event::getLength() const {
    return this->length;
}

// Description: Sets type of event, A or D, or just A if neither is input
// Pre-Condition: Options are A or D chars
// Post-Condition: Type is A or D
void Event::setType(const char type){
    if (type != ARRIVAL && type != DEPARTURE) {
        this->type = ARRIVAL;
    } else {
        this->type = type;
    }
}

// Description: Sets time of event, or 0 if time is less than zero
// Pre-Condition: time is greater than 0
// Post-Condition: Type is given time or 0
void Event::setTime(const int time){
    if (time < 0) {
        this->time = 0;
    } else {
        this->time = time;
    }
}

// Description: Sets length of event, or 0 if length is less than zero
// Pre-Condition: length is greater than 0
// Post-Condition: length is given length or 0
void Event::setLength(const int length){
    if (length < 0) {
        this->length = 0;
    } else {
        this->length = length;
    }
}

// Description: return a bool based on time and type of event
bool Event::operator<(const Event & rhs){
    if (getTime() == rhs.getTime()){
        return getType() < rhs.getType();
    }
    return getTime() < rhs.getTime();

}



// Description: prints the event object
ostream &operator<<(ostream& os, const Event& event){
    os << event.getType() << ", " << event.getTime() << ", " << event.getLength() << endl;
    return os;
}
