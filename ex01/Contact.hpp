#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact {
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;
public:
    Contact();
    ~Contact();


    void setContact(const std::string& firstName, const std::string& lastName,
                    const std::string& nickname, const std::string& phoneNumber,
                    const std::string& darkestSecret);
    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    const std::string& getNickname() const;
    const std::string& getPhoneNumber() const;
    const std::string& getDarkestSecret() const;
    bool isEmpty() const;
};

#endif
