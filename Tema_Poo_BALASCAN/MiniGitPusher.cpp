#include "MiniGitPusher.h"
#include <fstream>
#include "dirent.h"

MiniGitPusher::MiniGitPusher() { }

MiniGitPusher::~MiniGitPusher() { }

/**
 * Functie care face copierea fisierului din local in remote
 * @param source - path-ul sursa; adica catre local
 * @param destination - path-ul destinatie; adica catre remote
 * @return
 */
void MiniGitPusher::copyFile(string source, string destination) {
	std::ifstream src(source, std::ios::binary);
	std::ofstream dest(destination, std::ios::binary);
	dest << src.rdbuf();
}

/**
 * Caut toate fisierele cu extensia commit si le copiez pe remote
 * @param localPath
 * @param remotePath
 */
void MiniGitPusher::push(string localPath, string remotePath) {
	DIR *dirp = opendir(localPath.c_str());
	struct dirent *dp;
	string dirName;
	while ((dp = readdir(dirp)) != NULL) {
		dirName = dp->d_name;
		// la fiecare fisier cu extensia commit gasit, vad ce numar are
		if (dirName.find(".commit") != string::npos) {
			copyFile(localPath + "\\" + dirName, remotePath + "\\" + dirName);
		}
	}
}
