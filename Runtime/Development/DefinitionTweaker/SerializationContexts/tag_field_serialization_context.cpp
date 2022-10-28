#include "definitiontweaker-private-pch.h"

c_tag_field_serialization_context::c_tag_field_serialization_context(
	c_tag_struct_serialization_context& _tag_struct_serialization_context,
	const char* _field_data,
	c_runtime_tag_field_definition& _runtime_tag_field_definition) :
	c_serialization_context(_tag_struct_serialization_context),
	tag_struct_serialization_context(_tag_struct_serialization_context),
	field_data(_field_data),
	field_size(),
	runtime_tag_field_definition(_runtime_tag_field_definition)
{

}

c_tag_field_serialization_context::~c_tag_field_serialization_context()
{

}

void c_tag_field_serialization_context::read()
{
	if (!serialization_errors.empty())
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_tag_serialization_state_warning,
			"skipping read due to issues");
		return;
	}

	field_size = c_tag_field_serialization_context::calculate_field_size(*this, runtime_tag_field_definition);

	c_tag_serialization_context& tag_serialization_context = tag_struct_serialization_context.tag_serialization_context;
	const char* read_position = field_data;

	if (read_position < tag_serialization_context.tag_data_start)
	{
		intptr_t bytes = tag_serialization_context.tag_data_end - read_position;
		enqueue_serialization_error<c_generic_serialization_error>(
			_tag_serialization_state_error,
			"field data read before tag data start (bytes:%zu)", bytes);
	}

	read_position += field_size;

	if (read_position > tag_serialization_context.tag_data_end)
	{
		intptr_t bytes = read_position - tag_serialization_context.tag_data_end;
		enqueue_serialization_error<c_generic_serialization_error>(
			_tag_serialization_state_error,
			"field data read after tag data start (bytes:%zu)", bytes);
	}
}

void c_tag_field_serialization_context::traverse()
{
	if (!serialization_errors.empty())
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_tag_serialization_state_warning,
			"skipping traverse due to issues");
		return;
	}
}

void c_tag_field_serialization_context::render_tree()
{
	ImGui::PushID(this);
	ImGui::PushStyleColor(ImGuiCol_Text, serialization_error_colors[max_serialization_error_type]);

	static ImGuiTreeNodeFlags flags =
		ImGuiTreeNodeFlags_SpanFullWidth;
	if (true /*field_serialization_contexts.empty()*/)
	{
		flags = flags | ImGuiTreeNodeFlags_Leaf;
	}
	const char* field_type_name = "<bad>";
	blofeld::field_to_tagfile_field_type(runtime_tag_field_definition.field_type, field_type_name);
	const char* field_name = runtime_tag_field_definition.name.c_str();
	bool tree_node_result = ImGui::TreeNodeEx(this, flags, "%s %s", field_type_name, field_name);
	render_hover_tooltip();
	if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
	{
		debug_point;
	}
	if (tree_node_result)
	{
		//if (c_tag_struct_serialization_context* struct_serialization_context = root_struct_serialization_context)
		//{
		//	struct_serialization_context->render_tree();
		//}
		ImGui::TreePop();
	}

	ImGui::PopStyleColor();
	ImGui::PopID();
}

