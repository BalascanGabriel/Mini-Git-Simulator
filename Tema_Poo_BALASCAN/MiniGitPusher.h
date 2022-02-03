#ifndef MINIGIT_MINIGITPUSHER_H
#define MINIGIT_MINIGITPUSHER_H

#include <iostream>
using namespace std;

class MiniGitPusher {
private:
	static void copyFile(string source, string destination);
public:
	MiniGitPusher();
	~MiniGitPusher();

	static void push(string localPath, string remotePath);
};


#endif 

