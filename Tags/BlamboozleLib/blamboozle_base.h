#pragma once

class c_blamboozle_base
{
public:
	c_blamboozle_base(const wchar_t* output_directory, const wchar_t* binary_filepath);
	virtual ~c_blamboozle_base();
	virtual int run() = 0;


	std::wstring output_directory;
	std::wstring binary_filepath;
};

