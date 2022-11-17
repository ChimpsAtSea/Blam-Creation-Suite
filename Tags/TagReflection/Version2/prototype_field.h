#pragma once

template<typename t_parent_type, uint32_t _field_index>
using h_prototype_string_id_field = h_string_id_field;

template<typename t_type, typename t_parent_type, uint32_t _field_index>
using h_prototype_block = h_typed_block<t_type>;

template<typename t_type, typename t_parent_type, uint32_t _field_index>
using h_prototype_array = h_typed_block<t_type>;

#ifdef BCS_HIGH_LEVEL_USE_TRIVIAL_FIELDS

template<typename t_type, typename t_parent_type, uint32_t _field_index>
using h_prototype_field = h_typed_field<t_type>;

#else

class h_prototype;

template<typename t_type, typename t_parent_type, unsigned int field_index>
struct h_prototype_field :
	public h_typed_field<t_type>
{
	// static_assert(sizeof(h_prototype_field<t_type, t_parent_type, field_index>) == sizeof(h_typed_field<t_type>));
	h_prototype_field() = delete;
	h_prototype_field(h_prototype_field const&) = delete;
	~h_prototype_field() = default;

	void do_a_flip()
	{
		h_typed_field::do_a_flip();
	}

	t_parent_type& get_parent()
	{
		h_member_info& member_info = t_parent_type::member_information[field_index];
		h_prototype& parent_prototype = h_typed_field<t_type>::get_parent(member_info);
		return static_cast<t_parent_type&>(parent_prototype);

		//h_pointer_to_member pointer_to_menber = ;
		//static_assert(sizeof(pointer_to_menber) == 4);

		//intptr_t this_address = reinterpret_cast<intptr_t>(this);
		//int relative_offset = *reinterpret_cast<int*>(&pointer_to_menber);
		//intptr_t parent_address = this_address - relative_offset;

		//t_parent_type* parent = reinterpret_cast<t_parent_type*>(parent_address);
		//return *parent;
	}

	const char* get_name()
	{
		h_member_info& member_info = t_parent_type::member_information[field_index];
		return member_info.name;
	}
};

#endif
