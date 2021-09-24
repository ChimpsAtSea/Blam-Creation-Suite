#pragma once

//inline bool string_ends_with(std::string const& string, std::string const& ending)
//{
//	if (string.length() >= ending.length())
//	{
//		return (0 == string.compare(string.length() - ending.length(), ending.length(), ending));
//	}
//	return false;
//}
//
//inline void string_transform_lowercase(char* begin, char* end)
//{
//	for (char* pos = begin; pos < end; pos++)
//	{
//		*pos = tolower(*pos);
//	}
//}
//
//inline void string_transform_lowercase(char* string, size_t size)
//{
//	string_transform_lowercase(string, string + size);
//}
//
//inline void string_transform_uppercase(char* begin, char* end)
//{
//	for (char* pos = begin; pos < end; pos++)
//	{
//		*pos = toupper(*pos);
//	}
//}
//
//inline void string_transform_uppercase(char* string, size_t size)
//{
//	string_transform_uppercase(string, string + size);
//}
//
//inline bool string_replace(std::string& string, std::string search, std::string replace)
//{
//	bool replaced = false;
//
//	size_t current_position = string.find(search);
//	while (current_position != std::string::npos)
//	{
//		replaced = true;
//		string.replace(current_position, search.size(), replace);
//		current_position = string.find(search, current_position + replace.size());
//	}
//
//	return replaced;
//}
//
//inline void string_remove(std::string& string, std::string search)
//{
//	string_replace(string, search, "");
//}
