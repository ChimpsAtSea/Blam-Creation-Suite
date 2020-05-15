#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(active_camo_globals, 1)
{
	{ _field_real, "biped speed reference:wu/s#for bipeds, the speed at which you are on the far right of the \'speed to max camo\' graph" },
	{ _field_real, "vehicle speed reference:wu/s#for vehicles, the speed at which you are on the far right of the \'speed to max camo\' graph" },
	{ _field_real_fraction, "camo value for game name#minimum active camo percentage at which a player\'s game name will start becoming visible" },
	{ _field_struct, "camo value to distortion" },
	{ _field_struct, "camo value to transparency#maps active-camo percentage to alpha for THIRD PERSON rendering" },
	{ _field_struct, "camo value to fp transparency#maps active-camo percentage to alpha for FIRST PERSON rendering" },
	{ _field_struct, "camo distortion texture strength" },
	{ _field_real_vector_2d, "camo distortion scale" },
	{ _field_real_vector_2d, "camo distortion translate speed" },
	{ _field_tag_reference, "camo distortion texture" },
	{ _field_real, "camo depth bias max distance#This is used to deal with ugly rendering artifacts when camo is not fully on" },
	{ _field_struct, "camo depth bias function#This is used to deal with ugly rendering artifacts when camo is not fully on" },
	{ _field_block, "camo levels", &active_camo_level_definition_block },
	{ _field_terminator },
};

TAG_BLOCK(active_camo_level_definition, k_number_of_active_camo_levels)
{
	{ _field_real, "grenade throw penalty:0..1#reduces camo value by this much when throwing a grenade" },
	{ _field_real, "melee penalty:0..1#reduces camo by this much when meleeing" },
	{ _field_real, "minimum dinged value#when taking damage or doing other actions that reduce camo, we will never drop below this value" },
	{ _field_real, "interpolation time:s#time it takes to interpolate from 0.0 to 1.0" },
	{ _field_struct, "speed to maximum camo" },
	{ _field_terminator },
};

} // namespace blofeld

