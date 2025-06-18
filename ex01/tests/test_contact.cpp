#include "../Contact.hpp"
#include <iostream>
#include <cassert>

void testContactCreation() {
    std::cout << "Testing Contact creation..." << std::endl;
    
    Contact contact;
    assert(contact.isEmpty() == true);
    assert(contact.getFirstName() == "");
    assert(contact.getLastName() == "");
    assert(contact.getNickname() == "");
    assert(contact.getPhoneNumber() == "");
    assert(contact.getDarkestSecret() == "");
    
    std::cout << "✓ Contact creation test passed" << std::endl;
}

void testContactSetData() {
    std::cout << "Testing Contact setContact..." << std::endl;
    
    Contact contact;
    contact.setContact("John", "Doe", "Johnny", "123456789", "Loves cats");
    
    assert(contact.isEmpty() == false);
    assert(contact.getFirstName() == "John");
    assert(contact.getLastName() == "Doe");
    assert(contact.getNickname() == "Johnny");
    assert(contact.getPhoneNumber() == "123456789");
    assert(contact.getDarkestSecret() == "Loves cats");
    
    std::cout << "✓ Contact setContact test passed" << std::endl;
}

void testContactEmptyFields() {
    std::cout << "Testing Contact with empty fields..." << std::endl;
    
    Contact contact;
    contact.setContact("", "Doe", "Johnny", "123456789", "Secret");
    
    assert(contact.isEmpty() == true);
    
    std::cout << "✓ Contact empty fields test passed" << std::endl;
}

int main() {
    std::cout << "Running Contact tests..." << std::endl;
    
    testContactCreation();
    testContactSetData();
    testContactEmptyFields();
    
    std::cout << "All Contact tests passed!" << std::endl;
    return 0;
}
