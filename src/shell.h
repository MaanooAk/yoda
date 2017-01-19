#pragma once

#include <sys/types.h>


/**
 * Starts synchronized and asynchronized processes and manipulates the working directory.
 * Keeps track of the last started process.
 *
 * Only one instance of the Shell should be active at any time.
 *
 * Used by the Handler.
 */
class Shell {
public:

	/**
	 * Constructs and initializes the shell and registers a SIGCHLD signal handler.
	 */
	Shell();

	/**
	 * Deconstructs the shell and unregisters the SIGCHLD signal handler.
	 */
	virtual ~Shell();

	/**
	 * Set the working directory path.
	 *
	 * The '.' and '..' wildcards are accepted.
	 */
	bool setPath(const char* path);

	/**
	 * Get the current working directory path.
	 */
	const char* getPath() const;

	/**
	 * Start a synchronized process.
	 *
	 * Arguments is a null terminated char* array including program.
	 */
	bool startSync(const char* program, char* const arguments[]);

	/**
	 * Start an asynchronized process.
	 *
	 * Arguments is a null terminated char* array including program.
	 */
	bool startAsync(const char* program, char* const arguments[]);

	/**
	 * Terminates the last program started with startSync()
	 */
	bool stopLast();

protected:

	char* path;
	pid_t child_pid;

	bool start(const char* program, char* const arguments[], const bool async);

private:

	static void cleanZombie(int signal_number);

};