#include "console.h"
#include <iostream>

#include "defs.h"

#define LINE_SIZE 512

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
		
		const char* cur_path;
		//getting the current path
		cur_path=shell->getPath();
		//printing the prompt
		std::cout<< cur_path << PROMPT ;
		
		//reading the line
		char line[LINE_SIZE]; 
		std::cin.getline(line,LINE_SIZE);
		
		//creating new Command object
		Command* command = new Command(line);
		
		
		
	}
	
	return true;
	
}