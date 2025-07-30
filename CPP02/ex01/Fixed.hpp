#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> // For roundf

class Fixed {
    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;

    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        Fixed(const int value);
        Fixed(const float value);

        int getRawBits() const;
        void setRawBits(int const raw);
        float toFloat() const;
        int toInt() const;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif