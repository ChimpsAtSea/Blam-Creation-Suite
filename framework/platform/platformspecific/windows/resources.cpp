#include "platform-private-pch.h"
#include <platform\!resources\resource.h>

#pragma optimize("", off)

#define RESOURCE_ENTRY(resource_type, filename, int_resource) { #resource_type, filename, int_resource }
struct s_resource_entry { const char* name; const char* filename; LPWSTR resource_int; };
static s_resource_entry resource_entries[] =
{
	RESOURCE_ENTRY(_bcs_resource_type_icon_application, 						nullptr,								MAKEINTRESOURCEW(IDI_ICON_APPLICATION)),
	RESOURCE_ENTRY(_bcs_resource_type_icon_blam_creation_suite, 				nullptr,								MAKEINTRESOURCEW(IDI_ICON_BLAM_CREATION_SUITE)),
	RESOURCE_ENTRY(_bcs_resource_type_icon_mandrill, 							nullptr,								MAKEINTRESOURCEW(IDI_ICON_MANDRILL)),
	RESOURCE_ENTRY(_bcs_resource_type_font_cousine_regular, 					nullptr,								MAKEINTRESOURCEW(IDR_FONT_COUSINE_REGULAR)),
	RESOURCE_ENTRY(_bcs_resource_type_font_font_awesome_regular, 				nullptr,								MAKEINTRESOURCEW(IDR_FONT_FONT_AWESOME_REGULAR)),
	RESOURCE_ENTRY(_bcs_resource_type_font_font_awesome_solid, 					nullptr,								MAKEINTRESOURCEW(IDR_FONT_FONT_AWESOME_SOLID)),
	RESOURCE_ENTRY(_bcs_resource_type_font_font_awesome_brands, 				nullptr,								MAKEINTRESOURCEW(IDR_FONT_FONT_AWESOME_BRANDS)),
	RESOURCE_ENTRY(_bcs_resource_type_box_pixel_shader, 						"BoxShaderPS.cso",						MAKEINTRESOURCEW(IDR_BOXSHADERPS)),
	RESOURCE_ENTRY(_bcs_resource_type_box_vertex_shader, 						"BoxShaderVS.cso",						MAKEINTRESOURCEW(IDR_BOXSHADERVS)),
	RESOURCE_ENTRY(_bcs_resource_type_viewport_p_vertex_shader, 				"vertex_layout_p.cso",					MAKEINTRESOURCEW(IDR_VIEWPORT_P_SHADER_VS)),
	RESOURCE_ENTRY(_bcs_resource_type_viewport_pc_vertex_shader, 				"vertex_layout_pc.cso",					MAKEINTRESOURCEW(IDR_VIEWPORT_PC_SHADER_VS)),
	RESOURCE_ENTRY(_bcs_resource_type_viewport_ptcn_vertex_shader, 				"vertex_layout_ptcn.cso",				MAKEINTRESOURCEW(IDR_VIEWPORT_PTCN_SHADER_VSVS)),
	RESOURCE_ENTRY(_bcs_resource_type_viewport_debug_pixel_shader, 				"debug_shader.cso",						MAKEINTRESOURCEW(IDR_VIEWPORT_DEBUG_SHADER_PS)),
	RESOURCE_ENTRY(_bcs_resource_type_viewport_default_pixel_shader, 			"default_shader.cso",					MAKEINTRESOURCEW(IDR_VIEWPORT_DEFAULT_SHADER_PS)),
	RESOURCE_ENTRY(_bcs_resource_type_generic_infinite_vertex_shader, 			"generic_infinite_vertex_shader.cso",	MAKEINTRESOURCEW(IDR_GENERIC_INFINITE_VERTEX_SHADER)),
	RESOURCE_ENTRY(_bcs_resource_type_generic_infinite_pixel_shader, 			"generic_infinite_pixel_shader.cso",	MAKEINTRESOURCEW(IDR_GENERIC_INFINITE_PIXEL_SHADER)),
	RESOURCE_ENTRY(_bcs_resource_type_generic_lightmap_debug_vertex_shader,		"lightmap_debug_vs.cso",				MAKEINTRESOURCEW(IDR_GENERIC_LIGHTMAP_DEBUG_VERTEX_SHADER)),
	RESOURCE_ENTRY(_bcs_resource_type_generic_lightmap_debug_pixel_shader, 		"lightmap_debug_ps.cso",				MAKEINTRESOURCEW(IDR_GENERIC_LIGHTMAP_DEBUG_PIXEL_SHADER)),
	RESOURCE_ENTRY(_bcs_resource_type_generic_lightmap_compute_test_shader, 	"lightmap_compute_test_cs.cso",			MAKEINTRESOURCEW(IDR_GENERIC_LIGHTMAP_COMPUTE_TEST_SHADER)),
	RESOURCE_ENTRY(_bcs_resource_type_symbols_blob, 							nullptr,								MAKEINTRESOURCEW(IDR_MAPDATABASE)),
};
static_assert(_countof(resource_entries) == k_number_of_bcs_resource_types);
#undef RESOURCE_ENTRY

