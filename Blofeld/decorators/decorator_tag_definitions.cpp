#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP(decorator_set, DECORATOR_SET_TAG)
	{
		FIELD( _field_custom, "link to render model" ),
		FIELD( _field_explanation, "Render models:" ),
		FIELD( _field_tag_reference, "Base{render model}*" ),
		FIELD( _field_tag_reference, "Lod2{render model_lod1}*" ),
		FIELD( _field_tag_reference, "Lod3{render model_lod2}*" ),
		FIELD( _field_tag_reference, "Lod4{render model_lod3}*" ),
		FIELD( _field_block, "render model instance names!", &decorator_set_instance_name_block_block ),
		FIELD( _field_long_integer, "render model instance name valid count!" ),
		FIELD( _field_tag_reference, "texture" ),
		FIELD( _field_explanation, "RENDERING" ),
		FIELD( _field_byte_flags, "render flags", &decorator_set_render_flags_definition ),
		FIELD( _field_char_enum, "render shader", &decorator_set_render_shader_enum_definition ),
		FIELD( _field_char_enum, "light sampling pattern", &decorator_set_lighting_sample_pattern_enum_definition ),
		FIELD( _field_byte_integer, "version!" ),
		FIELD( _field_real, "translucency A!:dont touch#postprocessed value" ),
		FIELD( _field_real, "translucency B!:dont touch#postprocessed value" ),
		FIELD( _field_real, "translucency C!:dont touch#postprocessed value" ),
		FIELD( _field_real, "translucency:[0..1]#how translucent the material is (0 = opaque, 1 = both sides same intensity), only affects dynamic lights" ),
		FIELD( _field_real, "wavelength X:world units#direction and speed of wave through the world" ),
		FIELD( _field_real, "wavelength Y:world units#direction and speed of wave through the world" ),
		FIELD( _field_real, "wave speed:per second#waves per second through a point" ),
		FIELD( _field_real, "wave frequency:per world unit#number of waves per world unit" ),
		FIELD( _field_real, "shaded dark:#how dark is the dark side of a shaded decorator" ),
		FIELD( _field_real, "shaded bright:#the bright side of a shaded decorator is this much brighter than the dark side" ),
		FIELD( _field_real, "unused1!" ),
		FIELD( _field_real, "unused2!" ),
		FIELD( _field_explanation, "LOD FADE + CULL" ),
		FIELD( _field_real, "early cull:[0 - 1]#cull vertices this percentage sooner than LOD3-nothing transition" ),
		FIELD( _field_real, "cull block size:[0.5-100]world units#decorators are grouped into blocks to be culled in large batches, this determines how much ground each batch covers.  Should be small if you expect to have very dense decorators, and large if you expect them to be sparse" ),
		FIELD( _field_real, "decimation speed!:[0 - infinite]#1 is default" ),
		FIELD( _field_real, "decimation start distance!#[block size by default] decimation offset of the starting point" ),
		FIELD( _field_real, "decimate to!{max decimation percentage}#0 means all the way removed. 100 means nothing" ),
		FIELD( _field_real, "decimation start:world units" ),
		FIELD( _field_real, "decimation end:world units" ),
		FIELD( _field_long_integer, "max valid lod!" ),
		FIELD( _field_explanation, "Lod transitions:" ),
		FIELD( _field_explanation, "Base to LOD2:" ),
		FIELD( _field_real, "start point0{Base to LOD1 cross fading start point}" ),
		FIELD( _field_real, "end point0{Base to LOD1 cross fading end point}" ),
		FIELD( _field_real, "scale0!" ),
		FIELD( _field_real, "offset0!" ),
		FIELD( _field_explanation, "LOD2 to LOD3:" ),
		FIELD( _field_real, "start point1{LOD1 to LOD2 cross fading start point}" ),
		FIELD( _field_real, "end point1{LOD1 to LOD2 cross fading end point}" ),
		FIELD( _field_real, "scale1!" ),
		FIELD( _field_real, "offset1!" ),
		FIELD( _field_explanation, "LOD3 to LOD4:" ),
		FIELD( _field_real, "start point2{LOD2 to LOD3 cross fading start point}" ),
		FIELD( _field_real, "end point2{LOD2 to LOD3 cross fading end point}" ),
		FIELD( _field_real, "scale2!" ),
		FIELD( _field_real, "offset2!" ),
		FIELD( _field_explanation, "LOD4 to nothing:" ),
		FIELD( _field_real, "start point3{LOD3 to nothing cross fading start point}" ),
		FIELD( _field_real, "end point3{LOD3 to nothing cross fading end point}" ),
		FIELD( _field_real, "scale3!" ),
		FIELD( _field_real, "offset3!" ),
		FIELD( _field_explanation, "DECORATOR TYPES" ),
		FIELD( _field_block, "decorator types", &global_decorator_type_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(decorator_set_instance_name_block, SHORT_MAX)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(global_decorator_type_block, BYTE_MAX-1, global_decorator_type_struct_struct_definition );

	TAG_BLOCK(decorator_runtime_cluster_block, MAXIMUM_BLOCKS_PER_CLUSTER)
	{
		FIELD( _field_word_integer, "decorator placement count*" ),
		FIELD( _field_byte_integer, "decorator set index*" ),
		FIELD( _field_byte_integer, "decorator instance buffer index*" ),
		FIELD( _field_long_integer, "decorator instance buffer offset*" ),
		FIELD( _field_real_vector_3d, "position bounds min*" ),
		FIELD( _field_real, "bounding sphere radius*" ),
		FIELD( _field_real_vector_3d, "position bounds size*" ),
		FIELD( _field_real_vector_3d, "bounding sphere center*" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(global_decorator_type_struct)
	{
		FIELD( _field_long_integer, "index!" ),
		FIELD( _field_long_block_index, "mesh^" ),
		FIELD( _field_long_flags, "flags", &decorator_type_flags_definition ),
		FIELD( _field_real, "scale min:[0.0 - 5.0]" ),
		FIELD( _field_real, "scale max:[0.0 - 5.0]" ),
		FIELD( _field_real, "tilt min:degrees" ),
		FIELD( _field_real, "tilt max:degrees" ),
		FIELD( _field_real, "wind min:[0.0 - 1.0]" ),
		FIELD( _field_real, "wind max:[0.0 - 1.0]" ),
		FIELD( _field_real_rgb_color, "color 0" ),
		FIELD( _field_real_rgb_color, "color 1" ),
		FIELD( _field_real_rgb_color, "color 2" ),
		FIELD( _field_real, "ground tint min:[0.0 - 1.0]" ),
		FIELD( _field_real, "ground tint max:[0.0 - 1.0]" ),
		FIELD( _field_real, "hover min:[-1.0 - 1.0]" ),
		FIELD( _field_real, "hover max:[-1.0 - 1.0]" ),
		FIELD( _field_real, "minimum distance between decorators:world units" ),
		FIELD( _field_real, "placement weight:[0.0 - 1.0]" ),
		FIELD( _field_real, "postprocessed weight!" ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(decorator_type_flags_definition, 5)
	{
		OPTION("only on ground"),
		OPTION("random rotation"),
		OPTION("rotate x axis down"),
		OPTION("align to normal"),
		OPTION("align random"),
	};

	TAG_ENUM(decorator_set_render_flags_definition, 5)
	{
		OPTION("render two sided"),
		OPTION("dont sample light through geometry#takes twice as long to light"),
		OPTION("Use decimation method for random structured decorators"),
		OPTION("more strictly respect block size#or there could only be 10x10 blocks per cluster"),
		OPTION("do not desaturate#only matters if the do not desaturate decorators checkbox is unchecked in the structure bsps block of the .scenario tag"),
	};

	TAG_ENUM(decorator_set_render_shader_enum_definition, 7)
	{
		OPTION("billboard + wind + dynamic lights{wind + dynamic lights}"),
		OPTION("billboard + dynamic lights{still + dynamic lights}"),
		OPTION("solid mesh + dynamic lights{still + no lights}"),
		OPTION("solid mesh{still + sun light only}"),
		OPTION("underwater + dynamic lights{wavy + dynamic lights}"),
		OPTION("volumetric billboard + dynamic lights{shaded + dynamic lights}"),
		OPTION("volumetric billboard + wind + dynamic lights"),
	};

	TAG_ENUM(decorator_set_lighting_sample_pattern_enum_definition, 2)
	{
		OPTION("ground default"),
		OPTION("hanging"),
	};

} // namespace blofeld

