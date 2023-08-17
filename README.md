# elevator

This repository contains all the necessary tooling to build, install and test an executable that computes the total travel time of an elevator given a specified set of floors to visit.

## Environment

The following assumes `docker` is installed. The repository implements a `Makefile` for ease of use if running from a Linux environment.

## Running the executable

To run the executable:
```
$> make run
$> ./run_elevator -h

Runs the elevator over a given list of floors.
Usage:
  run_elevator [OPTION...] [optional args]

      --floors arg      A list of ints representing desired floors. Example
                        input --floors=12,2,9,1,32
  -t, --floor_time arg  A double representing the travel time between
                        floors (default: 10)
  -h, --help            Print usage and exit

```
Usage example:
```
$> ./run_elevator --floors=12,2,9,1,32 -t 5

Total travel time: 280
Floors visited (in order): 12 2 9 1 32
```
Use `make start_run` to shell back into the container if `make run` was called previously but the shell is no longer active.

## Running the tests

To run the tests:
```
$> make tests
$> ./test_elevator

Randomness seeded to: 634903484
===============================================================================
All tests passed (6 assertions in 3 test cases)
```
The test suite makes use of the [Catch2](https://github.com/catchorg/Catch2) unit testing framework.

Use `make start_tests` to shell back into the testing container if `make tests` was called previously but the shell is no longer active.

## Cleanup
A `make clean` target has also been included to help with cleanup. This will forcefully remove all containers and images created from the above steps.
