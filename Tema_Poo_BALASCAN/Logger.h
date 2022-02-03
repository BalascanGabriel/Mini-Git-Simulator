#ifndef MINIGIT_LOGGER_H
#define MINIGIT_LOGGER_H
#include <iostream>
using namespace std;

class Logger {
	const string logFile;
public:
	Logger();
	~Logger();

	void log(string command);
};


#endif 
