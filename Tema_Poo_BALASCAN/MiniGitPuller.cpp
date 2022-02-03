#include "MiniGitPuller.h"
#include <fstream>
#include <sstream>
#include <cstring>

MiniGitPuller::MiniGitPuller() { }

MiniGitPuller::~MiniGitPuller() { }

void MiniGitPuller::pull(string remoteLocation, string commitName) {
	string commitLocation = remoteLocation + "\\" + commitName;
	// Citesc din fisierul cu commitul continutul
	ifstream out(commitLocation);
	stringstream buffer;
	buffer << out.rdbuf();
	string commitContent = buffer.str(); // aici e continutul commitului salvat ca string
	// aici separ continutul commitului pe linii *
	string delimiter = "\n", token;
	int lineCount = 0;
	size_t pos = 0;
	string buf[1000];
	while ((pos = commitContent.find(delimiter)) != string::npos) {
		token = commitContent.substr(0, pos);
		buf[lineCount] = token;
		commitContent.erase(0, pos + delimiter.length());
		lineCount++;
	}
	// *
	int fileCount = atoi(buf[2].c_str()); //  numarul total de fisiere din commit; 
	string fileNames[100];
	// Merg doar pe liniile unde se gasesc numele fisierelor ca sa le salvez
	for (int i = 3; i <= 3 * fileCount; i += 3)
		fileNames[i / 3 - 1] = buf[i];

	int lineIndex = 0; // indexul liniei curente
	// Parcurgem fiecare linie salvata din fisierul commit pana gasim "cuvintele cheie"
	for (int i = 0; i < fileCount; i++) {
		while (buf[lineIndex] != "*Continutul fisierului " + to_string(i) + "* ") // pana gasim linie de inceput
		{
			lineIndex++;
		}
		lineIndex++;
		// cand ajungem aici inseamna ca am iesit din while si suntem pe linia de inceput
		string currentFileContent;
		//ne apucam sa copiem
		while (buf[lineIndex] != "*Sfarsitul fisierului " + to_string(i) + "* ") // cat timp nu ajungem la sfarsitul fisierului
		{
			currentFileContent += buf[lineIndex] + "\n"; // adaug pe rand fiecare linie la continutul fisierului
			lineIndex++;
		}
		copyContentToFile(currentFileContent, remoteLocation, fileNames[i]);
	}
}

void MiniGitPuller::copyContentToFile(string fileContent, string remoteLocation, string fileName) {
	// trebuie sa gasesc directorul parinte (adica in care e fisierul pe care vreau sa il modific)
	// asa ca caut ultimul \ si despart stringul
	string parentDirectory = remoteLocation.substr(0, remoteLocation.find_last_of("/\\"));
	ofstream out;
	// deschid fisierul cu optiunea trunc (trunchiere) ca sa se stearga practic tot ce e in el
	// si sa scriu noul continut din commit
	out.open(parentDirectory + "\\" + fileName, ofstream::out | ofstream::trunc);
	out << fileContent;
}
