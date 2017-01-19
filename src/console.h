#pragma once

class Console {
public:
	/**
	* constructor of the console
	*/
	Console();
	
	/**
	* Starts running the console, contains the main loop of the program. When this function exits, the program exits.
	* returns 0 if everything executed without errors, otherwise it returns 1
	*/
	bool start();
	

protected:
	

private:
	
	//error flags here
	
	/**
	* Reads a line of user's input.
	* returns a char** alpharithmetic 
	*/
	
	//should this char* be static or not?
	char* readLine(char* empty_string);
	
	/**
	**************CORRECT ME IF STH IS WRONG**********************
	* readLine's returning string will be the parameter of command's constructor
	* the command itself will be a parameter in a handler's function
	*/
	

};