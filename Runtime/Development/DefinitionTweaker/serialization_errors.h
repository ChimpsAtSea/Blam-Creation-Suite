#pragma once

enum e_serialization_error_type
{
	_tag_serialization_state_good,
	_tag_serialization_state_warning,
	_tag_serialization_state_error,
};

class c_serialization_error
{
public:
	c_serialization_error(e_serialization_error_type error_type);
	c_serialization_error(c_serialization_error const&) = delete;
	virtual ~c_serialization_error();
	virtual void render() = 0;

	e_serialization_error_type error_type;
};

class c_generic_serialization_error :
	public c_serialization_error
{
public:
	const char* error;
	c_generic_serialization_error(e_serialization_error_type error_type, const char* _error_format, ...);
	virtual ~c_generic_serialization_error();
	c_generic_serialization_error(c_generic_serialization_error const&) = delete;
	virtual void render();
};
