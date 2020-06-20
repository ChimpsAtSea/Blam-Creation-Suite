#include <tagdefinitions-private-pch.h>

namespace blofeld
{
	static uint32_t tag_struct_definition_count = 0;
	const s_tag_struct_definition** tag_struct_definitions = nullptr;

	static void tag_struct_count_search_callback(const s_tag_struct_definition& struct_definition, void* userdata)
	{
		std::vector<const s_tag_struct_definition*>& structures = *reinterpret_cast<std::vector<const s_tag_struct_definition*>*>(userdata);
		for (const s_tag_struct_definition* current_struct_definition : structures)
		{
			if (current_struct_definition == &struct_definition)
			{
				return;
			}
		}
		structures.push_back(&struct_definition);
		tag_struct_definition_count++;
	}

	static uint32_t get_tag_struct_definition_count()
	{
		static bool initialised = false;
		if (initialised)
		{
			return tag_struct_definition_count;
		}

		std::vector<const s_tag_struct_definition*> structures;

		for (const s_tag_group& tag_group : c_reference_loop(blofeld::tag_groups))
		{
			blofeld::iterate_structure_fields(
				tag_group.block_definition.struct_definition,
				true,
				true,
				&tag_struct_count_search_callback,
				&structures);
		}

		initialised = true;
		return tag_struct_definition_count;
	}

	static void tag_struct_definition_search_callback(const s_tag_struct_definition& struct_definition, void* userdata)
	{
		const s_tag_struct_definition**& current_write_position = *reinterpret_cast<const s_tag_struct_definition***>(userdata);
		for (const s_tag_struct_definition* current_struct_definition : c_range_loop(tag_struct_definitions, tag_struct_definition_count))
		{
			if (current_struct_definition == nullptr) break;
			if (current_struct_definition == &struct_definition)
			{
				return;
			}
		}

		*current_write_position = &struct_definition;
		current_write_position++;
	}

	const s_tag_struct_definition** get_tag_struct_definitions()
	{
		static bool initialised = false;
		if (initialised)
		{
			return tag_struct_definitions;
		}

		get_tag_struct_definition_count();

		tag_struct_definitions = new const s_tag_struct_definition * [tag_struct_definition_count + 1] {};
		const s_tag_struct_definition** tag_struct_definition_write_position = tag_struct_definitions;

		for (const s_tag_group& tag_group : c_reference_loop(blofeld::tag_groups))
		{
			blofeld::iterate_structure_fields(
				tag_group.block_definition.struct_definition,
				true,
				true,
				&tag_struct_definition_search_callback,
				&tag_struct_definition_write_position);
		}

		initialised = true;
		return tag_struct_definitions;
	}

} // namespace blofeld

