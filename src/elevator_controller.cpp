#include <elevator/elevator_controller.h>
#include <vector>
#include <cmath>

using namespace std;

RESULT ElevatorController::add_floors(vector<int>& floors, double floor_time) {
    int num_floors = 0;
    for (int i {1}; i < floors.size(); ++i) {
        num_floors += abs(floors[i] - floors[i-1]);
    };

    RESULT result;
    result.travel_time = num_floors * floor_time;
    result.floors_visited = floors;

    return result;
}
