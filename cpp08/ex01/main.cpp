#include <iostream>
#include <vector>
#include <cstdlib>
#include "Span.hpp"

int main()
{

    std::cout << "===== Small tests =====" << std::endl;
    try {
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: "  << sp.longestSpan()  << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }


    std::cout << "\n===== Big test (10,000 numbers) =====" << std::endl;
    try {
        Span big(10000);

        for (int i = 0; i < 10000; i++) {
            big.addNumber(i);
        }

        std::cout << "Shortest span: " << big.shortestSpan() << std::endl;
        std::cout << "Longest span: "  << big.longestSpan()  << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
