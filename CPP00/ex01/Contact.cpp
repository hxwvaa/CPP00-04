#include "Contact.hpp"

Contact::Contact()
    : _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""), _darkestSecret("") {}

Contact::~Contact() {}

void Contact::setContact(const std::string& firstName, const std::string& lastName,
                         const std::string& nickname, const std::string& phoneNumber,
                         const std::string& darkestSecret) {
    _firstName = firstName;
    _lastName = lastName;
    _nickname = nickname;
    _phoneNumber = phoneNumber;
    _darkestSecret = darkestSecret;
}
const std::string& Contact::getFirstName() const {
    return _firstName;
}
const std::string& Contact::getLastName() const {
    return _lastName;
}
const std::string& Contact::getNickname() const {
    return _nickname;
}
const std::string& Contact::getPhoneNumber() const {
    return _phoneNumber;
}
const std::string& Contact::getDarkestSecret() const {
    return _darkestSecret;
}
bool Contact::isEmpty() const {
    return _firstName.empty() && _lastName.empty() && _nickname.empty() &&
        _phoneNumber.empty() && _darkestSecret.empty();
}
