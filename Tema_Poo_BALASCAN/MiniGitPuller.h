#ifndef MINIGIT_MINIGITPULLER_H
#define MINIGIT_MINIGITPULLER_H

#include <iostream>
using namespace std;

class MiniGitPuller {
private:
	static void copyContentToFile(string fileContent, string remoteLocation, string fileName);
public:
	MiniGitPuller();
	~MiniGitPuller();

	static void pull(string remoteLocation, string commitName);

};


#endif 

