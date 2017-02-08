#include "path.h"

#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


const std::string Path::home() {
	static const std::string path(getenv("HOME"));
	return path;
}

std::string Path::join(const std::string & p1, const std::string & p2) {
	std::string p;
	p.append(p1);
	if (p1.back() == '/') {
		if (p2.front() == '/') {
			p.pop_back();
		}
	} else {
		if (p2.front() != '/') {
			p.push_back('/');
		}
	}
	p.append(p2);
	return p;
}

std::string Path::homejoin(const std::string & p2) {
	return join(home(), p2);
}

std::string Path::compress(const std::string & p1) {
	const std::string h = home();

	std::string p(p1);
	if (p.compare(0, h.size(), h) == 0) {
		p.erase(0, h.size());
		p.insert(0, "~");
	}
	return p;
}

std::string Path::decompress(const std::string & p1) {
	const std::string h = home();

	std::string p(p1);
	if (p.front() == '~') {
		p.erase(0, 1);
		p.insert(0, h);
	}
	return p;
}

bool Path::makeDir(const std::string & p1) {
	std::string p = Path::decompress(p1);
	struct stat st = {0};
	if (stat(p.c_str(), &st) == -1) {
		mkdir(p.c_str(), 0700);
		return true;
	}
	return false;
}
