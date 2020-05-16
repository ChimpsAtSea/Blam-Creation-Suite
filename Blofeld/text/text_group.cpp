#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(multilingual_unicode_string_list, MULTILINGUAL_UNICODE_STRING_LIST_TAG, multilingual_unicode_string_list_block_block );

TAG_BLOCK_FROM_STRUCT(multilingual_unicode_string_list_block, 1, multilingual_unicode_string_list_struct_definition_struct_definition );

TAG_BLOCK(multilingual_unicode_string_reference_block, k_maximum_multilingual_unicode_strings_per_string_list)
{
	FIELD( _field_string_id, "string id^*" ),
	FIELD( _field_long_integer, "english offset*" ),
	FIELD( _field_long_integer, "japanese offset*" ),
	FIELD( _field_long_integer, "german offset*" ),
	FIELD( _field_long_integer, "french offset*" ),
	FIELD( _field_long_integer, "spanish offset*" ),
	FIELD( _field_long_integer, "mexican spanish offset*" ),
	FIELD( _field_long_integer, "italian offset*" ),
	FIELD( _field_long_integer, "korean offset*" ),
	FIELD( _field_long_integer, "traditional chinese offset*" ),
	FIELD( _field_long_integer, "simplified chinese offset*" ),
	FIELD( _field_long_integer, "portuguese offset*" ),
	FIELD( _field_long_integer, "polish offset*" ),
	FIELD( _field_long_integer, "russian offset*" ),
	FIELD( _field_long_integer, "danish offset*" ),
	FIELD( _field_long_integer, "finnish offset*" ),
	FIELD( _field_long_integer, "dutch offset*" ),
	FIELD( _field_long_integer, "norwegian offset*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(string_substitution_pair_block, k_maximum_strings_per_string_list)
{
	FIELD( _field_string_id, "first string id^*!" ),
	FIELD( _field_string_id, "second string id*!" ),
	FIELD( _field_long_integer, "associated value*!" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(multilingual_unicode_string_list_struct_definition)
{
	FIELD( _field_custom, "import" ),
	FIELD( _field_custom, "import clean" ),
	FIELD( _field_block, "string references*", &multilingual_unicode_string_reference_block_block ),
	FIELD( _field_block, "substitution pairs*", &string_substitution_pair_block_block ),
	FIELD( _field_data, "string data utf8*" ),
	FIELD( _field_array, "language pack offsets!" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(language_pack_definition)
{
	FIELD( _field_long_integer, "string reference pointer!" ),
	FIELD( _field_long_integer, "string data pointer!" ),
	FIELD( _field_long_integer, "number of strings!" ),
	FIELD( _field_long_integer, "string data size!" ),
	FIELD( _field_long_integer, "string reference cache offset!" ),
	FIELD( _field_long_integer, "string data cache offset!" ),
	FIELD( _field_array, "string reference checksum!" ),
	FIELD( _field_array, "string data checksum!" ),
	FIELD( _field_long_integer, "data loaded boolean~!" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

