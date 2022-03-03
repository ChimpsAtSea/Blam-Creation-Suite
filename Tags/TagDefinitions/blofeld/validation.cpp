#include "tagdefinitions-private-pch.h"

namespace blofeld
{
	void validation_iterate_structure_fields(
		s_engine_platform_build engine_platform_build,
		const s_tag_struct_definition& struct_definition,
		bool recursive,
		bool recursive_block,
		t_iterate_structure_fields_callback* callback,
		void* userdata)
	{
		callback(struct_definition, userdata);


		for (const s_tag_field* current_field = struct_definition.fields; current_field->field_type != _field_terminator; current_field++)
		{
			unsigned long field_skip_count;
			if (execute_tag_field_versioning(*current_field, engine_platform_build, blofeld::ANY_TAG, field_skip_count))
			{
				current_field += field_skip_count;
				continue;
			}

			const char* field_string;
			ASSERT(BCS_SUCCEEDED(field_to_tag_field_type(current_field->field_type, field_string)));
			const char* nice_field_string = field_string + 1;

			if (recursive)
			{
				const s_tag_struct_definition* next_struct_definition = nullptr;
				switch (current_field->field_type)
				{
				case _field_struct:
				{
					next_struct_definition = current_field->struct_definition;
					break;
				}
				case _field_array:
				{
					next_struct_definition = &current_field->array_definition->struct_definition;
					break;
				}
				case _field_api_interop:
				{
					if (current_field->tag_interop_definition) // #TODO: enforce this
					{
						next_struct_definition = &current_field->tag_interop_definition->struct_definition;
					}
					break;
				}
				case _field_pageable:
				{
					next_struct_definition = current_field->struct_definition;
					break;
				}
				case _field_block:
					if (recursive_block)
					{
						if (current_field->block_definition)
						{
							next_struct_definition = &current_field->block_definition->struct_definition;
						}
						break;
					}
				//case _field_char_block_index:
				//case _field_short_block_index:
				//case _field_long_block_index:
				//	if (current_field->block_definition)
				//	{
				//		callback(current_field->block_definition->struct_definition, userdata);
				//	}
					break;
				}

				if (next_struct_definition != nullptr && next_struct_definition != &struct_definition)
				{
					validation_iterate_structure_fields(
						engine_platform_build,
						*next_struct_definition,
						recursive,
						recursive_block,
						callback,
						userdata);
				}
			}
		}
	}

	void validation_iterate_structure_fields(
		const s_tag_struct_definition& struct_definition,
		bool recursive,
		bool recursive_block,
		t_iterate_structure_fields_callback* callback,
		void* userdata)
	{
		validation_iterate_structure_fields({}, struct_definition, recursive, recursive_block, callback, userdata);
	}

	enum e_validation_warnings
	{
		_validation_warning_no_string_list_specified,
		_validation_warning_string_table_reached,
		_validation_warning_no_struct_specified,
		_validation_warning_no_array_specified,
		_validation_warning_no_block_specified,
		_validation_warning_no_tag_reference_specified,
		_validation_warning_no_pageable_specified,
		_validation_warning_no_api_interop_specified,
	};

