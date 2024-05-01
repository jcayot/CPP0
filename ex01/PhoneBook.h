//
// Created by Jules Cayot on 4/27/24.
//

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>
#include <limits>
#include "Contact.h"

class PhoneBook {
private:
	Contact contacts[8];
	int n_contact;

	void	choose_option();
	void	wait_for_next();
	int		get_option();
	void	add_contact();
	void	search_contact();
	int get_contact_index(std::string name);

public:
	PhoneBook();
	~PhoneBook();
	void run();
};

#endif // PHONEBOOK_H
