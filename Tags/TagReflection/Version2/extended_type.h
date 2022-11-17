#pragma once

class h_prototype;

static constexpr unsigned int k_number_of_global_vftable_index_bits = 6;
static constexpr unsigned int k_number_of_local_vftable_index_bits = 16;
static constexpr unsigned int k_number_of_relative_address_to_parent_bits = 28;
static constexpr unsigned int k_number_of_is_child_bits = 1;
static constexpr unsigned int k_number_of_relative_address_to_parent_max = k_number_of_relative_address_to_parent_bits == 32 ? UINT_MAX : ((1u << k_number_of_relative_address_to_parent_bits) - 1);
static_assert(
	k_number_of_high_level_type_bits + 
	k_number_of_global_vftable_index_bits +
	k_number_of_local_vftable_index_bits +
	k_number_of_is_child_bits +
	k_number_of_relative_address_to_parent_bits == 56);

class h_extended_type
{
	intelliaccess(public, protected) :;

	h_extended_type(h_extended_type const&) = delete;
	h_extended_type(
		e_high_level_type _field_type,
		bool is_child,
		unsigned char _global_vftable_index,
		unsigned short _local_vftable_index);

	union
	{
		struct
		{
			e_high_level_type __field_type : k_number_of_high_level_type_bits;
		};
		struct
		{
			unsigned int : k_number_of_high_level_type_bits; // bitpad (__field_type)
			unsigned int __global_vftable_index : k_number_of_global_vftable_index_bits;
		};
		struct
		{
			unsigned char : 8; // bitpad (__field_type & __global_vftable_index)
			unsigned int : (k_number_of_high_level_type_bits + k_number_of_global_vftable_index_bits) - 8; // bitpad(__global_vftable_index)
			unsigned int __is_child : k_number_of_is_child_bits;
			unsigned int __relative_address_to_parent : k_number_of_relative_address_to_parent_bits;
		};
	};
	unsigned short __local_vftable_index;

	h_prototype* get_parent() const;
};
static_assert(sizeof(h_extended_type) == 7);
