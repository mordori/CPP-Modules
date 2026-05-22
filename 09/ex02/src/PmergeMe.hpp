#pragma once

#include <algorithm>
#include <cassert>
#include <chrono>
#include <concepts>
#include <ranges>
#include <ratio>
#include <span>
#include <vector>

template <typename T>
concept UIntRange = std::ranges::range<T> && std::same_as<std::ranges::range_value_t<T>, unsigned int>;

class PmergeMe {
private:
	std::vector<unsigned int> _vector;

public:
	PmergeMe(const std::span<const char*>& args);
	~PmergeMe() = default;
	PmergeMe() = delete;
	PmergeMe(const PmergeMe& other) = delete;
	PmergeMe& operator=(const PmergeMe& other) = delete;

	[[nodiscard]] const std::vector<unsigned int>& getUnsortedSequence() const;

	double run(UIntRange auto& r) {
		r.assign(_vector.cbegin(), _vector.cend());
		auto startTime{ std::chrono::steady_clock::now() };
		sort(r);
		auto endTime{ std::chrono::steady_clock::now() };
		std::chrono::duration<double, std::micro> sortTime = endTime - startTime;
		return sortTime.count();
	}

	void sort(UIntRange auto& r) {
		(void)r;
		assert(std::ranges::is_sorted(r) && "container is not sorted");
	}
};
