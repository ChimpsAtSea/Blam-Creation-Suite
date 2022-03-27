#include "mandrilllib-private-pch.h"

c_monolithic_partition_view::c_monolithic_partition_view(wchar_t* partition_filepath) :
	partition_filepath(_wcsdup(partition_filepath))
{

}

c_monolithic_partition_view::~c_monolithic_partition_view()
{
	untracked_free(partition_filepath);
}
