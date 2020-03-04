#pragma once

typedef signed __int8		int8_t;
typedef signed __int16		int16_t;
typedef signed __int32		int32_t;
typedef signed __int64		int64_t;
typedef unsigned __int8		uint8_t;
typedef unsigned __int16	uint16_t;
typedef unsigned __int32	uint32_t;
typedef unsigned __int64	uint64_t;
typedef unsigned __int8		bool8_t;
typedef unsigned __int16	bool16_t;
typedef unsigned __int32	bool32_t;
typedef unsigned __int64	bool64_t;
typedef	uint8_t				enum8_t;
typedef	uint16_t			enum16_t;
typedef	uint32_t			enum32_t;
typedef	uint64_t			enum64_t;
typedef	uint8_t				bitfield8_t;
typedef	uint16_t			bitfield16_t;
typedef	uint32_t			bitfield32_t;
typedef	uint64_t			bitfield64_t;
typedef	uint8_t				bitflag8_t;
typedef	uint16_t			bitflag16_t;
typedef	uint32_t			bitflag32_t;
typedef	uint64_t			bitflag64_t;
typedef	uint8_t				undefined8_t;
typedef	uint16_t			undefined16_t;
typedef	uint32_t			undefined32_t;
typedef	uint64_t			undefined64_t;

#pragma pack(push, 1)

#ifndef STRINGIFY
#define STRINGIFY(s) __STRINGIFY(s)
#define __STRINGIFY(s) #s
#endif

#ifdef __INTELLISENSE__
#define noreflection /* noreflection */
#define nicename(...) /* nicename */
#define group(...) /* group */
#else
#ifdef __clang__
#define noreflection __attribute__((annotate("no_reflection")))
#define nicename(name) __attribute__((annotate("nice_name:" name)))
#define group(groupName) __attribute__((annotate("tag_group:" STRINGIFY(groupName))))
#else
#define noreflection 
#define nicename(name) 
#define group(groupName) 
#endif
#endif

#ifndef BUILD_REFLECTION_DATA
#include "TagGroups.h"
#define _tag_group_render_method 'rm  '
#else
enum e_tag_group : int32_t {};
#endif

#include "TagTypes/StringID.h"
#include "TagTypes/DataReference.h"
#include "TagTypes/TagReference.h"
#include "TagTypes/TagBlock.h"
#include "TagTypes/Undefined.h"

