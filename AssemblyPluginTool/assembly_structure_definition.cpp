#include "assemblyplugintool-private-pch.h"

c_assembly_structure_definition::c_assembly_structure_definition(c_assembly_plugin_tool& plugin_tool, const char* name, xml_object_range<xml_node_iterator> nodes) :
	plugin_tool(plugin_tool),
	structure_name(name),
	tool_error(_apt_error_ok)
{
	log("Creating structure '%s'\n", name);

	for (xml_node node : nodes)
	{
		e_assembly_data_type data_type = _data_type_unknown;
		uint32_t array_size = 0;
		c_assembly_structure_definition* structure_definition = nullptr;
		c_assembly_bitfield_definition* bitfield_definition = nullptr;
		c_assembly_enum_definition* enum_definition = nullptr;

		if (nodecmp(node, "revisions")) continue;

		if (nodecmp(node, "comment"))
		{
			data_type = _data_type_comment;

			xml_attribute title_attribute = node.attribute("title");
			if (title_attribute.empty())
				return_error(_apt_error_failed_to_find_title_attribute);

			fields.emplace_back(data_type, title_attribute.as_string());
			continue;
		}

		xml_attribute name_attribute = node.attribute("name");
		if (name_attribute.empty())
			return_error(_apt_error_failed_to_find_name_attribute);

		if (nodecmp(node, "reflexive"))
		{
			data_type = _data_type_reflexive;



			// #TODO: correct structure name
			structure_definition = new c_assembly_structure_definition(plugin_tool, name_attribute.as_string(), node.children());
		}
		else if (nodecmp(node, "tagref")) data_type = _data_type_tagref;
		else if (nodecmp(node, "dataref")) data_type = _data_type_dataref;
		else if (nodecmp(node, "shader")) data_type = _data_type_shader;
		else if (nodecmp(node, "uniclist")) data_type = _data_type_uniclist;
		else if (nodecmp(node, "ascii"))
		{
			data_type = _data_type_ascii;
			xml_attribute length_attribute = node.attribute("length");
			array_size = length_attribute.as_uint();
		}
		else if (nodecmp(node, "utf16"))
		{
			data_type = _data_type_utf16;
			xml_attribute length_attribute = node.attribute("length");
			array_size = length_attribute.as_uint();
		}
		else if (nodecmp(node, "raw"))
		{
			data_type = _data_type_raw;
			xml_attribute size_attribute = node.attribute("size");
			array_size = size_attribute.as_uint();
		}
		else if (nodecmp(node, "stringid")) data_type = _data_type_stringid;
		else if (nodecmp(node, "int8")) data_type = _data_type_int8;
		else if (nodecmp(node, "int16")) data_type = _data_type_int16;
		else if (nodecmp(node, "int32")) data_type = _data_type_int32;
		else if (nodecmp(node, "int64")) data_type = _data_type_int64;
		else if (nodecmp(node, "uint8")) data_type = _data_type_uint8;
		else if (nodecmp(node, "uint16")) data_type = _data_type_uint16;
		else if (nodecmp(node, "uint32")) data_type = _data_type_uint32;
		else if (nodecmp(node, "uint64")) data_type = _data_type_uint64;
		else if (nodecmp(node, "bitfield8")) data_type = _data_type_bitfield8;
		else if (nodecmp(node, "bitfield16")) data_type = _data_type_bitfield16;
		else if (nodecmp(node, "bitfield32")) data_type = _data_type_bitfield32;
		else if (nodecmp(node, "bitfield64")) data_type = _data_type_bitfield64;
		else if (nodecmp(node, "enum8")) data_type = _data_type_enum8;
		else if (nodecmp(node, "enum16")) data_type = _data_type_enum16;
		else if (nodecmp(node, "enum32")) data_type = _data_type_enum32;
		else if (nodecmp(node, "enum64")) data_type = _data_type_enum64;
		else if (nodecmp(node, "undefined"))	data_type = _data_type_undefined32;
		else if (nodecmp(node, "undefined8"))	data_type = _data_type_undefined8;
		else if (nodecmp(node, "undefined16"))	data_type = _data_type_undefined16;
		else if (nodecmp(node, "undefined32"))	data_type = _data_type_undefined32;
		else if (nodecmp(node, "undefined64"))	data_type = _data_type_undefined64;
		else if (nodecmp(node, "half")) data_type = _data_type_half;
		else if (nodecmp(node, "float16")) data_type = _data_type_half;
		else if (nodecmp(node, "float")) data_type = _data_type_float;
		else if (nodecmp(node, "float32")) data_type = _data_type_float;
		else if (nodecmp(node, "double")) data_type = _data_type_double;
		else if (nodecmp(node, "float64")) data_type = _data_type_double;
		else if (nodecmp(node, "degree")) data_type = _data_type_degree;
		else if (nodecmp(node, "color24") || nodecmp(node, "colour24")) data_type = _data_type_colour24;
		else if (nodecmp(node, "color32") || nodecmp(node, "colour32")) data_type = _data_type_colour32;
		else if (nodecmp(node, "colorf") || nodecmp(node, "colourf")) data_type = _data_type_colourf;
		else throw;

		if (data_type == _data_type_bitfield8 || data_type == _data_type_bitfield16 || data_type == _data_type_bitfield32 || data_type == _data_type_bitfield64)
		{
			bitfield_definition = new c_assembly_bitfield_definition(plugin_tool, name_attribute.as_string(), node.children());
		}
		if (data_type == _data_type_enum8 || data_type == _data_type_enum16 || data_type == _data_type_enum32 || data_type == _data_type_enum64)
		{
			enum_definition = new c_assembly_enum_definition(plugin_tool, name_attribute.as_string(), node.children());
		}

		fields.emplace_back(data_type, name_attribute.as_string(), array_size, structure_definition, bitfield_definition, enum_definition);
	}


}

