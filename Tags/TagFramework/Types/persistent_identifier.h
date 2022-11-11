#pragma once

namespace blofeld
{
	struct s_tag_persistent_identifier
	{
		uint32_t identifier_part_0;
		uint32_t identifier_part_1;
		uint32_t identifier_part_2;
		uint32_t identifier_part_3;

		BCS_SHARED bool operator==(const s_tag_persistent_identifier& value) const;
		BCS_SHARED bool operator!=(const s_tag_persistent_identifier& value) const;
	};
}

#define PERSISTENT_ID_EMPTY { 0, 0, 0, 0 }
#define PERSISTENT_ID_UNKNOWN { UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX }
