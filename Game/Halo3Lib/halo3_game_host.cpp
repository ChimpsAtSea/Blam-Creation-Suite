#include "halo3lib-private-pch.h"

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */

c_game_runtime* c_halo3_game_host::g_halo3_game_runtime;
static c_halo3_engine_state_command* g_halo3_engine_state_command;
static c_halo3_test_command* g_halo3_test_command;

/* ---------- private prototypes */
/* ---------- public code */

#include "halo3_game_host.memory.inl"
#include "halo3_game_host.mainmenu.inl"
#include "halo3_game_host.shell.inl"
#include "halo3_game_host.user_interface.inl"
#include "halo3_game_host.game.inl"
#include "halo3_game_host.testing.inl"

void register_halo3lib()
{

}

c_halo3_game_host::c_halo3_game_host(e_engine_type engine_type, e_build build) :
	c_opus_game_engine_host(engine_type, build, get_game_runtime())
{
	c_console::write_line_verbose("Init %s", __func__);

	init_runtime_modifications(g_halo3_game_runtime->get_build());

	if (g_halo3_engine_state_command != nullptr)
	{
		g_halo3_engine_state_command->set_game_engine(get_game_engine());
	}

	c_mandrill_user_interface::set_get_tag_section_address_callback(halo3_tag_address_get); // #TODO: This is kinda hacky
	c_mandrill_user_interface::set_get_tag_game_memory_callback(halo3_tag_definition_get); // #TODO: This is kinda hacky
}

c_halo3_game_host::~c_halo3_game_host()
{
	c_console::write_line_verbose("Deinit %s", __func__);

	c_mandrill_user_interface::set_get_tag_section_address_callback(nullptr); // #TODO: This is kinda hacky
	c_mandrill_user_interface::set_get_tag_game_memory_callback(nullptr); // #TODO: This is kinda hacky

	deinit_runtime_modifications(g_halo3_game_runtime->get_build());

	c_game_runtime& halo3_game_runtime = get_game_runtime();
	halo3_game_runtime.~c_game_runtime();
	new(&halo3_game_runtime) c_game_runtime(_engine_type_halo3, "halo3", "Halo3\\halo3.dll");
}

void c_halo3_game_host::frame_end(IDXGISwapChain* swap_chain, _QWORD unknown1)
{
	if (GetAsyncKeyState(VK_F10))
	{
		get_game_engine()->update_engine_state(_engine_state_game_end);
	}

	c_opus_game_engine_host::frame_end(swap_chain, unknown1);
}

void c_halo3_game_host::render_ui() const
{
}

IGameEngine* c_halo3_game_host::get_game_engine() const
{
	if (game_engine == nullptr)
	{
		__int64 create_game_engine_result = get_game_runtime().create_game_engine((IGameEngine**)&game_engine);
	}
	ASSERT(game_engine != nullptr);

	return game_engine;
}

c_game_runtime& c_halo3_game_host::get_game_runtime()
{
	if (g_halo3_game_runtime == nullptr)
	{
		g_halo3_game_runtime = new c_game_runtime(_engine_type_halo3, "halo3", "Halo3\\halo3.dll");
	}

	return *g_halo3_game_runtime;
}

void c_halo3_game_host::init_runtime_modifications(e_build build)
{
	g_halo3_engine_state_command = new c_halo3_engine_state_command();
	g_halo3_test_command = new c_halo3_test_command();

	g_use_30_tick = c_settings::read_boolean(_settings_section_game, "Use30Tick", false);
	c_settings::write_boolean(_settings_section_game, "Use30Tick", g_use_30_tick);

	init_detours();
	c_global_reference::init_global_reference_tree(_engine_type_halo3, build);
	c_data_patch_base::init_data_patch_tree(_engine_type_halo3, build);
	c_function_hook_base::init_function_hook_tree(_engine_type_halo3, build);
	end_detours();
}

void c_halo3_game_host::deinit_runtime_modifications(e_build build)
{
	delete g_halo3_engine_state_command;
	delete g_halo3_test_command;

	init_detours();
	c_function_hook_base::deinit_function_hook_tree(_engine_type_halo3, build);
	c_data_patch_base::deinit_data_patch_tree(_engine_type_halo3, build);
	c_global_reference::deinit_global_reference_tree(_engine_type_halo3, build);
	end_detours();
}

/* ---------- private code */