// Tag Definitions
#include "TagDefinitions/bitmap.h"
#include "TagDefinitions/breakable_surface.h"
#include "TagDefinitions/camera_fx_settings.h"
#include "TagDefinitions/camera_track.h"
#include "TagDefinitions/camo.h"
#include "TagDefinitions/chocolate_mountain_new.h"
#include "TagDefinitions/chud_animation_definition.h"
#include "TagDefinitions/chud_definition.h"
#include "TagDefinitions/chud_globals_definition.h"
#include "TagDefinitions/cloth.h"
#include "TagDefinitions/collision_damage.h"
#include "TagDefinitions/collision_model.h"
#include "TagDefinitions/color_table.h"
#include "TagDefinitions/contrail_system.h"
#include "TagDefinitions/crate.h"
#include "TagDefinitions/creature.h"
#include "TagDefinitions/damage_effect.h"
#include "TagDefinitions/damage_response_definition.h"
#include "TagDefinitions/decal_system.h"
#include "TagDefinitions/decorator_set.h"
#include "TagDefinitions/device_control.h"
#include "TagDefinitions/device_machine.h"
#include "TagDefinitions/dialogue.h"
#include "TagDefinitions/effect.h"
#include "TagDefinitions/effect_globals.h"
#include "TagDefinitions/effect_scenery.h"
#include "TagDefinitions/equipment.h"
#include "TagDefinitions/flock.h"
#include "TagDefinitions/formation.h"
#include "TagDefinitions/game_engine_settings_definition.h"
#include "TagDefinitions/global_pixel_shader.h"
#include "TagDefinitions/global_vertex_shader.h"
#include "TagDefinitions/globals.h"
#include "TagDefinitions/lens_flare.h"
#include "TagDefinitions/light.h"
#include "TagDefinitions/light_volume_system.h"
#include "TagDefinitions/material_effects.h"
#include "TagDefinitions/model.h"
#include "TagDefinitions/model_animation_graph.h"
#include "TagDefinitions/multilingual_unicode_string_list.h"
#include "TagDefinitions/multiplayer_globals.h"
#include "TagDefinitions/multiplayer_variant_settings_interface_definition.h"
#include "TagDefinitions/particle.h"
#include "TagDefinitions/particle_model.h"
#include "TagDefinitions/particle_physics.h"
#include "TagDefinitions/performance_throttles.h"
#include "TagDefinitions/physics_model.h"
#include "TagDefinitions/pixel_shader.h"
#include "TagDefinitions/point_physics.h"
#include "TagDefinitions/projectile.h"
#include "TagDefinitions/rasterizer_globals.h"
#include "TagDefinitions/render_method_definition.h"
#include "TagDefinitions/render_method_option.h"
#include "TagDefinitions/render_method_template.h"
#include "TagDefinitions/render_model.h"
#include "TagDefinitions/render_water_ripple.h"
#include "TagDefinitions/scenario.h"
#include "TagDefinitions/scenario_lightmap.h"
#include "TagDefinitions/scenario_lightmap_bsp_data.h"
#include "TagDefinitions/scenario_structure_bsp.h"
#include "TagDefinitions/scenery.h"
#include "TagDefinitions/shader.h"
#include "TagDefinitions/shader_custom.h"
#include "TagDefinitions/shader_decal.h"
#include "TagDefinitions/shader_foliage.h"
#include "TagDefinitions/shader_halogram.h"
#include "TagDefinitions/shader_screen.h"
#include "TagDefinitions/shader_terrain.h"
#include "TagDefinitions/shader_water.h"
#include "TagDefinitions/shield_impact.h"
#include "TagDefinitions/sky_atm_parameters.h"
#include "TagDefinitions/sound.h"
#include "TagDefinitions/sound_classes.h"
#include "TagDefinitions/sound_dialogue_constants.h"
#include "TagDefinitions/sound_effect_collection.h"
#include "TagDefinitions/sound_environment.h"
#include "TagDefinitions/sound_global_propagation.h"
#include "TagDefinitions/sound_looping.h"
#include "TagDefinitions/sound_mix.h"
#include "TagDefinitions/sound_scenery.h"
#include "TagDefinitions/squad_template.h"
#include "TagDefinitions/structure_design.h"
#include "TagDefinitions/style.h"
#include "TagDefinitions/survival_mode_globals.h"
#include "TagDefinitions/text_value_pair_definition.h"
#include "TagDefinitions/user_interface_globals_definition.h"
#include "TagDefinitions/user_interface_shared_globals_definition.h"
#include "TagDefinitions/user_interface_sounds_definition.h"
#include "TagDefinitions/vehicle.h"
#include "TagDefinitions/vertex_shader.h"
#include "TagDefinitions/weapon.h"
#include "TagDefinitions/wind.h"
#include "TagDefinitions/achievements.h"
#include "TagDefinitions/ai_dialogue_globals.h"
#include "TagDefinitions/ai_globals.h"
#include "TagDefinitions/antenna.h"
#include "TagDefinitions/area_screen_effect.h"
#include "TagDefinitions/beam_system.h"
#include "TagDefinitions/biped.h"

#ifndef BUILD_REFLECTION_DATA
#include "GeneratedGUI.h"
#include "ReflectionData.h"
#include "GeneratedConversion.h"
//#include "VirtualTagInterfaces.h"
#endif

#pragma pack(pop)