#include "MiniGitIniter.h"
#include <direct.h>


MiniGitIniter::MiniGitIniter()
{
}


MiniGitIniter::~MiniGitIniter()
{
}

void MiniGitIniter::init(string path)
{
	_mkdir((path + "\\local").c_str());
	_mkdir((path + "\\remote").c_str());
}