BCS_RESULT resources_get_resource_type(e_bcs_resource_type type, LPCWSTR& resource_type)
{
	switch (type)
	{
	case _bcs_resource_type_icon_application:
	case _bcs_resource_type_icon_blam_creation_suite:
	case _bcs_resource_type_icon_mandrill:
		resource_type = reinterpret_cast<LPCWSTR>(RT_ICON);
		break;
	default:
		resource_type = reinterpret_cast<LPCWSTR>(RT_RCDATA);
		break;
	}

	return BCS_S_OK;
}

BCS_RESULT resources_get_resource_int(e_bcs_resource_type type, LPCWSTR& resource_int)
{
	BCS_VALIDATE_ARGUMENT(type >= 0);
	BCS_VALIDATE_ARGUMENT(type < k_number_of_bcs_resource_types);

	resource_int = resource_entries[type].resource_int;

	return BCS_S_OK;
}

BCS_RESULT resources_get_resource_handle(e_bcs_resource_type type, HRSRC& resource_handle)
{
	BCS_RESULT rs = BCS_S_OK;

	LPCWSTR resource_int;
	if (BCS_FAILED(rs = resources_get_resource_int(type, resource_int)))
	{
		return rs;
	}

	void* process_module;
	if (BCS_FAILED(rs = get_process_module(process_module)))
	{
		return rs;
	}

	LPCWSTR resource_type;
	if (BCS_FAILED(rs = resources_get_resource_type(type, resource_type)))
	{
		return rs;
	}

	resource_handle = FindResourceW(static_cast<HMODULE>(process_module), resource_int, resource_type);
	if (resource_handle == NULL)
	{
		return BCS_E_NOT_FOUND;
	}

	return rs;
}

BCS_RESULT resources_get_resource_icon_handle(e_bcs_resource_type type, HICON& resource_icon_handle)
{
	BCS_RESULT rs = BCS_S_OK;

	LPCWSTR resource_type;
	if (BCS_FAILED(rs = resources_get_resource_type(type, resource_type)))
	{
		return rs;
	}

	if (resource_type != reinterpret_cast<LPCWSTR>(RT_ICON))
	{
		return BCS_E_FAIL;
	}

	void* process_module;
	if (BCS_FAILED(rs = get_process_module(process_module)))
	{
		return rs;
	}

	LPCWSTR resource_int;
	if (BCS_FAILED(rs = resources_get_resource_int(type, resource_int)))
	{
		return rs;
	}

	resource_icon_handle = LoadIconW(static_cast<HINSTANCE>(process_module), resource_int);

	return rs;
}

BCS_RESULT resources_get_resource_filename(e_bcs_resource_type type, const char*& resource_filename)
{
	BCS_VALIDATE_ARGUMENT(type >= 0);
	BCS_VALIDATE_ARGUMENT(type < k_number_of_bcs_resource_types);

	resource_filename = resource_entries[type].filename;

	if (resource_filename == nullptr)
	{
		return BCS_E_NOT_FOUND;
	}

	return BCS_S_OK;
}

