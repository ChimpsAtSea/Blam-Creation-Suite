#include "mandrillapiprototype-private-pch.h"

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */

bool g_mandrill_running = true;
const char* c_console::g_console_executable_name = "Mandrill API Prorotype";
c_window* window = nullptr;
c_mandrill_user_interface* mandrill_user_interface = nullptr;

/* ---------- private prototypes */
/* ---------- public code */
/* ---------- private code */

static void load_plugins()
{

	c_fixed_wide_path executable_directory;
	GetModuleFileNameW(c_runtime_util::get_current_module(), executable_directory.str(), executable_directory.capacity());
	PathRemoveFileSpecW(executable_directory.str());
	executable_directory += L"\\*.mext";

	std::function<bool(const wchar_t* filepath)> handler = [](const wchar_t* filepath)
	{
		const wchar_t* filename = PathFindFileNameW(filepath);
		HMODULE extension_module = LoadLibraryW(filepath);
		if (extension_module == nullptr)
		{
			c_console::write_line_verbose("failed to load plugin '%S' LoadLibrary failed", filename);
			return true; // continue
		}

		t_create_mandrill_extension* create_mandrill_extension = reinterpret_cast<t_create_mandrill_extension*>(GetProcAddress(extension_module, "create_mandrill_extension"));
		if (create_mandrill_extension == nullptr)
		{
			c_console::write_line_verbose("failed to load plugin '%S' create_mandrill_extension was not found", filename);
			if (extension_module)
			{
				FreeLibrary(extension_module);
			}
			return true; // continue
		}

		c_mandrill_extension* extension = create_mandrill_extension();
		int version = extension->get_version();
		if (version != BCS_EXTENSION_VERSION)
		{
			c_console::write_line_verbose("failed to load plugin '%S' version missmatch", filename);
			if (extension_module)
			{
				FreeLibrary(extension_module);
			}
			return true; // continue
		}

		const char* extension_name = extension->get_name();
		c_console::write_line_verbose("successfully loaded plugin '%s'", extension_name);

		c_mandrill_extension::register_extension(extension);

		return true;
	};
	filesystem_iterate_directory(executable_directory.c_str(), handler);
}

static void init_mandrill(HINSTANCE instance_handle, int show_cmd, const wchar_t* command_line)
{
#ifdef _DEBUG
	const wchar_t* k_window_title = L"Mandrill API Test Debug";
#else
	const wchar_t* k_window_title = L"Mandrill API Test";
#endif

	c_console::init_console();

	load_plugins();

	c_console::show_startup_banner();

}

std::map<c_high_level_tag*, uint32_t> high_level_tags;

static void find_tags(c_high_level_type& type, std::vector<c_high_level_tag*>& tags)
{
	using namespace blofeld;

	// #TODO: populate tag struct definition

	for (const s_tag_field* field = type.struct_definition.fields; field->field_type != _field_terminator; field++)
	{
		switch (field->field_type)
		{
		case _field_struct:
		{
			if (c_high_level_type* field_struct = type.get_field_pointer<c_high_level_type>(*field))
			{
				find_tags(*field_struct, tags);
			}
			break;
		}
		case _field_block:
		{
			if (std::vector<c_high_level_type*>* block_struct = type.get_field_pointer<std::vector<c_high_level_type*>>(*field))
			{
				for (c_high_level_type* block_entry : *block_struct)
				{
					find_tags(*block_entry, tags);
				}
			}
			break;
		}
		case _field_tag_reference:
		{
			if (c_high_level_tag** field_tag = type.get_field_pointer<c_high_level_tag*>(*field))
			{
				if (*field_tag != nullptr)
				{
					tags.push_back(*field_tag);
				}
			}
			break;
		}
		}
	}
}

