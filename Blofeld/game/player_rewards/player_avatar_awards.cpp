#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(single_avatar_award_definition, k_online_avatar_award_count)
{
	{ _field_string_id, "name^" },
	{ _field_long_enum, "type" },
	{ _field_terminator },
};

TAG_GROUP(avatar_awards, AVATAR_AWARDS_TAG)
{
	{ _field_block, "avatar_award", &single_avatar_award_definition_block },
	{ _field_terminator },
};

} // namespace blofeld

