#ifndef MINIGIT_MINIGITLOGGER_H
#define MINIGIT_MINIGITLOGGER_H

#include <iostream>
using namespace std;

class MiniGitLogger {
public:
	MiniGitLogger();
	~MiniGitLogger();

	static void log(string remoteLocation);
};


#endif 
