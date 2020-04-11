#pragma once

enum e_hs_player
{
	_hs_player_player0 = 0,
	_hs_player_player1,
	_hs_player_player2,
	_hs_player_player3,
	_hs_player_player4,
	_hs_player_player5,
	_hs_player_player6,
	_hs_player_player7,
	_hs_player_player8,
	_hs_player_player9,
	_hs_player_player10,
	_hs_player_player11,
	_hs_player_player12,
	_hs_player_player13,
	_hs_player_player14,
	_hs_player_player15,
	hs_player_count
};

enum e_hs_game_difficulty
{
	_hs_game_difficulty_easy,
	_hs_game_difficulty_normal,
	_hs_game_difficulty_heroic,
	_hs_game_difficulty_legendary,
	hs_game_difficulty_count
};

enum e_hs_team
{
	_hs_team_default,
	_hs_team_player,
	_hs_team_human,
	_hs_team_covenant,
	_hs_team_brute,
	_hs_team_mule,
	_hs_team_spare,
	_hs_team_covenant_player,
	hs_team_count
};

enum e_hs_mp_team
{
	_hs_mp_team_red,
	_hs_mp_team_blue,
	_hs_mp_team_green,
	_hs_mp_team_yellow,
	_hs_mp_team_purple,
	_hs_mp_team_orange,
	_hs_mp_team_brown,
	_hs_mp_team_grey,
	hs_mp_team_count
};

enum e_hs_controller
{
	_hs_controller_controller1,
	_hs_controller_controller2,
	_hs_controller_controller3,
	_hs_controller_controller4,
	hs_controller_count
};

enum e_hs_button_press
{
	_hs_button_press_standard,
	_hs_button_press_community1,
	_hs_button_press_boxer,
	_hs_button_press_green_thumb,
	_hs_button_press_professional,
	_hs_button_press_evolved,
	_hs_button_press_community2,
	hs_button_press_count
};

enum e_hs_joystick_preset
{
	_hs_joystick_preset_standard,
	_hs_joystick_preset_south_paw,
	_hs_joystick_preset_legacy,
	_hs_joystick_preset_legacy_south_paw,
	hs_joystick_preset_count
};

enum e_hs_player_color
{
	_hs_player_color_00,
	_hs_player_color_01,
	_hs_player_color_02,
	_hs_player_color_03,
	_hs_player_color_04,
	_hs_player_color_05,
	_hs_player_color_06,
	_hs_player_color_07,
	_hs_player_color_08,
	_hs_player_color_09,
	_hs_player_color_10,
	_hs_player_color_11,
	_hs_player_color_12,
	_hs_player_color_13,
	_hs_player_color_14,
	_hs_player_color_15,
	_hs_player_color_16,
	_hs_player_color_17,
	_hs_player_color_18,
	_hs_player_color_19,
	_hs_player_color_20,
	_hs_player_color_21,
	_hs_player_color_22,
	_hs_player_color_23,
	_hs_player_color_24,
	_hs_player_color_25,
	_hs_player_color_26,
	_hs_player_color_27,
	_hs_player_color_28,
	_hs_player_color_29,
	_hs_player_color_30,
	_hs_player_color_31,
	hs_player_color_count
};

enum e_hs_player_model_choice
{
	_hs_player_model_choice_spartan,
	_hs_player_model_choice_elite,
	hs_player_model_choice
};

enum e_hs_voice_output_setting
{
	_hs_voice_output_setting_default,
	_hs_voice_output_setting_headset,
	hs_voice_output_setting_count
};

enum e_hs_voice_mask
{
	_hs_voice_mask_none,
	_hs_voice_mask_anonymous,
	hs_voice_mask_count
};

enum e_hs_subtitle_setting
{
	_hs_subtitle_setting_automatic,
	_hs_subtitle_setting_enabled,
	_hs_subtitle_setting_disabled,
	hs_subtitle_setting_count
};

