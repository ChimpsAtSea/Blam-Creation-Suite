#include <tagdefinitions-private-pch.h>

namespace blofeld
{
	static unsigned long tag_struct_definition_counts[k_number_of_engine_types] = {};
	const s_tag_struct_definition** tag_struct_definitions[k_number_of_engine_types] = {};

	struct s_tag_struct_count_search_callback_userdata
	{
		s_engine_platform_build engine_platform_build;
		std::vector<const s_tag_struct_definition*>* structures;
	};

	static void tag_struct_count_search_callback(const s_tag_struct_definition& struct_definition, void* userdata_pointer)
	{
		const s_tag_struct_count_search_callback_userdata& userdata = *reinterpret_cast<const s_tag_struct_count_search_callback_userdata*>(userdata_pointer);

		std::vector<const s_tag_struct_definition*>& structures = *userdata.structures;
		for (const s_tag_struct_definition* current_struct_definition : structures)
		{
			if (current_struct_definition == &struct_definition)
			{
				return;
			}
		}
		structures.push_back(&struct_definition);
		tag_struct_definition_counts[userdata.engine_platform_build.engine_type]++;
	}

	static unsigned long get_tag_struct_definition_count(s_engine_platform_build engine_platform_build)
	{
		static bool initialised[k_number_of_engine_types] = {};
		if (initialised[engine_platform_build.engine_type])
		{
			return tag_struct_definition_counts[engine_platform_build.engine_type];
		}

		std::vector<const s_tag_struct_definition*> structures;

		s_tag_struct_count_search_callback_userdata userdata;
		userdata.engine_platform_build = engine_platform_build;
		userdata.structures = &structures;

		for(const s_tag_group** tag_group_iter = blofeld::tag_groups[engine_platform_build.engine_type]; *tag_group_iter; tag_group_iter++)
		{
			const s_tag_group& tag_group = **tag_group_iter;

			blofeld::iterate_structure_fields(
				engine_platform_build,
				tag_group.block_definition.struct_definition,
				true,
				true,
				&tag_struct_count_search_callback,
				&userdata);
		}

		initialised[engine_platform_build.engine_type] = true;
		return tag_struct_definition_counts[engine_platform_build.engine_type];
	}

	struct s_tag_struct_definition_search_callback_userdata
	{
		s_engine_platform_build engine_platform_build;
		const s_tag_struct_definition*** current_write_position;
	};

	static void tag_struct_definition_search_callback(const s_tag_struct_definition& struct_definition, void* userdata_pointer)
	{
		const s_tag_struct_definition_search_callback_userdata& userdata = *reinterpret_cast<const s_tag_struct_definition_search_callback_userdata*>(userdata_pointer);

		const s_tag_struct_definition**& current_write_position = *userdata.current_write_position;

		unsigned long tag_struct_definition_count = tag_struct_definition_counts[userdata.engine_platform_build.engine_type];
		for (unsigned long tag_struct_index = 0; tag_struct_index < tag_struct_definition_count; tag_struct_index++)
		{
			const s_tag_struct_definition* current_struct_definition = tag_struct_definitions[userdata.engine_platform_build.engine_type][tag_struct_index];

			if (current_struct_definition == nullptr) break;
			if (current_struct_definition == &struct_definition)
			{
				return;
			}
		}

		*current_write_position = &struct_definition;
		current_write_position++;
	}

	const s_tag_struct_definition** get_tag_struct_definitions(s_engine_platform_build engine_platform_build)
	{
		static bool initialised[k_number_of_engine_types] = {};
		if (initialised[engine_platform_build.engine_type])
		{
			return tag_struct_definitions[engine_platform_build.engine_type];
		}

		get_tag_struct_definition_count(engine_platform_build);

		tag_struct_definitions[engine_platform_build.engine_type] = new() const s_tag_struct_definition * [tag_struct_definition_counts[engine_platform_build.engine_type] + 1]{};
		const s_tag_struct_definition** tag_struct_definition_write_position = tag_struct_definitions[engine_platform_build.engine_type];

		s_tag_struct_definition_search_callback_userdata userdata;
		userdata.engine_platform_build = engine_platform_build;
		userdata.current_write_position = &tag_struct_definition_write_position;

		for (const s_tag_group** tag_group_iter = blofeld::tag_groups[engine_platform_build.engine_type]; *tag_group_iter; tag_group_iter++)
		{
			const s_tag_group& tag_group = **tag_group_iter;
			blofeld::iterate_structure_fields(
				engine_platform_build,
				tag_group.block_definition.struct_definition,
				true,
				true,
				&tag_struct_definition_search_callback,
				&userdata);
		}

		initialised[engine_platform_build.engine_type] = true;
		return tag_struct_definitions[engine_platform_build.engine_type];
	}

} // namespace blofeld
