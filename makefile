output: main.o book.o bookcollection.o loan.o loancollection.o patron.o patroncollection.o
	g++ -g main.o book.o bookcollection.o loan.o loancollection.o patron.o patroncollection.o -o output

main.o: main.cpp
	g++ -c main.cpp book.h bookcollection.h patroncollection.h loancollection.h

book.o: book.cpp
	g++ -c book.cpp book.h

bookcollection.o: bookcollection.cpp
	g++ -c bookcollection.cpp bookcollection.h

loan.o: loan.cpp
	g++ -c loan.cpp loan.h patroncollection.h bookcollection.h

loancollection.o: loancollection.cpp
	g++ -c loancollection.cpp loancollection.h bookcollection.h patroncollection.h

patron.o: patron.cpp
	g++ -c patron.cpp patron.h

patroncollection.o: patroncollection.cpp
	g++ -c patroncollection.cpp patroncollection.h

clean:
	rm *.o *.gch output