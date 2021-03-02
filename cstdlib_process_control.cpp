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

#ifdef EXIT
    exit(0);          // destroys only static + runs atexit routines + exits normally
#elseif QUICK_EXIT
    quick_exit(0);    // doesn't destroy anything + runs at_quick_exit routines + exits normally
#elseif _EXIT
    _Exit(0);         // doesn't destroy anything + doesn't run anything + exits normally
#elseif ABORT
    abort();          // doesn't destroy anything + doesn't run anything + exits abnormally
#else
    return 0;         // destroys everything + runs atexit routines + exits normally
#endif

}
