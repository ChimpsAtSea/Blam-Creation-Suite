#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	#define DECORATOR_SET_STRUCT_DEFINITION_ID { 0xAF008F9B, 0x6F9E4D28, 0xAD976280, 0x056A47AD }
	TAG_BLOCK(
		decorator_set_block,
		"decorator_set_block",
		MAXIMUM_DECORATOR_SETS_PER_SCENARIO,
		"s_decorator_set",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | 
		SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		DECORATOR_SET_STRUCT_DEFINITION_ID)
	{
		FIELD_CUSTOM_EX("link to render model", nullptr, FIELD_FLAG_NONE, _field_id_unknown_compile),
		FIELD_EXPLANATION_EX("Render models", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_tag_reference, "Base", MAKE_OLD_NAMES("render model"), FIELD_FLAG_READ_ONLY, &render_model_reference },
		{ _field_tag_reference, "Lod2", MAKE_OLD_NAMES("render model_lod1"), FIELD_FLAG_READ_ONLY, &render_model_reference },
		{ _field_tag_reference, "Lod3", MAKE_OLD_NAMES("render model_lod2"), FIELD_FLAG_READ_ONLY, &render_model_reference },
		{ _field_tag_reference, "Lod4", MAKE_OLD_NAMES("render model_lod3"), FIELD_FLAG_READ_ONLY, &render_model_reference },
		{ _field_block, "render model instance names", FIELD_FLAG_UNKNOWN0, &decorator_set_instance_name_block },
		{ _field_long_integer, "render model instance name valid count", FIELD_FLAG_UNKNOWN0 },
		{ _field_tag_reference, "texture", &bitmap_reference$6 },
		FIELD_EXPLANATION_EX("RENDERING", nullptr, FIELD_FLAG_NONE, "\n"),
		{ _field_byte_flags, "render flags", &decorator_set_render_flags_definition },
		{ _field_char_enum, "render shader", &decorator_set_render_shader_enum_definition },
		{ _field_char_enum, "light sampling pattern", &decorator_set_lighting_sample_pattern_enum_definition },
		{ _field_byte_integer, "version", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "translucency A", "postprocessed value", "dont touch", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "translucency B", "postprocessed value", "dont touch", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "translucency C", "postprocessed value", "dont touch", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "translucency", "how translucent the material is (0 = opaque, 1 = both sides same intensity), only affects dynamic lights", nullptr, "[0..1]" },
		{ _field_real, "wavelength X", "direction and speed of wave through the world", "world units" },
		{ _field_real, "wavelength Y", "direction and speed of wave through the world", "world units" },
		{ _field_real, "wave speed", "waves per second through a point", "per second" },
		{ _field_real, "wave frequency", "number of waves per world unit", "per world unit" },
		{ _field_real, "shaded dark", "how dark is the dark side of a shaded decorator" },
		{ _field_real, "shaded bright", "the bright side of a shaded decorator is this much brighter than the dark side" },
		{ _field_real, "unused1", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "unused2", FIELD_FLAG_UNKNOWN0 },
		FIELD_EXPLANATION_EX("LOD FADE + CULL", nullptr, FIELD_FLAG_NONE, "\n"),
		{ _field_real, "early cull", "cull vertices this percentage sooner than LOD3-nothing transition", nullptr, "[0 - 1]" },
		{ _field_real, "cull block size", "decorators are grouped into blocks to be culled in large batches, this determines how much ground each batch covers.  Should be small if you expect to have very dense decorators, and large if you expect them to be sparse", nullptr, "[0.5-100]world units" },
		{ _field_real, "decimation speed", "1 is default", nullptr, "[0 - infinite]", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "decimation start distance", "[block size by default] decimation offset of the starting point", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "decimate to", "0 means all the way removed. 100 means nothing", MAKE_OLD_NAMES("max decimation percentage"), FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "decimation start", nullptr, "world units" },
		{ _field_real, "decimation end", nullptr, "world units" },
		{ _field_long_integer, "max valid lod", FIELD_FLAG_UNKNOWN0 },
		FIELD_EXPLANATION_EX("Lod transitions", nullptr, FIELD_FLAG_NONE, ""),
		FIELD_EXPLANATION_EX("Base to LOD2", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "start point0", MAKE_OLD_NAMES("Base to LOD1 cross fading start point") },
		{ _field_real, "end point0", MAKE_OLD_NAMES("Base to LOD1 cross fading end point") },
		{ _field_real, "scale0", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "offset0", FIELD_FLAG_UNKNOWN0 },
		FIELD_EXPLANATION_EX("LOD2 to LOD3", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "start point1", MAKE_OLD_NAMES("LOD1 to LOD2 cross fading start point") },
		{ _field_real, "end point1", MAKE_OLD_NAMES("LOD1 to LOD2 cross fading end point") },
		{ _field_real, "scale1", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "offset1", FIELD_FLAG_UNKNOWN0 },
		FIELD_EXPLANATION_EX("LOD3 to LOD4", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "start point2", MAKE_OLD_NAMES("LOD2 to LOD3 cross fading start point") },
		{ _field_real, "end point2", MAKE_OLD_NAMES("LOD2 to LOD3 cross fading end point") },
		{ _field_real, "scale2", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "offset2", FIELD_FLAG_UNKNOWN0 },
		FIELD_EXPLANATION_EX("LOD4 to nothing", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "start point3", MAKE_OLD_NAMES("LOD3 to nothing cross fading start point") },
		{ _field_real, "end point3", MAKE_OLD_NAMES("LOD3 to nothing cross fading end point") },
		{ _field_real, "scale3", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "offset3", FIELD_FLAG_UNKNOWN0 },
		FIELD_EXPLANATION_EX("DECORATOR TYPES", nullptr, FIELD_FLAG_NONE, "These describe the randomized settings for your decorator meshes.\n\nTHIS ONLY AFFECTS DECORATORS WHEN YOU PLACE THEM DOWN INITIALLY\nChanging these settings will not affect already placed decorators unless you use the \'reapply-type-settings\' brush\n\nWARNING: Re-arranging the order of these types after placing decorators\nin your level will cause the placed decorators to change types.\n\nDO NOT DELETE!  DO NOT INSERT!  OR YOUR PLACED DECORATORS WILL BE CHANGED!\n"),
		{ _field_block, "decorator types", &global_decorator_type_block },
		{ _field_terminator }
	};

	TAG_GROUP(
		decorator_set_group,
		DECORATOR_SET_TAG,
		nullptr,
		INVALID_TAG,
		decorator_set_block );

	#define DECORATOR_SET_INSTANCE_NAME_BLOCK_ID { 0xBA17DA19, 0x1009419A, 0x875C1352, 0xFE1C4B67 }
	TAG_BLOCK(
		decorator_set_instance_name_block,
		"decorator_set_instance_name_block",
		SHORT_MAX,
		"string_id",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DECORATOR_SET_INSTANCE_NAME_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		global_decorator_type_block,
		"global_decorator_type_block",
		BYTE_MAX-1,
		global_decorator_type_struct);

	#define DECORATOR_RUNTIME_CLUSTER_BLOCK_ID { 0xE2543A30, 0xA9E742B9, 0x8F489AF7, 0xC283783F }
	TAG_BLOCK(
		decorator_runtime_cluster_block,
		"decorator_runtime_cluster_block",
		MAXIMUM_BLOCKS_PER_CLUSTER,
		"s_decorator_runtime_block",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DECORATOR_RUNTIME_CLUSTER_BLOCK_ID)
	{
		{ _field_word_integer, "decorator placement count", FIELD_FLAG_READ_ONLY },
		{ _field_byte_integer, "decorator set index", FIELD_FLAG_READ_ONLY },
		{ _field_byte_integer, "decorator instance buffer index", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "decorator instance buffer offset", FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "position bounds min", FIELD_FLAG_READ_ONLY },
		{ _field_real, "bounding sphere radius", FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "position bounds size", FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "bounding sphere center", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define GLOBAL_DECORATOR_TYPE_STRUCT_ID { 0x02B61C35, 0x457E4970, 0xBB11A050, 0x2DF8A18E }
	TAG_STRUCT_V6(
		global_decorator_type_struct,
		"global_decorator_type_struct",
		"s_decorator_type",
		SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_DECORATOR_TYPE_STRUCT_ID)
	{
		{ _field_long_integer, "index", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_block_index, "mesh", FIELD_FLAG_INDEX, &decorator_set_instance_name_block },
		{ _field_long_flags, "flags", &decorator_type_flags_definition },
		{ _field_real, "scale min", nullptr, nullptr, "[0.0 - 5.0]" },
		{ _field_real, "scale max", nullptr, nullptr, "[0.0 - 5.0]" },
		{ _field_real, "tilt min", nullptr, "degrees" },
		{ _field_real, "tilt max", nullptr, "degrees" },
		{ _field_real, "wind min", nullptr, nullptr, "[0.0 - 1.0]" },
		{ _field_real, "wind max", nullptr, nullptr, "[0.0 - 1.0]" },
		{ _field_real_rgb_color, "color 0" },
		{ _field_real_rgb_color, "color 1" },
		{ _field_real_rgb_color, "color 2" },
		{ _field_real, "ground tint min", nullptr, nullptr, "[0.0 - 1.0]" },
		{ _field_real, "ground tint max", nullptr, nullptr, "[0.0 - 1.0]" },
		{ _field_real, "hover min", nullptr, nullptr, "[-1.0 - 1.0]" },
		{ _field_real, "hover max", nullptr, nullptr, "[-1.0 - 1.0]" },
		{ _field_real, "minimum distance between decorators", nullptr, "world units" },
		{ _field_real, "placement weight", nullptr, nullptr, "[0.0 - 1.0]" },
		{ _field_real, "postprocessed weight", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	STRINGS(decorator_type_flags_definition)
	{
		"only on ground",
		"random rotation",
		"rotate x axis down",
		"align to normal",
		"align random"
	};
	STRING_LIST(decorator_type_flags_definition, decorator_type_flags_definition_strings, _countof(decorator_type_flags_definition_strings));

	STRINGS(decorator_set_render_flags_definition)
	{
		"render two sided",
		"dont sample light through geometry#takes twice as long to light",
		"Use decimation method for random structured decorators",
		"more strictly respect block size#or there could only be 10x10 blocks per cluster",
		"do not desaturate#only matters if the do not desaturate decorators checkbox is unchecked in the structure bsps block of the .scenario tag"
	};
	STRING_LIST(decorator_set_render_flags_definition, decorator_set_render_flags_definition_strings, _countof(decorator_set_render_flags_definition_strings));

	STRINGS(decorator_set_render_shader_enum_definition)
	{
		"billboard + wind + dynamic lights{wind + dynamic lights}",
		"billboard + dynamic lights{still + dynamic lights}",
		"solid mesh + dynamic lights{still + no lights}",
		"solid mesh{still + sun light only}",
		"underwater + dynamic lights{wavy + dynamic lights}",
		"volumetric billboard + dynamic lights{shaded + dynamic lights}",
		"volumetric billboard + wind + dynamic lights"
	};
	STRING_LIST(decorator_set_render_shader_enum_definition, decorator_set_render_shader_enum_definition_strings, _countof(decorator_set_render_shader_enum_definition_strings));

	STRINGS(decorator_set_lighting_sample_pattern_enum_definition)
	{
		"ground default",
		"hanging"
	};
	STRING_LIST(decorator_set_lighting_sample_pattern_enum_definition, decorator_set_lighting_sample_pattern_enum_definition_strings, _countof(decorator_set_lighting_sample_pattern_enum_definition_strings));

	TAG_REFERENCE(global_decorator_set_reference, DECORATOR_SET_TAG);



} // namespace blofeld

