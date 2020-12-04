#pragma once

class c_resource_entry
{
public:
	virtual void* get_pageable_data();
	virtual uint32_t get_compressed_size();
	virtual uint32_t get_uncompressed_size();
};
