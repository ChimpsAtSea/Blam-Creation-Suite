#include "mandrilllib-private-pch.h"

using namespace blofeld;
using namespace blofeld::taggroups;

c_tag_project::c_tag_project(
	s_engine_platform_build engine_platform_build,
	c_status_interface* status_interface) :
	engine_platform_build(engine_platform_build),
	status_interface(status_interface)
{
	
}

c_tag_project::~c_tag_project()
{
	
}

struct s_resolve_unqualified_tag_references
{
	const c_tag_project* tag_project;
	h_tag_instance* const* tag_instances;
	uint32_t num_tag_instances;
};

static void resolve_unqualified_tag_references(void* _userdata, uint32_t tag_index)
{
	s_resolve_unqualified_tag_references* userdata = static_cast<s_resolve_unqualified_tag_references*>(_userdata);
	const c_tag_project* _this = userdata->tag_project;

	h_tag_instance* tag = userdata->tag_instances[tag_index];
	_this->resolve_unqualified_tag_references(tag->prototype);

	if (_this->status_interface)
	{
		_this->status_interface->set_status_bar_status(_status_interface_priority_low, INFINITY, "Resolving unqualified tag references (%lu/%lu)", tag_index, userdata->num_tag_instances);
	}
}

BCS_RESULT c_tag_project::resolve_unqualified_tags() const
{
	BCS_RESULT rs = BCS_S_OK;

	c_stopwatch stopwatch;
	stopwatch.start();

	s_resolve_unqualified_tag_references userdata = {};
	userdata.tag_project = this;
	if (BCS_FAILED(rs = get_tag_instances(userdata.tag_instances, userdata.num_tag_instances)))
	{
		return rs;
	}

	if (status_interface)
	{
		status_interface->set_status_bar_status(_status_interface_priority_low, INFINITY, "Resolving unqualified tag references (%lu/%lu)", 0lu, userdata.num_tag_instances);
	}

	parallel_invoke(0ul, userdata.num_tag_instances, ::resolve_unqualified_tag_references, &userdata);

	stopwatch.stop();
	float resolve_unqualified_tags_time = stopwatch.get_miliseconds();

	if (status_interface)
	{
		status_interface->wait_status_bar_idle();
		status_interface->set_status_bar_status(_status_interface_priority_low, INFINITY, "Resolving unqualified tag references finished %0.2fms", stopwatch.get_miliseconds());
	}

	return rs;
}

bool c_tag_project::resolve_tag_reference(tag group_tag, h_tag_reference& tag_reference, const char* target_file_path_without_extension) const
{
	h_tag_group* group;
	if (BCS_SUCCEEDED(get_group_by_group_tag(group_tag, group)))
	{
		for (h_tag_instance* current_tag : group->tags)
		{
			if (strcmp(current_tag->get_file_path_without_extension(), target_file_path_without_extension) == 0)
			{
				tag_reference.set_group(group);
				tag_reference.set_tag(current_tag);
				return true;
			}
		}
	}
	return false;
}

BCS_RESULT c_tag_project::resolve_unqualified_tag_references(h_prototype& prototype) const
{
	BCS_RESULT rs = BCS_S_OK;

	unsigned int serialization_count;
	h_serialization_info const* serialization_infos = prototype.get_serialization_information(serialization_count);
	for (unsigned int serialization_index = 0; serialization_index < serialization_count; serialization_index++)
	{
		h_serialization_info const& serialization_info = serialization_infos[serialization_index];

		switch (serialization_info.tag_field.field_type)
		{
		{
		case _field_struct:
		{
			h_type* type_field = prototype.get_member(serialization_info.pointer_to_member);
			h_prototype* prototype_field = high_level_cast<h_prototype*>(type_field);
			DEBUG_ASSERT(prototype_field != nullptr);
			if (BCS_FAILED(rs = resolve_unqualified_tag_references(*prototype_field)))
			{
				return rs;
			}
		}
		break;
		case _field_array:
		{
			h_type* type_field = prototype.get_member(serialization_info.pointer_to_member);
			h_prototype* prototype_field = high_level_cast<h_prototype*>(type_field);
			DEBUG_ASSERT(prototype_field != nullptr);
		}
		break;
		case _field_block:
		{
			h_type* type_field = prototype.get_member(serialization_info.pointer_to_member);
			h_enumerable* enumerable = prototype.get_field_data<h_enumerable>(*field);
			ASSERT(enumerable != nullptr);

			uint32_t enumerable_count = enumerable->size();
			for (uint32_t enumerable_index = 0; enumerable_index < enumerable_count; enumerable_index++)
			{
				h_prototype& enumerable_object = enumerable->get(enumerable_index);
				if (BCS_FAILED(rs = resolve_unqualified_tag_references(enumerable_object)))
				{
					return rs;
				}
			}

			debug_point;
		}
		break;
		case _field_tag_reference:
		{
			h_tag_reference* tag_reference = prototype.get_field_data<h_tag_reference>(*field);
			ASSERT(tag_reference != nullptr);

			if (tag_reference->is_unqualified())
			{
				const char* target_tag_filepath = tag_reference->get_file_path_without_extension();
				tag group_tag = tag_reference->get_group_tag();
				if (group_tag != INVALID_TAG && resolve_tag_reference(group_tag, *tag_reference, target_tag_filepath))
				{
					goto next;
				}
				else if (engine_platform_build.engine_type == _engine_type_halo1)
				{
					if (group_tag == MODEL_TAG(_engine_type_halo1) && resolve_tag_reference(GBXMODEL_TAG, *tag_reference, target_tag_filepath))
					{
						goto next;
					}
					else if (group_tag == GBXMODEL_TAG && resolve_tag_reference(MODEL_TAG(_engine_type_halo1), *tag_reference, target_tag_filepath))
					{
						goto next;
					}
				}
				debug_point;
			}
		}
		break;
		}
	next:;
	}

	return rs;
}
