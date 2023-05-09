#include <iostream>
#include "user.h"

int main()
{

	int options;
	const int usersCount = 3;
	User users[usersCount];
	static int index = 0;
	User userRegOrAuth;
	std::string username, message;

	bool open = true;
	while (open)
	{
		std::cout << "Welcome to the chat, select an operation: " << std::endl;
		std::cout << "1 - to sign up" << std::endl;
		std::cout << "2 - to sign in" << std::endl;
		std::cout << "0 - to quit" << std::endl;


		std::cin >> options;

		switch (options)
		{
		case 1:
			if (index != usersCount)
			{
				std::cout << "Sign Up..." << std::endl;
				users[index] = userRegOrAuth.sign_up();
				index++;
				break;
			}
			else
			{
				std::cout << "Maximum number of users reached: " << usersCount << std::endl;
				break;
			}
		case 2:
			std::cout << "Enter login and password." << std::endl;
			userRegOrAuth = userRegOrAuth.sign_in(users, usersCount);
				if (userRegOrAuth._auth)
				{
					std::cout << "Successful authorization!" << std::endl;
				}
				else
				{
					std::cout << "Incorrect login or password" << std::endl;
					break;
				}
			while (userRegOrAuth._auth)
			{
				std::cout << "Hello, select an operation: " << std::endl;
				std::cout << "1 - to send a message to someone" << std::endl;
				std::cout << "2 - to send a message to everyone" << std::endl;
				std::cout << "3 - check messages" << std::endl;
				std::cout << "0 - to log out" << std::endl;

				std::cin >> options;

				switch (options)
				{
				case 1:
					std::cout << "Whom to send a message to? Enter a username:" << std::endl;
					std::cin >> username;
					std::cout << "Write a message:" << std::endl;
					std::cin >> message;
					userRegOrAuth.sendAMessage(users, usersCount, username, message);
					break;
				case 2:
					std::cout << "Write a message:" << std::endl;
					std::cin >> message;
					userRegOrAuth.SendAMessageToEveryone(users, usersCount, message);
					std::cout << "Message sent to all users!" << std::endl;
					break;
				case 3:
					std::cout << "Checking messages.." << std::endl;
					userRegOrAuth.CheckMessages(userRegOrAuth, users, usersCount);
					break;
				case 0:
					std::cout << "Logging out.." << std::endl;
					userRegOrAuth._auth = 0;
					break;
				default:
					break;
				}

			}
			break;
		case 0:
			/*
			for (int i = 0; i < usersCount; i++)
			{
				users[i].showAll();
			}
			*/
			open = false;
			break;
		default:
			break;
		}
	}
	return 0;

}