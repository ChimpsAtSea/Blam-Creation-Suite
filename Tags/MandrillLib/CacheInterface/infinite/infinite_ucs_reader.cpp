#include "mandrilllib-private-pch.h"

c_infinite_ucs_reader::c_infinite_ucs_reader(const void* ucs_data) :
	header_data(ucs_data),
	tag_data(),
	ucs_header(),
	tag_dependency_list(),
	nuggets(),
	tag_block_instances(),
	tag_data_instances(),
	tag_reference(),
	string_table(),
	zoneset_data(),
	extra_data(),
	extra_data_size(),
	root_tag_block_entry_index(),
	tag_group_tag_block_entry(),
	root_nugget(),
	root_tag_block_data()
{
	ucs_header = static_cast<const s_infinite_ucs_header*>(header_data);

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
	
	tag_data = reinterpret_cast<const char*>(ucs_header) + ucs_header->header_size;
	
	if (ucs_header->tag_dependency_count == 0) tag_dependency_list = nullptr;
	if (ucs_header->nugget_count == 0) nuggets = nullptr;
	if (ucs_header->tag_block_count == 0) tag_block_instances = nullptr;
	if (ucs_header->data_reference_count == 0) tag_data_instances = nullptr;
	if (ucs_header->tag_reference_count == 0) tag_reference = nullptr;
	if (ucs_header->string_table_size == 0) string_table = nullptr;
	if (ucs_header->zoneset_data_size == 0) zoneset_data = nullptr;

	debug_point;

	root_tag_block_entry_index = get_root_tag_block_entry_index();
	ASSERT(root_tag_block_entry_index >= 0);
	tag_group_tag_block_entry = &tag_block_instances[root_tag_block_entry_index];
	ASSERT(tag_group_tag_block_entry != nullptr);
	ASSERT(tag_group_tag_block_entry->nugget_index >= 0);

	root_nugget = &nuggets[tag_group_tag_block_entry->nugget_index];

	const char* root_tag_data = static_cast<const char*>(tag_data);
	root_tag_block_data = root_tag_data + root_nugget->offset;
}

c_infinite_ucs_reader::~c_infinite_ucs_reader()
{

}

long c_infinite_ucs_reader::get_root_tag_block_entry_index() const
{
	for (long struct_index = 0; struct_index < ucs_header->tag_block_count; struct_index++)
	{
		const s_infinite_ucs_tag_block_data& struct_entry = tag_block_instances[struct_index];

		if (struct_entry.type == _infinite_ucs_tag_block_type_tag_group)
		{
			return struct_index;
		}

	}
	return -1;
}
