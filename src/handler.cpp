#include "handler.h"

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

	if (String::compare(c.getCommand(), "cd")) {
		cd(c.getLast());
		return true;
	}
	if (String::compare(c.getCommand(), "pwd")) {
		pwd();
		return true;
	}
	if (String::compare(c.getCommand(), "exit")) {
		exitYoda();
		return true;
	}
	if (String::compare(c.getCommand(), "help") || String::compare(c.getCommand(), "yoda")) {
		help();
		return true;
	}
	if (String::compare(c.getCommand(), "prefs")) {
		prefs();
		return true;
	}

	if (String::compare(c.getLast(), "&")) {

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
		std::cout << MES_DIRECTORY_NOT_FOUND_1 << path << MES_DIRECTORY_NOT_FOUND_2 << std::endl;
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
