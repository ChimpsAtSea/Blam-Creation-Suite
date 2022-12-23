#include "tagframework-private-pch.h"

namespace blofeld
{
	using t_tag_group_collection_keyvalue = std::pair<s_engine_platform_build, t_tag_group_collection>;
	using t_tag_group_collection_map = std::vector<t_tag_group_collection_keyvalue>;
	t_tag_group_collection_map* tag_group_collections;
	BCS_RESULT tag_definition_registry_init()
	{
		tag_group_collections = new t_tag_group_collection_map();
		if (tag_group_collections == nullptr)
		{
			return BCS_E_OUT_OF_MEMORY;
		}

		return BCS_S_OK;
	}

	BCS_RESULT tag_definition_registry_deinit()
	{
		delete tag_group_collections;
		tag_group_collections = nullptr;

		return BCS_S_OK;
	}

	BCS_RESULT tag_definition_registry_register_tag_group_collection(s_engine_platform_build engine_platform_build, t_tag_group_collection tag_groups)
	{
		if (tag_group_collections == nullptr)
		{
			return BCS_E_FAIL;
		}

		for (t_tag_group_collection_map::const_iterator iterator = tag_group_collections->begin(); iterator != tag_group_collections->end(); iterator++)
		{
			if (iterator->first == engine_platform_build)
			{
				return BCS_S_NO_CHANGES_MADE;
			}
		}

		tag_group_collections->emplace_back(engine_platform_build, tag_groups);

		return BCS_S_OK;
	}

	BCS_RESULT tag_definition_registry_unregister_tag_group_collection(s_engine_platform_build engine_platform_build)
	{
		if (tag_group_collections == nullptr)
		{
			return BCS_E_FAIL;
		}

		for (t_tag_group_collection_map::const_iterator iterator = tag_group_collections->begin(); iterator != tag_group_collections->end(); iterator++)
		{
			if (iterator->first == engine_platform_build)
			{
				tag_group_collections->erase(iterator);
				return BCS_S_OK;
			}
		}

		return BCS_S_NO_CHANGES_MADE;
	}

	BCS_RESULT tag_definition_registry_get_tag_groups_by_engine_platform_build(s_engine_platform_build engine_platform_build, t_tag_group_collection& tag_groups)
	{
		if (tag_group_collections == nullptr)
		{
			return BCS_E_FAIL;
		}

		for (t_tag_group_collection_map::const_iterator iterator = tag_group_collections->begin(); iterator != tag_group_collections->end(); iterator++)
		{
			if (iterator->first == engine_platform_build)
			{
				tag_groups = iterator->second;
				return BCS_S_OK;
			}
		}

		return BCS_E_NOT_FOUND;
	}

	BCS_RESULT tag_definition_registry_get_tag_group_by_engine_platform_build(s_engine_platform_build engine_platform_build, tag group_tag, s_tag_group const*& out_tag_group)
	{
		if (tag_group_collections == nullptr)
		{
			return BCS_E_FAIL;
		}

		BCS_RESULT rs = BCS_S_OK;
		t_tag_group_collection tag_groups;
		if (BCS_FAILED(rs = tag_definition_registry_get_tag_groups_by_engine_platform_build(engine_platform_build, tag_groups)))
		{
			return rs;
		}

		for (t_tag_group_iterator tag_group_iterator = tag_groups; *tag_group_iterator; tag_group_iterator++)
		{
			s_tag_group const& tag_group = **tag_group_iterator;
			if (tag_group.group_tag == group_tag)
			{
				out_tag_group = &tag_group;
				return BCS_S_OK;
			}
		}

		return BCS_E_NOT_FOUND;
	}

}
