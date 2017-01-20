#pragma once

/**
 * TODO(asarlidou) implement
 */
class Command {
public:

	Command(const char* text);

	char* const* getArgs() const;

	const char* getCommand() const;

	const char* getLast() const;

protected:

private:

};