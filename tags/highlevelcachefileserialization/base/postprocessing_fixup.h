#pragma once

class c_tag_instance;

using t_postprocessing_fixup_function = BCS_RESULT(*)(s_cache_cluster_transplant_context& context, c_tag_instance& source_tag_instance, h_tag_instance& target_tag_instance);

class c_postprocessing_fixup
{
public:
	c_postprocessing_fixup(bool multi_thread, t_postprocessing_fixup_function function);
	c_postprocessing_fixup(c_postprocessing_fixup const&) = delete;

	bool multi_thread;
	t_postprocessing_fixup_function function;
};
