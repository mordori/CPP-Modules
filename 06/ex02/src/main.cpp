#include <cstddef>
#include <exception>
#include <iostream>
#include <random>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base* generate() {
	static std::mt19937 mt{ std::random_device{}() };
	std::uniform_int_distribution random02{ 0, 2 };
	switch (random02(mt)) {
		case 0:
			return new A{};
		case 1:
			return new B{};
		case 2:
			return new C{};
		default:
			return nullptr;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << 'A';
	else if (dynamic_cast<B*>(p))
		std::cout << 'B';
	else if (dynamic_cast<C*>(p))
		std::cout << 'C';
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << 'A';
		return;
	} catch (const std::exception& e) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << 'B';
		return;
	} catch (const std::exception& e) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << 'C';
		return;
	} catch (const std::exception& e) {}
}

int main() {
	Base* ptr[10]{};
	for (std::size_t i{}; i < 10; ++i)
		ptr[i] = generate();

	std::cout << "Ptr:\t";
	for (std::size_t i{}; i < 10; ++i)
		identify(ptr[i]);

	std::cout << "\nRef:\t";
	for (std::size_t i{}; i < 10; ++i)
		identify(*(ptr[i]));

	std::cout << '\n';
	for (std::size_t i{}; i < 10; ++i)
		delete ptr[i];
	return 0;
}
