#pragma once

#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {
public:
	using iterator = typename Container::iterator;
	using reverse_iterator = typename Container::reverse_iterator;
	using const_iterator = typename Container::const_iterator;
	using const_reverse_iterator = typename Container::const_reverse_iterator;

	MutantStack() = default;
	MutantStack(const MutantStack& other) = default;
	~MutantStack() = default;
	MutantStack& operator=(const MutantStack& other) = default;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }

	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }
	const_reverse_iterator rbegin() const { return this->c.rbegin(); }
	const_reverse_iterator rend() const { return this->c.rend(); }

	const_iterator cbegin() const { return this->c.cbegin(); }
	const_iterator cend() const { return this->c.cend(); }
	const_reverse_iterator crbegin() const { return this->c.crbegin(); }
	const_reverse_iterator crend() const { return this->c.crend(); }
};
