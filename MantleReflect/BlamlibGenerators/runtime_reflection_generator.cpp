#include "mantlereflect-private-pch.h"

c_runtime_reflection_generator::c_runtime_reflection_generator(const wchar_t* output_header_file, const wchar_t* output_source_file) :
	c_ast_source_generator(output_header_file, output_source_file)
{

}

void c_runtime_reflection_generator::run(std::vector<c_reflection_type_container*>& type_containers)
{
	header_string_stream << "#pragma once" << std::endl;
	header_string_stream << std::endl;

	source_string_stream << "#include \"mantlegen-private-pch.h\"" << std::endl;
	source_string_stream << std::endl;

	{
		source_string_stream << "// approximately... a big contiguous chunk of all types (who knows what the compilers gonna do?)" << std::endl;
		//source_string_stream << "const s_reflection_type int32_t_type_info = s_reflection_type(_reflection_type_class_int, sizeof(int32_t), \"int32_t\", \"Int32\", \"32bit Signed Integer\");" << std::endl;
		current_enum_index = 0;
		current_member_index = 0;
		for (c_reflection_type_container* type_container : type_containers)
		{
			write_render_gui_type_entry_header(*type_container);
			write_render_gui_type_entry_source(*type_container);
		}
		source_string_stream << std::endl;
		source_string_stream << "#define memberoffset(s,m) (uint32_t)((size_t)&(((s*)0)->m))" << std::endl;
		source_string_stream << std::endl;
	}
	{
		source_string_stream << "// big contiguous chunk of all fields" << std::endl;
		source_string_stream << "const s_reflection_member g_members[] =" << std::endl;
		source_string_stream << "{" << std::endl;
		current_enum_index = 0;
		current_member_index = 0;
		for (c_reflection_type_container* type_container : type_containers)
		{
			write_render_gui_type_entry_header2(*type_container);
			write_render_gui_type_entry_source2(*type_container);
		}
		source_string_stream << "};" << std::endl;
		source_string_stream << "#undef memberoffset" << std::endl;
		source_string_stream << std::endl;
	}
	{
		source_string_stream << "// big contiguous chunk of all enum names" << std::endl;
		source_string_stream << "const s_reflection_enum_name g_enum_names[] =" << std::endl;
		source_string_stream << "{" << std::endl;

		current_enum_index = 0;
		current_member_index = 0;
		for (c_reflection_type_container* type_container : type_containers)
		{
			write_render_gui_type_entry_header3(*type_container);
			write_render_gui_type_entry_source3(*type_container);
		}

		source_string_stream << "};" << std::endl;
		source_string_stream << std::endl;


	}
	{
		current_enum_index = 0;
		current_member_index = 0;
		for (c_reflection_type_container* type_container : type_containers)
		{
			write_render_gui_type_entry_header4(*type_container);
			write_render_gui_type_entry_source4(*type_container);
		}
	}

}

void c_runtime_reflection_generator::write_render_gui_type_entry_header(const c_reflection_type_container& type_container)
{
	header_string_stream << type_container.type_name << std::endl;


}

