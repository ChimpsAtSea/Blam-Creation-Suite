#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		user_interface_hud_globals_definition_group,
		USER_INTERFACE_HUD_GLOBALS_DEFINITION_TAG,
		nullptr,
		INVALID_TAG,
		user_interface_hud_globals_definition_block );

	TAG_BLOCK_FROM_STRUCT(
		user_interface_hud_globals_definition_block,
		"user_interface_hud_globals_definition_block",
		1,
		user_interface_hud_globals_definition_struct_definition);

	#define SCREEN_TRANSFORM_BASIS_ARRAY_DEFINITION_ID { 0xEE6C4CCF, 0x5BE94948, 0xA2F9EA40, 0x71F433BE }
	TAG_ARRAY(
		screen_transform_basis_array_definition_array,
		"screen_transform_basis_array_definition",
		9,
		"real_point2d",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCREEN_TRANSFORM_BASIS_ARRAY_DEFINITION_ID)
	{
		{ _field_real_point_2d, "screen transform basis element" },
		{ _field_terminator }
	};

	#define USER_INTERFACE_HUD_GLOBALS_DEFINITION_STRUCT_DEFINITION_ID { 0x26873A9C, 0x2C164287, 0xA3863666, 0xDBD13CFC }
	TAG_STRUCT_V6(
		user_interface_hud_globals_definition_struct_definition,
		"user_interface_hud_globals_definition_struct_definition",
		"UserInterfaceHUDGlobalsDefinitions",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		USER_INTERFACE_HUD_GLOBALS_DEFINITION_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION_EX("Motion sensor globals", nullptr, FIELD_FLAG_NONE, "Misc settings for the motion sensor"),
		{ _field_byte_flags, "flags", &HUDMotionSensorGlobalsFlags },
		FIELD_PAD_EX("pad0", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_real, "active camo appears as enemy when lower than", "active Camo users show up as enemy when active camo is lower than this value (multiplayer)" },
		{ _field_real, "height classified as above", "relative height at which something is above (meters)" },
		{ _field_real, "height classified as below", "relative height at which something is below (meters)" },
		{ _field_real, "threshold speed", "speed at which stuff is visible on the sensor (meters/sec)" },
		{ _field_real, "upwards movement scaling", "multiplier for vertical speed upwards (multiplier)" },
		{ _field_real, "downwards movement scaling", "multiplier for vertical speed downwards (multiplier)" },
		{ _field_real, "crouching movement scaling", "multiplier for speed when crouching (multiplier)" },
		{ _field_real, "normal detection range extension", "how far off the edge of the radar we can detect things (multiplier)" },
		{ _field_real, "vehicle detection range extension", "how far off the edge of the radar we can detect vehicles (multiplier)" },
		{ _field_real, "vehicle radar range", "special range boost used for large flying vehicles (meters)" },
		{ _field_real, "mech radar range", "override for mech/mantis" },
		{ _field_real, "vehicle navigation marker range detection", "range at which hud nav markers will show (meters)" },
		{ _field_real, "vehicle contested flash time", "rate at which a contested vehicle flashes (seconds)" },
		{ _field_real, "activecamo xray animation cooldown ", "duration to wait before showing another animation (seconds)" },
		{ _field_real, "dead people visible time", "time for which we will see dead team mates (seconds)" },
		{ _field_long_integer, "Motion Tracker Fade Frames", "The number of frames that a non moving target will fade out over on the motion tracker." },
		{ _field_long_integer, "Armor Mod Display Counter", "The number of seconds to show the players armor mod in the HUD (seconds)." },
		{ _field_real, "Broadsword Parallax Velocity Override" },
		{ _field_real, "Pelican Parallax Velocity Override" },
		FIELD_EXPLANATION_EX("Fanfare and Messaging globals", nullptr, FIELD_FLAG_NONE, "Misc settings for fanfares and messages"),
		{ _field_real, "fanfare display time ", "time to display the fanfares (seconds)" },
		{ _field_real, "fanfare speed up display time ", "time to display when higher priority fanfare queues up (seconds)" },
		{ _field_real, "medal score message lifetime ", "message time of the medal score message (seconds)" },
		{ _field_real, "medal score message restart time ", "time to reset message to when messages collide (seconds)" },
		FIELD_EXPLANATION_EX("Remote motion sensor globals", nullptr, FIELD_FLAG_NONE, "Misc settings for the remote motion sensor"),
		{ _field_real, "remote sensor range", "absolute range. (meters)" },
		{ _field_real, "remote sensor weak distance", "distance at which the remote sensor starts to fail (meters)" },
		{ _field_real, "remote sensor failure distance", "distance at which the remote sensor completely fails (meters)" },
		FIELD_EXPLANATION_EX("Damage globals", nullptr, FIELD_FLAG_NONE, "HUD damage settings"),
		{ _field_real, "shield bar recent damage duration", "time taken to drain an entire bar of visible damage. less damage drains faster (seconds)" },
		{ _field_real, "damage indicator response duration", "duration which the damage indicator icons will show in the HUD (seconds)" },
		{ _field_real, "damage flash response duration", "used to determine how long to show the fullscreen damage flash (seconds)" },
		{ _field_tag_reference, "tiled mesh seen when hit in 1st person", &global_bitmap_reference },
		{ _field_real, "number of tiles across the screen" },
		{ _field_real, "mesh alpha multiplier" },
		{ _field_real, "mesh alpha gradient" },
		{ _field_real, "mesh alpha at centre (0..1)" },
		{ _field_real, "mesh alpha at screen edge (0..1)" },
		{ _field_array, "screen transform basis", &screen_transform_basis_array_definition_array },
		FIELD_EXPLANATION_EX("Reticule globals", nullptr, FIELD_FLAG_NONE, "Settings for the weapon reticules"),
		{ _field_real, "Reticule maximum spread angle", "Maximum spread for all weapon reticules. This should be set to the largest spread angle of all the weapons.", "degrees" },
		FIELD_EXPLANATION_EX("Sounds", nullptr, FIELD_FLAG_NONE, "misc global audio stuff"),
		{ _field_tag_reference, "banned vehicle entrance sound", &global_sound_and_looping_sound_reference },
		FIELD_EXPLANATION_EX("High Contrast globals", nullptr, FIELD_FLAG_NONE, "Settings controlling the high contrast hud rendering"),
		{ _field_byte_flags, "High Contrast Flags", &high_contrast_flags },
		FIELD_PAD_EX("pad1", nullptr, FIELD_FLAG_NONE, 3),
		FIELD_EXPLANATION_EX("Dynamic Contrast Settings", nullptr, FIELD_FLAG_NONE, "Settings controlling the dynamic contrast"),
		{ _field_real, "Minimum Threshold", "Minimum brightness value at which the dynamic contrast activates." },
		{ _field_real, "Maximum Threshold", "Brightness value at which the dynamic contrast is fully activated." },
		{ _field_real, "Clamp Threshold", "Clamped brightness value. Can be used to limit the intensity of the dynamic contrast, or enable over strength contrast." },
		FIELD_EXPLANATION_EX("Double Draw Settings", nullptr, FIELD_FLAG_NONE, "Settings controlling the double draw"),
		{ _field_real, "Darken Factor", "Opacity of the black layer." },
		{ _field_real, "Brighten Factor", "Overbrightness factor to apply to the additive layer." },
		FIELD_EXPLANATION_EX("Text", nullptr, FIELD_FLAG_NONE, "Text-related settings"),
		{ _field_block, "string references", &string_file_references_block },
		{ _field_tag_reference, "Interact Message Appear Sound", &global_sound_reference },
		{ _field_tag_reference, "Interact Message Disappear Sound ", &global_sound_reference },
		{ _field_real, "medal fanfare animation lifetime ", "animation time of the medal fanfare (seconds)" },
		{ _field_real, "medal fanfare animation in lifetime ", "animation in time of the medal fanfare (seconds)" },
		{ _field_real, "medal fanfare animation out begin time ", "the time to begin the animation out sequence (seconds)" },
		{ _field_real, "event fanfare animation lifetime ", "animation time of the medal fanfare (seconds)" },
		{ _field_real, "event fanfare animation in lifetime ", "animation in time of the medal fanfare (seconds)" },
		{ _field_real, "event fanfare animation out begin time ", "the time to begin the animation out sequence (seconds)" },
		FIELD_EXPLANATION_EX("Player Training", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_block, "player training data", &player_training_entry_data_block },
		{ _field_terminator }
	};

	STRINGS(HUDMotionSensorGlobalsFlags)
	{
		"show scripted pings at any distance"
	};
	STRING_LIST(HUDMotionSensorGlobalsFlags, HUDMotionSensorGlobalsFlags_strings, _countof(HUDMotionSensorGlobalsFlags_strings));

	STRINGS(high_contrast_flags)
	{
		"disable dynamic contrast",
		"disable double draw"
	};
	STRING_LIST(high_contrast_flags, high_contrast_flags_strings, _countof(high_contrast_flags_strings));



} // namespace blofeld

