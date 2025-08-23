#include "Fixed.hpp"

int main( void ) {

    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    // Fixed a;
    // Fixed b(5.05f * 2);

    // Fixed const c(5.05f * 2);
    // Fixed const d(5.05f * 2);

    // std::cout << "\n --------Comparison Operators--------\n" << std::endl;
    // std::cout << "a == b: " << (a == b) << std::endl;
    // std::cout << "a != b: " << (a != b) << std::endl;
    // std::cout << "a < b: " << (a < b) << std::endl;
    // std::cout << "a <= b: " << (a <= b) << std::endl;
    // std::cout << "a > b: " << (a > b) << std::endl;
    // std::cout << "a >= b: " << (a >= b) << std::endl;

    // std::cout << "\n--------Arithmetic Operators--------\n" << std::endl;
    // std::cout << "a + b: " << (a + b) << std::endl;
    // std::cout << "a - b: " << (a - b) << std::endl;
    // std::cout << "a * b: " << (a * b) << std::endl;
    // std::cout << "a / b: " << (a / b) << std::endl;

    // std::cout << "\n--------Increment/Decrement Operators--------\n" << std::endl;
    // std::cout << "a--: " << a-- << std::endl;
    // std::cout << "a: " << a << std::endl;
    // std::cout << "--a: " << --a << std::endl;   
    // std::cout << "a: " << a << std::endl;
    // std::cout << "++a: " << ++a << std::endl;
    // std::cout << "a: " << a << std::endl;
    // std::cout << "a++: " << a++ << std::endl;
    // std::cout << "a: " << a << std::endl;

    // std::cout << "\n--------Min/Max Functions--------\n" << std::endl;
    // std::cout << "Min of a and b: " << Fixed::min(a, b) << std::endl;
    // std::cout << "Max of a and b: " << Fixed::max(a, b) << std::endl;
    // std::cout << "Min of c and d: " << Fixed::min(c, d) << std::endl;
    // std::cout << "Max of c and d: " << Fixed::max(c, d) << std::endl;


    // std::cout << "\n--------End of program--------\n" << std::endl;

    return 0;
}
