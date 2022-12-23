#pragma once

namespace blofeld
{
	struct s_tag_persistent_identifier
	{
		uint32_t identifier_part_0;
		uint32_t identifier_part_1;
		uint32_t identifier_part_2;
		uint32_t identifier_part_3;
	};
}

BCS_SHARED extern bool operator==(const blofeld::s_tag_persistent_identifier& a, const blofeld::s_tag_persistent_identifier& b);
BCS_SHARED extern bool operator!=(const blofeld::s_tag_persistent_identifier& a, const blofeld::s_tag_persistent_identifier& b);

#define PERSISTENT_ID_EMPTY { 0, 0, 0, 0 }
#define PERSISTENT_ID_UNKNOWN { UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX }
