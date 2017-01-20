#pragma once

/**
 *
 */
class String {
public:

	static void copy(char* dest, const char* src);
	static void copy(char** dest, const char* const* src);

	static bool compare(const char* s1, const char* s2);
	static bool compare(const char* const* s1, const char* const* s2);


protected:

private:

	String() {}
};