#include "Logger.h"
#include <fstream>

Logger::Logger() : logFile("commands.log") { }

Logger::~Logger() { }

void Logger::log(string command) {
	ofstream out(logFile, ios::app); // ios::app  e modul append adica adauga la final
	out << command.c_str();
	out << endl;
}