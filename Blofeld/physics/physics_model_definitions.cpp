#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(physics_model_struct_definition)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_real, "mass scale#scales the mass of each rigid body.  If you leave this field as 0, then it will be calculated from the total mass below." ),
	FIELD( _field_real, "mass#override total mass of all rigid bodies.  Note that this will NOT be the mass of the object if not all rigid bodies are present (for example if you are using permutations)\nIf you set a mass scale above, this field is unused." ),
	FIELD( _field_real, "low freq. deactivation scale#0 is default (1). LESS than 1 deactivates less aggressively. GREATER than 1 is more agressive." ),
	FIELD( _field_real, "high freq. deactivation scale#0 is default (1). LESS than 1 deactivates less aggressively. GREATER than 1 is more agressive." ),
	FIELD( _field_real, "custom shape radius!#0 defaults to .016.  This field is intentionally hidden because we should only alter this for very special situations.  Lower number == lower performance" ),
	FIELD( _field_real, "maximum penetration depth scale#0 is default (1). for objects that are prone to falling through the world we can reduce this number at the cost of performance" ),
	FIELD( _field_char_integer, "import version*!" ),
	FIELD( _field_pad, "pad0", 3 ),
	FIELD( _field_block, "damped spring motors", &physics_model_damped_spring_motor_block ),
	FIELD( _field_block, "position motors", &physics_model_position_motor_block ),
	FIELD( _field_block, "phantom types", &phantom_types_block ),
	FIELD( _field_block, "powered chains", &physics_model_powered_chains_block ),
	FIELD( _field_block, "node edges*", &physics_model_node_constraint_edge_block ),
	FIELD( _field_block, "rigid bodies*", &rigid_bodies_block ),
	FIELD( _field_block, "materials*", &materials_block$3 ),
	FIELD( _field_block, "spheres*", &spheres_block ),
	FIELD( _field_block, "multi spheres*", &multi_spheres_block ),
	FIELD( _field_block, "pills*", &pills_block ),
	FIELD( _field_block, "boxes*", &boxes_block ),
	FIELD( _field_block, "triangles*", &triangles_block ),
	FIELD( _field_block, "polyhedra*", &polyhedra_block ),
	FIELD( _field_block, "polyhedron four vectors*!", &polyhedron_four_vectors_block ),
	FIELD( _field_block, "polyhedron plane equations*!", &polyhedron_plane_equations_block ),
	FIELD( _field_block, "mass distributions*!", &mass_distributions_block ),
	FIELD( _field_block, "lists*!", &lists_block ),
	FIELD( _field_block, "list shapes*!", &list_shapes_block ),
	FIELD( _field_block, "mopps*!", &mopps_block ),
	FIELD( _field_data, "mopp codes*!" ),
	FIELD( _field_block, "hinge constraints*!", &hinge_constraints_block ),
	FIELD( _field_block, "ragdoll constraints*!", &ragdoll_constraints_block ),
	FIELD( _field_block, "regions*", &regions_block ),
	FIELD( _field_block, "nodes*", &nodes_block ),
	FIELD( _field_block, "errors*!", &global_error_report_categories_block ),
	FIELD( _field_block, "point to path curves*!", &point_to_path_curve_block ),
	FIELD( _field_block, "limited hinge constraints*!", &limited_hinge_constraints_block ),
	FIELD( _field_block, "ball and socket constraints*!", &ball_and_socket_constraints_block ),
	FIELD( _field_block, "stiff spring constraints*!", &stiff_spring_constraints_block ),
	FIELD( _field_block, "prismatic constraints*!", &prismatic_constraints_block ),
	FIELD( _field_block, "phantoms*!", &phantoms_block ),
	FIELD( _field_block, "RigidBody Serialized Shapes*", &RigidBodySerializedShapesBlock ),
	FIELD( _field_terminator )
};

