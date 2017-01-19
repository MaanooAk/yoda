#pragma once

class Command {
public:

	char* const* getArgs() const;
	const char* getCommand() const;
	const char* getLast() const;

protected:

private:

};