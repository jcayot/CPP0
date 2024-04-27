//
// Created by Jules Cayot on 4/27/24.
//

#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
private:
	std::string name;
	std::string number;

public:
	Contact();
	Contact(std::string name, std::string number);

	std::string getName();
	std::string getNumber();
};

#endif // CONTACT_H
