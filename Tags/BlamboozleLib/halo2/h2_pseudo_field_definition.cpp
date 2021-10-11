#include "blamboozlelib-private-pch.h"

c_h2_pseudo_field_definition::c_h2_pseudo_field_definition(const char* guerilla_data, const s_h2_tag_field& field) :
	name(h2_va_to_pointer_with_external_string(guerilla_data, field.name_address)),
	field_type(h2_field_type_to_h2_pseudo_field_type(field.field_type)),
	field(&field),
	block_definition(nullptr),
	tag_reference_definition(nullptr),
	struct_definition(nullptr),
	pseudo_array_definition(nullptr),
	string_list_definition(nullptr),
	padding(),
	skip_length(),
	explanation()
{
	switch (field.field_id_type)
	{
	case 0:
	case 0xFFFFFFFF:
	case _h2_field_id_bitmap_show_dialog:
	case _h2_field_id_hud_interface_show_weapon_dialog:
	case _h2_field_id_hud_interface_show_grenade_dialog:
	case _h2_field_id_hud_interface_show_unit_dialog:
	case _h2_field_id_sound_playback_dialog:
	case _h2_field_id_c_field_function_dialog:
	case _h2_field_id_c_tag_template_field_dialog:
	case _h2_field_id_c_model_bulk_import_dialog:
	case _h2_field_id_c_editor_tag_command_dialog:
	case _h2_field_id_c_marker_play_dialog:
	case _h2_field_id_c_biquad_graph_dialog:
	case _h2_field_id_c_sound_permutation_dialog:
	case _h2_field_id_c_string_editor_base:
	case _h2_field_id_scenario_environment_function:
	case _h2_field_id_squad_template:
	case _h2_field_id_type:
	case _h2_field_id_name:
	case _h2_field_id_filter:
	case _h2_field_id_object_editor:
	case _h2_field_id_point:
	case _h2_field_id_orientation:
	case _h2_field_id_scale:
	case _h2_field_id_hide:
	case _h2_field_id_enum:
	case _h2_field_id_manual_bsp_flags:
	case _h2_field_id_object_id:
	case _h2_field_id_object_variant:
	case _h2_field_id_pathfinding:
	case _h2_field_id_lflg:
	case _h2_field_id_allg:
	case _h2_field_id_hide_begin:
	case _h2_field_id_hide_end:
	case _h2_field_id_function_input_scalar:
	case _h2_field_id_function_input_range:
	case _h2_field_id_function_output_modifier_input:
	case _h2_field_id_function_unknown:
	case _h2_field_id_function_output_modifier:
	case _h2_field_id_halo_script_block:
	case _h2_field_id_cfpf:
	case _h2_field_id_cflt:
	case _h2_field_id_sort:
	case _h2_field_id_camera_matrix_editor:
	case _h2_field_id_align:
	case _h2_field_id_unknown_ugh:
	case _h2_field_id_wide:
	case _h2_field_id_decibels:
	case _h2_field_id_filx:
	case _h2_field_id_cents:
	case _h2_field_id_auds:
		break;
	default:
		FATAL_ERROR("Unknown field id type");
	}

	if (field.definition_address)
	{
		if (field.field_type == _h2_field_type_short_integer)
		{
			field_type = _h2_pseudo_field_type_short_block_index;
		}
		if (field.field_type == _h2_field_type_long_integer)
		{
			field_type = _h2_pseudo_field_type_long_block_index;
		}
	}
	if (field.field_type == _h2_field_type_array_end)
	{
		field_type = _h2_pseudo_field_type_terminator;
	}

	switch (field_type)
	{
	case _h2_pseudo_field_type_custom:
		//ASSERT(field.definition_address);
		ASSERT(field.field_id_type);
		break;
	case _h2_pseudo_field_type_custom_char_block_index:
	case _h2_pseudo_field_type_custom_short_block_index:
	case _h2_pseudo_field_type_custom_long_block_index:
		ASSERT(field.definition_address);
		break;
	case _h2_pseudo_field_type_char_block_index:
	case _h2_pseudo_field_type_short_block_index:
	case _h2_pseudo_field_type_long_block_index:
		ASSERT(field.definition_address);
		break;
	case _h2_pseudo_field_type_data:
		ASSERT(field.definition_address != 0);
		break;
	case _h2_pseudo_field_type_block:
		block_definition = c_h2_tag_block_definition::h2_get_tag_block_definition(guerilla_data, field.definition_address);
		break;
	case _h2_pseudo_field_type_struct:
	{
		const s_h2_tag_field_struct_definition* tag_struct_definition = reinterpret_cast<const s_h2_tag_field_struct_definition*>(h2_va_to_pointer(guerilla_data, field.definition_address));
		ASSERT(tag_struct_definition);

		c_h2_tag_block_definition* block_definition = c_h2_tag_block_definition::h2_get_tag_block_definition(guerilla_data, tag_struct_definition->block_definition_address);
		ASSERT(block_definition);

		struct_definition = block_definition->latest_pseudo_struct_definition;

		debug_point;
	}
	break;
	case _h2_pseudo_field_type_array:
		if (field.field_type == _h2_field_type_array_start)
		{
			ASSERT(field.definition_address > 0);
		}
		else
		{
			ASSERT(field.definition_address == 0);
		}
		break;
	case _h2_pseudo_field_type_tag_reference:
		tag_reference_definition = c_h2_tag_reference_definition::h2_get_tag_reference_definition(guerilla_data, field.definition_address);
		break;
	case _h2_pseudo_field_type_pad:
	case _h2_pseudo_field_type_useless_pad:
	case _h2_pseudo_field_type_skip:
		padding = skip_length = field.definition_address.value();
		break;
	case _h2_pseudo_field_type_char_enum:
	case _h2_pseudo_field_type_enum:
	case _h2_pseudo_field_type_long_enum:
	case _h2_pseudo_field_type_long_flags:
	case _h2_pseudo_field_type_word_flags:
	case _h2_pseudo_field_type_byte_flags:
		string_list_definition = c_h2_string_list_definition::h2_get_string_list_definition(guerilla_data, field.definition_address);
		break;
	case _h2_pseudo_field_type_long_block_flags:
	case _h2_pseudo_field_type_word_block_flags:
	case _h2_pseudo_field_type_byte_block_flags:
		ASSERT(field.definition_address != 0);
		break;
	case _h2_pseudo_field_type_explanation:
		if (field.definition_address)
			explanation = h2_va_to_pointer_with_external_string(guerilla_data, field.definition_address);
		break;
	case _h2_pseudo_field_type_string_id:
		break;
	case _h2_field_type_real:
		break;
	default:
		ASSERT(field.definition_address == 0);
	}
}

c_h2_pseudo_field_definition::c_h2_pseudo_field_definition(c_h2_pseudo_struct_definition& pseudo_struct_definition) :
	name(),
	field_type(_h2_pseudo_field_type_struct),
	field(nullptr),
	block_definition(nullptr),
	tag_reference_definition(nullptr),
	struct_definition(&pseudo_struct_definition),
	pseudo_array_definition(nullptr),
	string_list_definition(nullptr),
	padding(),
	skip_length(),
	explanation()
{
	ASSERT(pseudo_struct_definition.block_definitions.size() == 1);
	ASSERT(pseudo_struct_definition.block_definitions[0]->tag_group_definition);

	name = pseudo_struct_definition.block_definitions[0]->tag_group_definition->name;
}
