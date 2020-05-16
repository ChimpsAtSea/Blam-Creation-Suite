#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(vector_hud_definition_struct_definition)
{
	FIELD( _field_data, "raw hud data" ),
	FIELD( _field_terminator )
};

TAG_GROUP(vector_hud_definition_block, VECTOR_HUD_DEFINITION_TAG)
{
	FIELD( _field_data, "raw hud data" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

