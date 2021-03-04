#include "mandrilllib-private-pch.h"

byteswap_func(gen3::s_cache_file_section_file_bounds)
{
	byteswap(value.offset);
	byteswap(value.size);
}

byteswap_func(gen3::s_network_http_request_hash)
{

}

byteswap_func(gen3::s_rsa_signature)
{

}

byteswap_func(gen3::s_file_last_modification_date)
{
	byteswap(value.unknown0);
	byteswap(value.unknown4);
}

byteswap_func(gen3::s_cache_file_insertion_point_resource_usage)
{
	// #TODO
}
