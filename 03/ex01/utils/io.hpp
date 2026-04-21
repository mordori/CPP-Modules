#pragma once

#include <ios>

struct IosFlags
{
	std::ios_base& m_stream;
	std::ios_base::fmtflags m_origFlags;

	explicit IosFlags(std::ios_base& stream);
	~IosFlags();
};

