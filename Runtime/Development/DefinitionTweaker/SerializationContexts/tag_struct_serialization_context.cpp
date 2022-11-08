#include "definitiontweaker-private-pch.h"

bool c_tag_struct_serialization_context::_execute_tag_field_versioning(
	blofeld::s_tag_field_versioning const& versioning,
	s_engine_platform_build engine_platform_build,
	uint32_t struct_version,
	uint32_t& skip_count)
{
	bool skip_versioning_field = false;
	skip_count = versioning.version_field_skip_count;

	constexpr tag group_tag = blofeld::ANY_TAG;

	switch (versioning.mode)
	{
	case blofeld::_version_mode_invalid:
		FATAL_ERROR("Invalid version mode");
		break;
	case blofeld::_version_mode_custom:
		ASSERT(versioning.custom_version_callback);
		skip_count = versioning.custom_version_callback(engine_platform_build);
		skip_versioning_field = false;
		break;
	case blofeld::_version_mode_platform_include:
		if (versioning.engine_platform_build.platform_type != _platform_type_not_set && engine_platform_build.platform_type != _platform_type_not_set)
		{
			skip_versioning_field = (versioning.engine_platform_build.platform_type & engine_platform_build.platform_type) != 0;
		}
		break;
	case blofeld::_version_mode_platform_exclude:
		if (versioning.engine_platform_build.platform_type != _platform_type_not_set && engine_platform_build.platform_type != _platform_type_not_set)
		{
			skip_versioning_field = (versioning.engine_platform_build.platform_type & engine_platform_build.platform_type) != 0;
		}
		break;
	case blofeld::_version_mode_equal:
		skip_versioning_field = engine_platform_build == versioning.engine_platform_build;
		break;
	case blofeld::_version_mode_not_equal:
		skip_versioning_field = engine_platform_build != versioning.engine_platform_build;
		break;
	case blofeld::_version_mode_less:
		skip_versioning_field = engine_platform_build < versioning.engine_platform_build;
		break;
	case blofeld::_version_mode_greater:
		skip_versioning_field = engine_platform_build > versioning.engine_platform_build;
		break;
	case blofeld::_version_mode_less_or_equal:
		skip_versioning_field = engine_platform_build <= versioning.engine_platform_build;
		break;
	case blofeld::_version_mode_greater_or_equal:
		skip_versioning_field = engine_platform_build >= versioning.engine_platform_build;
		break;
	case blofeld::_version_mode_tag_group_equal:
		skip_versioning_field = group_tag == blofeld::ANY_TAG || versioning.group->group_tag == group_tag;
		break;
	case blofeld::_version_mode_tag_group_not_equal:
		skip_versioning_field = group_tag == blofeld::ANY_TAG || versioning.group->group_tag != group_tag;
		break;
	case blofeld::_struct_version_mode_equal:
		skip_versioning_field = struct_version == tag_field_version_all || struct_version == versioning.struct_version;
		break;
	case blofeld::_struct_version_mode_greater_or_equal:
		skip_versioning_field = struct_version == tag_field_version_all || struct_version >= versioning.struct_version;
		break;
	}

	if (skip_versioning_field)
	{
		skip_count = 0;
	}

	return true;
}

bool c_tag_struct_serialization_context::_execute_tag_field_versioning(
	c_runtime_tag_field_definition& tag_field,
	s_engine_platform_build engine_platform_build,
	uint32_t struct_version,
	uint32_t& skip_count)
{
	if (tag_field.field_type != blofeld::_field_version)
	{
		skip_count = 0;
		return false;
	}

	return _execute_tag_field_versioning(tag_field.versioning, engine_platform_build, struct_version, skip_count);
}

unsigned int c_tag_struct_serialization_context::_tag_field_iterator_versioning(c_runtime_tag_field_definition& field, size_t& tag_field_index, s_engine_platform_build engine_platform_build, unsigned int struct_version)
{
	uint32_t _field_skip_count;
	if (_execute_tag_field_versioning(field, engine_platform_build, struct_version, _field_skip_count))
	{
		tag_field_index += _field_skip_count;
		return true;
	}
	return false;
}

