#include "halo5lib-private-pch.h"

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */

c_game_runtime* c_halo5_game_host::g_halo5_game_runtime = nullptr; // #TODO: Setup halo5 version detection

/* ---------- private prototypes */
/* ---------- public code */

#include "halo5_game_host.testing.inl"

void register_halo5lib()
{

}

c_halo5_game_host::c_halo5_game_host(s_engine_platform_build engine_platform_build) :
	c_aotus_game_engine_host(engine_platform_build, *g_halo5_game_runtime)
{

}

c_halo5_game_host::~c_halo5_game_host()
{

}

void c_halo5_game_host::init_game_host(e_build build)
{
	g_halo5_game_runtime = new c_game_runtime({ _engine_type_halo5, _platform_type_pc_64bit, build }, "halo5", "halo5.exe", true);
}

void c_halo5_game_host::deinit_game_host()
{
	delete g_halo5_game_runtime;
}

e_build c_halo5_game_host::get_build()
{
	return g_halo5_game_runtime->get_build();
}

void c_halo5_game_host::init_runtime_modifications(e_build build)
{
	init_detours();
	c_global_reference::init_global_reference_tree({ _engine_type_halo5, _platform_type_pc_64bit, build });
	c_function_hook_base::init_function_hook_tree({ _engine_type_halo5, _platform_type_pc_64bit, build });
	c_data_patch_base::init_data_patch_tree({ _engine_type_halo5, _platform_type_pc_64bit, build });
	end_detours();
}

void c_halo5_game_host::deinit_runtime_modifications(e_build build)
{
	init_detours();
	c_function_hook_base::deinit_function_hook_tree({ _engine_type_halo5, _platform_type_pc_64bit, build });
	c_data_patch_base::deinit_data_patch_tree({ _engine_type_halo5, _platform_type_pc_64bit, build });
	c_global_reference::deinit_global_reference_tree({ _engine_type_halo5, _platform_type_pc_64bit, build });
	end_detours();
}

/* ---------- private code */



