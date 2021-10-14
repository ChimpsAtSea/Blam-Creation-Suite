#include "halo3tagfiletest-private-pch.h"

c_node* create_data_node(char* data, c_node* parent)
{
	char literal_string[5] = { data[3], data[2], data[1], data[0], 0 };
	unsigned long& literal = *reinterpret_cast<unsigned long*>(data);

	switch (literal)
	{
	case c_block_v2_node::type: return new c_block_v2_node(data, parent);
	case c_gras_node::type: return new c_gras_node(data, parent);
	case c_tab_block_node::type: return new c_tab_block_node(data, parent);
	case c_tag_string_id_node::type: return new c_tag_string_id_node(data, parent);
	case c_tag_reference_node::type: return new c_tag_reference_node(data, parent);
	case c_binary_data_node::type: return new c_binary_data_node(data, parent);
	case c_string_table_node::type: return new c_string_table_node(data, parent);
	case c_blay_node::type: return new c_blay_node(data, parent);
	case c_string1_node::type: return new c_string1_node(data, parent);
	case c_custom_search_block_names_node::type: return new c_custom_search_block_names_node(data, parent);
	case c_datum_node::type: return new c_datum_node(data, parent);
	case c_array_node::type: return new c_array_node(data, parent);
	case c_resources_v2_node::type: return new c_resources_v2_node(data, parent);
	case c_unknown_node::type: return new c_unknown_node(data, parent);
	case c_tag_field_types_node::type: return new c_tag_field_types_node(data, parent);
	case c_tag_header_node::type: return new c_tag_header_node(data, parent);
	case c_tag_tgly_node::type: return new c_tag_tgly_node(data, parent);
	case c_tag_string_list_node::type: return new c_tag_string_list_node(data, parent);
	case c_tag_structure_table_node::type: return new c_tag_structure_table_node(data, parent);
		//default: return new c_node(data, parent);
	}

	return nullptr;
}

c_tag_header_node::c_tag_header_node(char* node_header_data, c_node* parent) :
	c_typed_node(node_header_data, parent, true)
{
	debug_point;
}

c_tag_header_node::~c_tag_header_node()
{

}

c_tag_tgly_node::c_tag_tgly_node(char* node_header_data, c_node* parent) :
	c_typed_node(node_header_data, parent, true)
{
	debug_point;
}

c_tag_string_list_node::c_tag_string_list_node(char* node_header_data, c_node* parent) :
	c_typed_node(node_header_data, parent, true),
	entries(reinterpret_cast<s_string_list_entry*>(node_data_start)),
	entry_count(size / sizeof(*entries))
{
	debug_point;
}

void c_tag_string_list_node::log_impl()
{
	c_string_table_node* string_table = parent->find_first_node<c_string_table_node>();
	ASSERT(string_table != nullptr);

	printf("%.4s count:%u\n", short_name, entry_count);
	ASSERT(entry_count == 0);
	//for (unsigned long index = 0; index < entry_count; index++)
	//{
	//	s_tag_struct_table_entry& entry = entries[index];
	//	char* string = string_table->node_data_start + entry.string_offset;
	//	log_pad(); printf(
	//		"\t0x%X\t[0x%X, 0x%X, 0x%X, 0x%X]\tgras_index:0x%X %s\n", 
	//		index, 
	//		entry.persistent_identifier.identifier_part_0, 
	//		entry.persistent_identifier.identifier_part_1, 
	//		entry.persistent_identifier.identifier_part_2, 
	//		entry.persistent_identifier.identifier_part_3,
	//		entry.gras_index,
	//		string);
	//	debug_point;
	//}
}

c_tag_structure_table_node::c_tag_structure_table_node(char* node_header_data, c_node* parent) :
	c_typed_node(node_header_data, parent, false),
	entries(reinterpret_cast<s_tag_struct_table_entry*>(node_data_start)),
	entry_count(size / sizeof(*entries))
{
	debug_point;
}

void c_tag_structure_table_node::log_impl()
{
	c_string_table_node* string_table = parent->find_first_node<c_string_table_node>();
	ASSERT(string_table != nullptr);

	printf("%.4s count:%u\n", short_name, entry_count);
	for (unsigned long index = 0; index < entry_count; index++)
	{
		s_tag_struct_table_entry& entry = entries[index];
		char* string = string_table->node_data_start + entry.string_offset;
		log_pad(); printf(
			"\t0x%X\t[0x%X, 0x%X, 0x%X, 0x%X]\tgras_index:0x%X %s\n", 
			index, 
			entry.persistent_identifier.identifier_part_0, 
			entry.persistent_identifier.identifier_part_1, 
			entry.persistent_identifier.identifier_part_2, 
			entry.persistent_identifier.identifier_part_3,
			entry.gras_index,
			string);
		debug_point;
	}
}



