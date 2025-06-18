#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() : currentIndex(0), contactCount(0) {
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::addContact(const Contact& contact) {
    contacts[currentIndex] = contact;
    currentIndex = (currentIndex + 1) % 8;
    if (contactCount < 8)
        contactCount++;
}

std::string PhoneBook::truncateString(const std::string& str, size_t width) const {
    if (str.length() > width) {
        return str.substr(0, width - 1) + ".";
    }
    return str;
}

std::string PhoneBook::formatColumn(const std::string& str, size_t width) const {
    std::string truncated = truncateString(str, width);
    return std::string(width - truncated.length(), ' ') + truncated;
}

void PhoneBook::displayContacts() const {
    std::cout << "|" << formatColumn("Index", 10) << "|" 
              << formatColumn("First Name", 10) << "|"
              << formatColumn("Last Name", 10) << "|"
              << formatColumn("Nickname", 10) << "|" << std::endl;
    
    for (int i = 0; i < contactCount; i++) {
        if (!contacts[i].isEmpty()) {
            std::stringstream ss;
            ss << i;
            std::cout << "|" << formatColumn(ss.str(), 10) << "|"
                      << formatColumn(contacts[i].getFirstName(), 10) << "|"
                      << formatColumn(contacts[i].getLastName(), 10) << "|"
                      << formatColumn(contacts[i].getNickname(), 10) << "|" << std::endl;
        }
    }
}

void PhoneBook::displayContact(int index) const {
    if (index < 0 || index >= contactCount || contacts[index].isEmpty()) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

int PhoneBook::getContactCount() const {
    return contactCount;
}
