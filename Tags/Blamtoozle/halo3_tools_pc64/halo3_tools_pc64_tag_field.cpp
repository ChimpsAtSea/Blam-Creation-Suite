#include "blamtoozle-private-pch.h"

#define tag_definition_manager static_cast<c_halo3_tools_pc64_tag_definition_manager&>(tag_definition_manager)

template<> void byteswap_inplace(s_halo3_tools_pc64_tag_field& value)
{
	byteswap_inplace(value.field_type);
	byteswap_inplace(value.name_address);
	byteswap_inplace(value.definition_address);
	byteswap_inplace(value.field_id);
}

c_halo3_tools_pc64_tag_field::c_halo3_tools_pc64_tag_field(c_halo3_tools_pc64_tag_definition_manager& _tag_definition_manager, ptr64 _definition_address) :
	c_blamtoozle_tag_field(_tag_definition_manager),
	definition_address(_definition_address),
	field_definition(tag_definition_manager.read_structure<s_halo3_tools_pc64_tag_field>(_definition_address)),
	field_type(halo3_tools_pc64_field_type_to_generic_field_type(field_definition.field_type)),
	raw_name(tag_definition_manager.va_to_pointer(field_definition.name_address)),
	name(),
	description(),
	units(),
	limits(),
	limits_legacy(),
	old_names(),
	flags(),
	//definition(_tag_definition_manager.va_to_pointer(field_definition.definition_address)),
	block_definition(),
	tag_reference_definition(),
	struct_definition(),
	array_definition(),
	string_list_definition(),
	tag_resource_definition(),
	data_definition(),
	api_interop_definition(),
	block_index_custom_search_definition(),
	padding(),
	skip_length(),
	explanation()
{
	switch (field_type)
	{
	case blofeld::_field_char_block_index:
	case blofeld::_field_short_block_index:
	case blofeld::_field_long_block_index:
	case blofeld::_field_byte_block_flags:
	case blofeld::_field_word_block_flags:
	case blofeld::_field_long_block_flags:
	case blofeld::_field_block:
		block_definition = &tag_definition_manager.eval_block(field_definition.definition_address);
		break;
	case blofeld::_field_struct:
		struct_definition = &tag_definition_manager.eval_struct(field_definition.definition_address);
		break;
	case blofeld::_field_array:
		array_definition = &tag_definition_manager.eval_array(field_definition.definition_address);
		break;
	case blofeld::_field_tag_reference:
		tag_reference_definition = &tag_definition_manager.eval_tag_reference(field_definition.definition_address);
		break;
	case blofeld::_field_useless_pad:
	case blofeld::_field_pad:
		padding = field_definition.definition_address;
		break;
	case blofeld::_field_skip:
		skip_length = field_definition.definition_address;
		break;
	case blofeld::_field_char_enum:
	case blofeld::_field_short_enum:
	case blofeld::_field_long_enum:
	case blofeld::_field_long_flags:
	case blofeld::_field_word_flags:
	case blofeld::_field_byte_flags:
		string_list_definition = &tag_definition_manager.eval_string_list(field_definition.definition_address);
		break;
	case blofeld::_field_explanation:
		explanation = tag_definition_manager.va_to_pointer(field_definition.definition_address);
		break;
	case blofeld::_field_pageable_resource:
		tag_resource_definition = &tag_definition_manager.eval_pageable_resource(field_definition.definition_address);
		break;
	case blofeld::_field_char_block_index_custom_search:
	case blofeld::_field_short_block_index_custom_search:
	case blofeld::_field_long_block_index_custom_search:
		block_index_custom_search_definition = &tag_definition_manager.eval_block_index_custom_search(field_definition.definition_address);
		break;
	case blofeld::_field_custom:
		break;
	case blofeld::_field_api_interop:
		api_interop_definition = &tag_definition_manager.eval_api_interop(field_definition.definition_address);
		break;
	case blofeld::_field_data:
		data_definition = &tag_definition_manager.eval_data(field_definition.definition_address);
		break;
	case blofeld::_field_char_integer:
	case blofeld::_field_short_integer:
	case blofeld::_field_long_integer:
	case blofeld::_field_real:
	case blofeld::_field_string_id:
	case blofeld::_field_int64_integer:
		break;
	default:
		ASSERT(field_definition.definition_address == 0);
	}

	if (field_definition.field_id)
	{
		switch (field_type)
		{
		case blofeld::_field_custom:
		{
			if (const char* tag_field_attributed_definition_string = blofeld::tag_field_custom_type_to_string(static_cast<blofeld::e_tag_field_custom_type>(field_definition.field_id)))
			{

			}
			else
			{
				debug_break;
				//FATAL_ERROR("Unknown custom type");
			}
		}
		break;
		default:
		{
			if (const char* field_id_string = blofeld::field_id_to_string(static_cast<blofeld::e_field_id>(field_definition.field_id)))
			{

			}
			else if (const char* tag_field_attributed_definition_string = blofeld::tag_field_attributed_definition_to_string(static_cast<blofeld::e_tag_field_attributed_definition>(field_definition.field_id)))
			{

			}
			else
			{
				debug_break;
				//FATAL_ERROR("Unknown field id");
			}
		}
		break;
		}

	}

	string_parser(
		raw_name,
		name,
		description,
		units,
		limits,
		limits_legacy,
		old_names,
		flags);
}

