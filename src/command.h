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

	/**
	 * Creates a command adding a prefix to a command.
	 */
	Command(const char* text, const Command & c);

	virtual ~Command();

	/**
	 * Returns the argument array.
	 */
	char* const* getArgs() const;

	/**
	 * Returns an argument given an index.
	 * Negative indexes start from the end.
	 */
	const char* getArg(const int index) const;

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