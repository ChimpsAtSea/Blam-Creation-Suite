#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(particle_model, PARTICLE_MODEL_TAG, particle_model_block_block );

	TAG_BLOCK_FROM_STRUCT(particle_model_block, 1, particle_model_struct_definition_struct_definition );

	TAG_STRUCT(particle_model_struct_definition)
	{
		{ _field_custom, "Import model" },
		{ _field_explanation, "WHY IS THIS TAG EMPTY\?" },
		{ _field_custom },
		{ _field_struct, "render geometry*!", &global_render_geometry_struct_struct_definition },
		{ _field_custom },
		{ _field_struct, "m_gpu_data!", &gpu_data_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(gpu_data_struct)
	{
		{ _field_block, "m_variants!", &gpu_variants_block_block },
		{ _field_terminator }
	};

} // namespace blofeld

