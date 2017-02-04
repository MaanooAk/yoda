#pragma once

#include "shell.h"
#include "handler.h"


/**
 * Handles the main app loop:
 * - read line
 * - create command
 * - execute command
 *
 * Also handles the SIGINT signals.
 */
class Console {
public:

	/**
	 * Constructs and initializes the console.
	 *
	 * Creates also a shell and a handler object.
	 */
	Console();

	/**
	 * Deconstructs the Console.
	 *
	 * Deletes also the shell and handler.
	 */
	virtual ~Console();

	/**
	 * Starts running the console, contains the main loop of the program.
	 *
	 * When this function returns, the program should exit.
	 *
	 * Returns 0 if everything executed without errors, otherwise it returns 1
	 */
	bool start();


protected:

	Shell* shell;

	Handler* handler;

private:

	static void stopLast(int signal);

};