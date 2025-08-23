#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called." << std::endl;
}

// Copy constr`initialization
// Copies the raw fixed-point value to preserve exact representation
Fixed::Fixed(const Fixed& other) : _fixedPointValue(other._fixedPointValue) {
    std::cout << "Copy constructor called." << std::endl;
}

// Copy assignment operator: Assigns the value of one Fixed object to another existing object
// Implements self-assignment protection to avoid unnecessary work and potential issues
// Returns reference to *this to enable chaining (e.g., a = b = c)
// Uses getRawBits() to maintain consistent access pattern
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called." << std::endl;
    if (this != &other) {  // Self-assignment check
        _fixedPointValue = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called." << std::endl;
}

// Getter function that returns the raw fixed-point value without any conversion
// The raw value contains both integer and fractional parts as a single integer
// Used for direct access to the underlying representation
int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called." << std::endl;
    return _fixedPointValue;
}

// Setter function that directly assigns a raw value to the fixed-point number
// The input should already be in proper fixed-point format (scaled)
// No conversion or validation is performed on the input value
void Fixed::setRawBits(int const raw) {
    _fixedPointValue = raw;
}