c_tag_struct_serialization_context::c_tag_struct_serialization_context(
	c_serialization_context& _serialization_context,
	c_tag_serialization_context& _tag_serialization_context,
	const char* _struct_data,
	c_runtime_tag_struct_definition& _runtime_tag_struct_definition,
	unsigned int _expected_struct_size) :
	c_serialization_context(_serialization_context),
	tag_serialization_context(_tag_serialization_context),
	struct_data(_struct_data),
	expected_struct_size(_expected_struct_size),
	struct_size(),
	field_serialization_contexts(),
	field_serialization_contexts_memory(),
	runtime_tag_struct_definition(_runtime_tag_struct_definition),
	name(runtime_tag_struct_definition.name),
	traverse_count()
{

}

c_tag_struct_serialization_context::~c_tag_struct_serialization_context()
{
	for (c_tag_field_serialization_context* field_serialization_context : field_serialization_contexts)
	{
		field_serialization_context->~c_tag_field_serialization_context();
		//delete field_serialization_context;
	}
	delete field_serialization_contexts_memory;
}

BCS_RESULT c_tag_struct_serialization_context::read()
{
	if (max_serialization_error_type >= _serialization_error_type_fatal)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_warning,
			"skipping read due to issues");
		return BCS_E_FAIL;
	}

	if (runtime_tag_struct_definition.fields.empty())
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_fatal,
			"struct '%' has no fields",
			runtime_tag_struct_definition.name.c_str());
	}
	else
	{
		struct_size = calculate_struct_size(*this, runtime_tag_struct_definition);
	}

	// check read bounds of structure
	{
		const char* read_position = struct_data;

		if (read_position < tag_serialization_context.tag_data_start)
		{
			intptr_t bytes = tag_serialization_context.tag_data_end - read_position;
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_fatal,
				"struct data read before tag data start (bytes:%zu)", bytes);
		}

		read_position += struct_size;

		if (read_position > tag_serialization_context.tag_data_end)
		{
			intptr_t bytes = read_position - tag_serialization_context.tag_data_end;
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_fatal,
				"struct data read after tag data start (bytes:%zu)", bytes);
		}
	}

	// iterate through fields
	if(max_serialization_error_type < _serialization_error_type_fatal)
	{
		const char* read_position = struct_data;
		field_serialization_contexts_memory = trivial_malloc(c_tag_field_serialization_context, runtime_tag_struct_definition.fields.size());
		for (size_t field_index = 0; field_index < runtime_tag_struct_definition.fields.size(); field_index++)
		{
			t_blamtoozle_tag_field& blamtoozle_field = *runtime_tag_struct_definition.fields[field_index];
			if (c_runtime_tag_field_definition* runtime_field = dynamic_cast<c_runtime_tag_field_definition*>(&blamtoozle_field))
			{
				c_runtime_tag_field_definition* max_version_field = dynamic_cast<c_runtime_tag_field_definition*>(runtime_tag_struct_definition.fields.front());
				if (_tag_field_iterator_versioning(*runtime_field, field_index, engine_platform_build, max_version_field->versioning.struct_version))
				{
					continue;
				}

				c_tag_field_serialization_context* tag_field_serialization_context = new(field_serialization_contexts_memory + field_index) c_tag_field_serialization_context(*this, read_position, *runtime_field);
				field_serialization_contexts.push_back(tag_field_serialization_context);

				read_position += tag_field_serialization_context->field_size;
			}
		}
	}

	for (c_tag_field_serialization_context* field_serialization_context : field_serialization_contexts)
	{
		field_serialization_context->read();
	}

	debug_point;
}

BCS_RESULT c_tag_struct_serialization_context::traverse()
{
	unsigned int has_traversed = atomic_incu32(&traverse_count) > 1;
	ASSERT(!has_traversed);

	if (max_serialization_error_type >= _serialization_error_type_fatal)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_warning,
			"skipping traverse due to issues");
		return BCS_E_FAIL;
	}

	for (c_tag_field_serialization_context* field_serialization_context : field_serialization_contexts)
	{
		field_serialization_context->traverse();
	}

	debug_point;

	return BCS_S_OK;
}

