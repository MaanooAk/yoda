#include "preferences.h"

#include <fstream>

#include "defs.h"


Preferences *Preferences::main;

Preferences::Preferences() :
	Preferences(PATH_PREFERENCES) {}

Preferences::Preferences(const std::string path) {
	this->path = path;

	this->load();
}

std::string Preferences::get(const std::string name) const {
	return map.at(name);
}

int Preferences::getInt(const std::string name) const {
	return std::stoi(this->get(name));
}

void Preferences::set(const std::string name, const std::string value) {
	map[name] = value;

	this->store();
}

void Preferences::set(const std::string name, int value) {
	this->set(name, std::to_string(value));
}

void Preferences::setDefault(const std::string name, const std::string value) {
	if (map.count(name) == 0) {
		this->set(name, value);
	}
}

void Preferences::setDefault(const std::string name, int value) {
	this->setDefault(name, std::to_string(value));
}

std::vector<std::string> Preferences::getKeys() const {
	std::vector<std::string> keys;

	for (auto& i : map) {
		keys.push_back(i.first);
	}

	return keys;
}

void Preferences::load() {
	std::ifstream stream(this->path);

	std::string name, value;
	while (std::getline(stream, name, '=')) {
		std::getline(stream, value);

		map[name] = value;
	}

	stream.close();
}

void Preferences::store() const {
	std::ofstream stream(this->path);

	for (auto& i : map) {
		stream << i.first << "=" << i.second << std::endl;
	}

	stream.close();
}
