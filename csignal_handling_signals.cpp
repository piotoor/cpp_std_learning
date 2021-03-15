#include <iostream>
#include <csignal>
#include <vector>
#include <string>
#include <iterator>

namespace {
    volatile std::sig_atomic_t status;
}

void handler(int sig) {
    status = sig;
}

int main() {
    std::vector<int> signals {
        SIGABRT, SIGINT, SIGFPE, SIGILL, SIGSEGV, SIGTERM
    };

    std::vector<std::string> signalsToStr {
        "SIGABRT", "SIGINT", "SIGFPE", "SIGILL", "SIGSEGV", "SIGTERM"
    };

    for (const auto &sig: signals) {
        std::signal(sig, handler);
    }

    for (int i = 0; i < size(signals); ++i) {
        std::cout << "Raising signal:\t" << signalsToStr[i] << std::endl;
        std::raise(signals[i]);
        std::cout << "\tstatus:\t" << status << std::endl;
    }

    return 0;
}
