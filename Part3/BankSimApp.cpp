/*
 * SimulationApp.cpp
 *
 * Description: Handles simulation of events
 * Last Modified: March 2022
 * Author: Daehyung Kwak
 */
#include <iostream>
#include "Queue.h"
#include "PriorityQueue.h"
#include "Event.h"

using namespace std;

#include <sstream>
#include <fstream>
#include <iomanip>

// store sum of waiting time
int sum = 0;
int customerCount = 0;

// Process an arrival event
void processArrival(Event& arrivalEvent, PriorityQueue<Event>& eventPriorityQueue, Queue<Event>& bankLine, int & currentTime, bool & tellerAvailable){
    cout << "Processing an arrival event at time:" << setw(6) << right << currentTime << endl;
    
    eventPriorityQueue.dequeue();
    int departureTime;
    // if there is a teller available, process the customer
    if (bankLine.isEmpty() && tellerAvailable) {
        departureTime = currentTime + arrivalEvent.getLength();
        Event departureEvent = Event('D', departureTime);
        // departureEvent.setTime(departureTime);
        eventPriorityQueue.enqueue(departureEvent);
        tellerAvailable = false;
    // if there is no teller available, add the customer to the bank line
    } else {
        bankLine.enqueue(arrivalEvent);
    }
}

// Process a departure event
void processDeparture(Event& departureEvent, PriorityQueue<Event>& eventPriorityQueue, Queue<Event>& bankLine, int & currentTime, bool & tellerAvailable){
    cout << "Processing a departure event at time:" << setw(5) << right << currentTime << endl;
    eventPriorityQueue.dequeue();

    int departureTime;

    if (!bankLine.isEmpty()){

        try {
            Event customer = bankLine.peek();
            sum = sum + currentTime - customer.getTime(); // update sum of waiting time
            bankLine.dequeue();
            departureTime = currentTime + customer.getLength();
            Event newDepartureEvent = Event('D', departureTime);
            // newDepartureEvent.setTime(departureTime);
            eventPriorityQueue.enqueue(newDepartureEvent);
        } catch (EmptyDataCollectionException& exception){
            cout << exception.what() << endl;
        }

    } else {
        tellerAvailable = true;
    }
}

int main(int argc, char* argv[]) {
    
    // open file
    ifstream inputFile;
    inputFile.open(argv[1]);

    int currentTime = 0;
    Queue<Event> bankLine = Queue<Event>();
    PriorityQueue<Event> eventPriorityQueue = PriorityQueue<Event>();
    bool tellerAvailable = true;
    int customerCount = 0;

    string aLine = "";
    int length = 0;
    int time = 0;
    Event streamEvent;

    cout << "Simulation Begins" << endl;

    while( getline(inputFile, aLine)) {   // while (there is data)

        // get time as first element of line and length as second element of line as strings
        stringstream ss(aLine);
        ss >> time;
        ss >> length;

        // create event and enqueue it if allowed
        streamEvent =  Event();
        streamEvent.setLength(length);
        streamEvent.setTime(time);

        if (!eventPriorityQueue.enqueue(streamEvent)){
            return 1;
        }

        customerCount++;
    }
    inputFile.close();

    // Event Loop
    while (!eventPriorityQueue.isEmpty()) {
        try {
            Event newEvent = eventPriorityQueue.peek();
            currentTime = newEvent.getTime();

            if (newEvent.getType() == Event::ARRIVAL){
                processArrival(newEvent, eventPriorityQueue, bankLine, currentTime, tellerAvailable);
            } else {
                processDeparture(newEvent, eventPriorityQueue, bankLine, currentTime, tellerAvailable);
            }
        } catch (EmptyDataCollectionException & exception){
            cout << exception.what() << endl;
        }
    }

    // Print statistics
    cout << "Simulation Ends" << endl;
    cout << endl;
    cout << "Final Statistics: " << endl;
    cout << endl;
    cout << "    Total number of people processed: " << customerCount << endl;
    cout << "    Average amount of time spent waiting: " << (float)sum/(float)customerCount << endl;
    return 0;
}