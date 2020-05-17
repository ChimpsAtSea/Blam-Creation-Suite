#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_STRUCT(character_physics_struct)
	{
		FIELD( _field_long_flags, "flags", &character_physics_flags ),
		FIELD( _field_real, "height standing" ),
		FIELD( _field_real, "height crouching" ),
		FIELD( _field_real, "radius" ),
		FIELD( _field_real, "mass" ),
		FIELD( _field_string_id, "living material name#collision material used when character is alive" ),
		FIELD( _field_string_id, "dead material name#collision material used when character is dead" ),
		FIELD( _field_useless_pad ),
		FIELD( _field_short_integer, "runtime global material type!" ),
		FIELD( _field_short_integer, "runtime dead global material type!" ),
		FIELD( _field_useless_pad ),
		FIELD( _field_block, "dead sphere shapes*#don\'t be an asshole, edit something else!", &spheres_block_block ),
		FIELD( _field_block, "pill shapes*#don\'t be an asshole, edit something else!", &pills_block_block ),
		FIELD( _field_block, "sphere shapes*#don\'t be an asshole, edit something else!", &spheres_block_block ),
		FIELD( _field_block, "list sphere shapes*#don\'t be an asshole, edit something else!", &spheres_block_block ),
		FIELD( _field_block, "list shapes*#don\'t be an asshole, edit something else!", &lists_block_block ),
		FIELD( _field_block, "list shape childInfos*#don\'t be an asshole, edit something else!", &list_shapes_block_block ),
		FIELD( _field_explanation, "ground" ),
		FIELD( _field_struct, "ground physics", &character_physics_ground_struct_struct_definition ),
		FIELD( _field_explanation, "flying" ),
		FIELD( _field_struct, "flying physics", &character_physics_flying_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(character_physics_ground_struct)
	{
		FIELD( _field_angle, "maximum slope angle:degrees" ),
		FIELD( _field_angle, "downhill falloff angle:degrees" ),
		FIELD( _field_angle, "downhill cutoff angle:degrees" ),
		FIELD( _field_angle, "uphill falloff angle:degrees" ),
		FIELD( _field_angle, "uphill cutoff angle:degrees" ),
		FIELD( _field_real, "downhill velocity scale" ),
		FIELD( _field_real, "uphill velocity scale" ),
		FIELD( _field_real, "runtime_minimum_normal_k!" ),
		FIELD( _field_real, "runtime_downhill_k0!" ),
		FIELD( _field_real, "runtime_downhill_k1!" ),
		FIELD( _field_real, "runtime_uphill_k0!" ),
		FIELD( _field_real, "runtime_uphill_k1!" ),
		FIELD( _field_angle, "climb inflection angle#angle for bipeds at which climb direction changes between up and down" ),
		FIELD( _field_real, "scale airborne reaction time#scale on the time for the entity to realize it is airborne" ),
		FIELD( _field_real, "scale ground adhesion velocity#scale on velocity with which the entity is pushed back into its ground plane (set to -1 to lock to ground)" ),
		FIELD( _field_real, "gravity scale#scale on gravity for this entity" ),
		FIELD( _field_real, "airborne acceleration scale#scale on airborne acceleration maximum" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(character_physics_flying_struct)
	{
		FIELD( _field_angle, "bank angle:degrees#angle at which we bank left/right when sidestepping or turning while moving forwards" ),
		FIELD( _field_real, "bank apply time:seconds#time it takes us to apply a bank" ),
		FIELD( _field_real, "bank decay time:seconds#time it takes us to recover from a bank" ),
		FIELD( _field_real, "pitch ratio#amount that we pitch up/down when moving up or down" ),
		FIELD( _field_real, "max velocity:world units per second#max velocity when not crouching" ),
		FIELD( _field_real, "max sidestep velocity:world units per second#max sideways or up/down velocity when not crouching" ),
		FIELD( _field_real, "acceleration:world units per second squared" ),
		FIELD( _field_real, "deceleration:world units per second squared" ),
		FIELD( _field_angle, "angular velocity maximum:degrees per second#turn rate" ),
		FIELD( _field_angle, "angular acceleration maximum:degrees per second squared#turn acceleration rate" ),
		FIELD( _field_real, "crouch velocity modifier:[0,1]#how much slower we fly if crouching (zero = same speed)" ),
		FIELD( _field_long_flags, "flags", &flying_physics_flags ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(flying_physics_flags, 1)
	{
		OPTION("use world up"),
	};

	TAG_ENUM(character_physics_flags, 13)
	{
		OPTION("centered_at_origin"),
		OPTION("shape spherical"),
		OPTION("use player physics"),
		OPTION("climb any surface"),
		OPTION("flying"),
		OPTION("not physical"),
		OPTION("dead character collision group"),
		OPTION("suppress ground planes on bipeds"),
		OPTION("physical ragdoll"),
		OPTION("do not resize dead spheres"),
		OPTION("multiple Mantis shapes"),
		OPTION("I am an Extreme Slipsurface"),
		OPTION("slips off movers"),
	};

} // namespace blofeld

