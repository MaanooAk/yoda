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
	 * TODO(evaperon) write
	 */
	Console();

	/**
	 * destructor
	 * TODO(evaperon) write
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

};