//c_tag_field_types_node::c_tag_field_types_node(char* node_header_data, c_node* parent) :
//	c_typed_node(node_header_data, parent, false),
//	entries(reinterpret_cast<s_tag_field_type_entry*>(node_data_start)),
//	entry_count(size / sizeof(*entries))

c_node::c_node(char* node_header_data, c_node* parent, bool parse_children) :
	literal(*reinterpret_cast<unsigned long*>(node_header_data)),
	unknown(*reinterpret_cast<unsigned long*>(node_header_data + 4)),
	size(*reinterpret_cast<unsigned long*>(node_header_data + 8)),
	depth(parent ? parent->depth + 1 : 0),
	parent(parent),
	children(),
	node_header_data(node_header_data),
	node_data_start(node_header_data + 12),
	node_data_end(node_data_start + size),
	short_name{ node_header_data[3],node_header_data[2],node_header_data[1],node_header_data[0],0 }
{
	log();

	if (parse_children)
	{
		this->parse_children();
	}
}

c_node::~c_node()
{

}

void c_node::log_pad()
{
	for (unsigned long i = 0; i < depth; i++)
	{
		printf("  ");
	}
}

void c_node::log()
{
	log_pad();
	log_impl();

	for (c_node* child : children)
	{
		child->log();
	}
}

void c_node::parse_children()
{
	for (char* data_position = node_data_start; data_position < node_data_end;)
	{
		c_node* node = create_data_node(data_position, this);
		data_position = node->node_data_end;
		children.push_back(node);
	}
}

void c_node::log_impl()
{
	printf("%.4s\n", short_name);
}

c_node* c_node::find_first_node(unsigned long type)
{
	for (c_node* node : children)
	{
		if (node->literal == type)
		{
			return node;
		}
		c_node* child_search_result = node->find_first_node(type);
		if (child_search_result)
		{
			return child_search_result;
		}
	}
	return nullptr;
}

c_node* c_node::get_node(unsigned long index)
{
	return children[index];
}

c_binary_data_node::c_binary_data_node(char* node_header_data, c_node* parent) :
	c_typed_node(node_header_data, parent, true)
{
	debug_point;
}

c_tag_reference_node::c_tag_reference_node(char* node_header_data, c_node* parent) :
	c_typed_node(node_header_data, parent, false),
	filepath_buffer(nullptr),
	filepath(nullptr)
{
	group_tag = *reinterpret_cast<unsigned long*>(node_data_start);

	char* filepath_begin = node_data_start + 4;

	intptr_t filepath_length = node_data_end - filepath_begin;
	filepath_buffer = new char[filepath_length + 1];
	memcpy(filepath_buffer, node_data_start, static_cast<size_t>(filepath_length));
	filepath_buffer[filepath_length] = 0;
	filepath = filepath_buffer;
}

c_tag_reference_node::~c_tag_reference_node()
{
	delete filepath_buffer;
}

void c_tag_reference_node::log_impl()
{
	printf("%.4s '%s'\n", short_name, filepath);
}

c_tag_string_id_node::c_tag_string_id_node(char* node_header_data, c_node* parent) :
	c_typed_node(node_header_data, parent, false),
	filepath_buffer(nullptr),
	filepath(nullptr)
{
	intptr_t filepath_length = node_data_end - node_data_start;
	filepath_buffer = new char[filepath_length + 1];
	memcpy(filepath_buffer, node_data_start, static_cast<size_t>(filepath_length));
	filepath_buffer[filepath_length] = 0;
	filepath = filepath_buffer;
}

c_tag_string_id_node::~c_tag_string_id_node()
{
	delete filepath_buffer;
}

void c_tag_string_id_node::log_impl()
{
	printf("%.4s '%s'\n", short_name, filepath);
}

c_blay_node::c_blay_node(char* node_header_data, c_node* parent) :
	c_typed_node(node_header_data, parent, false)
{
	node_data_start += 0x4C;

	parse_children();
}

c_blay_node::~c_blay_node()
{

}

