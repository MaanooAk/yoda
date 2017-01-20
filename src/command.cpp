#include "command.h"


Command::Command(const char* text) {

	int i=0;
	// turn the string into a stream
	stringstream ssin(*text);
	//put the stream to the array
	while (i<argc ){
		ssin >> argv[i];
		i+=1;
	}

}

virtual Command::~Command() {
	// TODO(asarlidou) implement
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