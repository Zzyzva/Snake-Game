#include <iostream>

#include "main.h"
#include "Client.h"
#include "Server.h"

int main() {
	std::cout << "Press c for Client\nPress s for Server:\n";
	char command;
	std::cin >> command;
	if (command == 'c') {
		Client::client();
	}
	if (command == 's') {
		Server::server();
	}
	return 0;
}