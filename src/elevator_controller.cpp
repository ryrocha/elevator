#include <elevator/elevator_controller.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

RESULT ElevatorController::add_floors(vector<int>& floors, double floor_time) {
    int num_floors = 0;

    if (floors.size() > 1) {
        int first_floor = floors[0];
        // We want to ensure that duplicates don't show up in the list of floors
        // that were traveled to
        set<int> s(floors.begin(), floors.end());
        floors.assign(s.begin(), s.end());

        int max = floors.back();
        int min = floors[0];

        int first_to_max = max - first_floor;
        int first_to_min = first_floor - min;

        if (first_to_max > first_to_min) {
            num_floors = max - min + first_to_min;
        } else {
            reverse(floors.begin(), floors.end());
            num_floors = max - min + first_to_max;
        }

        vector<int>::iterator first_it = find(floors.begin(), floors.end(), first_floor);
        int first_idx = distance(floors.begin(), first_it);
        reverse(floors.begin(), floors.begin() + first_idx);
        floors.erase(floors.begin() + first_idx);
        floors.insert(floors.begin(), first_floor);
    }

    RESULT result;
    result.travel_time = num_floors * floor_time;
    result.floors_visited = floors;

    return result;
}