c_halo3_tools_pc64_tag_field::~c_halo3_tools_pc64_tag_field()
{

}

std::string const& c_halo3_tools_pc64_tag_field::get_raw_name()
{
	return raw_name;
}

std::string const& c_halo3_tools_pc64_tag_field::get_name()
{
	return name.c_str();
}

std::string const& c_halo3_tools_pc64_tag_field::get_description()
{
	return description.c_str();
}

std::string const& c_halo3_tools_pc64_tag_field::get_units()
{
	return units.c_str();
}

std::string const& c_halo3_tools_pc64_tag_field::get_limits()
{
	return limits.c_str();
}

std::string const& c_halo3_tools_pc64_tag_field::get_limits_legacy()
{
	return limits_legacy.c_str();
}

std::vector<std::string> const& c_halo3_tools_pc64_tag_field::get_old_names()
{
	return old_names;
}

blofeld::e_field c_halo3_tools_pc64_tag_field::get_field_type()
{
	return field_type;
}

blofeld::f_tag_field_flags c_halo3_tools_pc64_tag_field::get_field_flags()
{
	return flags;
}

uint32_t c_halo3_tools_pc64_tag_field::get_padding()
{
	return padding;
}

uint32_t c_halo3_tools_pc64_tag_field::get_skip_length()
{
	return skip_length;
}

const char* c_halo3_tools_pc64_tag_field::get_explanation()
{
	return explanation;
}

bool c_halo3_tools_pc64_tag_field::get_tag_field_attributed_definition(blofeld::e_tag_field_attributed_definition& out_tag_field_attributed_definition)
{
	if (field_definition.field_id)
	{
		blofeld::e_tag_field_attributed_definition tag_field_attributed_definition = static_cast<blofeld::e_tag_field_attributed_definition>(field_definition.field_id);
		if (const char* tag_field_attributed_definition_string = blofeld::tag_field_attributed_definition_to_string(tag_field_attributed_definition))
		{
			out_tag_field_attributed_definition = tag_field_attributed_definition;
			return true;
		}
	}
	return false;
}

bool c_halo3_tools_pc64_tag_field::get_tag_field_custom_type(blofeld::e_tag_field_custom_type& out_tag_field_custom_type)
{
	if (field_definition.field_id)
	{
		blofeld::e_tag_field_custom_type tag_field_custom_type = static_cast<blofeld::e_tag_field_custom_type>(field_definition.field_id);
		if (const char* tag_field_custom_type_string = blofeld::tag_field_custom_type_to_string(tag_field_custom_type))
		{
			out_tag_field_custom_type = tag_field_custom_type;
			return true;
		}
	}
	return false;
}

bool c_halo3_tools_pc64_tag_field::get_tag_field_id(blofeld::e_field_id& out_field_id)
{
	if (field_definition.field_id)
	{
		blofeld::e_field_id tag_field_id = static_cast<blofeld::e_field_id>(field_definition.field_id);
		if (const char* tag_field_id_string = blofeld::field_id_to_string(tag_field_id))
		{
			out_field_id = tag_field_id;
			return true;
		}
	}
	return false;
}

c_blamtoozle_tag_block_definition* c_halo3_tools_pc64_tag_field::get_block_definition()
{
	return block_definition;
}

c_blamtoozle_tag_reference_definition* c_halo3_tools_pc64_tag_field::get_tag_reference_definition()
{
	return tag_reference_definition;
}

c_blamtoozle_tag_struct_definition* c_halo3_tools_pc64_tag_field::get_struct_definition()
{
	return struct_definition;
}

c_blamtoozle_tag_array_definition* c_halo3_tools_pc64_tag_field::get_array_definition()
{
	return array_definition;
}

c_blamtoozle_string_list_definition* c_halo3_tools_pc64_tag_field::get_string_list_definition()
{
	return string_list_definition;
}

c_blamtoozle_tag_resource_definition* c_halo3_tools_pc64_tag_field::get_tag_resource_definition()
{
	return tag_resource_definition;
}

c_blamtoozle_tag_data_definition* c_halo3_tools_pc64_tag_field::get_data_definition()
{
	return data_definition;
}

c_blamtoozle_tag_api_interop_definition* c_halo3_tools_pc64_tag_field::get_api_interop_definition()
{
	return api_interop_definition;
}

c_blamtoozle_tag_block_index_custom_search_definition* c_halo3_tools_pc64_tag_field::get_block_index_custom_search_definition()
{
	return block_index_custom_search_definition;
}
