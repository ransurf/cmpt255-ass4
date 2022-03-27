/*
 * Event.h
 *
 * Class Description: Models an event (arrival or departure)
 * Class Invariant:  Must be of type Departure or Arrival (D or A).
 * Last Modified: March 2022
 * Author: Daehyung Kwak
 */
#pragma once
#include <string>

using namespace std;

class Event {

private:

    char type; // A or D (Arrival or Departure)
    int time;
    int length;

public:

    // Constants
    const static char ARRIVAL = 'A';
    const static char DEPARTURE = 'D';

    // Description: Default constructor for event class
    Event();

    // Description: Parametrized constructor for departure event
    Event(int time);

    // Description: Parametrized constructor for event class
    Event(char type, int time, int length);

    // Getters and Setters

    // Description: Returns type of event (arrival or departure)
    // Post-Condition: Nothing changed
    char getType() const;

    // Description: Returns time of event
    // Post-Condition: Nothing changed
    int getTime() const;

    // Description: Returns length of event
    // Post-Condition: Nothing changed
    int getLength() const;

    // Description: Sets type of event, A or D, or just A if neither is input
    // Pre-Condition: Options are A or D chars
    // Post-Condition: Type is A or D
    void setType(const char type);

    // Description: Sets time of event, or 0 if time is less than zero
    // Pre-Condition: time is greater than 0
    // Post-Condition: Type is given time or 0
    void setTime(const int time);

    // Description: Sets length of event, or 0 if length is less than zero
    // Pre-Condition: length is greater than 0
    // Post-Condition: length is given length or 0
    void setLength(const int length);

    // Operators

    // Description: return a bool based on time and type of event
    bool operator<(const Event & rhs);

    // Description: prints the event object
    friend ostream &operator<<(ostream& os, const Event& event);
};

#include "Event.cpp"