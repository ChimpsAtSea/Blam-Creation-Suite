#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(single_avatar_award_definition, k_online_avatar_award_count)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_long_enum, "type" ),
	FIELD( _field_terminator )
};

TAG_GROUP(avatar_awards, AVATAR_AWARDS_TAG)
{
	FIELD( _field_block, "avatar_award", &single_avatar_award_definition_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

