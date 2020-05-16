#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(hologramLightingGlobalsBlock, 1)
{
	FIELD( _field_custom, "HOLOGRAM FUNCTIONS" ),
	FIELD( _field_string_id, "Intensity" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "KEY LIGHT FUNCTIONS" ),
	FIELD( _field_struct, "Key Light Functions", &hologramLightFunctions_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "FILL LIGHT FUNCTIONS" ),
	FIELD( _field_struct, "Fill Light Functions", &hologramLightFunctions_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "RIM LIGHT FUNCTIONS" ),
	FIELD( _field_struct, "Rim Light Functions", &hologramLightFunctions_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_BLOCK_FROM_STRUCT(hologramLightingBlock, 1, hologramLightingBlock_struct_struct_definition );

TAG_STRUCT(hologramLightFunctions)
{
	FIELD( _field_string_id, "Intensity" ),
	FIELD( _field_string_id, "Forward" ),
	FIELD( _field_string_id, "Right" ),
	FIELD( _field_string_id, "Up" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(hologramLightingBlock_struct)
{
	FIELD( _field_custom, "HOLOGRAM" ),
	FIELD( _field_custom, "Intensity" ),
	FIELD( _field_real, "Intensity" ),
	FIELD( _field_real, "Intensity Input!" ),
	FIELD( _field_char_enum, "Transparency Mode" ),
	FIELD( _field_pad, "PADDING1", 3 ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "KEY LIGHT" ),
	FIELD( _field_struct, "Key Light", &hologramLight_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "FILL LIGHT" ),
	FIELD( _field_struct, "Fill Light", &hologramLight_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "RIM LIGHT" ),
	FIELD( _field_struct, "Rim Light", &hologramLight_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_STRUCT(hologramLight)
{
	FIELD( _field_custom, "Hologram Light" ),
	FIELD( _field_custom, "Direction" ),
	FIELD( _field_real, "Direction" ),
	FIELD( _field_custom, "Front-Back" ),
	FIELD( _field_real, "Front-Back" ),
	FIELD( _field_custom, "Intensity" ),
	FIELD( _field_real, "Intensity" ),
	FIELD( _field_real, "Intensity Input!" ),
	FIELD( _field_real, "Forward Input!" ),
	FIELD( _field_real, "Right Input!" ),
	FIELD( _field_real, "Up Input!" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

