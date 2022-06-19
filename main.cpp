#include<iostream>
#include "Elevator.cpp"
#include "ElevatorManager.cpp"
using namespace std;

int main()
{
    ElevatorManager E1;
    E1.RqstElevator(3, 1);
    E1.RqstElevator(2, 1);
    E1.UpdateElevators();
    return 0;
}