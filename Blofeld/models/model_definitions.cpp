#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(model_variant, k_maximum_variants_per_model)
{
	{ _field_string_id, "name^" },
	{ _field_array, "runtime variant region indices!" },
	{ _field_block, "regions", &model_variant_region_block },
	{ _field_block, "objects", &model_variant_object_block },
	{ _field_long_block_index, "instance group#selects an instance group for this variant" },
	{ _field_block, "muted nodes#turn off animation on these named nodes and children", &model_variant_muted_node_block },
	{ _field_array, "muted flag*!" },
	{ _field_terminator },
};

TAG_BLOCK(model_variant_region, MAXIMUM_REGIONS_PER_MODEL)
{
	{ _field_string_id, "region name^:must match region name in render_model" },
	{ _field_char_integer, "runtime region index!" },
	{ _field_byte_integer, "runtime flags!" },
	{ _field_short_block_index, "parent variant" },
	{ _field_block, "permutations", &model_variant_permutation_block },
	{ _field_enum, "sort order#negative values mean closer to the camera" },
	{ _field_pad, "JO", 2 },
	{ _field_terminator },
};

TAG_BLOCK(model_variant_permutation, MAXIMUM_PERMUTATIONS_PER_MODEL_REGION)
{
	{ _field_string_id, "permutation name^" },
	{ _field_char_integer, "runtime permutation index!" },
	{ _field_byte_flags, "flags" },
	{ _field_pad, "KSJOSR", 2 },
	{ _field_real, "probability:(0,+inf)" },
	{ _field_block, "states", &model_variant_state_block },
	{ _field_array, "runtime state permutation indices!" },
	{ _field_pad, "LOOEL", 7 },
	{ _field_terminator },
};

TAG_BLOCK(model_variant_state, MAXIMUM_STATES_PER_MODEL_PERMUTATION)
{
	{ _field_string_id, "permutation name" },
	{ _field_char_integer, "runtime permutation index!" },
	{ _field_byte_flags, "property flags" },
	{ _field_enum, "state^" },
	{ _field_real_fraction, "initial probability" },
	{ _field_terminator },
};

TAG_BLOCK(model_variant_object, k_maximum_objects_per_model_variant)
{
	{ _field_custom },
	{ _field_string_id, "parent marker^" },
	{ _field_string_id, "parent controlling seat label^#the seat in my parent that will control me" },
	{ _field_custom },
	{ _field_string_id, "child marker" },
	{ _field_string_id, "child variant name#optional" },
	{ _field_tag_reference, "child object" },
	{ _field_short_block_index, "damage section" },
	{ _field_byte_flags, "flags" },
	{ _field_pad, "MVOBP1", 1 },
	{ _field_terminator },
};

TAG_BLOCK(model_variant_muted_node, k_maximum_muted_nodes_per_model_variant)
{
	{ _field_string_id, "node name^:must match node name in render_model" },
	{ _field_terminator },
};

TAG_BLOCK(region_name, k_kilo)
{
	{ _field_string_id, "name" },
	{ _field_terminator },
};

TAG_BLOCK(global_model_instance_group, k_maximum_instance_groups_per_model)
{
	{ _field_string_id, "name^#name of this instance group" },
	{ _field_long_enum, "choice#how to choose members" },
	{ _field_block, "member list", &model_instance_group_member_block },
	{ _field_real, "total probability!" },
	{ _field_terminator },
};

TAG_BLOCK(model_instance_group_member, k_maximum_members_per_instance_group)
{
	{ _field_long_block_index, "subgroup#if this member is chosen, this subgroup will be chosen as well" },
	{ _field_string_id, "instances#instance name, a partial name will choose all matching instances, leave blank for NONE" },
	{ _field_real, "probability:> 0.0#higher numbers make it more likely" },
	{ _field_long_integer, "instance placement mask 0!" },
	{ _field_long_integer, "instance placement mask 1!" },
	{ _field_long_integer, "instance placement mask 2!" },
	{ _field_long_integer, "instance placement mask 3!" },
	{ _field_terminator },
};

TAG_BLOCK(model_material, MAXIMUM_MATERIALS_PER_MODEL)
{
	{ _field_string_id, "material name*" },
	{ _field_pad, "unused flags", 2 },
	{ _field_short_block_index, "damage section" },
	{ _field_short_integer, "runtime collision material index!" },
	{ _field_short_integer, "runtime damager material index!" },
	{ _field_string_id, "global material name" },
	{ _field_short_integer, "runtime global material index!" },
	{ _field_pad, "SEWETKHRE", 2 },
	{ _field_terminator },
};

