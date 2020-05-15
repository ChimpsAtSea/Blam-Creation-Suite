#pragma once

namespace blofeld
{

extern s_tag_block short_block;
extern s_tag_block render_method_parameter_block;
extern s_tag_block render_method_animated_parameter_block;
extern s_tag_block render_method_postprocess_block;
extern s_tag_block render_method_postprocess_texture_block;
extern s_tag_block real_vector4d$2_block;
extern s_tag_block int$2_block;
extern s_tag_block tag_block_index_block;
extern s_tag_block render_method_postprocess_pass_block;
extern s_tag_block render_method_routing_info_block;
extern s_tag_block render_method_locked_parameter_block;
extern s_tag_block render_method_category_block;
extern s_tag_block render_method_options_block;
extern s_tag_block render_method_entry_points_block;
extern s_tag_block render_method_pass_block;
extern s_tag_block render_method_pass_category_dependencies_block;
extern s_tag_block vertex_types_block;
extern s_tag_block render_method_option_parameter_block;
extern s_tag_block render_method_template_pass_block;
extern s_tag_block render_method_template_constant_table_block;
extern s_tag_block render_method_template_platform_block;

constexpr unsigned long RENDER_METHOD_TAG = 'rm  ';

extern s_tag_block render_method_block;
extern s_tag_group render_method_group;
constexpr unsigned long RENDER_METHOD_DEFINITION_TAG = 'rmdf';

extern s_tag_block render_method_definition_block;
extern s_tag_group render_method_definition_group;
constexpr unsigned long RENDER_METHOD_OPTION_TAG = 'rmop';

extern s_tag_block render_method_option_block;
extern s_tag_group render_method_option_group;
constexpr unsigned long RENDER_METHOD_TEMPLATE_TAG = 'rmt2';

extern s_tag_block render_method_template_block;
extern s_tag_group render_method_template_group;
} // namespace blofeld

