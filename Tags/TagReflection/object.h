#pragma once

class h_tag_reference;
class h_block;
class h_enumerable;

class h_prototype :
	public h_type
{
public:
	h_prototype(h_type* parent = nullptr);
	virtual ~h_prototype();

	static h_prototype* create_high_level_object(const blofeld::s_tag_struct_definition& struct_definition, s_engine_platform_build engine_platform_build);

	virtual void* get_field_data_unsafe(const blofeld::s_tag_field& field) = 0;
	inline const void* get_field_data_unsafe(const blofeld::s_tag_field& field) const
	{
		return const_cast<h_prototype*>(this)->get_field_data_unsafe(field);
	}
	virtual bool is_field_active(const blofeld::s_tag_field& field) const = 0;
	virtual const blofeld::s_tag_struct_definition& get_blofeld_struct_definition() const = 0;
	virtual const blofeld::s_tag_field* const* get_blofeld_field_list() const = 0;
	virtual unsigned long long get_type_guid() const = 0;

	template<typename T>
	T* get_field_data_unsafe(const blofeld::s_tag_field& field)
	{
		return static_cast<T*>(get_field_data_unsafe(field));
	}

	template<typename T>
	T* get_field_data(const blofeld::s_tag_field& field)
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
		

#undef get_field_data_valid_type
		throw;
		return nullptr;
	}











	//protected:
	//	h_prototype(h_prototype const&) = default;
};
