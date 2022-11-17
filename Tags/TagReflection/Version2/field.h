#pragma once

class h_prototype;
class h_member_info;

class h_field :
	public h_type
{
	intelliaccess(public, protected) :;

	h_field(h_type const&) = delete;
	h_field(e_high_level_type field_type) :
		h_type(field_type)
	{
	}
	~h_field() = default;

protected:
	////struct s_vftable :
	////	public s_high_level_vtable
	////{
	////	void (h_field::* do_a_barrel_roll)() = &do_a_barrel_roll_impl;
	////	void* (h_field::* get_data)() = nullptr;
	////	unsigned int data_size = 0;
	////};

public:
	void* get_data()
	{
		return static_cast<h_type*>(this) + 1;
		//s_vftable* vftable = static_cast<s_vftable*>(global_vtables[k_global_vftable_index][__field_type]);
		//return (this->*vftable->get_data)();
	};

	unsigned int get_size()
	{
		switch (__field_type)
		{
		case _high_level_field_metadata_1byte: return 1;
		case _high_level_field_metadata_2byte: return 2;
		case _high_level_field_metadata_4byte: return 4;
		case _high_level_field_metadata_8byte: return 8;
		case _high_level_field_metadata_12byte: return 12;
		case _high_level_field_metadata_16byte: return 16;
		case _high_level_field_metadata_32byte: return 32;
		case _high_level_field_metadata_256byte: return 256;
		default: return 0;
		}
		//s_vftable* vftable = static_cast<s_vftable*>(global_vtables[k_global_vftable_index][__field_type]);
		//return vftable->data_size;
	};

	h_prototype& get_parent(h_member_info& member_info)
	{
		static_assert(sizeof(member_info.pointer_to_member) == sizeof(int));

		intptr_t this_address = reinterpret_cast<intptr_t>(this);
		int relative_offset = *reinterpret_cast<int*>(&member_info.pointer_to_member);
		intptr_t parent_address = this_address - relative_offset;

		h_prototype* parent = reinterpret_cast<h_prototype*>(parent_address);
		return *parent;
	}

	const char* get_name(h_member_info& member_info)
	{
		return member_info.name;
	}
};
