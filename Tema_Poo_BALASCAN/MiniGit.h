#pragma once
#include<iostream>
using namespace std;
class MiniGit
{
private:
	string initPath;
	string localPath;
	string remotePath;
	int commitCount;

public:
	MiniGit();
	~MiniGit();

	void init(string path);
	void add(string fileName);
	void commit(string message);
	void push();
	void log(string remoteLocation);
	void pull(string remoteLocation, string commitName);
};

