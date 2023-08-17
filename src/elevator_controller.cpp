#include <elevator/elevator_controller.h>
#include <vector>
#include <cmath>

using namespace std;

RESULT ElevatorController::add_floors(vector<int>& floors, double floor_time) {
    int num_floors = 0;
    vector<int> floors_visited;

    if (! floors.empty()) {
        floors_visited.push_back(floors[0]);
    };

    for (int i {1}; i < floors.size(); ++i) {
        int last_floor = floors[i-1];
        int next_floor = floors[i];
        // We want consecutively repeated floors to show up once in our list of
        // visited floors
        if (next_floor != last_floor) {
            num_floors += abs(next_floor - last_floor);
            floors_visited.push_back(next_floor);
        }
    };

    RESULT result;
    result.travel_time = num_floors * floor_time;
    result.floors_visited = floors_visited;

    return result;
}
