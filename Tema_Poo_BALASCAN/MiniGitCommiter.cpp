#include "MiniGitCommiter.h"
#include <sstream>
#include <fstream>
#include <ctime>
#include <sys/types.h>
#include "dirent.h"
#include <vector>
using namespace std;

MiniGitCommiter::MiniGitCommiter()
{
}


MiniGitCommiter::~MiniGitCommiter()
{
}

string MiniGitCommiter::getNextCommitName(string localPath) {
	DIR* dirp = opendir(localPath.c_str());
	struct dirent * dp;
	string dirName;
	int max = -1; // in max tin cel mai mare index de commit gasit
	while ((dp = readdir(dirp)) != NULL) {
		dirName = dp->d_name;
		// la fiecare fisier cu extensia commit gasit, vad ce numar are
		if (dirName.find(".commit") != string::npos) {
			string commitNumber = "";  // construiesc numarul ca si string
			commitNumber += dirName[0];
			commitNumber += dirName[2];
			stringstream parser(commitNumber); //declar un parser care face conversia din string in int
			int number;
			parser >> number;
			if (number > max)
				max = number;
		}
	}
	closedir(dirp);
	int currentCommit = max + 1;
	// daca max nu se modifica inseamna ca sunt la primul commit, deci returnez 0_0.commit
	// currentCommit / 10 = numarul de unitati ale lui currentCommit
	// currentCommit % 10 = ultima cifra a lui currentCommit
	return to_string(currentCommit / 10) + "_" + to_string(currentCommit % 10) + ".commit";
}

string MiniGitCommiter::copyContentOfFile(string filePath) {
	ifstream t(filePath);
	std::stringstream buffer;
	
	buffer << t.rdbuf();
	return buffer.str();
}


void MiniGitCommiter::commit(string message, string localPath, string initPath) {
	string commitPath = localPath + "\\" + getNextCommitName(localPath);
	ofstream f(commitPath.c_str());
	f << message << '\n';
	f << std::time(0) << '\n';
	string localGitContent = copyContentOfFile(localPath + "\\local.git");
	f << localGitContent << '\n';
	int lineCount = 0;
	string delimiter = "\n", token;
	size_t pos = 0;
	string buffer[100];
	while ((pos = localGitContent.find(delimiter)) != string::npos) {
		token = localGitContent.substr(0, pos);
		buffer[lineCount] = token;
		localGitContent.erase(0, pos + delimiter.length());
		lineCount++;
	}

	// Identificand patternul, vedem ca denumirea fisierelor se afla doar pe liniile de tip 3k + 1
	int fileCount = 0;
	for (int i = 1; i < lineCount; i += 3)
	{
		f << "*Continutul fisierului " << fileCount << "* \n";
		f << copyContentOfFile(initPath + "\\" + buffer[i]) << '\n';
		f << "*Sfarsitul fisierului " << fileCount << "* \n";
		fileCount++;
	}
}