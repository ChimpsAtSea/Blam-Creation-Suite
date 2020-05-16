#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(grounded_friction, GROUNDED_FRICTION_TAG, grounded_friction_block_block );

TAG_BLOCK_FROM_STRUCT(grounded_friction_block, 1, grounded_friction_struct_definition_struct_definition );

TAG_STRUCT(grounded_friction_struct_definition)
{
	FIELD( _field_explanation, "GROUNDED FRICTION" ),
	FIELD( _field_struct, "Friction over time", &scalar_function_named_struct_struct_definition ),
	FIELD( _field_real, "Friction over time domain min:seconds#Grounded time at which the graph begins to apply (corresponds to the left side of the graph).  E.g. If you set this to 5.0, no friction will be applied for the first 5 seconds after an object is considered to be \"grounded\"." ),
	FIELD( _field_real, "Friction over time domain max:seconds#Grounded time at which the graph ends (corresponds to the right side of the graph).  E.g. If want friction to be a constant 0.5 after 15 seconds of grounded motion, set this to 15 and make the graph end at 0.5." ),
	FIELD( _field_real, "Maximum slope for friction:degrees#If the slope of the surface the object is resting on is steeper than this, the grounded friction timer will reset to zero (disabling friction temporarily)." ),
	FIELD( _field_real, "Minimum asymmetry ratio for axis lock#If the length of the longest axis of the object\'s bounding box is at least this multiple of the length of its shortest axis, angular friction will be applied only to rotation around the longest axis (to prevent the slow timber effect). 2.0 is the default if this is left at 0.0. Use a very large number to disable (e.g. 10000.0)." ),
	FIELD( _field_terminator )
};

} // namespace blofeld

