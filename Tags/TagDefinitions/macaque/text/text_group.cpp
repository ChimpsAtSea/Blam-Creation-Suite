#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		multilingual_unicode_string_list_group,
		MULTILINGUAL_UNICODE_STRING_LIST_TAG,
		nullptr,
		INVALID_TAG,
		multilingual_unicode_string_list_block );

	TAG_BLOCK_FROM_STRUCT(
		multilingual_unicode_string_list_block,
		"multilingual_unicode_string_list_block",
		1,
		multilingual_unicode_string_list_struct_definition);

	#define MULTILINGUAL_UNICODE_STRING_REFERENCE_BLOCK_ID { 0xC5BC6DA3, 0x37A44EB2, 0xA26A511D, 0x236996E6 }
	TAG_BLOCK(
		multilingual_unicode_string_reference_block,
		"multilingual_unicode_string_reference_block",
		k_maximum_multilingual_unicode_strings_per_string_list,
		"s_multilingual_unicode_string_reference",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MULTILINGUAL_UNICODE_STRING_REFERENCE_BLOCK_ID)
	{
		{ _field_string_id, "string id" },
		{ _field_long_integer, "english offset" },
		{ _field_long_integer, "japanese offset" },
		{ _field_long_integer, "german offset" },
		{ _field_long_integer, "french offset" },
		{ _field_long_integer, "spanish offset" },
		{ _field_long_integer, "mexican spanish offset" },
		{ _field_long_integer, "italian offset" },
		{ _field_long_integer, "korean offset" },
		{ _field_long_integer, "traditional chinese offset" },
		{ _field_long_integer, "simplified chinese offset" },
		{ _field_long_integer, "portuguese offset" },
		{ _field_long_integer, "polish offset" },
		{ _field_long_integer, "russian offset" },
		{ _field_long_integer, "danish offset" },
		{ _field_long_integer, "finnish offset" },
		{ _field_long_integer, "dutch offset" },
		{ _field_long_integer, "norwegian offset" },
		{ _field_terminator }
	};

	#define STRING_SUBSTITUTION_PAIR_BLOCK_ID { 0x57436AF6, 0x37054DE1, 0xBB030AB6, 0x685EDB0B }
	TAG_BLOCK(
		string_substitution_pair_block,
		"string_substitution_pair_block",
		k_maximum_strings_per_string_list,
		"s_string_substitution_pair",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRING_SUBSTITUTION_PAIR_BLOCK_ID)
	{
		{ _field_string_id, "first string id" },
		{ _field_string_id, "second string id" },
		{ _field_long_integer, "associated value" },
		{ _field_terminator }
	};

	#define DATA_HASH_DEFINITION_ID { 0x6A3A433A, 0xA2E2464E, 0xBD38F0AE, 0x0CC98FB3 }
	TAG_ARRAY(
		data_hash_definition_array,
		"data_hash_definition",
		k_hash_size,
		"byte",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DATA_HASH_DEFINITION_ID)
	{
		{ _field_byte_integer, "hash byte" },
		{ _field_terminator }
	};

	#define MULTILINGUAL_UNICODE_STRING_LIST_LANGUAGE_PACK_OFFSETS_ID { 0xD3554473, 0x3F7445DD, 0x86D39D3C, 0x59003C59 }
	TAG_ARRAY(
		multilingual_unicode_string_list_language_pack_offsets_array,
		"multilingual_unicode_string_list_language_pack_offsets",
		k_language_count,
		"s_language_pack_offsets",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MULTILINGUAL_UNICODE_STRING_LIST_LANGUAGE_PACK_OFFSETS_ID)
	{
		{ _field_short_integer, "start index" },
		{ _field_short_integer, "string count" },
		{ _field_terminator }
	};

	#define MULTILINGUAL_UNICODE_STRING_LIST_STRUCT_DEFINITION_ID { 0x257EFBBE, 0x66F84C7A, 0x8922D3CD, 0x800AE80F }
	TAG_STRUCT(
		multilingual_unicode_string_list_struct_definition,
		"multilingual_unicode_string_list_struct_definition",
		"s_multilingual_unicode_string_list_group_header",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MULTILINGUAL_UNICODE_STRING_LIST_STRUCT_DEFINITION_ID)
	{
		FIELD_CUSTOM("import", nullptr, _field_id_text_unknown),
		FIELD_CUSTOM("import clean", nullptr, _field_id_text_unknown),
		{ _field_block, "string references", &multilingual_unicode_string_reference_block },
		{ _field_block, "substitution pairs", &string_substitution_pair_block },
		{ _field_data, "string data utf8" },
		{ _field_array, "language pack offsets", &multilingual_unicode_string_list_language_pack_offsets_array },
		{ _field_terminator }
	};

	#define LANGUAGE_PACK_DEFINITION_ID { 0x75A16A47, 0xDCD04796, 0x8CB23851, 0x14C59991 }
	TAG_STRUCT(
		language_pack_definition,
		"language_pack_definition",
		"c_language_pack",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		LANGUAGE_PACK_DEFINITION_ID)
	{
		{ _field_long_integer, "string reference pointer", _field_id_zero_data },
		{ _field_long_integer, "string data pointer", _field_id_zero_data },
		{ _field_long_integer, "number of strings" },
		{ _field_long_integer, "string data size" },
		{ _field_long_integer, "string reference cache offset" },
		{ _field_long_integer, "string data cache offset" },
		{ _field_array, "string reference checksum", &data_hash_definition_array },
		{ _field_array, "string data checksum", &data_hash_definition_array },
		{ _field_long_integer, "data loaded boolean" },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_multilingual_unicode_string_list_reference, MULTILINGUAL_UNICODE_STRING_LIST_TAG);

} // namespace macaque

} // namespace blofeld

