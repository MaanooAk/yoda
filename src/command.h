#pragma once


/**
 * Gets a string and split into array.
 *
 * TODO(asarlidou) fix and improve doc
 */
class Command {
public:

	/**
	 * TODO(asarlidou) write
	 */
	Command(const char* text);

	virtual ~Command();

	/**
	 * TODO(asarlidou) write
	 */
	char* const* getArgs() const;

	/**
	 * TODO(asarlidou) write
	 */
	const char* getCommand() const;

	/**
	 * TODO(asarlidou) write
	 */
	const char* getLast() const;

	/**
	 * TODO(asarlidou) write
	 */
	int getArgsCount() const;

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