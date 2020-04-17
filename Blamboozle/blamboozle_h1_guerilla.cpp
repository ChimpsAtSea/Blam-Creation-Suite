#include "blamboozle-private-pch.h"

c_blamboozle_h1_guerilla::c_blamboozle_h1_guerilla(const wchar_t* _output_directory, const wchar_t* _binary_filepath) :
	c_blamboozle_base(_output_directory, _binary_filepath)
{
	output_directory += L"halo1\\";
}

c_blamboozle_h1_guerilla::~c_blamboozle_h1_guerilla()
{

}

int c_blamboozle_h1_guerilla::run()
{
	return 0;
}
