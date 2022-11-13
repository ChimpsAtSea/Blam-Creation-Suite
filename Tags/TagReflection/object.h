#pragma once

class h_tag_reference;
class h_block;
class h_enumerable;
class h_data;
class h_string_id;

namespace blofeld
{
	struct s_tag_struct_definition;
	struct s_tag_field;
}

class h_prototype :
	public h_type
{
public:
	h_prototype(h_type* parent = nullptr);
	virtual ~h_prototype();

	BCS_SHARED static h_prototype* create_high_level_object(blofeld::s_tag_struct_definition const& struct_definition, s_engine_platform_build engine_platform_build);

	virtual const void* get_field_data_unsafe(blofeld::s_tag_field const& field) const = 0;
	virtual void* get_field_data_unsafe(blofeld::s_tag_field const& field) = 0;		
	virtual const h_type* get_field_data(blofeld::s_tag_field const& field) const = 0;
	virtual h_type* get_field_data(blofeld::s_tag_field const& field) = 0;
	virtual blofeld::s_tag_struct_definition const& get_blofeld_struct_definition() const = 0;
	virtual uint32_t get_version() const = 0;
	virtual blofeld::s_tag_field const* const* get_blofeld_field_list() const = 0;
	virtual blofeld::s_tag_field const* const* get_blofeld_field_list_deprecated() const = 0;
	virtual bool is_field_active(blofeld::s_tag_field const& field) const = 0;

	virtual bool operator==(h_prototype const& value) const;
	virtual bool operator!=(h_prototype const& value) const;

	template<typename T>
	T* get_field_data(blofeld::s_tag_field const& field)
	{
#define get_field_data_valid_type(blofeld_field_type, highlevel_type) \
		if constexpr (std::is_same<T, highlevel_type>::value) \
			if (field.field_type == blofeld_field_type) \
				return static_cast<T*>(get_field_data_unsafe(field));

		get_field_data_valid_type(blofeld::_field_tag_reference, h_tag_reference);
		get_field_data_valid_type(blofeld::_field_block, h_block);
		get_field_data_valid_type(blofeld::_field_block, h_enumerable);
		get_field_data_valid_type(blofeld::_field_array, h_enumerable);
		get_field_data_valid_type(blofeld::_field_struct, h_prototype);
		get_field_data_valid_type(blofeld::_field_data, h_data);
		get_field_data_valid_type(blofeld::_field_string_id, h_string_id);
		get_field_data_valid_type(blofeld::_field_old_string_id, h_string_id);

#undef get_field_data_valid_type
		throw;
		return nullptr;
	}
};