void c_runtime_reflection_generator::write_render_gui_type_entry_source(const c_reflection_type_container& type_container)
{
	//source_string_stream << "const s_reflection_type int32_t_type_info = s_reflection_type(_reflection_type_class_int, sizeof(int32_t), \"int32_t\", \"Int32\", \"32bit Signed Integer\");" << std::endl;
	//source_string_stream << "const s_reflection_enum e_some_enum_type_info = s_reflection_enum(_reflection_type_class_enum, sizeof(e_some_enum), \"e_some_enum\", \"Some Enum\", \"An enum of some sort\", &g_enum_names[0], 1);" << std::endl;
	//source_string_stream << "const s_reflection_structure s_some_structure_type_info = s_reflection_structure(_reflection_type_class_structure, sizeof(s_some_structure), \"s_some_structure\", \"Some Structure\", \"A structure of some kind that does a thing\", nullptr, &g_members[0], 3);" << std::endl;
	//source_string_stream << "const s_reflection_structure s_some_other_structure_type_info = s_reflection_structure(_reflection_type_class_structure, sizeof(s_some_structure), \"s_some_other_structure\", \"Some Other Structure\", \"A structure of some kind that does a thing that isn't that other thing\", nullptr, &g_members[3], 2);" << std::endl;
	//source_string_stream << "const s_reflection_structure s_some_union_type_info = s_reflection_structure(_reflection_type_class_structure, sizeof(s_some_union), \"s_some_union\", \"Some Union\", \"A union that holds a couple of structures\", nullptr, &g_members[3], 2);" << std::endl;

	const char* type_class_str = reflection_type_class_to_string(type_container.type_class);

	uint32_t member_start_offset = current_member_index;
	uint32_t member_count = 0;
	for (const c_reflection_field_container* field_container : type_container.field_containers)
	{
		if (field_container->field_name.empty())
		{
			continue;
		}

		member_count++;
	}
	current_member_index += member_count;

	uint32_t enum_start_offset = current_enum_index;
	uint32_t enum_count = static_cast<uint32_t>(type_container.enum_name_containers.size());
	current_enum_index += enum_count;

	if (type_container.type_class == _reflection_type_class_structure)
	{
		source_string_stream << "const s_reflection_structure ";
		source_string_stream << type_container.type_name << "_type_info = s_reflection_structure";
		source_string_stream << "(" << type_class_str << ", ";												// e_reflection_type_class type
		source_string_stream << "sizeof(" << type_container.qualified_name << "), ";						// uint32_t size
		source_string_stream << "\"" << type_container.type_name << "\", ";									// const char* raw_name
		source_string_stream << "\"" << type_container.nice_name << "\", ";									// const char* nice_name
		source_string_stream << "\"" << type_container.description << "\", ";								// const char* description
		source_string_stream << "nullptr, ";																// const s_reflection_structure* inheritance
		source_string_stream << "&g_members[" << member_start_offset << "], ";								// const s_reflection_member* members
		source_string_stream << member_count << ");";														// uint16_t num_menbers
	}
	else if (type_container.type_class == _reflection_type_class_enum)
	{
		source_string_stream << "const s_reflection_enum ";
		source_string_stream << type_container.type_name << "_type_info = s_reflection_enum";
		source_string_stream << "(" << type_class_str << ", ";												// e_reflection_type_class type
		source_string_stream << "sizeof(" << type_container.qualified_name << "), ";						// uint32_t size
		source_string_stream << "\"" << type_container.type_name << "\", ";									// const char* raw_name
		source_string_stream << "\"" << type_container.nice_name << "\", ";									// const char* nice_name
		source_string_stream << "\"" << type_container.description << "\", ";								// const char* description
		source_string_stream << "&g_enum_names[" << enum_start_offset << "], ";								// const s_reflection_enum_name* names
		source_string_stream << enum_count << ");";															// uint16_t num_names
	}
	else
	{
		source_string_stream << "const s_reflection_type ";
		source_string_stream << type_container.type_name << "_type_info = s_reflection_type";
		source_string_stream << "(" << type_class_str << ", ";
		source_string_stream << "sizeof(" << type_container.qualified_name << "), ";
		source_string_stream << "\"" << type_container.type_name << "\", ";
		source_string_stream << "\"" << type_container.nice_name << "\", ";
		source_string_stream << "\"" << type_container.description << "\");";
	}
	source_string_stream << std::endl;




	//source_string_stream << type_container.type_name << std::endl;

	//for (c_reflection_field_container* field_container : type_container.field_containers)
	//{
	//	source_string_stream << "\t" << field_container->field_name << std::endl;
	//}

	//source_string_stream << std::endl;
}

void c_runtime_reflection_generator::write_render_gui_type_entry_header2(const c_reflection_type_container& type_container)
{

}

