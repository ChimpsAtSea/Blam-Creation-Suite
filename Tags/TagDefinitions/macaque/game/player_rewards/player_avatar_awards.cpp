#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		avatar_awards_group,
		AVATAR_AWARDS_TAG,
		nullptr,
		INVALID_TAG,
		avatar_awards_block );

	TAG_BLOCK_FROM_STRUCT(
		avatar_awards_block,
		"avatar_awards_block",
		1,
		avatar_awards_struct_definition);

	#define SINGLE_AVATAR_AWARD_DEFINITION_BLOCK_ID { 0x69CB40EF, 0xB1574B0C, 0x90BD2634, 0x87F8862D }
	TAG_BLOCK(
		single_avatar_award_definition_block,
		"single_avatar_award_definition_block",
		k_online_avatar_award_count,
		"s_single_avatar_award_definition",
		SINGLE_AVATAR_AWARD_DEFINITION_BLOCK_ID)
	{
		{ _field_string_id, "name^" },
		{ _field_long_enum, "type", &global_avatar_award_enum },
		{ _field_terminator }
	};

	#define AVATAR_AWARDS_STRUCT_DEFINITION_ID { 0xE7F475A4, 0xCEA745F5, 0xB17719E4, 0x82815003 }
	TAG_STRUCT(
		avatar_awards_struct_definition,
		"avatar_awards_struct_definition",
		"s_game_avatar_awards_definition",
		AVATAR_AWARDS_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "avatar_award", &single_avatar_award_definition_block },
		{ _field_terminator }
	};

	STRINGS(global_avatar_award_enum)
	{
		"award_0",
		"award_1",
		"award_2"
	};
	STRING_LIST(global_avatar_award_enum, global_avatar_award_enum_strings, _countof(global_avatar_award_enum_strings));

} // namespace macaque

} // namespace blofeld

