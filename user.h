#pragma once
#include <iostream>
#include <array>
#include <utility>
class User
{
public:
	User(const std::string& my_name, const std::pair<std::string, std::string>& user_data);
	User() = default;
	~User() = default;

	User& operator= (const User& user);

	// Registration
	User sign_up();

	// Authorization
	User sign_in(User users[], int usersCount);

	// Send a message to someone
	void sendAMessage(User users[], int usersCount, const std::string& username, const std::string& message);

	// Send a message to everyone
	void SendAMessageToEveryone(User users[], int usersCount, const std::string& message);

	// Check your messages
	void CheckMessages(const User& currentUser, User users[], int usersCount);
	void showAll();

	bool _auth = false;
	std::string _my_name;
	std::array<std::string, 5> _my_messages;
	int _message_count = 0;
private:
	// Username and password field
	std::pair<std::string, std::string> _user_data;
};