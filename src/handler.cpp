#include "handler.h"

#include <cstring>
#include <iostream>

#include "defs.h"


Handler::Handler(Shell *sh) {
	this->sh = sh;
	terminated = false;
}


bool Handler::execute(const Command &c) {
	const char* comm = c.getCommand();
	char* const* args = c.getArgs();
	
	if (strcmp(c.getCommand(), "cd") == 0) {
		cd(c.getLast());
		return true;
	}
	if (strcmp(c.getCommand(), "pwd") == 0) {
		pwd();
		return true;
	}
	if (strcmp(c.getCommand(), "exit") == 0) {
		exitYoda();
		return true;
	}
	if (strcmp(c.getCommand(), "help") == 0) {
		help();
		return true;
	}
	
	if (strcmp(c.getLast(), "&") == 0) {
		int count = 2;
		//int count = c.getArgCount();
		char** arguments = new char*[count - 1];
		
		int i;
		for (i=0; i < count; i++)
			arguments[i] = args[i];
		
		sh->startAsync(comm, arguments);
		delete[] arguments;
		return true;
	}
	else {
		sh->startSync(comm, args);
		return true;
	}
}

bool Handler::cd(const char* path) {
	return sh->setPath(path);
}

void Handler::pwd() {
	const char* path = sh->getPath();
	std::cout << path << std::endl;
}

void Handler::exitYoda() {
	terminated = true;
}

void Handler::help() {
	std::cout << APP_NAME << " v" << APP_VERSION << std::endl;
}

bool Handler::isTerminated() {
	return terminated;
}