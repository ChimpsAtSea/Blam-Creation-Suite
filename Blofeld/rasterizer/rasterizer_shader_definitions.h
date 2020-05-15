#pragma once

namespace blofeld
{

extern s_tag_block global_shader_entry_point_block;
extern s_tag_block global_shader_category_dependency_block;
extern s_tag_block global_shader_option_dependency_block;
extern s_tag_block compiled_pixel_shader_block;
extern s_tag_block global_vertex_shader_vertex_types_block;
extern s_tag_block compiled_vertex_shader_block;
extern s_tag_block pixel_entry_point_block;
extern s_tag_block vertex_entry_point_block;
extern s_tag_block vertex_types$2_block;

constexpr unsigned long GLOBAL_PIXEL_SHADER_TAG = 'glps';

extern s_tag_block global_pixel_shader_block;
extern s_tag_group global_pixel_shader_group;
constexpr unsigned long GLOBAL_VERTEX_SHADER_TAG = 'glvs';

extern s_tag_block global_vertex_shader_block;
extern s_tag_group global_vertex_shader_group;
constexpr unsigned long GLOBAL_CACHE_FILE_PIXEL_SHADERS_TAG = 'gpix';

extern s_tag_block global_cache_file_pixel_shaders_block;
extern s_tag_group global_cache_file_pixel_shaders_group;
constexpr unsigned long HLSL_INCLUDE_TAG = 'hlsl';

extern s_tag_block hlsl_include_block;
extern s_tag_group hlsl_include_group;
constexpr unsigned long PIXEL_SHADER_TAG = 'pixl';

extern s_tag_block pixel_shader_block;
extern s_tag_group pixel_shader_group;
constexpr unsigned long VERTEX_SHADER_TAG = 'vtsh';

extern s_tag_block vertex_shader_block;
extern s_tag_group vertex_shader_group;
} // namespace blofeld

