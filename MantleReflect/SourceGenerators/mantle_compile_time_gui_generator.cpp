#include "mantlereflect-private-pch.h"

c_mantle_compile_time_gui_generator::c_mantle_compile_time_gui_generator(const wchar_t* output_header_file, const wchar_t* output_source_file, std::vector<c_reflection_type_container*>& reflection_types) :
	c_ast_source_generator(output_header_file, output_source_file, reflection_types)
{

}

void c_mantle_compile_time_gui_generator::run()
{
	header_string_stream << "#pragma once" << std::endl << std::endl;
	header_string_stream << "template<typename T>" << std::endl;
	header_string_stream << "void render_type_gui();" << std::endl << std::endl;

	source_string_stream << "#include <MantleReflect/ReflectionTypes.h>" << std::endl;
	source_string_stream << "#include \"Tags.h\"" << std::endl << std::endl;

	for (c_reflection_type_container* reflection_type_container : reflection_types)
	{
		write_render_gui_type_entry_header(*reflection_type_container);
	}
	source_string_stream << std::endl;
	for (c_reflection_type_container* reflection_type_container : reflection_types)
	{
		write_render_gui_type_entry_source(*reflection_type_container);
	}
}

void c_mantle_compile_time_gui_generator::write_render_gui_type_entry_header(const c_reflection_type_container& reflection_type_container)
{
	if (reflection_type_container.is_primitive) return; // skip internal types

	source_string_stream << "template<> void render_type_gui<" << reflection_type_container.qualified_type_name << ">();" << std::endl;
}

void c_mantle_compile_time_gui_generator::write_render_gui_type_entry_source(const c_reflection_type_container& reflection_type_container)
{
	if (reflection_type_container.is_primitive) return; // skip internal types

	source_string_stream << "template<>" << std::endl;
	source_string_stream << "void render_type_gui<" << reflection_type_container.qualified_type_name << ">()" << std::endl;
	source_string_stream << "{" << std::endl;



	source_string_stream << "}" << std::endl;
	source_string_stream << std::endl;
}
