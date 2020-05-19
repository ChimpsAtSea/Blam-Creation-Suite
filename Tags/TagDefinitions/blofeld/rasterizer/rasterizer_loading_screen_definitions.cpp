#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(load_screen, LOAD_SCREEN_TAG, loadScreenBlock_block );

	TAG_BLOCK(vertexBlock, 77824)
	{
		{ _field_real_point_3d, "point*" },
		{ _field_terminator }
	};

	TAG_BLOCK(loadScreenBlock, 1)
	{
		{ _field_long_flags, "flags", &loadscreenFlags },
		{ _field_explanation, "Model parameters" },
		{ _field_tag_reference, "source render model", &render_model_reference$4 },
		{ _field_real, "spawn rate multiplier#the higher this number, the sooner the model is fully spawned in" },
		{ _field_real_point_3d, "source scan position#the direction in model space that the scan starts from.\nIgnored if do not sort vertex order flag is set above" },
		{ _field_real, "scale factor#model scale to match camera space" },
		{ _field_explanation, "Camera parameters" },
		{ _field_real_point_3d, "camera position" },
		{ _field_real_point_3d, "camera target position" },
		{ _field_real, "camera orbit period#0 means camera is stationary" },
		{ _field_explanation, "Particles" },
		{ _field_real, "particle scale#scale factor for individual particles" },
		{ _field_real, "particle acceleration#This is the acceleration rate when particles spawn in and move to their ultimate destination.  Higher numbers move faster." },
		{ _field_real, "particle initial offset multiplier#If flag particles spawn radially is set, this is the multiple of the particle location along the radial axis.\nIf not, this the random spawn distance from the particle destination." },
		{ _field_explanation, "Generated data" },
		{ _field_long_integer, "computed model vertex count:vertices" },
		{ _field_block, "model vertices*", &vertexBlock_block },
		{ _field_terminator }
	};

	STRINGS(loadscreenFlags)
	{
		"resolve two sided",
		"do not sort vertex order",
		"particles spawn radially#see particle initial offset multiplier"
	};
	STRING_LIST(loadscreenFlags, loadscreenFlags_strings, _countof(loadscreenFlags_strings));

	TAG_REFERENCE(global_loadscreen_reference, LOAD_SCREEN_TAG);

} // namespace blofeld

