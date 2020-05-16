#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(rasterizer_constant_block, c_rasterizer_constant_table_definition::k_max_constants)
{
	FIELD( _field_string_id, "constant name^" ),
	FIELD( _field_word_integer, "register start*" ),
	FIELD( _field_byte_integer, "register count*" ),
	FIELD( _field_char_enum, "register set*" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(global_rasterizer_constant_table_struct)
{
	FIELD( _field_block, "constants*", &rasterizer_constant_block_block ),
	FIELD( _field_char_enum, "type*" ),
	FIELD( _field_pad, "qersaui", 3 ),
	FIELD( _field_terminator )
};

} // namespace blofeld

