run:
	docker build -f ./Dockerfile --build-arg tests=OFF --tag=elevator_run:latest .
	docker run --name run_elevator -w /elevator/build/src -it elevator_run:latest

start_run:
	docker start -i run_elevator

tests:
	docker build -f ./Dockerfile --tag=elevator_test:latest .
	docker run --name test_elevator -w /elevator/build/test -it elevator_test:latest

start_tests:
	docker start -i test_elevator

clean:
	docker container rm -f run_elevator
	docker image rm -f elevator_run:latest

	docker container rm -f test_elevator
	docker image rm -f elevator_test:latest