all: Test OSLLTest OSULLTest

Test: Test.o
	g++ -Wall -o Test Test.o  

Test.o: Test.cpp OSLL.h OSULL.h
	g++ -Wall -o Test.o -c Test.cpp 

OSLLTest: OSLLTest.o
	g++ -Wall -o OSLLTest OSLLTest.o  

OSLLTest.o: OSLLTest.cpp OSLL.h
	g++ -Wall -o OSLLTest.o -c OSLLTest.cpp 

OSULLTest: OSULLTest.o
	g++ -Wall -o OSULLTest OSULLTest.o  

OSULLTest.o: OSULLTest.cpp OSULL.h
	g++ -Wall -o OSULLTest.o -c OSULLTest.cpp 

clean:
	rm -f Test OSLLTest OSULLTest  *.o
