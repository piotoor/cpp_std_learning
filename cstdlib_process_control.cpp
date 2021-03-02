#include <iostream>
#include <cstdlib>
#include <string>

void foo(void) {
    std::cout << "foo()" << std::endl;
}

void bar(void) {
    std::cout << "bar()" << std::endl;
}

void quick_foo(void) {
    std::cout << "quick_foo()" << std::endl;
}

void quick_bar(void) {
    std::cout << "quick_bar()" << std::endl;
}

class A {
    public:
        A(std::string x):x(x) {
            std::cout << "A(" << x << ")" << std::endl;
        }
        ~A() {
            std::cout << "~A(" << x << ")" << std::endl;
        }
    private:
        std::string x;
};

A b("b");


int main() {
    A a("a");
    atexit(foo);
    atexit(bar);
    at_quick_exit(quick_foo);
    at_quick_exit(quick_bar);

    std::cout << std::endl << "---------------------------------------------" << std::endl;
    std::cout << "How do you want to end this?" << std::endl
              << "e - exit()" << std::endl
              << "q - quick_exit()" << std::endl
              << "x - _Exit()" << std::endl
              << "a - abort()" << std::endl
              << "other - return" << std::endl;
    char choice;
    std::cout << "Your choice: ";
    std::cin >> choice;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << std::endl;
    switch (choice) {
      case 'e':
        exit(0);        // destroys only static + runs atexit routines + exits normally
        break;
      case 'q':
        quick_exit(0);  // doesn't destroy anything + runs at_quick_exit routines + exits normally
        break;
      case 'x':
        _Exit(0);       // doesn't destroy anything + doesn't run anything + exits normally
        break;
      case 'a':
        abort();        // doesn't destroy anything + doesn't run anything + exits abnormally
        break;
      default:
        return 0;       // destroys everything + runs atexit routines + exits normally
        break;
    }
}
