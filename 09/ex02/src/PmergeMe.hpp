#pragma once

#include <algorithm>
#include <cassert>
#include <chrono>
#include <concepts>
#include <cstddef>
#include <iterator>
#include <ranges>
#include <ratio>
#include <span>
#include <vector>

template <typename T>
concept UIntRange = std::ranges::range<T> && std::same_as<std::ranges::range_value_t<T>, unsigned int>;

class PmergeMe {
private:
	std::vector<unsigned int> _data;

public:
	PmergeMe(const std::span<const char*>& args);
	~PmergeMe() = default;
	PmergeMe() = delete;
	PmergeMe(const PmergeMe& other) = delete;
	PmergeMe& operator=(const PmergeMe& other) = delete;

	[[nodiscard]] const std::vector<unsigned int>& getUnsortedSequence() const noexcept;

	double run(UIntRange auto& r) {
		r.assign(_data.cbegin(), _data.cend());

		auto startTime{ std::chrono::steady_clock::now() };
		sort(r, 1);
		auto endTime{ std::chrono::steady_clock::now() };

		std::chrono::duration<double, std::micro> sortTime{ endTime - startTime };
		assert(std::ranges::is_sorted(r) && "container is not sorted");
		return sortTime.count();
	}

	void sort(UIntRange auto& r, std::size_t stride) {
		auto pair = stride * 2;
		if (pair > std::ranges::size(r))
			return;

		auto it{ std::ranges::begin(r) };
		std::size_t remaining{ std::ranges::size(r) };
		while (remaining >= pair) {
			auto next{ std::next(it, static_cast<long>(stride)) };
			auto a{ std::next(it, static_cast<long>(stride - 1)) };
			auto b{ std::next(next, static_cast<long>(stride - 1)) };
			if (*a > *b)
				std::swap_ranges(it, next, next);
			std::advance(it, pair);
			remaining -= pair;
		}
		sort(r, pair);

		using It = decltype(std::ranges::begin(r));
		std::vector<It> main;
		std::vector<It> pend;
		index(r, main, pend, stride);
		mergeInsert(r, main, pend, stride);
		reassemble(r, main, stride);
	}

	void index(UIntRange auto& r, auto& main, auto& pend, std::size_t stride) {
		auto pair = stride * 2;

		auto it{ std::ranges::begin(r) };
		std::size_t remaining{ std::ranges::size(r) };
		if (remaining >= pair) {
			auto b{ it };
			auto a{ std::next(it, static_cast<long>(stride)) };
			main.push_back(b);
			main.push_back(a);
			std::advance(it, pair);
			remaining -= pair;
		}

		while (remaining >= pair) {
			auto b{ it };
			auto a{ std::next(it, static_cast<long>(stride)) };
			main.push_back(a);
			pend.push_back(b);
			std::advance(it, pair);
			remaining -= pair;
		}

		if (remaining >= stride)
			pend.push_back(it);
	}

	void mergeInsert(UIntRange auto& r, auto& main, auto& pend, std::size_t stride) {
		using It = decltype(std::ranges::begin(r));

		if (pend.empty())
			return;

		auto comp = [stride](It lhs, It rhs) {
			auto val_lhs{ std::next(lhs, static_cast<long>(stride - 1)) };
			auto val_rhs{ std::next(rhs, static_cast<long>(stride - 1)) };
			return *val_lhs < *val_rhs;
		};

		std::size_t prev_jacob{ 1 };
		std::size_t curr_jacob{ 3 };
		std::size_t added{};

		while (true) {
			std::size_t start{ curr_jacob - 2 };
			if (start >= pend.size())
				start = pend.size() - 1;
			std::size_t end{ prev_jacob - 1 };

			for (std::size_t i{ start };; --i) {
				auto it_loser{ pend[i] };

				std::size_t bound = i + 2 + added;
				if (bound > main.size())
					bound = main.size();

				auto search_end{ main.begin() + static_cast<long>(bound) };
				auto insertPos{ std::upper_bound(main.begin(), search_end, it_loser, comp) };
				main.insert(insertPos, it_loser);
				++added;

				if (i == end) {
					break;
				}
			}

			if (start == pend.size() - 1)
				break;
			std::size_t next_jacob{ curr_jacob + (2 * prev_jacob) };
			prev_jacob = curr_jacob;
			curr_jacob = next_jacob;
		}
	}

	void reassemble(UIntRange auto& r, auto& main, std::size_t stride) {
		using It = decltype(std::ranges::begin(r));

		std::vector<unsigned int> temp;
		temp.reserve(std::ranges::size(r));
		for (It it_main : main) {
			auto end{ std::next(it_main, static_cast<long>(stride)) };
			for (auto it{ it_main }; it != end; ++it)
				temp.push_back(*it);
		}

		std::size_t remainder{ std::ranges::size(r) % stride };
		if (remainder > 0) {
			auto tail{ std::ranges::end(r) };
			std::advance(tail, -static_cast<long>(remainder));
			for (auto it{ tail }; it != std::ranges::end(r); ++it)
				temp.push_back(*it);
		}

		std::copy(temp.begin(), temp.end(), std::ranges::begin(r));
	}
};
