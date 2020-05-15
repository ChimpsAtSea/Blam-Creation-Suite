#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(string_file_references, 16)
{
	{ _field_tag_reference, "string list" },
	{ _field_terminator },
};

TAG_GROUP(cui_logic, CUI_LOGIC_TAG)
{
	{ _field_string_id, "logic name" },
	{ _field_tag_reference, "string list" },
	{ _field_struct, "system" },
	{ _field_terminator },
};

TAG_GROUP(cui_screen, CUI_SCREEN_TAG)
{
	{ _field_block, "string references", &string_file_references_block },
	{ _field_tag_reference, "logic" },
	{ _field_struct, "system" },
	{ _field_terminator },
};

TAG_GROUP(cui_static_data, CUI_STATIC_DATA_TAG)
{
	{ _field_struct, "static data" },
	{ _field_terminator },
};

} // namespace blofeld

