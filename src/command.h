#pragma once


/**
 * Contains the arguments of a command parsed from a string.
 *
 * The array is null terminated.
 */
class Command {
public:

	/**
	 * Creates a command by parsing a string.
	 */
	Command(const char* text);

	virtual ~Command();

	/**
	 * Returns the argument array.
	 */
	char* const* getArgs() const;

	/**
	 * Retruns the first argument.
	 */
	const char* getCommand() const;

	/**
	 * Retruns the last argument.
	 */
	const char* getLast() const;

	/**
	 * Retruns the number of arguments.
	 */
	int getArgsCount() const;


	void removeFirst();

	void removeLast();

protected:

	/**
	 * All the number of arguments in the array
	 */
	int argc;

	/**
	 * The array of arguments
	 */
	char** argv;

private:

};