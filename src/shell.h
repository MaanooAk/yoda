#pragma once

#include <sys/types.h>

class Shell {
public:

	Shell();

	bool setPath(const char* path);
	const char* getPath() const;

	bool startSync(const char* program, char* const arguments[]);
	bool startAsync(const char* program, char* const arguments[]);
	
	/**
	 * Terminates the last program started with startSync()
	 */
	bool stopLast();

protected:

	char* path;
	pid_t child_pid;

private:

	bool start(const char* program, char* const arguments[], const bool async);

};