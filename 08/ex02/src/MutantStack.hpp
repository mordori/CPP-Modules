#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	using container = typename std::stack<T>::container_type;

	using iterator = typename container::iterator;
	using reverse_iterator = typename container::reverse_iterator;
	using const_iterator = typename container::const_iterator;
	using const_reverse_iterator = typename container::const_reverse_iterator;

	MutantStack() = default;
	MutantStack(const MutantStack& other) = default;
	~MutantStack() = default;
	MutantStack& operator=(const MutantStack& other) = default;

	auto begin() {
		return this->c.begin();
	}
	auto end() {
		return this->c.end();
	}
	auto rbegin() {
		return this->c.rbegin();
	}
	auto rend() {
		return this->c.rend();
	}
	auto cbegin() const {
		return this->c.cbegin();
	}
	auto cend() const {
		return this->c.cend();
	}
	auto crbegin() const {
		return this->c.crbegin();
	}
	auto crend() const {
		return this->c.crend();
	}
};
