#include "texturelib-private-pch.h"

c_texture::~c_texture()
{

}

BCS_DEBUG_API BCS_RESULT texture_load_from_file(const wchar_t* file_path, c_texture*& texture)
{
	try
	{
		texture = new c_directxtex_texture(file_path);
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FATAL;
	}
	return BCS_S_OK;
}

BCS_DEBUG_API BCS_RESULT texture_destroy(c_texture* texture)
{
	try
	{
		delete texture;
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FATAL;
	}
	return BCS_S_OK;
}
