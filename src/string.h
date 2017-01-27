#pragma once


/**
 * Basic string operations
 */
class String {
public:

	static void copy(char* dest, const char* src);
	static void copy(char** dest, const char* const* src);

	static bool compare(const char* s1, const char* s2);
	static bool compare(const char* const* s1, const char* const* s2);

	static char* clone(const char* src);
	static char** clone(char* const* src);

	/**
	 * Clone all the leading array except the last item.
	 */
	static char** cloneLeading(char* const* src);

protected:

private:

	String() {}
};