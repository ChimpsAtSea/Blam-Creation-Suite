#pragma once

template<unsigned int offset>
struct s_prototype_child_to_parent
{
private:
	template <unsigned char offset_index>
	struct offset_type { using type = unsigned int; };

	template <>
	struct offset_type<1> { using type = unsigned short; };

	template <>
	struct offset_type<0> { using type = unsigned char; };

	static constexpr unsigned char k_offset_index = (offset < UCHAR_MAX / 4) ? 0 : ((offset < USHRT_MAX / 4) ? 1 : 2);
	using t_offset_type = typename offset_type<k_offset_index>::type;
	static constexpr t_offset_type k_offset = static_cast<t_offset_type>(offset * 4 + k_offset_index);

	static unsigned int rotate(unsigned int value)
	{
		return _byteswap_ulong(value);
	}

	static unsigned short rotate(unsigned short value)
	{
		return _byteswap_ushort(value);
	}

	static unsigned char rotate(unsigned char value)
	{
		return value;
	}

public:
	t_offset_type packed_offset = rotate(k_offset);
};

#define prototype_child_to_parent(size, name) protected: s_prototype_child_to_parent<size> name; public:

class h_prototype :
	public h_extended_type
{
	intelliaccess(public, protected) :;

	struct h_prototype_function_table :
		public h_high_level_function_table
	{
		h_prototype* (*prototype_constructor)(h_extended_type* parent) = nullptr;
		void (*prototype_destructor)(h_prototype*) = nullptr;
		size_t (*get_size)() = nullptr;
		h_member_info const* (h_prototype::* get_member_information)(unsigned int& num_member_information) = nullptr;
		h_serialization_info const* (h_prototype::* get_serialization_information)(unsigned int& num_serialization_information) = nullptr;
	};

protected:
	static constexpr unsigned short k_global_vftable_index = 0;
	static constexpr unsigned short k_local_vftable_index = USHRT_MAX;

	h_prototype(h_extended_type const&) = delete;
	BCS_SHARED h_prototype(
		h_extended_type* parent,
		unsigned char _global_vftable_index,
		unsigned short _local_vftable_index);

public:
	h_member_info const* get_member_information(unsigned int& num_member_information)
	{
		h_prototype_function_table* vftable = static_cast<h_prototype_function_table*>(global_vtables[__global_vftable_index][__local_vftable_index]);
		return (this->*vftable->get_member_information)(num_member_information);
	};

	h_serialization_info const* get_serialization_information(unsigned int& num_serialization_information)
	{
		h_prototype_function_table* vftable = static_cast<h_prototype_function_table*>(global_vtables[__global_vftable_index][__local_vftable_index]);
		return (this->*vftable->get_serialization_information)(num_serialization_information);
	};

	size_t get_size()
	{
		h_prototype_function_table* vftable = static_cast<h_prototype_function_table*>(global_vtables[__global_vftable_index][__local_vftable_index]);
		return vftable->get_size();
	};

	// #TODO: Wrap all types such that they are h_field
	h_type& get_member(h_pointer_to_member pointer_to_member)
	{
		return this->*pointer_to_member;
	}

protected:
	//unsigned int relative_address_to_parent;
};
