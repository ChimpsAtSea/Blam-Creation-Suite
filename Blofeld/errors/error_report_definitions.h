#pragma once

namespace blofeld
{

	extern const char* error_report_types_strings[];
	extern s_string_list_definition error_report_types;
	extern const char* error_report_source_strings[];
	extern s_string_list_definition error_report_source;
	extern const char* error_report_flags_strings[];
	extern s_string_list_definition error_report_flags;


	extern s_tag_struct global_error_report_categories_block_block_struct;
	extern s_tag_block_definition global_error_report_categories_block_block;
	extern s_tag_struct error_reports_block_block_struct;
	extern s_tag_block_definition error_reports_block_block;
	extern s_tag_struct error_report_vertices_block_block_struct;
	extern s_tag_block_definition error_report_vertices_block_block;
	extern s_tag_struct error_report_vectors_block_block_struct;
	extern s_tag_block_definition error_report_vectors_block_block;
	extern s_tag_struct error_report_lines_block_block_struct;
	extern s_tag_block_definition error_report_lines_block_block;
	extern s_tag_struct error_report_triangles_block_block_struct;
	extern s_tag_block_definition error_report_triangles_block_block;
	extern s_tag_struct error_report_quads_block_block_struct;
	extern s_tag_block_definition error_report_quads_block_block;
	extern s_tag_struct error_report_comments_block_block_struct;
	extern s_tag_block_definition error_report_comments_block_block;

	extern s_tag_struct error_report_point_definition_struct_definition;

} // namespace blofeld

