#pragma once

namespace blofeld
{
	struct s_tag_group;

	using t_tag_group_collection = s_tag_group const* const*;
	using t_tag_group_iterator = s_tag_group const* const*;

	BCS_SHARED extern BCS_RESULT tag_definition_registry_init();
	BCS_SHARED extern BCS_RESULT tag_definition_registry_deinit();
	BCS_SHARED extern BCS_RESULT tag_definition_registry_register_tag_group_collection(s_engine_platform_build engine_platform_build, t_tag_group_collection tag_groups);
	BCS_SHARED extern BCS_RESULT tag_definition_registry_unregister_tag_group_collection(s_engine_platform_build engine_platform_build);
	BCS_SHARED extern BCS_RESULT tag_definition_registry_get_tag_groups_by_engine_platform_build(s_engine_platform_build engine_platform_build, t_tag_group_collection& tag_groups);
	BCS_SHARED extern BCS_RESULT tag_definition_registry_get_tag_group_by_engine_platform_build(s_engine_platform_build engine_platform_build, tag group_tag, s_tag_group const*& tag_group);
	
}