TAG_STRUCT(physics_model_motor_reference_struct)
{
	FIELD( _field_enum, "motor type" ),
	FIELD( _field_custom_short_block_index, "index" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(havok_primitive_struct)
{
	FIELD( _field_string_id, "name^*!" ),
	FIELD( _field_char_block_index, "material*" ),
	FIELD( _field_byte_flags, "material flags*" ),
	FIELD( _field_short_integer, "runtime material type*~!" ),
	FIELD( _field_real, "relative mass scale" ),
	FIELD( _field_real_fraction, "friction" ),
	FIELD( _field_real_fraction, "restitution" ),
	FIELD( _field_real, "volume *" ),
	FIELD( _field_real, "mass*!" ),
	FIELD( _field_short_integer, "mass distribution index!" ),
	FIELD( _field_char_block_index, "phantom*" ),
	FIELD( _field_explanation, "collision group override" ),
	FIELD( _field_char_enum, "proxy collision group" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(havok_convex_shape_struct)
{
	FIELD( _field_struct, "base", &havok_shape_struct_struct_definition ),
	FIELD( _field_real, "radius*!" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(havok_shape_struct)
{
	FIELD( _field_long_integer, "field pointer skip!~" ),
	FIELD( _field_short_integer, "size*~!" ),
	FIELD( _field_short_integer, "count*~!" ),
	FIELD( _field_char_integer, "type*~!" ),
	FIELD( _field_char_integer, "dispatchType*~!" ),
	FIELD( _field_char_integer, "bitsPerKey*~!" ),
	FIELD( _field_char_integer, "codecType*~!" ),
	FIELD( _field_long_integer, "user data*~!" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(havok_convex_translate_shape_struct)
{
	FIELD( _field_struct, "convex", &havok_convex_shape_struct_struct_definition ),
	FIELD( _field_long_integer, "field pointer skip!~" ),
	FIELD( _field_struct, "havok shape reference struct", &havok_shape_reference_struct_struct_definition ),
	FIELD( _field_long_integer, "child shape size" ),
	FIELD( _field_real_vector_3d, "translation*!" ),
	FIELD( _field_real, "havok w translation*!!" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(havok_shape_reference_struct)
{
	FIELD( _field_enum, "shape type*" ),
	FIELD( _field_custom_short_block_index, "shape*" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(havok_shape_collection_struct_2010_2)
{
	FIELD( _field_struct, "base", &havok_shape_struct_2010_2_struct_definition ),
	FIELD( _field_long_integer, "field pointer skip!~" ),
	FIELD( _field_char_integer, "disable welding*~" ),
	FIELD( _field_char_integer, "collection type*~" ),
	FIELD( _field_pad, "VDVAPBSS", 2 ),
	FIELD( _field_terminator )
};

TAG_STRUCT(havok_shape_struct_2010_2)
{
	FIELD( _field_long_integer, "field pointer skip!~" ),
	FIELD( _field_short_integer, "size*~!" ),
	FIELD( _field_short_integer, "count*~!" ),
	FIELD( _field_long_integer, "user data*~!" ),
	FIELD( _field_long_integer, "type*~!" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(havok_convex_transform_shape_struct)
{
	FIELD( _field_struct, "convex", &havok_convex_shape_struct_struct_definition ),
	FIELD( _field_long_integer, "field pointer skip!~" ),
	FIELD( _field_struct, "havok shape reference struct", &havok_shape_reference_struct_struct_definition ),
	FIELD( _field_long_integer, "child shape size" ),
	FIELD( _field_real_vector_3d, "rotation i*!" ),
	FIELD( _field_real, "havok w rotation i*!!" ),
	FIELD( _field_real_vector_3d, "rotation j*!" ),
	FIELD( _field_real, "havok w rotation j*!!" ),
	FIELD( _field_real_vector_3d, "rotation k*!" ),
	FIELD( _field_real, "havok w rotation k*!!" ),
	FIELD( _field_real_vector_3d, "translation*!" ),
	FIELD( _field_real, "havok w translation*!!" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(havok_convex_shape_struct_2010_2)
{
	FIELD( _field_struct, "base", &havok_shape_struct_2010_2_struct_definition ),
	FIELD( _field_real, "radius*!" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(constraint_bodies_struct)
{
	FIELD( _field_string_id, "name^*!" ),
	FIELD( _field_short_block_index, "node a*!" ),
	FIELD( _field_short_block_index, "node b*!" ),
	FIELD( _field_real, "a scale*!" ),
	FIELD( _field_real_vector_3d, "a forward*!" ),
	FIELD( _field_real_vector_3d, "a left*!" ),
	FIELD( _field_real_vector_3d, "a up*!" ),
	FIELD( _field_real_point_3d, "a position*!" ),
	FIELD( _field_real, "b scale*!" ),
	FIELD( _field_real_vector_3d, "b forward*!" ),
	FIELD( _field_real_vector_3d, "b left*!" ),
	FIELD( _field_real_vector_3d, "b up*!" ),
	FIELD( _field_real_point_3d, "b position*!" ),
	FIELD( _field_short_block_index, "edge index*!" ),
	FIELD( _field_pad, "H", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(spheres_block, k_maximum_shapes_per_physics_model)
{
	FIELD( _field_struct, "base", &havok_primitive_struct_struct_definition ),
	FIELD( _field_struct, "sphere shape", &havok_convex_shape_struct_struct_definition ),
	FIELD( _field_pad, "algn344", 12 ),
	FIELD( _field_struct, "translate shape", &havok_convex_translate_shape_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(pills_block, k_maximum_shapes_per_physics_model)
{
	FIELD( _field_struct, "base", &havok_primitive_struct_struct_definition ),
	FIELD( _field_struct, "capsule shape", &havok_convex_shape_struct_struct_definition ),
	FIELD( _field_pad, "algn243", 12 ),
	FIELD( _field_real_vector_3d, "bottom*!" ),
	FIELD( _field_real, "havok w bottom*!!" ),
	FIELD( _field_real_vector_3d, "top*!" ),
	FIELD( _field_real, "havok w top*!!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(lists_block, k_maximum_rigid_bodies_per_physics_model)
{
	FIELD( _field_struct, "base", &havok_shape_collection_struct_2010_2_struct_definition ),
	FIELD( _field_long_integer, "field pointer skip!~" ),
	FIELD( _field_long_integer, "child shapes size*" ),
	FIELD( _field_long_integer, "child shapes capacity*!" ),
	FIELD( _field_pad, "nail_in_dick", 12 ),
	FIELD( _field_real_vector_3d, "aabb half extents!*!" ),
	FIELD( _field_real, "havok w aabb half extents!*!!" ),
	FIELD( _field_real_vector_3d, "aabb center!*!" ),
	FIELD( _field_real, "havok w aabb center!*!!" ),
	FIELD( _field_long_integer, "enabled children0" ),
	FIELD( _field_long_integer, "enabled children1" ),
	FIELD( _field_long_integer, "enabled children2" ),
	FIELD( _field_long_integer, "enabled children3" ),
	FIELD( _field_long_integer, "enabled children4" ),
	FIELD( _field_long_integer, "enabled children5" ),
	FIELD( _field_long_integer, "enabled children6" ),
	FIELD( _field_long_integer, "enabled children7" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(list_shapes_block, k_maximum_list_shapes_per_physics_model)
{
	FIELD( _field_struct, "shape reference", &havok_shape_reference_struct_struct_definition ),
	FIELD( _field_long_integer, "collision filter*" ),
	FIELD( _field_long_integer, "shape size*" ),
	FIELD( _field_long_integer, "num child shapes*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(physics_model_damped_spring_motor_block, k_maximum_constraints_per_physics_model)
{
	FIELD( _field_string_id, "name" ),
	FIELD( _field_real, "maximum force#0 defaults to k_real_max" ),
	FIELD( _field_real, "minimum force#0 defaults to maximum force.  In general you should leave this alone unless working on ragdolls or something like them" ),
	FIELD( _field_real, "spring k" ),
	FIELD( _field_real, "damping#0 means default daming of 1.0f" ),
	FIELD( _field_real, "initial position" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(physics_model_position_motor_block, k_maximum_constraints_per_physics_model)
{
	FIELD( _field_string_id, "name" ),
	FIELD( _field_real, "maximum force" ),
	FIELD( _field_real, "minimum force#0 defaults to maximum force.  In general you should leave this alone unless working on ragdolls or something like them" ),
	FIELD( _field_real, "tau#from 0-1.  relative stiffness" ),
	FIELD( _field_real, "damping#from 0-1" ),
	FIELD( _field_real, "proportion recover vel#fraction of recover velocity used.  0 defaults to 1" ),
	FIELD( _field_real, "consant recover vel#velocity used to recover when errors happen.  in degress per second" ),
	FIELD( _field_real, "initial position" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(phantom_types_block, k_maximum_phantom_types_per_physics_model)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_real, "brittle timer:seconds#objects in this phantom volume will be set to brittle collision damage for this amount of time." ),
	FIELD( _field_char_enum, "minimum size" ),
	FIELD( _field_char_enum, "maximum size" ),
	FIELD( _field_pad, "OF", 2 ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "marker name#you don\'t need this if you\'re just generating effects.  If empty it defaults to the up of the object" ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "alignment marker name#you don\'t need this if you\'re just generating effects.  If empty it defaults to \"marker name\"" ),
	FIELD( _field_explanation, "Linear Motion" ),
	FIELD( _field_pad, "WTBFO", 8 ),
	FIELD( _field_real, "hookes law e#0 if you don\'t want this to behave like spring.  1 is a good starting point if you do." ),
	FIELD( _field_real, "linear dead radius#radius from linear motion origin in which acceleration is dead." ),
	FIELD( _field_real, "center acc" ),
	FIELD( _field_real, "center max vel" ),
	FIELD( _field_real, "axis acc" ),
	FIELD( _field_real, "axis max vel" ),
	FIELD( _field_real, "direction acc" ),
	FIELD( _field_real, "direction max vel" ),
	FIELD( _field_real, "orbit acc#negative values spin the opposite direction from positive ones" ),
	FIELD( _field_real, "orbit max vel" ),
	FIELD( _field_pad, "TF", 28 ),
	FIELD( _field_explanation, "Angular Motion" ),
	FIELD( _field_real, "alignment hookes law e#0 if you don\'t want this to behave like spring.  1 is a good starting point if you do." ),
	FIELD( _field_real, "alignment acc" ),
	FIELD( _field_real, "alignment max vel" ),
	FIELD( _field_pad, "TYXJL", 8 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(physics_model_powered_chains_block, k_maximum_constraints_per_physics_model)
{
	FIELD( _field_block, "nodes", &physics_model_powered_chain_nodes_block ),
	FIELD( _field_block, "constraints", &physics_model_powered_chain_constraints_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(physics_model_powered_chain_nodes_block, MAXIMUM_NODES_PER_MODEL)
{
	FIELD( _field_short_block_index, "node" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(physics_model_powered_chain_constraints_block, k_maximum_constraints_per_physics_model)
{
	FIELD( _field_enum, "constraint type" ),
	FIELD( _field_custom_short_block_index, "constraint index" ),
	FIELD( _field_struct, "motor x", &physics_model_motor_reference_struct_struct_definition ),
	FIELD( _field_struct, "motor y", &physics_model_motor_reference_struct_struct_definition ),
	FIELD( _field_struct, "motor z", &physics_model_motor_reference_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(physics_model_node_constraint_edge_block, k_maximum_node_constraint_edges_per_physics_model)
{
	FIELD( _field_short_integer, "runtime material type a!" ),
	FIELD( _field_short_integer, "runtime material type b!" ),
	FIELD( _field_short_block_index, "node a*!" ),
	FIELD( _field_short_block_index, "node b*!" ),
	FIELD( _field_block, "constraints*", &physics_model_constraint_edge_constraint_block ),
	FIELD( _field_string_id, "node a material#if you don\'t fill this out we will pluck the material from the first primitive, of the first rigid body attached to node a" ),
	FIELD( _field_string_id, "node b material#if you don\'t fill this out we will pluck the material from the first primitive, of the first rigid body attached to node b, if node b is none we use whatever material a has" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(physics_model_constraint_edge_constraint_block, k_maximum_constraints_per_physics_model)
{
	FIELD( _field_enum, "type*!" ),
	FIELD( _field_custom_short_block_index, "index*!" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_real, "friction#0 is the default (takes what it was set in max) anything else overrides that value" ),
	FIELD( _field_block, "ragdoll motors", &physics_model_ragdoll_motors_block ),
	FIELD( _field_block, "limited hinge motors", &physics_model_limited_hinge_motors_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(physics_model_ragdoll_motors_block, 1)
{
	FIELD( _field_explanation, "twist" ),
	FIELD( _field_struct, "twist motor", &physics_model_motor_reference_struct_struct_definition ),
	FIELD( _field_explanation, "cone" ),
	FIELD( _field_struct, "cone motor", &physics_model_motor_reference_struct_struct_definition ),
	FIELD( _field_explanation, "plane" ),
	FIELD( _field_struct, "plane motor", &physics_model_motor_reference_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(physics_model_limited_hinge_motors_block, 1)
{
	FIELD( _field_struct, "motor", &physics_model_motor_reference_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(rigid_bodies_block, k_maximum_rigid_bodies_per_physics_model)
{
	FIELD( _field_short_block_index, "node*" ),
	FIELD( _field_short_block_index, "region*" ),
	FIELD( _field_custom_short_block_index, "permutattion*" ),
	FIELD( _field_short_block_index, "serialized shapes*" ),
	FIELD( _field_real_point_3d, "bouding sphere offset*!" ),
	FIELD( _field_real, "bounding sphere radius*!" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_short_block_index, "no phantom power alt" ),
	FIELD( _field_char_enum, "motion type" ),
	FIELD( _field_explanation, "collision group override" ),
	FIELD( _field_char_enum, "proxy collision group" ),
	FIELD( _field_enum, "size" ),
	FIELD( _field_explanation, "inertia tensor scales" ),
	FIELD( _field_real, "inertia tensor scale#0.0 defaults to 1.0" ),
	FIELD( _field_real, "inertia tensor scale x#0.0 defaults to 1.0" ),
	FIELD( _field_real, "inertia tensor scale y#0.0 defaults to 1.0" ),
	FIELD( _field_real, "inertia tensor scale z#0.0 defaults to 1.0" ),
	FIELD( _field_real, "linear damping#this goes from 0-10 (10 is really, really high)" ),
	FIELD( _field_real, "angular damping#this goes from 0-10 (10 is really, really high)" ),
	FIELD( _field_real_vector_3d, "center off mass offset" ),
	FIELD( _field_explanation, "water physics bounding box" ),
	FIELD( _field_real, "water physics x0#x0 value of the water physics aabb" ),
	FIELD( _field_real, "water physics x1#x1 value of the water physics aabb" ),
	FIELD( _field_real, "water physics y0#y0 value of the water physics aabb" ),
	FIELD( _field_real, "water physics y1#y1 value of the water physics aabb" ),
	FIELD( _field_real, "water physics z0#z0 value of the water physics aabb" ),
	FIELD( _field_real, "water physics z1#z1 value of the water physics aabb" ),
	FIELD( _field_long_integer, "Runtime Shape Pointer*~!" ),
	FIELD( _field_real_vector_3d, "center of mass*!" ),
	FIELD( _field_real, "havok w center of mass*!!" ),
	FIELD( _field_real_vector_3d, "intertia tensor x*!" ),
	FIELD( _field_real, "havok w intertia tensor x*!!" ),
	FIELD( _field_real_vector_3d, "intertia tensor y*!" ),
	FIELD( _field_real, "havok w intertia tensor y*!!" ),
	FIELD( _field_real_vector_3d, "intertia tensor z*!" ),
	FIELD( _field_real, "havok w intertia tensor z*!!" ),
	FIELD( _field_long_integer, "runtime havok group mask *!" ),
	FIELD( _field_struct, "shape reference", &havok_shape_reference_struct_struct_definition ),
	FIELD( _field_real, "mass:kg*!" ),
	FIELD( _field_real, "bounding sphere pad#the bounding sphere for this rigid body will be outset by this much" ),
	FIELD( _field_char_enum, "collision quality override type" ),
	FIELD( _field_pad, "pad3", 1 ),
	FIELD( _field_short_integer, "runtime_flags*!" ),
	FIELD( _field_explanation, "Stupid mass override" ),
	FIELD( _field_real, "Mass body override" ),
	FIELD( _field_pad, "pad4", 8 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(materials_block$3, k_maximum_materials_per_physics_model)
{
	FIELD( _field_string_id, "name^*!" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "flags pad", 3 ),
	FIELD( _field_string_id, "global material name" ),
	FIELD( _field_short_block_index, "phantom type" ),
	FIELD( _field_explanation, "collision group override" ),
	FIELD( _field_char_enum, "proxy collision group" ),
	FIELD( _field_char_integer, "runtime collision group*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(multi_spheres_block, k_maximum_shapes_per_physics_model)
{
	FIELD( _field_struct, "base", &havok_primitive_struct_struct_definition ),
	FIELD( _field_struct, "sphere rep shape", &havok_shape_struct_struct_definition ),
	FIELD( _field_long_integer, "num spheres*!" ),
	FIELD( _field_pad, "bull434", 12 ),
	FIELD( _field_array, "four vectors storage*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(boxes_block, k_maximum_shapes_per_physics_model)
{
	FIELD( _field_struct, "base", &havok_primitive_struct_struct_definition ),
	FIELD( _field_struct, "box shape", &havok_convex_shape_struct_struct_definition ),
	FIELD( _field_pad, "algn3473", 12 ),
	FIELD( _field_real_vector_3d, "half extents*!" ),
	FIELD( _field_real, "havok w half extents*!!" ),
	FIELD( _field_struct, "convex transform shape", &havok_convex_transform_shape_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(triangles_block, k_maximum_shapes_per_physics_model)
{
	FIELD( _field_struct, "base", &havok_primitive_struct_struct_definition ),
	FIELD( _field_struct, "triangle shape", &havok_convex_shape_struct_2010_2_struct_definition ),
	FIELD( _field_short_integer, "welding info*!" ),
	FIELD( _field_char_integer, "welding type*!" ),
	FIELD( _field_char_integer, "is extruded*!" ),
	FIELD( _field_pad, "algn92", 8 ),
	FIELD( _field_real_vector_3d, "point a*!" ),
	FIELD( _field_real, "havok w point a*!!" ),
	FIELD( _field_real_vector_3d, "point b*!" ),
	FIELD( _field_real, "havok w point b*!!" ),
	FIELD( _field_real_vector_3d, "point c*!" ),
	FIELD( _field_real, "havok w point c*!!" ),
	FIELD( _field_real_vector_3d, "extrusion*!" ),
	FIELD( _field_real, "havok w extrusion*!!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(polyhedra_block, k_maximum_shapes_per_physics_model)
{
	FIELD( _field_struct, "base", &havok_primitive_struct_struct_definition ),
	FIELD( _field_struct, "polyhedron shape", &havok_convex_shape_struct_struct_definition ),
	FIELD( _field_pad, "algn743", 12 ),
	FIELD( _field_real_vector_3d, "aabb half extents*" ),
	FIELD( _field_real, "havok w aabb half extents*!" ),
	FIELD( _field_real_vector_3d, "aabb center*" ),
	FIELD( _field_real, "havok w aabb center*!" ),
	FIELD( _field_long_integer, "field pointer skip!~" ),
	FIELD( _field_long_integer, "four vectors size*" ),
	FIELD( _field_long_integer, "four vectors capacity*!" ),
	FIELD( _field_long_integer, "num vertices*" ),
	FIELD( _field_char_integer, "m_useSpuBuffer*" ),
	FIELD( _field_pad, "algn434", 3 ),
	FIELD( _field_long_integer, "another field pointer skip!~" ),
	FIELD( _field_long_integer, "plane equations size*" ),
	FIELD( _field_long_integer, "plane equations capacity*!" ),
	FIELD( _field_long_integer, "connectivity*!" ),
	FIELD( _field_pad, "SAMTRA", 12 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(polyhedron_four_vectors_block, k_maximum_four_vectors_per_physics_model)
{
	FIELD( _field_real_vector_3d, "four vectors x*" ),
	FIELD( _field_real, "havok w four vectors x*!" ),
	FIELD( _field_real_vector_3d, "four vectors y*" ),
	FIELD( _field_real, "havok w four vectors y*!" ),
	FIELD( _field_real_vector_3d, "four vectors z*" ),
	FIELD( _field_real, "havok w four vectors z*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(polyhedron_plane_equations_block, k_maximum_plane_equations_per_physics_model)
{
	FIELD( _field_real_vector_3d, "plane equations*!" ),
	FIELD( _field_real, "havok w plane equations*!!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(mass_distributions_block, k_maximum_inertia_tensors_per_physics_model)
{
	FIELD( _field_real_vector_3d, "center of mass*" ),
	FIELD( _field_real, "havok w center of mass*!" ),
	FIELD( _field_real_vector_3d, "inertia tensor i*" ),
	FIELD( _field_real, "havok w inertia tensor i*!" ),
	FIELD( _field_real_vector_3d, "inertia tensor j*" ),
	FIELD( _field_real, "havok w inertia tensor j*!" ),
	FIELD( _field_real_vector_3d, "inertia tensor k*" ),
	FIELD( _field_real, "havok w inertia tensor k*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(mopps_block, k_maximum_rigid_bodies_per_physics_model)
{
	FIELD( _field_struct, "base", &havok_shape_struct_struct_definition ),
	FIELD( _field_pad, "m_bvTreeType", 1 ),
	FIELD( _field_pad, "3 other bytes", 3 ),
	FIELD( _field_long_integer, "mopp code pointer!~" ),
	FIELD( _field_long_integer, "mopp data skip!~" ),
	FIELD( _field_long_integer, "mopp data size~" ),
	FIELD( _field_real_vector_3d, "m_codeInfoCopy*" ),
	FIELD( _field_real, "havok w m_codeInfoCopy*!" ),
	FIELD( _field_long_integer, "child shape vtable*!~" ),
	FIELD( _field_struct, "childShapePointer!~", &havok_shape_reference_struct_struct_definition ),
	FIELD( _field_long_integer, "child size!~" ),
	FIELD( _field_pad, "mopp alignment*!~", 4 ),
	FIELD( _field_real, "scale*!" ),
	FIELD( _field_pad, "final alignment*!~", 12 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(hinge_constraints_block, k_maximum_constraints_per_physics_model)
{
	FIELD( _field_struct, "constraint bodies*!", &constraint_bodies_struct_struct_definition ),
	FIELD( _field_pad, "JENFOXHY", 4 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(ragdoll_constraints_block, k_maximum_constraints_per_physics_model)
{
	FIELD( _field_struct, "constraint bodies*!", &constraint_bodies_struct_struct_definition ),
	FIELD( _field_pad, "OVIM", 4 ),
	FIELD( _field_real, "min twist*!" ),
	FIELD( _field_real, "max twist*!" ),
	FIELD( _field_real, "min cone*!" ),
	FIELD( _field_real, "max cone*!" ),
	FIELD( _field_real, "min plane*!" ),
	FIELD( _field_real, "max plane*!" ),
	FIELD( _field_real, "max friciton torque*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(regions_block, MAXIMUM_REGIONS_PER_MODEL)
{
	FIELD( _field_string_id, "name^*!" ),
	FIELD( _field_block, "permutations", &permutations_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(permutations_block, MAXIMUM_PERMUTATIONS_PER_MODEL_REGION)
{
	FIELD( _field_string_id, "name^*!" ),
	FIELD( _field_block, "rigid bodies", &rigid_body_indices_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(rigid_body_indices_block, k_maximum_rigid_bodies_per_physics_model)
{
	FIELD( _field_short_block_index, "rigid body^*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(nodes_block, MAXIMUM_NODES_PER_MODEL)
{
	FIELD( _field_string_id, "name^*!" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_short_block_index, "parent*!" ),
	FIELD( _field_short_block_index, "sibling*!" ),
	FIELD( _field_short_block_index, "child*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(point_to_path_curve_block, k_maximum_rigid_bodies_per_physics_model)
{
	FIELD( _field_string_id, "name^*!" ),
	FIELD( _field_short_block_index, "node index*!" ),
	FIELD( _field_pad, "TNLRSOSY", 2 ),
	FIELD( _field_block, "points*!", &point_to_path_curve_point_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(point_to_path_curve_point_block, 1024)
{
	FIELD( _field_real_point_3d, "position*!" ),
	FIELD( _field_real, "t value*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(limited_hinge_constraints_block, k_maximum_constraints_per_physics_model)
{
	FIELD( _field_struct, "constraint bodies*!", &constraint_bodies_struct_struct_definition ),
	FIELD( _field_pad, "TC", 4 ),
	FIELD( _field_real, "limit friction*!" ),
	FIELD( _field_real, "limit min angle*!" ),
	FIELD( _field_real, "limit max angle*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(ball_and_socket_constraints_block, k_maximum_constraints_per_physics_model)
{
	FIELD( _field_struct, "constraint bodies*!", &constraint_bodies_struct_struct_definition ),
	FIELD( _field_pad, "UPDLSKB", 4 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(stiff_spring_constraints_block, k_maximum_constraints_per_physics_model)
{
	FIELD( _field_struct, "constraint bodies*!", &constraint_bodies_struct_struct_definition ),
	FIELD( _field_pad, "KGB", 4 ),
	FIELD( _field_real, "spring_length*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(prismatic_constraints_block, k_maximum_constraints_per_physics_model)
{
	FIELD( _field_struct, "constraint bodies*!", &constraint_bodies_struct_struct_definition ),
	FIELD( _field_pad, "XVEPD", 4 ),
	FIELD( _field_real, "min_limit*!" ),
	FIELD( _field_real, "max_limit*!" ),
	FIELD( _field_real, "max_friction_force*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(phantoms_block, k_maximum_phantoms_per_physics_model)
{
	FIELD( _field_struct, "bv shape", &havok_shape_struct_struct_definition ),
	FIELD( _field_struct, "havok shape reference struct1", &havok_shape_reference_struct_struct_definition ),
	FIELD( _field_long_integer, "field pointer skip!~" ),
	FIELD( _field_long_integer, "child shape pointer!~" ),
	FIELD( _field_struct, "phantom shape", &havok_shape_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(RigidBodySerializedShapesBlock, k_maximum_shapes_per_physics_model)
{
	FIELD( _field_block, "Mopp Serialized Havok Data", &MoppSerializedHavokDataBlock ),
	FIELD( _field_terminator )
};

TAG_BLOCK(MoppSerializedHavokDataBlock, k_maximum_rigid_bodies_per_physics_model)
{
	FIELD( _field_struct, "base", &havok_primitive_struct_struct_definition ),
	FIELD( _field_long_integer, "version*" ),
	FIELD( _field_long_integer, "Runtime Deserialized Shape Pointer*~!" ),
	FIELD( _field_data, "Serialized Havok Data*" ),
	FIELD( _field_data, "Serialized Havok Data Any Temp*!" ),
	FIELD( _field_terminator )
};

TAG_GROUP(physics_model_block, PHYSICS_MODEL_TAG)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_real, "mass scale#scales the mass of each rigid body.  If you leave this field as 0, then it will be calculated from the total mass below." ),
	FIELD( _field_real, "mass#override total mass of all rigid bodies.  Note that this will NOT be the mass of the object if not all rigid bodies are present (for example if you are using permutations)\nIf you set a mass scale above, this field is unused." ),
	FIELD( _field_real, "low freq. deactivation scale#0 is default (1). LESS than 1 deactivates less aggressively. GREATER than 1 is more agressive." ),
	FIELD( _field_real, "high freq. deactivation scale#0 is default (1). LESS than 1 deactivates less aggressively. GREATER than 1 is more agressive." ),
	FIELD( _field_real, "custom shape radius!#0 defaults to .016.  This field is intentionally hidden because we should only alter this for very special situations.  Lower number == lower performance" ),
	FIELD( _field_real, "maximum penetration depth scale#0 is default (1). for objects that are prone to falling through the world we can reduce this number at the cost of performance" ),
	FIELD( _field_char_integer, "import version*!" ),
	FIELD( _field_pad, "pad0", 3 ),
	FIELD( _field_block, "damped spring motors", &physics_model_damped_spring_motor_block ),
	FIELD( _field_block, "position motors", &physics_model_position_motor_block ),
	FIELD( _field_block, "phantom types", &phantom_types_block ),
	FIELD( _field_block, "powered chains", &physics_model_powered_chains_block ),
	FIELD( _field_block, "node edges*", &physics_model_node_constraint_edge_block ),
	FIELD( _field_block, "rigid bodies*", &rigid_bodies_block ),
	FIELD( _field_block, "materials*", &materials_block$3 ),
	FIELD( _field_block, "spheres*", &spheres_block ),
	FIELD( _field_block, "multi spheres*", &multi_spheres_block ),
	FIELD( _field_block, "pills*", &pills_block ),
	FIELD( _field_block, "boxes*", &boxes_block ),
	FIELD( _field_block, "triangles*", &triangles_block ),
	FIELD( _field_block, "polyhedra*", &polyhedra_block ),
	FIELD( _field_block, "polyhedron four vectors*!", &polyhedron_four_vectors_block ),
	FIELD( _field_block, "polyhedron plane equations*!", &polyhedron_plane_equations_block ),
	FIELD( _field_block, "mass distributions*!", &mass_distributions_block ),
	FIELD( _field_block, "lists*!", &lists_block ),
	FIELD( _field_block, "list shapes*!", &list_shapes_block ),
	FIELD( _field_block, "mopps*!", &mopps_block ),
	FIELD( _field_data, "mopp codes*!" ),
	FIELD( _field_block, "hinge constraints*!", &hinge_constraints_block ),
	FIELD( _field_block, "ragdoll constraints*!", &ragdoll_constraints_block ),
	FIELD( _field_block, "regions*", &regions_block ),
	FIELD( _field_block, "nodes*", &nodes_block ),
	FIELD( _field_block, "errors*!", &global_error_report_categories_block ),
	FIELD( _field_block, "point to path curves*!", &point_to_path_curve_block ),
	FIELD( _field_block, "limited hinge constraints*!", &limited_hinge_constraints_block ),
	FIELD( _field_block, "ball and socket constraints*!", &ball_and_socket_constraints_block ),
	FIELD( _field_block, "stiff spring constraints*!", &stiff_spring_constraints_block ),
	FIELD( _field_block, "prismatic constraints*!", &prismatic_constraints_block ),
	FIELD( _field_block, "phantoms*!", &phantoms_block ),
	FIELD( _field_block, "RigidBody Serialized Shapes*", &RigidBodySerializedShapesBlock ),
	FIELD( _field_terminator )
};

} // namespace blofeld

