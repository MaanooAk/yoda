#include "console.h"

#include <iostream>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <signal.h>

#include "defs.h"
#include "command.h"
#include "preferences.h"


// used from the SIGINT handler
static Console* instance;

Console::Console() {

	shell = new Shell();
	handler = new Handler(shell);

	instance = this;
	signal(SIGINT, stopLast);
}

Console::~Console() {

	delete handler;
	delete shell;
}

void Console::stopLast(int signal) {

	pid_t pid = instance->shell->stopLast();

	if (pid == 0) {
		std::cout << std::endl << MES_PROGRAM_NOTERM << std::endl;
	} else {
		std::cout << std::endl << MES_PROGRAM_TERM_1 << pid << MES_PROGRAM_TERM_2 << std::endl;
	}
}

bool Console::start() {

	char *line = nullptr;

	// TODO fix this, all return the same thing or something
	const char *prompt1 = Preferences::main->get("prompt1").c_str();
	const char *prompt2 = Preferences::main->get("prompt2").c_str();
	const char *prompt3 = Preferences::main->get("prompt3").c_str();

	while (!handler->isTerminated()) {

		// getting the current path
		const char* cur_path = shell->getPath();

		// checking if line is empty and if it is not it frees it and reallocates memory
		if (line) {
			free(line);
		}
		// printing the prompt and getting the line
		std::cout << prompt1 << cur_path << prompt2;
		line = readline(prompt3);

		// adding it to history (you can use the arrows to navigate through history)
		if (line && *line) {
			add_history(line);
		}

		// creating new Command object
		Command command(line);

		// have handler object to execute the command
		handler->execute(command);

	}

	return true;
}