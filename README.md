# HW1 README File
Implementations for the Recursive and Unrolled linked lists. 

split.cpp and the test file compiles,does not have memory leaks, and passes tests.
g++ -g -Wall -std=c++11 -c split.cpp
g++ -g -Wall -std=c++11 test_split.cpp split.cpp -o test_split
valgrind --tool=memcheck --leak-check=yes ./test_split
bash ./grade_split.sh

ulliststr.cpp adn the test file compiles, does not have mrmory leaks, and passes tests.
 g++ -g -Wall ulliststr.cpp test_ulliststr.cpp -o test_ulliststr
 bash ./grade_ulliststr.sh
