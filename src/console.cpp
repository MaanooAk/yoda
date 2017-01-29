#include "console.h"

#include <iostream>
#include <readline/readline.h>
#include <readline/history.h>

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

		// getting the current path
		const char* cur_path = shell->getPath();
		// printing the prompt
		std::cout << PROMPT1 << cur_path << PROMPT2;

		
		char *line=(char*)NULL;
		
		/***using GNU readline***/
		
		//checking if line is empty and if it is not it frees it and reallocates memory
		if (line){
        	delete line;
      		line = (char *)NULL;
    	}
		//getting the line
  		line = readline ("");

 		//adding it to history (you can use the arrows to navigate through history)
 	    if (line && *line){
    		add_history (line);
		}
		
		// creating new Command object
		Command command(line);
		
		//have handler object to execute the command
		handler->execute(command);

	}

	return true;
}