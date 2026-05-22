#include <cstddef>
#include <exception>
#include <iostream>
#include <list>
#include <ostream>
#include <ranges>
#include <span>
#include <string_view>
#include <vector>

#include "PmergeMe.hpp"

#define OUTPUT(container, type, time) printContainerTime(container, type, time)

template <typename T>
concept Printable = requires(std::ostream& os, const T& obj) { os << obj; };

void printContainerTime(UIntRange auto& r, std::string_view type, double time) {
	std::cout << "Time to process a range of " << r.size() << " elements with " << type << " :\t " << time << " us\n";
}

template <std::ranges::range Range>
	requires Printable<std::ranges::range_value_t<Range>>
void printContents(const Range& r) {
	if (std::ranges::empty(r))
		return;
	auto it = std::ranges::cbegin(r);
	std::cout << *it;
	++it;
	for (; it != std::ranges::cend(r); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

int main(int argc, const char** argv) {
	if (argc < 2) {
		std::cerr << "Error: sequence of numbers is required as arguments\n";
		return 1;
	}
	try {
		auto args{ std::span<const char*>(argv, static_cast<std::size_t>(argc)).subspan(1) };
		PmergeMe sorter{ args };
		std::vector<unsigned int> vector_;
		std::list<unsigned int> list_;
		double timeVector{ sorter.run(vector_) };
		double timeList{ sorter.run(list_) };
		std::cout << "Before:\t  ";
		printContents(sorter.getUnsortedSequence());
		std::cout << "After:\t  ";
		printContents(vector_);
		OUTPUT(vector_, "std::vector<unsigned int>", timeVector);
		OUTPUT(list_, "std::list<unsigned int>  ", timeList);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
	} catch (...) {
		std::cerr << "Error: unknown\n";
	}
	return 0;
}
