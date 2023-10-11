# Makefile that compiles programs for the coffee shop.

CC=g++ -std=c++11
exe_file=run

$(exe_file): coffee++.cpp coffee.o shop.o menu.o order.o
	$(CC) coffee++.cpp coffee.o shop.o menu.o order.o -o $(exe_file)

coffee.o: coffee.cpp coffee.h
	$(CC) -c coffee.cpp

shop.o: shop.cpp shop.h
	$(CC) -c shop.cpp

menu.o: menu.cpp menu.h
	$(CC) -c menu.cpp

order.o: order.cpp order.h
	$(CC) -c order.cpp

clean:
	rm -f *.o $(exe_file)