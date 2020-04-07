#include "assemblyplugintool-private-pch.h"

thread_local c_assembly_structure_definition* c_assembly_structure_definition::current_root_structure = nullptr;

c_assembly_structure_definition::c_assembly_structure_definition(c_assembly_structure_definition* parent, c_assembly_plugin_tool& plugin_tool, const char* structure_name, xml_object_range<xml_node_iterator> nodes, const char* tag_group_name) :
	parent(parent),
	plugin_tool(plugin_tool),
	unformatted_name(structure_name),
	tool_error(_apt_error_ok),
	tag_group_name(tag_group_name),
	name(structure_name),
	type_name(structure_name),
	nice_name(structure_name)
{
	name = c_assembly_plugin_tool::format_source_friendly_name(unformatted_name);

	if (parent == nullptr)
	{
		current_root_structure = this;
	}
	else
	{
		name = current_root_structure->get_unique_type_name(name);
		this->type_name_tracker = current_root_structure->type_name_tracker;
	}

	type_name = std::string("s_") + name + "_definition";
	this->type_name_tracker[name]++;

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

			std::string comment = node.first_child().value();

			fields.emplace_back(*this, data_type, title_attribute.as_string(), array_size, structure_definition, bitfield_definition, enum_definition, comment);
			continue;
		}

		xml_attribute name_attribute = node.attribute("name");
		if (name_attribute.empty())
			return_error(_apt_error_failed_to_find_name_attribute);

		if (nodecmp(node, "reflexive"))
		{
			data_type = _data_type_reflexive;



			// #TODO: correct structure name
			structure_definition = new c_assembly_structure_definition(this, plugin_tool, name_attribute.as_string(), node.children());
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
		else if (nodecmp(node, "color24") || nodecmp(node, "colour24")) data_type = _data_type_color24;
		else if (nodecmp(node, "color32") || nodecmp(node, "colour32")) data_type = _data_type_color32;
		else if (nodecmp(node, "colorf") || nodecmp(node, "colourf")) data_type = _data_type_colorf;
		else throw;

		if (data_type == _data_type_bitfield8 || data_type == _data_type_bitfield16 || data_type == _data_type_bitfield32 || data_type == _data_type_bitfield64)
		{
			bitfield_definition = new c_assembly_bitfield_definition(*this, plugin_tool, name_attribute.as_string(), node.children());
		}
		if (data_type == _data_type_enum8 || data_type == _data_type_enum16 || data_type == _data_type_enum32 || data_type == _data_type_enum64)
		{
			enum_definition = new c_assembly_enum_definition(*this, plugin_tool, name_attribute.as_string(), node.children());
		}

		fields.emplace_back(*this, data_type, name_attribute.as_string(), array_size, structure_definition, bitfield_definition, enum_definition);
	}
}

c_assembly_structure_definition::~c_assembly_structure_definition()
{
	if (current_root_structure == this)
	{
		current_root_structure = nullptr;
	}
}

std::string c_assembly_structure_definition::get_unique_type_name(const std::string& name)
{
	std::string result = name;

	int index = type_name_tracker[name]++;
	if (index > 0)
	{
		result += std::to_string(index);
	}

	return result;
}

std::string c_assembly_structure_definition::get_unique_field_name(const std::string& name)
{
	std::string result = name;

	int index = field_name_tracker[name]++;
	if (index > 0)
	{
		result += std::to_string(index);
	}

	return result;
}

