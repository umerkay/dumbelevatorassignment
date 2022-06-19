#include "ElevatorManager.h"
#include<iostream>
#include<windows.h>
using namespace std;

int ElevatorManager::maxFloor = 5;
int ElevatorManager::minFloor = 0;

ElevatorManager::ElevatorManager() {
        for(int i = 0; i < 2; i++) {
            elevators[i] = new Elevator();
        }

        for(int i = 0; i < 6; i++) {
            ReqstdFloors[i] = 0;
            //0 not requested
            //-1 request for going down
            //1 request for going up
        }
        DrawElevators();
}

void ElevatorManager::RqstElevator(int floor, int dir) {
    if(floor >= minFloor && floor <= maxFloor) {
        ReqstdFloors[floor] = dir;
        if(!elevators[0]->canService(floor)) {
            elevators[1]->canService(floor);
        }
    }
    DrawElevators();
}

void ElevatorManager::UpdateElevators() {
    if(elevators[0]->isMoving) {
        if(elevators[0]->dir == 1) elevators[0]->goUp();
        if(elevators[0]->dir == -1) elevators[0]->goDown();

        if(ReqstdFloors[elevators[0]->getFloor()] == elevators[0]->dir) {
            ReqstdFloors[elevators[0]->getFloor()] = 0;
            elevators[0]->stop();
        }
    }
    if(elevators[1]->isMoving) {
        if(elevators[1]->dir == 1) elevators[1]->goUp();
        if(elevators[1]->dir == -1) elevators[1]->goDown();

        if(ReqstdFloors[elevators[1]->getFloor()] == elevators[1]->dir) {
            ReqstdFloors[elevators[1]->getFloor()] = 0;
            elevators[1]->stop();
        }
    }

    DrawElevators();
    Sleep(1000);
    UpdateElevators();
}

void ElevatorManager::DrawElevators() {
    system("cls");
    for(int i = maxFloor; i >= 0; i--) {
        cout << i;
        cout << (ReqstdFloors[i] == 1 ? "^" : (ReqstdFloors[i] == -1 ? "v" : " "));
        if(elevators[0]->getFloor() == i) {
            elevators[0]->draw();
        }
        cout << "     ";
        if(elevators[1]->getFloor() == i) {
            elevators[1]->draw();
        }
        cout<<endl;
    }
}