void c_runtime_reflection_generator::write_render_gui_type_entry_source2(const c_reflection_type_container& type_container)
{
	//static int i = 0;
	source_string_stream << "\t" << "// " << type_container.type_name << " (" << type_container.field_containers.size() << " fields)" << std::endl;
	for (const c_reflection_field_container* field_container : type_container.field_containers)
	{
		//if (i++ >= 40) break;

		if (field_container->field_name.empty())
		{
			continue;
		}

		const char* qualified_name_string = field_container->qualified_decl.c_str();

		const char* qualified_type_string = nullptr;
		if (field_container->type_container)
		{
			qualified_type_string = field_container->type_container->qualified_name.c_str();
		}
		else // #TODO: remove
		{
			qualified_type_string = "int32_t";
		}

		const char* field_type_class_str = reflection_type_class_to_string(field_container->type_class);

		source_string_stream << "\t" << "s_reflection_member(" << type_container.type_name << "_type_info, ";
		source_string_stream << field_type_class_str << ", ";
		source_string_stream << "memberoffset(" << type_container.type_name << ", " << field_container->field_name << "), ";
		source_string_stream << "sizeof(" << qualified_name_string << "), ";
		if (field_container->type_container)
		{
			const c_reflection_type_container* field_type_container = field_container->type_container;


			source_string_stream << field_type_container->type_name << "_type_info, ";

		}
		else
		{
			source_string_stream << "int32_t_type_info, ";
		}
		source_string_stream << "\"" << field_container->field_name << "\", ";
		source_string_stream << "\"" << field_container->nice_name << "\", ";
		source_string_stream << "\"" << field_container->description << "\")," << std::endl;;


		//source_string_stream << "\t" << "s_reflection_member(s_some_structure_type_info, sizeof(uint16_t), memberoffset(s_some_structure, some_value0), e_some_enum_type_info, \"some_value0\", \"Some Value 0\", \"A value that stores something\"), // enum with a different underlying size" << std::endl;
		//source_string_stream << "\t" << "s_reflection_member(s_some_structure_type_info, sizeof(int32_t), memberoffset(s_some_structure, some_value1), int32_t_type_info, \"some_value1\", \"Some Value 1\", \"A value that stores something\")," << std::endl;
		//source_string_stream << "\t" << "s_reflection_member(s_some_structure_type_info, sizeof(int32_t), memberoffset(s_some_structure, some_value1), int32_t_type_info, \"some_value2\", \"Some Value 2\", \"A value that stores something\")," << std::endl;

		

	}
	source_string_stream << std::endl;

	//source_string_stream << "\t" << "// s_some_other_structure (2 fields)" << std::endl;
	//source_string_stream << "\t" << "s_reflection_member(s_some_other_structure_type_info, sizeof(int32_t), memberoffset(s_some_other_structure, some_value1), int32_t_type_info, \"some_value0\", \"Some Value\", \"A value that stores something\")," << std::endl;
	//source_string_stream << "\t" << "s_reflection_member(s_some_other_structure_type_info, sizeof(int32_t), memberoffset(s_some_other_structure, some_value1), int32_t_type_info, \"some_value1\", \"Some Value\", \"A value that stores something\")," << std::endl;
	//source_string_stream << std::endl;
	//source_string_stream << "\t" << "// s_some_union (2 fields)" << std::endl;
	//source_string_stream << "\t" << "s_reflection_member(s_some_other_structure_type_info, sizeof(int32_t), memberoffset(s_some_other_structure, some_value1), int32_t_type_info, \"some_value0\", \"Some Value\", \"A value that stores something\")," << std::endl;
	//source_string_stream << "\t" << "s_reflection_member(s_some_other_structure_type_info, sizeof(int32_t), memberoffset(s_some_other_structure, some_value1), int32_t_type_info, \"some_value1\", \"Some Value\", \"A value that stores something\")," << std::endl;
	//source_string_stream << "" << std::endl;
}

void c_runtime_reflection_generator::write_render_gui_type_entry_header3(const c_reflection_type_container& type_container)
{

}

void c_runtime_reflection_generator::write_render_gui_type_entry_source3(const c_reflection_type_container& type_container)
{
	// source_string_stream << "\t" << "// e_some_enum_type_info (1 name)" << std::endl;
	source_string_stream << "\t" << "// " << type_container.type_name << " (" << type_container.enum_name_containers.size() << " names)" << std::endl;
	for (const c_reflection_enum_name_container* enum_name_container : type_container.enum_name_containers)
	{
		// source_string_stream << "\t" << "s_reflection_enum_name(e_some_enum_type_info, 100, \"_some_enum_value_a\", \"Value A\", \"The first value of an enum\")," << std::endl;
		source_string_stream << "\t" << "s_reflection_enum_name(" << type_container.type_name << "_type_info, ";
		source_string_stream << enum_name_container->value << "ui64, ";
		source_string_stream << "\""<< enum_name_container->value_name <<"\", ";
		source_string_stream << "\"" << enum_name_container->nice_name << "\", ";
		source_string_stream << "\"" << enum_name_container->description << "\")," << std::endl;
	}
	source_string_stream << std::endl;
}

void c_runtime_reflection_generator::write_render_gui_type_entry_header4(const c_reflection_type_container& type_container)
{

}

void c_runtime_reflection_generator::write_render_gui_type_entry_source4(const c_reflection_type_container& type_container)
{
	if (type_container.type_class == _reflection_type_class_structure || type_container.type_class == _reflection_type_class_union)
	{
		source_string_stream << "template<> const s_reflection_structure& structure_reflection<" << type_container.qualified_name << ">() { return " << type_container.type_name << "_type_info; }" << std::endl;
	}
	else if (type_container.type_class == _reflection_type_class_enum)
	{
		source_string_stream << "template<> const s_reflection_enum& enum_reflection<" << type_container.qualified_name << ">() { return " << type_container.type_name << "_type_info; }" << std::endl;
	}

	
}
