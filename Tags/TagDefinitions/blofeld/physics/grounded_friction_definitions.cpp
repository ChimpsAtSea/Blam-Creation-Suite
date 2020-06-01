#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(grounded_friction, GROUNDED_FRICTION_TAG, grounded_friction_block_block );

	TAG_BLOCK_FROM_STRUCT(grounded_friction_block, 1, grounded_friction_struct_definition_struct_definition );

	TAG_STRUCT(grounded_friction_struct_definition)
	{
		{ _field_explanation, "GROUNDED FRICTION", "Defines friction to be applied to grounded things (rolling or sliding) relative to the time they\'ve been rolling/sliding. Friction of 1.0 will stop them completely in a single tick.  Friction of 0.0 is the same as no friction at all.  The on-ground timer used to access this graph resets if the object leaves the ground for any period of time (bounces, is blown off the ground, etc). \n\nFOR EXAMPLE: Set up the graph as a \"Curve\", set the range to 0-1 (using the boxes at the top and bottom of the right-hand side of the graph), and set the domain min and max to 0 and 5, respectively. Set the maximum slope for friction to 90 (vertical walls).  The in-game result is that any object using this grounded friction will have friction of 0 (no friction) applied the instant they stop bouncing and start rolling/sliding, and that friction will ramp up (using the curve you provided) to 1 over the course of 5 seconds.  After 5 seconds of sliding/rolling, the object will come to a stop, no matter what (even if it\'s sliding down an 85 degree slope, because you set the maximum slope for friction to 90).  See daldridge or Sage w/ further questions." },
		{ _field_struct, "Friction over time", &scalar_function_named_struct_struct_definition },
		{ _field_real, "Friction over time domain min:seconds#Grounded time at which the graph begins to apply (corresponds to the left side of the graph).  E.g. If you set this to 5.0, no friction will be applied for the first 5 seconds after an object is considered to be \"grounded\"." },
		{ _field_real, "Friction over time domain max:seconds#Grounded time at which the graph ends (corresponds to the right side of the graph).  E.g. If want friction to be a constant 0.5 after 15 seconds of grounded motion, set this to 15 and make the graph end at 0.5." },
		{ _field_real, "Maximum slope for friction:degrees#If the slope of the surface the object is resting on is steeper than this, the grounded friction timer will reset to zero (disabling friction temporarily)." },
		{ _field_real, "Minimum asymmetry ratio for axis lock#If the length of the longest axis of the object\'s bounding box is at least this multiple of the length of its shortest axis, angular friction will be applied only to rotation around the longest axis (to prevent the slow timber effect). 2.0 is the default if this is left at 0.0. Use a very large number to disable (e.g. 10000.0)." },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_grounded_friction_reference, GROUNDED_FRICTION_TAG);

} // namespace blofeld

