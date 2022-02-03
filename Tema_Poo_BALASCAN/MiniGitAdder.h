#pragma once
#include<iostream>
using namespace std;
class MiniGitAdder
{
public:
	MiniGitAdder();
	~MiniGitAdder();

	static void add(string fileName, string localPath);
	bool fileExists(const std::string& filePath);
};
