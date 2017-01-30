#pragma once

#include "shell.h"
#include "handler.h"


/**
 * TODO(evaperon) write
 */
class Console {
public:

	/**
	 * constructor of the console
	 * Creates a shell and a handler object
	 */
	Console();

	/**
	 * destructor
	 * frees (delete) the allocated memory of the shell and the handler
	 */
	virtual ~Console();

	/**
	 * Starts running the console, contains the main loop of the program.
	 * When this function returns, the program should exit.
	 * Returns 0 if everything executed without errors, otherwise it returns 1
	 */
	bool start();


protected:

	Shell* shell;

	Handler* handler;

private:

	static void stopLast(int signal);

};