TAG_BLOCK(model_target, MAXIMUM_MODEL_TARGETS_PER_MODEL)
{
	{ _field_custom },
	{ _field_string_id, "marker name^#multiple markers become multiple spheres of the same radius" },
	{ _field_real, "size#sphere radius" },
	{ _field_angle, "cone angle#the target is only visible when viewed within this angle of the marker\'s x axis" },
	{ _field_custom_short_block_index, "damage section#the target is associated with this damage section" },
	{ _field_short_block_index, "variant#the target will only appear with this variant" },
	{ _field_real_fraction, "targeting relevance#higher relevances turn into stronger magnetisms" },
	{ _field_real, "aoe exclusion radius#ignored if zero" },
	{ _field_struct, "lock-on data" },
	{ _field_terminator },
};

TAG_BLOCK(model_target$2, MAXIMUM_MODEL_TARGETS_PER_MODEL)
{
	{ _field_byte_flags, "flags" },
	{ _field_pad, "MTBNP1", 3 },
	{ _field_custom },
	{ _field_string_id, "marker name^#multiple markers become multiple spheres of the same radius" },
	{ _field_real, "size#sphere radius" },
	{ _field_angle, "cone angle#the target is only visible when viewed within this angle of the marker\'s x axis" },
	{ _field_short_block_index, "damage section#the target is associated with this damage section" },
	{ _field_short_block_index, "variant#the target will only appear with this variant" },
	{ _field_real_fraction, "targeting relevance#higher relevances turn into stronger magnetisms" },
	{ _field_real, "aoe exclusion radius#ignored if zero" },
	{ _field_struct, "lock-on data" },
	{ _field_terminator },
};

TAG_BLOCK(model_region, MAXIMUM_REGIONS_PER_MODEL)
{
	{ _field_string_id, "name*^" },
	{ _field_char_integer, "collision region index*" },
	{ _field_char_integer, "physics region index*" },
	{ _field_pad, "QDSJS", 2 },
	{ _field_block, "permutations*", &model_permutation_block },
	{ _field_terminator },
};

TAG_BLOCK(model_permutation, MAXIMUM_PERMUTATIONS_PER_MODEL_REGION)
{
	{ _field_string_id, "name*^" },
	{ _field_byte_flags, "flags*" },
	{ _field_char_integer, "collision permutation index*" },
	{ _field_char_integer, "physics permutation index*" },
	{ _field_pad, "AVZQS", 1 },
	{ _field_terminator },
};

TAG_BLOCK(model_node, MAXIMUM_NODES_PER_MODEL)
{
	{ _field_string_id, "name*^" },
	{ _field_short_block_index, "parent node*" },
	{ _field_short_block_index, "first child node*" },
	{ _field_short_block_index, "next sibling node*" },
	{ _field_pad, "GHTI", 2 },
	{ _field_real_point_3d, "default translation*" },
	{ _field_real_quaternion, "default rotation*" },
	{ _field_real, "default inverse scale*" },
	{ _field_real_vector_3d, "default inverse forward*" },
	{ _field_real_vector_3d, "default inverse left*" },
	{ _field_real_vector_3d, "default inverse up*" },
	{ _field_real_point_3d, "default inverse position*" },
	{ _field_terminator },
};

TAG_BLOCK(model_game_mode_render_model_override, k_maximum_model_game_mode_types)
{
	{ _field_enum, "game mode^" },
	{ _field_pad, "BL", 2 },
	{ _field_tag_reference, "render model override" },
	{ _field_terminator },
};

TAG_BLOCK(model_self_shadow_region_cast_override, MAXIMUM_REGIONS_PER_MODEL)
{
	{ _field_string_id, "region" },
	{ _field_string_id, "shadow cast permutation#leave blank for none" },
	{ _field_terminator },
};

TAG_BLOCK(model_self_shadow_region_receive_override, MAXIMUM_REGIONS_PER_MODEL)
{
	{ _field_string_id, "region" },
	{ _field_long_enum, "shadow type" },
	{ _field_terminator },
};

TAG_BLOCK(model_occlusion_sphere, MAXIMUM_REGIONS_PER_MODEL)
{
	{ _field_custom },
	{ _field_string_id, "marker 1 name" },
	{ _field_long_integer, "marker 1 index" },
	{ _field_custom },
	{ _field_string_id, "marker 2 name" },
	{ _field_long_integer, "marker 2 index" },
	{ _field_real, "radius" },
	{ _field_terminator },
};

