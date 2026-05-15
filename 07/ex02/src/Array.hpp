#pragma once

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array
{
private:
	unsigned int m_n{};
	T* m_data{};

public:
	Array() = default;
	Array(unsigned int n) : m_n{ n }, m_data{ new T[n]{} } {}
	Array(const Array& other) : m_n{ other.m_n }, m_data{ new T[other.m_n]{} }
	{
		for (std::size_t i{}; i < m_n; ++i)
			m_data[i] = other.m_data[i];
	}
	~Array() { delete[] m_data; }

	unsigned int size() const { return m_n; }

	Array& operator=(const Array& other)
	{
		if (this == &other)
			return *this;
		T* temp = new T[other.m_n];
		for (std::size_t i{}; i < other.m_n; ++i)
			temp[i] = other.m_data[i];
		delete[] m_data;
		m_data = temp;
		m_n = other.m_n;
		return *this;
	}

	T& operator[](unsigned int index)
	{
		if (index >= m_n)
			throw std::out_of_range{ "Index out of bounds" };
		return m_data[index];
	}

	const T& operator[](unsigned int index) const
	{
		if (index >= m_n)
			throw std::out_of_range{ "Index out of bounds" };
		return m_data[index];
	}
};