enum e_hs_actor_type
{
	_hs_actor_type_none,
	_hs_actor_type_player,
	_hs_actor_type_marine,
	_hs_actor_type_crew,
	_hs_actor_type_spartan,
	_hs_actor_type_elite,
	_hs_actor_type_jackal,
	_hs_actor_type_grunt,
	_hs_actor_type_brute,
	_hs_actor_type_hunter,
	_hs_actor_type_prophet,
	_hs_actor_type_bugger,
	_hs_actor_type_scarab,
	_hs_actor_type_engineer,
	_hs_actor_type_skirmisher,
	_hs_actor_type_mule,
	_hs_actor_type_mounted_weapon,
	hs_actor_type_count
};

enum e_hs_model_state
{
	_hs_model_state_standard,
	_hs_model_state_minor_damage,
	_hs_model_state_medium_damage,
	_hs_model_state_major_damage,
	_hs_model_state_destroyed,
	hs_model_state_count
};

enum e_hs_event
{
	_hs_event_verbose,
	_hs_event_status,
	_hs_event_message,
	_hs_event_warning,
	_hs_event_error,
	_hs_event_critical,
	hs_event_count
};

enum e_hs_character_physics
{
	_hs_character_physics_none,
	_hs_character_physics_player,
	_hs_character_physics_biped,
	hs_character_physics_count
};

enum e_hs_skull
{
	_hs_skull_iron,
	_hs_skull_black_eye,
	_hs_skull_tough_luck,
	_hs_skull_catch,
	_hs_skull_fog,
	_hs_skull_famine,
	_hs_skull_thunderstorm,
	_hs_skull_tilt,
	_hs_skull_mythic,
	_hs_skull_assassin,
	_hs_skull_blind,
	_hs_skull_superman,
	_hs_skull_birthday_party,
	_hs_skull_daddy,
	_hs_skull_red,
	_hs_skull_yellow,
	_hs_skull_blue,
	hs_skull_count
};

enum e_hs_firing_point_evaluator
{
	_hs_firing_point_evaluator_INVALID,
	_hs_firing_point_evaluator_attack_dangerousenemy,
	_hs_firing_point_evaluator_attack_idealrange,
	_hs_firing_point_evaluator_attack_leader_distance,
	_hs_firing_point_evaluator_attack_same_frame_of_reference,
	_hs_firing_point_evaluator_attack_weaponrange,
	_hs_firing_point_evaluator_combat_cue,
	_hs_firing_point_evaluator_combatmove_elevation,
	_hs_firing_point_evaluator_combatmove_follow_unit,
	_hs_firing_point_evaluator_combatmove_lineoffire,
	_hs_firing_point_evaluator_combatmove_lineoffire_occluded,
	_hs_firing_point_evaluator_cover_near_friends,
	_hs_firing_point_evaluator_current_position,
	_hs_firing_point_evaluator_current_destination,
	_hs_firing_point_evaluator_danger_zone,
	_hs_firing_point_evaluator_directional_movement,
	_hs_firing_point_evaluator_facing,
	_hs_firing_point_evaluator_fireteam_leader,
	_hs_firing_point_evaluator_flag_preferences,
	_hs_firing_point_evaluator_flank,
	_hs_firing_point_evaluator_flee_to_leader,
	_hs_firing_point_evaluator_friendly,
	_hs_firing_point_evaluator_friend_bunkering,
	_hs_firing_point_evaluator_goal_points_only,
	_hs_firing_point_evaluator_goal_preferences,
	_hs_firing_point_evaluator_heatmap,
	_hs_firing_point_evaluator_hide_equipment,
	_hs_firing_point_evaluator_inertia_preservation,
	_hs_firing_point_evaluator_leadership,
	_hs_firing_point_evaluator_movement_planning,
	_hs_firing_point_evaluator_move_into_danger_zone,
	_hs_firing_point_evaluator_move_distance,
	_hs_firing_point_evaluator_move_localized,
	_hs_firing_point_evaluator_multi_target,
	_hs_firing_point_evaluator_obstacle,
	_hs_firing_point_evaluator_panic_closetotarget,
	_hs_firing_point_evaluator_panic_targetdistance,
	_hs_firing_point_evaluator_pathfinding,
	_hs_firing_point_evaluator_perch_preferences,
	_hs_firing_point_evaluator_postsearch_prefer_original,
	_hs_firing_point_evaluator_previously_discarded,
	_hs_firing_point_evaluator_pursuit_search_pattern,
	_hs_firing_point_evaluator_ranged_fight,
	_hs_firing_point_evaluator_squad_patrol_search,
	_hs_firing_point_evaluator_stalking,
	_hs_firing_point_evaluator_stimulus,
	_hs_firing_point_evaluator_task_direction,
	_hs_firing_point_evaluator_too_far_from_leader,
	_hs_firing_point_evaluator_vehicle_move_distance,
	_hs_firing_point_evaluator_vehicle_pickup,
	_hs_firing_point_evaluator_wall_leanable,
	_hs_firing_point_evaluator_3d_path_available,
	_hs_firing_point_evaluator_attack_visible,
	_hs_firing_point_evaluator_attack_visible_los_optional,
	_hs_firing_point_evaluator_guard_cover,
	_hs_firing_point_evaluator_hide_cover,
	_hs_firing_point_evaluator_uncover_visible,
	_hs_firing_point_evaluator_vehicle_hide_cover,
	_hs_firing_point_evaluator_fight,
	_hs_firing_point_evaluator_panic,
	_hs_firing_point_evaluator_cover,
	_hs_firing_point_evaluator_uncover,
	_hs_firing_point_evaluator_guard,
	_hs_firing_point_evaluator_pursue,
	_hs_firing_point_evaluator_avoid,
	_hs_firing_point_evaluator_vehicle_cover,
	_hs_firing_point_evaluator_postsearch,
	hs_firing_point_evaluator_count
};

