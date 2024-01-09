
output: main.o librarian.o member.o person.o book.o	
	g++ main.o librarian.o member.o person.o book.o -o output

main.o: main.cpp
	g++ -c main.cpp

librarian.o: librarian.cpp librarian.h
	g++ -c librarian.cpp

member.o: member.cpp member.h
	g++ -c member.cpp

person.o: person.cpp person.h
	g++ -c person.cpp

book.o: book.cpp book.h
	g++ -c book.cpp



clean:
	rm *.o output

