#include "PhoneBook.hpp"
#include  "Contact.hpp"
#include <iostream>
#include <string>
#include <limits>

std::string prompt(const std::string& msg) {
    std::string input;
    std::cout << msg;
    std::getline(std::cin, input);
    return input;
}


int main() {
    PhoneBook phonebook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (std::cin.eof())
            break;
        if (command == "ADD") {
            Contact c;
            std::string first = prompt("First Name: ");
            std::string last = prompt("Last Name: ");
            std::string nick = prompt("Nickname: ");
            std::string phone = prompt("Phone Number: ");
            std::string secret = prompt("Darkest Secret: ");

            if (first.empty() || last.empty() || nick.empty() || phone.empty() || secret.empty()) {
                std::cout << "All fields must be filled!" << std::endl;
                continue;
            }

            c.setContact(first, last, nick, phone, secret);
            phonebook.addContact(c);
            std::cout << "Contact added!" << std::endl;

        } else if (command == "SEARCH") {
            if (phonebook.getcontactCount() == 0) {
                std::cout << "Phonebook is empty!" << std::endl;
                continue;
            }

            phonebook.displayContacts();
            std::cout << "Enter index to view details: ";
            int idx;
            std::cin >> idx;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input." << std::endl;
                continue;
            }
            std::cin.ignore(); // Clear newline
            phonebook.displayContactDetails(idx);

        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Unknown command." << std::endl;
        }
    }

    return 0;
}
