#pragma once

enum e_serialization_error_type
{
	_serialization_error_type_ok,
	_serialization_error_type_warning,
	_serialization_error_type_error,
	_serialization_error_type_data_validation_error,
	k_num_serialization_error_types
};

#ifdef IMGUI_VERSION
extern ImVec4 serialization_error_colors[k_num_serialization_error_types];
#endif

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
