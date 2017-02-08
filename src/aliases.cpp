#include "aliases.h"

#include <fstream>

#include "defs.h"
#include "path.h"


Aliases *Aliases::main;

Aliases::Aliases() :
	Aliases(PATH_ALIAS) {}

Aliases::Aliases(const std::string path) {
	this->path = Path::decompress(path);

	this->load();
}

bool Aliases::has(const std::string name) const {
	return map.count(name) > 0;
}

std::string Aliases::get(const std::string name) const {
	return map.at(name);
}

void Aliases::set(const std::string name, const std::string value) {
	map[name] = value;

	this->store();
}

void Aliases::setDefault(const std::string name, const std::string value) {
	if (map.count(name) == 0) {
		this->set(name, value);
	}
}

std::vector<std::string> Aliases::getKeys() const {
	std::vector<std::string> keys;

	for (auto& i : map) {
		keys.push_back(i.first);
	}

	return keys;
}

void Aliases::load() {
	std::ifstream stream(this->path);

	std::string name, value;
	while (std::getline(stream, name, '=')) {
		std::getline(stream, value);

		map[name] = value;
	}

	stream.close();
}

void Aliases::store() const {
	std::ofstream stream(this->path);

	for (auto& i : map) {
		stream << i.first << "=" << i.second << std::endl;
	}

	stream.close();
}
