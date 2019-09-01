#pragma once

#include <HaloShared/local_types.h>

class IGameEngineHost;

// TODO: find a better place for this?
enum e_tls_offset
{
	// tls offsets for version 1.887.0.0 of haloreach.dll
	// 0x0 unknown is this even one?
	_tls_offset_object_header_data = 0x8,
	_tls_offset_player_data = 0x18,
	_tls_offset_game_engine_globals = 0x20,
	// 0x28 threading related?
	_tls_offset_ai_globals = 0x30,
	_tls_offset_prop_ref_data = 0x38,
	_tls_offset_hs_thread_deterministic_data = 0x40,
	_tls_offset_squad_data = 0x48,
	_tls_offset_game_globals = 0x50,
	_tls_offset_prop_data = 0x58,
	_tls_offset_camera_script_globals = 0x60,
	_tls_offset_effect_data = 0x68,
	_tls_offset_command_script = 0x70,
	_tls_offset_cinematic_new_globals = 0x78,
	_tls_offset_sound_data = 0x90,
	_tls_offset_incident_globals = 0x98,
	_tls_offset_preferences = 0xA0,
	_tls_offset_clump_data = 0xA8,
	_tls_offset_flocks_data = 0xB0,
	_tls_offset_render_texture_camera_globals = 0xB8,
	_tls_offset_game_time_globals = 0xC0,
	_tls_offset_rasterizer_game_states = 0xC8,
	_tls_offset_game_looping_sound_data = 0xD0,
	_tls_offset_player_control_globals = 0xD8,
	_tls_offset_performance_data = 0xE0,
	_tls_offset_cinematic_globals = 0xE8,
	_tls_offset_event_data = 0xF0,
	_tls_offset_light_data = 0xF8,
	
	_tls_offset_simulation_object_glue_data = 0x100,
	_tls_offset_stimulus_data = 0x108,
	_tls_offset_breakable_surface_globals = 0x110,
	_tls_offset_boids_data = 0x118,
	_tls_offset_players_globals = 0x120,
	_tls_offset_main_gamestate_timing_data = 0x128,
	// 0x130 threading or font_cache related?
	_tls_offset_players_per_map_globals = 0x138,
	_tls_offset_fire_team_data = 0x140,
	_tls_offset_looping_sound_data = 0x148,
	_tls_offset_player_mapping_globals = 0x150,
	_tls_offset_joint_data = 0x158,
	_tls_offset_object_globals = 0x160,
	_tls_offset_game_save_globals = 0x168,
	_tls_offset_player_training_globals = 0x170,
	_tls_offset_ai_directive_data = 0x178,
	_tls_offset_chud_draw_user_globals = 0x180,
	_tls_offset_game_allegiance_globals = 0x188,
	_tls_offset_collision_hierarchy_node_data = 0x190,
	_tls_offset_director_globals = 0x198,
	_tls_offset_campaign_metagame = 0x1A0,
	_tls_offset_effect_location_data = 0x1A8,
	_tls_offset_recycling_groups = 0x1B0,
	_tls_offset_ai_players = 0x1B8,
	_tls_offset_vocalization_record = 0x1C0,
	_tls_offset_multiplayer_sound_globals = 0x1C8,
	_tls_offset_impact_data = 0x1D0,
	_tls_offset_player_effect_globals = 0x1D8,
	_tls_offset_collision_hierarchy_element_data = 0x1E0,
	_tls_offset_scripted_exposure_game_globals = 0x1E8,
	_tls_offset_recycling_volumes = 0x1F0,
	_tls_offset_airstrike_system = 0x1F8,

	_tls_offset_object_early_movers_globals = 0x200,
	_tls_offset_game_sound_globals = 0x208,
	_tls_offset_cached_object_render_states = 0x210,
	_tls_offset_device_groups_data = 0x218,
	_tls_offset_simulation_debug_globals = 0x220,
	_tls_offset_objectives_data = 0x228,
	_tls_offset_ai_sync_action_arranger_data = 0x230,
	_tls_offset_swarm_data = 0x238,
	_tls_offset_hs_runtime_globals = 0x240,
	_tls_offset_object_scripting_state = 0x248,
	_tls_offset_particle_system_data_array = 0x250,
	// 0x258 complete mystery??!
	_tls_offset_effect_counts = 0x260,
	_tls_offset_breakable_surface_set_broken_event = 0x268,
	_tls_offset_cloth_data = 0x270,
	_tls_offset_squad_group_data = 0x278,
	_tls_offset_main_time_globals = 0x280,
	_tls_offset_sound_effect_data = 0x288,
	_tls_offset_impact_globals = 0x290,
	_tls_offset_widget_data = 0x298,
	_tls_offset_local_game_engine_globals = 0x2A0,
	_tls_offset_particle_emitter_data_array = 0x2A8,
	_tls_offset_particle_location_data_array = 0x2B0,
	_tls_offset_rumble_globals = 0x2B8,
	_tls_offset_havok_proxy_data = 0x2C0,
	_tls_offset_damage_globals = 0x2C8,
	_tls_offset_squad_patrol_data = 0x2D0,
	_tls_offset_sound_playback_controller_data = 0x2D8,
	_tls_offset_leaf_system_data = 0x2E0,
	_tls_offset_dynamic_firing_set = 0x2E8,
	_tls_offset_depth_of_field_game_globals = 0x2F0,
	_tls_offset_beam_system = 0x2F8,

