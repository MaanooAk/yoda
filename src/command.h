#pragma once


/**
 * this class gets a string and split into array.
 * TODO(asarlidou) implement
 */
class Command {
public:

	Command(const char* text);

	virtual ~Command();
	
	char* const* getArgs() const;

	const char* getCommand() const;

	const char* getLast() const;

protected:

	// all the number of arguments in the array
	int argc;

	// an array of arguments
	char* argv[];

private:

};