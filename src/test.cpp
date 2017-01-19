#include "test.h"

#include <iostream>
#include <cstring>
#include <limits.h>
#include <unistd.h>

#include "defs.h"
#include "shell.h"

const char *cwd = getcwd(NULL, PATH_MAX+1);

bool Test::perform() {

	std::cout << " " << this->title << RESET << ": " << this->subtitle << std::endl;

	bool result = assert(execute());

	std::cout << "  " << (result ? MES_TEST_TRUE : this->must ? MES_TEST_FALSE : MES_TEST_SEMI) << std::endl;

	return result;
}

Tests::Tests() {
	this->tests.push_back(new TestShell01());
	this->tests.push_back(new TestShell02());
	this->tests.push_back(new TestShell03());
	this->tests.push_back(new TestCommand01());
	this->tests.push_back(new TestCommand02());
	this->tests.push_back(new TestCommand03());
}

bool Tests::perform() {
	bool result = true;

	std::cout << "Perform tests: " << std::endl;
	for (auto i : this->tests) {
		result &= i->perform() || !i->must;
	}

	return result;
}

// === Sub functions ===

static bool compare(const char* s1, const char* s2) {
	unsigned int i1 = 0, i2 = 0;
	while (s1[i1] != '\0' && s1[i1] == s2[i2]) {
		i1++;
		i2++;
	}
	return s1[i1] == s2[i2];
}

static bool compare(const char* const* s1, const char* const* s2) {
	unsigned int i1 = 0, i2 = 0;
	while (s1[i1] != nullptr && compare(s1[i1], s2[i2])) {
		i1++;
		i2++;
	}
	return s1[i1] == s2[i2];
}

// === Tests ===

const void* TestShell01::execute() {
	Shell s;
	return s.getPath();
}

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
	char* const args[] = {s1, s2, nullptr};
	bool flag = s.startSync(s1, args);
	return new bool(flag);
}

bool TestShell03::assert(const void* result) {

	bool a = *((bool*)result);

	if (!a) {
		std::cout << "  Found " << a << " instead of " << true << std::endl;
	}
	return a;
}

const void* TestCommand01::execute() {
	char line[] = "ls build -a";
	return new char(line[0]); // TODO change
}

bool TestCommand01::assert(const void* result) {
	char s1[] = "ls";
	char s2[] = "build";
	char s3[] = "-a";
	const char* const args[] = {s1, s2, s3, nullptr};

	bool a = !compare(args, args);
	return a;
}

const void* TestCommand02::execute() {
	char line[] = "ls  build    -a";
	return new char(line[0]); // TODO change
}

bool TestCommand02::assert(const void* result) {
	char s1[] = "ls";
	char s2[] = "build";
	char s3[] = "-a";
	const char* const args[] = {s1, s2, s3, nullptr};

	bool a = !compare(args, args);
	return a;
}

const void* TestCommand03::execute() {
	char line[] = "ls \"build all\" -a";
	return new char(line[0]); // TODO change
}

bool TestCommand03::assert(const void* result) {
	char s1[] = "ls";
	char s2[] = "\"build all\""; // TODO remove quotes?
	char s3[] = "-a";
	const char* const args[] = {s1, s2, s3, nullptr};

	bool a = !compare(args, args);
	return a;
}

