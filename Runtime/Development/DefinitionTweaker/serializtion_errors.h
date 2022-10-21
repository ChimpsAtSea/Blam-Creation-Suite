#pragma once

class c_serializtion_error
{
public:
	c_serializtion_error();
	c_serializtion_error(c_serializtion_error const&) = delete;
	virtual ~c_serializtion_error();
	virtual void render() = 0;
};

class c_generic_serializtion_error :
	public c_serializtion_error
{
public:
	const char* error;
	c_generic_serializtion_error(const char* _error_format, ...);
	virtual ~c_generic_serializtion_error();
	c_generic_serializtion_error(c_generic_serializtion_error const&) = delete;
	virtual void render();
};
