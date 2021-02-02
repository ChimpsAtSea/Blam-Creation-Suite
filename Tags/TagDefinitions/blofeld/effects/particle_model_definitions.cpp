#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(particle_model, PARTICLE_MODEL_TAG, particle_model_block_block );

	V5_TAG_BLOCK_FROM_STRUCT(particle_model_block, 1, particle_model_struct_definition_struct_definition );

	V5_TAG_STRUCT(particle_model_struct_definition)
	{
		{ _field_legacy, _field_custom, "Import model" },
		{ _field_legacy, _field_explanation, "WHY IS THIS TAG EMPTY\?", "This tag is only a shell for containing imported particle geometry data.\nEven an empty geometry structure is pretty large, so I didn\'t want to put it in the parent particle tag.\n" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_struct, "render geometry*!", &global_render_geometry_struct_struct_definition },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_struct, "m_gpu_data!", &gpu_data_struct_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(gpu_data_struct)
	{
		{ _field_legacy, _field_block, "m_variants!", &gpu_variants_block_block },
		{ _field_legacy, _field_terminator }
	};

} // namespace blofeld

