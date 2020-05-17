#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(multiplayer_object_boundary_shape, 4)
	{
		OPTION("unused"),
		OPTION("sphere"),
		OPTION("cylinder"),
		OPTION("box"),
	};

	TAG_ENUM(multiplayer_object_type, 36)
	{
		OPTION("ordinary"),
		OPTION("weapon"),
		OPTION("grenade"),
		OPTION("projectile"),
		OPTION("powerup"),
		OPTION("equipment"),
		OPTION("ammo pack"),
		OPTION("light land vehicle"),
		OPTION("heavy land vehicle"),
		OPTION("flying vehicle"),
		OPTION("turret"),
		OPTION("device"),
		OPTION("dispenser"),
		OPTION("teleporter 2way"),
		OPTION("teleporter sender"),
		OPTION("teleporter receiver"),
		OPTION("player spawn location"),
		OPTION("player respawn zone"),
		OPTION("secondary objective"),
		OPTION("primary objective"),
		OPTION("named location area"),
		OPTION("danger zone"),
		OPTION("fireteam 1 respawn zone"),
		OPTION("fireteam 2 respawn zone"),
		OPTION("fireteam 3 respawn zone"),
		OPTION("fireteam 4 respawn zone"),
		OPTION("safe volume"),
		OPTION("kill volume"),
		OPTION("cinematic camera position"),
		OPTION("mosh enemy spawn location"),
		OPTION("ordnance drop point"),
		OPTION("trait zone"),
		OPTION("initial ordnance drop point"),
		OPTION("random ordnance drop point"),
		OPTION("objective ordnance drop point"),
		OPTION("personal ordnance drop point"),
	};

} // namespace blofeld

