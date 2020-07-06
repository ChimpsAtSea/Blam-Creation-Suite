#pragma once

struct s_engine_type_and_platform_and_build
{
	s_engine_type_and_platform_and_build(e_platform_type platform_type) :
		engine_type(_engine_type_not_set),
		platform_type(platform_type),
		build(_build_not_set)
	{

	}

	s_engine_type_and_platform_and_build(e_engine_type engine_type, e_platform_type platform_type, e_build build = _build_not_set) :
		engine_type(engine_type),
		platform_type(platform_type),
		build(build)
	{

	}

	s_engine_type_and_platform_and_build(e_engine_type engine_type, e_build build = _build_not_set) :
		engine_type(engine_type),
		platform_type(_platform_type_not_set),
		build(build)
	{

	}

	e_engine_type engine_type;
	e_platform_type platform_type;
	e_build build;
};
