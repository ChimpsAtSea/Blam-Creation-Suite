#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(global_avatar_award_enum, 3)
	{
		OPTION("award_0"),
		OPTION("award_1"),
		OPTION("award_2"),
	};

	TAG_GROUP_FROM_BLOCK(avatar_awards, AVATAR_AWARDS_TAG, avatar_awards_block_block );

	TAG_BLOCK_FROM_STRUCT(avatar_awards_block, 1, avatar_awards_struct_definition_struct_definition );

	TAG_BLOCK(single_avatar_award_definition_block, k_online_avatar_award_count)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_long_enum, "type", &global_avatar_award_enum ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(avatar_awards_struct_definition)
{
		FIELD( _field_block, "avatar_award", &single_avatar_award_definition_block_block ),
		FIELD( _field_terminator )
};

} // namespace blofeld

