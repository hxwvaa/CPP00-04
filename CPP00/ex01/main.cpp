#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

std::string getInput(const std::string& prompt) {
    std::string input;
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cout << std::endl;
            return "";
        }
    } while (input.empty());
    return input;
}

std::string getphoneNumber(const std::string& prompt) {
    std::string input;
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cout << std::endl;
            return "";
        }
    } while (input.empty() || !input.find_first_not_of("0123456789")) ;
    return input;
}

void addContact(PhoneBook& phoneBook) {
    std::string firstName = getInput("Enter first name: ");
    if (firstName.empty())
        return;
    std::string lastName = getInput("Enter last name: ");
    if (lastName.empty())
        return;
    std::string nickname = getInput("Enter nickname: ");
    if (nickname.empty())
        return;
    std::string phoneNumber = getphoneNumber("Enter phone number: ");
    if (phoneNumber.empty())
        return;
    std::string darkestSecret = getInput("Enter darkest secret: ");
    if (darkestSecret.empty())
        return;
    
    Contact contact;
    contact.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    phoneBook.addContact(contact);
    std::cout << "Contact added successfully!" << std::endl;
}

void searchContact(PhoneBook& phoneBook) {
    if (phoneBook.getContactCount() == 0) {
        std::cout << "No contacts available!" << std::endl;
        return;
    }
    
    phoneBook.displayContacts();
    std::cout << "Enter index to display: ";
    
    std::string input;
    std::getline(std::cin, input);
    if (std::cin.eof()) {
        std::cout << std::endl;
        return;
    }
    
    std::stringstream ss(input);
    int index;
    if (!(ss >> index) || !ss.eof()) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    
    phoneBook.displayContact(index);
}

int main() {
    PhoneBook phoneBook;
    std::string command;
    
    std::cout << "Welcome!" << std::endl;
    
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        
        if (command == "ADD") {
            addContact(phoneBook);
        } else if (command == "SEARCH") {
            searchContact(phoneBook);
        } else if (command == "EXIT") {
            std::cout << "Goodbye!" << std::endl;
            break;
        } else if (!command.empty()) {
            std::cout << "Invalid command!" << std::endl;
        }

        if (std::cin.eof()) {
            std::cout << std::endl;
            break;
        }
    }
    
    return 0;
}