enum e_hs_damage_region
{
	_hs_damage_region_gut,
	_hs_damage_region_chest,
	_hs_damage_region_head,
	_hs_damage_region_left_shoulder,
	_hs_damage_region_left_arm,
	_hs_damage_region_left_leg,
	_hs_damage_region_left_foot,
	_hs_damage_region_right_shoulder,
	_hs_damage_region_right_arm,
	_hs_damage_region_right_leg,
	_hs_damage_region_right_foot,
	hs_damage_region_count
};

enum e_hs_type_flags : uint8_t
{
	_hs_type_flag_none = 0,
	_hs_type_flag_string_value = 1 << 0,
	_hs_type_flag_object = 1 << 1,
	_hs_type_flag_enum = 1 << 2,
	_hs_type_flag_tag = 1 << 3,
	_hs_type_flag_accepts_cast = 1 << 4,
	_hs_type_flag_can_cast = 1 << 5,
};

enum e_hs_type : uint8_t
{
	_hs_type_unparsed,
	_hs_type_special_form,
	_hs_type_function_name,
	_hs_type_passthrough,
	_hs_type_void,
	_hs_type_boolean,
	_hs_type_real,
	_hs_type_short,
	_hs_type_long,
	_hs_type_string,
	_hs_type_script,
	_hs_type_string_id,
	_hs_type_unit_seat_mapping,
	_hs_type_trigger_volume,
	_hs_type_cutscene_flag,
	_hs_type_cutscene_camera_point,
	_hs_type_cutscene_title,
	_hs_type_cutscene_recording,
	_hs_type_device_group,
	_hs_type_ai,
	_hs_type_ai_command_list,
	_hs_type_ai_command_script,
	_hs_type_ai_behavior,
	_hs_type_ai_orders,
	_hs_type_ai_line,
	_hs_type_starting_profile,
	_hs_type_conversation,
	_hs_type_player,
	_hs_type_zone_set,
	_hs_type_designer_zone,
	_hs_type_point_reference,
	_hs_type_style,
	_hs_type_object_list,
	_hs_type_folder,
	_hs_type_sound,
	_hs_type_effect,
	_hs_type_damage,
	_hs_type_looping_sound,
	_hs_type_animation_graph,
	_hs_type_damage_effect,
	_hs_type_object_definition,
	_hs_type_bitmap,
	_hs_type_shader,
	_hs_type_render_model,
	_hs_type_structure_definition,
	_hs_type_lightmap_definition,
	_hs_type_cinematic_definition,
	_hs_type_cinematic_scene_definition,
	_hs_type_cinematic_transition_definition,
	_hs_type_bink_definition,
	_hs_type_cui_screen_definition,
	_hs_type_any_tag,
	_hs_type_any_tag_not_resolving,
	_hs_type_game_difficulty,
	_hs_type_team,
	_hs_type_mp_team,
	_hs_type_controller,
	_hs_type_button_preset,
	_hs_type_joystick_preset,
	_hs_type_player_color,
	_hs_type_player_model_choice,
	_hs_type_voice_output_setting,
	_hs_type_voice_mask,
	_hs_type_subtitle_setting,
	_hs_type_actor_type,
	_hs_type_model_state,
	_hs_type_event,
	_hs_type_character_physics,
	_hs_type_skull,
	_hs_type_firing_point_evaluator,
	_hs_type_damage_region,
	_hs_type_object,
	_hs_type_unit,
	_hs_type_vehicle,
	_hs_type_weapon,
	_hs_type_device,
	_hs_type_scenery,
	_hs_type_effect_scenery,
	_hs_type_object_name,
	_hs_type_unit_name,
	_hs_type_vehicle_name,
	_hs_type_weapon_name,
	_hs_type_device_name,
	_hs_type_scenery_name,
	_hs_type_effect_scenery_name,
	_hs_type_cinematic_lightprobe,
	_hs_type_animation_budget_reference,
	_hs_type_looping_sound_budget_reference,
	_hs_type_sound_budget_reference,

