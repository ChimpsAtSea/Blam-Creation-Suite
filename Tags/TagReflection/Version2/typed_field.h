#pragma once

template<typename t_type>
constexpr e_high_level_type type_to_id()
{
#define type_to_id_helper(_type, high_level_type) if (std::is_same_v<t_type, _type>) return high_level_type
#define size_to_id_helper(_size, high_level_type) if (sizeof(t_type) == _size) return high_level_type

	size_to_id_helper(1, _high_level_field_metadata_1byte);
	size_to_id_helper(2, _high_level_field_metadata_2byte);
	size_to_id_helper(4, _high_level_field_metadata_4byte);
	size_to_id_helper(8, _high_level_field_metadata_8byte);
	size_to_id_helper(12, _high_level_field_metadata_12byte);
	size_to_id_helper(16, _high_level_field_metadata_16byte);
	size_to_id_helper(32, _high_level_field_metadata_32byte);
	size_to_id_helper(256, _high_level_field_metadata_256byte);

#undef type_to_id_helper
#undef type_to_id_helper
	return k_number_of_high_level_types;
}

class h_prototype;

template<typename t_type>
class h_typed_field :
	public h_field
{
	intelliaccess(public, protected) :;

	static constexpr e_high_level_type k_field_type = type_to_id<t_type>();
	static_assert(k_field_type < blofeld::k_number_of_blofeld_field_types);
	h_typed_field() :
		h_field(k_field_type),
		value()
	{

	}
	h_typed_field(t_type const& _value) : h_field(__field_type), value(_value) {}
	h_typed_field(t_type _value) : h_field(__field_type), value(_value) {}
	~h_typed_field() = default;

protected:
	t_type value;
};
