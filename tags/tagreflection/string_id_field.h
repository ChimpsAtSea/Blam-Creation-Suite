#pragma once

class h_string_id_field :
	public h_field
{
public:
	h_string_id_field() = delete;
	BCS_SHARED h_string_id_field(h_prototype& parent);
	//BCS_SHARED h_string_id_field(const char* string);
	h_string_id_field(h_string_id_field const& string_id) = delete;
	BCS_SHARED ~h_string_id_field();

protected:
	virtual void const* get_data() const override;
	virtual void* get_data() override;

public:

	BCS_SHARED const char* get_string() const;
	BCS_SHARED void set_string(const char* string);
	BCS_SHARED void set_string(const char* string_start, const char* string_end);
	BCS_SHARED void clear();
	BCS_SHARED h_string_id_field& operator=(h_string_id_field const& value);
	BCS_SHARED h_string_id_field& operator=(const char* const& value);
	BCS_SHARED bool operator==(h_string_id_field const& value) const;
	BCS_SHARED bool operator==(const char* const& value) const;
	BCS_SHARED bool operator!=(h_string_id_field const& value) const;
	BCS_SHARED bool operator!=(const char* const& value) const;

protected:
	const char* string;
};

#ifdef BCS_HIGH_LEVEL_USE_TRIVIAL_FIELDS

template<typename t_parent_type, uint32_t _field_index>
using h_prototype_string_id_field = h_string_id_field;

#else

// #TODO

template<typename t_parent_type, uint32_t _field_index>
using h_prototype_string_id_field = h_string_id_field;

#endif