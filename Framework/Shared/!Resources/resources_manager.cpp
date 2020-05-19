#include "shared-private-pch.h"
#include "resource.h"

LPSTR c_resources_manager::get_resource_int_resource(e_resource_type type)
{
	switch (type)
	{
	case _resource_type_icon:					return MAKEINTRESOURCE(IDI_ICON1);
	case _resource_type_imgui_font:			return MAKEINTRESOURCE(IDR_FONT1);
	case _resource_type_symbols_blob:			return MAKEINTRESOURCE(IDR_MAPDATABASE);
	case _resource_type_box_pixel_shader:		return MAKEINTRESOURCE(IDR_BOXSHADERPS);
	case _resource_type_box_vertex_shader:		return MAKEINTRESOURCE(IDR_BOXSHADERVS);
	}
	return NULL;
}

HRSRC c_resources_manager::get_resource_handle(e_resource_type type)
{
	static HMODULE hInstance = c_runtime_util::get_current_module();

	LPSTR intResource = get_resource_int_resource(type);
	if (intResource == nullptr) return NULL;

	switch (type)
	{
	case _resource_type_icon:
		return FindResource(hInstance, intResource, RT_ICON);
	case _resource_type_imgui_font:
	case _resource_type_symbols_blob:
	case _resource_type_box_pixel_shader:
	case _resource_type_box_vertex_shader:
		return FindResource(hInstance, intResource, RT_RCDATA);
	}
	return NULL;
}

bool c_resources_manager::get_resource(e_resource_type type, char** out_data, size_t* out_data_size, bool null_terminate)
{
	*out_data = nullptr;
	*out_data_size = 0;

	static HMODULE hInstance = c_runtime_util::get_current_module();

	HRSRC hResource = get_resource_handle(type);
	if (hResource == NULL) return false;
	HGLOBAL hMemory = LoadResource(hInstance, hResource);
	if (hMemory == NULL) return false;
	DWORD dwSize = SizeofResource(hInstance, hResource);
	if (dwSize == 0) return false;
	LPVOID lpAddress = LockResource(hMemory);
	if (lpAddress == nullptr) return false;

	char* bytes = new char[dwSize + (null_terminate ? 1 : 0)] {};
	ASSERT(bytes != nullptr);
	for (DWORD i = 0; i < dwSize; i++)
	{
		bytes[i] = reinterpret_cast<char*>(lpAddress)[i];
	}
	memcpy(bytes, lpAddress, dwSize);
	if (null_terminate)
	{
		bytes[dwSize] = 0;
	}

	UnlockResource(lpAddress);
	BOOL freeResourceResult = FreeResource(hMemory);
	ASSERT(freeResourceResult == 0);

	*out_data = bytes;
	*out_data_size = dwSize + (null_terminate ? 1 : 0);

	return true;
}
