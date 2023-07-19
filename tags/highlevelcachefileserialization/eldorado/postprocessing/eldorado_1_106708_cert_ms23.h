#pragma once

namespace eldorado_1_106708_cert_ms23
{
	extern c_postprocessing_fixup* const postprocessing_fixups[];
	extern unsigned int const num_postprocessing_fixups;

	extern BCS_RESULT postprocessing_rename_tags(s_cache_cluster_transplant_context& context, c_tag_instance& source_tag_instance, h_tag_instance& target_tag_instance);
	extern BCS_RESULT postprocessing_scenario_structure_bsp(s_cache_cluster_transplant_context& context, c_tag_instance& source_tag_instance, h_tag_instance& target_tag_instance);
	extern BCS_RESULT postprocessing_scenario(s_cache_cluster_transplant_context& context, c_tag_instance& source_tag_instance, h_tag_instance& target_tag_instance);
	extern BCS_RESULT postprocessing_nuke_shader_references(s_cache_cluster_transplant_context& context, c_tag_instance& source_tag_instance, h_tag_instance& target_tag_instance);
	extern BCS_RESULT postprocessing_physics_model(s_cache_cluster_transplant_context& context, c_tag_instance& source_tag_instance, h_tag_instance& target_tag_instance);
	extern BCS_RESULT postprocessing_bitmaps(s_cache_cluster_transplant_context& context, c_tag_instance& source_tag_instance, h_tag_instance& target_tag_instance);
	extern BCS_RESULT postprocessing_decorator_sets(s_cache_cluster_transplant_context& context, c_tag_instance& source_tag_instance, h_tag_instance& target_tag_instance);
	extern BCS_RESULT postprocessing_global_render_geometry(s_cache_cluster_transplant_context& context, c_tag_instance& source_tag_instance, h_tag_instance& target_tag_instance);
	
}