unsigned int c_tag_field_serialization_context::calculate_field_size(c_serialization_context& serialization_context, c_runtime_tag_field_definition& runtime_field)
{
#define field_size(_field, size) if(_field == runtime_field.field_type) { return (size); }

	field_size(blofeld::_field_string, sizeof(::c_static_string<32>));
	field_size(blofeld::_field_long_string, sizeof(::c_static_string<256>));
	field_size(blofeld::_field_string_id, sizeof(string_id));
	field_size(blofeld::_field_old_string_id, sizeof(::c_old_string_id));
	field_size(blofeld::_field_char_integer, sizeof(char));
	field_size(blofeld::_field_short_integer, sizeof(short));
	field_size(blofeld::_field_long_integer, sizeof(long));
	field_size(blofeld::_field_int64_integer, sizeof(int64_t));
	field_size(blofeld::_field_angle, sizeof(angle));
	field_size(blofeld::_field_tag, sizeof(tag));
	field_size(blofeld::_field_char_enum, sizeof(char));
	field_size(blofeld::_field_short_enum, sizeof(short));
	field_size(blofeld::_field_long_enum, sizeof(long));
	field_size(blofeld::_field_long_flags, sizeof(long));
	field_size(blofeld::_field_word_flags, sizeof(word));
	field_size(blofeld::_field_byte_flags, sizeof(byte));
	field_size(blofeld::_field_point_2d, sizeof(::s_point2d));
	field_size(blofeld::_field_rectangle_2d, sizeof(::s_rectangle2d));
	field_size(blofeld::_field_rgb_color, sizeof(::pixel32));
	field_size(blofeld::_field_argb_color, sizeof(::pixel32));
	field_size(blofeld::_field_real, sizeof(::real));
	field_size(blofeld::_field_real_slider, sizeof(::real));
	field_size(blofeld::_field_real_fraction, sizeof(::real_fraction));
	field_size(blofeld::_field_real_point_2d, sizeof(::real_point2d));
	field_size(blofeld::_field_real_point_3d, sizeof(::real_point3d));
	field_size(blofeld::_field_real_vector_2d, sizeof(::real_vector2d));
	field_size(blofeld::_field_real_vector_3d, sizeof(::real_vector3d));
	field_size(blofeld::_field_real_quaternion, sizeof(::real_quaternion));
	field_size(blofeld::_field_real_euler_angles_2d, sizeof(::real_euler_angles2d));
	field_size(blofeld::_field_real_euler_angles_3d, sizeof(::real_euler_angles3d));
	field_size(blofeld::_field_real_plane_2d, sizeof(::real_plane2d));
	field_size(blofeld::_field_real_plane_3d, sizeof(::real_plane3d));
	field_size(blofeld::_field_real_rgb_color, sizeof(::rgb_color));
	field_size(blofeld::_field_real_argb_color, sizeof(::argb_color));
	field_size(blofeld::_field_real_hsv_color, sizeof(::real_hsv_color));
	field_size(blofeld::_field_real_ahsv_color, sizeof(::real_ahsv_color));
	field_size(blofeld::_field_short_integer_bounds, sizeof(::short_bounds));
	field_size(blofeld::_field_angle_bounds, sizeof(::angle_bounds));
	field_size(blofeld::_field_real_bounds, sizeof(::real_bounds));
	field_size(blofeld::_field_real_fraction_bounds, sizeof(::real_fraction_bounds));
	field_size(blofeld::_field_tag_reference, sizeof(::s_tag_reference));
	field_size(blofeld::_field_block, sizeof(::s_tag_block));
	field_size(blofeld::_field_long_block_flags, sizeof(long));
	field_size(blofeld::_field_word_block_flags, sizeof(word));
	field_size(blofeld::_field_byte_block_flags, sizeof(byte));
	field_size(blofeld::_field_char_block_index, sizeof(char));
	field_size(blofeld::_field_char_block_index_custom_search, sizeof(char));
	field_size(blofeld::_field_short_block_index, sizeof(short));
	field_size(blofeld::_field_short_block_index_custom_search, sizeof(short));
	field_size(blofeld::_field_long_block_index, sizeof(long));
	field_size(blofeld::_field_long_block_index_custom_search, sizeof(long));
	field_size(blofeld::_field_data, sizeof(::s_tag_data));
	field_size(blofeld::_field_vertex_buffer, sizeof(::s_tag_d3d_vertex_buffer));
	field_size(blofeld::_field_pad, runtime_field.padding);
	field_size(blofeld::_field_useless_pad, runtime_field.padding);
	field_size(blofeld::_field_skip, runtime_field.length);
	field_size(blofeld::_field_non_cache_runtime_value, 0);
	field_size(blofeld::_field_explanation, 0);
	field_size(blofeld::_field_custom, 0);
	if (runtime_field.field_type == blofeld::_field_struct)
	{
		if (c_runtime_tag_struct_definition* struct_definition = runtime_field.struct_definition)
		{
			unsigned int field_struct_size = c_tag_struct_serialization_context::calculate_struct_size(serialization_context, *struct_definition);
			if (field_struct_size == 0)
			{
				serialization_context.enqueue_serialization_error<c_generic_serialization_error>(
					_tag_serialization_state_error,
					"field '%s' struct '%' has zero size",
					runtime_field.name.c_str(),
					struct_definition->name.c_str());
			}
			return field_struct_size;
		}
		else
		{
			serialization_context.enqueue_serialization_error<c_generic_serialization_error>(
				_tag_serialization_state_error,
				"field '%s' struct is null",
				runtime_field.name.c_str());
			return 0;
		}
	}
	if (runtime_field.field_type == blofeld::_field_array)
	{
		if (c_runtime_tag_array_definition* array_definition = runtime_field.array_definition)
		{
			if (c_runtime_tag_struct_definition* struct_definition = array_definition->struct_definition)
			{
				unsigned int field_struct_size = c_tag_struct_serialization_context::calculate_struct_size(serialization_context, *struct_definition);
				if (field_struct_size == 0)
				{
					serialization_context.enqueue_serialization_error<c_generic_serialization_error>(
						_tag_serialization_state_error,
						"field '%s' array struct '%' has zero size",
						runtime_field.name.c_str(),
						struct_definition->name.c_str());
				}
				return field_struct_size;
			}
			else
			{
				serialization_context.enqueue_serialization_error<c_generic_serialization_error>(
					_tag_serialization_state_error,
					"field '%s' array struct is null",
					runtime_field.name.c_str());
				return 0;
			}
		}
		else
		{
			serialization_context.enqueue_serialization_error<c_generic_serialization_error>(
				_tag_serialization_state_error,
				"field '%s' array definition is null",
				runtime_field.name.c_str());
			return 0;
		}
	}
	field_size(blofeld::_field_pageable_resource, sizeof(::s_tag_resource));
	field_size(blofeld::_field_api_interop, sizeof(::s_tag_interop));
	field_size(blofeld::_field_terminator, 0);
	field_size(blofeld::_field_byte_integer, sizeof(byte));
	field_size(blofeld::_field_word_integer, sizeof(word));
	field_size(blofeld::_field_dword_integer, sizeof(dword));
	field_size(blofeld::_field_qword_integer, sizeof(qword));
	field_size(blofeld::_field_embedded_tag, sizeof(::s_tag_reference));
	field_size(blofeld::_field_data_path, sizeof(::c_static_string<256>));
	if (runtime_field.field_type == blofeld::_field_pointer)
	{
		unsigned int pointer_size = 0;
		ASSERT(BCS_SUCCEEDED(get_platform_pointer_size(serialization_context.engine_platform_build.platform_type, &pointer_size)));
		return pointer_size;
	};
	field_size(blofeld::_field_half, sizeof(word));

	FATAL_ERROR("Unsupported field type");

#undef field_size
}
