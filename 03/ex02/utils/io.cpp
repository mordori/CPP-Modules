#include "io.hpp"

#include <ios>

IosFlags::IosFlags(std::ios_base& stream) :
	m_stream{ stream }, m_origFlags{ stream.flags() }
{}

IosFlags::~IosFlags()
{ m_stream.flags(m_origFlags); }
