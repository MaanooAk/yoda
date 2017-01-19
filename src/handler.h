#pragma once

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

private:
	
	Shell *sh;
	
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
