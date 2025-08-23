#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const Fixed& other) : _fixedPointValue(other._fixedPointValue) {
    std::cout << "Copy constructor called." << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called." << std::endl;
    if (this != &other) {
        _fixedPointValue = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called." << std::endl;
}
// Constructor that converts an integer to fixed-point representation
// Shifts the integer left by _fractionalBits (8) to store it in the integer portion
// of the fixed-point number, leaving the fractional bits as zero
Fixed::Fixed(const int value) : _fixedPointValue(value << _fractionalBits) {
    std::cout << "Int constructor called." << std::endl;
}

// Constructor that converts a float to fixed-point representation
// Multiplies the float by 2^_fractionalBits to scale it, then rounds to nearest integer
// This preserves fractional precision up to 1/256 (2^-8) due to 8 fractional bits
Fixed::Fixed(const float value) : _fixedPointValue(roundf(value * (1 << _fractionalBits))) {
    std::cout << "Float constructor called." << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called." << std::endl;
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    _fixedPointValue = raw;
}

float Fixed::toFloat() const {
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt() const {
    return _fixedPointValue >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}