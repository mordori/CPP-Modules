#pragma once

#include <algorithm>
#include <concepts>
#include <ranges>

template <std::ranges::range T>
	requires std::same_as<std::ranges::range_value_t<T>, int>
auto easyfind(T& container, int value) {
	return std::ranges::find(container, value);
}
