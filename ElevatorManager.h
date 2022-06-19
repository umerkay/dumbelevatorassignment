#ifndef ELEVATOR_MANAGER_H
#define ELEVATOR_MANAGER_H
#include "Elevator.h"

class ElevatorManager {
    public:
        ElevatorManager();
        void RqstElevator(int floor, int dir); //return elevator after a few seconds
        void DrawElevators();
        static int maxFloor;
        static int minFloor;
        void UpdateElevators();

    private:
        Elevator* elevators[2];
        int ReqstdFloors[6]; //stores record of floors where elevators are requested
        //0 not requested
        //-1 request for going down
        //1 request for going up
};

#endif