#include "tagreflection-private-pch.h"

namespace blofeld
{
	namespace halo3
	{
		c_virtual_tag_interface* create_virtual_tag_interface(c_tag_interface& tag_interface, unsigned long group_tag);
	}
	namespace haloreach
	{
		c_virtual_tag_interface* create_virtual_tag_interface(c_tag_interface& tag_interface, unsigned long group_tag);
	}
	namespace halo4
	{
		c_virtual_tag_interface* create_virtual_tag_interface(c_tag_interface& tag_interface, unsigned long group_tag);
	}
	namespace groundhog
	{
		c_virtual_tag_interface* create_virtual_tag_interface(c_tag_interface& tag_interface, unsigned long group_tag);
	}
}

c_virtual_tag_interface* create_virtual_tag_interface(c_tag_interface& tag_interface, s_engine_platform_build engine_platform_build, unsigned long group_tag)
{
	switch (engine_platform_build.engine_type)
	{
	case _engine_type_halo3: return blofeld::halo3::create_virtual_tag_interface(tag_interface, group_tag);
	case _engine_type_haloreach: return blofeld::haloreach::create_virtual_tag_interface(tag_interface, group_tag);
	case _engine_type_halo4: return blofeld::halo4::create_virtual_tag_interface(tag_interface, group_tag);
	case _engine_type_groundhog: return blofeld::groundhog::create_virtual_tag_interface(tag_interface, group_tag);
	}
	return nullptr;
}

c_virtual_tag_interface::c_virtual_tag_interface(c_tag_interface& tag_interface) :
	tag_interface(tag_interface)
{
	tag_interface.associate_virtual_tag_interface(*this);
}

c_virtual_tag_interface::~c_virtual_tag_interface()
{

}

void* c_virtual_tag_interface::get_field_data(const blofeld::s_tag_field& field)
{
	// #TODO: cache refactor
	//using namespace blofeld;

	//const blofeld::s_tag_group* group = tag_interface.get_blofeld_reflection_data();
	//if (group == nullptr)
	//{
	//	return nullptr;
	//}
	//const blofeld::s_tag_struct_definition& struct_definition = group->block_definition.struct_definition;
	//e_engine_type engine_type = tag_interface.get_cache_file().get_engine_type();
	//e_platform_type platform_type = tag_interface.get_cache_file().get_platform_type();
	//e_build build = _build_not_set; // tag_interface.get_cache_file().get_build();


	//char* current_position = tag_interface.get_data();

	//for (const s_tag_field* current_field = struct_definition.fields; current_field->field_type != _field_terminator; current_field++)
	//{
	//	if (current_field == &field)
	//	{
	//		return current_position;
	//	}

	//	const char* field_string = field_to_string(current_field->field_type);

	//	uint32_t field_skip_count;
	//	if (skip_tag_field_version(*current_field, engine_platform_build, field_skip_count))
	//	{
	//		current_field += field_skip_count;
	//		continue;
	//	}

	//	switch (current_field->field_type)
	//	{
	//	case _field_useless_pad:
	//		//computed_size += current_field->padding;
	//		break;
	//	case _field_pad:
	//		current_position += current_field->padding;
	//		break;
	//	case _field_skip:
	//		current_position += current_field->length;
	//		break;
	//	case _field_struct:
	//		current_position += calculate_struct_size(engine_platform_build, *current_field->struct_definition);
	//		break;
	//	case _field_array:
	//	{
	//		const s_tag_array_definition& array_definition = *current_field->array_definition;
	//		const s_tag_struct_definition& struct_definition = array_definition.struct_definition;
	//		uint32_t struct_size = calculate_struct_size(engine_platform_build, struct_definition);
	//		uint32_t array_data_size = struct_size * array_definition.count(engine_type);
	//		current_position += array_data_size;
	//		break;
	//	}
	//	default:
	//		current_position += get_blofeld_field_size(platform_type, current_field->field_type);
	//		break;
	//	}
	//}

	return nullptr;
}
