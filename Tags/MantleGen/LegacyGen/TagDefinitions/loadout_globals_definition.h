#pragma once

struct nicename("loadout_globals_definition") tag_group('lgtd') s_loadout_globals_definition_definition_legacy
{
	struct nicename("Default Loadouts") s_default_loadouts_definition_legacy
	{
		enum nicename("Grenade Count") e_grenade_count : uint8_t
		{
			/*nicename("Unchanged")*/ _grenade_count_unchanged = 0ui8,
			/*nicename("Map Default")*/ _grenade_count_map_default = 1ui8,
			/*nicename("None")*/ _grenade_count_none = 2ui8,
			/*nicename("1 Frag")*/ _grenade_count__1_frag = 3ui8,
			/*nicename("2 Frags")*/ _grenade_count__2_frags = 4ui8,
			/*nicename("3 Frags")*/ _grenade_count__3_frags = 5ui8,
			/*nicename("4 Frags")*/ _grenade_count__4_frags = 6ui8,
			/*nicename("1 Plasma")*/ _grenade_count__1_plasma = 7ui8,
			/*nicename("2 Plasmas")*/ _grenade_count__2_plasmas = 8ui8,
			/*nicename("3 Plasmas")*/ _grenade_count__3_plasmas = 9ui8,
			/*nicename("4 Plasmas")*/ _grenade_count__4_plasmas = 10ui8,
			/*nicename("1x Each")*/ _grenade_count__1x_each = 11ui8,
			/*nicename("2x Each")*/ _grenade_count__2x_each = 12ui8,
			/*nicename("3x Each")*/ _grenade_count__3x_each = 13ui8,
			/*nicename("4x Each")*/ _grenade_count__4x_each = 14ui8,
		};

		string_id_legacy nicename("Loadout Name") loadout_name;
		string_id_legacy nicename("Primary Weapon") primary_weapon;
		string_id_legacy nicename("Secondary Weapon") secondary_weapon;
		string_id_legacy nicename("Equipment") equipment;
		e_grenade_count nicename("Grenade Count") grenade_count;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
	};

	struct nicename("Loadout Sets") s_loadout_sets_definition_legacy
	{
		struct nicename("Set Loadouts") s_set_loadouts_definition_legacy
		{
			int16_t nicename("Default Loadout Index") default_loadout_index;
			int16_t __unknown0;
		};

		string_id_legacy nicename("Set Name") set_name;
		s_tag_block_legacy<s_set_loadouts_definition_legacy> nicename("Set Loadouts") set_loadouts_block;
	};

	struct nicename("Custom Loadout Names List") s_custom_loadout_names_list_definition_legacy
	{
		string_id_legacy nicename("Name") name;
	};

	s_tag_block_legacy<s_default_loadouts_definition_legacy> nicename("Default Loadouts") default_loadouts_block;
	s_tag_block_legacy<s_loadout_sets_definition_legacy> nicename("Loadout Sets") loadout_sets_block;
	s_tag_block_legacy<s_custom_loadout_names_list_definition_legacy> nicename("Custom Loadout Names List") custom_loadout_names_list_block;
};

