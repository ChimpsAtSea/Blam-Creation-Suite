#include <halo3lib-private-pch.h>

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */
/* ---------- private prototypes */

void print_mainmenu_ui_globals_test_command();
void first_person_weapon_offset_test_command();
void use_30_tick_command();

/* ---------- public code */

c_halo3_test_command::c_halo3_test_command()
{
	c_console::register_command(k_halo3_test_command_name, this);
}

c_halo3_test_command::~c_halo3_test_command()
{
	c_console::unregister_command(k_halo3_test_command_name);
}

bool c_halo3_test_command::execute_command(const std::vector<std::string>& arguments)
{
	if (arguments.empty()) return true;

	if (!arguments.front().compare(k_halo3_test_command_name))
	{
		if (arguments.size() >= 2)
		{
			const std::string& arg1 = arguments[1];

			c_console::set_text_color(_console_color_info);

			if (!arg1.compare("print_mainmenu_ui_globals"))
			{
				print_mainmenu_ui_globals_test_command();
			}
			else if (!arg1.compare("first_person_weapon_offset"))
			{
				first_person_weapon_offset_test_command();
			}
			else if (!arg1.compare("use_30_tick"))
			{
				use_30_tick_command();
			}
		}
		else return false;
	}
	return true;
}

std::string c_halo3_test_command::get_command_info(const std::string& topic) const
{
	if (!topic.empty())
	{
		if (!topic.compare(k_halo3_test_command_name))
		{
			return
				"test\n"
				"Usage: test <command>\n"
				"Commands:\n"
				"\tprint_mainmenu_ui_globals\n";
				"\tfirst_person_weapon_offset\n";
				"\tuse_30_tick\n";
		}
	}
	return "";
}

std::string c_halo3_test_command::get_command_auto_complete(const std::vector<std::string>& Arguments) const
{
	if (Arguments.size() > 1)
	{
		if (!Arguments[1].compare("p"))
		{
			return "print_mainmenu_ui_globals";
		}
		else if (!Arguments[1].compare("f"))
		{
			return "first_person_weapon_offset";
		}
		else if (!Arguments[1].compare("u"))
		{
			return "use_30_tick";
		}
	}

	return "";
}

/* ---------- private code */

using namespace blofeld::halo3;

extern char* halo3_tag_definition_get(unsigned long group, const char* tag_name);
extern char* halo3_tag_address_get(uint32_t tag_instance_address);
extern char* halo3_tag_definition_get(uint32_t index);
extern const char* halo3_tag_name_get(unsigned long tag_index);

void print_mainmenu_ui_globals_test_command()
{
	// #TODO: the globals structure isn't currently the correct size for Halo 3, someone please fix that
	//if (s_globals_struct_definition* globals = reinterpret_cast<s_globals_struct_definition*>(halo3_tag_definition_get(blofeld::GLOBALS_TAG, "globals\\globals")); globals)
	if (char* globals = halo3_tag_definition_get(blofeld::GLOBALS_TAG, "globals\\globals"); globals)
	{
		//if (decltype(globals->interface_tags_block) interface_tags_block = globals->interface_tags_block; interface_tags_block.count)
		if (unsigned long interface_tag_block_count = *reinterpret_cast<unsigned long*>(&globals[0x134] + 0); interface_tag_block_count)
		{
			//if (decltype(interface_tags_block.get_element(0)) interface_tag = interface_tags_block.get_element(0); interface_tag)
			if (char* interface_tag = halo3_tag_address_get(*reinterpret_cast<unsigned long*>(&globals[0x134] + 4)); interface_tag)
			{
				//if (decltype(interface_tag->mainmenu_ui_globals) mainmenu_ui_globals_reference = interface_tag->mainmenu_ui_globals; mainmenu_ui_globals_reference.group_tag == blofeld::USER_INTERFACE_GLOBALS_DEFINITION_TAG)
				if (unsigned long mainmenu_ui_globals_group = *reinterpret_cast<unsigned long*>(&interface_tag[0xE0] + 0); mainmenu_ui_globals_group == blofeld::USER_INTERFACE_GLOBALS_DEFINITION_TAG)
				{
					//if (unsigned short mainmenu_ui_globals_index = mainmenu_ui_globals_reference.index; mainmenu_ui_globals_index)
					if (unsigned short mainmenu_ui_globals_index = *reinterpret_cast<unsigned short*>(&interface_tag[0xE0] + 12); mainmenu_ui_globals_index)
					{
						if (char* mainmenu_ui_globals = halo3_tag_definition_get(mainmenu_ui_globals_index); mainmenu_ui_globals)
						{
							// #TODO: get full name via the tag reference group index
							union { uint64_t value; char string[8]; } group;
							//group.value = _byteswap_ulong(mainmenu_ui_globals_reference.group_tag);
							group.value = _byteswap_ulong(*reinterpret_cast<unsigned long*>(&interface_tag[0xE0] + 0));

							const char* mainmenu_ui_globals_name = halo3_tag_name_get(mainmenu_ui_globals_index);
							const char* mainmenu_ui_globals_group_short_name = group.string;
							c_console::write_line_verbose("mainmenu ui globals: '%s.%s'", mainmenu_ui_globals_name, mainmenu_ui_globals_group_short_name);
							debug_point;
						}
					}
				}
				else
				{
					c_console::write_line_verbose("no mainmenu ui globals tag exists or has the wrong group tag");
					debug_point;
				}
			}
		}
	}
}

