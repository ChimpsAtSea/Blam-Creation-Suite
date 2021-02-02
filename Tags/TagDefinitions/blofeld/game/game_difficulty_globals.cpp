#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(difficulty_block, 1)
	{
		{ _field_legacy, _field_explanation, "health", "scale values for enemy health and damage settings" },
		{ _field_legacy, _field_real, "easy enemy damage#enemy damage multiplier on easy difficulty" },
		{ _field_legacy, _field_real, "normal enemy damage#enemy damage multiplier on normal difficulty" },
		{ _field_legacy, _field_real, "hard enemy damage#enemy damage multiplier on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. enemy damage#enemy damage multiplier on impossible difficulty" },
		{ _field_legacy, _field_real, "easy enemy vitality#enemy maximum body vitality scale on easy difficulty" },
		{ _field_legacy, _field_real, "normal enemy vitality#enemy maximum body vitality scale on normal difficulty" },
		{ _field_legacy, _field_real, "hard enemy vitality#enemy maximum body vitality scale on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. enemy vitality#enemy maximum body vitality scale on impossible difficulty" },
		{ _field_legacy, _field_real, "easy enemy shield#enemy maximum shield vitality scale on easy difficulty" },
		{ _field_legacy, _field_real, "normal enemy shield#enemy maximum shield vitality scale on normal difficulty" },
		{ _field_legacy, _field_real, "hard enemy shield#enemy maximum shield vitality scale on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. enemy shield#enemy maximum shield vitality scale on impossible difficulty" },
		{ _field_legacy, _field_real, "easy enemy recharge#enemy shield recharge scale on easy difficulty" },
		{ _field_legacy, _field_real, "normal enemy recharge#enemy shield recharge scale on normal difficulty" },
		{ _field_legacy, _field_real, "hard enemy recharge#enemy shield recharge scale on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. enemy recharge#enemy shield recharge scale on impossible difficulty" },
		{ _field_legacy, _field_real, "easy friend damage#friend damage multiplier on easy difficulty" },
		{ _field_legacy, _field_real, "normal friend damage#friend damage multiplier on normal difficulty" },
		{ _field_legacy, _field_real, "hard friend damage#friend damage multiplier on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. friend damage#friend damage multiplier on impossible difficulty" },
		{ _field_legacy, _field_real, "easy friend vitality#friend maximum body vitality scale on easy difficulty" },
		{ _field_legacy, _field_real, "normal friend vitality#friend maximum body vitality scale on normal difficulty" },
		{ _field_legacy, _field_real, "hard friend vitality#friend maximum body vitality scale on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. friend vitality#friend maximum body vitality scale on impossible difficulty" },
		{ _field_legacy, _field_real, "easy friend shield#friend maximum shield vitality scale on easy difficulty" },
		{ _field_legacy, _field_real, "normal friend shield#friend maximum shield vitality scale on normal difficulty" },
		{ _field_legacy, _field_real, "hard friend shield#friend maximum shield vitality scale on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. friend shield#friend maximum shield vitality scale on impossible difficulty" },
		{ _field_legacy, _field_real, "easy friend recharge#friend shield recharge scale on easy difficulty" },
		{ _field_legacy, _field_real, "normal friend recharge#friend shield recharge scale on normal difficulty" },
		{ _field_legacy, _field_real, "hard friend recharge#friend shield recharge scale on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. friend recharge#friend shield recharge scale on impossible difficulty" },
		{ _field_legacy, _field_pad, "$", 16 },
		{ _field_legacy, _field_pad, "$$", 16 },
		{ _field_legacy, _field_explanation, "ranged fire", "difficulty-affecting values for enemy ranged combat settings" },
		{ _field_legacy, _field_real, "easy rate of fire#enemy rate of fire scale on easy difficulty" },
		{ _field_legacy, _field_real, "normal rate of fire#enemy rate of fire scale on normal difficulty" },
		{ _field_legacy, _field_real, "hard rate of fire#enemy rate of fire scale on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. rate of fire#enemy rate of fire scale on impossible difficulty" },
		{ _field_legacy, _field_real, "easy projectile error#enemy projectile error scale, as a fraction of their base firing error. on easy difficulty" },
		{ _field_legacy, _field_real, "normal projectile error#enemy projectile error scale, as a fraction of their base firing error. on normal difficulty" },
		{ _field_legacy, _field_real, "hard projectile error#enemy projectile error scale, as a fraction of their base firing error. on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. projectile error#enemy projectile error scale, as a fraction of their base firing error. on impossible difficulty" },
		{ _field_legacy, _field_real, "easy burst error#enemy burst error scale; reduces intra-burst shot distance. on easy difficulty" },
		{ _field_legacy, _field_real, "normal burst error#enemy burst error scale; reduces intra-burst shot distance. on normal difficulty" },
		{ _field_legacy, _field_real, "hard burst error#enemy burst error scale; reduces intra-burst shot distance. on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. burst error#enemy burst error scale; reduces intra-burst shot distance. on impossible difficulty" },
		{ _field_legacy, _field_real, "easy new target delay#enemy new-target delay scale factor. on easy difficulty" },
		{ _field_legacy, _field_real, "normal new target delay#enemy new-target delay scale factor. on normal difficulty" },
		{ _field_legacy, _field_real, "hard new target delay#enemy new-target delay scale factor. on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. new target delay#enemy new-target delay scale factor. on impossible difficulty" },
		{ _field_legacy, _field_real, "easy burst separation#delay time between bursts scale factor for enemies. on easy difficulty" },
		{ _field_legacy, _field_real, "normal burst separation#delay time between bursts scale factor for enemies. on normal difficulty" },
		{ _field_legacy, _field_real, "hard burst separation#delay time between bursts scale factor for enemies. on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. burst separation#delay time between bursts scale factor for enemies. on impossible difficulty" },
		{ _field_legacy, _field_real, "easy target tracking#additional target tracking fraction for enemies. on easy difficulty" },
		{ _field_legacy, _field_real, "normal target tracking#additional target tracking fraction for enemies. on normal difficulty" },
		{ _field_legacy, _field_real, "hard target tracking#additional target tracking fraction for enemies. on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. target tracking#additional target tracking fraction for enemies. on impossible difficulty" },
		{ _field_legacy, _field_real, "easy target leading#additional target leading fraction for enemies. on easy difficulty" },
		{ _field_legacy, _field_real, "normal target leading#additional target leading fraction for enemies. on normal difficulty" },
		{ _field_legacy, _field_real, "hard target leading#additional target leading fraction for enemies. on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. target leading#additional target leading fraction for enemies. on impossible difficulty" },
		{ _field_legacy, _field_real, "easy overcharge chance#overcharge chance scale factor for enemies. on easy difficulty" },
		{ _field_legacy, _field_real, "normal overcharge chance#overcharge chance scale factor for enemies. on normal difficulty" },
		{ _field_legacy, _field_real, "hard overcharge chance#overcharge chance scale factor for enemies. on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. overcharge chance#overcharge chance scale factor for enemies. on impossible difficulty" },
		{ _field_legacy, _field_real, "easy special fire delay#delay between special-fire shots (overcharge, banshee bombs) scale factor for enemies. on easy difficulty" },
		{ _field_legacy, _field_real, "normal special fire delay#delay between special-fire shots (overcharge, banshee bombs) scale factor for enemies. on normal difficulty" },
		{ _field_legacy, _field_real, "hard special fire delay#delay between special-fire shots (overcharge, banshee bombs) scale factor for enemies. on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. special fire delay#delay between special-fire shots (overcharge, banshee bombs) scale factor for enemies. on impossible difficulty" },
		{ _field_legacy, _field_real, "easy guidance vs player#guidance velocity scale factor for all projectiles targeted on a player. on easy difficulty" },
		{ _field_legacy, _field_real, "normal guidance vs player#guidance velocity scale factor for all projectiles targeted on a player. on normal difficulty" },
		{ _field_legacy, _field_real, "hard guidance vs player#guidance velocity scale factor for all projectiles targeted on a player. on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. guidance vs player#guidance velocity scale factor for all projectiles targeted on a player. on impossible difficulty" },
		{ _field_legacy, _field_real, "easy melee delay base#delay period added to all melee attacks, even when berserk. on easy difficulty" },
		{ _field_legacy, _field_real, "normal melee delay base#delay period added to all melee attacks, even when berserk. on normal difficulty" },
		{ _field_legacy, _field_real, "hard melee delay base#delay period added to all melee attacks, even when berserk. on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. melee delay base#delay period added to all melee attacks, even when berserk. on impossible difficulty" },
		{ _field_legacy, _field_real, "easy melee delay scale#multiplier for all existing non-berserk melee delay times. on easy difficulty" },
		{ _field_legacy, _field_real, "normal melee delay scale#multiplier for all existing non-berserk melee delay times. on normal difficulty" },
		{ _field_legacy, _field_real, "hard melee delay scale#multiplier for all existing non-berserk melee delay times. on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. melee delay scale#multiplier for all existing non-berserk melee delay times. on impossible difficulty" },
		{ _field_legacy, _field_pad, "$$$", 16 },
		{ _field_legacy, _field_explanation, "grenades", "difficulty-affecting values for enemy grenade behavior" },
		{ _field_legacy, _field_real, "easy grenade chance scale#scale factor affecting the desicions to throw a grenade. on easy difficulty" },
		{ _field_legacy, _field_real, "normal grenade chance scale#scale factor affecting the desicions to throw a grenade. on normal difficulty" },
		{ _field_legacy, _field_real, "hard grenade chance scale#scale factor affecting the desicions to throw a grenade. on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. grenade chance scale#scale factor affecting the desicions to throw a grenade. on impossible difficulty" },
		{ _field_legacy, _field_real, "easy grenade timer scale#scale factor affecting the delay period between grenades thrown from the same encounter (lower is more often). on easy difficulty" },
		{ _field_legacy, _field_real, "normal grenade timer scale#scale factor affecting the delay period between grenades thrown from the same encounter (lower is more often). on normal difficulty" },
		{ _field_legacy, _field_real, "hard grenade timer scale#scale factor affecting the delay period between grenades thrown from the same encounter (lower is more often). on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. grenade timer scale#scale factor affecting the delay period between grenades thrown from the same encounter (lower is more often). on impossible difficulty" },
		{ _field_legacy, _field_pad, "$$$$", 16 },
		{ _field_legacy, _field_pad, "$$$$$", 16 },
		{ _field_legacy, _field_pad, "$$$$$$", 16 },
		{ _field_legacy, _field_explanation, "placement", "difficulty-affecting values for enemy placement" },
		{ _field_legacy, _field_real, "easy major upgrade (normal)#fraction of actors upgraded to their major variant. on easy difficulty" },
		{ _field_legacy, _field_real, "normal major upgrade (normal)#fraction of actors upgraded to their major variant. on normal difficulty" },
		{ _field_legacy, _field_real, "hard major upgrade (normal)#fraction of actors upgraded to their major variant. on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. major upgrade (normal)#fraction of actors upgraded to their major variant. on impossible difficulty" },
		{ _field_legacy, _field_real, "easy major upgrade (few)#fraction of actors upgraded to their major variant when mix = normal. on easy difficulty" },
		{ _field_legacy, _field_real, "normal major upgrade (few)#fraction of actors upgraded to their major variant when mix = normal. on normal difficulty" },
		{ _field_legacy, _field_real, "hard major upgrade (few)#fraction of actors upgraded to their major variant when mix = normal. on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. major upgrade (few)#fraction of actors upgraded to their major variant when mix = normal. on impossible difficulty" },
		{ _field_legacy, _field_real, "easy major upgrade (many)#fraction of actors upgraded to their major variant when mix = many. on easy difficulty" },
		{ _field_legacy, _field_real, "normal major upgrade (many)#fraction of actors upgraded to their major variant when mix = many. on normal difficulty" },
		{ _field_legacy, _field_real, "hard major upgrade (many)#fraction of actors upgraded to their major variant when mix = many. on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. major upgrade (many)#fraction of actors upgraded to their major variant when mix = many. on impossible difficulty" },
		{ _field_legacy, _field_explanation, "vehicles", "difficulty-affecting values for vehicle driving/combat" },
		{ _field_legacy, _field_real, "easy player vehicle ram chance#Chance of deciding to ram the player in a vehicle on easy difficulty" },
		{ _field_legacy, _field_real, "normal player vehicle ram chance#Chance of deciding to ram the player in a vehicle on normal difficulty" },
		{ _field_legacy, _field_real, "hard player vehicle ram chance#Chance of deciding to ram the player in a vehicle on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. player vehicle ram chance#Chance of deciding to ram the player in a vehicle on impossible difficulty" },
		{ _field_legacy, _field_real, "easy trick dodge chance scale#Multiplies the chance that a flying vehicle will trick to dodge danger on easy difficulty" },
		{ _field_legacy, _field_real, "normal trick dodge chance scale#Multiplies the chance that a flying vehicle will trick to dodge danger on normal difficulty" },
		{ _field_legacy, _field_real, "hard trick dodge chance scale#Multiplies the chance that a flying vehicle will trick to dodge danger on hard difficulty" },
		{ _field_legacy, _field_real, "imposs. trick dodge chance scale#Multiplies the chance that a flying vehicle will trick to dodge danger on impossible difficulty" },
		{ _field_legacy, _field_pad, "$$$$$$$$", 16 },
		{ _field_legacy, _field_pad, "$$$$$$$$$", 16 },
		{ _field_legacy, _field_pad, "Q", 84 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(coop_difficulty_block, 1)
	{
		{ _field_legacy, _field_explanation, "vitality", "scale values for enemy health and shield settings" },
		{ _field_legacy, _field_real, "two-player shield recharge delay#multiplier on enemy shield recharge delay with two coop players" },
		{ _field_legacy, _field_real, "four-player shield recharge delay#multiplier on enemy shield recharge delay with four coop players" },
		{ _field_legacy, _field_real, "six-player shield recharge delay#multiplier on enemy shield recharge delay with six coop players or more" },
		{ _field_legacy, _field_real, "two-player shield recharge timer#multiplier on enemy shield recharge timer with two coop players" },
		{ _field_legacy, _field_real, "four-player shield recharge timer#multiplier on enemy shield recharge timer with four coop players" },
		{ _field_legacy, _field_real, "six-player shield recharge timer#multiplier on enemy shield recharge timer with six coop players or more" },
		{ _field_legacy, _field_explanation, "movement", "scale values for enemy movement properties" },
		{ _field_legacy, _field_real, "two-player grenade dive chance#multiplier on enemy grenade dive chance with two coop players" },
		{ _field_legacy, _field_real, "four-player grenade dive chance#multiplier on enemy grenade dive chance with four coop players" },
		{ _field_legacy, _field_real, "six-player grenade dive chance#multiplier on enemy grenade dive chance with six coop players or more" },
		{ _field_legacy, _field_real, "two-player armor lock chance#multiplier on enemy armor lock chance with two coop players" },
		{ _field_legacy, _field_real, "four-player armor lock chance#multiplier on enemy armor lock chance with four coop players" },
		{ _field_legacy, _field_real, "six-player armor lock chance#multiplier on enemy armor lock chance with six coop players or more" },
		{ _field_legacy, _field_explanation, "evasion", "scale values for enemy evasion settings" },
		{ _field_legacy, _field_real, "two-player evasion danger threshold#multiplier on enemy evasion danger threshold with two coop players" },
		{ _field_legacy, _field_real, "four-player evasion danger threshold#multiplier on enemy evasion danger threshold with four coop players" },
		{ _field_legacy, _field_real, "six-player evasion danger threshold#multiplier on enemy evasion danger threshold with six coop players or more" },
		{ _field_legacy, _field_real, "two-player evasion delay timer#multiplier on enemy evasion delay timer with two coop players" },
		{ _field_legacy, _field_real, "four-player evasion delay timer#multiplier on enemy evasion delay timer with four coop players" },
		{ _field_legacy, _field_real, "six-player evasion delay timer#multiplier on enemy evasion delay timer with six coop players or more" },
		{ _field_legacy, _field_real, "two-player evasion chance#multiplier on enemy evasion chance with two coop players" },
		{ _field_legacy, _field_real, "four-player evasion chance#multiplier on enemy evasion chance with four coop players" },
		{ _field_legacy, _field_real, "six-player evasion chance#multiplier on enemy evasion chance with six coop players or more" },
		{ _field_legacy, _field_explanation, "shooting", "scale values for enemy shooting settings" },
		{ _field_legacy, _field_real, "two-player burst duration#multiplier on the enemy shooting burst duration with two coop players" },
		{ _field_legacy, _field_real, "four-player burst duration#multiplier on the enemy shooting burst duration with four coop players" },
		{ _field_legacy, _field_real, "six-player burst duration#multiplier on the enemy shooting burst duration with six coop players or more" },
		{ _field_legacy, _field_real, "two-player burst separation#multipler on the enemy shooting burst separation with two coop players" },
		{ _field_legacy, _field_real, "four-player burst separation#multipler on the enemy shooting burst separation with four coop players" },
		{ _field_legacy, _field_real, "six-player burst separation#multipler on the enemy shooting burst separation with six coop players or more" },
		{ _field_legacy, _field_real, "two-player damage modifier#multipler on the enemy shooting damage multiplier with two coop players" },
		{ _field_legacy, _field_real, "four-player damage modifier#multipler on the enemy shooting damage multiplier with four coop players" },
		{ _field_legacy, _field_real, "six-player damage modifier#multipler on the enemy shooting damage multiplier with six coop players or more" },
		{ _field_legacy, _field_explanation, "projectile", "scale values for enemy projectile settings" },
		{ _field_legacy, _field_real, "two-player projectile speed#multiplier on the speed of projectiles fired by enemies with two coop players" },
		{ _field_legacy, _field_real, "four-player projectile speed#multiplier on the speed of projectiles fired by enemies with four coop players" },
		{ _field_legacy, _field_real, "six-player projectile speed#multiplier on the speed of projectiles fired by enemies with six coop players or more" },
		{ _field_legacy, _field_terminator }
	};

} // namespace blofeld

