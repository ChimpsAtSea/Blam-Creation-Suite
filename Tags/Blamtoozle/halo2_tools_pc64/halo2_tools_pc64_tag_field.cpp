#include "blamtoozle-private-pch.h"

#define tag_definition_manager static_cast<c_halo2_tools_pc64_tag_definition_manager&>(tag_definition_manager)

template<> void byteswap_inplace(s_halo2_tools_pc64_tag_field& value)
{
	byteswap_inplace(value.field_type);
	byteswap_inplace(value.name_address);
	byteswap_inplace(value.definition_address);
	byteswap_inplace(value.field_id);
}

c_halo2_tools_pc64_tag_field::c_halo2_tools_pc64_tag_field(c_halo2_tools_pc64_tag_definition_manager& _tag_definition_manager, ptr32 _definition_address) :
	c_blamtoozle_tag_field(_tag_definition_manager),
	definition_address(_definition_address),
	field_definition(tag_definition_manager.read_structure<s_halo2_tools_pc64_tag_field>(_definition_address)),
	field_type(halo2_tools_pc64_field_type_to_generic_field_type(field_definition.field_type)),
	name(tag_definition_manager.va_to_pointer(field_definition.name_address)),
	block_definition(),
	tag_reference_definition(),
	struct_definition(),
	array_definition(),
	string_list_definition(),
	data_definition(),
	block_index_custom_search_definition(),
	padding(),
	skip_length(),
	explanation(),
	field_id(field_definition.field_id)
{
	if (field_definition.field_type == _halo2_tools_pc64_field_array_start)
	{
		array_definition = &tag_definition_manager.eval_array(_definition_address);
	}
	else switch (field_type)
	{
	case blofeld::_field_long_block_flags:
	case blofeld::_field_word_block_flags:
	case blofeld::_field_byte_block_flags:
	case blofeld::_field_block:
		block_definition = &tag_definition_manager.eval_block(field_definition.definition_address);
		break;
	case blofeld::_field_struct:
	{
		ASSERT(field_definition.field_id == 0);

		s_halo2_tools_pc64_tag_field_struct_definition tag_field_struct_definition = tag_definition_manager.read_structure<s_halo2_tools_pc64_tag_field_struct_definition>(field_definition.definition_address);

		field_id = tag_field_struct_definition.signature;

		block_definition = &tag_definition_manager.eval_block(tag_field_struct_definition.block_definition_address);
		struct_definition = static_cast<c_halo2_tools_pc64_tag_struct_definition*>(&block_definition->get_struct_definition());


		if (field_definition.field_id)
		{

		}
	}
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
	case blofeld::_field_data:
		data_definition = &tag_definition_manager.eval_data(field_definition.definition_address);
		break;
	case blofeld::_field_custom:
	case blofeld::_field_char_integer:
	case blofeld::_field_short_integer:
	case blofeld::_field_long_integer:
	case blofeld::_field_real:
	case blofeld::_field_string_id:
		break;
	case blofeld::_field_pointer:
		ASSERT(field_definition.definition_address == 4);
		break;
	case blofeld::_field_char_block_index:
	case blofeld::_field_short_block_index:
	case blofeld::_field_long_block_index:
		
		break;
	case blofeld::_field_char_block_index_custom_search:
	case blofeld::_field_short_block_index_custom_search:
	case blofeld::_field_long_block_index_custom_search:
		break;
	default:
		ASSERT(field_definition.definition_address == 0);
	}
	if (field_id)
	{
		const char* field_id_string = blofeld::field_id_to_string(field_id);
		ASSERT(field_id_string != nullptr);
	}

}

c_halo2_tools_pc64_tag_field::~c_halo2_tools_pc64_tag_field()
{

}

const char* c_halo2_tools_pc64_tag_field::get_name()
{
	return name;
}

blofeld::e_field c_halo2_tools_pc64_tag_field::get_field_type()
{
	return field_type;
}

uint32_t c_halo2_tools_pc64_tag_field::get_padding()
{
	return padding;
}

uint32_t c_halo2_tools_pc64_tag_field::get_skip_length()
{
	return skip_length;
}

const char* c_halo2_tools_pc64_tag_field::get_explanation()
{
	return explanation;
}

blofeld::e_field_id c_halo2_tools_pc64_tag_field::get_field_id()
{
	return field_id;
}

c_blamtoozle_tag_block_definition* c_halo2_tools_pc64_tag_field::get_block_definition()
{
	return block_definition;
}

c_blamtoozle_tag_reference_definition* c_halo2_tools_pc64_tag_field::get_tag_reference_definition()
{
	return tag_reference_definition;
}

c_blamtoozle_tag_struct_definition* c_halo2_tools_pc64_tag_field::get_struct_definition()
{
	return struct_definition;
}

c_blamtoozle_tag_array_definition* c_halo2_tools_pc64_tag_field::get_array_definition()
{
	return array_definition;
}

c_blamtoozle_string_list_definition* c_halo2_tools_pc64_tag_field::get_string_list_definition()
{
	return string_list_definition;
}

c_blamtoozle_tag_resource_definition* c_halo2_tools_pc64_tag_field::get_tag_resource_definition()
{
	return nullptr;
}

c_blamtoozle_tag_data_definition* c_halo2_tools_pc64_tag_field::get_data_definition()
{
	return data_definition;
}

c_blamtoozle_tag_api_interop_definition* c_halo2_tools_pc64_tag_field::get_api_interop_definition()
{
	return nullptr;
}

c_blamtoozle_tag_block_index_custom_search_definition* c_halo2_tools_pc64_tag_field::get_block_index_custom_search_definition()
{
	return block_index_custom_search_definition;
}
