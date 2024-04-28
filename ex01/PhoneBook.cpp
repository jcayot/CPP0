//
// Created by Jules Cayot on 4/27/24.
//

#include <iostream>

#include "PhoneBook.h"

PhoneBook::PhoneBook() {
	n_contact = 0;
}

PhoneBook::~PhoneBook() {

}

void PhoneBook::run() {
	std::cout << "Welcome to PhoneBook\n\n";
	while (true) {
		choose_option();
		switch (get_option()) {
			case 1:
				add_contact();
				break;
			case 2:
				search_contact();
				break;
			case 3:
				std::cout << "Exiting PhoneBook\n";
				return;
			default:
				std::cout << "Invalid input\n";
				break;
		}
		wait_for_next();
	}
}

void PhoneBook::choose_option() {
	std::cout << "Please choose an option below:\n";
	std::cout << "ADD\n";
	std::cout << "SEARCH\n";
	std::cout << "EXIT\n";
	std::cout << "\nYour choose : ";
}

int PhoneBook::get_option() {
	std::string input;
	std::cin >> input;

	if (input == "ADD")
		return (1);
	if (input == "SEARCH")
		return (2);
	if (input == "EXIT")
		return (3);
	return (-1);
}

void PhoneBook::add_contact() {
	std::string	name;
	std::string number;

	if (n_contact == 8)
		n_contact = 0;
	name = "";
	while (name.empty())
	{
		std::cout << "Enter contact name : ";
		std::cin >> name;
	}
	number = "";
	while (number.empty())
	{
		std::cout << "Enter contact number : ";
		std::cin >> number;
	}
	contacts[n_contact] = Contact(name, number);
	n_contact++;
}

void PhoneBook::search_contact() {
	std::string	name;

	while (name.empty())
	{
		std::cout << "Enter name of existing contact : ";
		std::cin >> name;
	}
	std::cout << "\n";
	for (int i = 0; i < 8; i++) {
		if (contacts[i].getName() == name)
		{
			std::cout << name + " Number is : " + contacts[i].getNumber() + "\n";
			return ;
		}
	}
	std::cout << "Error : Contact : " + name + " not found\n";
}

void PhoneBook::wait_for_next() {
	std::cout << "\nDone. Press any key to continue\n";
	std::getchar();
	std::cout << "\n";
}
