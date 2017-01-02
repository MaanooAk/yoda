#include "test.h"

#include <iostream>
#include <cstring>
#include <limits.h>
#include <unistd.h>

#include "defs.h"
#include "shell.h"

const char *cwd = getcwd(NULL, PATH_MAX+1);

bool Test::perform() {
	
	std::cout << " Perform test: " << this->title << std::endl;
	
	bool result = assert(execute());
	
	std::cout << "  " << (result ? MES_TEST_TRUE : this->must ? MES_TEST_FALSE : MES_TEST_SEMI) << std::endl;
	return result;
}

Tests::Tests() {
	tests.push_back(new TestShell01());	
	tests.push_back(new TestShell02());	
	tests.push_back(new TestShell03());	
}

bool Tests::perform() {
	bool result = true;
	
	for(auto i : tests) {
		result &= i->perform() || !i->must;
	}
	
	return true;
}

const void* TestShell01::execute() {
	Shell s;
	return s.getPath();
}

// === Tests ===

bool TestShell01::assert(const void* result) {
	char path[PATH_MAX+1];
	strcpy(path, cwd);
	strcat(path, "");
	
	bool a = !strcmp((const char*)result, path);
	
	if (!a) {
		std::cout << "  Found " << (const char*)result << " instead of " << path << std::endl;
	}
	return a;
}

const void* TestShell02::execute() {
	Shell s;
	s.setPath("build");
	s.setPath("..");
	s.setPath("src");
	return s.getPath();
}

bool TestShell02::assert(const void* result) {
	char path[PATH_MAX+1];
	strcpy(path, cwd);
	strcat(path, "/src");
	
	bool a = !strcmp((const char*)result, path);
	
	if (!a) {
		std::cout << "  Found " << (const char*)result << " instead of " << path << std::endl;
	}
	return a;
}

const void* TestShell03::execute() {
	Shell s;
	s.setPath(cwd);
	char s1[] = "echo";
	char s2[] = "  Echo command text";
	char* const args[] = {s1, s2, 0};
	bool flag = s.startSync(s1, args);
	return new bool(flag);
}

bool TestShell03::assert(const void* result) {
	
	bool a = *((bool*)result);//!strcmp((const char*)result, path);
	
	if (!a) {
		std::cout << "  Found " << a << " instead of " << true << std::endl;
	}
	return a;
}

