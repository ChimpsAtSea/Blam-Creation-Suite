#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(model_flags_definition, 13)
	{
		OPTION("active camo always on"),
		OPTION("active camo never"),
		OPTION("inconsequential target#used in magnetism and campaign saving"),
		OPTION("model use airprobe lighting first{model use airprobe lighting}"),
		OPTION("locked precomputed probes#air or scenery probe"),
		OPTION("If sky attaches to camera#parallax % between sky pos and camera pos below"),
		OPTION("model is big battle object"),
		OPTION("model never uses compressed vertex position"),
		OPTION("model is invisible, even attachments"),
		OPTION("model can have shield impact effect!*"),
		OPTION("model is good z occluder"),
		OPTION("no child objects in lightmap shadow"),
		OPTION("should include model in floating shadow"),
	};

	TAG_ENUM(model_private_flags_definition, 1)
	{
		OPTION("contains run-time nodes"),
	};

	TAG_ENUM(model_lightmap_flags_definition, 3)
	{
		OPTION("pvs enabled"),
		OPTION("per vertex all"),
		OPTION("generate forge atlas"),
	};

	TAG_ENUM(model_lod_resource_distance_flags_definition, 1)
	{
		OPTION("override enabled"),
	};

	TAG_ENUM(imposter_quality_definition, 3)
	{
		OPTION("default"),
		OPTION("high"),
		OPTION("super"),
	};

	TAG_ENUM(imposter_policy_definition, 3)
	{
		OPTION("default"),
		OPTION("never"),
		OPTION("always"),
	};

	TAG_ENUM(model_game_mode_types, 4)
	{
		OPTION("campaign"),
		OPTION("multiplayer"),
		OPTION("firefight"),
		OPTION("mainmenu"),
	};

	TAG_ENUM(model_variant_permutation_flags_definition, 1)
	{
		OPTION("copy states to all permutations"),
	};

	TAG_ENUM(model_state_property_flags_definition, 4)
	{
		OPTION("blurred"),
		OPTION("hella blurred"),
		OPTION("unshielded{shielded}"),
		OPTION("battery depleted"),
	};

	TAG_ENUM(region_sort_enum, 12)
	{
		OPTION("no sorting"),
		OPTION("-5 (closest)"),
		OPTION("-4"),
		OPTION("-3"),
		OPTION("-2"),
		OPTION("-1"),
		OPTION("0 (same as model)"),
		OPTION("1"),
		OPTION("2"),
		OPTION("3"),
		OPTION("4"),
		OPTION("5 (farthest)"),
	};

	TAG_ENUM(ModelVariantObjectFlagsDefinition, 1)
	{
		OPTION("enable physics"),
	};

	TAG_ENUM(model_instance_group_choice_enum, 2)
	{
		OPTION("choose one member"),
		OPTION("choose all members"),
	};

	TAG_ENUM(model_target_lock_on_flags_definition, 4)
	{
		OPTION("headshot"),
		OPTION("vulnerable"),
		OPTION("ignored on local physics"),
		OPTION("use for network lead vector only"),
	};

	TAG_ENUM(model_target_flags_definition, 3)
	{
		OPTION("aoe top level"),
		OPTION("aoe test obstruction"),
		OPTION("shows tracking reticle#use this model targets center for displaying the targetting reticle"),
	};

	TAG_ENUM(model_permutation_flags_definition, 1)
	{
		OPTION("cannot be chosen randomly"),
	};

	TAG_ENUM(model_self_shadow_detail_definition, 3)
	{
		OPTION("Ambient Occlusion (2 bytes per vertex){0}"),
		OPTION("Linear (8 bytes per vertex){1}"),
		OPTION("Quadratic (18 bytes per vertex){2}"),
	};

	TAG_ENUM(model_self_shadow_bounces_definition, 4)
	{
		OPTION("0 bounces (very fast, direct light only)"),
		OPTION("1 bounce  (slower, pretty good)"),
		OPTION("2 bounces (molasses, very good)"),
		OPTION("3 bounces (sloth in molasses, overkill really)"),
	};

	TAG_ENUM(model_prt_shadow_receive_mode_definition, 3)
	{
		OPTION("PRT shadows from all regions (default permutations)"),
		OPTION("PRT self-shadow only (no shadows from other regions)"),
		OPTION("No PRT shadows at all (probably not useful)"),
	};

	TAG_GROUP(model, MODEL_TAG)
	{
		FIELD( _field_explanation, "MODEL" ),
		FIELD( _field_custom ),
		FIELD( _field_tag_reference, "render model" ),
		FIELD( _field_tag_reference, "collision model" ),
		FIELD( _field_tag_reference, "animation" ),
		FIELD( _field_tag_reference, "physics_model" ),
		FIELD( _field_tag_reference, "imposter model" ),
		FIELD( _field_long_integer, "runtime render checksum*!" ),
		FIELD( _field_long_integer, "runtime collision checksum*!" ),
		FIELD( _field_explanation, "Optional Static Lightmap" ),
		FIELD( _field_tag_reference, "Lighting Info^" ),
		FIELD( _field_long_enum, "Size Class", &scenario_structure_size_enum ),
		FIELD( _field_long_flags, "Lightmap Flags{PVS flags}", &model_lightmap_flags_definition ),
		FIELD( _field_long_block_index, "Lightmap Variant" ),
		FIELD( _field_explanation, "PVS" ),
		FIELD( _field_real, "PVS bounding box extension factor #How much we extend the PVS region around the objects AABB : [good initial value 2.5]" ),
		FIELD( _field_real_vector_3d, "PVS block size #How big a single PVS block is, in world units : [good initial value (2.0,2.0,2.0)]" ),
		FIELD( _field_long_integer, "PVS sampling subdivision per axis #How many sample subdivisions we perform per PVS block when generating the data : [good initial value 2]" ),
		FIELD( _field_real, "PVS visibility threshold #Minimum amount we need to see of an individual part mesh to care about it : [good initial value 0.004]" ),
		FIELD( _field_explanation, "level of detail" ),
		FIELD( _field_real, "disappear distance:world units" ),
		FIELD( _field_real, "begin fade distance:world units" ),
		FIELD( _field_real, "animation lod distance:world units" ),
		FIELD( _field_real, "shadow fade distance:world units#NOTE this is only a maximum distance, shadows may fade closer when you exceed the shadow budget, you should balance the total shadows in a scene" ),
		FIELD( _field_real, "imposter render distance:world units" ),
		FIELD( _field_enum, "imposter quality", &imposter_quality_definition ),
		FIELD( _field_enum, "imposter policy", &imposter_policy_definition ),
		FIELD( _field_real, "imposter brightness adjustment" ),
		FIELD( _field_real, "instance disappear distance:world units" ),
		FIELD( _field_real, "midrange detail disappear distance:world units#distance at which the midrange detail disappears" ),
		FIELD( _field_real, "close detail disappear distance:world units#distance at which the close detail disappears" ),
		FIELD( _field_real, "tessellation max draw distance:world units" ),
		FIELD( _field_long_flags, "resource distance override flags", &model_lod_resource_distance_flags_definition ),
		FIELD( _field_real, "medium priority distance" ),
		FIELD( _field_real, "low priority distance" ),
		FIELD( _field_block, "variants", &model_variant_block_block ),
		FIELD( _field_block, "region sort", &region_name_block_block ),
		FIELD( _field_block, "instance groups", &global_model_instance_group_block_block ),
		FIELD( _field_block, "model materials*", &model_material_block_new_block ),
		FIELD( _field_block, "new damage info!", &global_damage_info_block_block ),
		FIELD( _field_struct, "damage info", &model_damage_info_struct_struct_definition ),
		FIELD( _field_block, "targets old{targets}!", &model_target_block_old_block ),
		FIELD( _field_block, "model targets", &model_target_block_new_block ),
		FIELD( _field_block, "runtime regions!", &model_region_block_block ),
		FIELD( _field_block, "runtime nodes!", &model_node_block_block ),
		FIELD( _field_long_integer, "runtime node list checksum!" ),
		FIELD( _field_explanation, "more stuff" ),
		FIELD( _field_tag_reference, "default dialogue#The default dialogue tag for this model (overriden by variants)" ),
		FIELD( _field_tag_reference, "default dialogue female#The default FEMALE dialogue tag for this model (overriden by variants)" ),
		FIELD( _field_long_flags, "flags", &model_flags_definition ),
		FIELD( _field_string_id, "default dialogue effect#The default dialogue tag for this model (overriden by variants)" ),
		FIELD( _field_array, "render-only node flags*!" ),
		FIELD( _field_array, "render-only section flags*!" ),
		FIELD( _field_long_flags, "runtime flags*!", &model_private_flags_definition ),
		FIELD( _field_block, "scenario load parameters", &global_scenario_load_parameters_block_block ),
		FIELD( _field_block, "game mode render model override", &model_game_mode_render_model_override_block ),
		FIELD( _field_real_fraction, "Sky parallax percent#If flag checked % between sky pos and camera pos 0=camera" ),
		FIELD( _field_real, "shadow depth compare bias#Default is 0.002" ),
		FIELD( _field_real, "shadow slope scale bias:degrees#controls cutoff point for shadows around edges.  Default is 81 degrees" ),
		FIELD( _field_real, "shadow depth compare bias (dynamic lights)#Default is 0.0008" ),
		FIELD( _field_real, "shadow slope scale bias (dynamic lights):degrees#controls cutoff point for shadows around edges.  Default is 81 degrees" ),
		FIELD( _field_explanation, "PRT Shadows (soft self-shadow)" ),
		FIELD( _field_char_enum, "PRT shadow detail!#how much information is recorded about different light directions", &model_self_shadow_detail_definition ),
		FIELD( _field_char_enum, "PRT shadow bounces#0 means direct light only", &model_self_shadow_bounces_definition ),
		FIELD( _field_pad, "NCFGBA", 2 ),
		FIELD( _field_block, "shadow cast override", &model_self_shadow_region_cast_override_block_block ),
		FIELD( _field_block, "shadow receive override", &model_self_shadow_region_receive_override_block_block ),
		FIELD( _field_block, "occlusion spheres", &model_occlusion_sphere_block_block ),
		FIELD( _field_explanation, "Shield impact overrides!" ),
		FIELD( _field_tag_reference, "shield impact parameter override!" ),
		FIELD( _field_tag_reference, "1st person shield impact parameter override!" ),
		FIELD( _field_real, "runtime bounding radius:world units*!" ),
		FIELD( _field_real_point_3d, "runtime bounding offset*!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(model_variant_block, k_maximum_variants_per_model)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_array, "runtime variant region indices!" ),
		FIELD( _field_block, "regions", &model_variant_region_block_block ),
		FIELD( _field_block, "objects", &model_variant_object_block_block ),
		FIELD( _field_long_block_index, "instance group#selects an instance group for this variant" ),
		FIELD( _field_block, "muted nodes#turn off animation on these named nodes and children", &model_variant_muted_node_block_block ),
		FIELD( _field_array, "muted flag*!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(model_variant_region_block, MAXIMUM_REGIONS_PER_MODEL)
	{
		FIELD( _field_string_id, "region name^:must match region name in render_model" ),
		FIELD( _field_char_integer, "runtime region index!" ),
		FIELD( _field_byte_integer, "runtime flags!" ),
		FIELD( _field_short_block_index, "parent variant" ),
		FIELD( _field_block, "permutations", &model_variant_permutation_block_block ),
		FIELD( _field_enum, "sort order#negative values mean closer to the camera", &region_sort_enum ),
		FIELD( _field_pad, "JO", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(model_variant_permutation_block, MAXIMUM_PERMUTATIONS_PER_MODEL_REGION)
	{
		FIELD( _field_string_id, "permutation name^" ),
		FIELD( _field_char_integer, "runtime permutation index!" ),
		FIELD( _field_byte_flags, "flags", &model_variant_permutation_flags_definition ),
		FIELD( _field_pad, "KSJOSR", 2 ),
		FIELD( _field_real, "probability:(0,+inf)" ),
		FIELD( _field_block, "states", &model_variant_state_block_block ),
		FIELD( _field_array, "runtime state permutation indices!" ),
		FIELD( _field_pad, "LOOEL", 7 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(model_variant_state_block, MAXIMUM_STATES_PER_MODEL_PERMUTATION)
	{
		FIELD( _field_string_id, "permutation name" ),
		FIELD( _field_char_integer, "runtime permutation index!" ),
		FIELD( _field_byte_flags, "property flags", &model_state_property_flags_definition ),
		FIELD( _field_enum, "state^", &model_state_enum_definition ),
		FIELD( _field_real_fraction, "initial probability" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(model_variant_object_block, k_maximum_objects_per_model_variant)
	{
		FIELD( _field_custom ),
		FIELD( _field_string_id, "parent marker^" ),
		FIELD( _field_string_id, "parent controlling seat label^#the seat in my parent that will control me" ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "child marker" ),
		FIELD( _field_string_id, "child variant name#optional" ),
		FIELD( _field_tag_reference, "child object" ),
		FIELD( _field_short_block_index, "damage section" ),
		FIELD( _field_byte_flags, "flags", &ModelVariantObjectFlagsDefinition ),
		FIELD( _field_pad, "MVOBP1", 1 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(model_variant_muted_node_block, k_maximum_muted_nodes_per_model_variant)
	{
		FIELD( _field_string_id, "node name^:must match node name in render_model" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(region_name_block, k_kilo)
	{
		FIELD( _field_string_id, "name" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(global_model_instance_group_block, k_maximum_instance_groups_per_model)
	{
		FIELD( _field_string_id, "name^#name of this instance group" ),
		FIELD( _field_long_enum, "choice#how to choose members", &model_instance_group_choice_enum ),
		FIELD( _field_block, "member list", &model_instance_group_member_block_block ),
		FIELD( _field_real, "total probability!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(model_instance_group_member_block, k_maximum_members_per_instance_group)
	{
		FIELD( _field_long_block_index, "subgroup#if this member is chosen, this subgroup will be chosen as well" ),
		FIELD( _field_string_id, "instances#instance name, a partial name will choose all matching instances, leave blank for NONE" ),
		FIELD( _field_real, "probability:> 0.0#higher numbers make it more likely" ),
		FIELD( _field_long_integer, "instance placement mask 0!" ),
		FIELD( _field_long_integer, "instance placement mask 1!" ),
		FIELD( _field_long_integer, "instance placement mask 2!" ),
		FIELD( _field_long_integer, "instance placement mask 3!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(model_material_block_new, MAXIMUM_MATERIALS_PER_MODEL)
	{
		FIELD( _field_string_id, "material name*" ),
		FIELD( _field_pad, "unused flags", 2 ),
		FIELD( _field_short_block_index, "damage section" ),
		FIELD( _field_short_integer, "runtime collision material index!" ),
		FIELD( _field_short_integer, "runtime damager material index!" ),
		FIELD( _field_string_id, "global material name" ),
		FIELD( _field_short_integer, "runtime global material index!" ),
		FIELD( _field_pad, "SEWETKHRE", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(model_target_block_old, MAXIMUM_MODEL_TARGETS_PER_MODEL)
	{
		FIELD( _field_custom ),
		FIELD( _field_string_id, "marker name^#multiple markers become multiple spheres of the same radius" ),
		FIELD( _field_real, "size#sphere radius" ),
		FIELD( _field_angle, "cone angle#the target is only visible when viewed within this angle of the marker\'s x axis" ),
		FIELD( _field_custom_short_block_index, "damage section#the target is associated with this damage section" ),
		FIELD( _field_short_block_index, "variant#the target will only appear with this variant" ),
		FIELD( _field_real_fraction, "targeting relevance#higher relevances turn into stronger magnetisms" ),
		FIELD( _field_real, "aoe exclusion radius#ignored if zero" ),
		FIELD( _field_struct, "lock-on data", &model_target_lock_on_data_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(model_target_block_new, MAXIMUM_MODEL_TARGETS_PER_MODEL)
	{
		FIELD( _field_byte_flags, "flags", &model_target_flags_definition ),
		FIELD( _field_pad, "MTBNP1", 3 ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "marker name^#multiple markers become multiple spheres of the same radius" ),
		FIELD( _field_real, "size#sphere radius" ),
		FIELD( _field_angle, "cone angle#the target is only visible when viewed within this angle of the marker\'s x axis" ),
		FIELD( _field_short_block_index, "damage section#the target is associated with this damage section" ),
		FIELD( _field_short_block_index, "variant#the target will only appear with this variant" ),
		FIELD( _field_real_fraction, "targeting relevance#higher relevances turn into stronger magnetisms" ),
		FIELD( _field_real, "aoe exclusion radius#ignored if zero" ),
		FIELD( _field_struct, "lock-on data", &model_target_lock_on_data_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(model_region_block, MAXIMUM_REGIONS_PER_MODEL)
	{
		FIELD( _field_string_id, "name*^" ),
		FIELD( _field_char_integer, "collision region index*" ),
		FIELD( _field_char_integer, "physics region index*" ),
		FIELD( _field_pad, "QDSJS", 2 ),
		FIELD( _field_block, "permutations*", &model_permutation_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(model_permutation_block, MAXIMUM_PERMUTATIONS_PER_MODEL_REGION)
	{
		FIELD( _field_string_id, "name*^" ),
		FIELD( _field_byte_flags, "flags*", &model_permutation_flags_definition ),
		FIELD( _field_char_integer, "collision permutation index*" ),
		FIELD( _field_char_integer, "physics permutation index*" ),
		FIELD( _field_pad, "AVZQS", 1 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(model_node_block, MAXIMUM_NODES_PER_MODEL)
	{
		FIELD( _field_string_id, "name*^" ),
		FIELD( _field_short_block_index, "parent node*" ),
		FIELD( _field_short_block_index, "first child node*" ),
		FIELD( _field_short_block_index, "next sibling node*" ),
		FIELD( _field_pad, "GHTI", 2 ),
		FIELD( _field_real_point_3d, "default translation*" ),
		FIELD( _field_real_quaternion, "default rotation*" ),
		FIELD( _field_real, "default inverse scale*" ),
		FIELD( _field_real_vector_3d, "default inverse forward*" ),
		FIELD( _field_real_vector_3d, "default inverse left*" ),
		FIELD( _field_real_vector_3d, "default inverse up*" ),
		FIELD( _field_real_point_3d, "default inverse position*" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(model_game_mode_render_model_override, k_maximum_model_game_mode_types)
	{
		FIELD( _field_enum, "game mode^", &model_game_mode_types ),
		FIELD( _field_pad, "BL", 2 ),
		FIELD( _field_tag_reference, "render model override" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(model_self_shadow_region_cast_override_block, MAXIMUM_REGIONS_PER_MODEL)
	{
		FIELD( _field_string_id, "region" ),
		FIELD( _field_string_id, "shadow cast permutation#leave blank for none" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(model_self_shadow_region_receive_override_block, MAXIMUM_REGIONS_PER_MODEL)
	{
		FIELD( _field_string_id, "region" ),
		FIELD( _field_long_enum, "shadow type", &model_prt_shadow_receive_mode_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(model_occlusion_sphere_block, MAXIMUM_REGIONS_PER_MODEL)
	{
		FIELD( _field_custom ),
		FIELD( _field_string_id, "marker 1 name" ),
		FIELD( _field_long_integer, "marker 1 index" ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "marker 2 name" ),
		FIELD( _field_long_integer, "marker 2 index" ),
		FIELD( _field_real, "radius" ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(model_target_lock_on_data_struct)
{
		FIELD( _field_explanation, "lock-on fields" ),
		FIELD( _field_byte_flags, "flags", &model_target_lock_on_flags_definition ),
		FIELD( _field_pad, "SVLKJERAF", 3 ),
		FIELD( _field_real, "lock on distance" ),
		FIELD( _field_string_id, "tracking type#a weapon can track/lock on this target if this string is in the weapon\'s tracking block" ),
		FIELD( _field_terminator )
};

} // namespace blofeld

