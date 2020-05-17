#pragma once

inline bool string_ends_with(std::string const& string, std::string const& ending)
{
	if (string.length() >= ending.length())
	{
		return (0 == string.compare(string.length() - ending.length(), ending.length(), ending));
	}
	return false;
}

