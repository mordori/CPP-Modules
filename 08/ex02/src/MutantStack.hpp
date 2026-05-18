#pragma once

#include <iterator>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
private:
	std::stack<T> _stack;

public:
	auto begin() {
		return this->c.begin();
	}
	auto end() {
		return this->c.end();
	}
	auto cbegin() {
		return this->c.cbegin();
	}
	auto cend() {
		return this->c.cend();
	}
};
