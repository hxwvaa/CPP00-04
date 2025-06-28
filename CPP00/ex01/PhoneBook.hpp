#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact _contacts[8];
    int _currentIndex;
    int _contactCount;

public:
    PhoneBook();
    ~PhoneBook();

    void addContact(const Contact& contact);
    void addContact(const std::string& firstName, const std::string& lastName,
                    const std::string& nickname, const std::string& phoneNumber,
                    const std::string& darkestSecret);
    void displayContacts() const;
    void displayContact(int index) const;
    int getContactCount() const;

};
#endif
