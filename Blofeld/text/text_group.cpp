#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(multilingual_unicode_string_reference, k_maximum_multilingual_unicode_strings_per_string_list)
{
	{ _field_string_id, "string id^*" },
	{ _field_long_integer, "english offset*" },
	{ _field_long_integer, "japanese offset*" },
	{ _field_long_integer, "german offset*" },
	{ _field_long_integer, "french offset*" },
	{ _field_long_integer, "spanish offset*" },
	{ _field_long_integer, "mexican spanish offset*" },
	{ _field_long_integer, "italian offset*" },
	{ _field_long_integer, "korean offset*" },
	{ _field_long_integer, "traditional chinese offset*" },
	{ _field_long_integer, "simplified chinese offset*" },
	{ _field_long_integer, "portuguese offset*" },
	{ _field_long_integer, "polish offset*" },
	{ _field_long_integer, "russian offset*" },
	{ _field_long_integer, "danish offset*" },
	{ _field_long_integer, "finnish offset*" },
	{ _field_long_integer, "dutch offset*" },
	{ _field_long_integer, "norwegian offset*" },
	{ _field_terminator },
};

TAG_BLOCK(string_substitution_pair, k_maximum_strings_per_string_list)
{
	{ _field_string_id, "first string id^*!" },
	{ _field_string_id, "second string id*!" },
	{ _field_long_integer, "associated value*!" },
	{ _field_terminator },
};

TAG_GROUP(multilingual_unicode_string_list, MULTILINGUAL_UNICODE_STRING_LIST_TAG)
{
	{ _field_custom, "import" },
	{ _field_custom, "import clean" },
	{ _field_block, "string references*", &multilingual_unicode_string_reference_block },
	{ _field_block, "substitution pairs*", &string_substitution_pair_block },
	{ _field_data, "string data utf8*" },
	{ _field_array, "language pack offsets!" },
	{ _field_terminator },
};

} // namespace blofeld

