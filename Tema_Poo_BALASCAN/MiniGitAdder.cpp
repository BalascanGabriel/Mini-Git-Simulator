#include "MiniGitAdder.h"
#include<fstream>
#include <sstream>
#include<ctime>

MiniGitAdder::MiniGitAdder()
{
}


MiniGitAdder::~MiniGitAdder()
{
}

//Functie care verifica daca fisierul exista
bool MiniGitAdder::fileExists(const std::string& name) {
	ifstream f(name.c_str());
	return f.good();
}


void MiniGitAdder::add(string fileName, string localPath)
{
	string localGitPath = localPath + "\\local.git";
	ifstream f(localGitPath.c_str());
	if (!f.good())
	{
		ofstream out(localGitPath);
		out << 1 << '\n';
		out << fileName << '\n';
		out << std::time(0) << '\n';
		out << "----" << '\n';
		return;
	}
	f.close();
	std::fstream file(localGitPath.c_str(), std::ios::in | std::ios::out);
	int nrOfFiles;
	file >> nrOfFiles;
	file.seekp(0);
	file << nrOfFiles + 1;
	file.seekp(0, ios::end); // muta pointerul la sfarsitul fisierului
	file << fileName << '\n';
	file << std::time(0) << '\n';
	file << "----" << '\n';
}