	_tls_offset_light_volume_system = 0x300,
	_tls_offset_contrail_system = 0x308,
	_tls_offset_path_influence_data = 0x310,
	_tls_offset_tracking_data = 0x318,
	_tls_offset_stimulus_ref = 0x320,
	_tls_offset_physics_constants = 0x328,
	_tls_offset_screen_effect_data = 0x330,
	_tls_offset_objectives = 0x338,
	_tls_offset_hud_camera_globals = 0x340,
	_tls_offset_decal_system = 0x348,
	_tls_offsetemory_pool_address = 0x350,
	// 0x358 c_cache_file_tag_runtime_resource related?
	_tls_offset_prop_search_data = 0x360,
	_tls_offset_bbsquad = 0x368,
	_tls_offset_effect_lightprobe_slot_data = 0x370,
	_tls_offset_main_render_timing_data = 0x378,
	_tls_offset_formation_data = 0x380,
	_tls_offset_particle_emitter_gpu_data_array = 0x388,
	_tls_offset_object_list_header_data = 0x390,
	_tls_offset_hs_global_data = 0x398,
	_tls_offset_object_schedule_globals = 0x3A0,
	_tls_offset_swarm_spawners = 0x3A8,
	_tls_offset_weather_state_deterministic = 0x3B0,
	_tls_offset_light_volume_location = 0x3B8,
	_tls_offset_memory_pool = 0x3C0,
	_tls_offset_cheap_particle_emitter_from_update_thread_data = 0x3C8,
	_tls_offset_impact_array_data = 0x3D0,
	_tls_offset_game_sound_scripted_impulses = 0x3D8,
	_tls_offset_particle_emitter_gpu__s_row_data_array = 0x3E0,
	_tls_offset_rasterizer_implicit_geometry_data = 0x3E8,
	_tls_offset_beam_location = 0x3F0,
	_tls_offset_contrail_location = 0x3F8,

	_tls_offset_looping_sound_restore_data = 0x400,
	_tls_offset_water_physics_cache_data = 0x408,
	_tls_offset_antenna_data = 0x410,
	_tls_offset_object_render_globals = 0x418,
	_tls_offset_light_volume = 0x420,
	_tls_offset_lasing_data = 0x428,
	_tls_offset_ai_cue_data = 0x430,
	_tls_offset_water_interaction_event = 0x438,
	_tls_offset_shield_render_cache_data = 0x440,
	_tls_offset_beam = 0x448,
	_tls_offset_contrail = 0x450,
	_tls_offset_ragdoll_data = 0x458,
	_tls_offset_cinematic_globals_non_deterministic = 0x460,
	_tls_offset_character_properties_cache = 0x468,
	_tls_offset_ai_reference_frame_data = 0x470,
	_tls_offset_beam_gpu_data_array = 0x478,
	_tls_offset_light_volume_gpu_data_array = 0x480,
	// 0x488 structure_bsp related?
	_tls_offset_campaign_metagame_secondary = 0x490,
	_tls_offset_performance_runtime_definition_data = 0x498,
	_tls_offset_contrail_gpu__s_row_data_array = 0x4A0,
	_tls_offset_contrail_gpu_data_array = 0x4A8,
	_tls_offset_animation_threads = 0x4B0,
	_tls_offset_scenario_kill_trigger_volumes_state = 0x4B8,
	_tls_offset_object_activation_region_data = 0x4C0,
	_tls_offset_lights_game_globals = 0x4C8,
	_tls_offset_beam_gpu__s_row_data_array = 0x4D0,
	_tls_offset_light_volume_gpu__s_row_data_array = 0x4D8,
	_tls_offset_weather_state_render = 0x4E0,
	_tls_offset_contrail_profile = 0x4E8,
	_tls_offset_sound_class_data = 0x4F0,
	_tls_offset_game_sound_multithreading_globals = 0x4F8,

