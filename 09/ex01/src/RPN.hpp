#pragma once

#include <stack>
#include <string>

class RPN {
private:
	std::stack<int> _stack;

	void calculate(char op);

public:
	RPN() = default;
	~RPN() = default;
	RPN(const RPN& other) = delete;
	RPN& operator=(const RPN& other) = delete;

	int evaluate(const std::string& expression);
};