	hs_type_count
};

enum e_hs_underlying_type : uint8_t
{
	_hs_underlying_type_empty = 0,
	_hs_underlying_type_uint8 = 1,
	_hs_underlying_type_uint16 = 2,
	_hs_underlying_type_uint32 = 4,
	_hs_underlying_type_uint64 = 8,

	hs_underlying_type_count
};

class c_hs_enum_value
{
public:
	c_hs_enum_value() = delete;
	c_hs_enum_value(const c_hs_enum_value&) = delete;
	c_hs_enum_value& operator=(const c_hs_enum_value&) = delete;

	c_hs_enum_value(const char* name, uint32_t value) :
		value(value),
		name(name)
	{
	}

	uint32_t value;
	const char* name;
};

class c_hs_type_definition
{
public:
	c_hs_type_definition() = delete;
	c_hs_type_definition(const c_hs_type_definition&) = delete;
	c_hs_type_definition& operator=(const c_hs_type_definition&) = delete;

	c_hs_type_definition(const char* name, uint8_t opcode, e_hs_type type, e_hs_underlying_type underlying_type, const c_hs_enum_value* enums, size_t enums_count, uint8_t flags = {}, const c_hs_type_definition** cast_from_types = nullptr, size_t cast_from_types_count = 0) :
		c_hs_type_definition(name, opcode, type, underlying_type, flags, cast_from_types, cast_from_types_count)
	{
		this->enums = enums;
		this->enums_count = static_cast<uint16_t>(enums_count);
		flags_raw |= _hs_type_flag_enum;
	}

	c_hs_type_definition(const char* name, uint8_t opcode, e_hs_type type, e_hs_underlying_type underlying_type, e_tag_group tag_group, uint8_t flags = {}) :
		c_hs_type_definition(name, opcode, type, underlying_type, flags)
	{
		tag_group = tag_group;
		flags_raw |= _hs_type_flag_tag;
	}

