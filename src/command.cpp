#include "command.h"

#include "string.h"
#include <iostream>

Command::Command(const char* text) {
	// buffer variables
	char buff[256];
	char* array[256];
	// indexes
	int i = 0, ibuff = 0, iarray = 0;

	while (true) {

		if (text[i] != ' ' && text[i] != '\0') {
			// copy any normal char to buffer

			buff[ibuff] = text[i];
			ibuff += 1;

		} else if (ibuff > 0) {
			// do the split

			buff[ibuff] = '\0';
			ibuff += 1;

			char* arg = new char[ibuff];
			String::copy(arg, buff);

			array[iarray] = arg;
			iarray += 1;

			ibuff = 0;
		}

		// exit on end of text
		if (text[i] == '\0') {
			break;
		}

		i += 1;
	}

	array[iarray] = nullptr;

	// set member variables
	this->argc = iarray;
	this->argv = new char*[this->argc + 1];

	for(i = 0; i <= this->argc; i++) {
		this->argv[i] = array[i];
	}

}

Command::~Command() {
	// delete the args
	for (int i = 0; i < argc; i++) {
		delete[] argv[i];
	}
	delete[] argv;
}

char* const* Command::getArgs() const {
	return argv;
}

const char* Command::getCommand() const {
	return argv[0];
}

const char* Command::getLast() const {
	return argv[argc - 1];
}

int Command::getArgsCount() const {
	return argc;
}
