#include<iostream>
#include <string>
#include "dirent.h"
using namespace std;
#include "MiniGit.h"
#include "Logger.h"

int main()
{
	MiniGit miniGit;
	Logger logger;
	string command;
	std::getline(cin, command);
	while (command != "0 ") {
		logger.log(command);
		command = command + " ";
		size_t pos = 0;
		string buffer[10];
		int commandWords = 0;
		string delimiter = " ", token;
		while ((pos = command.find(delimiter)) != string::npos) {
			token = command.substr(0, pos);
			buffer[commandWords] = token;
			command.erase(0, pos + delimiter.length());
			commandWords++;
		}
		if (buffer[1] == "init")
			miniGit.init(buffer[2]);
		if (buffer[1] == "add")
			miniGit.add(buffer[2]);
		if (buffer[1] == "commit")
			miniGit.commit(buffer[2]);
		if (buffer[1] == "push")
			miniGit.push();
		if (buffer[1] == "log")
			miniGit.log(buffer[2]);
		if (buffer[1] == "pull")
			miniGit.pull(buffer[2], buffer[3]);
		std::getline(cin, command);
	}

	system("pause");
	return 0;
}