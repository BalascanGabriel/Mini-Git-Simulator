#pragma once
#include <iostream>
using namespace std;
class MiniGitCommiter
{
	static string copyContentOfFile(string filePath);
	static string getNextCommitName(string localPath);
public:
	MiniGitCommiter();
	~MiniGitCommiter();

	static void commit(string message, string localPath, string initPath);
};

