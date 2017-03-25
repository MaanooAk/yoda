#pragma once

#include <string>
#include <unordered_map>
#include <vector>


/**
 * Stores name-value pairs inside a ini formated file.
 */
class Aliases {
public:

	static Aliases *main;

	/**
	 * Creates and loads all preferences from the defualt path.
	 */
	Aliases();

	/**
	 * Creates and loads all preferences from a given path.
	 */
	Aliases(const std::string path);

	/**
	 * Check if a given name exists.
	 */
	bool has(const std::string name) const;

	/**
	 * Get a value based on a given name.
	 */
	std::string get(const std::string name) const;

	/**
	 * Sets a value for a given name.
	 */
	void set(const std::string name, const std::string value);

	/**
	 * Sets a value for a given name only if it's missing.
	 */
	void setDefault(const std::string name, const std::string value);

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