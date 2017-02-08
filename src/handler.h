#pragma once

#include "shell.h"
#include "command.h"


/**
 * Executes internal commands and passes external commands to the Shell.
 *
 * Keeps track if the app should terminate.
 *
 * Used by the Console.
 */
class Handler {
public:

	/**
	 * Constructs and initializes the handler with a given Shell.
	 */
	Handler(Shell *sh);

	/**
	 * Executes a command.
	 */
	bool execute(Command &c);

	/**
	 * Returns true if there has been a command to close the shell;
	 */
	bool isTerminated();

protected:

	Shell *sh;

	bool terminated;

private:

	// Internal commands

	/**
	 * Changes the active directory.
	 */
	bool cd(const char* path);

	/**
	 * Displays the active directory.
	 */
	void pwd();

	/**
	 * Closes the shell.
	 */
	void exitYoda();

	/**
	 * Displays some information regarding the shell.
	 */
	void help();

	void prefs(Command &c);

	void alias(Command &c);
};
