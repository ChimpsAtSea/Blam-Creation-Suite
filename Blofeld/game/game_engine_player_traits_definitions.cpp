#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(player_trait_damage_resistance, 13)
	{
		OPTION("unchanged"),
		OPTION("10 percent"),
		OPTION("50 percent"),
		OPTION("90 percent"),
		OPTION("100 percent"),
		OPTION("110 percent"),
		OPTION("150 percent"),
		OPTION("200 percent"),
		OPTION("300 percent"),
		OPTION("500 percent"),
		OPTION("1000 percent"),
		OPTION("2000 percent"),
		OPTION("invulnerable"),
	};

	TAG_ENUM(player_trait_damage_modifier, 13)
	{
		OPTION("unchanged"),
		OPTION("0 percent"),
		OPTION("25 percent"),
		OPTION("50 percent"),
		OPTION("75 percent"),
		OPTION("90 percent"),
		OPTION("100 percent"),
		OPTION("110 percent"),
		OPTION("125 percent"),
		OPTION("150 percent"),
		OPTION("200 percent"),
		OPTION("300 percent"),
		OPTION("fatality"),
	};

} // namespace blofeld

