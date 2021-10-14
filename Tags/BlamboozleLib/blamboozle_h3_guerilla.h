#pragma once

class c_blamboozle_h3_guerilla :
	public c_blamboozle_base
{
public:
	c_blamboozle_h3_guerilla(const wchar_t* output_directory, const wchar_t* binary_filepath, e_build build);
	~c_blamboozle_h3_guerilla();
	virtual int run() override final;
};
