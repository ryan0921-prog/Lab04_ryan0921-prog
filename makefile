all: examheap 

examheap: examheap.cpp heap.cpp
	g++ -c examheap.cpp 
	g++ -c heap.cpp 
	g++ examheap.o heap.o -o examheap 

clean: 
	rm -f examheap *.o