//
// Created by Jules Cayot on 4/27/24.
//

#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
private:
	std::string firstname;
	std::string	lastname;
	std::string	nickname;
	std::string number;
	std::string	darkestSecret;

	std::string shortened(std::string str);

public:
	Contact();
	Contact(std::string firstname, std::string lastname, std::string nickname, std::string number,
			std::string darkestSecret);

	std::string getFirstname();
	std::string getLastname();
	std::string getNickname();
	std::string getNumber();
	std::string getDarkestSecret();
	std::string toString();
};

#endif // CONTACT_H
