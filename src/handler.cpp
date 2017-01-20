#include "handler.h"

#include <cstring>
#include <iostream>

#include "defs.h"


Handler::Handler(Shell *sh) {
	this->sh = sh;
	this->terminated = false;
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

		int count = c.getArgsCount();
		char** arguments = new char*[count];

		for (int i = 0; i < count - 1; i++) {
			arguments[i] = args[i];
		}
		arguments[count - 1] = nullptr;

		this->sh->startAsync(comm, arguments);
		delete[] arguments;
		return true;
	}
	else {
		this->sh->startSync(comm, args);
		return true;
	}
}

bool Handler::isTerminated() {
	return this->terminated;
}

bool Handler::cd(const char* path) {
	return this->sh->setPath(path);
}

void Handler::pwd() {
	const char* path = this->sh->getPath();
	std::cout << path << std::endl;
}

void Handler::exitYoda() {
	this->terminated = true;
}

void Handler::help() {
	std::cout << APP_NAME << " v" << APP_VERSION << std::endl;
}
