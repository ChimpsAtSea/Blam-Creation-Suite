#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{



	#define CAMERA_BLOCK_ID { 0x5544FB06, 0xF3D04476, 0xA51F6257, 0x6BA634E2 }
	TAG_BLOCK(
		camera_block,
		"camera_block",
		1,
		"s_game_globals_camera",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_BLOCK_ID)
	{
		{ _field_tag_reference, "default unit camera track", &global_camera_track_reference },
		FIELD_EXPLANATION("SANDBOX", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "pitch to vertical offset", &scalar_function_named_struct },
		FIELD_EXPLANATION("CAMERA UNIVERSALS", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "field of view", nullptr, "degrees" },
		{ _field_real, "yaw scale" },
		{ _field_real, "pitch scale" },
		{ _field_real, "forward scale" },
		{ _field_real, "side scale" },
		{ _field_real, "up scale" },
		FIELD_EXPLANATION("DEAD CAMERA", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "transition time", "time it takes for the camera to move from the initial distance to the final distance", "seconds" },
		{ _field_real, "falling death transition time", "time it takes for the camera to move to its final position during a falling death", "seconds" },
		{ _field_real, "initial distance", "on the first frame after death, this is how far out of the body the camera will be", "wu" },
		{ _field_real, "final distance", "how far from the body the camera will settle", "wu" },
		{ _field_real, "dead cam z offset", "how far above the body the camera focuses on", "wu" },
		{ _field_real, "dead cam maximum elevation", "the highest angle the camera can raise to (prevents it from flipping over the vertical axis)", "radians" },
		{ _field_real, "dead cam movement delay", "delay in tracking the killer", "seconds" },
		{ _field_real, "time_to_auto_switch_to_orbiting", "how long the death camera lasts before auto-switching to orbiting camera", "seconds" },
		{ _field_real, "ignore_stick_time", "how long the death camera ignores stick inputs and keeps turning towards the killer (should be non-zero because user could have died while running or looking around)", "seconds" },
		{ _field_real, "ignore_button_time", "how long the death camera ignores shoulder button inputs and keeps turning towards the killer", "seconds" },
		{ _field_real, "dead camera minimum falling velocity", "minimum velocity to switch to fell to death behavior (when biped is not actually falling to death)" },
		FIELD_EXPLANATION("FLYING CAMERA", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "maximum boost speed", "the scaling factor for the left stick when the left trigger is fully depressed" },
		{ _field_real, "time to maximum_boost", "seconds. while pegging boost, time to reach maximum speed" },
		{ _field_enum, "boost function", &global_transition_functions_enum },
		FIELD_PAD("hoist", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "zoomed field of view", "field of view when zoomed", "degrees" },
		{ _field_real, "zoomed look speed", "scaling factor for look speed when zoomed" },
		{ _field_real, "bounding sphere radius", "radius of sphere for collision", "wu" },
		{ _field_real, "flying cam movement delay", "how quickly the camera responds to the user's input", "seconds" },
		{ _field_real, "zoom transition time", "how long it takes to zoom in or out", "seconds" },
		{ _field_real, "vertical movement time to max speed" },
		{ _field_enum, "vertical movement function", &global_transition_functions_enum },
		FIELD_PAD("moist", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "survival switch time", "how long it takes in survival mode before switching to flying camera", "seconds" },
		FIELD_EXPLANATION("ORBITING CAMERA", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "minimum distance", nullptr, "wu" },
		{ _field_real, "maximum distance", nullptr, "wu" },
		{ _field_real, "orbit cam movement delay", "how quickly the camera responds to the user's input", "seconds" },
		{ _field_real, "orbit cam z offset", "how far above the object's root node to position the camera's focus point", "wu" },
		{ _field_real, "orbit cam minimum elevation", "lowest angle the camera can be moved to", "radians" },
		{ _field_real, "orbit cam maximum elevation", "highest angle the camera can be moved to", "radians" },
		FIELD_EXPLANATION("SAVED FILMS", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "max playback speed", "how fast the film plays when the trigger is fully depressed" },
		{ _field_real, "fade out time", "how long it takes for the screen to fade out when rewinding", "seconds" },
		{ _field_real, "fade in time", "see above", "seconds" },
		FIELD_EXPLANATION("IN GAME", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "enter vehicle transition time", "how long it takes the camera to move from first to third person when entering a vehicle", "seconds" },
		{ _field_real, "exit vehicle transition time", "see above", "seconds" },
		FIELD_EXPLANATION("CAMERA OBSTRUCTION", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "obstruction", &camera_obstruction_struct },
		{ _field_terminator }
	};



} // namespace blofeld

