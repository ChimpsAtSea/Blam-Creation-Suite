#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(global_error_report_categories, MAXIMUM_ERROR_REPORT_CATEGORIES)
{
	{ _field_long_string, "name^*" },
	{ _field_enum, "report type*" },
	{ _field_word_flags, "flags*" },
	{ _field_short_integer, "runtime generation flags!" },
	{ _field_pad, "WVTP", 2 },
	{ _field_long_integer, "runtime something~!" },
	{ _field_block, "reports*", &error_reports_block },
	{ _field_terminator },
};

TAG_BLOCK(error_reports, MAXIMUM_REPORTS_PER_ERROR_REPORT_CATEGORY)
{
	{ _field_char_enum, "type*" },
	{ _field_char_enum, "source*" },
	{ _field_word_flags, "flags*" },
	{ _field_data, "text*" },
	{ _field_long_integer, "source identifier*" },
	{ _field_string, "source filename*" },
	{ _field_long_integer, "source line number*" },
	{ _field_block, "vertices*", &error_report_vertices_block },
	{ _field_block, "vectors*", &error_report_vectors_block },
	{ _field_block, "lines*", &error_report_lines_block },
	{ _field_block, "triangles*", &error_report_triangles_block },
	{ _field_block, "quads*", &error_report_quads_block },
	{ _field_block, "comments*", &error_report_comments_block },
	{ _field_long_integer, "report key*" },
	{ _field_long_integer, "node index*" },
	{ _field_real_bounds, "bounds x*" },
	{ _field_real_bounds, "bounds y*" },
	{ _field_real_bounds, "bounds z*" },
	{ _field_real_argb_color, "color*" },
	{ _field_terminator },
};

TAG_BLOCK(error_report_vertices, MAXIMUM_VERTICES_PER_ERROR_REPORT)
{
	{ _field_struct, "point" },
	{ _field_real_argb_color, "color*" },
	{ _field_real, "screen size*" },
	{ _field_terminator },
};

TAG_BLOCK(error_report_vectors, MAXIMUM_VECTORS_PER_ERROR_REPORT)
{
	{ _field_struct, "point" },
	{ _field_real_argb_color, "color*" },
	{ _field_real_vector_3d, "normal*" },
	{ _field_real, "screen length*" },
	{ _field_terminator },
};

TAG_BLOCK(error_report_lines, MAXIMUM_LINES_PER_ERROR_REPORT)
{
	{ _field_array, "points*" },
	{ _field_real_argb_color, "color*" },
	{ _field_terminator },
};

TAG_BLOCK(error_report_triangles, MAXIMUM_TRIANGLES_PER_ERROR_REPORT)
{
	{ _field_array, "points*" },
	{ _field_real_argb_color, "color*" },
	{ _field_terminator },
};

TAG_BLOCK(error_report_quads, MAXIMUM_QUADS_PER_ERROR_REPORT)
{
	{ _field_array, "points*" },
	{ _field_real_argb_color, "color*" },
	{ _field_terminator },
};

TAG_BLOCK(error_report_comments, MAXIMUM_COMMENTS_PER_ERROR_REPORT)
{
	{ _field_data, "text*" },
	{ _field_struct, "point" },
	{ _field_real_argb_color, "color*" },
	{ _field_terminator },
};

} // namespace blofeld

