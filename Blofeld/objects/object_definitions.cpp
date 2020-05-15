#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(sidecarBlock, 1)
{
	{ _field_long_string, "sidecar path*" },
	{ _field_terminator },
};

TAG_BLOCK(object_early_mover_obb, 1)
{
	{ _field_string_id, "node name#empty mean object space" },
	{ _field_long_integer, "runtime node index*!" },
	{ _field_real, "x0" },
	{ _field_real, "x1" },
	{ _field_real, "y0" },
	{ _field_real, "y1" },
	{ _field_real, "z0" },
	{ _field_real, "z1" },
	{ _field_real_euler_angles_3d, "angles" },
	{ _field_terminator },
};

TAG_BLOCK(object_ai_properties, 1)
{
	{ _field_long_flags, "ai flags" },
	{ _field_string_id, "ai type name#used for combat dialogue, etc." },
	{ _field_string_id, "interaction name#if you checked the consider for interaction flag, type what interaction the AI should do with this object (NYI - you can use any)" },
	{ _field_enum, "ai size" },
	{ _field_enum, "leap jump speed" },
	{ _field_terminator },
};

TAG_BLOCK(object_function, k_maximum_object_functions)
{
	{ _field_long_flags, "flags" },
	{ _field_string_id, "import name#if you leave this field blank then you can set this function\'s input value with the hs_function object_set_function_variable" },
	{ _field_string_id, "export name" },
	{ _field_string_id, "turn off with#if the specified function is off, so is this function" },
	{ _field_string_id, "ranged interpolation name#if you have the ranged button checked" },
	{ _field_real, "min value#function must exceed this value (after mapping) to be active 0. means do nothing" },
	{ _field_custom },
	{ _field_struct, "default function" },
	{ _field_string_id, "scale by" },
	{ _field_block, "interpolation", &object_function_interpolation_block },
	{ _field_long_block_index, "runtime interpolator index*!" },
	{ _field_terminator },
};

TAG_BLOCK(object_function_interpolation, 2)
{
	{ _field_long_enum, "interpolation mode" },
	{ _field_real, "linear travel time:s#used by constant velocity" },
	{ _field_real, "acceleration:1/s/s#used by linear acceleration" },
	{ _field_explanation, "springs" },
	{ _field_real, "spring k#used by damped spring\ndetermines acceleration by displacement" },
	{ _field_real, "spring c#used by damped spring\ndetermines damping based on velocity" },
	{ _field_real, "fraction:0-1#used by fractional\nhow mush of the distance to the target to cover each update" },
	{ _field_terminator },
};

TAG_BLOCK(object_runtime_interpolator_functions, k_maximum_object_functions)
{
	{ _field_long_integer, "runtime interpolator to object function mapping*!" },
	{ _field_terminator },
};

TAG_BLOCK(objectFunctionSwitchBlock, ObjectFunctionSwitchDefinition::k_maxCount)
{
	{ _field_string_id, "switch function name" },
	{ _field_string_id, "export name" },
	{ _field_block, "switched functions", &objectFunctionSwitchFunctionBlock_block },
	{ _field_terminator },
};

TAG_BLOCK(objectFunctionSwitchFunctionBlock, ObjectFunctionSwitchDefinition::Function::k_maxCount)
{
	{ _field_real_bounds, "selection bounds#if the switch function is between these values, this function will be picked" },
	{ _field_string_id, "function name^" },
	{ _field_terminator },
};

TAG_BLOCK(global_object_attachment, k_maximum_number_of_attachments_per_object)
{
	{ _field_tag_reference, "type^" },
	{ _field_custom },
	{ _field_old_string_id, "marker" },
	{ _field_char_enum, "change color" },
	{ _field_byte_flags, "flags" },
	{ _field_pad, "DPKP", 2 },
	{ _field_string_id, "primary scale" },
	{ _field_string_id, "secondary scale" },
	{ _field_terminator },
};

TAG_BLOCK(object_widget, MAXIMUM_WIDGETS_PER_OBJECT)
{
	{ _field_tag_reference, "type" },
	{ _field_useless_pad },
	{ _field_terminator },
};

