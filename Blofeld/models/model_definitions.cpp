#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(model_variant, k_maximum_variants_per_model)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_array, "runtime variant region indices!" ),
	FIELD( _field_block, "regions", &model_variant_region_block ),
	FIELD( _field_block, "objects", &model_variant_object_block ),
	FIELD( _field_long_block_index, "instance group#selects an instance group for this variant" ),
	FIELD( _field_block, "muted nodes#turn off animation on these named nodes and children", &model_variant_muted_node_block ),
	FIELD( _field_array, "muted flag*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(model_variant_region, MAXIMUM_REGIONS_PER_MODEL)
{
	FIELD( _field_string_id, "region name^:must match region name in render_model" ),
	FIELD( _field_char_integer, "runtime region index!" ),
	FIELD( _field_byte_integer, "runtime flags!" ),
	FIELD( _field_short_block_index, "parent variant" ),
	FIELD( _field_block, "permutations", &model_variant_permutation_block ),
	FIELD( _field_enum, "sort order#negative values mean closer to the camera" ),
	FIELD( _field_pad, "JO", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(model_variant_permutation, MAXIMUM_PERMUTATIONS_PER_MODEL_REGION)
{
	FIELD( _field_string_id, "permutation name^" ),
	FIELD( _field_char_integer, "runtime permutation index!" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "KSJOSR", 2 ),
	FIELD( _field_real, "probability:(0,+inf)" ),
	FIELD( _field_block, "states", &model_variant_state_block ),
	FIELD( _field_array, "runtime state permutation indices!" ),
	FIELD( _field_pad, "LOOEL", 7 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(model_variant_state, MAXIMUM_STATES_PER_MODEL_PERMUTATION)
{
	FIELD( _field_string_id, "permutation name" ),
	FIELD( _field_char_integer, "runtime permutation index!" ),
	FIELD( _field_byte_flags, "property flags" ),
	FIELD( _field_enum, "state^" ),
	FIELD( _field_real_fraction, "initial probability" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(model_variant_object, k_maximum_objects_per_model_variant)
{
	FIELD( _field_custom ),
	FIELD( _field_string_id, "parent marker^" ),
	FIELD( _field_string_id, "parent controlling seat label^#the seat in my parent that will control me" ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "child marker" ),
	FIELD( _field_string_id, "child variant name#optional" ),
	FIELD( _field_tag_reference, "child object" ),
	FIELD( _field_short_block_index, "damage section" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "MVOBP1", 1 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(model_variant_muted_node, k_maximum_muted_nodes_per_model_variant)
{
	FIELD( _field_string_id, "node name^:must match node name in render_model" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(region_name, k_kilo)
{
	FIELD( _field_string_id, "name" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(global_model_instance_group, k_maximum_instance_groups_per_model)
{
	FIELD( _field_string_id, "name^#name of this instance group" ),
	FIELD( _field_long_enum, "choice#how to choose members" ),
	FIELD( _field_block, "member list", &model_instance_group_member_block ),
	FIELD( _field_real, "total probability!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(model_instance_group_member, k_maximum_members_per_instance_group)
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

TAG_BLOCK(model_material, MAXIMUM_MATERIALS_PER_MODEL)
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

TAG_BLOCK(model_target, MAXIMUM_MODEL_TARGETS_PER_MODEL)
{
	FIELD( _field_custom ),
	FIELD( _field_string_id, "marker name^#multiple markers become multiple spheres of the same radius" ),
	FIELD( _field_real, "size#sphere radius" ),
	FIELD( _field_angle, "cone angle#the target is only visible when viewed within this angle of the marker\'s x axis" ),
	FIELD( _field_custom_short_block_index, "damage section#the target is associated with this damage section" ),
	FIELD( _field_short_block_index, "variant#the target will only appear with this variant" ),
	FIELD( _field_real_fraction, "targeting relevance#higher relevances turn into stronger magnetisms" ),
	FIELD( _field_real, "aoe exclusion radius#ignored if zero" ),
	FIELD( _field_struct, "lock-on data" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(model_target$2, MAXIMUM_MODEL_TARGETS_PER_MODEL)
{
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "MTBNP1", 3 ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "marker name^#multiple markers become multiple spheres of the same radius" ),
	FIELD( _field_real, "size#sphere radius" ),
	FIELD( _field_angle, "cone angle#the target is only visible when viewed within this angle of the marker\'s x axis" ),
	FIELD( _field_short_block_index, "damage section#the target is associated with this damage section" ),
	FIELD( _field_short_block_index, "variant#the target will only appear with this variant" ),
	FIELD( _field_real_fraction, "targeting relevance#higher relevances turn into stronger magnetisms" ),
	FIELD( _field_real, "aoe exclusion radius#ignored if zero" ),
	FIELD( _field_struct, "lock-on data" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(model_region, MAXIMUM_REGIONS_PER_MODEL)
{
	FIELD( _field_string_id, "name*^" ),
	FIELD( _field_char_integer, "collision region index*" ),
	FIELD( _field_char_integer, "physics region index*" ),
	FIELD( _field_pad, "QDSJS", 2 ),
	FIELD( _field_block, "permutations*", &model_permutation_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(model_permutation, MAXIMUM_PERMUTATIONS_PER_MODEL_REGION)
{
	FIELD( _field_string_id, "name*^" ),
	FIELD( _field_byte_flags, "flags*" ),
	FIELD( _field_char_integer, "collision permutation index*" ),
	FIELD( _field_char_integer, "physics permutation index*" ),
	FIELD( _field_pad, "AVZQS", 1 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(model_node, MAXIMUM_NODES_PER_MODEL)
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
	FIELD( _field_enum, "game mode^" ),
	FIELD( _field_pad, "BL", 2 ),
	FIELD( _field_tag_reference, "render model override" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(model_self_shadow_region_cast_override, MAXIMUM_REGIONS_PER_MODEL)
{
	FIELD( _field_string_id, "region" ),
	FIELD( _field_string_id, "shadow cast permutation#leave blank for none" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(model_self_shadow_region_receive_override, MAXIMUM_REGIONS_PER_MODEL)
{
	FIELD( _field_string_id, "region" ),
	FIELD( _field_long_enum, "shadow type" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(model_occlusion_sphere, MAXIMUM_REGIONS_PER_MODEL)
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
	FIELD( _field_long_enum, "Size Class" ),
	FIELD( _field_long_flags, "Lightmap Flags{PVS flags}" ),
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
	FIELD( _field_enum, "imposter quality" ),
	FIELD( _field_enum, "imposter policy" ),
	FIELD( _field_real, "imposter brightness adjustment" ),
	FIELD( _field_real, "instance disappear distance:world units" ),
	FIELD( _field_real, "midrange detail disappear distance:world units#distance at which the midrange detail disappears" ),
	FIELD( _field_real, "close detail disappear distance:world units#distance at which the close detail disappears" ),
	FIELD( _field_real, "tessellation max draw distance:world units" ),
	FIELD( _field_long_flags, "resource distance override flags" ),
	FIELD( _field_real, "medium priority distance" ),
	FIELD( _field_real, "low priority distance" ),
	FIELD( _field_block, "variants", &model_variant_block ),
	FIELD( _field_block, "region sort", &region_name_block ),
	FIELD( _field_block, "instance groups", &global_model_instance_group_block ),
	FIELD( _field_block, "model materials*", &model_material_block ),
	FIELD( _field_block, "new damage info!", &global_damage_info_block ),
	FIELD( _field_struct, "damage info" ),
	FIELD( _field_block, "targets old{targets}!", &model_target_block ),
	FIELD( _field_block, "model targets", &model_target$2_block ),
	FIELD( _field_block, "runtime regions!", &model_region_block ),
	FIELD( _field_block, "runtime nodes!", &model_node_block ),
	FIELD( _field_long_integer, "runtime node list checksum!" ),
	FIELD( _field_explanation, "more stuff" ),
	FIELD( _field_tag_reference, "default dialogue#The default dialogue tag for this model (overriden by variants)" ),
	FIELD( _field_tag_reference, "default dialogue female#The default FEMALE dialogue tag for this model (overriden by variants)" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_string_id, "default dialogue effect#The default dialogue tag for this model (overriden by variants)" ),
	FIELD( _field_array, "render-only node flags*!" ),
	FIELD( _field_array, "render-only section flags*!" ),
	FIELD( _field_long_flags, "runtime flags*!" ),
	FIELD( _field_block, "scenario load parameters", &global_scenario_load_parameters_block ),
	FIELD( _field_block, "game mode render model override", &model_game_mode_render_model_override_block ),
	FIELD( _field_real_fraction, "Sky parallax percent#If flag checked % between sky pos and camera pos 0=camera" ),
	FIELD( _field_real, "shadow depth compare bias#Default is 0.002" ),
	FIELD( _field_real, "shadow slope scale bias:degrees#controls cutoff point for shadows around edges.  Default is 81 degrees" ),
	FIELD( _field_real, "shadow depth compare bias (dynamic lights)#Default is 0.0008" ),
	FIELD( _field_real, "shadow slope scale bias (dynamic lights):degrees#controls cutoff point for shadows around edges.  Default is 81 degrees" ),
	FIELD( _field_explanation, "PRT Shadows (soft self-shadow)" ),
	FIELD( _field_char_enum, "PRT shadow detail!#how much information is recorded about different light directions" ),
	FIELD( _field_char_enum, "PRT shadow bounces#0 means direct light only" ),
	FIELD( _field_pad, "NCFGBA", 2 ),
	FIELD( _field_block, "shadow cast override", &model_self_shadow_region_cast_override_block ),
	FIELD( _field_block, "shadow receive override", &model_self_shadow_region_receive_override_block ),
	FIELD( _field_block, "occlusion spheres", &model_occlusion_sphere_block ),
	FIELD( _field_explanation, "Shield impact overrides!" ),
	FIELD( _field_tag_reference, "shield impact parameter override!" ),
	FIELD( _field_tag_reference, "1st person shield impact parameter override!" ),
	FIELD( _field_real, "runtime bounding radius:world units*!" ),
	FIELD( _field_real_point_3d, "runtime bounding offset*!" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

