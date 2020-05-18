#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(error_report_vertices_block, MAXIMUM_VERTICES_PER_ERROR_REPORT)
	{
		{ _field_struct, "point", &error_report_point_definition_struct_definition },
		{ _field_real_argb_color, "color*" },
		{ _field_real, "screen size*" },
		{ _field_terminator }
	};

	TAG_BLOCK(error_report_vectors_block, MAXIMUM_VECTORS_PER_ERROR_REPORT)
	{
		{ _field_struct, "point", &error_report_point_definition_struct_definition },
		{ _field_real_argb_color, "color*" },
		{ _field_real_vector_3d, "normal*" },
		{ _field_real, "screen length*" },
		{ _field_terminator }
	};

	TAG_BLOCK(error_report_lines_block, MAXIMUM_LINES_PER_ERROR_REPORT)
	{
		{ _field_array, "points*", &error_report_line_point_array_array },
		{ _field_real_argb_color, "color*" },
		{ _field_terminator }
	};

	TAG_BLOCK(error_report_triangles_block, MAXIMUM_TRIANGLES_PER_ERROR_REPORT)
	{
		{ _field_array, "points*", &error_report_triangle_point_array_array },
		{ _field_real_argb_color, "color*" },
		{ _field_terminator }
	};

	TAG_BLOCK(error_report_quads_block, MAXIMUM_QUADS_PER_ERROR_REPORT)
	{
		{ _field_array, "points*", &error_report_quad_point_array_array },
		{ _field_real_argb_color, "color*" },
		{ _field_terminator }
	};

	TAG_BLOCK(error_report_comments_block, MAXIMUM_COMMENTS_PER_ERROR_REPORT)
	{
		{ _field_data, "text*" },
		{ _field_struct, "point", &error_report_point_definition_struct_definition },
		{ _field_real_argb_color, "color*" },
		{ _field_terminator }
	};

	TAG_BLOCK(error_reports_block, MAXIMUM_REPORTS_PER_ERROR_REPORT_CATEGORY)
	{
		{ _field_char_enum, "type*", &error_report_types },
		{ _field_char_enum, "source*", &error_report_source },
		{ _field_word_flags, "flags*", &error_report_flags },
		{ _field_data, "text*" },
		{ _field_long_integer, "source identifier*" },
		{ _field_string, "source filename*" },
		{ _field_long_integer, "source line number*" },
		{ _field_block, "vertices*", &error_report_vertices_block_block },
		{ _field_block, "vectors*", &error_report_vectors_block_block },
		{ _field_block, "lines*", &error_report_lines_block_block },
		{ _field_block, "triangles*", &error_report_triangles_block_block },
		{ _field_block, "quads*", &error_report_quads_block_block },
		{ _field_block, "comments*", &error_report_comments_block_block },
		{ _field_long_integer, "report key*" },
		{ _field_long_integer, "node index*" },
		{ _field_real_bounds, "bounds x*" },
		{ _field_real_bounds, "bounds y*" },
		{ _field_real_bounds, "bounds z*" },
		{ _field_real_argb_color, "color*" },
		{ _field_terminator }
	};

	TAG_BLOCK(global_error_report_categories_block, MAXIMUM_ERROR_REPORT_CATEGORIES)
	{
		{ _field_long_string, "name^*" },
		{ _field_enum, "report type*", &error_report_types },
		{ _field_word_flags, "flags*", &error_report_flags },
		{ _field_short_integer, "runtime generation flags!" },
		{ _field_pad, "WVTP", 2 },
		{ _field_long_integer, "runtime something~!" },
		{ _field_block, "reports*", &error_reports_block_block },
		{ _field_terminator }
	};

	TAG_ARRAY(error_point_node_index_array, MAXIMUM_NODE_INDICES_PER_ERROR_POINT)
	{
		{ _field_char_integer, "node index*" },
		{ _field_terminator }
	};

	TAG_ARRAY(error_point_node_weight_array, MAXIMUM_NODE_INDICES_PER_ERROR_POINT)
	{
		{ _field_real, "node weight*" },
		{ _field_terminator }
	};

	TAG_ARRAY(error_report_line_point_array, k_vertices_per_line_count)
	{
		{ _field_struct, "point", &error_report_point_definition_struct_definition },
		{ _field_terminator }
	};

	TAG_ARRAY(error_report_triangle_point_array, k_vertices_per_triangle_count)
	{
		{ _field_struct, "point", &error_report_point_definition_struct_definition },
		{ _field_terminator }
	};

	TAG_ARRAY(error_report_quad_point_array, k_vertices_per_quadrilateral_count)
	{
		{ _field_struct, "point", &error_report_point_definition_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(error_report_point_definition)
	{
		{ _field_real_point_3d, "position*" },
		{ _field_array, "node indices*", &error_point_node_index_array_array },
		{ _field_array, "node weights*", &error_point_node_weight_array_array },
		{ _field_terminator }
	};

	STRINGS(error_report_types)
	{
		"silent",
		"comment",
		"warning",
		"error"
	};
	STRING_LIST(error_report_types, error_report_types_strings, _countof(error_report_types_strings));

	STRINGS(error_report_source)
	{
		"none",
		"structure",
		"poop",
		"lightmap",
		"pathfinding"
	};
	STRING_LIST(error_report_source, error_report_source_strings, _countof(error_report_source_strings));

	STRINGS(error_report_flags)
	{
		"rendered",
		"tangent-space",
		"non-critical",
		"lightmap light",
		"report key is valid"
	};
	STRING_LIST(error_report_flags, error_report_flags_strings, _countof(error_report_flags_strings));

} // namespace blofeld

