#pragma once

struct s_system_global_unique_identifier
{
	uint32_t identifier_part_0;
	uint32_t identifier_part_1;
	uint32_t identifier_part_2;
	uint32_t identifier_part_3;
};

BCS_SHARED extern bool operator==(const s_system_global_unique_identifier& a, const blofeld::s_tag_persistent_identifier& b);
BCS_SHARED extern bool operator==(const blofeld::s_tag_persistent_identifier& a, const s_system_global_unique_identifier& b);
BCS_SHARED extern bool operator!=(const s_system_global_unique_identifier& a, const blofeld::s_tag_persistent_identifier& b);
BCS_SHARED extern bool operator!=(const blofeld::s_tag_persistent_identifier& a, const s_system_global_unique_identifier& b);
