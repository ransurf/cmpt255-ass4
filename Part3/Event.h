/*
 * Event.h
 * 
 * Description: Models arrival or departure event.
 * 
 * Class Invariant: Arrival events have type 'A'
 * 					Departure event have type 'D'
 * 
 * Author: AL
 * Last Modified: March 2022
 */

#pragma once
#include <iostream>

using namespace std;

class Event {

private:
	char type;
	int time;
	int length; //only used for arrival events
	
public:
	static const char ARRIVAL = 'A';
	static const char DEPARTURE = 'D';
	
	// Constructor
	Event();
	Event(char type, int time);
	Event(char type, int time, int length);
	
    // Getters
    char getType() const;
    int getTime() const;
    int getLength() const;
    
    // Setters
    void setType( char aType );
    void setTime( int aTime );
    void setLength( int aLength );
	
	// Description: Return true if this event is an arrival event, false otherwise.
	bool isArrival();

	// Overloaded Operators
	// Description: Comparison <= operator. 
	bool operator<=(const Event& rhs);

	// For Testing Purposes
	// Description: Prints the content of "this". 
	friend ostream & operator<<(ostream & os, const Event& rhs);

}; // end of Event.h
