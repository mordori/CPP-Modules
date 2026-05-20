#pragma once

#include <stack>
#include <string_view>

class RPN {
private:
	std::stack<int> _stack;

public:
	RPN() = default;
	~RPN() = default;

	RPN(const RPN& other) = delete;
	RPN& operator=(const RPN& other) = delete;

	int calculate(std::string_view sequence);
};
