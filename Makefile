build:
	g++ -Wall airline.cpp flight.cpp main.cpp One.cpp passenger.cpp seat.cpp -o airline

run:
	./airline

clean:
	rm airline