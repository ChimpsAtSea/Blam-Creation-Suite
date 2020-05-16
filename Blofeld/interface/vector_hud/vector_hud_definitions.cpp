#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(vector_hud_definition, VECTOR_HUD_DEFINITION_TAG, vector_hud_definition_block_block );

TAG_BLOCK_FROM_STRUCT(vector_hud_definition_block, 1, vector_hud_definition_struct_definition_struct_definition );

TAG_STRUCT(vector_hud_definition_struct_definition)
{
	FIELD( _field_data, "raw hud data" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

