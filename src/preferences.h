#pragma once

#include <string>
#include <unordered_map>
#include <vector>


/**
 * Stores name-value pairs inside a ini formated file.
 */
class Preferences {
public:

	static Preferences *main;

	/**
	 * Creates and loads all preferences from the defualt path.
	 */
	Preferences();

	/**
	 * Creates and loads all preferences from a given path.
	 */
	Preferences(const std::string path);

	/**
	 * Get a value based on a given name.
	 */
	std::string get(const std::string name) const;
	int getInt(const std::string name) const;

	/**
	 * Sets a value for a given name.
	 */
	void set(const std::string name, const std::string value);
	void set(const std::string name, int value);

	/**
	 * Sets a value for a given name only if it's missing.
	 */
	void setDefault(const std::string name, const std::string value);
	void setDefault(const std::string name, int value);

	/**
	 * Get the path of the preferences ini file.
	 */
	std::string getPath() const { return path; }

	std::vector<std::string> getKeys() const;

protected:

	std::string path;

	std::unordered_map<std::string, std::string> map;

private:

	void load();
	void store() const;
};