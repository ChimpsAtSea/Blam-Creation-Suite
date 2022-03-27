#pragma once

class c_monolithic_partition_view
{
public:
	c_monolithic_partition_view(wchar_t* partition_filepath);
	~c_monolithic_partition_view();

	const wchar_t* partition_filepath;
};
