all: DQtest DQarreytest
DQtest: DQtest.o
	g++ -o DQtest DQtest.o
DQtest.o: DQtest.cpp Vector.h Tvector.h Stack.h Ivector.h Deque.h dsexceptions.h
	 g++ -Wall -o DQtest.o -c DQtest.cpp
DQarreytest: DQarreytest.o
	g++ -o DQarreytest DQarreytest.o
DQarreytest.o : DQarreytest.cpp Deque.h
	g++ -o DQarreytest.o -c DQarreytest.cpp
clean :
	rm -f DQarreytest DQarreytest *.o
