#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		load_screen_group,
		LOAD_SCREEN_TAG,
		nullptr,
		INVALID_TAG,
		loadScreenBlock_block );

	#define LOAD_SCREEN_STRUCT_DEFINITION_ID { 0x2E46384A, 0xEF8849AA, 0xB23A75A8, 0xFD5DEE4F }
	TAG_BLOCK(
		loadScreenBlock_block,
		"loadScreenBlock",
		1,
		"LoadScreenDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		LOAD_SCREEN_STRUCT_DEFINITION_ID)
	{
		{ _field_long_flags, "flags", &loadscreenFlags },
		{ _field_explanation, "Model parameters", "" },
		{ _field_tag_reference, "source render model", &render_model_reference$4 },
		{ _field_real, "spawn rate multiplier", "the higher this number, the sooner the model is fully spawned in" },
		{ _field_real_point_3d, "source scan position", "the direction in model space that the scan starts from.\nIgnored if do not sort vertex order flag is set above" },
		{ _field_real, "scale factor", "model scale to match camera space" },
		{ _field_explanation, "Camera parameters", "" },
		{ _field_real_point_3d, "camera position" },
		{ _field_real_point_3d, "camera target position" },
		{ _field_real, "camera orbit period", "0 means camera is stationary" },
		{ _field_explanation, "Particles", "The following control particle behavior" },
		{ _field_real, "particle scale", "scale factor for individual particles" },
		{ _field_real, "particle acceleration", "This is the acceleration rate when particles spawn in and move to their ultimate destination.  Higher numbers move faster." },
		{ _field_real, "particle initial offset multiplier", "If flag particles spawn radially is set, this is the multiple of the particle location along the radial axis.\nIf not, this the random spawn distance from the particle destination." },
		{ _field_explanation, "Generated data", "the following are generated from running the tool generate-loadscreen command on this tag." },
		{ _field_long_integer, "computed model vertex count", "vertices" },
		{ _field_block, "model vertices", &vertexBlock_block },
		{ _field_terminator }
	};

	#define VERTEXBLOCK_ID { 0x78585A41, 0xEDEE4CEF, 0x8FA573A4, 0xB55AEE3D }
	TAG_BLOCK(
		vertexBlock_block,
		"vertexBlock",
		77824,
		"real_point3d",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		VERTEXBLOCK_ID)
	{
		{ _field_real_point_3d, "point" },
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

} // namespace macaque

} // namespace blofeld

