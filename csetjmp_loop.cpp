#include <iostream>
#include <csetjmp>
#include <vector>
#include <string>
#include <iterator>

void printVector(const std::vector<int> &vect) {
    std::jmp_buf buff;
    volatile int counter = -1;

    int i = setjmp(buff);
    if (i < size(vect)) {
        std::cout << "vect[" << i << "] = " << vect[i] << std::endl;
        std::longjmp(buff, ++counter);
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vect = {1, 2, 6, 56, 4, 6, 8, 9, 0};
    std::cout << "vect:" << std::endl;
    printVector(vect);

    std::vector<int> vect2 = {100, 200, 300, 400, 700, 600, 500, 900, 800, 150};
    std::cout << "vect2:" << std::endl;
    printVector(vect2);
    
    return 0;
}
