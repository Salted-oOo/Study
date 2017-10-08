.PYHON: clean

out.queue : queue.o queue_function.o
	g++ -o out.queue queue.o queue_function.o

queue.o : queue.cpp
	g++ -o queue.o -c -DTESTCASE queue.cpp

queue_function.o : queue_function.cc queue.h
	g++ -o queue_function.o -c queue_function.cc

clean :
	rm -rf main *.o out.*
