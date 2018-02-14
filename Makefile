all: main.cpp
	g++ -g -Wall -std=c++11 -o LoveLetter main.cpp

clean:
	$(RM) LoveLetter