	unsigned long calculate_struct_size(
		s_engine_platform_build engine_platform_build,
		const s_tag_struct_definition& struct_definition,
		e_validation_result* block_failed_validation,
		bool disable_platform_independent_warnings,
		std::map<const s_tag_field*, uint64_t>* warnings_tracking)
	{
#define GET_WARNING_VALUE(field) ((warnings_tracking && warnings_tracking->find(field) != warnings_tracking->end()) ? (*warnings_tracking)[field] : 0ull)
#define HAS_WARNING(field, warning) ((GET_WARNING_VALUE(field) & (1ull << warning)) != 0)
#define ADD_WARNING(field, warning) do { if(warnings_tracking) { (*warnings_tracking)[field] |= (1ull << warning); } } while(false)

		unsigned long computed_size = 0;

		for (const s_tag_field* current_field = struct_definition.fields; current_field->field_type != _field_terminator; current_field++)
		{
			unsigned long field_skip_count;
			if (execute_tag_field_versioning(*current_field, engine_platform_build, blofeld::ANY_TAG, field_skip_count))
			{
				current_field += field_skip_count;
				continue;
			}

			const char* field_string;
			ASSERT(BCS_SUCCEEDED(field_to_tag_field_type(current_field->field_type, field_string)));

			if (block_failed_validation)
			{
				// data validation
				switch (current_field->field_type)
				{
				case _field_char_enum:
				case _field_enum:
				case _field_long_enum:
				case _field_long_flags:
				case _field_word_flags:
				case _field_byte_flags:
					if (current_field->string_list_definition == nullptr)
					{
						if (!disable_platform_independent_warnings && !HAS_WARNING(current_field, _validation_warning_no_string_list_specified))
						{
							ADD_WARNING(current_field, _validation_warning_no_string_list_specified);
							console_write_line("%s(%i): warning V1000: '%s' '%s':'%s' failed validation. no string list specified.", current_field->filename, current_field->line, field_string, struct_definition.name, current_field->name);
						}
						*block_failed_validation = _validation_result_field_missing_string_list;
					}
					else 
					{
						unsigned long string_count = current_field->string_list_definition->get_count(engine_platform_build);
						//if (string_count == k_versioned_string_list_table_size)
						//{
						//	ADD_WARNING(current_field, _validation_warning_string_table_reached);
						//	console_write_line("%s(%i): warning V1001: '%s' '%s':'%s' failed validation. string table reached limit!.", current_field->filename, current_field->line, field_string, struct_definition.name, current_field->name);
						//	*block_failed_validation = _validation_result_string_list_limit_reached;
						//}
					}
					break;
				case _field_struct:
					if (current_field->struct_definition == nullptr)
					{
						if (!disable_platform_independent_warnings && !HAS_WARNING(current_field, _validation_warning_no_struct_specified))
						{
							ADD_WARNING(current_field, _validation_warning_no_struct_specified);
							console_write_line("%s(%i): warning V2000: '%s' '%s':'%s' failed validation. no struct specified.", current_field->filename, current_field->line, field_string, struct_definition.name, current_field->name);
						}
						*block_failed_validation = _validation_result_field_missing_struct_definition;
						continue;
					}
					break;
				case _field_array:
					if (current_field->array_definition == nullptr)
					{
						if (!disable_platform_independent_warnings && !HAS_WARNING(current_field, _validation_warning_no_array_specified))
						{
							ADD_WARNING(current_field, _validation_warning_no_array_specified);
							console_write_line("%s(%i): warning V3000: '%s' '%s':'%s' failed validation. no array specified.", current_field->filename, current_field->line, field_string, struct_definition.name, current_field->name);
						}
						*block_failed_validation = _validation_result_field_missing_array_definition;
						continue;
					}
					break;
				case _field_block:
					if (current_field->block_definition == nullptr)
					{
						if (!disable_platform_independent_warnings && !HAS_WARNING(current_field, _validation_warning_no_block_specified))
						{
							ADD_WARNING(current_field, _validation_warning_no_block_specified);
							console_write_line("%s(%i): warning V2000: '%s' '%s':'%s' failed validation. no block specified.", current_field->filename, current_field->line, field_string, struct_definition.name, current_field->name);
						}
						*block_failed_validation = _validation_result_field_missing_block_definition;
						continue;
					}
					break;
				case _field_tag_reference:
					if (current_field->tag_reference_definition == nullptr)
					{
						if (!disable_platform_independent_warnings && !HAS_WARNING(current_field, _validation_warning_no_tag_reference_specified))
						{
							ADD_WARNING(current_field, _validation_warning_no_tag_reference_specified);
							console_write_line("%s(%i): warning V4000: '%s' '%s':'%s' failed validation. no tag reference specified.", current_field->filename, current_field->line, field_string, struct_definition.name, current_field->name);
						}
						*block_failed_validation = _validation_result_field_missing_tag_reference;
						continue;
					}
					break;
				case _field_pageable:
					if (current_field->struct_definition == nullptr)
					{
						if (!disable_platform_independent_warnings && !HAS_WARNING(current_field, _validation_warning_no_pageable_specified))
						{
							ADD_WARNING(current_field, _validation_warning_no_pageable_specified);
							console_write_line("%s(%i): warning V5000: '%s' '%s':'%s' failed validation. no pageable specified.", current_field->filename, current_field->line, field_string, struct_definition.name, current_field->name);
						}
						//*block_failed_validation = _validation_result_field_missing_block_definition;
						//continue;
					}
				break;
				case _field_api_interop:
					if (current_field->struct_definition == nullptr)
					{
						if (!disable_platform_independent_warnings && !HAS_WARNING(current_field, _validation_warning_no_api_interop_specified))
						{
							ADD_WARNING(current_field, _validation_warning_no_api_interop_specified);
							console_write_line("%s(%i): warning V6000: '%s' '%s':'%s' failed validation. no api interop specified.", current_field->filename, current_field->line, field_string, struct_definition.name, current_field->name);
						}
						*block_failed_validation = _validation_result_field_missing_block_definition;
						continue;
					}
					break;
				}

				//c_blamlib_string_parser field_formatter(current_field, current_field->name, nullptr);
				//if (field_formatter.is_pointer && current_field->field_type == _field_long_integer)
				//{
				//	console_write_line("%s(%i): warning V5000: '%s' '%s' failed validation. field type is not pointer.", current_field->filename, current_field->line, field_string, current_field->name);
				//}


			}

			switch (current_field->field_type)
			{
			case _field_useless_pad:
				//computed_size += current_field->padding;
				break;
			case _field_pad:
				computed_size += current_field->padding;
				break;
			case _field_skip:
				computed_size += current_field->length;
				break;
			case _field_struct:
				computed_size += calculate_struct_size(engine_platform_build, *current_field->struct_definition, block_failed_validation, disable_platform_independent_warnings, warnings_tracking);
				break;
			case _field_array:
			{
				const s_tag_array_definition& array_definition = *current_field->array_definition;
				REFERENCE_ASSERT(array_definition);
				const s_tag_struct_definition& struct_definition = array_definition.struct_definition;
				REFERENCE_ASSERT(struct_definition);
				unsigned long struct_size = calculate_struct_size(engine_platform_build, struct_definition, block_failed_validation, disable_platform_independent_warnings, warnings_tracking);
				unsigned long array_data_size = struct_size * array_definition.count(engine_platform_build);
				computed_size += array_data_size;
				break;
			}
			default:
				computed_size += get_blofeld_field_size(engine_platform_build.platform_type, current_field->field_type);
				break;
			}
		}

		return computed_size;
	}

