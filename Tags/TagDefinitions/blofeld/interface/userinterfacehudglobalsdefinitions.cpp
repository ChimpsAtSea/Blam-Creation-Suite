#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(user_interface_hud_globals_definition, USER_INTERFACE_HUD_GLOBALS_DEFINITION_TAG, user_interface_hud_globals_definition_block_block );

	V5_TAG_BLOCK_FROM_STRUCT(user_interface_hud_globals_definition_block, 1, user_interface_hud_globals_definition_struct_definition_struct_definition );

	V5_TAG_ARRAY(screen_transform_basis_array_definition, 9)
	{
		{ _field_real_point_2d, "screen transform basis element" },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(user_interface_hud_globals_definition_struct_definition)
	{
		{ _field_explanation, "Motion sensor globals", "Misc settings for the motion sensor" },
		{ _field_byte_flags, "flags", &HUDMotionSensorGlobalsFlags },
		{ _field_pad, "pad0", 3 },
		{ _field_real, "active camo appears as enemy when lower than#active Camo users show up as enemy when active camo is lower than this value (multiplayer)" },
		{ _field_real, "height classified as above#relative height at which something is above (meters)" },
		{ _field_real, "height classified as below#relative height at which something is below (meters)" },
		{ _field_real, "threshold speed#speed at which stuff is visible on the sensor (meters/sec)" },
		{ _field_real, "upwards movement scaling#multiplier for vertical speed upwards (multiplier)" },
		{ _field_real, "downwards movement scaling#multiplier for vertical speed downwards (multiplier)" },
		{ _field_real, "crouching movement scaling#multiplier for speed when crouching (multiplier)" },
		{ _field_real, "normal detection range extension#how far off the edge of the radar we can detect things (multiplier)" },
		{ _field_real, "vehicle detection range extension#how far off the edge of the radar we can detect vehicles (multiplier)" },
		{ _field_real, "vehicle radar range#special range boost used for large flying vehicles (meters)" },
		{ _field_real, "mech radar range#override for mech/mantis" },
		{ _field_real, "vehicle navigation marker range detection#range at which hud nav markers will show (meters)" },
		{ _field_real, "vehicle contested flash time#rate at which a contested vehicle flashes (seconds)" },
		{ _field_real, "activecamo xray animation cooldown #duration to wait before showing another animation (seconds)" },
		{ _field_real, "dead people visible time#time for which we will see dead team mates (seconds)" },
		{ _field_long_integer, "Motion Tracker Fade Frames#The number of frames that a non moving target will fade out over on the motion tracker." },
		{ _field_long_integer, "Armor Mod Display Counter#The number of seconds to show the players armor mod in the HUD (seconds)." },
		{ _field_real, "Broadsword Parallax Velocity Override" },
		{ _field_real, "Pelican Parallax Velocity Override" },
		{ _field_explanation, "Fanfare and Messaging globals", "Misc settings for fanfares and messages" },
		{ _field_real, "fanfare display time #time to display the fanfares (seconds)" },
		{ _field_real, "fanfare speed up display time #time to display when higher priority fanfare queues up (seconds)" },
		{ _field_real, "medal score message lifetime #message time of the medal score message (seconds)" },
		{ _field_real, "medal score message restart time #time to reset message to when messages collide (seconds)" },
		{ _field_explanation, "Remote motion sensor globals", "Misc settings for the remote motion sensor" },
		{ _field_real, "remote sensor range#absolute range. (meters)" },
		{ _field_real, "remote sensor weak distance#distance at which the remote sensor starts to fail (meters)" },
		{ _field_real, "remote sensor failure distance#distance at which the remote sensor completely fails (meters)" },
		{ _field_explanation, "Damage globals", "HUD damage settings" },
		{ _field_real, "shield bar recent damage duration#time taken to drain an entire bar of visible damage. less damage drains faster (seconds)" },
		{ _field_real, "damage indicator response duration#duration which the damage indicator icons will show in the HUD (seconds)" },
		{ _field_real, "damage flash response duration#used to determine how long to show the fullscreen damage flash (seconds)" },
		{ _field_tag_reference, "tiled mesh seen when hit in 1st person", &global_bitmap_reference },
		{ _field_real, "number of tiles across the screen" },
		{ _field_real, "mesh alpha multiplier" },
		{ _field_real, "mesh alpha gradient" },
		{ _field_real, "mesh alpha at centre (0..1)" },
		{ _field_real, "mesh alpha at screen edge (0..1)" },
		{ _field_array, "screen transform basis", &screen_transform_basis_array_definition_array },
		{ _field_explanation, "Reticule globals", "Settings for the weapon reticules" },
		{ _field_real, "Reticule maximum spread angle:degrees#Maximum spread for all weapon reticules. This should be set to the largest spread angle of all the weapons." },
		{ _field_explanation, "Sounds", "misc global audio stuff" },
		{ _field_tag_reference, "banned vehicle entrance sound", &global_sound_and_looping_sound_reference },
		{ _field_explanation, "High Contrast globals", "Settings controlling the high contrast hud rendering" },
		{ _field_byte_flags, "High Contrast Flags", &high_contrast_flags },
		{ _field_pad, "pad1", 3 },
		{ _field_explanation, "Dynamic Contrast Settings", "Settings controlling the dynamic contrast" },
		{ _field_real, "Minimum Threshold#Minimum brightness value at which the dynamic contrast activates." },
		{ _field_real, "Maximum Threshold#Brightness value at which the dynamic contrast is fully activated." },
		{ _field_real, "Clamp Threshold#Clamped brightness value. Can be used to limit the intensity of the dynamic contrast, or enable over strength contrast." },
		{ _field_explanation, "Double Draw Settings", "Settings controlling the double draw" },
		{ _field_real, "Darken Factor#Opacity of the black layer." },
		{ _field_real, "Brighten Factor#Overbrightness factor to apply to the additive layer." },
		{ _field_explanation, "Text", "Text-related settings" },
		{ _field_block, "string references", &string_file_references_block },
		{ _field_tag_reference, "Interact Message Appear Sound", &global_sound_reference },
		{ _field_tag_reference, "Interact Message Disappear Sound ", &global_sound_reference },
		{ _field_real, "medal fanfare animation lifetime #animation time of the medal fanfare (seconds)" },
		{ _field_real, "medal fanfare animation in lifetime #animation in time of the medal fanfare (seconds)" },
		{ _field_real, "medal fanfare animation out begin time #the time to begin the animation out sequence (seconds)" },
		{ _field_real, "event fanfare animation lifetime #animation time of the medal fanfare (seconds)" },
		{ _field_real, "event fanfare animation in lifetime #animation in time of the medal fanfare (seconds)" },
		{ _field_real, "event fanfare animation out begin time #the time to begin the animation out sequence (seconds)" },
		{ _field_explanation, "Player Training", "" },
		{ _field_block, "player training data", &player_training_entry_data_block_block },
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

