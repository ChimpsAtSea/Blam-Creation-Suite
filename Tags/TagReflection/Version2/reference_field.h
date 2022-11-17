#pragma once

class h_string_field :
	public h_field
{
public:
	BCS_SHARED h_string_field();
	BCS_SHARED h_string_field(const char* string);
	BCS_SHARED h_string_field(h_string_field const& string_id);
	BCS_SHARED ~h_string_field();

protected:
	void* get_data_impl();
public:
	struct s_vftable :
		h_field::s_vftable
	{
		s_vftable() :
			h_field::s_vftable()
		{
			get_data = reinterpret_cast<decltype(get_data)>(&get_data_impl);
		}

	};

public:

	BCS_SHARED const char* get_string() const;
	BCS_SHARED void set_string(const char* string);
	BCS_SHARED void set_string(const char* string_start, const char* string_end);
	BCS_SHARED void clear();
	BCS_SHARED h_string_field& operator=(h_string_field const& value);
	BCS_SHARED h_string_field& operator=(const char* const& value);
	BCS_SHARED bool operator==(h_string_field const& value) const;
	BCS_SHARED bool operator==(const char* const& value) const;
	BCS_SHARED bool operator!=(h_string_field const& value) const;
	BCS_SHARED bool operator!=(const char* const& value) const;

protected:
	const char* string;
};
