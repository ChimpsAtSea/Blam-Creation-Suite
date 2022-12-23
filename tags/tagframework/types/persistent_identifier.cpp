#include "tagframework-private-pch.h"

using namespace blofeld;

bool operator==(const blofeld::s_tag_persistent_identifier& a, const blofeld::s_tag_persistent_identifier& b)
{
	return
		a.identifier_part_0 == b.identifier_part_0 &&
		a.identifier_part_1 == b.identifier_part_1 &&
		a.identifier_part_2 == b.identifier_part_2 &&
		a.identifier_part_3 == b.identifier_part_3;
}

bool operator!=(const blofeld::s_tag_persistent_identifier& a, const blofeld::s_tag_persistent_identifier& b)
{
	return
		a.identifier_part_0 != b.identifier_part_0 ||
		a.identifier_part_1 != b.identifier_part_1 ||
		a.identifier_part_2 != b.identifier_part_2 ||
		a.identifier_part_3 != b.identifier_part_3;
}

template<> BCS_SHARED void byteswap_inplace(blofeld::s_tag_persistent_identifier& value)
{
	byteswap_inplace(value.identifier_part_0);
	byteswap_inplace(value.identifier_part_1);
	byteswap_inplace(value.identifier_part_2);
	byteswap_inplace(value.identifier_part_3);
}
