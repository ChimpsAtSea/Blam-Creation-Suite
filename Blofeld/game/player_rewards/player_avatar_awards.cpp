#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(avatar_awards_struct_definition)
{
	FIELD( _field_block, "avatar_award", &single_avatar_award_definition_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(single_avatar_award_definition_block, k_online_avatar_award_count)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_long_enum, "type" ),
	FIELD( _field_terminator )
};

TAG_GROUP(avatar_awards_block, AVATAR_AWARDS_TAG)
{
	FIELD( _field_block, "avatar_award", &single_avatar_award_definition_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

