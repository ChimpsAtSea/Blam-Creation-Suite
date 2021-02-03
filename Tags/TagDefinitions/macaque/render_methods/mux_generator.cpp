#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		mux_generator_group,
		MUX_GENERATOR_TAG,
		nullptr,
		INVALID_TAG,
		mux_generator_block );

	TAG_BLOCK_FROM_STRUCT(
		mux_generator_block,
		"mux_generator_block",
		1,
		mux_generator_struct_definition);

	#define MUX_GENERATOR_MATERIAL_BLOCK_ID { 0xEB1A54DC, 0x46534B9C, 0xBEA3C266, 0xBDAE8035 }
	TAG_BLOCK(
		mux_generator_material_block,
		"mux_generator_material_block",
		s_mux_generator::k_max_materials,
		"s_mux_generator_material",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MUX_GENERATOR_MATERIAL_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_tag_reference, "mux material", &Tag::Reference<class c_render_method_shader_mux_material>::s_defaultDefinition },
		{ _field_terminator }
	};

	#define MUX_GENERATOR_STRUCT_DEFINITION_ID { 0xA616DC83, 0x5C9B46DF, 0xA97EF406, 0x704B43E8 }
	TAG_STRUCT(
		mux_generator_struct_definition,
		"mux_generator_struct_definition",
		"s_mux_generator",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MUX_GENERATOR_STRUCT_DEFINITION_ID)
	{
		FIELD_CUSTOM("generate", nullptr, _field_id_unknown_compile),
		{ _field_explanation, "Blend Map", "The blend map determines which material shows up where in your mux shader.\nWhere the blend map is black (color 0) you will see the first material\nWhere it is white (color 255), you will see the last material\nIn between it will blend through all the materials in order (at least once through the list)\nSo if you have 5 materials, first set to 1, and last set to 2, the material order is:\n1-2-3-4-0-1-2\nBy default, it starts and ends at the first material:\n0-1-2-3-4-0\n" },
		{ _field_tag_reference, "blend texture", &bitmap_reference$10 },
		{ _field_long_block_index, "first material in blend map", &mux_generator_material_block },
		{ _field_long_block_index, "last material in blend map", &mux_generator_material_block },
		{ _field_block, "materials", &mux_generator_material_block },
		{ _field_explanation, "TARGETS", "these will be filled out automatically if you don\'t specify them\nthese are the tags that will be modified by this mux generator\n" },
		{ _field_tag_reference, "target mux shader", &shader_mux_reference },
		{ _field_tag_reference, "target albedo base", &bitmap_reference$10 },
		{ _field_tag_reference, "target albedo detail", &bitmap_reference$10 },
		{ _field_tag_reference, "target bump base", &bitmap_reference$10 },
		{ _field_tag_reference, "target bump detail", &bitmap_reference$10 },
		{ _field_tag_reference, "target parallax", &bitmap_reference$10 },
		{ _field_tag_reference, "target material 0", &bitmap_reference$10 },
		{ _field_tag_reference, "target material 1", &bitmap_reference$10 },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

