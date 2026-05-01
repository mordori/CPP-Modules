#include <cstdint>
#include <iostream>

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data data{ 'a', 1 };
	std::cout << &data << '\n';
	uintptr_t ptr{ Serializer::serialize(&data) };
	std::cout << ptr << '\n';
	Data* data_ptr{ Serializer::deserialize(ptr) };
	std::cout << data_ptr << '\n';
	std::cout << data_ptr->m_char << '\n';
	std::cout << data_ptr->m_int << '\n';
	return 0;
}
