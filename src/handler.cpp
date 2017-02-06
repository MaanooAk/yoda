#include "handler.h"

#include <cstring>
#include <iostream>

#include "defs.h"
#include "string.h"
#include "preferences.h"


Handler::Handler(Shell *sh) {
	this->sh = sh;
	this->terminated = false;
}

bool Handler::execute(Command &c) {
	if (c.getArgsCount() == 0) {
		return true;
	}

	const char* comm = c.getCommand();

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
	if (strcmp(c.getCommand(), "prefs") == 0) {
		prefs();
		return true;
	}

	if (strcmp(c.getLast(), "&") == 0) {

		c.removeLast();
		this->sh->startAsync(comm, c.getArgs());

		return true;
	}
	else {
		this->sh->startSync(comm, c.getArgs());
		return true;
	}
}

bool Handler::isTerminated() {
	return this->terminated;
}

bool Handler::cd(const char* path) {
	if (!this->sh->setPath(path)) {
		std::cout << "No directory '" << path << "' found!" << std::endl;
		return false;
	}
	int showpath = Preferences::main->getInt("showpath");
	if (showpath == 0) {
		pwd();
	}
	return true;
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
	std::cout << APP_WEBSITE << std::endl;
}

void Handler::prefs() {
	for (auto &i : Preferences::main->getKeys()) {
		std::cout << i << "=" << Preferences::main->get(i) << RESET << std::endl;
	}
}