TAG_GROUP(model, MODEL_TAG)
{
	{ _field_explanation, "MODEL" },
	{ _field_custom },
	{ _field_tag_reference, "render model" },
	{ _field_tag_reference, "collision model" },
	{ _field_tag_reference, "animation" },
	{ _field_tag_reference, "physics_model" },
	{ _field_tag_reference, "imposter model" },
	{ _field_long_integer, "runtime render checksum*!" },
	{ _field_long_integer, "runtime collision checksum*!" },
	{ _field_explanation, "Optional Static Lightmap" },
	{ _field_tag_reference, "Lighting Info^" },
	{ _field_long_enum, "Size Class" },
	{ _field_long_flags, "Lightmap Flags{PVS flags}" },
	{ _field_long_block_index, "Lightmap Variant" },
	{ _field_explanation, "PVS" },
	{ _field_real, "PVS bounding box extension factor #How much we extend the PVS region around the objects AABB : [good initial value 2.5]" },
	{ _field_real_vector_3d, "PVS block size #How big a single PVS block is, in world units : [good initial value (2.0,2.0,2.0)]" },
	{ _field_long_integer, "PVS sampling subdivision per axis #How many sample subdivisions we perform per PVS block when generating the data : [good initial value 2]" },
	{ _field_real, "PVS visibility threshold #Minimum amount we need to see of an individual part mesh to care about it : [good initial value 0.004]" },
	{ _field_explanation, "level of detail" },
	{ _field_real, "disappear distance:world units" },
	{ _field_real, "begin fade distance:world units" },
	{ _field_real, "animation lod distance:world units" },
	{ _field_real, "shadow fade distance:world units#NOTE this is only a maximum distance, shadows may fade closer when you exceed the shadow budget, you should balance the total shadows in a scene" },
	{ _field_real, "imposter render distance:world units" },
	{ _field_enum, "imposter quality" },
	{ _field_enum, "imposter policy" },
	{ _field_real, "imposter brightness adjustment" },
	{ _field_real, "instance disappear distance:world units" },
	{ _field_real, "midrange detail disappear distance:world units#distance at which the midrange detail disappears" },
	{ _field_real, "close detail disappear distance:world units#distance at which the close detail disappears" },
	{ _field_real, "tessellation max draw distance:world units" },
	{ _field_long_flags, "resource distance override flags" },
	{ _field_real, "medium priority distance" },
	{ _field_real, "low priority distance" },
	{ _field_block, "variants", &model_variant_block },
	{ _field_block, "region sort", &region_name_block },
	{ _field_block, "instance groups", &global_model_instance_group_block },
	{ _field_block, "model materials*", &model_material_block },
	{ _field_block, "new damage info!", &global_damage_info_block },
	{ _field_struct, "damage info" },
	{ _field_block, "targets old{targets}!", &model_target_block },
	{ _field_block, "model targets", &model_target$2_block },
	{ _field_block, "runtime regions!", &model_region_block },
	{ _field_block, "runtime nodes!", &model_node_block },
	{ _field_long_integer, "runtime node list checksum!" },
	{ _field_explanation, "more stuff" },
	{ _field_tag_reference, "default dialogue#The default dialogue tag for this model (overriden by variants)" },
	{ _field_tag_reference, "default dialogue female#The default FEMALE dialogue tag for this model (overriden by variants)" },
	{ _field_long_flags, "flags" },
	{ _field_string_id, "default dialogue effect#The default dialogue tag for this model (overriden by variants)" },
	{ _field_array, "render-only node flags*!" },
	{ _field_array, "render-only section flags*!" },
	{ _field_long_flags, "runtime flags*!" },
	{ _field_block, "scenario load parameters", &global_scenario_load_parameters_block },
	{ _field_block, "game mode render model override", &model_game_mode_render_model_override_block },
	{ _field_real_fraction, "Sky parallax percent#If flag checked % between sky pos and camera pos 0=camera" },
	{ _field_real, "shadow depth compare bias#Default is 0.002" },
	{ _field_real, "shadow slope scale bias:degrees#controls cutoff point for shadows around edges.  Default is 81 degrees" },
	{ _field_real, "shadow depth compare bias (dynamic lights)#Default is 0.0008" },
	{ _field_real, "shadow slope scale bias (dynamic lights):degrees#controls cutoff point for shadows around edges.  Default is 81 degrees" },
	{ _field_explanation, "PRT Shadows (soft self-shadow)" },
	{ _field_char_enum, "PRT shadow detail!#how much information is recorded about different light directions" },
	{ _field_char_enum, "PRT shadow bounces#0 means direct light only" },
	{ _field_pad, "NCFGBA", 2 },
	{ _field_block, "shadow cast override", &model_self_shadow_region_cast_override_block },
	{ _field_block, "shadow receive override", &model_self_shadow_region_receive_override_block },
	{ _field_block, "occlusion spheres", &model_occlusion_sphere_block },
	{ _field_explanation, "Shield impact overrides!" },
	{ _field_tag_reference, "shield impact parameter override!" },
	{ _field_tag_reference, "1st person shield impact parameter override!" },
	{ _field_real, "runtime bounding radius:world units*!" },
	{ _field_real_point_3d, "runtime bounding offset*!" },
	{ _field_terminator },
};

} // namespace blofeld

