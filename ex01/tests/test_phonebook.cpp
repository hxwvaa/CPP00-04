#include "../PhoneBook.hpp"
#include <iostream>
#include <cassert>
#include <sstream>

std::string intToString(int value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

void testPhoneBookCreation() {
    std::cout << "Testing PhoneBook creation..." << std::endl;
    
    PhoneBook phoneBook;
    assert(phoneBook.getContactCount() == 0);
    
    std::cout << "✓ PhoneBook creation test passed" << std::endl;
}

void testAddSingleContact() {
    std::cout << "Testing adding single contact..." << std::endl;
    
    PhoneBook phoneBook;
    Contact contact;
    contact.setContact("John", "Doe", "Johnny", "123456789", "Loves cats");
    
    phoneBook.addContact(contact);
    assert(phoneBook.getContactCount() == 1);
    
    std::cout << "✓ Add single contact test passed" << std::endl;
}

void testAddMultipleContacts() {
    std::cout << "Testing adding multiple contacts..." << std::endl;
    
    PhoneBook phoneBook;
    
    for (int i = 0; i < 5; i++) {
        Contact contact;
        std::string suffix = intToString(i);
        contact.setContact("First" + suffix, 
                          "Last" + suffix,
                          "Nick" + suffix,
                          "Phone" + suffix,
                          "Secret" + suffix);
        phoneBook.addContact(contact);
    }
    
    assert(phoneBook.getContactCount() == 5);
    
    std::cout << "✓ Add multiple contacts test passed" << std::endl;
}

void testMaxContactsLimit() {
    std::cout << "Testing 8 contacts limit..." << std::endl;
    
    PhoneBook phoneBook;
    
    // Add 10 contacts (more than the 8 limit)
    for (int i = 0; i < 10; i++) {
        Contact contact;
        std::string suffix = intToString(i);
        contact.setContact("First" + suffix, 
                          "Last" + suffix,
                          "Nick" + suffix,
                          "Phone" + suffix,
                          "Secret" + suffix);
        phoneBook.addContact(contact);
    }
    
    // Should still be 8
    assert(phoneBook.getContactCount() == 8);
    
    std::cout << "✓ Max contacts limit test passed" << std::endl;
}

void testDisplayInvalidIndex() {
    std::cout << "Testing display with invalid index..." << std::endl;
    
    PhoneBook phoneBook;
    Contact contact;
    contact.setContact("John", "Doe", "Johnny", "123456789", "Loves cats");
    phoneBook.addContact(contact);
    
    // Redirect cout to capture output
    std::streambuf* orig = std::cout.rdbuf();
    std::ostringstream capture;
    std::cout.rdbuf(capture.rdbuf());
    
    phoneBook.displayContact(-1);  // Invalid negative index
    phoneBook.displayContact(10);  // Invalid large index
    
    std::cout.rdbuf(orig);
    
    std::string output = capture.str();
    assert(output.find("Invalid index!") != std::string::npos);
    
    std::cout << "✓ Invalid index test passed" << std::endl;
}

int main() {
    std::cout << "Running PhoneBook tests..." << std::endl;
    
    testPhoneBookCreation();
    testAddSingleContact();
    testAddMultipleContacts();
    testMaxContactsLimit();
    testDisplayInvalidIndex();
    
    std::cout << "All PhoneBook tests passed!" << std::endl;
    return 0;
}
