#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(hologramLightingGlobalsBlock, 1)
{
	FIELD( _field_custom, "HOLOGRAM FUNCTIONS" ),
	FIELD( _field_string_id, "Intensity" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "KEY LIGHT FUNCTIONS" ),
	FIELD( _field_struct, "Key Light Functions" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "FILL LIGHT FUNCTIONS" ),
	FIELD( _field_struct, "Fill Light Functions" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "RIM LIGHT FUNCTIONS" ),
	FIELD( _field_struct, "Rim Light Functions" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_BLOCK(hologramLightingBlock, 1)
{
	FIELD( _field_custom, "HOLOGRAM" ),
	FIELD( _field_custom, "Intensity" ),
	FIELD( _field_real, "Intensity" ),
	FIELD( _field_real, "Intensity Input!" ),
	FIELD( _field_char_enum, "Transparency Mode" ),
	FIELD( _field_pad, "PADDING1", 3 ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "KEY LIGHT" ),
	FIELD( _field_struct, "Key Light" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "FILL LIGHT" ),
	FIELD( _field_struct, "Fill Light" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "RIM LIGHT" ),
	FIELD( _field_struct, "Rim Light" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

} // namespace blofeld

