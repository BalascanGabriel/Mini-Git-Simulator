#include "MiniGit.h"
#include "MiniGitIniter.h"
#include "MiniGitAdder.h"
#include "MiniGitCommiter.h"
#include "MiniGitPusher.h"
#include "MiniGitLogger.h"
#include "MiniGitPuller.h"

MiniGit::MiniGit()
{
}


MiniGit::~MiniGit()
{
}

void MiniGit::init(string path)
{
	MiniGitIniter::init(path);
	initPath = path;
	localPath = path + "\\local";
	remotePath = path + "\\remote";
}

void MiniGit::add(string fileName)
{
	MiniGitAdder::add(fileName, localPath);
}

void MiniGit::commit(string message)
{
	MiniGitCommiter::commit(message, localPath, initPath);
}

void MiniGit::push() {
	MiniGitPusher::push(localPath, remotePath);
}

void MiniGit::log(string remoteLocation) {
	MiniGitLogger::log(remoteLocation);
}

void MiniGit::pull(string remoteLocation, string commitName) {
	MiniGitPuller::pull(remoteLocation, commitName);
}