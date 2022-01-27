#pragma once

class c_blamboozle_reach_tags_test_x360 :
	public c_blamboozle_base
{
public:
	c_blamboozle_reach_tags_test_x360(const wchar_t* output_directory, const wchar_t* binary_filepath, e_build build);
	~c_blamboozle_reach_tags_test_x360();
	virtual int run() override final;
};