void c_assembly_structure_definition::print_debug(int level)
{
#if ENABLE_LOGGING == 0
	return;
#endif
#define print_debug_log(...) for(int i=0;i<level;i++) log("\t"); log(__VA_ARGS__);

	print_debug_log("struct '%s' {\n", unformatted_name.c_str());
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
			print_debug_log("enum '%s' : %s {\n", field.enum_definition->unformatted_name.c_str(), enum_underlying_type);
			for (s_assembly_enum& $enum : field.enum_definition->enums)
			{
				switch (field.data_type)
				{
				case _data_type_enum8:
					print_debug_log("\t'%s' = %iui8,\n", $enum.first.c_str(), $enum.second);
					break;
				case _data_type_enum16:
					print_debug_log("\t'%s' = %iui16,\n", $enum.first.c_str(), $enum.second);
					break;
				case _data_type_enum32:
					print_debug_log("\t'%s' = %iui32,\n", $enum.first.c_str(), $enum.second);
					break;
				case _data_type_enum64:
					print_debug_log("\t'%s' = %iui64,\n", $enum.first.c_str(), $enum.second);
					break;
				}
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
			print_debug_log("enum '%s' : %s { /* bitfield */\n", field.bitfield_definition->unformatted_name.c_str(), bitfield_underlying_type);
			for (s_assembly_bit& bit : field.bitfield_definition->bits)
			{
				switch (field.data_type)
				{
				case _data_type_bitfield8:
					print_debug_log("\t'%s' = 1ui8 << %iui8,\n", $enum.first.c_str(), $enum.second);
					break;
				case _data_type_bitfield16:
					print_debug_log("\t'%s' = 1ui16 << %iui16,\n", $enum.first.c_str(), $enum.second);
					break;
				case _data_type_bitfield32:
					print_debug_log("\t'%s' = 1ui32 << %iui32,\n", $enum.first.c_str(), $enum.second);
					break;
				case _data_type_bitfield64:
					print_debug_log("\t'%s' = 1ui64 << %iui64,\n", $enum.first.c_str(), $enum.second);
					break;
				}
				//print_debug_log("\t'%s' = 1 << %i,\n", bit.first.c_str(), bit.second);
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
			print_debug_log("\t%s<%s> '%s';\n", data_type_to_string(field.data_type), field.structure_definition->unformatted_name.c_str(), field.unformatted_name.c_str());
			break;
		case _data_type_bitfield8:
		case _data_type_bitfield16:
		case _data_type_bitfield32:
		case _data_type_bitfield64:
			print_debug_log("\t%s<%s> '%s';\n", data_type_to_string(field.data_type), field.bitfield_definition->unformatted_name.c_str(), field.unformatted_name.c_str());
			break;
		case _data_type_enum8:
		case _data_type_enum16:
		case _data_type_enum32:
		case _data_type_enum64:
			print_debug_log("\t%s<%s> '%s';\n", data_type_to_string(field.data_type), field.enum_definition->unformatted_name.c_str(), field.unformatted_name.c_str());
			break;
		case _data_type_raw:
		case _data_type_ascii:
		case _data_type_utf16:
			print_debug_log("\t%s '%s'[%i];\n", data_type_to_string(field.data_type), field.unformatted_name.c_str(), field.array_size);
			break;
		default:
			print_debug_log("\t%s '%s';\n", data_type_to_string(field.data_type), field.unformatted_name.c_str());
			break;
		}
	}
	print_debug_log("};\n");

#undef log
}

void c_assembly_structure_definition::write_begin(std::stringstream& stream)
{
	stream << "#pragma once" << std::endl << std::endl;
	write(stream, 0);
}

