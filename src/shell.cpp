#include "shell.h"

#include <cstring>

#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <limits.h>


Shell::Shell() {
	this->path = getcwd(NULL, PATH_MAX+1); // get path
	this->child_pid = 0; // no child
}

bool Shell::setPath(const char* path) {
	
	// change path
	if (chdir(path)) {
		// failed
		return false;
	}
	
	// get and store resolved path
	getcwd(this->path, PATH_MAX+1);
	
	return true;
}

const char* Shell::getPath() const {
	return this->path;
}

bool Shell::startSync(const char* program, char* const arguments[]) {	
	
	return start(program, arguments, false);
}

bool Shell::startAsync(const char* program, char* const arguments[]) {

	return start(program, arguments, true);
}

bool Shell::start(const char* program, char* const arguments[], const bool async) {
	
	// TODO MAYBE convert arguments 
	
	// fork
	pid_t child_pid = fork();
	
	if (child_pid == 0) {
		// child
		
		// execvp: v = null terminated arguments, p = search in path
		execvp(program, arguments);
		
	}
	else {
		// parrent
		
		if (!async) {
			this->child_pid = child_pid;
			
			int status_code;
			waitpid(child_pid, &status_code, 0);
			
			this->child_pid = 0; // child no longer alive
			
			if (!WIFEXITED(status_code)) {
				return false;
			}
		}
		else {
			
			// TODO handle zombies
		}
	}
	
	return true;
}

bool Shell::stopLast() {
	
	if(this->child_pid == 0) {
		// no child running
		return false;
	}
	
	kill(this->child_pid, SIGTERM);
	
	return true;
}
