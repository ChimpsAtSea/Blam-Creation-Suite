#pragma once

class h_string_id :
	public t_virtual
{
public:
	h_string_id();
	h_string_id(const char* string);
	virtual ~h_string_id();

	const char* get_string() const;
	void set_string(const char* string);
	void set_string(const char* string_start, const char* string_end);
	void clear();

protected:
	const char* string;
};
