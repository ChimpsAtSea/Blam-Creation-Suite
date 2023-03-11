#pragma once

namespace blofeld
{
	
	enum e_tag_field_set_bit : unsigned long
	{
		_tag_field_set_unknown0_bit,
		_tag_field_set_unknown1_bit,
		_tag_field_set_has_inlined_children_with_placement_new_bit, // confirmed
		_tag_field_set_unknown3_bit,
		_tag_field_set_unknown4_bit,
		_tag_field_set_has_aggregate_types_bit,
		_tag_field_set_is_temporary_bit, // confirmed
		_tag_field_set_unknown7_bit,
		_tag_field_set_unknown8_bit,
		_tag_field_set_delete_recursively_bit, // confirmed
		_tag_field_set_postprocess_recursively_bit, // confirmed
		_tag_field_set_is_memcpyable_bit, // confirmed
		_tag_field_set_unknown12_bit,
		_tag_field_set_has_resources_bit,
		_tag_field_set_unknown14_bit,
		_tag_field_set_unknown15_bit,
		_tag_field_set_has_level_specific_fields_bit, // confirmed
		_tag_field_set_can_memset_to_initialize_bit, // confirmed
		_tag_field_set_unknown18_bit,
		_tag_field_set_exist_in_cache_build_bit,

		_tag_field_set_mandrill_has_versioning, // custom
		k_num_runtime_flags [[maybe_unused]]
	};
	
#define SET_DEFAULT c_flags<e_tag_field_set_bit>()
#define SET_UNKNOWN0 c_flags<e_tag_field_set_bit>(_tag_field_set_unknown0_bit)
#define SET_UNKNOWN1 c_flags<e_tag_field_set_bit>(_tag_field_set_unknown1_bit)
#define SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW c_flags<e_tag_field_set_bit>(_tag_field_set_has_inlined_children_with_placement_new_bit)
#define SET_UNKNOWN3 c_flags<e_tag_field_set_bit>(_tag_field_set_unknown3_bit)
#define SET_UNKNOWN4 c_flags<e_tag_field_set_bit>(_tag_field_set_unknown4_bit)
#define SET_UNKNOWN5 c_flags<e_tag_field_set_bit>(_tag_field_set_has_aggregate_types_bit)
#define SET_IS_TEMPORARY c_flags<e_tag_field_set_bit>(_tag_field_set_is_temporary_bit) 
#define SET_UNKNOWN7 c_flags<e_tag_field_set_bit>(_tag_field_set_unknown7_bit)
#define SET_UNKNOWN8 c_flags<e_tag_field_set_bit>(_tag_field_set_unknown8_bit)
#define SET_DELETE_RECURSIVELY c_flags<e_tag_field_set_bit>(_tag_field_set_delete_recursively_bit)
#define SET_POSTPROCESS_RECURSIVELY c_flags<e_tag_field_set_bit>(_tag_field_set_postprocess_recursively_bit)
#define SET_IS_MEMCPYABLE c_flags<e_tag_field_set_bit>(_tag_field_set_is_memcpyable_bit)
#define SET_UNKNOWN12 c_flags<e_tag_field_set_bit>(_tag_field_set_unknown12_bit)
#define SET_HAS_RESOURCES c_flags<e_tag_field_set_bit>(_tag_field_set_has_resources_bit)
#define SET_UNKNOWN14 c_flags<e_tag_field_set_bit>(_tag_field_set_unknown14_bit)
#define SET_UNKNOWN15 c_flags<e_tag_field_set_bit>(_tag_field_set_unknown15_bit)
#define SET_HAS_LEVEL_SPECIFIC_FIELDS c_flags<e_tag_field_set_bit>(_tag_field_set_has_level_specific_fields_bit)
#define SET_CAN_MEMSET_TO_INITIALIZE c_flags<e_tag_field_set_bit>(_tag_field_set_can_memset_to_initialize_bit)
#define SET_UNKNOWN18 c_flags<e_tag_field_set_bit>(_tag_field_set_unknown18_bit)
#define SET_EXIST_IN_CACHE_BUILD c_flags<e_tag_field_set_bit>(_tag_field_set_exist_in_cache_build_bit)

#define SET_MANDRILL_VERSIONING c_flags<e_tag_field_set_bit>(_tag_field_set_mandrill_has_versioning)

}
