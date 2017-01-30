
#include <iostream>

#include "defs.h"
#include "test.h"
#include "console.h"


int main(int argc, char *argv[]) {

	std::cout << APP_NAME << " v" << APP_VERSION << std::endl;

	if (argc == 2 && argv[1][0] == 't') {
		// perfom all test
		Tests tests;
		bool result = tests.perform();
		return result ? 0 : 1;
	}

	Console console;
	console.start();

	return 0;
}
