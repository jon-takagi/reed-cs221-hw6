test-htree : htree-test.cpp htree.cpp
	g++ -g -Wall -Wextra -pedantic -Werror -o test-htree htree-test.cpp
clean:
	rm -rf *.o
