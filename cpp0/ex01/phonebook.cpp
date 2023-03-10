#include <iostream>
#include <string>

class Contact
{
	public:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
};

class PhoneBook 
{
	private:
		Contact contacts[8];
		int currentIndex;
	public:
		PhoneBook()
		{
			currentIndex = 0;
		}
	void addcontact()
	{
		if(currentIndex == 8)
		{
			currentIndex = 0;	
		}
		Contact &newContact = contacts[currentIndex];
	   while (true)
    {
        std::cout << "First Name: ";
        std::cin >> newContact.firstName;

        if (!newContact.firstName.empty())
        {
            newContact.firstName = newContact.firstName;
            break;
        }
        else
        {
            std::cout << "Error: First name cannot be empty. Please try again.\n";
        }
    }

    while (true)
    {
        std::cout << "Last Name: ";
        std::cin >> newContact.lastName;

        if (!newContact.lastName.empty())
        {
            newContact.lastName = newContact.lastName;
            break;
        }
        else
        {
            std::cout << "Error: Last name cannot be empty. Please try again.\n";
        }
    }

    while (true)
    {
        std::cout << "Nickname: ";
        std::cin >> newContact.nickName;

        if (!newContact.nickName.empty())
        {
            newContact.nickName = newContact.nickName;
            break;
        }
        else
        {
            std::cout << "Error: Nickname cannot be empty. Please try again.\n";
        }
    }
    while (true)
    {
        std::cout << "Phone Number: ";
        std::cin >> newContact.phoneNumber;
        if (!newContact.phoneNumber.empty())
        {
            newContact.phoneNumber = newContact.phoneNumber;
            break;
        }
        else
        {
            std::cout << "Error: Phone number cannot be empty. Please try again.\n";
        }
    }
    while (true)
    {
        std::cout << "Darkest Secret: ";
        std::cin >> newContact.darkestSecret;

        if (!newContact.darkestSecret.empty())
        {
            newContact.darkestSecret = newContact.darkestSecret;
            break;
        }
        else
        {
            std::cout << "Error: Darkest secret cannot be empty. Please try again.\n";
        }
    }
    currentIndex++;
}
	void searchcontact()
	{
		std::cout << "Index | First Name | Last Name | Nickname" << std::endl;

		for(int i = 0; i < 8; i++)
		{
			if(!contacts[i].firstName.empty())
			{
				
				std::cout << std::right << i << " | ";
				std::cout.width(10);
				std::string firstnameDisplay =  contacts[i].firstName.substr(0, 10);
				if(contacts[i].firstName.length() > 10)
					firstnameDisplay[9] = '.';
				std::cout << std::right << firstnameDisplay << " | ";
				std::cout.width(10);
				std::string lastnameDisplay = contacts[i].lastName.substr(0,10);
				if(contacts[i].lastName.length() > 10)
					lastnameDisplay[9] = '.';
				std::cout << std::right << lastnameDisplay << " | ";
				std::cout.width(10);
				std::string nicknameDisplay = contacts[i].nickName.substr(0,10);
				if(contacts[i].nickName.length() > 10)
					nicknameDisplay[9] = '.';
				std::cout << std::right << nicknameDisplay << std::endl;
			}
		}
	}
	void detailscontact(int index)
	{
		std::cout << "Firstname: " << contacts[index].firstName << std::endl;
		std::cout << "Lastname: " << contacts[index].lastName  << std::endl;
		std::cout << "Nickname: " << contacts[index].nickName << std::endl;
		std::cout << "Phone Number: " << contacts[index].phoneNumber << std::endl;
		std::cout << "Darkest Secret: " << contacts[index].darkestSecret << std::endl;
	}
};

int main()
{
	PhoneBook phonebook;
	std::string command;

	int index;
	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::cin >> command;

		if (command == "EXIT")
		{
			break;
		}
		else if (command == "ADD")
		{
			phonebook.addcontact();
		}
		else if (command == "SEARCH")
		{
			phonebook.searchcontact();
			std::cout << "Search Index 0 - 7: ";
			std::cin >> index;
			phonebook.detailscontact(index);
		}
		else
		{
			std::cout << "Invalid command" << std::endl;
		}
	}
	return 0;
}