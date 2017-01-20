#include "command.h"

#include "string.h"


Command::Command(const char* text) {
	// buffer variables
	char buff[256];
	char* array[256];
	// indexes
	int i = 0, ibuff = 0, iarray = 0;

	while(true) {

		if (text[i] != ' ' && text[i] != '\0') {
			// copy any normal char to buffer

			buff[ibuff] = text[i];
			ibuff += 1;

		}else if(ibuff > 0) {
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
		if(text[i] == '\0') {
			break;
		}

		i += 1;
	}

	array[i] = nullptr;

	// set member variables
	argc = i;
	argv = new char*[i+1];
	String::copy(argv, array);

}

virtual Command::~Command() {
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
	return argc[0];
}

const char* Command::getLast() const {
	return argv[argc - 1];
}
