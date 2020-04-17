#include "blamboozle-private-pch.h"

c_blamboozle_h5_forge::c_blamboozle_h5_forge(const wchar_t* _output_directory, const wchar_t* _binary_filepath) :
	c_blamboozle_base(_output_directory, _binary_filepath)
{
	output_directory += L"halo5\\";
}

c_blamboozle_h5_forge::~c_blamboozle_h5_forge()
{

}

int c_blamboozle_h5_forge::run()
{
	return 0;
}
