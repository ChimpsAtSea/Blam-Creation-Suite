#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		particle_model_group,
		PARTICLE_MODEL_TAG,
		nullptr,
		INVALID_TAG,
		particle_model_block );

	TAG_BLOCK_FROM_STRUCT(
		particle_model_block,
		"particle_model_block",
		1,
		particle_model_struct_definition);

	#define PARTICLE_MODEL_STRUCT_DEFINITION_ID { 0xC4C7FDE0, 0xADA64FF1, 0x9CDCC3BE, 0xF1D59F65 }
	TAG_STRUCT_V6(
		particle_model_struct_definition,
		"particle_model_struct_definition",
		"c_particle_model_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_RESOURCES | 
		SET_UNKNOWN14 | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PARTICLE_MODEL_STRUCT_DEFINITION_ID)
	{
		FIELD_CUSTOM_EX("Import model", nullptr, FIELD_FLAG_NONE, _field_id_import_model),
		FIELD_EXPLANATION_EX("WHY IS THIS TAG EMPTY?", nullptr, FIELD_FLAG_NONE, "This tag is only a shell for containing imported particle geometry data.\nEven an empty geometry structure is pretty large, so I didn\'t want to put it in the parent particle tag.\n"),
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_hide_begin),
		{ _field_struct, "render geometry", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &global_render_geometry_struct },
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_hide_end),
		{ _field_struct, "m_gpu_data", FIELD_FLAG_UNKNOWN0, &gpu_data_struct },
		{ _field_terminator }
	};

	#define GPU_DATA_STRUCT_ID { 0xF0F224FF, 0x7CD04586, 0x9698B35C, 0x7E98B715 }
	TAG_STRUCT_V6(
		gpu_data_struct,
		"gpu_data_struct",
		"c_particle_model_definition::s_gpu_data",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GPU_DATA_STRUCT_ID)
	{
		{ _field_block, "m_variants", FIELD_FLAG_UNKNOWN0, &gpu_variants_block },
		{ _field_terminator }
	};



} // namespace blofeld

