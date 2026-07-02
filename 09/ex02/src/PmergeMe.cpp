#include "PmergeMe.hpp"

#include <charconv>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <vector>

PmergeMe::PmergeMe(const std::span<const char*>& args) {
	for (std::string_view sv : args) {
		if (sv.empty())
			continue;
		if (sv.front() == '+')
			sv.remove_prefix(1);
		unsigned int i{};
		auto [ptr, ec]{ std::from_chars(sv.data(), sv.data() + sv.size(), i) };
		if (ec != std::errc{} || ptr != sv.data() + sv.size())
			throw std::runtime_error{ "invalid token '" + std::string{ sv } + "'" };
		_data.push_back(i);
	}
}

const std::vector<unsigned int>& PmergeMe::getUnsortedSequence() const noexcept {
	return _data;
}
