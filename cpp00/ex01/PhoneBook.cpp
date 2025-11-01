#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : contactCount(0), nextIndex(0) {}

int PhoneBook::getcontactCount() const {
    return contactCount;
}

void PhoneBook::addContact(const Contact& newContact) {
    contacts[nextIndex] = newContact;
    nextIndex = (nextIndex + 1) % 8;
    if (contactCount < 8)
        contactCount++;
}

void PhoneBook::displayContacts() const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < contactCount; ++i) {
        contacts[i].displaySummary(i);
    }
}

void PhoneBook::displayContactDetails(int i) const {
    if (!isValidIndex(i))
        std::cout << "Invalid index." << std::endl;
    else
        contacts[i].displayDetails();
}

bool PhoneBook::isValidIndex(int index) const {
    return (index >= 0 && index < contactCount);
}