	_tls_offset_megalo_object_data = 0x500,
	_tls_offset_actor_firing_position_hash_set = 0x508,
	_tls_offset_weather_state_shared = 0x510,
	_tls_offset_hue_saturation_control = 0x518,
	_tls_offset_decal_array = 0x520,
	_tls_offset_object_list_data = 0x528,
	_tls_offset_object_name_list = 0x530,
	_tls_offset_bink_globals = 0x538,
	_tls_offset_collision_hierarchy_node_hash_table_data = 0x540,
	_tls_offset_collision_hierarchy_globals = 0x548,
	_tls_offset_player_control_globals_deterministic = 0x550,
	_tls_offset_effect_message_queue = 0x558,
	_tls_offset_object_placement_globals = 0x560,
	_tls_offset_bbsquad_unit = 0x568,
	_tls_offset_team_dialogue_state = 0x570,
	_tls_offset_simulated_input_globals = 0x578,
	_tls_offset_future_development = 0x580,
	_tls_offset_hs_thread_non_deterministic_data = 0x588,
	_tls_offset_decal_message_queue = 0x590,
	_tls_offset_havok_game_state = 0x598,
	_tls_offset_hs_distributed_global_data = 0x5A0,
	_tls_offset_director_camera_scripted = 0x5A8,
	_tls_offset_deterministic_random_seed_ptr = 0x5B0,
	_tls_offset_object_message_queue = 0x5B8,
	_tls_offset_chud_persistent_global_data = 0x5C0,
	_tls_offset_effect_lightprobe_data = 0x5C8,
	_tls_offset_scenario_interpolator_globals = 0x5D0,
	_tls_offset_muffin_data = 0x5D8,
	_tls_offset_spawner_globals = 0x5E0,
	_tls_offset_observer_gamestate_globals = 0x5E8,
	_tls_offset_chud_persistent_user_data = 0x5F0,
	// 0x5F8

	// 0x600
	// 0x608
	// 0x610
	_tls_offset_render_game_globals = 0x618,
	_tls_offset_player_effects_globals = 0x620,
	_tls_offset_scenario_soft_ceilings = 0x628,
	_tls_offset_breakable_surface_redirection_globals = 0x630,
	_tls_offset_tasks_data = 0x638,
	// 0x640
	_tls_offset_game_heat_globals = 0x648,
	_tls_offset_active_portal_bitvectors = 0x650,
	_tls_offset_cinematic_light_globals = 0x658,
	_tls_offset_game_engine_render_globals = 0x660,
	// 0x668
	// 0x670
	// 0x678
	_tls_offset_vision_mode_state = 0x680,
	_tls_offset_first_person_weapon_orientations = 0x688,
	_tls_offset_observer_globals = 0x690,
	_tls_offset_cloth_globals = 0x698,
	_tls_offset_object_render_data = 0x6A0,
	_tls_offset_first_person_weapons = 0x6A8,
	_tls_offset_havok_contact_point_globals = 0x6B8,
	// 0x6C0
	// 0x6C8
	// 0x6D0
	// 0x6D8
	// 0x6E0
	// 0x6E8
	// 0x6F0
	// 0x6F8

	// 0x700
	_tls_offset_user_widgets = 0x708,
	// 0x710
	// 0x718
	// 0x720
	_tls_offset_usability_globals_backup = 0x728,
	_tls_offset_start_menu_campaign_objectives = 0x730
	// unsure if more exist after 0x730
};

extern intptr_t TlsIndex_offset(HaloGameID gameID);
extern DataEx<uint32_t, TlsIndex_offset> TlsIndex;
struct s_thread_local_storage
{
	uint64_t Address = NULL;

	template<typename T = uint64_t>
	T Get(size_t offset = 0)
	{
		Address = *(uint64_t *)(__readgsqword(0x58u) + (uint32_t)TlsIndex * sizeof(void *));

		if (!Address)
			return uint64_t(0);

		if (offset)
			return *(T *)(Address + offset);

		return (T)Address;
	}

	bool IsValid()
	{
		return Get() != NULL;
	}
};

extern s_thread_local_storage ThreadLocalStorage;

// Custom Stuff

enum class CurrentState
{
	eInactive,
	eRunning,
	eFinished
};
extern CurrentState g_CurrentGameState;
extern bool g_gameManuallyKilled;
extern bool g_isHooked;
extern WORD g_frameLimit;
extern int g_fieldOfView;
extern bool g_pancamEnabled;
extern int g_controlsLayout;
extern int g_useController;
extern bool g_hideWindowOnStartup;

extern e_map_id g_LaunchMapId;
extern int g_LaunchGameMode;
extern e_campaign_difficulty_level g_LaunchCampaignDifficultyLevel;
extern const char *g_LaunchHopperGameVariant;

// Halo Reach Functions

