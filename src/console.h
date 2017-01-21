#pragma once
#include "command.h"
#include "handler.h"

class Console {
public:
	/**
	* constructor of the console
	*/
	Console();
	
	/**
	* destructor
	*/
	~Console();
	
	/**
	* Starts running the console, contains the main loop of the program. When this function exits, the program exits.
	* returns 0 if everything executed without errors, otherwise it returns 1
	*/
	bool start();
	

protected:
	
	Shell* shell;
	
	Handler* handler;

private:
	
	//error flags here

	
	

};