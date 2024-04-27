//
// Created by Jules Cayot on 4/27/24.
//

#include "Contact.h"

Contact::Contact() {
	this->name = "";
	this->number = "";
}

Contact::Contact(std::string name, std::string number) {
	this->name = name;
	this->number = number;
}

std::string Contact::getName() {
	return name;
}

std::string Contact::getNumber() {
	return number;
}
