#include "command.h"

#include "string.h"


Command::Command(const char* text) {

	char buff[256];	
	char* array[256];
	
	int i = 0, ibuff = 0, iarray = 0;
	
	while(true) {
		
		if (text[i] != ' ' && text[i] != '\0') {
			
			buff[ibuff] = text[i];
			ibuff += 1;
			
		}else if(ibuff > 0) {
			
			buff[ibuff] = '\0';
			ibuff += 1;
			
			char* arg = new char[ibuff];
			String::copy(arg, buff);
			
			array[iarray] = arg;
			iarray += 1;
			
			ibuff = 0;
		}
		
		if(text[i] == '\0') {
			break;
		}
		
		i += 1;
	}
	
	array[i] = nullptr;
	
	argc = i;
	args = new char*[i+1];
	String::copy(args, array);

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