#define profile_configuration_update_args \
__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8,	\
__int64 a9, __int64 a10, __int64 a11, __int64 a12, __int64 a13, __int64 a14, __int64 a15, __int64 a16,	\
__int64 a17, __int64 a18, __int64 a19, __int64 a20, __int64 a21, __int64 a22, __int64 a23, __int64 a24,	\
__int64 a25, __int64 a26, __int64 a27, __int64 a28, __int64 a29, __int64 a30, __int64 a31, __int64 a32,	\
__int64 a33, __int64 a34, __int64 a35, __int64 a36, __int64 a37, __int64 a38, __int64 a39, __int64 a40,	\
__int64 a41, __int64 a42, __int64 a43, __int64 a44, __int64 a45, __int64 a46, __int64 a47, __int64 a48,	\
__int64 a49, __int64 a50, __int64 a51, __int64 a52, __int64 a53, __int64 a54, __int64 a55, __int64 a56,	\
__int64 a57, __int64 a58, __int64 a59, __int64 a60, __int64 a61, __int64 a62, __int64 a63
#define profile_configuration_update_vals \
a1,a2,a3,a4,a5,a6,a7,a8, \
a9,a10,a11,a12,a13,a14,a15,a16, \
a17,a18,a19,a20,a21,a22,a23,a24, \
a25,a26,a27,a28,a29,a30,a31,a32, \
a33,a34,a35,a36,a37,a38,a39,a40, \
a41,a42,a43,a44,a45,a46,a47,a48, \
a49,a50,a51,a52,a53,a54,a55,a56, \
a57,a58,a59,a60,a61,a62,a63
typedef char __fastcall profile_configuration_update_func(profile_configuration_update_args);
extern HaloReach_2019_Jun_24_Hook<0x180780D90, profile_configuration_update_func> profile_configuration_update_type; // 0x180497FD0

// Halo Reach Variables

extern intptr_t get_game_engine_host_offset(HaloGameID gameID);
extern DataEx<IGameEngineHost*, get_game_engine_host_offset> g_game_engine_host_pointer;
extern intptr_t get_render_thread_mode_offset(HaloGameID gameID);
extern DataEx<LONG, get_render_thread_mode_offset> g_render_thread_mode;

// #TODO: Cleanup --------------- (Make all of these match naming conventions)

extern intptr_t g_controller_interfaces_offset(HaloGameID gameID);
extern DataEx<c_controller_interface[4], g_controller_interfaces_offset> g_controller_interfaces;
extern intptr_t g_game_options_offset(HaloGameID gameID);
extern DataEx<s_game_options, g_game_options_offset> g_game_options;
extern intptr_t g_player_names_offset(HaloGameID gameID);
extern DataEx<wchar_t[4][32], g_player_names_offset> g_player_names;
extern intptr_t g_hwnd_offset(HaloGameID gameID);
extern DataEx<HWND, g_hwnd_offset> g_hwnd;
extern intptr_t level_name_to_patch_offset(HaloGameID gameID);
extern DataEx<char, level_name_to_patch_offset> level_name_to_patch;
extern HaloReach_2019_Jun_24_Data<_QWORD, 0x183461018> qword_183461018; // no equivalent
extern intptr_t g_gamepad_globals_offset(HaloGameID gameID);
extern DataEx<s_gamepad_globals, g_gamepad_globals_offset> g_gamepad_globals;
extern intptr_t g_input_abstraction_offset(HaloGameID gameID);
extern DataEx<s_input_abstraction, g_input_abstraction_offset> g_input_abstraction;
extern HaloReach_2019_Jun_24_Data<char*, 0x183461000> g_shell_command_line; // no equivalent
extern intptr_t g_createdWindow_offset(HaloGameID gameID);
extern DataEx<HWND, g_createdWindow_offset> g_createdWindow;
extern intptr_t dword_1810EC584_offset(HaloGameID gameID);
extern DataEx<DWORD, dword_1810EC584_offset> dword_1810EC584;
extern intptr_t byte_18342E55D_offset(HaloGameID gameID);
extern DataEx<BYTE, byte_18342E55D_offset> byte_18342E55D;
extern intptr_t byte_183984DE4_offset(HaloGameID gameID);
extern DataEx<BYTE, byte_183984DE4_offset> byte_183984DE4;
extern intptr_t dword_1810524AC_offset(HaloGameID gameID);
extern DataEx<DWORD, dword_1810524AC_offset> dword_1810524AC;
extern intptr_t ClassName_offset(HaloGameID gameID);
extern DataEx<char[64], ClassName_offset> ClassName;
extern intptr_t WindowName_offset(HaloGameID gameID);
extern DataEx<char[64], WindowName_offset> WindowName;
extern intptr_t g_WndProc_offset(HaloGameID gameID);
extern DataEx<WNDPROC, g_WndProc_offset> g_WndProc;
extern intptr_t g_hInstance_offset(HaloGameID gameID);
extern DataEx<HINSTANCE, g_hInstance_offset> g_hInstance;

// #TODO: End Cleanup -----------









// config flags

extern bool g_useCustomGameWindow;
extern void init_haloreach_hooks();
extern const char* g_haloReachPathOverride;




