#pragma once

#include <string>

/**
 * TODO make Path an actual class
 */
class Path {
public:

	static const std::string home();

	static std::string join(const std::string & p1, const std::string & p2);

	static std::string homejoin(const std::string & p2);

	static std::string compress(const std::string & p1);

	static std::string decompress(const std::string & p1);

	static bool makeDir(const std::string & p1);

protected:

private:

	Path() {}
};