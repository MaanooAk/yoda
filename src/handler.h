#pragma once

#include "shell.h"
#include "command.h"


/**
 * TODO(jimboelessar) write
 */
class Handler {
public:

	/**
 	 * Constructor
 	 */
	Handler(Shell *sh);

	/**
	 * Executes a command.
 	 */
	bool execute(const Command &c);

	/**
	 * Returns true if there has been a command to close the shell;
	 */
	bool isTerminated();

protected:

	Shell *sh;

	bool terminated;

private:

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


};