	bool validate_all_definitions(std::map<const s_tag_field*, uint64_t>* warnings_tracking)
	{
		bool any_block_failed_validation = false;
		unsigned long validation_attempts = 0;
		unsigned long successful_validation_attempts = 0;

		for (unsigned long engine_type_index = 0; engine_type_index < k_number_of_engine_types; engine_type_index++)
		{
			e_engine_type engine_type = static_cast<e_engine_type>(engine_type_index);

			c_tag_struct_definition_view tag_struct_view({ engine_type });

			for (const s_tag_struct_definition** struct_definition_iter = tag_struct_view.get_tag_struct_definitions(); *struct_definition_iter; struct_definition_iter++)
			{
				const s_tag_struct_definition& struct_definition = **struct_definition_iter;

				validation_attempts++;

				e_validation_result block_failed_validation = _validation_result_ok;
				const char* const block_name = struct_definition.name;

				e_platform_type platform_type = _platform_type_pc_64bit;
				calculate_struct_size({ engine_type, _platform_type_pc_64bit, _build_not_set }, struct_definition, &block_failed_validation, platform_type == _platform_type_not_set, warnings_tracking);

				if (block_failed_validation == _validation_result_ok)
				{
					successful_validation_attempts++;
				}
				else
				{
					any_block_failed_validation = true;
				}
			}
		}
		float percentage = 100.0f * float(successful_validation_attempts) / float(validation_attempts);
		if (percentage != 100.0f)
		{
			console_write_line("warning V0001: failed to validate all tags. success rate %.1f.", percentage);
		}
		return any_block_failed_validation;
	}