c_tab_block_node::c_tab_block_node(char* node_header_data, c_node* parent) :
	c_typed_node(node_header_data, parent, false)
{
	char* node_data_pos = node_data_start;
	unsigned long count = *reinterpret_cast<unsigned long*>(node_data_pos);
	node_data_pos += sizeof(unsigned long);
	unsigned long unknown = *reinterpret_cast<unsigned long*>(node_data_pos);
	node_data_pos += sizeof(unsigned long);

	s_tag_block block0 = *reinterpret_cast<s_tag_block*>(node_data_pos);
	node_data_pos += sizeof(s_tag_block);

	s_tag_data data0 = *reinterpret_cast<s_tag_data*>(node_data_pos);
	node_data_pos += sizeof(s_tag_data);

	struct s_array_stuff
	{
		unsigned long items[12];
	};
	s_array_stuff stuff = *reinterpret_cast<s_array_stuff*>(node_data_pos);
	node_data_pos += sizeof(s_array_stuff);

	node_data_start;// += 0x18;

	parse_children();
}

c_tab_block_node::~c_tab_block_node()
{

}

c_string_table_node::c_string_table_node(char* node_header_data, c_node* parent) :
	c_typed_node(node_header_data, parent, false)
{

}

c_string_table_node::~c_string_table_node()
{

}

void c_string_table_node::log_impl()
{
	printf("%.4s\n", short_name);

	unsigned long offset = 0;
	for (char* current_position = node_data_start; current_position < node_data_end; current_position++)
	{
		intptr_t offset = current_position - node_data_start;

		log_pad(); printf("\t0x%zX\t%s\n", offset, current_position);

		current_position += strlen(current_position);
	}
}

c_string1_node::c_string1_node(char* node_header_data, c_node* parent) :
	c_typed_node(node_header_data, parent, false),
	offsets(reinterpret_cast<unsigned long*>(node_data_start)),
	entry_count(size / sizeof(*offsets))
{

}

c_string1_node::~c_string1_node()
{

}

void c_string1_node::log_impl()
{
	c_string_table_node* string_table = parent->find_first_node<c_string_table_node>();
	ASSERT(string_table != nullptr);

	printf("%.4s count:%u\n", short_name, entry_count);
	for (unsigned long index = 0; index < entry_count; index++)
	{
		unsigned long offset = offsets[index];
		char* string = string_table->node_data_start + offset;
		log_pad(); printf("\t0x%X\t0x%X\t%s\n", index, offset, string);
	}
}

c_custom_search_block_names_node::c_custom_search_block_names_node(char* node_header_data, c_node* parent) :
	c_typed_node(node_header_data, parent, false),
	offsets(reinterpret_cast<unsigned long*>(node_data_start)),
	entry_count(size / sizeof(*offsets))
{

}

c_custom_search_block_names_node::~c_custom_search_block_names_node()
{

}

void c_custom_search_block_names_node::log_impl()
{
	c_string_table_node* string_table = parent->find_first_node<c_string_table_node>();
	ASSERT(string_table != nullptr);

	printf("%.4s count:%u\n", short_name, entry_count);
	for (unsigned long index = 0; index < entry_count; index++)
	{
		unsigned long offset = offsets[index];
		char* string = string_table->node_data_start + offset;
		log_pad(); printf("\t0x%X\t0x%X\t%s\n", index, offset, string);
	}
}

c_datum_node::c_datum_node(char* node_header_data, c_node* parent) :
	c_typed_node(node_header_data, parent, false),
	offsets(reinterpret_cast<unsigned long*>(node_data_start)),
	entry_count(size / sizeof(*offsets))
{

}

c_datum_node::~c_datum_node()
{

}

void c_datum_node::log_impl()
{
	c_string_table_node* string_table = parent->find_first_node<c_string_table_node>();
	ASSERT(string_table != nullptr);

	printf("%.4s count:%u\n", short_name, entry_count);
	for (unsigned long index = 0; index < entry_count; index++)
	{
		unsigned long offset = offsets[index];
		char* string = string_table->node_data_start + offset;
		log_pad(); printf("\t0x%X\t0x%X\t%s\n", index, offset, string);
	}
}

c_array_node::c_array_node(char* node_header_data, c_node* parent) :
	c_typed_node(node_header_data, parent, false),
	entries(reinterpret_cast<s_array_entry*>(node_data_start)),
	entry_count(size / sizeof(*entries))
{
	debug_point;
}

c_array_node::~c_array_node()
{

}

void c_array_node::log_impl()
{
	c_string_table_node* string_table = parent->find_first_node<c_string_table_node>();
	ASSERT(string_table != nullptr);

	printf("%.4s count:%u\n", short_name, entry_count);
	for (unsigned long index = 0; index < entry_count; index++)
	{
		s_array_entry entry = entries[index];
		char* string = string_table->node_data_start + entry.name_offset;
		log_pad(); printf("\t0x%X\tcount:%u num_fields:%u %s\n", index, entry.count, entry.num_fields, string);
	}
}

