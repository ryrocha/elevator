#include <cxxopts.hpp>
#include <elevator/elevator_controller.h>
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
    cxxopts::Options options("run_elevator",
        "Runs the elevator over a given list of floors.");

    options.positional_help("[optional args]").show_positional_help();

    options.add_options()
        ("floors",
            "A list of ints representing desired floors. "
            "Example input --floors=12,2,9,1,32",
            cxxopts::value<std::vector<int>>())
        ("t,floor_time", "A double representing the travel time between floors",
            cxxopts::value<double>()->default_value("10"))
        ("h,help", "Print usage and exit");

    options.parse_positional({"floors"});

    auto opts = options.parse(argc, argv);

    if (opts.count("help")) {
        std::cout << options.help() << std::endl;
        exit(0);
    };

    std::vector<int> floors = opts["floors"].as<std::vector<int>>();
    double floor_time = opts["floor_time"].as<double>();

    ElevatorController controller;
    RESULT result = controller.add_floors(floors, floor_time);

    std::cout << "Total travel time: " << result.travel_time << std::endl;
    std::cout << "Floors visited (in order): ";
    for (const int& floor : result.floors_visited) {
        std::cout << floor << " ";
    };
    std::cout << std::endl;
}