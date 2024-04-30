//
// Created by Jules Cayot on 4/27/24.
//

#include "PhoneBook.h"

int	main()
{
	PhoneBook phoneBook;

	phoneBook = PhoneBook();
	phoneBook.run();
	phoneBook.~PhoneBook();
	return (0);
}
