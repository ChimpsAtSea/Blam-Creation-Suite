#include <tagdefinitions-private-pch.h>

#include <slipspace/tag_groups.infinite.inl>

namespace blofeld
{
	const s_tag_group* tag_groups_empty[] = { nullptr };

	BCS_SHARED const s_tag_group** get_tag_groups_by_engine_platform_build(s_engine_platform_build engine_platform_build)
	{
		switch (engine_platform_build.engine_type)
		{
		case _engine_type_halo1:
		{
			return blofeld::halo1::pc64::tag_groups;
		}
		break;
		case _engine_type_halo2:
		{
			return blofeld::halo2::pc64::tag_groups;
		}
		break;
		case _engine_type_halo3:
		{
			return blofeld::halo3::pc64::tag_groups;
		}
		break;
		case _engine_type_halo3odst:
		{
			return blofeld::halo3odst::pc64::tag_groups;
		}
		break;
		case _engine_type_haloreach:
		{
			return blofeld::haloreach::xbox360::tag_groups;
		}
		break;
		case _engine_type_halo4:
		{
			return blofeld::halo4::xbox360::tag_groups;
		}
		break;
		case _engine_type_infinite:
		{
			// #TODO: specific engine versions?
			return tag_groups_infinite; 
		}
		break;
		case _engine_type_not_set:
		case _engine_type_mcc:
		case _engine_type_stubbs:
		case _engine_type_eldorado:
		case _engine_type_groundhog:
		case _engine_type_halo5:
			break;
		}

		return tag_groups_empty;
	}

	BCS_SHARED const s_tag_group* get_tag_group_by_group_tag(s_engine_platform_build engine_platform_build, tag group_tag)
	{
		for (const s_tag_group** tag_group_iter = get_tag_groups_by_engine_platform_build(engine_platform_build); *tag_group_iter; tag_group_iter++)
		{
			const s_tag_group& tag_group = **tag_group_iter;

			if (tag_group.group_tag == group_tag)
			{
				return &tag_group;
			}
		}
		return nullptr;
	}

} // namespace blofeld