	bool validate_gen3_definitions(std::map<const s_tag_field*, uint64_t>* warnings_tracking)
	{
		bool any_block_failed_validation = false;
		unsigned long successful_validation_attempts = 0;
		for (s_tag_struct_validation_data& struct_validation_data : gen3_xbox360_tag_struct_validation_data)
		{
			e_validation_result block_failed_validation = _validation_result_ok;
			const s_tag_struct_definition& struct_definition = struct_validation_data.struct_definition;
			const char* const block_name = struct_definition.name;
			unsigned long const expected_size = struct_validation_data.size;

			e_engine_type engine_type = _engine_type_gen3_xbox360;
			e_platform_type platform_type = _platform_type_xbox_360;
			unsigned long computed_size = calculate_struct_size({ engine_type, platform_type, _build_not_set }, struct_definition, &block_failed_validation, platform_type == _platform_type_not_set, warnings_tracking);

			if (computed_size != expected_size)
			{
				block_failed_validation = _validation_result_struct_invalid_size;
				console_write_line("%s(%i): warning V0002: s_tag_struct '%s' failed validation. computed size 0x%x expected 0x%x", struct_definition.filename, struct_definition.line, block_name, computed_size, expected_size);
			}

			if (block_failed_validation == _validation_result_ok)
			{
				successful_validation_attempts++;
			}
			else
			{
				any_block_failed_validation = true;
			}
		}
		float percentage = 100.0f * float(successful_validation_attempts) / float(_countof(gen3_xbox360_tag_struct_validation_data));
		if (percentage != 100.0f)
		{
			console_write_line("warning V0001: failed to validate all tags. success rate %.1f.", percentage);
		}
		return any_block_failed_validation;
	}

	bool validate_halo4_xbox360_definitions(std::map<const s_tag_field*, uint64_t>* warnings_tracking)
	{
		bool any_block_failed_validation = false;
		unsigned long successful_validation_attempts = 0;
		for (s_tag_struct_validation_data& struct_validation_data : gen3_xbox360_tag_struct_validation_data)
		{
			e_validation_result block_failed_validation = _validation_result_ok;
			const s_tag_struct_definition& struct_definition = struct_validation_data.struct_definition;
			const char* const block_name = struct_definition.name;
			unsigned long const expected_size = struct_validation_data.size;

			e_engine_type engine_type = _engine_type_halo4;
			e_platform_type platform_type = _platform_type_xbox_360;
			unsigned long computed_size = calculate_struct_size({ engine_type, platform_type, _build_not_set }, struct_definition, &block_failed_validation, platform_type == _platform_type_not_set, warnings_tracking);

			if (computed_size != expected_size)
			{
				block_failed_validation = _validation_result_struct_invalid_size;
				console_write_line("%s(%i): warning V0002: s_tag_struct '%s' failed validation. computed size 0x%x expected 0x%x", struct_definition.filename, struct_definition.line, block_name, computed_size, expected_size);
			}

			if (block_failed_validation == _validation_result_ok)
			{
				successful_validation_attempts++;
			}
			else
			{
				any_block_failed_validation = true;
			}
		}
		float percentage = 100.0f * float(successful_validation_attempts) / float(_countof(gen3_xbox360_tag_struct_validation_data));
		if (percentage != 100.0f)
		{
			console_write_line("warning V0001: failed to validate all tags. success rate %.1f.", percentage);
		}
		return any_block_failed_validation;
	}

}
