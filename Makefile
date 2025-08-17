# Abdalla Kharoub
# 665282497

output: a7.o main.o
	g++ a7.o main.o -o output -g -Wall -Wextra

a7.o: a7.cpp a7.h
	g++ -c a7.cpp -g -Wall -Wextra

main.o: main.cpp a7.h
	g++ -c main.cpp -g -Wall -Wextra

.PHONY: clean
clean:
	rm -r *.o output