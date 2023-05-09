#include "user.h"

User::User(const std::string& my_name, const std::pair<std::string, std::string>& user_data)
: _my_name(my_name), _user_data(user_data)
{
}

User& User::operator= (const User& user)
{
	if (&user == this)
		return *this;
	this->_my_name = user._my_name;
	this->_user_data.first = user._user_data.first;
	this->_user_data.second = user._user_data.second;
	this->_message_count = user._message_count;
	return *this;
}

// Registration
User User::sign_up()
{
	std::string regName, regLogin, regPassword;
	std::cout << "Enter your name: ";
	std::cin >> regName;
	std::cout << "Enter login: ";
	std::cin >> regLogin;
	std::cout << "Enter password: ";
	std::cin >> regPassword;
	std::pair<std::string, std::string> regData = make_pair(regLogin, regPassword);

	User newUser(regName, regData);
	return newUser;
}

// Authorization
User User::sign_in(User users[], int usersCount)
{
	std::string authLogin, authPassword;
	std::cout << "Enter login: ";
	std::cin >> authLogin;
	std::cout << "Enter password: ";
	std::cin >> authPassword;
	std::pair<std::string, std::string> authData = make_pair(authLogin, authPassword);
	for(int i = 0; i <= usersCount; i++)
	{
		if (users[i]._user_data.first == authData.first && users[i]._user_data.second == authData.second)
		{
			this->_auth = 1;
			return users[i];
		}
	}
	User userNone;
	return userNone;

}

// Send a message to someone
void User::sendAMessage(User users[], int usersCount, const std::string& username, const std::string& message)
{
	for (int i = 0; i <= usersCount; i++)
	{
		if (i == usersCount)
		{
			std::cout << "User is not found" << std::endl;
		}
		if (users[i]._my_name == username)
		{
			if (users[i]._message_count != 5)
			{
				users[i]._my_messages[users[i]._message_count] = message;
				users[i]._message_count++;
				std::cout << "Message sent!" << std::endl;
				break;
			}
			else 
			{
				users[i]._message_count = 0;
				users[i]._my_messages[users[i]._message_count] = message;
				users[i]._message_count++;
				std::cout << "Message sent!" << std::endl;
				break;
			}
		}
	}
}

// Send a message to everyone
void User::SendAMessageToEveryone(User users[], int usersCount, const std::string& message)
{
	for (int i = 0; i < usersCount; i++)
	{
		if (users[i]._message_count != 5)
		{
			users[i]._my_messages[users[i]._message_count] = message;
			users[i]._message_count++;
		}
		else 
		{
			users[i]._message_count = 0;
			users[i]._my_messages[users[i]._message_count] = message;
			users[i]._message_count++;
		}
	}
}

// Check your messages
void User::CheckMessages(const User& currentUser, User users[], int usersCount)
{
	for (int i = 0; i < usersCount; i++)
	{
		if (users[i]._user_data.first == currentUser._user_data.first)
		{
			for (int k = 0; k < _my_messages.size(); k++)
			{
				std::cout << "Message: " << users[i]._my_messages[k] << std::endl;
			}
			break;
		}
		else
		{
			std::cout << "Something went wrong." << std::endl;
		}
	}
}


void User::showAll()
{
	std::cout << _my_name << std::endl;
	std::cout << _user_data.first << std::endl;
	std::cout << _user_data.second << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << _my_messages[i] << std::endl;
	}

}