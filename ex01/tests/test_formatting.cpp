#include "../PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include <cassert>

void testColumnFormatting() {
    std::cout << "Testing column formatting..." << std::endl;
    
    PhoneBook phoneBook;
    
    // Add contact with long names to test truncation
    Contact contact;
    contact.setContact("VeryLongFirstName", "VeryLongLastName", "VeryLongNickname", 
                      "123456789", "Secret");
    phoneBook.addContact(contact);
    
    // Redirect cout to capture output
    std::streambuf* orig = std::cout.rdbuf();
    std::ostringstream capture;
    std::cout.rdbuf(capture.rdbuf());
    
    phoneBook.displayContacts();
    
    std::cout.rdbuf(orig);
    
    std::string output = capture.str();
    
    // Check if truncation occurred (should contain dots)
    assert(output.find(".") != std::string::npos);
    
    // Check if pipe separators are present
    assert(output.find("|") != std::string::npos);
    
    std::cout << "✓ Column formatting test passed" << std::endl;
}

void testShortNameFormatting() {
    std::cout << "Testing short name formatting..." << std::endl;
    
    PhoneBook phoneBook;
    
    Contact contact;
    contact.setContact("John", "Doe", "JD", "123", "Secret");
    phoneBook.addContact(contact);
    
    std::streambuf* orig = std::cout.rdbuf();
    std::ostringstream capture;
    std::cout.rdbuf(capture.rdbuf());
    
    phoneBook.displayContacts();
    
    std::cout.rdbuf(orig);
    
    std::string output = capture.str();
    
    // Short names should not be truncated (no dots except in headers)
    size_t firstDot = output.find(".");
    size_t headerEnd = output.find('\n');
    
    // If there are dots, they should only be in the header line
    if (firstDot != std::string::npos) {
        assert(firstDot < headerEnd);
    }
    
    std::cout << "✓ Short name formatting test passed" << std::endl;
}

int main() {
    std::cout << "Running formatting tests..." << std::endl;
    
    testColumnFormatting();
    testShortNameFormatting();
    
    std::cout << "All formatting tests passed!" << std::endl;
    return 0;
}
