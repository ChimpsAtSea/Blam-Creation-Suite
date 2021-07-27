﻿#include "groundhoglib-private-pch.h"

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */

c_game_runtime* c_groundhog_game_host::g_groundhog_game_runtime;
static c_groundhog_engine_state_command* g_groundhog_engine_state_command;

/* ---------- private prototypes */
/* ---------- public code */

#include "groundhog_game_host.memory.inl"
#include "groundhog_game_host.shell.inl"
#include "groundhog_game_host.user_interface.inl"
#include "groundhog_game_host.scripting.inl"
#include "groundhog_game_host.testing.inl"

void register_groundhoglib()
{

}

c_groundhog_game_host::c_groundhog_game_host(s_engine_platform_build engine_platform_build) :
	c_aotus_game_engine_host(engine_platform_build, get_game_runtime(engine_platform_build))
{
	c_console::write_line_verbose("Init %s", __func__);

	init_runtime_modifications();

	if (g_groundhog_engine_state_command != nullptr)
	{
		g_groundhog_engine_state_command->set_game_engine(get_game_engine());
	}

	c_mandrill_user_interface::set_get_tag_section_address_callback(groundhog_tag_address_get); // #TODO: This is kinda hacky
	c_mandrill_user_interface::set_get_tag_game_memory_callback(groundhog_tag_definition_get); // #TODO: This is kinda hacky
}

c_groundhog_game_host::~c_groundhog_game_host()
{
	c_console::write_line_verbose("Deinit %s", __func__);

	c_mandrill_user_interface::set_get_tag_section_address_callback(nullptr); // #TODO: This is kinda hacky
	c_mandrill_user_interface::set_get_tag_game_memory_callback(nullptr); // #TODO: This is kinda hacky

	deinit_runtime_modifications();

	c_game_runtime& groundhog_game_runtime = get_game_runtime(engine_platform_build);
	groundhog_game_runtime.~c_game_runtime();
	new(&groundhog_game_runtime) c_game_runtime(engine_platform_build, "groundhog", "Groundhog\\groundhog.dll");
}

void c_groundhog_game_host::frame_end(IDXGISwapChain* swap_chain, _QWORD unknown1)
{
	if (GetAsyncKeyState(VK_F10))
	{
		get_game_engine()->EngineStateUpdate(_engine_state_game_end);
	}

	c_aotus_game_engine_host::frame_end(swap_chain, unknown1);
}

void c_groundhog_game_host::render_ui() const
{
}

IGameEngine* c_groundhog_game_host::get_game_engine() const
{
	if (game_engine == nullptr)
	{
		__int64 create_game_engine_result = get_game_runtime(engine_platform_build).create_game_engine((IGameEngine**)&game_engine);
	}
	ASSERT(game_engine != nullptr);

	return game_engine;
}

c_game_runtime& c_groundhog_game_host::get_game_runtime(s_engine_platform_build engine_platform_build)
{
	if (g_groundhog_game_runtime == nullptr)
	{
		g_groundhog_game_runtime = new c_game_runtime(engine_platform_build, "groundhog", "Groundhog\\groundhog.dll");
	}

	return *g_groundhog_game_runtime;
}

void c_groundhog_game_host::init_runtime_modifications()
{
	g_groundhog_engine_state_command = new c_groundhog_engine_state_command();

	init_detours();
	c_global_reference::init_global_reference_tree(engine_platform_build);
	c_data_patch_base::init_data_patch_tree(engine_platform_build);
	c_function_hook_base::init_function_hook_tree(engine_platform_build);
	end_detours();
}

void c_groundhog_game_host::deinit_runtime_modifications()
{
	delete g_groundhog_engine_state_command;

	init_detours();
	c_function_hook_base::deinit_function_hook_tree(engine_platform_build);
	c_data_patch_base::deinit_data_patch_tree(engine_platform_build);
	c_global_reference::deinit_global_reference_tree(engine_platform_build);
	end_detours();
}

/* ---------- private code */