BCS_RESULT resources_get_local_resource_size(const char* filename, uint64_t& resource_size)
{
	BCS_RESULT rs = BCS_S_OK;

	void* process_module;
	if (BCS_SUCCEEDED(rs = get_process_module(process_module)))
	{
		char resource_local_filepath[MAX_PATH];
		GetModuleFileNameA(static_cast<HMODULE>(process_module), resource_local_filepath, _countof(resource_local_filepath));
		PathRemoveFileSpecA(resource_local_filepath);
		strcat(resource_local_filepath, "\\");
		strcat(resource_local_filepath, filename);

		if (BCS_FAILED(rs = filesystem_filepath_exists(resource_local_filepath)))
		{
			return rs;
		}
		else
		{
			uint64_t local_resource_file_size;
			if (BCS_FAILED(rs = filesystem_get_file_size(resource_local_filepath, local_resource_file_size)))
			{
				return rs;
			}

			if (local_resource_file_size >= ULONG_MAX)
			{
				return BCS_E_FAIL;
			}

			resource_size = local_resource_file_size;

			return rs;
		}

		return rs;
	}
	return rs;
}

BCS_RESULT resources_copy_local_resource_to_buffer(const char* filename, void* buffer, uint64_t& buffer_size)
{
	BCS_RESULT rs = BCS_S_OK;

	void* process_module;
	if (BCS_SUCCEEDED(rs = get_process_module(process_module)))
	{
		char resource_local_filepath[MAX_PATH];
		GetModuleFileNameA(static_cast<HMODULE>(process_module), resource_local_filepath, _countof(resource_local_filepath));
		PathRemoveFileSpecA(resource_local_filepath);
		strcat(resource_local_filepath, "\\");
		strcat(resource_local_filepath, filename);

		if (BCS_FAILED(rs = filesystem_filepath_exists(resource_local_filepath)))
		{
			return rs;
		}
		else
		{
			uint64_t local_resource_size;
			if (BCS_FAILED(rs = filesystem_get_file_size(resource_local_filepath, local_resource_size)))
			{
				return rs;
			}

			uint64_t read_data_size = __min(local_resource_size, buffer_size);
			if (read_data_size >= ULONG_MAX)
			{
				return BCS_E_FAIL;
			}

			if (BCS_FAILED(rs = filesystem_copy_file_to_buffer(resource_local_filepath, buffer, read_data_size)))
			{
				return rs;
			}

			return rs;
		}
		return rs;
	}

	return rs;
}

BCS_RESULT resources_get_resource_size(e_bcs_resource_type type, uint64_t& resource_size)
{
	BCS_RESULT rs = BCS_S_OK;
	const char* filename;
	if (BCS_SUCCEEDED(rs = resources_get_resource_filename(type, filename)))
	{
		if (BCS_SUCCEEDED(rs = resources_get_local_resource_size(filename, resource_size)))
		{
			return rs;
		}
	}

	HRSRC resource_handle;
	if (BCS_FAILED(rs = resources_get_resource_handle(type, resource_handle)))
	{
		return rs;
	}

	void* process_module;
	if (BCS_FAILED(rs = get_process_module(process_module)))
	{
		return rs;
	}

	HGLOBAL resource = LoadResource(static_cast<HMODULE>(process_module), resource_handle);

	resource_size = SizeofResource(static_cast<HMODULE>(process_module), resource_handle);

	BOOL free_resource_result = FreeResource(resource);
	ASSERT(free_resource_result == FALSE);

	return rs;
}

BCS_RESULT resources_copy_resource_to_buffer(e_bcs_resource_type type, void* buffer, uint64_t& buffer_size)
{
	BCS_RESULT rs = BCS_S_OK;
	const char* filename;
	if (BCS_SUCCEEDED(rs = resources_get_resource_filename(type, filename)))
	{
		if (BCS_SUCCEEDED(rs = resources_copy_local_resource_to_buffer(filename, buffer, buffer_size)))
		{
			return rs;
		}
	}

	HRSRC resource_handle;
	if (BCS_FAILED(rs = resources_get_resource_handle(type, resource_handle)))
	{
		return rs;
	}

	void* process_module;
	if (BCS_FAILED(rs = get_process_module(process_module)))
	{
		return rs;
	}

	HGLOBAL resource = LoadResource(static_cast<HMODULE>(process_module), resource_handle);

	uint32_t process_resource_size = SizeofResource(static_cast<HMODULE>(process_module), resource_handle);
	if (LPVOID process_resource_data = LockResource(resource))
	{
		uint64_t read_data_size = __min(process_resource_size, buffer_size);

		memcpy(buffer, process_resource_data, read_data_size);
		buffer_size = read_data_size;

		UnlockResource(process_resource_data);
	}
	else
	{
		rs = BCS_E_FAIL;
	}

	BOOL free_resource_result = FreeResource(resource);
	ASSERT(free_resource_result == FALSE);

	return rs;
}

