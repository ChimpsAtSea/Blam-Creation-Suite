#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		vector_hud_definition_group,
		VECTOR_HUD_DEFINITION_TAG,
		nullptr,
		INVALID_TAG,
		vector_hud_definition_block );

	TAG_BLOCK_FROM_STRUCT(
		vector_hud_definition_block,
		"vector_hud_definition_block",
		1,
		vector_hud_definition_struct_definition);

	#define VECTOR_HUD_DEFINITION_STRUCT_DEFINITION_ID { 0xE9E8447E, 0x7C54444A, 0x8C686647, 0xF6B8E4B6 }
	TAG_STRUCT(
		vector_hud_definition_struct_definition,
		"vector_hud_definition_struct_definition",
		"s_vector_hud_definition",
		VECTOR_HUD_DEFINITION_STRUCT_DEFINITION_ID)
	{
		{ _field_data, "raw hud data" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

