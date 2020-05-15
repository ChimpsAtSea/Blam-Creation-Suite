#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(sidecarBlock, 1)
{
	FIELD( _field_long_string, "sidecar path*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(object_early_mover_obb, 1)
{
	FIELD( _field_string_id, "node name#empty mean object space" ),
	FIELD( _field_long_integer, "runtime node index*!" ),
	FIELD( _field_real, "x0" ),
	FIELD( _field_real, "x1" ),
	FIELD( _field_real, "y0" ),
	FIELD( _field_real, "y1" ),
	FIELD( _field_real, "z0" ),
	FIELD( _field_real, "z1" ),
	FIELD( _field_real_euler_angles_3d, "angles" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(object_ai_properties, 1)
{
	FIELD( _field_long_flags, "ai flags" ),
	FIELD( _field_string_id, "ai type name#used for combat dialogue, etc." ),
	FIELD( _field_string_id, "interaction name#if you checked the consider for interaction flag, type what interaction the AI should do with this object (NYI - you can use any)" ),
	FIELD( _field_enum, "ai size" ),
	FIELD( _field_enum, "leap jump speed" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(object_function, k_maximum_object_functions)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_string_id, "import name#if you leave this field blank then you can set this function\'s input value with the hs_function object_set_function_variable" ),
	FIELD( _field_string_id, "export name" ),
	FIELD( _field_string_id, "turn off with#if the specified function is off, so is this function" ),
	FIELD( _field_string_id, "ranged interpolation name#if you have the ranged button checked" ),
	FIELD( _field_real, "min value#function must exceed this value (after mapping) to be active 0. means do nothing" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "default function" ),
	FIELD( _field_string_id, "scale by" ),
	FIELD( _field_block, "interpolation", &object_function_interpolation_block ),
	FIELD( _field_long_block_index, "runtime interpolator index*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(object_function_interpolation, 2)
{
	FIELD( _field_long_enum, "interpolation mode" ),
	FIELD( _field_real, "linear travel time:s#used by constant velocity" ),
	FIELD( _field_real, "acceleration:1/s/s#used by linear acceleration" ),
	FIELD( _field_explanation, "springs" ),
	FIELD( _field_real, "spring k#used by damped spring\ndetermines acceleration by displacement" ),
	FIELD( _field_real, "spring c#used by damped spring\ndetermines damping based on velocity" ),
	FIELD( _field_real, "fraction:0-1#used by fractional\nhow mush of the distance to the target to cover each update" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(object_runtime_interpolator_functions, k_maximum_object_functions)
{
	FIELD( _field_long_integer, "runtime interpolator to object function mapping*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(objectFunctionSwitchBlock, ObjectFunctionSwitchDefinition::k_maxCount)
{
	FIELD( _field_string_id, "switch function name" ),
	FIELD( _field_string_id, "export name" ),
	FIELD( _field_block, "switched functions", &objectFunctionSwitchFunctionBlock_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(objectFunctionSwitchFunctionBlock, ObjectFunctionSwitchDefinition::Function::k_maxCount)
{
	FIELD( _field_real_bounds, "selection bounds#if the switch function is between these values, this function will be picked" ),
	FIELD( _field_string_id, "function name^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(global_object_attachment, k_maximum_number_of_attachments_per_object)
{
	FIELD( _field_tag_reference, "type^" ),
	FIELD( _field_custom ),
	FIELD( _field_old_string_id, "marker" ),
	FIELD( _field_char_enum, "change color" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "DPKP", 2 ),
	FIELD( _field_string_id, "primary scale" ),
	FIELD( _field_string_id, "secondary scale" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(object_widget, MAXIMUM_WIDGETS_PER_OBJECT)
{
	FIELD( _field_tag_reference, "type" ),
	FIELD( _field_useless_pad ),
	FIELD( _field_terminator )
};

TAG_BLOCK(object_change_colors, k_object_change_color_count)
{
	FIELD( _field_useless_pad ),
	FIELD( _field_block, "initial permutations", &object_change_color_initial_permutation_block ),
	FIELD( _field_block, "functions", &object_change_color_function_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(object_change_color_initial_permutation, MAXIMUM_NUMBER_OF_OBJECT_CHANGE_COLOR_INITIAL_PERMUTATIONS)
{
	FIELD( _field_real, "weight" ),
	FIELD( _field_real_rgb_color, "color lower bound" ),
	FIELD( _field_real_rgb_color, "color upper bound" ),
	FIELD( _field_string_id, "variant name#if empty, may be used by any model variant" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(object_change_color_function, MAXIMUM_NUMBER_OF_OBJECT_CHANGE_COLOR_FUNCTIONS)
{
	FIELD( _field_pad, "TJJWBYNU", 4 ),
	FIELD( _field_long_flags, "scale flags" ),
	FIELD( _field_real_rgb_color, "color lower bound" ),
	FIELD( _field_real_rgb_color, "color upper bound" ),
	FIELD( _field_string_id, "darken by" ),
	FIELD( _field_string_id, "scale by" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(multiplayer_object, k_maximum_multiplayer_object_blocks)
{
	FIELD( _field_explanation, "GAME ENGINE INCLUSION" ),
	FIELD( _field_byte_flags, "game engine flags" ),
	FIELD( _field_explanation, "TYPE AND FLAGS" ),
	FIELD( _field_char_enum, "type" ),
	FIELD( _field_byte_flags, "teleporter passability:used only for teleporters" ),
	FIELD( _field_char_enum, "spawn timer type" ),
	FIELD( _field_explanation, "GOAL & RESPAWN ZONE OBJECT BOUNDARY" ),
	FIELD( _field_real, "boundary width/radius" ),
	FIELD( _field_real, "boundary box length" ),
	FIELD( _field_real, "boundary +height" ),
	FIELD( _field_real, "boundary -height" ),
	FIELD( _field_char_enum, "boundary shape" ),
	FIELD( _field_pad, "pad_shape", 3 ),
	FIELD( _field_explanation, "SPAWNING DATA" ),
	FIELD( _field_short_integer, "default spawn time:seconds" ),
	FIELD( _field_short_integer, "default abandonment time:seconds" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "pad1", 2 ),
	FIELD( _field_explanation, "RESPAWN ZONE DATA" ),
	FIELD( _field_real, "normal weight:aka natural weight" ),
	FIELD( _field_block, "falloff function#Multiplier applied to weight (domain is center to radius, range should be 0 to 1).", &spawn_influence_weight_falloff_function_block ),
	FIELD( _field_explanation, "MARKER DATA" ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "boundary center marker" ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "spawned object marker name" ),
	FIELD( _field_explanation, "SPAWNED OBJECT" ),
	FIELD( _field_tag_reference, "spawned object" ),
	FIELD( _field_string_id, "NYI boundary material" ),
	FIELD( _field_explanation, "BOUNDARY SHADER - DEFAULT" ),
	FIELD( _field_tag_reference, "boundary standard shader" ),
	FIELD( _field_tag_reference, "boundary opaque shader" ),
	FIELD( _field_explanation, "BOUNDARY SHADER - SPHERE" ),
	FIELD( _field_tag_reference, "sphere standard shader" ),
	FIELD( _field_tag_reference, "sphere opaque shader" ),
	FIELD( _field_explanation, "BOUNDARY SHADER - CYLINDER" ),
	FIELD( _field_tag_reference, "cylinder standard shader" ),
	FIELD( _field_tag_reference, "cylinder opaque shader" ),
	FIELD( _field_explanation, "BOUNDARY SHADER - BOX" ),
	FIELD( _field_tag_reference, "box standard shader" ),
	FIELD( _field_tag_reference, "box opaque shader" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(object_spawn_effects, 1)
{
	FIELD( _field_explanation, "Spawn Effects" ),
	FIELD( _field_tag_reference, "multiplayer spawn effect#effect played when this object spawns in MP games" ),
	FIELD( _field_tag_reference, "survival spawn effect#effect played when this object spawns in Firefight games" ),
	FIELD( _field_tag_reference, "campaign spawn effect#effect played when this object spawns in Campaign games" ),
	FIELD( _field_terminator )
};

TAG_GROUP(object, OBJECT_TAG)
{
	FIELD( _field_custom, "OBJECT" ),
	FIELD( _field_short_integer, "runtime object type!" ),
	FIELD( _field_char_enum, "Nav Mesh Cutting" ),
	FIELD( _field_char_enum, "Nav Mesh Obstacle" ),
	FIELD( _field_real_vector_3d, "Nav Mesh Cutting OBB Offset" ),
	FIELD( _field_real_vector_3d, "Nav Mesh Cutting OBB Scale" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_real, "bounding radius#If you edit this field manually, beware that the render model is no longer respected for radius calculation and that you need to set the bounding offset as well." ),
	FIELD( _field_real_point_3d, "bounding offset" ),
	FIELD( _field_real, "horizontal acceleration scale{acceleration scale}:[0,+inf]" ),
	FIELD( _field_real, "vertical acceleration scale" ),
	FIELD( _field_real, "angular acceleration scale" ),
	FIELD( _field_enum, "lightmap shadow mode" ),
	FIELD( _field_char_enum, "sweetener size" ),
	FIELD( _field_char_enum, "water density" ),
	FIELD( _field_long_integer, "runtime flags!*" ),
	FIELD( _field_real, "dynamic light sphere radius#sphere to use for dynamic lights and shadows. only used if not 0" ),
	FIELD( _field_real_point_3d, "dynamic light sphere offset#only used if radius not 0" ),
	FIELD( _field_string_id, "generic hud text" ),
	FIELD( _field_tag_reference, "generic name list" ),
	FIELD( _field_tag_reference, "generic service tag list" ),
	FIELD( _field_block, "source sidecar", &sidecarBlock_block ),
	FIELD( _field_string_id, "default model variant" ),
	FIELD( _field_tag_reference, "model" ),
	FIELD( _field_tag_reference, "crate object" ),
	FIELD( _field_explanation, "only set this tag if you want to override the default collision damage values in globals.globals" ),
	FIELD( _field_tag_reference, "collision damage" ),
	FIELD( _field_tag_reference, "brittle collision damage" ),
	FIELD( _field_block, "early mover OBB", &object_early_mover_obb_block ),
	FIELD( _field_tag_reference, "creation effect" ),
	FIELD( _field_tag_reference, "material effects" ),
	FIELD( _field_tag_reference, "melee sound#this is the sound that is made when I am meleed.  This overrides the sweetener sound of my material." ),
	FIELD( _field_real, "self-destruct time:seconds#if non-zero, any instances of this object will destroy themselves after this many seconds." ),
	FIELD( _field_block, "ai properties", &object_ai_properties_block ),
	FIELD( _field_block, "functions", &object_function_block ),
	FIELD( _field_block, "runtime interpolator functions*!", &object_runtime_interpolator_functions_block ),
	FIELD( _field_block, "function switches", &objectFunctionSwitchBlock_block ),
	FIELD( _field_short_integer, "hud text message index" ),
	FIELD( _field_word_flags, "secondary flags" ),
	FIELD( _field_block, "attachments", &global_object_attachment_block ),
	FIELD( _field_block, "hull surfaces", &water_physics_hull_surface_definition_block ),
	FIELD( _field_block, "jetwash", &jetwash_definition_block ),
	FIELD( _field_block, "widgets", &object_widget_block ),
	FIELD( _field_block, "change colors", &object_change_colors_block ),
	FIELD( _field_block, "predicted resources*", &g_null_block ),
	FIELD( _field_block, "multiplayer object", &multiplayer_object_block ),
	FIELD( _field_tag_reference, "simulation_interpolation#Set to a specific interpolation definition, or leave blank to inherit the default for the object type (there are defaults for bipeds, vehicles, and crates in multiplayer_globals).  To disable interpolation on a particular object whose type has interpolation by default, set this reference to the special disable_interpolation.simulation_interpolation tag." ),
	FIELD( _field_block, "spawn effects", &object_spawn_effects_block ),
	FIELD( _field_block, "model dissolve data", &modelDissolveDataBlock_block ),
	FIELD( _field_struct, "script data*!" ),
	FIELD( _field_block, "script tagalongs", &hs_references_block ),
	FIELD( _field_block, "scripted dependencies", &hs_references_block ),
	FIELD( _field_explanation, "Object Abandoment" ),
	FIELD( _field_struct, "object abandonment" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

} // namespace blofeld