TAG_BLOCK(object_change_colors, k_object_change_color_count)
{
	{ _field_useless_pad },
	{ _field_block, "initial permutations", &object_change_color_initial_permutation_block },
	{ _field_block, "functions", &object_change_color_function_block },
	{ _field_terminator },
};

TAG_BLOCK(object_change_color_initial_permutation, MAXIMUM_NUMBER_OF_OBJECT_CHANGE_COLOR_INITIAL_PERMUTATIONS)
{
	{ _field_real, "weight" },
	{ _field_real_rgb_color, "color lower bound" },
	{ _field_real_rgb_color, "color upper bound" },
	{ _field_string_id, "variant name#if empty, may be used by any model variant" },
	{ _field_terminator },
};

TAG_BLOCK(object_change_color_function, MAXIMUM_NUMBER_OF_OBJECT_CHANGE_COLOR_FUNCTIONS)
{
	{ _field_pad, "TJJWBYNU", 4 },
	{ _field_long_flags, "scale flags" },
	{ _field_real_rgb_color, "color lower bound" },
	{ _field_real_rgb_color, "color upper bound" },
	{ _field_string_id, "darken by" },
	{ _field_string_id, "scale by" },
	{ _field_terminator },
};

TAG_BLOCK(multiplayer_object, k_maximum_multiplayer_object_blocks)
{
	{ _field_explanation, "GAME ENGINE INCLUSION" },
	{ _field_byte_flags, "game engine flags" },
	{ _field_explanation, "TYPE AND FLAGS" },
	{ _field_char_enum, "type" },
	{ _field_byte_flags, "teleporter passability:used only for teleporters" },
	{ _field_char_enum, "spawn timer type" },
	{ _field_explanation, "GOAL & RESPAWN ZONE OBJECT BOUNDARY" },
	{ _field_real, "boundary width/radius" },
	{ _field_real, "boundary box length" },
	{ _field_real, "boundary +height" },
	{ _field_real, "boundary -height" },
	{ _field_char_enum, "boundary shape" },
	{ _field_pad, "pad_shape", 3 },
	{ _field_explanation, "SPAWNING DATA" },
	{ _field_short_integer, "default spawn time:seconds" },
	{ _field_short_integer, "default abandonment time:seconds" },
	{ _field_word_flags, "flags" },
	{ _field_pad, "pad1", 2 },
	{ _field_explanation, "RESPAWN ZONE DATA" },
	{ _field_real, "normal weight:aka natural weight" },
	{ _field_block, "falloff function#Multiplier applied to weight (domain is center to radius, range should be 0 to 1).", &spawn_influence_weight_falloff_function_block },
	{ _field_explanation, "MARKER DATA" },
	{ _field_custom },
	{ _field_string_id, "boundary center marker" },
	{ _field_custom },
	{ _field_string_id, "spawned object marker name" },
	{ _field_explanation, "SPAWNED OBJECT" },
	{ _field_tag_reference, "spawned object" },
	{ _field_string_id, "NYI boundary material" },
	{ _field_explanation, "BOUNDARY SHADER - DEFAULT" },
	{ _field_tag_reference, "boundary standard shader" },
	{ _field_tag_reference, "boundary opaque shader" },
	{ _field_explanation, "BOUNDARY SHADER - SPHERE" },
	{ _field_tag_reference, "sphere standard shader" },
	{ _field_tag_reference, "sphere opaque shader" },
	{ _field_explanation, "BOUNDARY SHADER - CYLINDER" },
	{ _field_tag_reference, "cylinder standard shader" },
	{ _field_tag_reference, "cylinder opaque shader" },
	{ _field_explanation, "BOUNDARY SHADER - BOX" },
	{ _field_tag_reference, "box standard shader" },
	{ _field_tag_reference, "box opaque shader" },
	{ _field_terminator },
};

TAG_BLOCK(object_spawn_effects, 1)
{
	{ _field_explanation, "Spawn Effects" },
	{ _field_tag_reference, "multiplayer spawn effect#effect played when this object spawns in MP games" },
	{ _field_tag_reference, "survival spawn effect#effect played when this object spawns in Firefight games" },
	{ _field_tag_reference, "campaign spawn effect#effect played when this object spawns in Campaign games" },
	{ _field_terminator },
};

