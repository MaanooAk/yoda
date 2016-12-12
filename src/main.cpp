
#include <iostream>

#include "defs.h"


// Temp test functions
// TODO move to test framework
void testShell();


int main(int argc, char *argv[]) {

	std::cout << APP_NAME << " v" << APP_VERSION << std::endl;

	//testShell();
}


#include "shell.h"
void testShell() {
	
	Shell *s = new Shell();

	std::cout << s->getPath() << std::endl;
	std::cout << s->setPath("../..") << std::endl;
	std::cout << s->getPath() << std::endl;

	char s1[] = "ls";
	char s2[] = "-l";
	char* const args[] = {s1, s2, 0};

	std::cout << s->startSync(s1, args) << std::endl;
	std::cout << s->startSync(s1, args) << std::endl;

	std::cin >> s1;
	
}