BCS_RESULT resources_read_resource_to_memory(e_bcs_resource_type type, void*& out_buffer, uint64_t& out_buffer_size)
{
	BCS_RESULT rs = BCS_S_OK;

	uint64_t buffer_size;
	if (BCS_FAILED(rs = resources_get_resource_size(type, buffer_size)))
	{
		return rs;
	}

	void* buffer = tracked_malloc(buffer_size);
	if (BCS_FAILED(rs = resources_copy_resource_to_buffer(type, buffer, buffer_size)))
	{
		tracked_free(buffer);
		return rs;
	}

	out_buffer = buffer;
	out_buffer_size = buffer_size;

	return rs;
}

BCS_RESULT resources_read_local_resource_to_memory(const char* filename, void*& out_buffer, uint64_t& out_buffer_size)
{
	BCS_RESULT rs = BCS_S_OK;

	uint64_t buffer_size;
	if (BCS_FAILED(rs = resources_get_local_resource_size(filename, buffer_size)))
	{
		return rs;
	}

	void* buffer = tracked_malloc(buffer_size);
	if (BCS_FAILED(rs = resources_copy_local_resource_to_buffer(filename, buffer, buffer_size)))
	{
		tracked_free(buffer);
		return rs;
	}

	out_buffer = buffer;
	out_buffer_size = buffer_size;

	return rs;
}

BCS_RESULT resources_set_resource_data(e_bcs_resource_type type, const void* buffer, uint64_t buffer_size)
{
	FATAL_ERROR("NOT IMPLEMENTED");
	return BCS_E_NOT_IMPLEMENTED;
}

BCS_RESULT resources_set_external_resource_data(e_bcs_resource_type type, const char* filepath, const void* buffer, uint64_t buffer_size)
{
	BCS_VALIDATE_ARGUMENT(filepath);
	BCS_VALIDATE_ARGUMENT(buffer);
	BCS_VALIDATE_ARGUMENT(buffer_size);
	BCS_FAIL_RETURN(filesystem_filepath_exists(filepath));

	BCS_RESULT rs = BCS_S_OK;

	HANDLE update_resource_handle = BeginUpdateResourceA(filepath, FALSE);
	if (update_resource_handle == NULL)
	{
		return BCS_E_FAIL;
	}

	LPCWSTR resource_int;
	if (BCS_FAILED(rs = resources_get_resource_int(type, resource_int)))
	{
		return rs;
	}

	LPCWSTR resource_type;
	if (BCS_FAILED(rs = resources_get_resource_type(type, resource_type)))
	{
		return rs;
	}

	BOOL update_resource_result = UpdateResourceW(
		update_resource_handle,
		resource_type,
		resource_int,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL),
		const_cast<void*>(buffer),
		static_cast<DWORD>(buffer_size));
	if (update_resource_result != TRUE)
	{
		rs = BCS_E_FAIL;
	}

	BOOL end_update_resource_result = EndUpdateResource(update_resource_handle, FALSE);
	if (end_update_resource_result != TRUE)
	{
		DWORD error = GetLastError();
		rs = BCS_E_FAIL;
	}

	return rs;
}

BCS_RESULT resources_set_external_resource_data(e_bcs_resource_type type, const char* target_filepath, const char* resource_filepath)
{
	BCS_RESULT rs = BCS_S_OK;

	void* buffer_data;
	uint64_t buffer_data_size;
	if (BCS_FAILED(rs = filesystem_read_file_to_memory(resource_filepath, buffer_data, buffer_data_size)))
	{
		return rs;
	}

	if (buffer_data_size < ULONG_MAX)
	{
		if (BCS_FAILED(rs = resources_set_external_resource_data(type, target_filepath, buffer_data, buffer_data_size)))
		{
			return rs;
		}
	}
	else
	{
		rs = BCS_E_FAIL;
	}

	tracked_free(buffer_data);

	return rs;
}
