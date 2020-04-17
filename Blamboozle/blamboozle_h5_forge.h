#pragma once

class c_blamboozle_h5_forge :
	public c_blamboozle_base
{
public:
	c_blamboozle_h5_forge(const wchar_t* output_directory, const wchar_t* binary_filepath);
	~c_blamboozle_h5_forge();
	virtual int run() override final;
};

