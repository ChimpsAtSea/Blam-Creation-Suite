#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		grounded_friction_group,
		GROUNDED_FRICTION_TAG,
		nullptr,
		INVALID_TAG,
		grounded_friction_block );

	TAG_BLOCK_FROM_STRUCT(
		grounded_friction_block,
		"grounded_friction_block",
		1,
		grounded_friction_struct_definition);

	#define GROUNDED_FRICTION_STRUCT_DEFINITION_ID { 0xE69A028A, 0x3B434D19, 0x9099E80F, 0xC0A18EC7 }
	TAG_STRUCT(
		grounded_friction_struct_definition,
		"grounded_friction_struct_definition",
		"s_grounded_friction_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GROUNDED_FRICTION_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION("GROUNDED FRICTION", nullptr, FIELD_FLAG_NONE, "Defines friction to be applied to grounded things (rolling or sliding) relative to the time they\'ve been rolling/sliding. Friction of 1.0 will stop them completely in a single tick.  Friction of 0.0 is the same as no friction at all.  The on-ground timer used to access this graph resets if the object leaves the ground for any period of time (bounces, is blown off the ground, etc). \n\nFOR EXAMPLE: Set up the graph as a \"Curve\", set the range to 0-1 (using the boxes at the top and bottom of the right-hand side of the graph), and set the domain min and max to 0 and 5, respectively. Set the maximum slope for friction to 90 (vertical walls).  The in-game result is that any object using this grounded friction will have friction of 0 (no friction) applied the instant they stop bouncing and start rolling/sliding, and that friction will ramp up (using the curve you provided) to 1 over the course of 5 seconds.  After 5 seconds of sliding/rolling, the object will come to a stop, no matter what (even if it\'s sliding down an 85 degree slope, because you set the maximum slope for friction to 90).  See daldridge or Sage w/ further questions."),
		{ _field_struct, "Friction over time", &scalar_function_named_struct },
		{ _field_real, "Friction over time domain min", "Grounded time at which the graph begins to apply (corresponds to the left side of the graph).  E.g. If you set this to 5.0, no friction will be applied for the first 5 seconds after an object is considered to be \"grounded\".", "seconds" },
		{ _field_real, "Friction over time domain max", "Grounded time at which the graph ends (corresponds to the right side of the graph).  E.g. If want friction to be a constant 0.5 after 15 seconds of grounded motion, set this to 15 and make the graph end at 0.5.", "seconds" },
		{ _field_real, "Maximum slope for friction", "If the slope of the surface the object is resting on is steeper than this, the grounded friction timer will reset to zero (disabling friction temporarily).", "degrees" },
		{ _field_real, "Minimum asymmetry ratio for axis lock", "If the length of the longest axis of the object's bounding box is at least this multiple of the length of its shortest axis, angular friction will be applied only to rotation around the longest axis (to prevent the slow timber effect). 2.0 is the default if this is left at 0.0. Use a very large number to disable (e.g. 10000.0)." },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_grounded_friction_reference, GROUNDED_FRICTION_TAG);

} // namespace macaque

} // namespace blofeld

