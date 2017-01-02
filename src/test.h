#pragma once

#include <vector>

class Test {
public:

	Test(const bool must, const char* title) :
		must(must),
		title(title) {};

	bool perform();
	
	virtual const void* execute() = 0;
	
	virtual bool assert(const void* result) = 0;
	
	const bool must;
	
	const char* title;
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
		Test(true, "Get current working path") {}
	
	virtual const void* execute() override;
	virtual bool assert(const void* result) override;
};

class TestShell02 : public Test {
public:
	TestShell02() :
		Test(true, "Change current working path") {}
	
	virtual const void* execute() override;
	virtual bool assert(const void* result) override;
};

class TestShell03 : public Test {
public:
	TestShell03() :
		Test(true, "Run echo command with arguments") {}
	
	virtual const void* execute() override;
	virtual bool assert(const void* result) override;
};

