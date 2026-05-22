#include "RPN.hpp"

#include <cassert>
#include <charconv>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>

namespace {
constexpr bool isOperator(std::string_view token) noexcept {
	constexpr std::string_view operators = "+-*/";
	if (token.size() != 1)
		return false;
	return operators.find(token.front()) != std::string_view::npos;
}
}

void RPN::calculate(char op) {
	if (_stack.size() < 2)
		throw std::runtime_error{ "not enough operands" };
	long right{ _stack.top() };
	_stack.pop();
	long left{ _stack.top() };
	_stack.pop();
	long result{};
	switch (op) {
		case '+': result = left + right; break;
		case '-': result = left - right; break;
		case '*': result = left * right; break;
		case '/':
			if (right == 0)
				throw std::runtime_error{ "division by 0" };
			result = left / right;
			break;
		default: assert(false && "unreachable");
	}
	if (result < std::numeric_limits<int>::min() || result > std::numeric_limits<int>::max())
		throw std::length_error{ "expression surpasses int limits" };
	_stack.push(static_cast<int>(result));
}

int RPN::evaluate(const std::string& expression) {
	std::istringstream iss{ expression };
	std::string s;
	while (iss >> s) {
		std::string_view sv{ s };
		if (isOperator(sv))
			calculate(sv.front());
		else {
			int number{};
			if (sv.front() == '+')
				sv.remove_prefix(1);
			auto [ptr, ec]{ std::from_chars(sv.data(), sv.data() + sv.size(), number) };
			if (ec != std::errc{} || ptr != sv.data() + sv.size())
				throw std::runtime_error{ "invalid token '" + s + "'" };
			_stack.push(number);
		}
	}
	if (_stack.size() != 1)
		throw std::runtime_error{ "invalid token '" + s + "'" };
	return _stack.top();
}
