#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;

    public:
        Contact(); // Constructor

        void setContact(
            const std::string& firstName,
            const std::string& lastName,
            const std::string& nickname,
            const std::string& phoneNumber,
            const std::string& darkestSecret
        );

        std::string get_firstName() const;
        std::string get_lastName() const;
        std::string get_nickname() const;
        std::string get_phoneNumber() const;
        std::string get_darkestSecret() const;
        void displaySummary(int index) const;
        void displayDetails() const;

        bool isEmpty() const;
};






#endif