s_weapon_block_struct* weapon_get(const char* tag_name)
{
	if (char* weapon = halo3_tag_definition_get(blofeld::WEAPON_TAG, tag_name); weapon)
	{
		return reinterpret_cast<s_weapon_block_struct*>(weapon);
	}
	return nullptr;
}

template<bool is_centered>
real_vector3d& first_person_weapon_offset_get(const char* tag_name)
{
	static real_vector3d default_offset = {};
	if (s_weapon_block_struct& weapon = *weapon_get(tag_name); &weapon)
	{
		return is_centered ? weapon.centered_first_person_weapon_offset : weapon.first_person_weapon_offset;
	}
	return default_offset;
}

void first_person_weapon_offset_test_command()
{
	real_vector3d& energy_blade_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\melee\\energy_blade\\energy_blade");
	real_vector3d& energy_blade_centered = first_person_weapon_offset_get<true>("objects\\weapons\\melee\\energy_blade\\energy_blade");
	real_vector3d& energy_blade_useless_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\melee\\energy_blade\\energy_blade_useless");
	real_vector3d& energy_blade_useless_centered = first_person_weapon_offset_get<true>("objects\\weapons\\melee\\energy_blade\\energy_blade_useless");
	real_vector3d& gravity_hammer_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\melee\\gravity_hammer\\gravity_hammer");
	real_vector3d& gravity_hammer_centered = first_person_weapon_offset_get<true>("objects\\weapons\\melee\\gravity_hammer\\gravity_hammer");
	real_vector3d& assault_bomb_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\multiplayer\\assault_bomb\\assault_bomb");
	real_vector3d& assault_bomb_centered = first_person_weapon_offset_get<true>("objects\\weapons\\multiplayer\\assault_bomb\\assault_bomb");
	real_vector3d& ball_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\multiplayer\\ball\\ball");
	real_vector3d& ball_centered = first_person_weapon_offset_get<true>("objects\\weapons\\multiplayer\\ball\\ball");
	real_vector3d& flag_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\multiplayer\\flag\\flag");
	real_vector3d& flag_centered = first_person_weapon_offset_get<true>("objects\\weapons\\multiplayer\\flag\\flag");
	real_vector3d& excavator_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\pistol\\excavator\\excavator");
	real_vector3d& excavator_centered = first_person_weapon_offset_get<true>("objects\\weapons\\pistol\\excavator\\excavator");
	real_vector3d& magnum_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\pistol\\magnum\\magnum");
	real_vector3d& magnum_centered = first_person_weapon_offset_get<true>("objects\\weapons\\pistol\\magnum\\magnum");
	real_vector3d& needler_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\pistol\\needler\\needler");
	real_vector3d& needler_centered = first_person_weapon_offset_get<true>("objects\\weapons\\pistol\\needler\\needler");
	real_vector3d& plasma_pistol_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\pistol\\plasma_pistol\\plasma_pistol");
	real_vector3d& plasma_pistol_centered = first_person_weapon_offset_get<true>("objects\\weapons\\pistol\\plasma_pistol\\plasma_pistol");
	real_vector3d& assault_rifle_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\rifle\\assault_rifle\\assault_rifle");
	real_vector3d& assault_rifle_centered = first_person_weapon_offset_get<true>("objects\\weapons\\rifle\\assault_rifle\\assault_rifle");
	real_vector3d& battle_rifle_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\rifle\\battle_rifle\\battle_rifle");
	real_vector3d& battle_rifle_centered = first_person_weapon_offset_get<true>("objects\\weapons\\rifle\\battle_rifle\\battle_rifle");
	real_vector3d& beam_rifle_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\rifle\\beam_rifle\\beam_rifle");
	real_vector3d& beam_rifle_centered = first_person_weapon_offset_get<true>("objects\\weapons\\rifle\\beam_rifle\\beam_rifle");
	real_vector3d& covenant_carbine_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\rifle\\covenant_carbine\\covenant_carbine");
	real_vector3d& covenant_carbine_centered = first_person_weapon_offset_get<true>("objects\\weapons\\rifle\\covenant_carbine\\covenant_carbine");
	real_vector3d& plasma_rifle_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\rifle\\plasma_rifle\\plasma_rifle");
	real_vector3d& plasma_rifle_centered = first_person_weapon_offset_get<true>("objects\\weapons\\rifle\\plasma_rifle\\plasma_rifle");
	real_vector3d& shotgun_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\rifle\\shotgun\\shotgun");
	real_vector3d& shotgun_centered = first_person_weapon_offset_get<true>("objects\\weapons\\rifle\\shotgun\\shotgun");
	real_vector3d& smg_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\rifle\\smg\\smg");
	real_vector3d& smg_centered = first_person_weapon_offset_get<true>("objects\\weapons\\rifle\\smg\\smg");
	real_vector3d& sniper_rifle_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\rifle\\sniper_rifle\\sniper_rifle");
	real_vector3d& sniper_rifle_centered = first_person_weapon_offset_get<true>("objects\\weapons\\rifle\\sniper_rifle\\sniper_rifle");
	real_vector3d& spike_rifle_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\rifle\\spike_rifle\\spike_rifle");
	real_vector3d& spike_rifle_centered = first_person_weapon_offset_get<true>("objects\\weapons\\rifle\\spike_rifle\\spike_rifle");
	real_vector3d& flak_cannon_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\support_high\\flak_cannon\\flak_cannon");
	real_vector3d& flak_cannon_centered = first_person_weapon_offset_get<true>("objects\\weapons\\support_high\\flak_cannon\\flak_cannon");
	real_vector3d& rocket_launcher_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\support_high\\rocket_launcher\\rocket_launcher");
	real_vector3d& rocket_launcher_centered = first_person_weapon_offset_get<true>("objects\\weapons\\support_high\\rocket_launcher\\rocket_launcher");
	real_vector3d& spartan_laser_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\support_high\\spartan_laser\\spartan_laser");
	real_vector3d& spartan_laser_centered = first_person_weapon_offset_get<true>("objects\\weapons\\support_high\\spartan_laser\\spartan_laser");
	real_vector3d& brute_shot_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\support_low\\brute_shot\\brute_shot");
	real_vector3d& brute_shot_centered = first_person_weapon_offset_get<true>("objects\\weapons\\support_low\\brute_shot\\brute_shot");
	real_vector3d& sentinel_gun_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\support_low\\sentinel_gun\\sentinel_gun");
	real_vector3d& sentinel_gun_centered = first_person_weapon_offset_get<true>("objects\\weapons\\support_low\\sentinel_gun\\sentinel_gun");
	real_vector3d& machinegun_turret_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\turret\\machinegun_turret\\machinegun_turret");
	real_vector3d& machinegun_turret_centered = first_person_weapon_offset_get<true>("objects\\weapons\\turret\\machinegun_turret\\machinegun_turret");
	real_vector3d& machinegun_turret_integrated_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\turret\\machinegun_turret\\machinegun_turret_integrated");
	real_vector3d& machinegun_turret_integrated_centered = first_person_weapon_offset_get<true>("objects\\weapons\\turret\\machinegun_turret\\machinegun_turret_integrated");
	real_vector3d& missile_pod_lowered = first_person_weapon_offset_get<false>("objects\\weapons\\turret\\missile_pod\\missile_pod");
	real_vector3d& missile_pod_centered = first_person_weapon_offset_get<true>("objects\\weapons\\turret\\missile_pod\\missile_pod");

	debug_point;
}

extern bool g_use_30_tick;
void use_30_tick_command()
{
	g_use_30_tick = !g_use_30_tick;
	c_console::write_line_verbose("using 30 tick: %s", g_use_30_tick ? "true" : "false");
}