#pragma once

#include <algorithm>

template <typename T, std::is_same<T, std::array>>
static constexpr bool easyfind(T container, int value)
{
	auto result{ std::find(container.begin(), container.end(), value) };
	return result == container.begin();
}
