
#include <iostream>

#include "defs.h"
#include "test.h"
#include "console.h"
#include "preferences.h"


int main(int argc, char *argv[]) {

	std::cout << APP_NAME << " v" << APP_VERSION << std::endl;

	if (argc == 2 && argv[1][0] == 't') {
		// perfom all test
		Tests tests;
		bool result = tests.perform();
		return result ? 0 : 1;
	}

	Preferences::main = new Preferences();
	Preferences::main->setDefault("prompt1", PROMPT1);
	Preferences::main->setDefault("prompt2", PROMPT2);
	Preferences::main->setDefault("prompt3", PROMPT3);

	Console console;
	console.start();

	return 0;
}
