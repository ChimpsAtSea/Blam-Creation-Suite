#pragma once

class c_blamboozle_infinite :
	public c_blamboozle_base
{
public:
	c_blamboozle_infinite(const wchar_t* output_directory, const wchar_t* binary_filepath, e_build build);
	~c_blamboozle_infinite();
	virtual int run() override final;
};

