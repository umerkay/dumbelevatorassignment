#ifndef ELEVATOR_H
#define ELEVATOR_H

class ElevatorManager;

class Elevator {
    public:
        Elevator();
        void pressButton(int floor);

        void toggleDoor(bool open);
        void goUp();
        void goDown();
        void stop();
        
        bool canService(int floor);

        int getFloor();

        void draw();

        static int maxFloor;
        static int minFloor;

        friend class ElevatorManager;
        
    private:
        bool isDoorOpen, isMoving, isBwFloors;
        int atFloor, toFloor;
        int dir; //-1 for down, 0 for stationary, 1 for up
        bool ReqstdFloors[6]; //keeps record of floors where elevator must go
};

#endif