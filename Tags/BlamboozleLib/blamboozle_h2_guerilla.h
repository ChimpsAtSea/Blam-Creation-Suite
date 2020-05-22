#pragma once

class c_blamboozle_h2_guerilla :
	public c_blamboozle_base
{
public:
	c_blamboozle_h2_guerilla(const wchar_t* output_directory, const wchar_t* binary_filepath);
	~c_blamboozle_h2_guerilla();
	virtual int run() override final;
};

