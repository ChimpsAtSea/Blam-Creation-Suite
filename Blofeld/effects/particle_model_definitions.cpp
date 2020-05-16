#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(particle_model_struct_definition)
{
	FIELD( _field_custom, "Import model" ),
	FIELD( _field_explanation, "WHY IS THIS TAG EMPTY\?" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "render geometry*!", &global_render_geometry_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "m_gpu_data!", &gpu_data_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(gpu_data_struct)
{
	FIELD( _field_block, "m_variants!", &gpu_variants_block ),
	FIELD( _field_terminator )
};

TAG_GROUP(particle_model_block, PARTICLE_MODEL_TAG)
{
	FIELD( _field_custom, "Import model" ),
	FIELD( _field_explanation, "WHY IS THIS TAG EMPTY\?" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "render geometry*!", &global_render_geometry_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "m_gpu_data!", &gpu_data_struct_struct_definition ),
	FIELD( _field_terminator )
};

} // namespace blofeld

