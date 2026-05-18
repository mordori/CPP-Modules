#include <array>
#include <concepts>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <ranges>
#include <string_view>
#include <vector>

#include "easyfind.hpp"

#define TEST(container, value) test(container, value, #container)

template <std::ranges::range T>
	requires std::same_as<std::ranges::range_value_t<T>, int>
void test(T& container, int value, std::string_view name) {
	name.remove_suffix(1);
	std::cout << name << " contains " << value << ": ";
	std::cout << (easyfind(container, value) != std::ranges::end(container)) << '\n';
}

int main() {
	std::cout << std::boolalpha;

	std::array<int, 3> array_{ 1, 2, 3 };
	TEST(array_, 1);
	TEST(array_, 0);
	std::cout << '\n';

	std::list<int> list_{ 1, 2, 3 };
	TEST(list_, 1);
	TEST(list_, 0);
	std::cout << '\n';

	std::forward_list<int> forward_list_{ 1, 2, 3 };
	TEST(forward_list_, 1);
	TEST(forward_list_, 0);
	std::cout << '\n';

	std::deque<int> deque_{ 1, 2, 3 };
	TEST(deque_, 1);
	TEST(deque_, 0);
	std::cout << '\n';

	std::vector<int> vector_{ 1, 2, 3 };
	TEST(vector_, 1);
	TEST(vector_, 0);
	std::cout << '\n';

	int c_array_[3]{ 1, 2, 3 };
	TEST(c_array_, 1);
	TEST(c_array_, 0);

	// Doesn't compile due to required concepts

	// std::array<float, 3> floatArray_{ 1, 2, 3 };
	// TEST(floatArray_, 1);

	// int int_ = 1;
	// TEST(int_, 1);

	return 0;
}
