#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{



	#define GLOBAL_ERROR_REPORT_CATEGORIES_BLOCK_ID { 0x3CBB78D5, 0xCA074D83, 0x8994291A, 0x8E13F496 }
	TAG_BLOCK(
		global_error_report_categories_block,
		"error report category",
		MAXIMUM_ERROR_REPORT_CATEGORIES,
		"error_report_category",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE),
		GLOBAL_ERROR_REPORT_CATEGORIES_BLOCK_ID)
	{
		{ _field_long_string, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_enum, "report type", FIELD_FLAG_READ_ONLY, &error_report_types },
		{ _field_word_flags, "flags", FIELD_FLAG_READ_ONLY, &error_report_flags },
		{ _field_short_integer, "runtime generation flags", FIELD_FLAG_UNKNOWN0 },
		FIELD_PAD("WVTP", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_long_integer, "runtime something", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_block, "reports", FIELD_FLAG_READ_ONLY, &error_reports_block },
		{ _field_terminator }
	};

	#define ERROR_REPORTS_BLOCK_ID { 0xEE6AAB20, 0x3227499F, 0x914508D6, 0x40FCAA9E }
	TAG_BLOCK(
		error_reports_block,
		"error report",
		MAXIMUM_REPORTS_PER_ERROR_REPORT_CATEGORY,
		"error_report",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ERROR_REPORTS_BLOCK_ID)
	{
		{ _field_char_enum, "type", FIELD_FLAG_READ_ONLY, &error_report_types },
		{ _field_char_enum, "source", FIELD_FLAG_READ_ONLY, &error_report_source },
		{ _field_word_flags, "flags", FIELD_FLAG_READ_ONLY, &error_report_flags },
		{ _field_data, "text", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "source identifier", FIELD_FLAG_READ_ONLY },
		{ _field_string, "source filename", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "source line number", FIELD_FLAG_READ_ONLY },
		{ _field_block, "vertices", FIELD_FLAG_READ_ONLY, &error_report_vertices_block },
		{ _field_block, "vectors", FIELD_FLAG_READ_ONLY, &error_report_vectors_block },
		{ _field_block, "lines", FIELD_FLAG_READ_ONLY, &error_report_lines_block },
		{ _field_block, "triangles", FIELD_FLAG_READ_ONLY, &error_report_triangles_block },
		{ _field_block, "quads", FIELD_FLAG_READ_ONLY, &error_report_quads_block },
		{ _field_block, "comments", FIELD_FLAG_READ_ONLY, &error_report_comments_block },
		{ _field_long_integer, "report key", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "node index", FIELD_FLAG_READ_ONLY },
		{ _field_real_bounds, "bounds x", FIELD_FLAG_READ_ONLY },
		{ _field_real_bounds, "bounds y", FIELD_FLAG_READ_ONLY },
		{ _field_real_bounds, "bounds z", FIELD_FLAG_READ_ONLY },
		{ _field_real_argb_color, "color", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define ERROR_REPORT_VERTICES_BLOCK_ID { 0xB44D11D1, 0xA884463D, 0xB9552513, 0x0E390450 }
	TAG_BLOCK(
		error_report_vertices_block,
		"error report vertex",
		MAXIMUM_VERTICES_PER_ERROR_REPORT,
		"error_report_vertex",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ERROR_REPORT_VERTICES_BLOCK_ID)
	{
		{ _field_struct, "point", &error_report_point_definition },
		{ _field_real_argb_color, "color", FIELD_FLAG_READ_ONLY },
		{ _field_real, "screen size", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define ERROR_REPORT_VECTORS_BLOCK_ID { 0xF617E038, 0x0B4E4E8D, 0xAF4F86B9, 0x02745E1F }
	TAG_BLOCK(
		error_report_vectors_block,
		"error report vector",
		MAXIMUM_VECTORS_PER_ERROR_REPORT,
		"error_report_vector",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ERROR_REPORT_VECTORS_BLOCK_ID)
	{
		{ _field_struct, "point", &error_report_point_definition },
		{ _field_real_argb_color, "color", FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "normal", FIELD_FLAG_READ_ONLY },
		{ _field_real, "screen length", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define ERROR_REPORT_LINES_BLOCK_ID { 0x1C172D3C, 0x604A4356, 0x8F1BDE48, 0xE0CA8284 }
	TAG_BLOCK(
		error_report_lines_block,
		"error report line",
		MAXIMUM_LINES_PER_ERROR_REPORT,
		"error_report_line",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ERROR_REPORT_LINES_BLOCK_ID)
	{
		{ _field_array, "points", FIELD_FLAG_READ_ONLY, &error_report_line_point_array },
		{ _field_real_argb_color, "color", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define ERROR_REPORT_TRIANGLES_BLOCK_ID { 0xF926E761, 0x001244E3, 0x85173116, 0x2B96347A }
	TAG_BLOCK(
		error_report_triangles_block,
		"error report triangle",
		MAXIMUM_TRIANGLES_PER_ERROR_REPORT,
		"error_report_triangle",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ERROR_REPORT_TRIANGLES_BLOCK_ID)
	{
		{ _field_array, "points", FIELD_FLAG_READ_ONLY, &error_report_triangle_point_array },
		{ _field_real_argb_color, "color", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define ERROR_REPORT_QUADS_BLOCK_ID { 0xD1071621, 0xE7D84305, 0x8AEA9FCC, 0xC52955BF }
	TAG_BLOCK(
		error_report_quads_block,
		"error report quad",
		MAXIMUM_QUADS_PER_ERROR_REPORT,
		"error_report_quad",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ERROR_REPORT_QUADS_BLOCK_ID)
	{
		{ _field_array, "points", FIELD_FLAG_READ_ONLY, &error_report_quad_point_array },
		{ _field_real_argb_color, "color", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define ERROR_REPORT_COMMENTS_BLOCK_ID { 0x709A9566, 0xDEA34617, 0x8AFF50B9, 0xDB6DE950 }
	TAG_BLOCK(
		error_report_comments_block,
		"error report comment",
		MAXIMUM_COMMENTS_PER_ERROR_REPORT,
		"error_report_comment",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ERROR_REPORT_COMMENTS_BLOCK_ID)
	{
		{ _field_data, "text", FIELD_FLAG_READ_ONLY },
		{ _field_struct, "point", &error_report_point_definition },
		{ _field_real_argb_color, "color", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define ERROR_POINT_NODE_INDEX_ARRAY_ID { 0xB0BC81FE, 0xF4FF4938, 0xBA0BD7A5, 0xCE3EBDC0 }
	TAG_ARRAY(
		error_point_node_index_array,
		"error_point_node_index_array",
		MAXIMUM_NODE_INDICES_PER_ERROR_POINT,
		"char",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ERROR_POINT_NODE_INDEX_ARRAY_ID)
	{
		{ _field_char_integer, "node index", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define ERROR_POINT_NODE_WEIGHT_ARRAY_ID { 0xFA129333, 0xA37C4DC7, 0xB1050C1B, 0x12F05638 }
	TAG_ARRAY(
		error_point_node_weight_array,
		"error_point_node_weight_array",
		MAXIMUM_NODE_INDICES_PER_ERROR_POINT,
		"real",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ERROR_POINT_NODE_WEIGHT_ARRAY_ID)
	{
		{ _field_real, "node weight", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define ERROR_REPORT_LINE_POINT_ARRAY_ID { 0x0F4729E0, 0x338142C9, 0xBB1ABDAE, 0x4888C89A }
	TAG_ARRAY(
		error_report_line_point_array,
		"error_report_line_point_array",
		k_vertices_per_line_count,
		"error_report_point",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ERROR_REPORT_LINE_POINT_ARRAY_ID)
	{
		{ _field_struct, "point", &error_report_point_definition },
		{ _field_terminator }
	};

	#define ERROR_REPORT_TRIANGLE_POINT_ARRAY_ID { 0xD7176398, 0xDDD84F94, 0x8AFE9068, 0x59AEA189 }
	TAG_ARRAY(
		error_report_triangle_point_array,
		"error_report_triangle_point_array",
		k_vertices_per_triangle_count,
		"error_report_point",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ERROR_REPORT_TRIANGLE_POINT_ARRAY_ID)
	{
		{ _field_struct, "point", &error_report_point_definition },
		{ _field_terminator }
	};

	#define ERROR_REPORT_QUAD_POINT_ARRAY_ID { 0x81027CE9, 0x0A0E42FD, 0xAE95FE26, 0x6EB082A3 }
	TAG_ARRAY(
		error_report_quad_point_array,
		"error_report_quad_point_array",
		k_vertices_per_quadrilateral_count,
		"error_report_point",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ERROR_REPORT_QUAD_POINT_ARRAY_ID)
	{
		{ _field_struct, "point", &error_report_point_definition },
		{ _field_terminator }
	};

	#define ERROR_REPORT_POINT_DEFINITION_ID { 0xB6C2368C, 0x78534A62, 0x9882F40C, 0xE2181EF5 }
	TAG_STRUCT(
		error_report_point_definition,
		"error_report_point_definition",
		"error_report_point",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ERROR_REPORT_POINT_DEFINITION_ID)
	{
		{ _field_real_point_3d, "position", FIELD_FLAG_READ_ONLY },
		{ _field_array, "node indices", FIELD_FLAG_READ_ONLY, &error_point_node_index_array },
		{ _field_array, "node weights", FIELD_FLAG_READ_ONLY, &error_point_node_weight_array },
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

