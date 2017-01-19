#include "handler.h"

Handler::Handler(Shell *sh) {
	this.sh = sh;
}


bool Handler::execute(Command c) {
	const char* args[] = new const char*[];
	const char* comm = c.getCommand();
	args = c.getArgs();
	
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
		//get to the last argument (the '&') to remove it
		for(int i = 0; strcmp(args[i], "\0") != 0; i++)
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
	cout<<endl;
	cout<<path<<endl;
}

void Handler::exitYoda() {
	exit();
}

void Handler::help() {
	cout<<endl;
	cout<<APP_NAME<<", "<<APP_VERSION<<endl;
	cout<<"This shell was made for a school project on the Operating Systems course."<<endl;
	cout<<"It was made by the students Akritidis Akritas, Danis Dimitrios, Perontsi Eva and Sarlidou Anastasia."<<endl;
}
