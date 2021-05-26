#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		ai_globals_group,
		AI_GLOBALS_TAG,
		nullptr,
		INVALID_TAG,
		ai_globals_block );

	TAG_BLOCK_FROM_STRUCT(
		ai_globals_block,
		"ai_globals_block",
		1,
		ai_globals_struct_definition);

	#define AI_GLOBALS_DATA_BLOCK_STRUCT_ID { 0x1D0F80A0, 0xA5BD4A1B, 0x9A070B18, 0xA8706C11 }
	TAG_BLOCK(
		ai_globals_data_block,
		"ai_globals_data_block",
		1,
		"s_ai_globals_data",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		AI_GLOBALS_DATA_BLOCK_STRUCT_ID)
	{
		{ _field_real, "AI infantry-on-AI weapon damage scale", "Global scale on weapon damage made by AI on other AI", nullptr, "[0,1]" },
		{ _field_real, "AI vehicle-on-AI weapon damage scale", "Global scale on weapon damage made by AI in a vehicle on other AI", nullptr, "[0,1]" },
		{ _field_real, "AI player vehicle-on-AI weapon damage scale", "Global scale on weapon damage made by AI in a vehicle with the player on other AI", nullptr, "[0,1]" },
		{ _field_real, "danger broadly facing" },
		{ _field_real, "danger shooting near" },
		{ _field_real, "danger shooting at" },
		{ _field_real, "danger extremely close" },
		{ _field_real, "danger shield damage" },
		{ _field_real, "danger exetended shield damage" },
		{ _field_real, "danger body damage" },
		{ _field_real, "danger extended body damage" },
		{ _field_tag_reference, "global dialogue tag", &ai_dialogue_globals_reference },
		{ _field_string_id, "default mission dialogue sound effect" },
		{ _field_real, "jump down", nullptr, "wu/tick" },
		{ _field_real, "jump step", nullptr, "wu/tick" },
		{ _field_real, "jump crouch", nullptr, "wu/tick" },
		{ _field_real, "jump stand", nullptr, "wu/tick" },
		{ _field_real, "jump storey", nullptr, "wu/tick" },
		{ _field_real, "jump tower", nullptr, "wu/tick" },
		FIELD_PAD("jump leap placeholder", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "max jump down height down", nullptr, "wu" },
		{ _field_real, "max jump down height step", nullptr, "wu" },
		{ _field_real, "max jump down height crouch", nullptr, "wu" },
		{ _field_real, "max jump down height stand", nullptr, "wu" },
		{ _field_real, "max jump down height storey", nullptr, "wu" },
		{ _field_real, "max jump down height tower", nullptr, "wu" },
		FIELD_PAD("another leap placeholder", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real_bounds, "hoist step", nullptr, "wus" },
		{ _field_real_bounds, "hoist crouch", nullptr, "wus" },
		{ _field_real_bounds, "hoist stand", nullptr, "wus" },
		{ _field_real_bounds, "vault step", nullptr, "wus" },
		{ _field_real_bounds, "vault crouch", nullptr, "wus" },
		FIELD_EXPLANATION("PATHFINDING SEARCH RANGES", nullptr, FIELD_FLAG_NONE, "The maximum ranges to which firing point evaluations will do pathfinding searches. INCREASING THESE VALUES WILL ALMOST CERTAINLY HAVE A NEGATIVE IMPACT ON PERFORMANCE."),
		{ _field_real, "search range infantry", nullptr, "wus" },
		{ _field_real, "search range flying", nullptr, "wus" },
		{ _field_real, "search range vehicle", nullptr, "wus" },
		{ _field_real, "search range giant", nullptr, "wus" },
		{ _field_block, "gravemind properties", &ai_globals_gravemind_block },
		{ _field_real, "scary target threhold", "A target of this scariness is offically considered scary (by combat dialogue, etc.)" },
		{ _field_real, "scary weapon threhold", "A weapon of this scariness is offically considered scary (by combat dialogue, etc.)" },
		{ _field_real, "player scariness" },
		{ _field_real, "berserking actor scariness" },
		{ _field_real, "kamikazeing actor scariness" },
		{ _field_real, "invincible scariness", "when an actor's target is invincible, he is this much more scared" },
		FIELD_EXPLANATION("RESURRECTION", nullptr, FIELD_FLAG_NONE, "A few properties to help define when it is safe for a mission critical character to ressurect."),
		{ _field_real, "min death time", "I will be dead for at least this long", "seconds" },
		{ _field_real, "projectile distance", "If there is a projectile within this distance of me, I'll stay dead", "wu" },
		{ _field_real, "idle clump distance", "If there is any enemy clump within this distance of me, I'll stay dead", "wu" },
		{ _field_real, "dangerous clump distance", "If there is any enemy clump with a status higher than idle within this distance of me, I'll stay dead", "wu" },
		FIELD_EXPLANATION("TELEPORTATION", nullptr, FIELD_FLAG_NONE, "A few properties to help define when it is safe for a mission critical character to teleport."),
		{ _field_real, "cover search duration", "The number of seconds that must elapse before we try to look for a firing point behind cover to teleport to.", "seconds" },
		{ _field_real, "task direction search duration", "The number of seconds we try to look for a firing point that aligns us with the actor's task direction.", "seconds" },
		{ _field_block, "spawn formations", &ai_globals_formation_block },
		{ _field_block, "squad template folders", &ai_globals_squad_template_folder_block },
		{ _field_block, "performance template folders", &ai_globals_performance_template_folder_block },
		{ _field_block, "custom stimuli", &ai_globals_custom_stimuli_block },
		{ _field_block, "cue templates", &ai_cue_template_block },
		FIELD_EXPLANATION("CLUMP THROTTLING", nullptr, FIELD_FLAG_NONE, "Some values to help you control how much guys will throttle when they want to stick with the rest of their squad."),
		{ _field_real, "stop dist", "At this distance from the squad, stop.", "wu" },
		{ _field_real, "resume dist", "At this distance from the squad, start again.", "wu" },
		{ _field_real, "min dist", "Start throttling back at this distance", "wu" },
		{ _field_real, "max dist", "Maximum trottle scale at this distance", "wu" },
		{ _field_real, "min scale", "Minimum throttle value.", "0-1" },
		FIELD_EXPLANATION("SQUAD PATROLLING", nullptr, FIELD_FLAG_NONE, "Parameters related to squad patrolling."),
		{ _field_real, "passthrough chance", "Chance of passing through a patrol objective without pausing" },
		{ _field_real, "search phase skip chance", "Chance of skipping the search phase when stopped at a patrol objective" },
		{ _field_real, "patrol transition timeout", "If the squad takes more than this time to get to their new patrol point, cancel it and go on to the next.", "seconds" },
		{ _field_real, "patrol maneuver timeout", "If the squad takes longer than this time to reposition within a patrol point (e.g. searching and pausing), cancel the point and go on to the next.", "seconds" },
		{ _field_real_bounds, "patrol search firing point time", "spend this amount of time at a search firing position when in search phase", "seconds" },
		{ _field_real, "patrol isolation distance", "If you are more than this distance from your nearest squadmate, you are officially isolated.", "wus" },
		{ _field_real, "patrol isolation time", "If you are isolated for more than this time, you get deleted.", "seconds" },
		FIELD_EXPLANATION("KUNGFU CONTROL", nullptr, FIELD_FLAG_NONE, "These parameters control how the kung-fu circle works (i.e. when tasks have kungfu-count associated with them)"),
		{ _field_real, "kungfu deactivation delay", "When a task is disallowed from shooting, turn it off after this delay", "seconds" },
		FIELD_CUSTOM("Presearch Child Counts (0 means no limit)", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_short_integer, "suppressing fire count" },
		{ _field_short_integer, "uncover count" },
		{ _field_short_integer, "leap on cover count" },
		{ _field_short_integer, "destroy cover count" },
		{ _field_short_integer, "guard count" },
		{ _field_short_integer, "investigate count" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_block, "vision traits", &ai_trait_vision_block },
		{ _field_block, "sound traits", &ai_trait_sound_block },
		{ _field_block, "luck traits", &ai_trait_luck_block },
		{ _field_block, "grenade traits", &ai_trait_grenade_block },
		FIELD_CUSTOM("Search Pattern Specification", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_real, "max decay time" },
		{ _field_real, "decay time ping" },
		{ _field_real, "search pattern radius" },
		{ _field_short_integer, "search pattern shell count" },
		{ _field_short_bounds, "search pattern cells per shell range" },
		FIELD_PAD("MOOOOOOO", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	#define AI_GLOBALS_GRAVEMIND_BLOCK_ID { 0x5D6B3B9D, 0x1FC047FE, 0x8CDF19E7, 0xA287DA56 }
	TAG_BLOCK(
		ai_globals_gravemind_block,
		"ai_globals_gravemind_block",
		1,
		"s_ai_globals_gravemind_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		AI_GLOBALS_GRAVEMIND_BLOCK_ID)
	{
		{ _field_real, "min retreat time", nullptr, "secs" },
		{ _field_real, "ideal retreat time", nullptr, "secs" },
		{ _field_real, "max retreat time", nullptr, "secs" },
		{ _field_terminator }
	};

	#define AI_GLOBALS_FORMATION_BLOCK_ID { 0x33FDDAB4, 0x3B8542AB, 0x9FC8A81A, 0x4E45A898 }
	TAG_BLOCK(
		ai_globals_formation_block,
		"ai_globals_formation_block",
		k_global_formations_count,
		"s_ai_globals_formation_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		AI_GLOBALS_FORMATION_BLOCK_ID)
	{
		{ _field_tag_reference, "formation", FIELD_FLAG_INDEX, &formation_reference },
		{ _field_terminator }
	};

	#define AI_GLOBALS_SQUAD_TEMPLATE_FOLDER_BLOCK_STRUCT_ID { 0xFCA99DE5, 0xF2F54C0F, 0xB4F47498, 0x3B390792 }
	TAG_BLOCK(
		ai_globals_squad_template_folder_block,
		"ai_globals_squad_template_folder_block",
		k_global_squad_template_folder_count,
		"s_ai_globals_squad_template_folder_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		AI_GLOBALS_SQUAD_TEMPLATE_FOLDER_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "folder name", FIELD_FLAG_INDEX },
		{ _field_block, "sub folders", &ai_globals_squad_template_sub_folder_block },
		{ _field_block, "templates", &ai_globals_squad_template_block },
		{ _field_terminator }
	};

	#define AI_GLOBALS_SQUAD_TEMPLATE_SUB_FOLDER_BLOCK_STRUCT_ID { 0x411A7443, 0xDC4A4D55, 0xB4E36B7B, 0x017E72E0 }
	TAG_BLOCK(
		ai_globals_squad_template_sub_folder_block,
		"ai_globals_squad_template_sub_folder_block",
		k_global_squad_template_folder_count,
		"s_ai_globals_squad_template_sub_folder_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		AI_GLOBALS_SQUAD_TEMPLATE_SUB_FOLDER_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "sub folder name", FIELD_FLAG_INDEX },
		{ _field_block, "templates", &ai_globals_squad_template_block },
		{ _field_terminator }
	};

	#define AI_GLOBALS_SQUAD_TEMPLATE_BLOCK_ID { 0xB77AC649, 0x5B2E4CA5, 0xA7AC56CB, 0x82C99E1B }
	TAG_BLOCK(
		ai_globals_squad_template_block,
		"ai_globals_squad_template_block",
		k_global_squad_templates_count,
		"s_ai_globals_squad_template_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		AI_GLOBALS_SQUAD_TEMPLATE_BLOCK_ID)
	{
		{ _field_tag_reference, "squad_template", FIELD_FLAG_INDEX, &squad_template_reference },
		{ _field_terminator }
	};

	#define AI_GLOBALS_PERFORMANCE_TEMPLATE_FOLDER_BLOCK_STRUCT_ID { 0x2D27FA1B, 0xF6AD417B, 0x962BF0DA, 0x0AAD11C5 }
	TAG_BLOCK(
		ai_globals_performance_template_folder_block,
		"ai_globals_performance_template_folder_block",
		k_global_performance_template_folder_count,
		"s_ai_globals_performance_template_folder_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		AI_GLOBALS_PERFORMANCE_TEMPLATE_FOLDER_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "folder name", FIELD_FLAG_INDEX },
		{ _field_block, "sub folders", &ai_globals_performance_template_sub_folder_block },
		{ _field_block, "templates", &ai_globals_performance_template_block },
		{ _field_terminator }
	};

	#define AI_GLOBALS_PERFORMANCE_TEMPLATE_SUB_FOLDER_BLOCK_STRUCT_ID { 0xF6323DEC, 0xAC0C4CD9, 0xA340402D, 0x5B7A8313 }
	TAG_BLOCK(
		ai_globals_performance_template_sub_folder_block,
		"ai_globals_performance_template_sub_folder_block",
		k_global_performance_template_folder_count,
		"s_ai_globals_performance_template_sub_folder_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		AI_GLOBALS_PERFORMANCE_TEMPLATE_SUB_FOLDER_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "sub folder name", FIELD_FLAG_INDEX },
		{ _field_block, "templates", &ai_globals_performance_template_block },
		{ _field_terminator }
	};

	#define AI_GLOBALS_PERFORMANCE_TEMPLATE_BLOCK_ID { 0x8C59034C, 0x88C84BA4, 0xA2A249A4, 0xF4376EA3 }
	TAG_BLOCK(
		ai_globals_performance_template_block,
		"ai_globals_performance_template_block",
		k_global_performance_templates_count,
		"s_ai_globals_performance_template_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		AI_GLOBALS_PERFORMANCE_TEMPLATE_BLOCK_ID)
	{
		{ _field_tag_reference, "thespian_template", FIELD_FLAG_INDEX, &performance_template_reference },
		{ _field_terminator }
	};

	#define AI_GLOBALS_CUSTOM_STIMULI_BLOCK_ID { 0xA198B553, 0x7BC942E7, 0xBD3BC6BE, 0x7D86F5DF }
	TAG_BLOCK(
		ai_globals_custom_stimuli_block,
		"ai_globals_custom_stimuli_block",
		k_max_custom_stimuli_count,
		"s_ai_globals_custom_stimulus_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		AI_GLOBALS_CUSTOM_STIMULI_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define AI_TRAIT_VISION_BLOCK_STRUCT_ID { 0x5E1B04EF, 0x590F4CBB, 0x9A08D75A, 0xC4860BF8 }
	TAG_BLOCK(
		ai_trait_vision_block,
		"ai_trait_vision_block",
		k_num_ai_trait_vision-2,
		"s_ai_globals_trait_vision_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		AI_TRAIT_VISION_BLOCK_STRUCT_ID)
	{
		FIELD_EXPLANATION("Vision Traits", nullptr, FIELD_FLAG_NONE, "Traits that affect the AI\'s vision"),
		{ _field_real, "vision distance scale", "Scale the distance at which an AI can see their target." },
		{ _field_real, "vision angle scale", "Scale the angles of the AI's vision cone." },
		{ _field_terminator }
	};

	#define AI_TRAIT_SOUND_BLOCK_STRUCT_ID { 0xFC75461E, 0xA8274506, 0x91D2A359, 0x1B2BB7D6 }
	TAG_BLOCK(
		ai_trait_sound_block,
		"ai_trait_sound_block",
		k_num_ai_trait_sound-2,
		"s_ai_globals_trait_sound_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		AI_TRAIT_SOUND_BLOCK_STRUCT_ID)
	{
		FIELD_EXPLANATION("Sound Traits", nullptr, FIELD_FLAG_NONE, "Traits that affect the AI\'s sound awareness"),
		{ _field_real, "hearing distance scale", "Scale the character's hearing distance." },
		{ _field_terminator }
	};

	#define AI_TRAIT_LUCK_BLOCK_STRUCT_ID { 0xB158B95F, 0xF7DA4CF9, 0xBC3FD0FD, 0x8A9DD1B2 }
	TAG_BLOCK(
		ai_trait_luck_block,
		"ai_trait_luck_block",
		k_num_ai_trait_luck-2,
		"s_ai_globals_trait_luck_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		AI_TRAIT_LUCK_BLOCK_STRUCT_ID)
	{
		FIELD_EXPLANATION("Luck Traits", nullptr, FIELD_FLAG_NONE, "Traits that affect the AI\'s luck"),
		{ _field_real, "evasion chance scale", "Scale the chance of evading fire." },
		{ _field_real, "grenade dive chance scale", "Scale the chance of diving from grenades." },
		{ _field_real, "broken kamikaze chance scale", "Scale the chance of going kamikaze when broken." },
		{ _field_real, "leader dead retreat chance scale", "Scale the chance of retreating when your leader dies." },
		{ _field_real, "dive retreat chance scale", "Scale the chance of retreating after a dive." },
		{ _field_real, "shield depleted berserk chance scale", "Scale the chance of berserking when your shield is depleted." },
		{ _field_real, "leader abandoned berserk chance scale", "Scale the chance of a leader berserking when all his followers die." },
		{ _field_real, "melee attack delay timer scale", "Scale the time between melee attacks." },
		{ _field_real, "melee chance scale", "Scale the chance of meleeing." },
		{ _field_real, "melee leap delay timer scale", "Scale the delay for performing melee leaps." },
		{ _field_real, "throw grenade delay scale", "Scale the time between grenade throws." },
		{ _field_terminator }
	};

	#define AI_TRAIT_GRENADE_BLOCK_STRUCT_ID { 0x0B0F3099, 0x3F954756, 0x83E0F6F3, 0x74E85796 }
	TAG_BLOCK(
		ai_trait_grenade_block,
		"ai_trait_grenade_block",
		k_num_ai_trait_grenade-2,
		"s_ai_globals_trait_grenade_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		AI_TRAIT_GRENADE_BLOCK_STRUCT_ID)
	{
		FIELD_EXPLANATION("Grenade Traits", nullptr, FIELD_FLAG_NONE, "Traits that affect the AI\'s grenade use"),
		{ _field_real, "velocity scale", "Scale the velocity at which AI throws grenades" },
		{ _field_real, "throw grenade delay scale", "Scale the time between grenade throws." },
		{ _field_real, "don't drop grenades chance scale" },
		{ _field_real, "grenade uncover chance scale" },
		{ _field_real, "retreat throw grenade chance scale" },
		{ _field_real, "anti vehicle grenade chance scale" },
		{ _field_real, "throw grenade chance scale" },
		{ _field_terminator }
	};

	#define AI_GLOBALS_STRUCT_DEFINITION_ID { 0xEFB33B8C, 0x80EC4724, 0x9858CAF2, 0x53DD39B3 }
	TAG_STRUCT(
		ai_globals_struct_definition,
		"ai_globals_struct_definition",
		"s_ai_globals_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		AI_GLOBALS_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "data", &ai_globals_data_block },
		{ _field_terminator }
	};



} // namespace blofeld

