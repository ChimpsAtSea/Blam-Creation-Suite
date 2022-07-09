#pragma once

namespace blofeld
{
	BCS_DEBUG_API extern const s_tag_group** get_tag_groups_by_engine_platform_build(s_engine_platform_build engine_platform_build);
	BCS_DEBUG_API const blofeld::s_tag_group* get_tag_group_by_group_tag(s_engine_platform_build engine_platform_build, tag group_tag);


} // namespace blofeld


