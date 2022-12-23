#pragma once

class h_extended_type :
	public h_type
{
	intelliaccess(public, protected) :;

	h_extended_type(h_extended_type const&) = delete;
	h_extended_type(
		h_type* parent,
		unsigned char _global_vftable_index = UINT8_MAX,
		unsigned short _local_vftable_index = UINT16_MAX);

	unsigned char __global_vftable_index;
	unsigned short __local_vftable_index;
};
