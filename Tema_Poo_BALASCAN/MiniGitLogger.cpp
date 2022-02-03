#include "MiniGitLogger.h"
#include "dirent.h"
#include<iostream>
using namespace std;

MiniGitLogger::MiniGitLogger() { }

MiniGitLogger::~MiniGitLogger() { }

/**
 * Ma uit in toate fisierele din locatia remote si le afisez pe toate care au extensia commit
 * @param remoteLocation
 */
void MiniGitLogger::log(string remoteLocation) {
	DIR *dirp = opendir(remoteLocation.c_str());
	struct dirent *dp;
	string dirName;
	string aux = "Commiturile efectuate in locatia " + remoteLocation + " sunt:\n";
	aux.c_str();
	while ((dp = readdir(dirp)) != NULL) {
		dirName = dp->d_name;
		if (dirName.find(".commit") != string::npos) {
			dirName.c_str();
			cout << endl;
		}
	}
}
