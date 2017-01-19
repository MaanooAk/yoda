#include "handler.h"

#include <cstring>
#include <iostream>

#include "defs.h"


Handler::Handler(Shell *sh) {
	this->sh = sh;
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
		//help();
		return true;
	}
	
	if (strcmp(c.getLast(), "&") == 0) {

		// TODO(jimboelessar) create a copy of the array and the remove the last

		//get to the last argument (the '&') to remove it
		int i;
		for(i = 0; strcmp(args[i], "\0") != 0; i++)
		;
		args[--i] = '\0';
		
		sh->startAsync(comm, args);
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
	// TODO(jimboelessar) tell console that it needs to exit
}

void Handler::help() {
	std::cout << APP_NAME << " v" << APP_VERSION << std::endl;
	std::cout << "This shell was made for a school project on the Operating Systems course." << std::endl;
	std::cout << "It was made by the students Akritidis Akritas, Danis Dimitrios, Perontsi Eva and Sarlidou Anastasia." << std::endl;
}
