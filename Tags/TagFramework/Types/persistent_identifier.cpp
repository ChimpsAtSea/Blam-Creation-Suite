#include "tagframework-private-pch.h"

using namespace blofeld;

bool s_tag_persistent_identifier::operator==(const s_tag_persistent_identifier& value) const
{
	return
		identifier_part_0 == value.identifier_part_0 &&
		identifier_part_1 == value.identifier_part_1 &&
		identifier_part_2 == value.identifier_part_2 &&
		identifier_part_3 == value.identifier_part_3;
}

bool s_tag_persistent_identifier::operator!=(const s_tag_persistent_identifier& value) const
{
	return
		identifier_part_0 != value.identifier_part_0 ||
		identifier_part_1 != value.identifier_part_1 ||
		identifier_part_2 != value.identifier_part_2 ||
		identifier_part_3 != value.identifier_part_3;
}

template<> BCS_SHARED void byteswap_inplace(blofeld::s_tag_persistent_identifier& value)
{
	byteswap_inplace(value.identifier_part_0);
	byteswap_inplace(value.identifier_part_1);
	byteswap_inplace(value.identifier_part_2);
	byteswap_inplace(value.identifier_part_3);
}