void c_assembly_structure_definition::write(std::stringstream& _stream, int level)
{
#define stream for (int i = 0; i < level; i++) { _stream << "\t"; } _stream 

	stream << "struct ";
	if (!nice_name.empty()) _stream << "nicename(\"" << nice_name << "\") ";
	if (!tag_group_name.empty()) _stream << "tag_group('" << tag_group_name << "') ";
	_stream << type_name << std::endl;
	stream << "{" << std::endl;

	for (c_assembly_field_definition& field : fields)
	{
		if (field.enum_definition)
		{
			level++;
			const char* underlying_type_str = data_type_to_underlying_type_string(field.data_type);
			stream << "enum ";
			if (!field.nice_name.empty()) _stream << "nicename(\"" << field.nice_name << "\") ";
			_stream << field.enum_definition->type_name << " : " << underlying_type_str << std::endl;
			stream << "{" << std::endl;
			for (s_assembly_enum& $enum : field.enum_definition->enums)
			{
				stream << "\t";
				if (!$enum.nice_name.empty()) _stream << "/*nicename(\"" << $enum.nice_name << "\")*/ ";
				switch (field.data_type)
				{
				case _data_type_enum8:
					_stream << $enum.name << " = " << $enum.value << "ui8," << std::endl;
					break;
				case _data_type_enum16:
					_stream << $enum.name << " = " << $enum.value << "ui16," << std::endl;
					break;
				case _data_type_enum32:
					_stream << $enum.name << " = " << $enum.value << "ui32," << std::endl;
					break;
				case _data_type_enum64:
					_stream << $enum.name << " = " << $enum.value << "ui64," << std::endl;
					break;
				}
			}
			stream << "};" << std::endl << std::endl;
			level--;
		}
	}
	for (c_assembly_field_definition& field : fields)
	{
		if (field.bitfield_definition)
		{
			level++;
			const char* underlying_type_str = data_type_to_underlying_type_string(field.data_type);
			stream << "enum ";
			if (!field.nice_name.empty()) _stream << "nicename(\"" << field.nice_name << "\") ";
			_stream << field.bitfield_definition->type_name << " : " << underlying_type_str << " /* bitfield */" << std::endl;
			stream << "{" << std::endl;
			for (s_assembly_bit& bit : field.bitfield_definition->bits)
			{
				stream << "\t";
				if (!bit.nice_name.empty()) _stream << "/*nicename(\"" << bit.nice_name << "\")*/ ";

				switch (field.data_type)
				{
				case _data_type_bitfield8:
					_stream << bit.name << " = 1ui8 << " << bit.index << "ui8," << std::endl;
					break;
				case _data_type_bitfield16:
					_stream << bit.name << " = 1ui16 << " << bit.index << "ui16," << std::endl;
					break;
				case _data_type_bitfield32:
					_stream << bit.name << " = 1ui32 << " << bit.index << "ui32," << std::endl;
					break;
				case _data_type_bitfield64:
					_stream << bit.name << " = 1ui64 << " << bit.index << "ui64," << std::endl;
					break;
				}
			}
			stream << "};" << std::endl << std::endl;
			level--;
		}
	}
	for (c_assembly_field_definition& field : fields)
	{
		if (field.structure_definition)
		{
			field.structure_definition->write(_stream, level + 1);
		}
	}
	level++;
	for (c_assembly_field_definition& field : fields)
	{
		if (field.data_type == _data_type_comment)
		{
			std::string comment_formatted = field.comment;
			bool is_single_line = comment_formatted.find("\n") == std::string::npos;
			if (is_single_line)
			{
				stream << "// " << field.unformatted_name << " : " << comment_formatted << std::endl;
			}
			else
			{
				std::string padding; for (int i = 0; i < level; i++) padding += "\t";
				std::string comment_new_line = std::string("\n") + padding + "   ";
				c_assembly_plugin_tool::replace_instances_in_string(comment_formatted, "\n", comment_new_line);
				stream << "/* " << field.unformatted_name << " : " << comment_formatted << " */" << std::endl;
			}

			continue;
		}


		const char* data_type_str = data_type_to_string(field.data_type);
		const char* underlying_type_str = data_type_to_underlying_type_string(field.data_type);
		switch (field.data_type)
		{
		case _data_type_reflexive:
			stream << "s_tag_block_definition<" << field.structure_definition->type_name << ">";
			break;
		case _data_type_bitfield8:
		case _data_type_bitfield16:
		case _data_type_bitfield32:
		case _data_type_bitfield64:
			//stream << data_type_str << "<" << field.bitfield_definition->type_name << ">";
			stream << field.bitfield_definition->type_name;
			break;
		case _data_type_enum8:
		case _data_type_enum16:
		case _data_type_enum32:
		case _data_type_enum64:
			//stream << data_type_str << "<" << field.enum_definition->type_name << ">";
			stream << field.enum_definition->type_name;
			break;
		case _data_type_raw:
		case _data_type_ascii:
		case _data_type_utf16:
			stream << underlying_type_str;
			break;
		default:
			stream << underlying_type_str;
			break;
		}
		if(!field.nice_name.empty()) _stream << " nicename(\""<< field.nice_name <<"\")";
		_stream << " " << field.field_name;
		if (field.array_size > 0) _stream << "[" << field.array_size << "]";
		_stream << ";" << std::endl;
	}
	level--;

	stream << "};" << std::endl << std::endl;
}
