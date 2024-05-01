//
// Created by Jules Cayot on 4/27/24.
//

#include "Contact.h"

Contact::Contact() {
	this -> firstname = "";
	this -> lastname = "";
	this -> nickname = "";
	this -> number = "";
	this -> darkestSecret = "";
}

Contact::Contact(std::string firstname, std::string lastname, std::string nickname, std::string number,
				 std::string darkestSecret) {
	this -> firstname = firstname;
	this -> lastname = lastname;
	this -> nickname = nickname;
	this -> number = number;
	this -> darkestSecret = darkestSecret;
}

std::string Contact::getFirstname() {
	return (firstname);
}

std::string Contact::getLastname() {
	return (lastname);
}

std::string Contact::getNickname() {
	return (nickname);
}

std::string Contact::getNumber() {
	return (number);
}

std::string Contact::getDarkestSecret() {
	return (darkestSecret);
}

std::string Contact::toString() {
	return (shortened(firstname) + "|" + shortened(lastname) + "|" + shortened(nickname) + "\n");
}

std::string Contact::shortened(std::string str) {
	if (str.length() <= 10)
		return (str);
	return (str.substr(0, 8) + ".");
}