#include "handler.h"
#include "defs.h"


Handler(Shell sh) {
	this.sh = sh;
}


bool execute(Command c) {
	const char* comm = new const char*;
	const char* args[] = new const char*[];
	comm = c.getCommand();
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
		
		sh.startAsync(comm, args);
		return true;
	}
	else {
		sh.startSync(comm, args);
		return true;
	}
}

bool cd(const char* path) {
	return sh.setPath(path);
}

void pwd() {
	const char* path = sh.getPath();
	cout<<endl;
	cout<<path<<endl;
}

void exitYoda() {
	exit();
}

void help() {
	
}
