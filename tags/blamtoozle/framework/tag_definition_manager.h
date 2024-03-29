#pragma once

class c_blamtoozle_tag_group_definition;
class c_blamtoozle_tag_struct_definition;
class c_blamtoozle_tag_block_definition;
class c_blamtoozle_tag_reference_definition;
class c_blamtoozle_tag_array_definition;
class c_blamtoozle_string_list_definition;
class c_blamtoozle_tag_resource_definition;
class c_blamtoozle_tag_data_definition;
class c_blamtoozle_tag_api_interop_definition;
class c_blamtoozle_tag_block_index_custom_search_definition;

class c_blamtoozle_tag_definition_manager :
	public c_blamtoozle_tag_definition_reader
{
public:
	c_blamtoozle_tag_definition_manager(const c_blamtoozle_tag_definition_manager&) = delete;
	c_blamtoozle_tag_definition_manager(c_blamtoozle_tag_definition_manager&&) = delete;
	BCS_SHARED c_blamtoozle_tag_definition_manager();
	BCS_SHARED virtual ~c_blamtoozle_tag_definition_manager();

	BCS_SHARED virtual void set_is_big_endian(bool is_big_endian);
	BCS_SHARED virtual void format_structure_type_name(std::string& code_symbol_name);
	BCS_SHARED virtual void format_code_symbol_name(std::string& code_symbol_name);
	BCS_SHARED virtual void format_code_symbol_name_uid(std::string& code_symbol_name);
	BCS_SHARED virtual c_blamtoozle_tag_group_definition* get_tag_group_definition_by_group_tag(tag group_tag);
	BCS_SHARED virtual c_blamtoozle_tag_struct_definition* get_tag_struct_definition_by_persistent_id(blofeld::s_tag_persistent_identifier persistent_identifier);
	BCS_SHARED virtual void traverse(ptr64 group_table_address, uint32_t num_tag_layouts) = 0;

	template<typename t_element>
	void byteswap_inplace(t_element& value)
	{
		if (is_big_endian)
		{
			::byteswap_inplace(value);
		}
	}

	template<typename t_element>
	t_element byteswap(t_element value)
	{
		if (is_big_endian)
		{
			::byteswap_inplace(value);
		}
		return value;
	}

	template<typename t_type>
	t_type read_structure(ptr64 address)
	{
		const t_type* read_pointer = va_to_pointer2<t_type>(address);
		ASSERT(read_pointer != nullptr);
		t_type value = *read_pointer;
		if (is_big_endian)
		{
			::byteswap_inplace(value);
		}
		return value;
	}

	template<typename t_definition_manager_type, typename t_definition_type, typename t_storage_definition_type, typename t_storage_lookup_definition_type>
	t_definition_type& eval_definition(
		ptr64 definition_address, 
		std::vector<t_storage_definition_type*>& tag_type_definitions,
		std::map<ptr64, t_storage_lookup_definition_type*>& tag_type_definitions_lookup)
	{
		ASSERT(definition_address != 0);

		auto tag_type_definition_iterator = tag_type_definitions_lookup.find(definition_address);

		if (tag_type_definition_iterator != tag_type_definitions_lookup.end())
		{
			t_definition_type* existing_definition = dynamic_cast<t_definition_type*>(tag_type_definition_iterator->second);
			ASSERT(existing_definition != nullptr);
			return *existing_definition;
		}

		t_definition_type* tag_type_definition = reinterpret_cast<t_definition_type*>(tracked_malloc(sizeof(t_definition_type)));

		tag_type_definitions_lookup[definition_address] = tag_type_definition;
		tag_type_definitions.push_back(tag_type_definition);

		tag_type_definition = new(tag_type_definition) t_definition_type(*static_cast<t_definition_manager_type*>(this), definition_address);

		return *tag_type_definition;
	}

	bool is_big_endian;
	std::unordered_map<std::string, unsigned int> code_symbol_counts;

	std::vector<c_blamtoozle_tag_group_definition*> tag_group_definitions;
	std::vector<c_blamtoozle_tag_struct_definition*> tag_struct_definitions;
	std::vector<c_blamtoozle_tag_block_definition*> tag_block_definitions;
	std::vector<c_blamtoozle_tag_reference_definition*> tag_reference_definitions;
	std::vector<c_blamtoozle_tag_array_definition*> tag_array_definitions;
	std::vector<c_blamtoozle_string_list_definition*> tag_string_list_definitions;
	std::vector<c_blamtoozle_tag_resource_definition*> tag_resource_definitions;
	std::vector<c_blamtoozle_tag_data_definition*> tag_data_definitions;
	std::vector<c_blamtoozle_tag_api_interop_definition*> tag_api_interop_definitions;
	std::vector<c_blamtoozle_tag_block_index_custom_search_definition*> tag_block_index_custom_search_definitions;

};
