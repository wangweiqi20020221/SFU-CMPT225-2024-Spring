all: Test

Test: Test.o
	g++ -Wall -o Test Test.o  

Test.o: Test.cpp IPQ.h
	g++ -Wall -o Test.o -c Test.cpp 

clean:
	rm -f Test *.o