unsigned int c_tag_struct_serialization_context::calculate_struct_size(c_serialization_context& serialization_context, c_runtime_tag_struct_definition& struct_definition)
{
	unsigned int struct_size = 0;

	for (size_t field_index = 0; field_index < struct_definition.fields.size(); field_index++)
	{
		t_blamtoozle_tag_field& blamtoozle_field = *struct_definition.fields[field_index];
		if (c_runtime_tag_field_definition* runtime_field = dynamic_cast<c_runtime_tag_field_definition*>(&blamtoozle_field))
		{
			c_runtime_tag_field_definition* max_version_field = dynamic_cast<c_runtime_tag_field_definition*>(struct_definition.fields.front());
			if (runtime_field->field_type == blofeld::_field_version && (max_version_field == nullptr || max_version_field->field_type != blofeld::_field_version))
			{
				serialization_context.enqueue_serialization_error<c_generic_serialization_error>(
					_serialization_error_type_fatal,
					"versioned struct '%' doesn't start with a versioned runtime_field. unable to determine max version",
					runtime_field->name.c_str());
				return 0;
			}

			if (_tag_field_iterator_versioning(*runtime_field, field_index, serialization_context.engine_platform_build, max_version_field->versioning.struct_version))
			{
				continue;
			}

			unsigned int field_size = c_tag_field_serialization_context::calculate_field_size(serialization_context, *runtime_field);
			struct_size += field_size;
		}
	}

	return struct_size;
}

void c_tag_struct_serialization_context::render_tree()
{
	const char* struct_name = name.c_str();

	ImGui::PushID(struct_name);
	ImGui::PushStyleColor(ImGuiCol_Text, serialization_error_colors[max_serialization_error_type]);

	ImGuiTreeNodeFlags flags =
		ImGuiTreeNodeFlags_SpanFullWidth;
	if (field_serialization_contexts.empty())
	{
		flags = flags | ImGuiTreeNodeFlags_Leaf;
	}
	bool tree_node_result = ImGui::TreeNodeEx("##struct", flags, "%s [0x%X]", struct_name, struct_size);
	render_hover_tooltip();
	if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
	{
		debug_point;
	}
	tag_serialization_context.definition_tweaker.render_definition_context_menu(_definition_type_struct_definition, &runtime_tag_struct_definition);
	if (tree_node_result)
	{
		e_serialization_error_type field_max_serialization_error_type = _serialization_error_type_ok;
		for (c_tag_field_serialization_context* field_serialization_context : field_serialization_contexts)
		{
			field_max_serialization_error_type = __max(field_max_serialization_error_type, field_serialization_context->max_serialization_error_type);
		}
		ImGui::PushStyleColor(ImGuiCol_Text, serialization_error_colors[field_max_serialization_error_type]);
		if (!field_serialization_contexts.empty())
		{
			bool has_objects = false;
			for (c_tag_field_serialization_context* field_serialization_context : field_serialization_contexts)
			{
				if (field_serialization_context->tag_struct_serialization_context)
				{
					has_objects = true;
					break;
				}
				if (field_serialization_context->tag_block_serialization_context)
				{
					has_objects = true;
					break;
				}
			}
			if (has_objects)
			{
				if (ImGui::TreeNodeEx("##objects", flags, "Objects"))
				{
					for (c_tag_field_serialization_context* field_serialization_context : field_serialization_contexts)
					{
						if (c_tag_struct_serialization_context* tag_struct_serialization_context = field_serialization_context->tag_struct_serialization_context)
						{
							tag_struct_serialization_context->render_tree();
						}
						if (c_tag_block_serialization_context* tag_block_serialization_context = field_serialization_context->tag_block_serialization_context)
						{
							tag_block_serialization_context->render_tree();
						}
					}
					ImGui::TreePop();
				}
			}
			if (ImGui::TreeNodeEx("##fields", flags, "Fields"))
			{
				std::map<std::string, unsigned int> field_name_index;
				for (c_tag_field_serialization_context* field_serialization_context : field_serialization_contexts)
				{
					unsigned int index = field_name_index[field_serialization_context->name]++;
					ImGui::PushID(index);
					field_serialization_context->render_tree();
					ImGui::PopID();
				}
				ImGui::TreePop();
			}
		}
		ImGui::PopStyleColor();

		//if (c_tag_struct_serialization_context* struct_serialization_context = root_struct_serialization_context)
		//{
		//	struct_serialization_context->render_tree();
		//}
		ImGui::TreePop();
	}

	ImGui::PopStyleColor();
	ImGui::PopID();
}
