#include "shell.h"

#include "defs.h"

#include <iostream>
#include <cstring>
#include <cstdio>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <limits.h>


Shell::Shell() {
	this->path = getcwd(NULL, PATH_MAX+1); // get path
	this->child_pid = 0; // no child

	// Handle SIGCHLD by calling cleanZombies.
	struct sigaction act;
	sigemptyset(&act.sa_mask);
	act.sa_handler = &cleanZombie;
	sigaction(SIGCHLD, &act, NULL);
}

Shell::~Shell() {
	delete this->path;

	// Revert SIGCHLD back to default
	struct sigaction act;
	sigemptyset(&act.sa_mask);
	act.sa_handler = SIG_DFL;
	sigaction(SIGCHLD, &act, NULL);
}

void Shell::cleanZombie(int signal_number) {
	int status;
	wait(&status);
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
		// child process

		// execvp: v = null terminated arguments, p = search in path
		execvp(program, arguments);

		// Flow comes here only on error
		std::cout << MES_COMMAND_NOT_FOUND_1 << program << MES_COMMAND_NOT_FOUND_2 << std::endl;
		_exit(0);

	}
	else {
		// parrent

		if (!async) {
			this->child_pid = child_pid;

			int status;
			waitpid(child_pid, &status, 0);

			this->child_pid = 0; // child no longer alive

			if (!WIFEXITED(status)) {
				return false;
			}
		}
	}

	return true;
}

bool Shell::stopLast() {

	if (this->child_pid == 0) {
		// no child running
		return false;
	}

	kill(this->child_pid, SIGTERM);

	return true;
}
