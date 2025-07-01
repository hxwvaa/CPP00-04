#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>

// A function to display text formatted as requested
static void printFormatted(const std::string& str) {
    // Set justification to right and width to 10
    std::cout << std::right << std::setw(10);

    if (str.length() > 10) {
        // If string is too long, print the first 9 chars and a dot
        std::cout << str.substr(0, 9) + ".";
    } else {
        // Otherwise, print the string
        std::cout << str;
    }
}

PhoneBook::PhoneBook() : _currentIndex(0), _contactCount(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(const Contact& contact) {
    _contacts[_currentIndex] = contact;
    _currentIndex = (_currentIndex + 1) % 8; // Wrap around if we exceed 8 contacts
    if (_contactCount < 8) {
        _contactCount++;
    }
}

// void PhoneBook::addContact(const std::string& firstName, const std::string& lastName,
//                             const std::string& nickname, const std::string& phoneNumber,
//                             const std::string& darkestSecret) {
//     _contacts[_currentIndex].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
//     _currentIndex = (_currentIndex + 1) % 8; // Wrap around if we exceed 8 contacts
//     if (_contactCount < 8) {
//         _contactCount++;
//     }
// }


void PhoneBook::displayContacts() const {
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    
    for (int i = 0; i < _contactCount; ++i) {
        std::cout << std::setw(10) << i << "|";
        printFormatted(_contacts[i].getFirstName());
        std::cout << "|";
        printFormatted(_contacts[i].getLastName());
        std::cout << "|";
        printFormatted(_contacts[i].getNickname());
        std::cout << std::endl;
    }
}

void PhoneBook::displayContact(int index) const {
    if (index < 0 || index >= _contactCount) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    
    const Contact& contact = _contacts[index];
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickname() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

int PhoneBook::getContactCount() const {
    return _contactCount;
}

