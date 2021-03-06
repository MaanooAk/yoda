#include "handler.h"

#include <iostream>

#include "defs.h"
#include "string.h"
#include "preferences.h"
#include "aliases.h"
#include "path.h"


Handler::Handler(Shell *sh) {
	this->sh = sh;
	this->terminated = false;
}

bool Handler::execute(Command &c) {
	if (c.getArgsCount() == 0) {
		return true;
	}

	if (Aliases::main->has(c.getCommand())) {
		std::string prefix = Aliases::main->get(c.getCommand());
		c.removeFirst();
		Command *nc = new Command(prefix.c_str(), c);
		c = *nc;
	}

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
		prefs(c);
		return true;
	}
	if (String::compare(c.getCommand(), "alias")) {
		alias(c);
		return true;
	}

	if (String::compare(c.getLast(), "&")) {

		c.removeLast();
		this->sh->startAsync(c.getCommand(), c.getArgs());

		return true;
	}
	else {
		this->sh->startSync(c.getCommand(), c.getArgs());
		return true;
	}
}

bool Handler::isTerminated() {
	return this->terminated;
}

bool Handler::cd(const char* path) {
	if (!this->sh->setPath(Path::decompress(std::string(path)).c_str())) {
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

void Handler::prefs(Command &c) {
	if (c.getArgsCount() == 2) {
		const char* i = c.getArg(1);
		// show one
		if (Preferences::main->has(i)) {
			std::cout << Preferences::main->get(i) << std::endl;
		} else {
			std::cout << MES_NOT_FOUND_1 << i << MES_NOT_FOUND_2 << std::endl;
		}
	} else {
		// show all
		for (auto &i : Preferences::main->getKeys()) {
			std::cout << i << "=" << Preferences::main->get(i) << RESET << std::endl;
		}
	}
}

void Handler::alias(Command &c) {
	if (c.getArgsCount() == 2) {
		const char* i = c.getArg(1);
		// show one
		if (Aliases::main->has(i)) {
			std::cout << Aliases::main->get(i) << std::endl;
		} else {
			std::cout << MES_NOT_FOUND_1 << i << MES_NOT_FOUND_2 << std::endl;
		}
	} else {
		// show all
		for (auto &i : Aliases::main->getKeys()) {
			std::cout << i << "=" << Aliases::main->get(i) << RESET << std::endl;
		}
	}
}
