#pragma once

namespace blofeld
{

extern s_tag_block imposter_mode_node_block;
extern s_tag_block render_model_region_block;
extern s_tag_block render_model_permutation_block;
extern s_tag_block render_model_node_block;
extern s_tag_block render_model_marker_group_block;
extern s_tag_block render_model_marker_block;
extern s_tag_block instance_node_map_mapping_block;
extern s_tag_block volume_samples_block;
extern s_tag_block default_node_orientations_block;
extern s_tag_block RenderModelBoneGroupBlock_block;
extern s_tag_block RenderModelNodeIndexBlock_block;

constexpr unsigned long IMPOSTER_MODEL_TAG = 'impo';

extern s_tag_block imposter_model_block;
extern s_tag_group imposter_model_group;
constexpr unsigned long RENDER_MODEL_TAG = 'mode';

extern s_tag_block render_model_block;
extern s_tag_group render_model_group;
constexpr unsigned long RENDER_MODEL_LIGHTMAP_ATLAS_TAG = 'rmla';

extern s_tag_block render_model_lightmap_atlas_block;
extern s_tag_group render_model_lightmap_atlas_group;
} // namespace blofeld

