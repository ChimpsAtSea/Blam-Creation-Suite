#pragma once

enum e_shader_profile
{
	_shader_profile_vs_1_1,
	_shader_profile_ps_2_0,
	_shader_profile_ps_2_x,
	_shader_profile_vs_2_0,
	_shader_profile_vs_2_x,
	_shader_profile_ps_4_0_level_9_0,
	_shader_profile_ps_4_0_level_9_1,
	_shader_profile_ps_4_0_level_9_3,
	_shader_profile_vs_4_0_level_9_0,
	_shader_profile_vs_4_0_level_9_1,
	_shader_profile_vs_4_0_level_9_3,
	_shader_profile_lib_4_0_level_9_1,
	_shader_profile_lib_4_0_level_9_3,
	_shader_profile_ps_3_0,
	_shader_profile_vs_3_0,
	_shader_profile_cs_4_0,
	_shader_profile_gs_4_0,
	_shader_profile_ps_4_0,
	_shader_profile_vs_4_0,
	_shader_profile_cs_4_1,
	_shader_profile_gs_4_1,
	_shader_profile_ps_4_1,
	_shader_profile_vs_4_1,
	_shader_profile_lib_4_0,
	_shader_profile_lib_4_1,
	_shader_profile_cs_5_0,
	_shader_profile_ds_5_0,
	_shader_profile_gs_5_0,
	_shader_profile_hs_5_0,
	_shader_profile_ps_5_0,
	_shader_profile_vs_5_0,
	_shader_profile_lib_5_0,
	_shader_profile_cs_6_0,
	_shader_profile_ds_6_0,
	_shader_profile_gs_6_0,
	_shader_profile_hs_6_0,
	_shader_profile_ps_6_0,
	_shader_profile_vs_6_0,
	_shader_profile_lib_6_0,
};

inline const char* shader_profile_to_string(e_shader_profile shader_profile)
{
	switch (shader_profile)
	{
	case _shader_profile_vs_1_1:				return "vs_1_1";
	case _shader_profile_ps_2_0:				return "ps_2_0";
	case _shader_profile_ps_2_x:				return "ps_2_x";
	case _shader_profile_vs_2_0:				return "vs_2_0";
	case _shader_profile_vs_2_x:				return "vs_2_x";
	case _shader_profile_ps_4_0_level_9_0:		return "ps_4_0_level_9_0";
	case _shader_profile_ps_4_0_level_9_1:		return "ps_4_0_level_9_1";
	case _shader_profile_ps_4_0_level_9_3:		return "ps_4_0_level_9_3";
	case _shader_profile_vs_4_0_level_9_0:		return "vs_4_0_level_9_0";
	case _shader_profile_vs_4_0_level_9_1:		return "vs_4_0_level_9_1";
	case _shader_profile_vs_4_0_level_9_3:		return "vs_4_0_level_9_3";
	case _shader_profile_lib_4_0_level_9_1:		return "lib_4_0_level_9_1";
	case _shader_profile_lib_4_0_level_9_3:		return "lib_4_0_level_9_3";
	case _shader_profile_ps_3_0:				return "ps_3_0";
	case _shader_profile_vs_3_0:				return "vs_3_0";
	case _shader_profile_cs_4_0:				return "cs_4_0";
	case _shader_profile_gs_4_0:				return "gs_4_0";
	case _shader_profile_ps_4_0:				return "ps_4_0";
	case _shader_profile_vs_4_0:				return "vs_4_0";
	case _shader_profile_cs_4_1:				return "cs_4_1";
	case _shader_profile_gs_4_1:				return "gs_4_1";
	case _shader_profile_ps_4_1:				return "ps_4_1";
	case _shader_profile_vs_4_1:				return "vs_4_1";
	case _shader_profile_lib_4_0:				return "lib_4_0";
	case _shader_profile_lib_4_1:				return "lib_4_1";
	case _shader_profile_cs_5_0:				return "cs_5_0";
	case _shader_profile_ds_5_0:				return "ds_5_0";
	case _shader_profile_gs_5_0:				return "gs_5_0";
	case _shader_profile_hs_5_0:				return "hs_5_0";
	case _shader_profile_ps_5_0:				return "ps_5_0";
	case _shader_profile_vs_5_0:				return "vs_5_0";
	case _shader_profile_lib_5_0:				return "lib_5_0";
	case _shader_profile_cs_6_0:				return "cs_6_0";
	case _shader_profile_ds_6_0:				return "ds_6_0";
	case _shader_profile_gs_6_0:				return "gs_6_0";
	case _shader_profile_hs_6_0:				return "hs_6_0";
	case _shader_profile_ps_6_0:				return "ps_6_0";
	case _shader_profile_vs_6_0:				return "vs_6_0";
	case _shader_profile_lib_6_0:				return "lib_6_0";
	}
	return "<unknown e_shader_profile>";
}
