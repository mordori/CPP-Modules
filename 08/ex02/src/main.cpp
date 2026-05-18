#include <iostream>
#include <list>
#include <stack>
#include <string_view>

#include "MutantStack.hpp"

int main() {
	{
		std::cout << "Subject test for MutantStack.\n";
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << std::endl;

	{
		std::cout << "Same but list instead of MutantStack.\n";
		std::list<int> list_;
		list_.push_back(5);
		list_.push_back(17);
		std::cout << list_.back() << std::endl;
		list_.pop_back();
		std::cout << list_.size() << std::endl;
		list_.push_back(3);
		list_.push_back(5);
		list_.push_back(737);
		//[...]
		list_.push_back(0);
		auto it = list_.begin();
		auto ite = list_.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::cout << std::endl;

	{
		std::cout << "Testing MutantStack with string_view and constant iterators.\n";
		MutantStack<std::string_view> mstack;
		mstack.push("1");
		mstack.push("2");
		mstack.push("3");
		mstack.push("Sauna!");
		std::cout << "Forward\n";
		auto cit = mstack.cbegin();
		auto cend = mstack.cend();
		while (cit != cend) {
			std::cout << *cit << '\n';
			++cit;
		}
		std::cout << "\nBackward\n";
		auto crit = mstack.crbegin();
		auto crend = mstack.crend();
		while (crit != crend) {
			std::cout << *crit << '\n';
			++crit;
		}
	}
	return 0;
}
