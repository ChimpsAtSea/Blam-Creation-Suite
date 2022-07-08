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
	c_blamtoozle_tag_definition_manager();
	c_blamtoozle_tag_definition_manager(const c_blamtoozle_tag_definition_manager&) = delete;
	c_blamtoozle_tag_definition_manager(c_blamtoozle_tag_definition_manager&&) = delete;
	virtual ~c_blamtoozle_tag_definition_manager();

	virtual void set_is_big_endian(bool is_big_endian);
	virtual void format_code_symbol_name(std::string code_symbol_name);
	virtual void format_code_symbol_name_uid(std::string code_symbol_name);
	virtual c_blamtoozle_tag_group_definition* get_tag_group_definition_by_group_tag(tag group_tag);
	virtual c_blamtoozle_tag_struct_definition* get_tag_struct_definition_by_persistent_id(blofeld::s_tag_persistent_identifier persistent_identifier);

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

	template<typename t_definition_manager_type, typename t_definition_type>
	t_definition_type& eval_definition(
		ptr64 definition_address, 
		std::vector<t_definition_type*>& tag_type_definitions, 
		std::map<ptr64, t_definition_type*>& tag_type_definitions_lookup)
	{
		ASSERT(definition_address != 0);

		auto tag_type_definition_iterator = tag_type_definitions_lookup.find(definition_address);

		if (tag_type_definition_iterator != tag_type_definitions_lookup.end())
		{
			return *tag_type_definition_iterator->second;
		}

		t_definition_type* tag_type_definition = reinterpret_cast<t_definition_type*>(tracked_malloc(sizeof(t_definition_type)));

		tag_type_definitions_lookup[definition_address] = tag_type_definition;
		tag_type_definitions.push_back(tag_type_definition);

		tag_type_definition = new(tag_type_definition) t_definition_type(*static_cast<t_definition_manager_type*>(this), definition_address);

		return *tag_type_definition;
	}

	bool is_big_endian;
	std::unordered_map<std::string, unsigned long> code_symbol_counts;

	std::vector<c_blamtoozle_tag_group_definition*> tag_group_definitions;
	std::vector<c_blamtoozle_tag_struct_definition*> tag_struct_definitions;
	std::vector<c_blamtoozle_tag_block_definition*> tag_block_definitions;
	std::vector<c_blamtoozle_tag_reference_definition*> tag_reference_definitions;
	std::vector<c_blamtoozle_tag_array_definition*> tag_array_definitions;
	std::vector<c_blamtoozle_string_list_definition*> string_list_definitions;
	std::vector<c_blamtoozle_tag_resource_definition*> tag_resource_definitions;
	std::vector<c_blamtoozle_tag_data_definition*> tag_data_definitions;
	std::vector<c_blamtoozle_tag_api_interop_definition*> tag_api_interop_definitions;
	std::vector<c_blamtoozle_tag_block_index_custom_search_definition*> block_index_custom_search_definitions;

	std::map<ptr64, c_blamtoozle_tag_group_definition*> tag_group_definitions_lookup;
	std::map<ptr64, c_blamtoozle_tag_struct_definition*> tag_struct_definitions_lookup;
	std::map<ptr64, c_blamtoozle_tag_block_definition*> tag_block_definitions_lookup;
	std::map<ptr64, c_blamtoozle_tag_reference_definition*> tag_reference_definitions_lookup;
	std::map<ptr64, c_blamtoozle_tag_array_definition*> tag_array_definitions_lookup;
	std::map<ptr64, c_blamtoozle_string_list_definition*> string_list_definitions_lookup;
	std::map<ptr64, c_blamtoozle_tag_resource_definition*> tag_resource_definitions_lookup;
	std::map<ptr64, c_blamtoozle_tag_data_definition*> tag_data_definitions_lookup;
	std::map<ptr64, c_blamtoozle_tag_api_interop_definition*> tag_api_interop_definitions_lookup;
	std::map<ptr64, c_blamtoozle_tag_block_index_custom_search_definition*> block_index_custom_search_definitions_lookup;
	
};
