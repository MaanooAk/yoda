#pragma once

#include "shell.h"
#include "command.h"


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

protected:
	
	Shell *sh;

private:
	
	/*
	 * Changes the active directory.
	 */
	bool cd(const char* path);
	
	/*
	 * Displays the active directory.
	 */
	void pwd();
	
	/*
	 * Closes the shell.
	 */
	void exitYoda();
	
	/*
	 * Displays help list of commands.
	 */
	void help();

};
