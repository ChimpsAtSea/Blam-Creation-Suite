#include "highlevelcachefileserialization-private-pch.h"

c_cache_file_reader::c_cache_file_reader()
{

}

c_cache_file_reader::~c_cache_file_reader()
{

}

BCS_RESULT c_cache_file_reader::get_build_info(s_cache_file_build_info& build_info) const
{
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_cache_file_reader::get_debug_info(s_cache_file_debug_info& debug_info) const
{
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_cache_file_reader::get_buffer(e_cache_file_buffer_index buffer_index, s_cache_file_buffer_info& buffer_info) const
{
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_cache_file_reader::get_buffers(s_cache_file_buffers_info& buffers_info) const
{
	return BCS_E_UNSUPPORTED;
}
