#include "blamboozle-private-pch.h"

c_blamboozle_base::c_blamboozle_base(const wchar_t* _output_directory, const wchar_t* _binary_filepath) :
	output_directory(_output_directory),
	binary_filepath(_binary_filepath)
{
	if (output_directory.empty() || output_directory.end()[-1] != L'\\')
	{
		output_directory += L'\\';
	}
}

c_blamboozle_base::~c_blamboozle_base()
{

}
