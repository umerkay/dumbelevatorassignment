#include "Elevator.h"
#include<windows.h>
#include<iostream>
using namespace std;

int Elevator::maxFloor = 5;
int Elevator::minFloor = 0;

Elevator::Elevator() {

        isDoorOpen = false;
        isMoving = false;
        isBwFloors = false;
        atFloor = 0; // 0 for Ground, 1-5 for Floors
        toFloor = -1; // -1 for Stationary, 0 for Ground, 1-5 for Floors
        dir = 0; //-1 for down, 0 for stationary, 1 for up
}

void Elevator::pressButton(int floor) {
    if(floor >= minFloor && floor <= maxFloor && floor != atFloor) {
        ReqstdFloors[floor] = true;

        if(isMoving == false) {
            toFloor = floor;
            dir = toFloor > atFloor ? 1 : -1;
            this->toggleDoor(false);
            cout<<"lll";
            isMoving = true;
        }
    }
    if(floor == atFloor) {
        this->toggleDoor(true);
        // Sleep(3000);
        // this->toggleDoor(false);
    }
}   

bool Elevator::canService(int floor) {
    if((dir == 1 && floor > atFloor) || (dir == -1 && floor < atFloor)) {
        ReqstdFloors[floor] = true;
        return true;
    } else if(isMoving == false) {
        if(floor == atFloor) {
            this->toggleDoor(true);
            return true;
        } else {
            pressButton(floor);
            return true;
        }
    };
    return false;
}

int Elevator::getFloor() {
    return atFloor;
}

void Elevator::draw() {
    cout << (isDoorOpen ? "|  |" : "_||_");
}

void Elevator::toggleDoor(bool open) {
    isDoorOpen = open;
}

void Elevator::goUp() {
    if(atFloor + 1 <= maxFloor) {
        atFloor += 1;
        // if(atFloor == toFloor) {
        //     isMoving = false;
        //     toggleDoor(true);
        //     dir = 0;
        // }
    }
}

void Elevator::goDown() {
    if(atFloor - 1 <= maxFloor) {
        atFloor -= 1;
        // if(atFloor == toFloor) {
        //     isMoving = false;
        //     toggleDoor(true);
        //     dir = 0;
        // }
    }
}

void Elevator::stop() {
    isMoving = false;
    toggleDoor(true);
    dir = 0;
}