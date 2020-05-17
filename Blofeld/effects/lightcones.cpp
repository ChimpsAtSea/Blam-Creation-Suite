#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(lightConeFlags, 1)
	{
		OPTION("disabled in split-screen"),
	};

	TAG_GROUP_FROM_BLOCK(light_cone, LIGHT_CONE_TAG, light_cone_block_block );

	TAG_BLOCK_FROM_STRUCT(light_cone_block, 1, light_cone_struct_definition_struct_definition );

TAG_STRUCT(light_cone_struct_definition)
{
		FIELD( _field_byte_flags, "flags", &lightConeFlags ),
		FIELD( _field_pad, "gosh", 3 ),
		FIELD( _field_custom, "material" ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "actual material\?", &material_struct_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_real, "angle fade range:degrees" ),
		FIELD( _field_real, "angle fade cutoff:degrees" ),
		FIELD( _field_real, "far fade range:wus" ),
		FIELD( _field_real, "far fade cutoff:wus" ),
		FIELD( _field_terminator )
};

} // namespace blofeld

