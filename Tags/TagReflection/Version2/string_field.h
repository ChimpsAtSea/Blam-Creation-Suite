#pragma once

class h_string_id_field :
	public h_field
{
public:
	BCS_SHARED h_string_id_field();
	BCS_SHARED h_string_id_field(const char* string);
	BCS_SHARED h_string_id_field(h_string_id_field const& string_id);
	BCS_SHARED ~h_string_id_field();

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