void c_assembly_structure_definition::print_debug(int level)
{
#if ENABLE_LOGGING == 0
	return;
#endif
#define print_debug_log(...) for(int i=0;i<level;i++) log("\t"); log(__VA_ARGS__);

	print_debug_log("struct '%s' {\n", structure_name.c_str());
	for (c_assembly_field_definition& field : fields)
	{
		if (field.enum_definition)
		{
			level++;
			const char* enum_underlying_type = "";
			switch (field.data_type)
			{
			case _data_type_enum8: enum_underlying_type = "uint8_t"; break;
			case _data_type_enum16: enum_underlying_type = "uint16_t"; break;
			case _data_type_enum32: enum_underlying_type = "uint32_t"; break;
			case _data_type_enum64: enum_underlying_type = "uint64_t"; break;
			}
			print_debug_log("enum '%s' : %s {\n", field.enum_definition->enum_name.c_str(), enum_underlying_type);
			for (c_assembly_enum& $enum : field.enum_definition->enums)
			{
				print_debug_log("\t'%s' = 1 << %i,\n", $enum.first.c_str(), $enum.second);
			}
			print_debug_log("}\n");
			level--;
		}
	}
	for (c_assembly_field_definition& field : fields)
	{
		if (field.bitfield_definition)
		{
			level++;
			const char* bitfield_underlying_type = "";
			switch (field.data_type)
			{
			case _data_type_bitfield8: bitfield_underlying_type = "uint8_t"; break;
			case _data_type_bitfield16: bitfield_underlying_type = "uint16_t"; break;
			case _data_type_bitfield32: bitfield_underlying_type = "uint32_t"; break;
			case _data_type_bitfield64: bitfield_underlying_type = "uint64_t"; break;
			}
			print_debug_log("enum '%s' : %s { /* bitfield */\n", field.bitfield_definition->bitfield_name.c_str(), bitfield_underlying_type);
			for (c_assembly_bit& bit : field.bitfield_definition->bits)
			{
				print_debug_log("\t'%s' = 1 << %i,\n", bit.first.c_str(), bit.second);
			}
			print_debug_log("}\n");
			level--;
		}
	}
	for (c_assembly_field_definition& field : fields)
	{
		if (field.structure_definition)
		{
			field.structure_definition->print_debug(level + 1);
		}
	}
	for (c_assembly_field_definition& field : fields)
	{
		switch (field.data_type)
		{
		case _data_type_reflexive:
			print_debug_log("\t%s<%s> '%s';\n", data_type_to_string(field.data_type), field.structure_definition->structure_name.c_str(), field.field_name.c_str());
			break;
		case _data_type_bitfield8:
		case _data_type_bitfield16:
		case _data_type_bitfield32:
		case _data_type_bitfield64:
			print_debug_log("\t%s<%s> '%s';\n", data_type_to_string(field.data_type), field.bitfield_definition->bitfield_name.c_str(), field.field_name.c_str());
			break;
		case _data_type_enum8:
		case _data_type_enum16:
		case _data_type_enum32:
		case _data_type_enum64:
			print_debug_log("\t%s<%s> '%s';\n", data_type_to_string(field.data_type), field.enum_definition->enum_name.c_str(), field.field_name.c_str());
			break;
		case _data_type_raw:
		case _data_type_ascii:
		case _data_type_utf16:
			print_debug_log("\t%s '%s'[%i];\n", data_type_to_string(field.data_type), field.field_name.c_str(), field.array_size);
			break;
		default:
			print_debug_log("\t%s '%s';\n", data_type_to_string(field.data_type), field.field_name.c_str());
			break;
		}
	}
	print_debug_log("};\n");

#undef log
}
