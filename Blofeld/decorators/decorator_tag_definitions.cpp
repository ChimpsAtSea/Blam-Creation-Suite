#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(decorator_set_instance_name, SHORT_MAX)
{
	{ _field_string_id, "name^" },
	{ _field_terminator },
};

TAG_BLOCK(global_decorator_type, BYTE_MAX-1)
{
	{ _field_long_integer, "index!" },
	{ _field_long_block_index, "mesh^" },
	{ _field_long_flags, "flags" },
	{ _field_real, "scale min:[0.0 - 5.0]" },
	{ _field_real, "scale max:[0.0 - 5.0]" },
	{ _field_real, "tilt min:degrees" },
	{ _field_real, "tilt max:degrees" },
	{ _field_real, "wind min:[0.0 - 1.0]" },
	{ _field_real, "wind max:[0.0 - 1.0]" },
	{ _field_real_rgb_color, "color 0" },
	{ _field_real_rgb_color, "color 1" },
	{ _field_real_rgb_color, "color 2" },
	{ _field_real, "ground tint min:[0.0 - 1.0]" },
	{ _field_real, "ground tint max:[0.0 - 1.0]" },
	{ _field_real, "hover min:[-1.0 - 1.0]" },
	{ _field_real, "hover max:[-1.0 - 1.0]" },
	{ _field_real, "minimum distance between decorators:world units" },
	{ _field_real, "placement weight:[0.0 - 1.0]" },
	{ _field_real, "postprocessed weight!" },
	{ _field_terminator },
};

TAG_BLOCK(decorator_runtime_cluster, MAXIMUM_BLOCKS_PER_CLUSTER)
{
	{ _field_word_integer, "decorator placement count*" },
	{ _field_byte_integer, "decorator set index*" },
	{ _field_byte_integer, "decorator instance buffer index*" },
	{ _field_long_integer, "decorator instance buffer offset*" },
	{ _field_real_vector_3d, "position bounds min*" },
	{ _field_real, "bounding sphere radius*" },
	{ _field_real_vector_3d, "position bounds size*" },
	{ _field_real_vector_3d, "bounding sphere center*" },
	{ _field_terminator },
};

TAG_GROUP(decorator_set, DECORATOR_SET_TAG)
{
	{ _field_custom, "link to render model" },
	{ _field_explanation, "Render models:" },
	{ _field_tag_reference, "Base{render model}*" },
	{ _field_tag_reference, "Lod2{render model_lod1}*" },
	{ _field_tag_reference, "Lod3{render model_lod2}*" },
	{ _field_tag_reference, "Lod4{render model_lod3}*" },
	{ _field_block, "render model instance names!", &decorator_set_instance_name_block },
	{ _field_long_integer, "render model instance name valid count!" },
	{ _field_tag_reference, "texture" },
	{ _field_explanation, "RENDERING" },
	{ _field_byte_flags, "render flags" },
	{ _field_char_enum, "render shader" },
	{ _field_char_enum, "light sampling pattern" },
	{ _field_byte_integer, "version!" },
	{ _field_real, "translucency A!:dont touch#postprocessed value" },
	{ _field_real, "translucency B!:dont touch#postprocessed value" },
	{ _field_real, "translucency C!:dont touch#postprocessed value" },
	{ _field_real, "translucency:[0..1]#how translucent the material is (0 = opaque, 1 = both sides same intensity), only affects dynamic lights" },
	{ _field_real, "wavelength X:world units#direction and speed of wave through the world" },
	{ _field_real, "wavelength Y:world units#direction and speed of wave through the world" },
	{ _field_real, "wave speed:per second#waves per second through a point" },
	{ _field_real, "wave frequency:per world unit#number of waves per world unit" },
	{ _field_real, "shaded dark:#how dark is the dark side of a shaded decorator" },
	{ _field_real, "shaded bright:#the bright side of a shaded decorator is this much brighter than the dark side" },
	{ _field_real, "unused1!" },
	{ _field_real, "unused2!" },
	{ _field_explanation, "LOD FADE + CULL" },
	{ _field_real, "early cull:[0 - 1]#cull vertices this percentage sooner than LOD3-nothing transition" },
	{ _field_real, "cull block size:[0.5-100]world units#decorators are grouped into blocks to be culled in large batches, this determines how much ground each batch covers.  Should be small if you expect to have very dense decorators, and large if you expect them to be sparse" },
	{ _field_real, "decimation speed!:[0 - infinite]#1 is default" },
	{ _field_real, "decimation start distance!#[block size by default] decimation offset of the starting point" },
	{ _field_real, "decimate to!{max decimation percentage}#0 means all the way removed. 100 means nothing" },
	{ _field_real, "decimation start:world units" },
	{ _field_real, "decimation end:world units" },
	{ _field_long_integer, "max valid lod!" },
	{ _field_explanation, "Lod transitions:" },
	{ _field_explanation, "Base to LOD2:" },
	{ _field_real, "start point0{Base to LOD1 cross fading start point}" },
	{ _field_real, "end point0{Base to LOD1 cross fading end point}" },
	{ _field_real, "scale0!" },
	{ _field_real, "offset0!" },
	{ _field_explanation, "LOD2 to LOD3:" },
	{ _field_real, "start point1{LOD1 to LOD2 cross fading start point}" },
	{ _field_real, "end point1{LOD1 to LOD2 cross fading end point}" },
	{ _field_real, "scale1!" },
	{ _field_real, "offset1!" },
	{ _field_explanation, "LOD3 to LOD4:" },
	{ _field_real, "start point2{LOD2 to LOD3 cross fading start point}" },
	{ _field_real, "end point2{LOD2 to LOD3 cross fading end point}" },
	{ _field_real, "scale2!" },
	{ _field_real, "offset2!" },
	{ _field_explanation, "LOD4 to nothing:" },
	{ _field_real, "start point3{LOD3 to nothing cross fading start point}" },
	{ _field_real, "end point3{LOD3 to nothing cross fading end point}" },
	{ _field_real, "scale3!" },
	{ _field_real, "offset3!" },
	{ _field_explanation, "DECORATOR TYPES" },
	{ _field_block, "decorator types", &global_decorator_type_block },
	{ _field_terminator },
};

} // namespace blofeld

