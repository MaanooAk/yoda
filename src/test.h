#pragma once

#include <vector>


class Test {
public:

	Test(const bool must, const char* title, const char* subtitle) :
		must(must),
		title(title),
		subtitle(subtitle) {};

	virtual ~Test() {};

	bool perform();

	virtual const void* execute() = 0;

	virtual bool assert(const void* result) = 0;

	const bool must;

	const char* title;
	const char* subtitle;
};

class Tests {
public:

	Tests();

	bool perform();

	std::vector<Test*> tests;
};

// === Tests ===

class TestShell01 : public Test {
public:
	TestShell01() :
		Test(true, "Shell", "Get current working path") {}

	virtual const void* execute() override;
	virtual bool assert(const void* result) override;
};

class TestShell02 : public Test {
public:
	TestShell02() :
		Test(true, "Shell", "Change current working path") {}

	virtual const void* execute() override;
	virtual bool assert(const void* result) override;
};

class TestShell03 : public Test {
public:
	TestShell03() :
		Test(true, "Shell", "Run echo command with arguments") {}

	virtual const void* execute() override;
	virtual bool assert(const void* result) override;
};

class TestCommand01 : public Test {
public:
	TestCommand01() :
		Test(true, "Command", "Parse simple arguments") {}

	virtual const void* execute() override;
	virtual bool assert(const void* result) override;
};

class TestCommand02 : public Test {
public:
	TestCommand02() :
		Test(false, "Command", "Parse arguments with multiple whitespace") {}

	virtual const void* execute() override;
	virtual bool assert(const void* result) override;
};

class TestCommand03 : public Test {
public:
	TestCommand03() :
		Test(false, "Command", "Parse arguments with double quotes") {}

	virtual const void* execute() override;
	virtual bool assert(const void* result) override;
};

class TestCommand04 : public Test {
public:
	TestCommand04() :
		Test(false, "Command", "Parse empty line") {}

	virtual const void* execute() override;
	virtual bool assert(const void* result) override;
};
