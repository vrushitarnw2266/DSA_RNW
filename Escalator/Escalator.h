#ifndef ESCALATOR_H
#define ESCALATOR_H

#include "Stack.h"
#include <iostream>
#include <string>

struct Person {
    int id;
    std::string name;
    int floor;

    Person() : id(0), name(""), floor(0) {}
    Person(int id, const std::string& name, int floor) 
        : id(id), name(name), floor(floor) {}

    friend std::ostream& operator<<(std::ostream& os, const Person& p) {
        os << "Person(ID: " << p.id << ", Name: " << p.name << ", Floor: " << p.floor << ")";
        return os;
    }
};

class Escalator {
private:
    Stack<Person> escalatorStack;
    int maxCapacity;
    int currentFloor;
    std::string direction; // "UP" or "DOWN"

public:
    // Constructor
    Escalator(int capacity = 10, std::string dir = "UP") 
        : maxCapacity(capacity), currentFloor(1), direction(dir) {
        std::cout << "Escalator initialized (Capacity: " << maxCapacity 
                  << ", Direction: " << direction << ")" << std::endl;
    }

    // Destructor
    ~Escalator() {
        std::cout << "Escalator destructed" << std::endl;
    }

    // Person boards the escalator
    void boardPerson(int id, const std::string& name, int destinationFloor) {
        if (escalatorStack.getSize() >= maxCapacity) {
            std::cout << "ERROR: Escalator is at full capacity!" << std::endl;
            return;
        }
        
        Person person(id, name, destinationFloor);
        escalatorStack.push(person);
        std::cout << person << " boarded the escalator." << std::endl;
    }

    // Person exits the escalator
    void exitPerson() {
        if (escalatorStack.isEmpty()) {
            std::cout << "No one on the escalator to exit." << std::endl;
            return;
        }
        
        Person person = escalatorStack.pop();
        std::cout << person << " exited the escalator at floor " 
                  << currentFloor << "." << std::endl;
    }

    // Move escalator (simulate movement)
    void moveEscalator(int floors = 1) {
        if (direction == "UP") {
            currentFloor += floors;
        } else {
            currentFloor -= floors;
        }
        std::cout << "Escalator moved " << direction << ". Current floor: " 
                  << currentFloor << std::endl;
    }

    // Check if person is on escalator
    void checkOccupancy() {
        std::cout << "Escalator Occupancy: " << escalatorStack.getSize() 
                  << "/" << maxCapacity << std::endl;
        escalatorStack.display();
    }

    // Get current floor
    int getCurrentFloor() const {
        return currentFloor;
    }

    // Get direction
    std::string getDirection() const {
        return direction;
    }

    // Set direction
    void setDirection(const std::string& newDirection) {
        if (newDirection == "UP" || newDirection == "DOWN") {
            direction = newDirection;
            std::cout << "Escalator direction changed to " << direction << std::endl;
        } else {
            std::cout << "Invalid direction!" << std::endl;
        }
    }

    // Get occupancy level
    int getOccupancy() const {
        return escalatorStack.getSize();
    }

    // Check if escalator is full
    bool isFull() const {
        return escalatorStack.getSize() >= maxCapacity;
    }

    // Empty the escalator
    void emergencyStop() {
        std::cout << "EMERGENCY STOP! Evacuating escalator..." << std::endl;
        while (!escalatorStack.isEmpty()) {
            exitPerson();
        }
        std::cout << "Escalator evacuated." << std::endl;
    }
};

#endif // ESCALATOR_H
