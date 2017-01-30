#include "string.h"

#include <cstring>

void String::copy(char* dest, const char* src) {
	strcpy(dest, src);
}

void String::copy(char** dest, const char* const* src) {
	unsigned int i = 0;
	while (src[i] != nullptr) {
		copy(dest[i], src[i]);
		i++;
	}
}

bool String::compare(const char* s1, const char* s2) {
	unsigned int i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i]) {
		i++;
	}
	return s1[i] == s2[i];
}

bool String::compare(const char* const* s1, const char* const* s2) {
	if (s1 == nullptr || s2 == nullptr) {
		return false;
	}
	unsigned int i = 0;
	while (s1[i] != nullptr && compare(s1[i], s2[i])) {
		i++;
	}
	return s1[i] == s2[i];
}

char* String::clone(const char* src) {
	// calc length
	unsigned int len = 0;
	while (src[len] != '\0') {
		len++;
	}
	// clone string
	char *a = new char[len + 1];
	for (unsigned int i = 0; i <= len; i++) {
		a[i] = src[i];
	}
	return a;
}

char** String::clone(char* const* src) {
	// calc length
	unsigned int len = 0;
	while (src[len] != nullptr) {
		len++;
	}
	// clone string
	char **a = new char*[len + 1];
	for (unsigned int i = 0; i <= len; i++) {
		a[i] = src[i];
	}
	return a;
}

char** String::cloneLeading(char* const* src) {
	// calc length
	unsigned int len = 0;
	while (src[len] != nullptr) {
		len++;
	}
	len--;
	// clone string
	char **a = new char*[len + 1];
	for (unsigned int i = 0; i < len; i++) {
		a[i] = src[i];
	}
	a[len] = nullptr;
	return a;
}
