#include "tagfileserialization-private-pch.h"

template<> void byteswap_inplace(s_system_global_unique_identifier& value)
{
	byteswap_inplace(value.identifier_part_0);
	byteswap_inplace(value.identifier_part_1);
	byteswap_inplace(value.identifier_part_2);
	byteswap_inplace(value.identifier_part_3);
}

bool operator==(const s_system_global_unique_identifier& a, const blofeld::s_tag_persistent_identifier& b)
{
	return
		a.identifier_part_0 == b.identifier_part_0 &&
		a.identifier_part_1 == b.identifier_part_1 &&
		a.identifier_part_2 == b.identifier_part_2 &&
		a.identifier_part_3 == b.identifier_part_3;
}

bool operator==(const blofeld::s_tag_persistent_identifier& a, const s_system_global_unique_identifier& b)
{
	return
		a.identifier_part_0 == b.identifier_part_0 &&
		a.identifier_part_1 == b.identifier_part_1 &&
		a.identifier_part_2 == b.identifier_part_2 &&
		a.identifier_part_3 == b.identifier_part_3;
}

bool operator!=(const s_system_global_unique_identifier& a, const blofeld::s_tag_persistent_identifier& b)
{
	return
		a.identifier_part_0 != b.identifier_part_0 ||
		a.identifier_part_1 != b.identifier_part_1 ||
		a.identifier_part_2 != b.identifier_part_2 ||
		a.identifier_part_3 != b.identifier_part_3;
}

bool operator!=(const blofeld::s_tag_persistent_identifier& a, const s_system_global_unique_identifier& b)
{
	return
		a.identifier_part_0 != b.identifier_part_0 ||
		a.identifier_part_1 != b.identifier_part_1 ||
		a.identifier_part_2 != b.identifier_part_2 ||
		a.identifier_part_3 != b.identifier_part_3;
}
