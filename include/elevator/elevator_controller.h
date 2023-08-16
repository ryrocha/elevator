#ifndef ELEVATOR_CONTROLLER_H
#define ELEVATOR_CONTROLLER_H

#include <vector>

struct RESULT {
    double travel_time;
    std::vector<int> floors_visited;
};

class ElevatorController {
public:
    RESULT add_floors(std::vector<int>& floors, double floor_time = 10);
};

#endif