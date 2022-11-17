#pragma once

class h_string_id :
	public t_virtual
{
public:
	h_string_id();
	h_string_id(const char* string);
	h_string_id(h_string_id const& string_id);
	virtual ~h_string_id();

	const char* get_string() const;
	void set_string(const char* string);
	void set_string(const char* string_start, const char* string_end);
	void clear();

	h_string_id& operator=(h_string_id const& value);
	h_string_id& operator=(const char* const& value);
	bool operator==(h_string_id const& value) const;
	bool operator==(const char* const& value) const;

protected:
	const char* string;
};