	c_hs_type_definition(const char* name, uint8_t opcode, e_hs_type type, e_hs_underlying_type underlying_type, uint8_t flags = {}, const c_hs_type_definition** cast_from_types = nullptr, size_t cast_from_types_count = 0) :
		opcode(opcode),
		type(type),
		underlying_type(underlying_type),
		flags_raw(flags),
		tag_group(_legacy_tag_group_invalid),
		enums(nullptr),
		enums_count(0),
		name(name),
		cast_from_types(cast_from_types),
		cast_from_types_count(static_cast<uint16_t>(cast_from_types_count))
	{
		if (cast_from_types_count > 0)
		{
			ASSERT(cast_from_types != nullptr);
			for (size_t cast_from_index = 0; cast_from_index < cast_from_types_count; cast_from_index++)
			{
				const c_hs_type_definition* type_definition = cast_from_types[cast_from_index];
				ASSERT(type_definition != nullptr);

				type_definition->flags_raw |= _hs_type_flag_can_cast;
			}
			flags_raw |= _hs_type_flag_accepts_cast;
		}
	}

	union
	{
		e_hs_type_flags flags;
		mutable underlying(e_hs_type_flags) flags_raw;
	};
	uint8_t opcode;
	e_hs_type type;
	e_hs_underlying_type underlying_type;
	uint16_t cast_from_types_count;
	uint16_t enums_count;
	e_tag_group tag_group;
	const c_hs_type_definition** cast_from_types;
	const c_hs_enum_value* enums;
	const char* name;
};

extern const c_hs_type_definition hs_type_definitions[hs_type_count];

const c_hs_type_definition* hs_cast_to_object_types[];				// array terminated with null value
const c_hs_type_definition* hs_cast_to_object_list_types[];			// array terminated with null value
const c_hs_type_definition* hs_cast_to_object_name_types[];			// array terminated with null value
const c_hs_type_definition* hs_cast_to_unit_types[];				// array terminated with null value
const c_hs_type_definition* hs_cast_to_vehicle_types[];				// array terminated with null value
const c_hs_type_definition* hs_cast_to_weapon_types[];				// array terminated with null value
const c_hs_type_definition* hs_cast_to_device_types[];				// array terminated with null value
const c_hs_type_definition* hs_cast_to_scenery_types[];				// array terminated with null value
const c_hs_type_definition* hs_cast_to_effect_scenery_types[];		// array terminated with null value
const c_hs_type_definition* hs_cast_to_player_types[];				// array terminated with null value
const c_hs_type_definition* hs_cast_to_boolean_types[];				// array terminated with null value

extern const c_hs_enum_value hs_player_definitions[hs_player_count];
extern const c_hs_enum_value hs_game_difficulty_definitions[hs_game_difficulty_count];
extern const c_hs_enum_value hs_team_definitions[hs_team_count];
extern const c_hs_enum_value hs_mp_team_definitions[hs_mp_team_count];
extern const c_hs_enum_value hs_controller_definitions[hs_controller_count];
extern const c_hs_enum_value hs_button_press_definitions[hs_button_press_count];
extern const c_hs_enum_value hs_joystick_preset_definitions[hs_joystick_preset_count];
extern const c_hs_enum_value hs_player_color_definitions[hs_player_color_count];
extern const c_hs_enum_value hs_player_model_choice_definitions[hs_player_model_choice];
extern const c_hs_enum_value hs_voice_output_setting_definitions[hs_voice_output_setting_count];
extern const c_hs_enum_value hs_voice_mask_definitions[hs_voice_mask_count];
extern const c_hs_enum_value hs_subtitle_setting_definitions[hs_subtitle_setting_count];
extern const c_hs_enum_value hs_actor_type_definitions[hs_actor_type_count];
extern const c_hs_enum_value hs_model_state_definitions[hs_model_state_count];
extern const c_hs_enum_value hs_event_definitions[hs_event_count];
extern const c_hs_enum_value hs_character_physics_definitions[hs_character_physics_count];
extern const c_hs_enum_value hs_skull_definitions[hs_skull_count];
extern const c_hs_enum_value hs_firing_point_evaluator_definitions[hs_firing_point_evaluator_count];
extern const c_hs_enum_value hs_damage_region_definitions[hs_damage_region_count];

