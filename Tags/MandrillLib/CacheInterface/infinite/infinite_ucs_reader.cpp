#include "mandrilllib-private-pch.h"

c_infinite_ucs_reader::c_infinite_ucs_reader(const void** instance_block_data) :
	instance_block_data(),
	header_data(instance_block_data[0]),
	tag_data(instance_block_data[1]),
	resource_data(),
	ucs_header(),
	tag_dependency_list(),
	nuggets(),
	tag_block_instances(),
	tag_data_instances(),
	tag_reference(),
	string_table(),
	zoneset_data(),
	extra_data(),
	extra_data_size()
{
	ucs_header = static_cast<const s_infinite_ucs_header*>(header_data);

	for (unsigned long index = 0; ; index++)
	{
		const void* value = instance_block_data[index + 2];
		if (!value) break;
		resource_data[index] = value;
	}

	tag_dependency_list = reinterpret_cast<const s_infinite_ucs_tag_dependency_list*>(ucs_header + 1);
	nuggets = reinterpret_cast<const s_infinite_ucs_nugget*>(tag_dependency_list + ucs_header->tag_dependency_count);
	tag_block_instances = reinterpret_cast<const s_infinite_ucs_tag_block_data*>(nuggets + ucs_header->nugget_count);
	tag_data_instances = reinterpret_cast<const s_infinite_ucs_data_reference_list*>(tag_block_instances + ucs_header->tag_block_count);
	tag_reference = reinterpret_cast<const s_infinite_ucs_tag_reference_list*>(tag_data_instances + ucs_header->data_reference_count);
	string_table = reinterpret_cast<const char*>(tag_reference + ucs_header->tag_reference_count);
	//const s_infinite_ucs_string_id_list* string_id_list = reinterpret_cast<const s_infinite_ucs_string_id_list*>(tag_reference + ucs_header->tag_reference_count);
	//const char* string_table = reinterpret_cast<const char*>(string_id_list + ucs_header->string_id_count);
	zoneset_data = reinterpret_cast<const char*>(string_table + ucs_header->string_table_size);
	extra_data = reinterpret_cast<const void*>(zoneset_data + ucs_header->zoneset_data_size);
	extra_data_size = static_cast<unsigned long>(reinterpret_cast<intptr_t>(tag_data) - reinterpret_cast<intptr_t>(extra_data));

	debug_point;
}

c_infinite_ucs_reader::~c_infinite_ucs_reader()
{

}
