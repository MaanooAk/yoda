#include "console.h"

#include <iostream>

#include "defs.h"
#include "command.h"


Console::Console(){
	
	shell = new Shell();
	handler = new Handler(shell);
	
}

Console::~Console(){
	
	delete handler;
	delete shell;
	
}

bool Console::start(){
	
	while(!handler->isTerminated()){
		
		
		bool exec_OK;
		
		const char* cur_path;
		//getting the current path
		cur_path=shell->getPath();
		//printing the prompt
		std::cout << PROMPT1 << cur_path << PROMPT2;
		
		//reading the line
		char line[LINE_SIZE]; 
		std::cin.getline(line,LINE_SIZE);
		
		//creating new Command object
		// TODO make static?
		Command* command = new Command(line);
		
		//sth wrong with my arg
		exec_OK = handler->execute(*command);
		
		
	}
	
	return true;
	
}