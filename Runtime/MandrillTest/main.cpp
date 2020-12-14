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

#include <high_level_haloreach/highlevel-haloreach-public-pch.h>

class c_test
{
public:
	static void callback(void* userdata, const c_data_change_notification& notification)
	{
		reinterpret_cast<c_test*>(userdata)->callback(notification);
	}

	void callback(const c_data_change_notification& notification)
	{
		if (notification.userdata != this)
		{
			debug_point;
		}
	}

	c_test(c_tag_project* tag_project)
	{
		h_notification_system::push_value(this);

		if (blofeld::haloreach::h_cache_file_resource_layout_table_block_struct* cache_file_resource_layout_table = dynamic_cast<decltype(cache_file_resource_layout_table)>(tag_project->tags[2]))
		{
			debug_point;

			cache_file_resource_layout_table->add_notification_listener(callback, this);

			cache_file_resource_layout_table->sections_block[0].page_offsets[0].offset = 100;
		}

		if (blofeld::haloreach::h_scenario_struct_definition* scenario = dynamic_cast<decltype(scenario)>(tag_project->tags[8]))
		{
			debug_point;

			scenario->add_notification_listener(callback, this);

			scenario->campaign_id = 200;
			scenario->skies_block[0].cloud_scale = 2.0f;
		}
		
		h_notification_system::pop_value();
	}
};

static int run_mandrill_api_test()
{
	using namespace blofeld;
	using namespace blofeld::haloreach;

	const wchar_t* files[] =
	{
		L"C:\\!MCC\\haloreach\\maps\\20_sword_slayer.map",
		//L"C:\\!MCC\\haloreach\\maps\\m70_a.map", // smallest map
		//L"C:\\!MCC\\haloreach\\maps\\m70_bonus.map",
		L"C:\\!MCC\\haloreach\\maps\\shared.map",
		L"C:\\!MCC\\haloreach\\maps\\campaign.map",
	};
	c_cache_cluster* cache_cluster = new c_cache_cluster(files, sizeof(files) / sizeof(*files));
	c_cache_file* cache_file = cache_cluster->get_cache_file_by_dvd_path("maps\\20_sword_slayer.map");
	DEBUG_ASSERT(cache_file != nullptr);

	c_tag_project* tag_project = new c_tag_project(*cache_cluster, *cache_file);
	delete cache_cluster;

	c_test test(tag_project);

	delete tag_project;

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
