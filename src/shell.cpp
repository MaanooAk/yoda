#include "shell.h"

#include <iostream>
#include <cstdio>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <limits.h>

#include "defs.h"


Shell::Shell() {
	this->child_pid = 0; // no child

	this->path = new char[PATH_MAX + 1];
	getcwd(this->path, PATH_MAX + 1); // get path

	// Handle SIGCHLD by calling cleanZombies.
	//struct sigaction act;
	//sigemptyset(&act.sa_mask);
	//act.sa_handler = &cleanZombie;
	//sigaction(SIGCHLD, &act, NULL);
	signal(SIGCHLD, cleanZombie);
}

Shell::~Shell() {
	delete[] this->path;

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
	getcwd(this->path, PATH_MAX + 1);

	return true;
}

const char* Shell::getPath() const {
	return this->path;
}

bool Shell::startSync(const char* program, char* const arguments[]) {

	return this->start(program, arguments, false);
}

bool Shell::startAsync(const char* program, char* const arguments[]) {

	return this->start(program, arguments, true);
}

bool Shell::start(const char* program, char* const arguments[], const bool async) {

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
		// parrent process

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

pid_t Shell::stopLast() {

	if (this->child_pid == 0) {
		// no child running
		return 0;
	}

	pid_t pid = this->child_pid;

	kill(this->child_pid, SIGTERM);

	this->child_pid = 0;

	return pid;
}
