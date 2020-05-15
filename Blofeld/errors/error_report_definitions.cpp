#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(global_error_report_categories, MAXIMUM_ERROR_REPORT_CATEGORIES)
{
	FIELD( _field_long_string, "name^*" ),
	FIELD( _field_enum, "report type*" ),
	FIELD( _field_word_flags, "flags*" ),
	FIELD( _field_short_integer, "runtime generation flags!" ),
	FIELD( _field_pad, "WVTP", 2 ),
	FIELD( _field_long_integer, "runtime something~!" ),
	FIELD( _field_block, "reports*", &error_reports_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(error_reports, MAXIMUM_REPORTS_PER_ERROR_REPORT_CATEGORY)
{
	FIELD( _field_char_enum, "type*" ),
	FIELD( _field_char_enum, "source*" ),
	FIELD( _field_word_flags, "flags*" ),
	FIELD( _field_data, "text*" ),
	FIELD( _field_long_integer, "source identifier*" ),
	FIELD( _field_string, "source filename*" ),
	FIELD( _field_long_integer, "source line number*" ),
	FIELD( _field_block, "vertices*", &error_report_vertices_block ),
	FIELD( _field_block, "vectors*", &error_report_vectors_block ),
	FIELD( _field_block, "lines*", &error_report_lines_block ),
	FIELD( _field_block, "triangles*", &error_report_triangles_block ),
	FIELD( _field_block, "quads*", &error_report_quads_block ),
	FIELD( _field_block, "comments*", &error_report_comments_block ),
	FIELD( _field_long_integer, "report key*" ),
	FIELD( _field_long_integer, "node index*" ),
	FIELD( _field_real_bounds, "bounds x*" ),
	FIELD( _field_real_bounds, "bounds y*" ),
	FIELD( _field_real_bounds, "bounds z*" ),
	FIELD( _field_real_argb_color, "color*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(error_report_vertices, MAXIMUM_VERTICES_PER_ERROR_REPORT)
{
	FIELD( _field_struct, "point" ),
	FIELD( _field_real_argb_color, "color*" ),
	FIELD( _field_real, "screen size*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(error_report_vectors, MAXIMUM_VECTORS_PER_ERROR_REPORT)
{
	FIELD( _field_struct, "point" ),
	FIELD( _field_real_argb_color, "color*" ),
	FIELD( _field_real_vector_3d, "normal*" ),
	FIELD( _field_real, "screen length*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(error_report_lines, MAXIMUM_LINES_PER_ERROR_REPORT)
{
	FIELD( _field_array, "points*" ),
	FIELD( _field_real_argb_color, "color*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(error_report_triangles, MAXIMUM_TRIANGLES_PER_ERROR_REPORT)
{
	FIELD( _field_array, "points*" ),
	FIELD( _field_real_argb_color, "color*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(error_report_quads, MAXIMUM_QUADS_PER_ERROR_REPORT)
{
	FIELD( _field_array, "points*" ),
	FIELD( _field_real_argb_color, "color*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(error_report_comments, MAXIMUM_COMMENTS_PER_ERROR_REPORT)
{
	FIELD( _field_data, "text*" ),
	FIELD( _field_struct, "point" ),
	FIELD( _field_real_argb_color, "color*" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