static int run_mandrill_api_test()
{
	using namespace blofeld;
	using namespace blofeld::haloreach;

	c_cache_file& cache_file = *c_cache_file::create_cache_file(L"C:\\!MCC\\haloreach\\maps\\70_boneyard.map");
	c_tag_group_interface& vehicle_group = *cache_file.get_tag_group_interface_by_group_id(VEHICLE_TAG);
	c_tag_interface& tag_interface = *vehicle_group.get_tag_interfaces()[0];
	c_virtual_tag_interface& virtual_tag_interface = *tag_interface.get_virtual_tag_interface();
	const blofeld::s_tag_group& tag_group = *virtual_tag_interface.tag_interface.get_blofeld_reflection_data();

	c_high_level_tag & vehicle = *blofeld::haloreach::create_high_level_tag(tag_group, "vehicles\\instancetest.vehi");
	ASSERT(&tag_group.block_definition.struct_definition == &vehicle.struct_definition);


	for (const s_tag_field* field = vehicle.struct_definition.fields; field->field_type != _field_terminator; field++)
	{
		void* virtual_field = virtual_tag_interface.get_field_pointer(*field);
		void* high_level_field = vehicle.get_field_pointer(*field);

		if (!high_level_field && !virtual_field)
		{
			continue;
		}

		if (!high_level_field)
		{
			// #TODO: No destination
			continue;
		}

		if (!virtual_field)
		{
			// #TODO: No source
			continue;
		}

		switch (field->field_type)
		{
		case _field_string:
		case _field_long_string:
		case _field_string_id:
		case _field_old_string_id:
		case _field_char_integer:
		case _field_short_integer:
		case _field_long_integer:
		case _field_int64_integer:
		case _field_angle:
		case _field_char_enum:
		case _field_enum:
		case _field_long_enum:
		case _field_long_flags:
		case _field_word_flags:
		case _field_byte_flags:
		case _field_point_2d:
		case _field_rectangle_2d:
		case _field_rgb_color:
		case _field_argb_color:
		case _field_real:
		case _field_real_fraction:
		case _field_real_point_2d:
		case _field_real_point_3d:
		case _field_real_vector_2d:
		case _field_real_vector_3d:
		case _field_real_quaternion:
		case _field_real_euler_angles_2d:
		case _field_real_euler_angles_3d:
		case _field_real_plane_2d:
		case _field_real_plane_3d:
		case _field_real_rgb_color:
		case _field_real_argb_color:
		case _field_real_hsv_color:
		case _field_real_ahsv_color:
		case _field_short_bounds:
		case _field_angle_bounds:
		case _field_real_bounds:
		case _field_real_fraction_bounds:
			memcpy(high_level_field, virtual_field, get_blofeld_field_size(_platform_type_pc, field->field_type));
		}

	}






	c_effect_block_struct& effect = *new c_effect_block_struct("fx\\customeffect.effe");

	void* data = effect.get_field_pointer(effect.struct_definition.fields[0]);

	/* create the effect */

	c_weapon_block_struct& weapon = *new c_weapon_block_struct("weapons\\customweapon.weap");

	c_weapon_barrels_block_struct& barrel = *weapon.barrels_block.emplace_back(new c_weapon_barrels_block_struct());

	c_barrel_firing_effect_block_block_struct& firing_effect = *barrel.firing_effects_block.emplace_back(new c_barrel_firing_effect_block_block_struct());

	firing_effect.firing_effect = &effect;

	std::vector<c_high_level_tag*> tags;
	find_tags(weapon, tags);

	return 0;
}

static void deinit_mandrill()
{
	c_console::deinit_console();
}

int WINAPI wWinMain(
	_In_ HINSTANCE hInstance,				/* [input] handle to current instance */
	_In_opt_ HINSTANCE hPrevInstance,		/* [input] handle to previous instance */
	_In_ LPWSTR lpCmdLine,					/* [input] pointer to command line */
	_In_ int nShowCmd						/* [input] show state of window */
)
{
	int result = 0;
	if (rhesus_crash_reporter(result))
	{
		return result;
	}

	init_mandrill(hInstance, nShowCmd, lpCmdLine);
	result = run_mandrill_api_test();
	deinit_mandrill();

	return result;
}
