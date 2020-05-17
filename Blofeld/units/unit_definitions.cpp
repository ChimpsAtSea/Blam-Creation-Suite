#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(unit_camera_acceleration_displacement_input, 5)
	{
		OPTION("linear velocity"),
		OPTION("linear acceleration"),
		OPTION("yaw"),
		OPTION("pitch"),
		OPTION("roll"),
	};

	TAG_ENUM(unit_camera_flags_definition, 4)
	{
		OPTION("pitch bounds absolute space"),
		OPTION("only collides with environment"),
		OPTION("hides player-unit from camera#the player controlling this camera will not see their unit.  All other cameras will see this unit"),
		OPTION("use aiming vector instead of marker forward#for cameras without tracks that use a marker position, specifies that we use the unit\'s aiming vector instead of the marker\'s forward vector.\nThis results in more accurate aiming and smoother movement when frames are dropped"),
	};

	TAG_ENUM(unit_seat_flags, 32)
	{
		OPTION("invisible#completely enclosed by vehicle"),
		OPTION("locked#when occupied, prevents enemies from entering locked seats"),
		OPTION("driver"),
		OPTION("gunner"),
		OPTION("third person camera"),
		OPTION("allows weapons"),
		OPTION("third person on enter"),
		OPTION("first person camera slaved to gun."),
		OPTION("not valid without driver"),
		OPTION("allow AI noncombatants"),
		OPTION("boarding seat"),
		OPTION("ai firing disabled by max acceleration"),
		OPTION("boarding enters seat"),
		OPTION("boarding need any passenger"),
		OPTION("invalid for player"),
		OPTION("invalid for non-player"),
		OPTION("invalid for hero"),
		OPTION("gunner (player only)"),
		OPTION("invisible under major damage"),
		OPTION("melee instant killable"),
		OPTION("leader preference"),
		OPTION("allows exit and detach"),
		OPTION("blocks headshots"),
		OPTION("exits to ground"),
		OPTION("forward from attachment"),
		OPTION("disallow AI shooting"),
		OPTION("prevents weapon stowing"),
		OPTION("takes top level aoe damage"),
		OPTION("disallow exit#Prevents the unit currently in the seat from exiting regardless of circumstances"),
		OPTION("local aiming"),
		OPTION("pelvis relative attachment"),
		OPTION("apply velocity on death exit"),
	};

	TAG_ENUM(unit_seat_secondary_flags, 10)
	{
		OPTION("biped grab seat"),
		OPTION("low hanging cargo"),
		OPTION("ninja hot seat"),
		OPTION("skip obstacle check"),
		OPTION("search parent for entry marker"),
		OPTION("gunner release aim on exit#The unit\'s aim will no longer be controlled by gunner when it exits"),
		OPTION("fully open before allowing exit"),
		OPTION("finish melee before allowing exit"),
		OPTION("kill parent if unit in seat dies"),
		OPTION("co-pilot#opens and closes the cockpit to allow copilot in (if already closed)"),
	};

	TAG_ENUM(global_ai_seat_type_enum, 6)
	{
		OPTION("NONE"),
		OPTION("passenger"),
		OPTION("gunner"),
		OPTION("small cargo"),
		OPTION("large cargo"),
		OPTION("driver"),
	};

	TAG_ENUM(initial_weapon_position, 2)
	{
		OPTION("primary or backpack"),
		OPTION("secondary"),
	};

	TAG_ENUM(sentryTurretBehaviorFlagDefinition, 5)
	{
		OPTION("performs yaw scanning"),
		OPTION("secondary barrel starts enabled"),
		OPTION("suppress secondary barrel for light vehicles#Can be used to prevent turret from using its big guns on a mongoose"),
		OPTION("only use vehicle range scale if secondary barrel active"),
		OPTION("only use vehicle score bonus if secondary barrel active"),
	};

	TAG_ENUM(unit_flags_part1, 32)
	{
		OPTION("circular aiming"),
		OPTION("destroyed after dying"),
		OPTION("half-speed interpolation"),
		OPTION("fires from camera"),
		OPTION("entrance inside bounding sphere"),
		OPTION("doesn\'t show readied weapon"),
		OPTION("causes passenger dialogue"),
		OPTION("resists pings"),
		OPTION("melee attack is fatal"),
		OPTION("don\'t reface during pings"),
		OPTION("has no aiming"),
		OPTION("impact melee attaches to unit"),
		OPTION("impact melee dies on shields"),
		OPTION("cannot open doors automatically"),
		OPTION("melee attackers cannot attach"),
		OPTION("not instantly killed by melee"),
		OPTION("flashlight power doesnt transfer to weapon"),
		OPTION("runs around flaming"),
		OPTION("top level for AOE damage"),
		OPTION("special cinematic unit"),
		OPTION("ignored by autoaiming"),
		OPTION("shields fry infection forms"),
		OPTION("use velocity as acceleration"),
		OPTION("can dual wield"),
		OPTION("acts as gunner for parent"),
		OPTION("controlled by parent gunner"),
		OPTION("parent\'s primary weapon"),
		OPTION("parent\'s secondary weapon"),
		OPTION("unit has boost"),
		OPTION("unit has vectored thrust"),
		OPTION("allow aim while opening or closing"),
		OPTION("compute acceleration from aiming"),
	};

	TAG_ENUM(unit_flags_part2, 14)
	{
		OPTION("override all pings"),
		OPTION("unit supports bailout"),
		OPTION("flying_or_vehicle_hard_pings_allowed"),
		OPTION("attempt to fire from weapon matching camera#if this unit \"fires from camera\", this flag attempts to match the result, but have the projectile actually come out of the gun"),
		OPTION("treat as vehicle #Treats a non-vehicle unit as a vehicle for gameplay purposes.  Mantis (biped) hack."),
		OPTION("dropped weapons can dissolve"),
		OPTION("hard pings not allowed for driver-less vehicle"),
		OPTION("No friendly bump damage #Unit does not inflict collision damage to friendly units"),
		OPTION("ignores attachment feedback forced hard pings#ignores hard pings forced by attachment of sticky grenade"),
		OPTION("unit appears on radar as dot not sprite#do not try to find a sprite for this unit.  Just draw a dot."),
		OPTION("suppress radar blip"),
		OPTION("do not ignore parents for line of sight tests#ai that are operating this unit will not ignore the unit\'s parents when doing line of sight tests (Mammoth turret hack)"),
		OPTION("do not pass attached AOE damage to children#projectiles attached to this object do not do attached damage to the object\'s children (regular aoe damage is still done to top level aoe children)"),
		OPTION("do not generate AI line of fire pill for unit#even if this vehicle is being driven by a friendly character, don\'t generate a pill for it during ai line of fire checks (for very large vehicles i.e. the lich)"),
	};

	TAG_ENUM(unit_default_teams$2, 9)
	{
		OPTION("default"),
		OPTION("player"),
		OPTION("human"),
		OPTION("covenant"),
		OPTION("brute"),
		OPTION("mule"),
		OPTION("spare"),
		OPTION("covenant_player"),
		OPTION("forerunner"),
	};

	TAG_ENUM(boost_flags, 1)
	{
		OPTION("pegs throttle"),
	};

	TAG_ENUM(unit_item_owner_size_enum, 4)
	{
		OPTION("small"),
		OPTION("medium"),
		OPTION("large"),
		OPTION("huge"),
	};

	TAG_GROUP_INHERIT_FROM_BLOCK(unit, UNIT_TAG, object, OBJECT_TAG, unit_block_block );

	TAG_BLOCK_FROM_STRUCT(unit_block, 1, unit_struct_definition_struct_definition );

	TAG_BLOCK(unit_screen_effect_block, 4)
	{
		FIELD( _field_tag_reference, "screen effect^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(unit_camera_track_block, MAXIMUM_NUMBER_OF_UNIT_CAMERA_TRACKS)
	{
		FIELD( _field_tag_reference, "track" ),
		FIELD( _field_tag_reference, "screen effect" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(unit_camera_acceleration_displacement_block, 1)
	{
		FIELD( _field_real, "maximum camera velocity:wu/s#how quickly the camera can move to a new displacement (if the velocity suddenly changes).\nDuring this time the aim vector for the unit will be inaccurate, so don\'t set this too low.\n0 defaults to infinite." ),
		FIELD( _field_explanation, "" ),
		FIELD( _field_struct, "forward/back", &unit_camera_acceleration_displacement_function_struct_struct_definition ),
		FIELD( _field_struct, "left/right", &unit_camera_acceleration_displacement_function_struct_struct_definition ),
		FIELD( _field_struct, "up/down", &unit_camera_acceleration_displacement_function_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(WeaponSpecificMarkersBlock, WEAPON_SPECIFIC_MARKERS_COUNT)
	{
		FIELD( _field_string_id, "complete weapon name^" ),
		FIELD( _field_string_id, "weapon class" ),
		FIELD( _field_string_id, "weapon name" ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "right hand marker" ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "left hand marker" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(unit_postures_block, MAXIMUM_POSTURES_PER_UNIT)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_useless_pad ),
		FIELD( _field_real_vector_3d, "pill offset" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(dialogue_variant_block, MAXIMUM_DIALOGUE_VARIANTS_PER_UNIT)
	{
		FIELD( _field_short_integer, "variant number#variant number to use this dialogue with (must match the suffix in the permutations on the unit\'s model)" ),
		FIELD( _field_pad, "BQCVEMF", 2 ),
		FIELD( _field_useless_pad ),
		FIELD( _field_tag_reference, "dialogue" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(powered_seat_block, k_powered_seats_count)
	{
		FIELD( _field_real, "driver powerup time:seconds" ),
		FIELD( _field_real, "driver powerdown time:seconds" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(unit_weapon_block, MAXIMUM_INITIAL_WEAPONS_PER_UNIT)
	{
		FIELD( _field_tag_reference, "weapon^" ),
		FIELD( _field_string_id, "variant name" ),
		FIELD( _field_long_enum, "position", &initial_weapon_position ),
		FIELD( _field_real, "maximum firing cone angle:degrees#must be greater than zero for turret to fire" ),
		FIELD( _field_real, "minimum retarget time:seconds#minimum time before autoturret will change targets" ),
		FIELD( _field_real, "blind fire time:seconds#time after losing a target before turret stops blind firing" ),
		FIELD( _field_real, "lead fraction#0.0 = no lead, 1.0 = perfect lead" ),
		FIELD( _field_real_bounds, "engagement range:units#when non-zero, turret will not prioritize targets above or below this range" ),
		FIELD( _field_real, "proximity score multiplier#0.0 = no importance, 2.0 = things that are close are twice as important" ),
		FIELD( _field_real, "direction score multiplier#0.0 = no importance, 2.0 = things in front of you are twice as important" ),
		FIELD( _field_real, "attacker score multiplier#0.0 = no importance, 2.0 = things that attacked you last are twice as important" ),
		FIELD( _field_real, "targeting weight hologram#multiplier" ),
		FIELD( _field_real, "targeting weight auto turret#multiplier" ),
		FIELD( _field_real, "primary fire delay from idle:seconds" ),
		FIELD( _field_real, "secondary fire delay from idle:seconds" ),
		FIELD( _field_real, "caution duration:seconds#how long the turret stays alert after losing a target" ),
		FIELD( _field_real, "alert angular speed max:radians per second#0 = infinite" ),
		FIELD( _field_real, "idle angular speed max:radians per second#0 = infinite" ),
		FIELD( _field_real, "targeting yaw min:degrees#(-180 to 0) how far it can rotate past its initial rotation" ),
		FIELD( _field_real, "targeting yaw max:degrees#(0 to 180) how far it can rotate past its initial rotation" ),
		FIELD( _field_real, "targeting pitch min:degrees#(-180 to 0) how far it can rotate past its initial rotation" ),
		FIELD( _field_real, "targeting pitch max:degrees#(0 to 180) how far it can rotate past its initial rotation" ),
		FIELD( _field_real, "idle scanning yaw min:degrees#(-180 to 0) how far it will look around past its initial rotation" ),
		FIELD( _field_real, "idle scanning yaw max:degrees#(0 to 180) how far it will look around past its initial rotation" ),
		FIELD( _field_real, "idle scanning pitch min:degrees#(-180 to 0) how far it will look around past its initial rotation" ),
		FIELD( _field_real, "idle scanning pitch max:degrees#(0 to 180) how far it will look around past its initial rotation" ),
		FIELD( _field_real, "idle scanning min interest distance:world units#0 = infinite.  Idle scanning won\'t look at something that is closer than this distance" ),
		FIELD( _field_tag_reference, "alert mode effect#effect played on the turret when it goes into alert mode" ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "alert mode effect marker" ),
		FIELD( _field_string_id, "alert mode effect primary scale" ),
		FIELD( _field_string_id, "alert mode effect secondary scale" ),
		FIELD( _field_block, "sentry properties", &SentryPropertiesBlock_block ),
		FIELD( _field_real, "target camouflage threshold# 0 - 1 : target when players camo level falls below this threshold, full camo = 1" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(SentryPropertiesBlock, 1)
	{
		FIELD( _field_byte_flags, "behavior", &sentryTurretBehaviorFlagDefinition ),
		FIELD( _field_pad, "flagPad", 3 ),
		FIELD( _field_real, "sight cone angle:degrees#the cone that this sentry actually sees with; only used when scanning" ),
		FIELD( _field_real, "alert range:world units#how far the sentry can see (sentry will track enemies within alert range, but not necessarily fire)" ),
		FIELD( _field_real, "attack range:world units#how far the sentry can shoot" ),
		FIELD( _field_real, "attack range score multiplier#0 = No preference to targets in attack range; 0.5 = Targets in attack range get 50% score bonus" ),
		FIELD( _field_real, "light vehicle range scale#0 = Default of 1; 1.5 = light vehicles are attacked at 1.5x attack range" ),
		FIELD( _field_real, "heavy vehicle range scale#0 = Default of 1; 1.5 = light vehicles are attacked at 1.5x attack range" ),
		FIELD( _field_real, "flying vehicle range scale#0 = Default of 1; 1.5 = light vehicles are attacked at 1.5x attack range" ),
		FIELD( _field_real, "light vehicle score bonus#0 = No bonus preference for light vehicles; 0.5 = 50% score bonus for light vehicles" ),
		FIELD( _field_real, "heavy vehicle score bonus#0 = No bonus preference for heavy vehicles; 0.5 = 50% score bonus for heavy vehicles" ),
		FIELD( _field_real, "flying vehicle score bonus#0 = No bonus preference for flying vehicles; 0.5 = 50% score bonus for flying vehicles" ),
		FIELD( _field_real, "primary fire time:seconds#how long the sentry waits before using its primary weapon barrel" ),
		FIELD( _field_real, "secondary fire time:seconds#how long the sentry waits before using its secondary weapon barrel" ),
		FIELD( _field_tag_reference, "player entered alert range sound#1st person sound to play when targeted player enters sentry\'s alert range" ),
		FIELD( _field_tag_reference, "player exited alert range sound#1st person sound to play when targeted player leaves sentry\'s alert range" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(unit_seat_block, MAXIMUM_SEATS_PER_UNIT_DEFINITION)
	{
		FIELD( _field_long_flags, "flags", &unit_seat_flags ),
		FIELD( _field_long_flags, "secondary flags", &unit_seat_secondary_flags ),
		FIELD( _field_old_string_id, "label^" ),
		FIELD( _field_custom ),
		FIELD( _field_old_string_id, "marker name" ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "entry marker(s) name" ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "ui marker name" ),
		FIELD( _field_string_id, "ui navpoint name" ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "boarding grenade marker" ),
		FIELD( _field_string_id, "boarding grenade string" ),
		FIELD( _field_string_id, "boarding melee string" ),
		FIELD( _field_string_id, "in-seat string" ),
		FIELD( _field_real_fraction, "ping scale#nathan is too lazy to make pings for each seat." ),
		FIELD( _field_useless_pad ),
		FIELD( _field_real, "turnover time:seconds#how much time it takes to evict a rider from a flipped vehicle" ),
		FIELD( _field_explanation, "seat acceleration spring" ),
		FIELD( _field_tag_reference, "seat acceleration" ),
		FIELD( _field_real, "AI scariness" ),
		FIELD( _field_enum, "ai seat type", &global_ai_seat_type_enum ),
		FIELD( _field_short_block_index, "boarding seat" ),
		FIELD( _field_block, "additional boarding seats#additional seats to eject", &boarding_seat_block_block ),
		FIELD( _field_real_fraction, "listener interpolation factor#how far to interpolate listener position from camera to occupant\'s head" ),
		FIELD( _field_explanation, "speed dependant turn rates" ),
		FIELD( _field_real_bounds, "yaw rate bounds:degrees per second" ),
		FIELD( _field_real_bounds, "pitch rate bounds:degrees per second" ),
		FIELD( _field_real, "pitch interpolation time:seconds to interpolate#0 means use default 17" ),
		FIELD( _field_real, "min speed reference:world units/sec#Initial t is computed from velocity/(max speed - min speed)" ),
		FIELD( _field_real, "max speed reference" ),
		FIELD( _field_real, "speed exponent#if >0, t is then modified by raising to this exponent and result is used to linearly interpolate yaw/pitch rates" ),
		FIELD( _field_useless_pad ),
		FIELD( _field_explanation, "camera fields" ),
		FIELD( _field_struct, "unit camera", &unit_camera_struct_struct_definition ),
		FIELD( _field_tag_reference, "hud screen reference" ),
		FIELD( _field_string_id, "enter seat string" ),
		FIELD( _field_useless_pad ),
		FIELD( _field_angle, "yaw minimum" ),
		FIELD( _field_angle, "yaw maximum" ),
		FIELD( _field_angle, "yaw minimum for AI operator#only applies when an NPC is considering using this seat" ),
		FIELD( _field_angle, "yaw maximum for AI operator#only applies when an NPC is considering using this seat" ),
		FIELD( _field_tag_reference, "built-in gunner" ),
		FIELD( _field_useless_pad ),
		FIELD( _field_explanation, "entry fields" ),
		FIELD( _field_real, "entry radius#how close to the entry marker a unit must be" ),
		FIELD( _field_angle, "entry marker cone angle#angle from marker forward the unit must be" ),
		FIELD( _field_angle, "entry marker facing angle#angle from unit facing the marker must be" ),
		FIELD( _field_real, "maximum relative velocity" ),
		FIELD( _field_useless_pad ),
		FIELD( _field_real, "open time:seconds" ),
		FIELD( _field_real, "close time:seconds" ),
		FIELD( _field_string_id, "open function name#creates an object function with this name that you can use to query the open state of this seat" ),
		FIELD( _field_string_id, "opening function name#goes from 0 to 1 over the course of opening and stays at 1 while open.  Drops to 0 immediately when closing starts" ),
		FIELD( _field_string_id, "closing function name#goes from 0 to 1 over the course of closing and stays at 1 while closed.  Drops to 0 immediately when opening starts" ),
		FIELD( _field_string_id, "invisible seat region" ),
		FIELD( _field_long_integer, "runtime invisible seat region index*" ),
		FIELD( _field_explanation, "seat death grab crate" ),
		FIELD( _field_tag_reference, "seat death grab crate" ),
		FIELD( _field_string_id, "Seat Selection String" ),
		FIELD( _field_real, "bailout velocity:wu/s#if exiting in bailout fashion, how much velocity to add in the entry_marker\'s forward direction" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(boarding_seat_block, MAXIMUM_SEATS_PER_UNIT_DEFINITION)
	{
		FIELD( _field_short_block_index, "seat^" ),
		FIELD( _field_pad, "PAD", 2 ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(unit_struct_definition)
{
		FIELD( _field_struct, "object", &object_struct_definition_struct_definition ),
		FIELD( _field_custom, "$$$ UNIT $$$" ),
		FIELD( _field_long_flags, "flags", &unit_flags_part1 ),
		FIELD( _field_long_flags, "flags2", &unit_flags_part2 ),
		FIELD( _field_enum, "default team", &unit_default_teams ),
		FIELD( _field_enum, "constant sound volume", &ai_sound_volume_enum ),
		FIELD( _field_tag_reference, "hologram unit reference" ),
		FIELD( _field_block, "campaign metagame bucket", &campaign_metagame_bucket_block_block ),
		FIELD( _field_block, "screen effects", &unit_screen_effect_block_block ),
		FIELD( _field_real, "camera stiffness" ),
		FIELD( _field_struct, "unit camera", &unit_camera_struct_struct_definition ),
		FIELD( _field_explanation, "sync action camera fields" ),
		FIELD( _field_struct, "sync action camera", &unit_camera_struct_struct_definition ),
		FIELD( _field_tag_reference, "assasination start damage response" ),
		FIELD( _field_tag_reference, "assassination weapon" ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "assassination weapon stow marker#the anchor we attach the knife to when we stow it" ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "assassination weapon out marker#the anchor we attach the knife to when we pull it out" ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "assassination weapon anchor marker#the marker on the knife that we anchor to the biped" ),
		FIELD( _field_tag_reference, "seat acceleration" ),
		FIELD( _field_custom, "pings" ),
		FIELD( _field_real, "soft ping threshold:[0,1]" ),
		FIELD( _field_real, "soft ping interrupt time:seconds" ),
		FIELD( _field_real, "hard ping threshold:[0,1]" ),
		FIELD( _field_real, "hard ping interrupt time:seconds" ),
		FIELD( _field_real, "soft death direction speed threshold:wu/s#moving faster than this means you will soft death in the movement direction. zero defaults to damage direction." ),
		FIELD( _field_real, "hard death threshold:[0,1]" ),
		FIELD( _field_real, "feign death threshold:[0,1]" ),
		FIELD( _field_real, "feign death time:seconds" ),
		FIELD( _field_real, "pain screen duration:seconds|CCBBAA#The duration of the pain function\n0 defaults to 0.5" ),
		FIELD( _field_real, "pain screen region fade out duration:seconds|CCBBAA#The time it takes to fade out a damage region that is no longer the most recent damage region to be hit" ),
		FIELD( _field_real_fraction, "pain screen region fade out weight threshold:[0,1]#The threshold weight below which the focus channel must fall before we can cross fade to another region." ),
		FIELD( _field_angle, "pain screen angle tolerance:degrees|CCBBAA#The tolerance angle between next and previous damage directions, below which we randomly vary the ping direction." ),
		FIELD( _field_angle, "pain screen angle randomness:degrees|CCBBAA#The maximum random angle to vary the incoming ping direction by if it\'s too close to the previous ping." ),
		FIELD( _field_real, "defensive screen duration:seconds#The duration of the defensive function\n0 defaults to 2.0" ),
		FIELD( _field_real_fraction, "defensive screen scrub fallback fraction:[0,1]#When receiving multiple pings, this is the min percentage of the defensive screen scrub value will fallback to." ),
		FIELD( _field_custom ),
		FIELD( _field_real, "distance of dive anim:world units#this must be set to tell the AI how far it should expect our dive animation to move us" ),
		FIELD( _field_real_fraction, "terminal velocity fall ratio#ratio of airborne_arc animation to switch off falling overlay" ),
		FIELD( _field_custom, "stun" ),
		FIELD( _field_real, "stun movement penalty:[0,1]#1.0 prevents moving while stunned" ),
		FIELD( _field_real, "stun turning penalty:[0,1]#1.0 prevents turning while stunned" ),
		FIELD( _field_real, "stun jumping penalty:[0,1]#1.0 prevents jumping while stunned" ),
		FIELD( _field_real, "minimum stun time:seconds#all stunning damage will last for at least this long" ),
		FIELD( _field_real, "maximum stun time:seconds#no stunning damage will last for longer than this" ),
		FIELD( _field_custom ),
		FIELD( _field_real, "feign death chance:[0,1]" ),
		FIELD( _field_real, "feign repeat chance:[0,1]" ),
		FIELD( _field_tag_reference, "spawned turret character#automatically created character when this unit is driven" ),
		FIELD( _field_short_bounds, "spawned actor count#number of actors which we spawn" ),
		FIELD( _field_real, "spawned velocity#velocity at which we throw spawned actors" ),
		FIELD( _field_custom, "aiming/looking" ),
		FIELD( _field_string_id, "target aiming pivot marker name#set this to have your weapon barrel point at its calcualed target instead of matching the aiming of the unit controlling it.  This marker should be along the barrel at point that doesn\'t move when the barrel pitches up and down." ),
		FIELD( _field_angle, "aiming velocity maximum:degrees per second" ),
		FIELD( _field_angle, "aiming acceleration maximum:degrees per second squared" ),
		FIELD( _field_real_fraction, "casual aiming modifier:[0,1]" ),
		FIELD( _field_angle, "looking velocity maximum:degrees per second" ),
		FIELD( _field_angle, "looking acceleration maximum:degrees per second squared" ),
		FIELD( _field_custom ),
		FIELD( _field_real, "object velocity maximum!:world units per second#Debug value for object velocity that corresponds to a blend screen weight of 1, 0 defaults to 5.0" ),
		FIELD( _field_string_id, "right_hand_node#where the primary weapon is attached" ),
		FIELD( _field_string_id, "left_hand_node#where the seconday weapon is attached (for dual-pistol modes)" ),
		FIELD( _field_struct, "more damn nodes", &unit_additional_node_names_struct_struct_definition ),
		FIELD( _field_enum, "melee damage class", &global_melee_class_enum_definition ),
		FIELD( _field_pad, "PAD", 2 ),
		FIELD( _field_custom, "melee damage" ),
		FIELD( _field_tag_reference, "melee damage" ),
		FIELD( _field_tag_reference, "native melee override#when set, characters will melee with these settings rather than their actual held weapon. (for characters that melee with an off hand)" ),
		FIELD( _field_struct, "your momma", &unit_boarding_melee_struct_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_enum, "motion sensor blip size", &global_chud_blip_type_definition ),
		FIELD( _field_enum, "item owner size", &unit_item_owner_size_enum ),
		FIELD( _field_string_id, "equipment variant name" ),
		FIELD( _field_string_id, "grounded equipment variant name" ),
		FIELD( _field_block, "postures", &unit_postures_block_block ),
		FIELD( _field_block, "Hud audio cues", &hud_unit_sound_block_block ),
		FIELD( _field_block, "dialogue variants", &dialogue_variant_block_block ),
		FIELD( _field_custom, "standard grenade throw" ),
		FIELD( _field_real, "grenade angle:degrees" ),
		FIELD( _field_real, "grenade angle max elevation:degrees" ),
		FIELD( _field_real, "grenade angle min elevation:degrees" ),
		FIELD( _field_real, "grenade velocity:world units per second" ),
		FIELD( _field_custom ),
		FIELD( _field_custom, "sprinting grenade throw" ),
		FIELD( _field_real, "grenade angle (sprinting):degrees" ),
		FIELD( _field_real, "grenade angle max elevation (sprinting):degrees" ),
		FIELD( _field_real, "grenade angle min elevation (sprinting):degrees" ),
		FIELD( _field_real, "grenade velocity (sprinting):world units per second" ),
		FIELD( _field_custom ),
		FIELD( _field_custom, "primary weapon toss" ),
		FIELD( _field_real, "weapon angle:degrees" ),
		FIELD( _field_real, "weapon angle max elevation:degrees" ),
		FIELD( _field_real, "weapon angle min elevation:degrees" ),
		FIELD( _field_real, "weapon velocity:world units per second" ),
		FIELD( _field_custom ),
		FIELD( _field_enum, "grenade type", &global_grenade_type_enum ),
		FIELD( _field_short_integer, "grenade count" ),
		FIELD( _field_block, "powered seats", &powered_seat_block_block ),
		FIELD( _field_block, "weapons", &unit_weapon_block_block ),
		FIELD( _field_block, "target tracking", &global_target_tracking_parameters_block_block ),
		FIELD( _field_block, "seats", &unit_seat_block_block ),
		FIELD( _field_custom, "open/close" ),
		FIELD( _field_real, "opening time:s#how long the unit takes to open when the hs_function unit_open is called\nThe current open state can be retrieved from the object function unit_open" ),
		FIELD( _field_real, "closing time:s#you don\'t have to go home, but you can\'t stay here" ),
		FIELD( _field_custom ),
		FIELD( _field_custom, "EMP Disabling" ),
		FIELD( _field_real, "emp disabled time:seconds" ),
		FIELD( _field_real, "emp disabled time (PVP):seconds #Set to -1 for not disabled in MP but disabled in SP" ),
		FIELD( _field_tag_reference, "emp disabled effect" ),
		FIELD( _field_custom ),
		FIELD( _field_custom, "Boost" ),
		FIELD( _field_struct, "boost", &unit_boost_struct_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_explanation, "Lipsync" ),
		FIELD( _field_struct, "lipsync", &unit_lipsync_scales_struct_struct_definition ),
		FIELD( _field_explanation, "Exit and Detach" ),
		FIELD( _field_tag_reference, "exit and detach damage" ),
		FIELD( _field_tag_reference, "exit and detach weapon" ),
		FIELD( _field_explanation, "Experience" ),
		FIELD( _field_short_integer, "experience for kill" ),
		FIELD( _field_short_integer, "experience for assist" ),
		FIELD( _field_tag_reference, "hero assist equipment#this is where you stick an equipment that the biped will always have, to implement the bizarrely named hero assist" ),
		FIELD( _field_real, "bailout threshold:wu/s#the speed above which units will bail out of a vehicle instead of just exiting" ),
		FIELD( _field_custom ),
		FIELD( _field_real_fraction, "iron sight weapon dampening:(0-1)#when using iron sights, how much to scale the weapon overlays to steady the gun (0 = rock steady, 1= no dampening)" ),
		FIELD( _field_custom, "Birthing" ),
		FIELD( _field_struct, "birth", &unit_birth_struct_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_terminator )
};

TAG_STRUCT(unit_camera_struct)
{
		FIELD( _field_custom, "Unit Camera" ),
		FIELD( _field_word_flags, "flags", &unit_camera_flags_definition ),
		FIELD( _field_pad, "doh", 2 ),
		FIELD( _field_custom ),
		FIELD( _field_old_string_id, "camera marker name" ),
		FIELD( _field_angle, "pitch auto-level" ),
		FIELD( _field_angle_bounds, "pitch range" ),
		FIELD( _field_block, "camera tracks", &unit_camera_track_block_block ),
		FIELD( _field_angle, "pitch minimum spring" ),
		FIELD( _field_angle, "pitch mmaximum spring" ),
		FIELD( _field_angle, "spring velocity" ),
		FIELD( _field_angle, "look acceleration:deg/s/s#if non-zero, limits the change in look velocity per second while the user is pushing the look stick in the current direction of looking" ),
		FIELD( _field_angle, "look deceleration:deg/s/s#if non-zero, limits the change in look velocity per second while the user is not pushing the look stick or changing directions" ),
		FIELD( _field_real_fraction, "look acc smoothing fraction#if non-zero, when the desired velocity change is less than this fraction of the acceleration, starts interpolating the maximum acceleration towards zero.\nYou can think of this as a time in seconds where if the velocity would reach its target in this amount of time or less, it will start taking longer." ),
		FIELD( _field_angle, "override fov#if non-zero, overrides the FOV set in the unit or globals" ),
		FIELD( _field_struct, "camera obstruction", &camera_obstruction_struct_struct_definition ),
		FIELD( _field_block, "camera acceleration", &unit_camera_acceleration_displacement_block_block ),
		FIELD( _field_block, "move stick overrides", &gamepad_stick_info_block_block ),
		FIELD( _field_block, "look stick overrides", &gamepad_stick_info_block_block ),
		FIELD( _field_custom ),
		FIELD( _field_terminator )
};

TAG_STRUCT(unit_camera_acceleration_displacement_function_struct)
{
		FIELD( _field_char_enum, "Input Variable", &unit_camera_acceleration_displacement_input ),
		FIELD( _field_pad, "blah", 3 ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "mapping", &mapping_function_struct_definition ),
		FIELD( _field_real, "maximum value#for linear velocity; this is wu/s\nfor linear acceleration; this is the fraction of the seat acceleration\nfor angular velocity; this is deg/s" ),
		FIELD( _field_real, "camera scale (axial)#scale factor used when this acceleration component is along the axis of the forward vector of the camera" ),
		FIELD( _field_real, "camera scale (perpendicular)#scale factor used when this acceleration component is perpendicular to the camera" ),
		FIELD( _field_terminator )
};

TAG_STRUCT(unit_additional_node_names_struct)
{
		FIELD( _field_string_id, "preferred_gun_node#if found, use this gun marker" ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "preferred_grenade_marker#if found, use this marker to attach live grenades to" ),
		FIELD( _field_explanation, "Weapon Specific Markers" ),
		FIELD( _field_block, "weapon specific markers", &WeaponSpecificMarkersBlock_block ),
		FIELD( _field_terminator )
};

TAG_STRUCT(unit_boarding_melee_struct)
{
		FIELD( _field_tag_reference, "boarding melee damage" ),
		FIELD( _field_tag_reference, "boarding melee response" ),
		FIELD( _field_tag_reference, "eviction melee damage" ),
		FIELD( _field_tag_reference, "eviction melee response" ),
		FIELD( _field_tag_reference, "landing melee damage" ),
		FIELD( _field_tag_reference, "flurry melee damage" ),
		FIELD( _field_tag_reference, "obstacle smash damage" ),
		FIELD( _field_tag_reference, "assassination primary damage" ),
		FIELD( _field_tag_reference, "assassination ragdoll damage{assassination damage}" ),
		FIELD( _field_terminator )
};

TAG_STRUCT(unit_boost_struct)
{
		FIELD( _field_tag_reference, "boost collision damage" ),
		FIELD( _field_long_flags, "flags", &boost_flags ),
		FIELD( _field_real, "boost peak power" ),
		FIELD( _field_real, "boost rise time:s#if the trigger is fully down, takes this long to reach peak power" ),
		FIELD( _field_real, "boost fall time:s#if the trigger is let go (or peak time expires), takes this long to reach 0 power" ),
		FIELD( _field_real, "boost power per second#1, means you burn all your power in one sec.  .1 means you can boost for 10 seconds." ),
		FIELD( _field_real, "boost low warning threshold" ),
		FIELD( _field_real, "recharge rate#1 means you recharge fully in 1 second.  .1 means you rechage fully in 10 seconds" ),
		FIELD( _field_real, "recharge delay:s#how long do you have to be off the tirgger for before boost starts recharging" ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "trigger to boost", &mapping_function_struct_definition ),
		FIELD( _field_terminator )
};

TAG_STRUCT(unit_lipsync_scales_struct)
{
		FIELD( _field_real_fraction, "attack weight" ),
		FIELD( _field_real_fraction, "decay weight" ),
		FIELD( _field_terminator )
};

TAG_STRUCT(unit_birth_struct)
{
		FIELD( _field_short_block_index, "seat^" ),
		FIELD( _field_pad, "PAD", 2 ),
		FIELD( _field_string_id, "birthing region#if found, this region will be set to destroyed during birth" ),
		FIELD( _field_terminator )
};

} // namespace blofeld