c_resources_v2_node::c_resources_v2_node(char* node_header_data, c_node* parent) :
	c_typed_node(node_header_data, parent, false),
	entries(reinterpret_cast<s_resources_v2_entry*>(node_data_start)),
	entry_count(size / sizeof(*entries))
{

}

c_resources_v2_node::~c_resources_v2_node()
{

}

void c_resources_v2_node::log_impl()
{
	c_string_table_node* string_table = parent->find_first_node<c_string_table_node>();
	ASSERT(string_table != nullptr);

	printf("%.4s count:%u\n", short_name, entry_count);
	for (unsigned long index = 0; index < entry_count; index++)
	{
		s_resources_v2_entry entry = entries[index];
		char* string = string_table->node_data_start + entry.name_offset;
		log_pad(); printf("\t0x%X\tunknown:%u unknown1:%u %s\n", index, entry.unknown, entry.unknown1, string);
	}
}

c_unknown_node::c_unknown_node(char* node_header_data, c_node* parent) :
	c_typed_node(node_header_data, parent, false),
	entries(reinterpret_cast<s_unknown_entry*>(node_data_start)),
	entry_count(size / sizeof(*entries))
{

}

c_unknown_node::~c_unknown_node()
{

}

void c_unknown_node::log_impl()
{
	c_string_table_node* string_table = parent->find_first_node<c_string_table_node>();
	ASSERT(string_table != nullptr);

	printf("%.4s count:%u\n", short_name, entry_count);
	for (unsigned long index = 0; index < entry_count; index++)
	{
		s_unknown_entry entry = entries[index];
		char* string = string_table->node_data_start + entry.name_offset;
		log_pad(); printf("\t0x%X\tunknown:0x%X unknown1:0x%X unknown2:0x%X unknown3:0x%X unknown4:0x%X %s\n", index, entry.unknown, entry.unknown1, entry.unknown2, entry.unknown3, entry.unknown4, string);
	}

}

c_tag_field_types_node::c_tag_field_types_node(char* node_header_data, c_node* parent) :
	c_typed_node(node_header_data, parent, false),
	entries(reinterpret_cast<s_tag_field_type_entry*>(node_data_start)),
	entry_count(size / sizeof(*entries))
{

}

c_tag_field_types_node::~c_tag_field_types_node()
{

}

void c_tag_field_types_node::log_impl()
{
	c_string_table_node* string_table = parent->find_first_node<c_string_table_node>();
	ASSERT(string_table != nullptr);

	printf("%.4s count:%u\n", short_name, entry_count);
	for (unsigned long index = 0; index < entry_count; index++)
	{
		s_tag_field_type_entry entry = entries[index];
		char* _typename = string_table->node_data_start + entry.typename_offset;

		log_pad(); printf("\t0x%X\tsize:%u unknown1:%u %s\n", index, entry.size, entry.unknown1, _typename);
	}
}

c_gras_node::c_gras_node(char* node_header_data, c_node* parent) :
	c_typed_node(node_header_data, parent, false),
	entries(reinterpret_cast<s_gras_entry*>(node_data_start)),
	entry_count(size / sizeof(*entries))
{
	debug_point;
}

c_gras_node::~c_gras_node()
{

}

void c_gras_node::log_impl()
{
	c_string_table_node* string_table = parent->find_first_node<c_string_table_node>();
	ASSERT(string_table != nullptr);

	printf("%.4s count:%u\n", short_name, entry_count);
	for (unsigned long index = 0; index < entry_count; index++)
	{
		s_gras_entry entry = entries[index];
		char* name = string_table->node_data_start + entry.name_offset;

		ASSERT(entry.unknown1 == 0);

		log_pad(); printf("\t0x%X\ttag_field_type_index:%u\tunknown1:%u\t'%s'\n", index, entry.tag_field_type_index, entry.unknown1, name);
	}
}


c_block_v2_node::c_block_v2_node(char* node_header_data, c_node* parent) :
	c_typed_node(node_header_data, parent, false),
	entries(reinterpret_cast<s_block_v2_entry*>(node_data_start)),
	entry_count(size / sizeof(*entries))
{

}

c_block_v2_node::~c_block_v2_node()
{

}

void c_block_v2_node::log_impl()
{
	c_string_table_node* string_table = parent->find_first_node<c_string_table_node>();
	ASSERT(string_table != nullptr);

	printf("%.4s count:%u\n", short_name, entry_count);
	for (unsigned long index = 0; index < entry_count; index++)
	{
		s_block_v2_entry entry = entries[index];
		char* name = string_table->node_data_start + entry.name_offset;

		log_pad(); printf("\t0x%X\tmax_count:%u unknown1:%u %s\n", index, entry.max_count, entry.unknown1, name);
	}
}
