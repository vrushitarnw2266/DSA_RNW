#include "Escalator.h"
#include <iostream>

int main() {
    std::cout << "========== ESCALATOR SYSTEM SIMULATION ==========" << std::endl;
    std::cout << std::endl;

    // Create an escalator with capacity 5
    Escalator escalator(5, "UP");
    std::cout << std::endl;

    // Test 1: Board multiple people
    std::cout << "--- Test 1: Boarding People ---" << std::endl;
    escalator.boardPerson(1, "Alice", 5);
    escalator.boardPerson(2, "Bob", 6);
    escalator.boardPerson(3, "Charlie", 7);
    escalator.boardPerson(4, "Diana", 8);
    escalator.boardPerson(5, "Eve", 9);
    std::cout << std::endl;

    // Test 2: Check occupancy
    std::cout << "--- Test 2: Check Occupancy ---" << std::endl;
    escalator.checkOccupancy();
    std::cout << std::endl;

    // Test 3: Try to board when full
    std::cout << "--- Test 3: Try to Board When Full ---" << std::endl;
    escalator.boardPerson(6, "Frank", 10);
    std::cout << std::endl;

    // Test 4: Move escalator
    std::cout << "--- Test 4: Move Escalator ---" << std::endl;
    for (int i = 0; i < 3; i++) {
        escalator.moveEscalator(1);
    }
    std::cout << std::endl;

    // Test 5: People exit
    std::cout << "--- Test 5: People Exit Escalator ---" << std::endl;
    escalator.exitPerson();
    escalator.exitPerson();
    std::cout << std::endl;

    // Test 6: Check occupancy after exits
    std::cout << "--- Test 6: Check Occupancy After Exits ---" << std::endl;
    escalator.checkOccupancy();
    std::cout << std::endl;

    // Test 7: Change direction
    std::cout << "--- Test 7: Change Direction ---" << std::endl;
    escalator.setDirection("DOWN");
    escalator.moveEscalator(2);
    std::cout << std::endl;

    // Test 8: Board more people
    std::cout << "--- Test 8: Board More People ---" << std::endl;
    escalator.boardPerson(6, "Frank", 10);
    escalator.boardPerson(7, "Grace", 11);
    std::cout << std::endl;

    // Test 9: Check status
    std::cout << "--- Test 9: Check Escalator Status ---" << std::endl;
    std::cout << "Current Floor: " << escalator.getCurrentFloor() << std::endl;
    std::cout << "Direction: " << escalator.getDirection() << std::endl;
    std::cout << "Occupancy: " << escalator.getOccupancy() << std::endl;
    escalator.checkOccupancy();
    std::cout << std::endl;

    // Test 10: Emergency stop
    std::cout << "--- Test 10: Emergency Stop ---" << std::endl;
    escalator.emergencyStop();
    std::cout << std::endl;

    // Test 11: Final status
    std::cout << "--- Test 11: Final Occupancy ---" << std::endl;
    escalator.checkOccupancy();
    std::cout << std::endl;

    std::cout << "========== SIMULATION COMPLETE ==========" << std::endl;

    return 0;
}
