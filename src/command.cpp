#include "command.h"

#include "defs.h"
#include "string.h"


Command::Command(const char* text) {
	// buffer variables
	char buff[LINE_SIZE];
	char* array[ARGS_SIZE];
	// indexes
	int i = 0, ibuff = 0, iarray = 0;
	// inside quotes
	bool inqu = false;

	while (true) {

		if ((text[i] != ' ' || inqu) && text[i] != '\0') {
			// handle next char

			if (text[i] == '"') {
				// change inside quotes status
				inqu = !inqu;
			} else {
				// copy any normal char to buffer
				buff[ibuff] = text[i];
				ibuff += 1;
			}

		} else if (ibuff > 0) {
			// do the split

			buff[ibuff] = '\0';
			ibuff += 1;

			char* arg = String::clone(buff);

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
	this->argv = String::clone(array);

}

Command::~Command() {
	// delete the args
	for (int i = 0; i < this->argc; i++) {
		delete[] this->argv[i];
	}
	delete[] this->argv;
}

char* const* Command::getArgs() const {
	return this->argv;
}

const char* Command::getArg(const int index) const {
	if (index >= 0) {
		return this->argv[index];
	} else {
		return this->argv[this->argc - index];
	}
}

const char* Command::getCommand() const {
	return this->argv[0];
}

const char* Command::getLast() const {
	return this->argv[this->argc - 1];
}

int Command::getArgsCount() const {
	return this->argc;
}

void Command::removeFirst() {
	delete[] this->argv[0];
	for (int i = 1; i < this->argc; i++) {
		this->argv[i - 1] = this->argv[i];
	}
	this->argc--;
}

void Command::removeLast() {
	delete[] this->argv[this->argc - 1];
	this->argv[this->argc - 1] = nullptr;
	this->argc--;
}
