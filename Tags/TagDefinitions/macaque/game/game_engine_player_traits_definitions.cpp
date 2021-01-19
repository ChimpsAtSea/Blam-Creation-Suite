#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	STRINGS(player_trait_damage_resistance)
	{
		"unchanged",
		"10 percent",
		"50 percent",
		"90 percent",
		"100 percent",
		"110 percent",
		"150 percent",
		"200 percent",
		"300 percent",
		"500 percent",
		"1000 percent",
		"2000 percent",
		"invulnerable"
	};
	STRING_LIST(player_trait_damage_resistance, player_trait_damage_resistance_strings, _countof(player_trait_damage_resistance_strings));

	STRINGS(player_trait_damage_modifier)
	{
		"unchanged",
		"0 percent",
		"25 percent",
		"50 percent",
		"75 percent",
		"90 percent",
		"100 percent",
		"110 percent",
		"125 percent",
		"150 percent",
		"200 percent",
		"300 percent",
		"fatality"
	};
	STRING_LIST(player_trait_damage_modifier, player_trait_damage_modifier_strings, _countof(player_trait_damage_modifier_strings));

} // namespace macaque

} // namespace blofeld

