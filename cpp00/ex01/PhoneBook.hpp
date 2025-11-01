#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook {
	private:
		Contact contacts[8];
		int     contactCount;
		int     nextIndex;
	public:
		PhoneBook();
		int  getcontactCount() const;
		void addContact(const Contact& newContact);
		void displayContacts() const;
		void displayContactDetails(int index) const;
		bool isValidIndex(int index) const;
};

#endif // PHONEBOOK_HPP
