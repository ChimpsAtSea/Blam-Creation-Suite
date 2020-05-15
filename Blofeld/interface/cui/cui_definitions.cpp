#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(string_file_references, 16)
{
	FIELD( _field_tag_reference, "string list" ),
	FIELD( _field_terminator )
};

TAG_GROUP(cui_logic, CUI_LOGIC_TAG)
{
	FIELD( _field_string_id, "logic name" ),
	FIELD( _field_tag_reference, "string list" ),
	FIELD( _field_struct, "system" ),
	FIELD( _field_terminator )
};

TAG_GROUP(cui_screen, CUI_SCREEN_TAG)
{
	FIELD( _field_block, "string references", &string_file_references_block ),
	FIELD( _field_tag_reference, "logic" ),
	FIELD( _field_struct, "system" ),
	FIELD( _field_terminator )
};

TAG_GROUP(cui_static_data, CUI_STATIC_DATA_TAG)
{
	FIELD( _field_struct, "static data" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

