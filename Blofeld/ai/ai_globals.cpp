#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(ai_globals, AI_GLOBALS_TAG, ai_globals_block_block )

TAG_BLOCK_FROM_STRUCT(ai_globals_block, 1, ai_globals_struct_definition_struct_definition );

TAG_BLOCK(ai_globals_data_block, 1)
{
	FIELD( _field_real, "AI infantry-on-AI weapon damage scale:[0,1]#Global scale on weapon damage made by AI on other AI" ),
	FIELD( _field_real, "AI vehicle-on-AI weapon damage scale:[0,1]#Global scale on weapon damage made by AI in a vehicle on other AI" ),
	FIELD( _field_real, "AI player vehicle-on-AI weapon damage scale:[0,1]#Global scale on weapon damage made by AI in a vehicle with the player on other AI" ),
	FIELD( _field_real, "danger broadly facing" ),
	FIELD( _field_real, "danger shooting near" ),
	FIELD( _field_real, "danger shooting at" ),
	FIELD( _field_real, "danger extremely close" ),
	FIELD( _field_real, "danger shield damage" ),
	FIELD( _field_real, "danger exetended shield damage" ),
	FIELD( _field_real, "danger body damage" ),
	FIELD( _field_real, "danger extended body damage" ),
	FIELD( _field_tag_reference, "global dialogue tag" ),
	FIELD( _field_string_id, "default mission dialogue sound effect" ),
	FIELD( _field_real, "jump down:wu/tick" ),
	FIELD( _field_real, "jump step:wu/tick" ),
	FIELD( _field_real, "jump crouch:wu/tick" ),
	FIELD( _field_real, "jump stand:wu/tick" ),
	FIELD( _field_real, "jump storey:wu/tick" ),
	FIELD( _field_real, "jump tower:wu/tick" ),
	FIELD( _field_pad, "jump leap placeholder", 4 ),
	FIELD( _field_real, "max jump down height down:wu" ),
	FIELD( _field_real, "max jump down height step:wu" ),
	FIELD( _field_real, "max jump down height crouch:wu" ),
	FIELD( _field_real, "max jump down height stand:wu" ),
	FIELD( _field_real, "max jump down height storey:wu" ),
	FIELD( _field_real, "max jump down height tower:wu" ),
	FIELD( _field_pad, "another leap placeholder", 4 ),
	FIELD( _field_real_bounds, "hoist step:wus" ),
	FIELD( _field_real_bounds, "hoist crouch:wus" ),
	FIELD( _field_real_bounds, "hoist stand:wus" ),
	FIELD( _field_real_bounds, "vault step:wus" ),
	FIELD( _field_real_bounds, "vault crouch:wus" ),
	FIELD( _field_explanation, "PATHFINDING SEARCH RANGES" ),
	FIELD( _field_real, "search range infantry:wus" ),
	FIELD( _field_real, "search range flying:wus" ),
	FIELD( _field_real, "search range vehicle:wus" ),
	FIELD( _field_real, "search range giant:wus" ),
	FIELD( _field_block, "gravemind properties", &ai_globals_gravemind_block_block ),
	FIELD( _field_real, "scary target threhold#A target of this scariness is offically considered scary (by combat dialogue, etc.)" ),
	FIELD( _field_real, "scary weapon threhold#A weapon of this scariness is offically considered scary (by combat dialogue, etc.)" ),
	FIELD( _field_real, "player scariness" ),
	FIELD( _field_real, "berserking actor scariness" ),
	FIELD( _field_real, "kamikazeing actor scariness" ),
	FIELD( _field_real, "invincible scariness#when an actor\'s target is invincible, he is this much more scared" ),
	FIELD( _field_explanation, "RESURRECTION" ),
	FIELD( _field_real, "min death time:seconds#I will be dead for at least this long" ),
	FIELD( _field_real, "projectile distance:wu#If there is a projectile within this distance of me, I\'ll stay dead" ),
	FIELD( _field_real, "idle clump distance:wu#If there is any enemy clump within this distance of me, I\'ll stay dead" ),
	FIELD( _field_real, "dangerous clump distance:wu#If there is any enemy clump with a status higher than idle within this distance of me, I\'ll stay dead" ),
	FIELD( _field_explanation, "TELEPORTATION" ),
	FIELD( _field_real, "cover search duration:seconds#The number of seconds that must elapse before we try to look for a firing point behind cover to teleport to." ),
	FIELD( _field_real, "task direction search duration:seconds#The number of seconds we try to look for a firing point that aligns us with the actor\'s task direction." ),
	FIELD( _field_block, "spawn formations", &ai_globals_formation_block_block ),
	FIELD( _field_block, "squad template folders", &ai_globals_squad_template_folder_block_block ),
	FIELD( _field_block, "performance template folders", &ai_globals_performance_template_folder_block_block ),
	FIELD( _field_block, "custom stimuli", &ai_globals_custom_stimuli_block_block ),
	FIELD( _field_block, "cue templates", &ai_cue_template_block_block ),
	FIELD( _field_explanation, "CLUMP THROTTLING" ),
	FIELD( _field_real, "stop dist:wu#At this distance from the squad, stop." ),
	FIELD( _field_real, "resume dist:wu#At this distance from the squad, start again." ),
	FIELD( _field_real, "min dist:wu#Start throttling back at this distance" ),
	FIELD( _field_real, "max dist:wu#Maximum trottle scale at this distance" ),
	FIELD( _field_real, "min scale:0-1#Minimum throttle value." ),
	FIELD( _field_explanation, "SQUAD PATROLLING" ),
	FIELD( _field_real, "passthrough chance#Chance of passing through a patrol objective without pausing" ),
	FIELD( _field_real, "search phase skip chance#Chance of skipping the search phase when stopped at a patrol objective" ),
	FIELD( _field_real, "patrol transition timeout:seconds#If the squad takes more than this time to get to their new patrol point, cancel it and go on to the next." ),
	FIELD( _field_real, "patrol maneuver timeout:seconds#If the squad takes longer than this time to reposition within a patrol point (e.g. searching and pausing), cancel the point and go on to the next." ),
	FIELD( _field_real_bounds, "patrol search firing point time:seconds#spend this amount of time at a search firing position when in search phase" ),
	FIELD( _field_real, "patrol isolation distance:wus#If you are more than this distance from your nearest squadmate, you are officially isolated." ),
	FIELD( _field_real, "patrol isolation time:seconds#If you are isolated for more than this time, you get deleted." ),
	FIELD( _field_explanation, "KUNGFU CONTROL" ),
	FIELD( _field_real, "kungfu deactivation delay:seconds#When a task is disallowed from shooting, turn it off after this delay" ),
	FIELD( _field_custom, "Presearch Child Counts (0 means no limit)" ),
	FIELD( _field_short_integer, "suppressing fire count" ),
	FIELD( _field_short_integer, "uncover count" ),
	FIELD( _field_short_integer, "leap on cover count" ),
	FIELD( _field_short_integer, "destroy cover count" ),
	FIELD( _field_short_integer, "guard count" ),
	FIELD( _field_short_integer, "investigate count" ),
	FIELD( _field_custom ),
	FIELD( _field_block, "vision traits", &ai_trait_vision_block_block ),
	FIELD( _field_block, "sound traits", &ai_trait_sound_block_block ),
	FIELD( _field_block, "luck traits", &ai_trait_luck_block_block ),
	FIELD( _field_block, "grenade traits", &ai_trait_grenade_block_block ),
	FIELD( _field_custom, "Search Pattern Specification" ),
	FIELD( _field_real, "max decay time" ),
	FIELD( _field_real, "decay time ping" ),
	FIELD( _field_real, "search pattern radius" ),
	FIELD( _field_short_integer, "search pattern shell count" ),
	FIELD( _field_short_bounds, "search pattern cells per shell range" ),
	FIELD( _field_pad, "MOOOOOOO", 2 ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_BLOCK(ai_globals_gravemind_block, 1)
{
	FIELD( _field_real, "min retreat time:secs" ),
	FIELD( _field_real, "ideal retreat time:secs" ),
	FIELD( _field_real, "max retreat time:secs" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(ai_globals_formation_block, k_global_formations_count)
{
	FIELD( _field_tag_reference, "formation^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(ai_globals_squad_template_folder_block, k_global_squad_template_folder_count)
{
	FIELD( _field_string_id, "folder name^" ),
	FIELD( _field_block, "sub folders", &ai_globals_squad_template_sub_folder_block_block ),
	FIELD( _field_block, "templates", &ai_globals_squad_template_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(ai_globals_squad_template_sub_folder_block, k_global_squad_template_folder_count)
{
	FIELD( _field_string_id, "sub folder name^" ),
	FIELD( _field_block, "templates", &ai_globals_squad_template_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(ai_globals_squad_template_block, k_global_squad_templates_count)
{
	FIELD( _field_tag_reference, "squad_template^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(ai_globals_performance_template_folder_block, k_global_performance_template_folder_count)
{
	FIELD( _field_string_id, "folder name^" ),
	FIELD( _field_block, "sub folders", &ai_globals_performance_template_sub_folder_block_block ),
	FIELD( _field_block, "templates", &ai_globals_performance_template_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(ai_globals_performance_template_sub_folder_block, k_global_performance_template_folder_count)
{
	FIELD( _field_string_id, "sub folder name^" ),
	FIELD( _field_block, "templates", &ai_globals_performance_template_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(ai_globals_performance_template_block, k_global_performance_templates_count)
{
	FIELD( _field_tag_reference, "thespian_template^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(ai_globals_custom_stimuli_block, k_max_custom_stimuli_count)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(ai_trait_vision_block, k_num_ai_trait_vision-2)
{
	FIELD( _field_explanation, "Vision Traits" ),
	FIELD( _field_real, "vision distance scale#Scale the distance at which an AI can see their target." ),
	FIELD( _field_real, "vision angle scale#Scale the angles of the AI\'s vision cone." ),
	FIELD( _field_terminator )
};

TAG_BLOCK(ai_trait_sound_block, k_num_ai_trait_sound-2)
{
	FIELD( _field_explanation, "Sound Traits" ),
	FIELD( _field_real, "hearing distance scale#Scale the character\'s hearing distance." ),
	FIELD( _field_terminator )
};

TAG_BLOCK(ai_trait_luck_block, k_num_ai_trait_luck-2)
{
	FIELD( _field_explanation, "Luck Traits" ),
	FIELD( _field_real, "evasion chance scale#Scale the chance of evading fire." ),
	FIELD( _field_real, "grenade dive chance scale#Scale the chance of diving from grenades." ),
	FIELD( _field_real, "broken kamikaze chance scale#Scale the chance of going kamikaze when broken." ),
	FIELD( _field_real, "leader dead retreat chance scale#Scale the chance of retreating when your leader dies." ),
	FIELD( _field_real, "dive retreat chance scale#Scale the chance of retreating after a dive." ),
	FIELD( _field_real, "shield depleted berserk chance scale#Scale the chance of berserking when your shield is depleted." ),
	FIELD( _field_real, "leader abandoned berserk chance scale#Scale the chance of a leader berserking when all his followers die." ),
	FIELD( _field_real, "melee attack delay timer scale#Scale the time between melee attacks." ),
	FIELD( _field_real, "melee chance scale#Scale the chance of meleeing." ),
	FIELD( _field_real, "melee leap delay timer scale#Scale the delay for performing melee leaps." ),
	FIELD( _field_real, "throw grenade delay scale#Scale the time between grenade throws." ),
	FIELD( _field_terminator )
};

TAG_BLOCK(ai_trait_grenade_block, k_num_ai_trait_grenade-2)
{
	FIELD( _field_explanation, "Grenade Traits" ),
	FIELD( _field_real, "velocity scale#Scale the velocity at which AI throws grenades" ),
	FIELD( _field_real, "throw grenade delay scale#Scale the time between grenade throws." ),
	FIELD( _field_real, "don\'t drop grenades chance scale" ),
	FIELD( _field_real, "grenade uncover chance scale" ),
	FIELD( _field_real, "retreat throw grenade chance scale" ),
	FIELD( _field_real, "anti vehicle grenade chance scale" ),
	FIELD( _field_real, "throw grenade chance scale" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(ai_globals_struct_definition)
{
	FIELD( _field_block, "data", &ai_globals_data_block_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

