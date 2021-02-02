#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define CAMERA_BLOCK_ID { 0x5544FB06, 0xF3D04476, 0xA51F6257, 0x6BA634E2 }
	TAG_BLOCK(
		camera_block,
		"camera_block",
		1,
		"s_game_globals_camera",
		CAMERA_BLOCK_ID)
	{
		{ _field_tag_reference, "default unit camera track", &global_camera_track_reference },
		{ _field_explanation, "SANDBOX", "" },
		{ _field_struct, "pitch to vertical offset", &scalar_function_named_struct },
		{ _field_explanation, "CAMERA UNIVERSALS", "" },
		{ _field_real, "field of view", "degrees" },
		{ _field_real, "yaw scale" },
		{ _field_real, "pitch scale" },
		{ _field_real, "forward scale" },
		{ _field_real, "side scale" },
		{ _field_real, "up scale" },
		{ _field_explanation, "DEAD CAMERA", "" },
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
		{ _field_explanation, "FLYING CAMERA", "" },
		{ _field_real, "maximum boost speed", "the scaling factor for the left stick when the left trigger is fully depressed" },
		{ _field_real, "time to maximum_boost", "seconds. while pegging boost, time to reach maximum speed" },
		{ _field_enum, "boost function", &global_transition_functions_enum },
		FIELD_PAD("hoist", nullptr, 2),
		{ _field_real, "zoomed field of view", "field of view when zoomed", "degrees" },
		{ _field_real, "zoomed look speed", "scaling factor for look speed when zoomed" },
		{ _field_real, "bounding sphere radius", "radius of sphere for collision", "wu" },
		{ _field_real, "flying cam movement delay", "how quickly the camera responds to the user\'s input", "seconds" },
		{ _field_real, "zoom transition time", "how long it takes to zoom in or out", "seconds" },
		{ _field_real, "vertical movement time to max speed" },
		{ _field_enum, "vertical movement function", &global_transition_functions_enum },
		FIELD_PAD("moist", nullptr, 2),
		{ _field_real, "survival switch time", "how long it takes in survival mode before switching to flying camera", "seconds" },
		{ _field_explanation, "ORBITING CAMERA", "" },
		{ _field_real, "minimum distance", "wu" },
		{ _field_real, "maximum distance", "wu" },
		{ _field_real, "orbit cam movement delay", "how quickly the camera responds to the user\'s input", "seconds" },
		{ _field_real, "orbit cam z offset", "how far above the object\'s root node to position the camera\'s focus point", "wu" },
		{ _field_real, "orbit cam minimum elevation", "lowest angle the camera can be moved to", "radians" },
		{ _field_real, "orbit cam maximum elevation", "highest angle the camera can be moved to", "radians" },
		{ _field_explanation, "SAVED FILMS", "" },
		{ _field_real, "max playback speed", "how fast the film plays when the trigger is fully depressed" },
		{ _field_real, "fade out time", "how long it takes for the screen to fade out when rewinding", "seconds" },
		{ _field_real, "fade in time", "see above", "seconds" },
		{ _field_explanation, "IN GAME", "" },
		{ _field_real, "enter vehicle transition time", "how long it takes the camera to move from first to third person when entering a vehicle", "seconds" },
		{ _field_real, "exit vehicle transition time", "see above", "seconds" },
		{ _field_explanation, "CAMERA OBSTRUCTION", "" },
		{ _field_struct, "obstruction", &camera_obstruction_struct },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

