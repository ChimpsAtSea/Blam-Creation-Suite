#include <tag_files/tag_groups.h>

#include <cstdlib>

/* ---------- code */

bool tag_persistent_identifiers_equal(
	s_tag_persistent_identifier const &identifier1,
	s_tag_persistent_identifier const &identifier2)
{
	return csmemcmp(
		reinterpret_cast<const void *>(&identifier1),
		reinterpret_cast<const void *>(&identifier2),
		sizeof(s_tag_persistent_identifier)) == 0;
}

/* ---------- definitions */

TAG_BLOCK(
	g_bit_vector_block,
	sizeof(dword),
	NONE)
{
	{ _field_dword_integer, "bits" },
	{ _field_terminator }
};

TAG_REFERENCE(
	tag_reference_block_reference,
	1)
{
	static_cast<tag>(NONE)
};

TAG_BLOCK(
	g_tag_reference_block,
	sizeof(s_tag_reference),
	NONE)
{
	{ _field_tag_reference, "type", &tag_reference_block_reference },
	{ _field_terminator }
};

TAG_STRUCT(
	g_tag_function_struct,
	sizeof(s_tag_data))
{
	{ _field_data, "data" },
	{ _field_terminator }
};
