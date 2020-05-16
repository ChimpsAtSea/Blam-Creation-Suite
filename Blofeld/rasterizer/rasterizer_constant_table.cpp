#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(global_rasterizer_constant_table_struct)
{
	FIELD( _field_block, "constants*" ),
	FIELD( _field_char_enum, "type*" ),
	FIELD( _field_pad, "qersaui", 3 ),
	FIELD( _field_terminator )
};

} // namespace blofeld