TAG_GROUP(object, OBJECT_TAG)
{
	{ _field_custom, "OBJECT" },
	{ _field_short_integer, "runtime object type!" },
	{ _field_char_enum, "Nav Mesh Cutting" },
	{ _field_char_enum, "Nav Mesh Obstacle" },
	{ _field_real_vector_3d, "Nav Mesh Cutting OBB Offset" },
	{ _field_real_vector_3d, "Nav Mesh Cutting OBB Scale" },
	{ _field_long_flags, "flags" },
	{ _field_real, "bounding radius#If you edit this field manually, beware that the render model is no longer respected for radius calculation and that you need to set the bounding offset as well." },
	{ _field_real_point_3d, "bounding offset" },
	{ _field_real, "horizontal acceleration scale{acceleration scale}:[0,+inf]" },
	{ _field_real, "vertical acceleration scale" },
	{ _field_real, "angular acceleration scale" },
	{ _field_enum, "lightmap shadow mode" },
	{ _field_char_enum, "sweetener size" },
	{ _field_char_enum, "water density" },
	{ _field_long_integer, "runtime flags!*" },
	{ _field_real, "dynamic light sphere radius#sphere to use for dynamic lights and shadows. only used if not 0" },
	{ _field_real_point_3d, "dynamic light sphere offset#only used if radius not 0" },
	{ _field_string_id, "generic hud text" },
	{ _field_tag_reference, "generic name list" },
	{ _field_tag_reference, "generic service tag list" },
	{ _field_block, "source sidecar", &sidecarBlock_block },
	{ _field_string_id, "default model variant" },
	{ _field_tag_reference, "model" },
	{ _field_tag_reference, "crate object" },
	{ _field_explanation, "only set this tag if you want to override the default collision damage values in globals.globals" },
	{ _field_tag_reference, "collision damage" },
	{ _field_tag_reference, "brittle collision damage" },
	{ _field_block, "early mover OBB", &object_early_mover_obb_block },
	{ _field_tag_reference, "creation effect" },
	{ _field_tag_reference, "material effects" },
	{ _field_tag_reference, "melee sound#this is the sound that is made when I am meleed.  This overrides the sweetener sound of my material." },
	{ _field_real, "self-destruct time:seconds#if non-zero, any instances of this object will destroy themselves after this many seconds." },
	{ _field_block, "ai properties", &object_ai_properties_block },
	{ _field_block, "functions", &object_function_block },
	{ _field_block, "runtime interpolator functions*!", &object_runtime_interpolator_functions_block },
	{ _field_block, "function switches", &objectFunctionSwitchBlock_block },
	{ _field_short_integer, "hud text message index" },
	{ _field_word_flags, "secondary flags" },
	{ _field_block, "attachments", &global_object_attachment_block },
	{ _field_block, "hull surfaces", &water_physics_hull_surface_definition_block },
	{ _field_block, "jetwash", &jetwash_definition_block },
	{ _field_block, "widgets", &object_widget_block },
	{ _field_block, "change colors", &object_change_colors_block },
	{ _field_block, "predicted resources*", &g_null_block },
	{ _field_block, "multiplayer object", &multiplayer_object_block },
	{ _field_tag_reference, "simulation_interpolation#Set to a specific interpolation definition, or leave blank to inherit the default for the object type (there are defaults for bipeds, vehicles, and crates in multiplayer_globals).  To disable interpolation on a particular object whose type has interpolation by default, set this reference to the special disable_interpolation.simulation_interpolation tag." },
	{ _field_block, "spawn effects", &object_spawn_effects_block },
	{ _field_block, "model dissolve data", &modelDissolveDataBlock_block },
	{ _field_struct, "script data*!" },
	{ _field_block, "script tagalongs", &hs_references_block },
	{ _field_block, "scripted dependencies", &hs_references_block },
	{ _field_explanation, "Object Abandoment" },
	{ _field_struct, "object abandonment" },
	{ _field_custom },
	{ _field_terminator },
};

} // namespace blofeld

