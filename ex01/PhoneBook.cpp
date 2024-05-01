//
// Created by Jules Cayot on 4/27/24.
//

#include "PhoneBook.h"

PhoneBook::PhoneBook() {
	n_contact = 0;
}

PhoneBook::~PhoneBook() {
	for (int i = 0; i < 8; i++)
		contacts[i].~Contact();
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
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (input == "ADD")
		return (1);
	if (input == "SEARCH")
		return (2);
	if (input == "EXIT")
		return (3);
	return (-1);
}

void PhoneBook::add_contact() {
	std::string	firstname = get_field("firstname");
	std::string lastname = get_field("lastname");
	std::string nickname = get_field("nickname");
	std::string	number = get_field("number");
	std::string darkestSecret = get_field("darkestSecret");
	if (n_contact == 8)
		n_contact = 0;
	contacts[n_contact] = Contact(firstname, lastname, nickname, number, darkestSecret);
}

std::string	PhoneBook::get_field(std::string fieldName) {
	std::string	fieldContent;

	while (fieldContent.empty()) {
		std::cout << "Enter contact " + fieldName + " : ";
		std::cin >> fieldContent;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return (fieldContent);
}

void PhoneBook::search_contact() {
	std::string	input;
	int 		index;

	for (int i = 0; i < 8 && !contacts[i].getFirstname().empty(); i++)
		std::cout << std::to_string(i) + "|" + contacts[i].toString();

	while (input.empty() || input.length() != 1 || input[0] < '0' || input[0] > '7') {
		std::cout << "\nPlease enter the index of the contact you would like to display : ";
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	index = std::atoi(input.data());
	if (!contacts[index].getFirstname().empty()) {
		std::cout << "\nContact information for index : " + std::to_string(index) + "\n"
			+ "Firstname : " + contacts[index].getFirstname() + "\n"
			+ "Lastname : " + contacts[index].getLastname() + "\n"
			+ "Nickname : " + contacts[index].getNickname() + "\n"
			+ "Number : " + contacts[index].getNumber() + "\n"
			+ "Darkest secret : " + contacts[index].getDarkestSecret() + "\n";
	} else
		std::cout << "No entry for index : " + std::to_string(index);
}

void PhoneBook::wait_for_next() {
	std::cout << "\nDone. Press enter to continue\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "\n";
}
