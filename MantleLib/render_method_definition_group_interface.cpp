#include "mantlelib-private-pch.h"

c_render_method_definition_group_interface::c_render_method_definition_group_interface(c_cache_file& cache_file, uint16_t group_index) :
	c_tag_group_interface(cache_file, group_index)
{
	for (c_tag_interface* tag_interface : m_rCacheFile.GetTagInterfaces(true))
	{
		if (tag_interface->IsNull()) continue;

		s_cache_file_tag_group* const cache_file_tag_group = tag_interface->GetRawGroup();

		if (cache_file_tag_group->group_tags[1] == _tag_group_render_method)
		{
			s_shader_definition* shader_definition = tag_interface->GetData<s_shader_definition>();

			for (c_tag_interface* render_method_definition_tag_interface : m_tagInterfaces)
			{
				// #TODO: Replace with an interface to class that handles this comparison
				if (shader_definition->base_render_method_reference.index != render_method_definition_tag_interface->GetIndex()) continue; // skip until the rmdf matches


				std::vector<c_tag_interface*>& rmt2_tags = shader_definition_and_rmt2[render_method_definition_tag_interface];


				//#TODO: #IMPORTANT Create render method base class
				s_shader_definition* shader_definition = tag_interface->GetData<s_shader_definition>();
				for (uint32_t shader_properties_block_index = 0; shader_properties_block_index < shader_definition->shader_properties_block.count; shader_properties_block_index++)
				{
					s_shader_definition::s_shader_property_block_definition* shader_property = m_rCacheFile.GetTagBlockData(shader_definition->shader_properties_block) + shader_properties_block_index;

					c_tag_interface* render_method_template_tag_interface = m_rCacheFile.GetTagInterface(shader_property->template_reference.index, true);
					if (render_method_template_tag_interface)
					{
						rmt2_tags.push_back(render_method_template_tag_interface);
					}
				}
			}
		}
	}


	for (c_tag_interface* render_method_definition_tag_interface : m_tagInterfaces)
	{
		std::vector<c_tag_interface*>& rmt2_tags = shader_definition_and_rmt2[render_method_definition_tag_interface];

		std::vector<c_tag_interface*>::iterator rmt2_tags_last = std::unique(rmt2_tags.begin(), rmt2_tags.end());
		rmt2_tags.erase(rmt2_tags_last, rmt2_tags.end());
	}
}

c_render_method_definition_group_interface::~c_render_method_definition_group_interface()
{

}
