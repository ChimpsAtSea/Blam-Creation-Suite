#include "tagfileserialization-private-pch.h"

template<> BCS_SHARED_EXPORT void byteswap_inplace(s_tag_file_header& value)
{
	byteswap_inplace(value.unknown0);
	byteswap_inplace(value.unknown4);
	byteswap_inplace(value.unknown8);
	byteswap_inplace(value.unknownC);
	byteswap_inplace(value.unknown10);
	byteswap_inplace(value.unknown14);
	byteswap_inplace(value.unknown18);
	byteswap_inplace(value.unknown1C);
	byteswap_inplace(value.unknown20);
	byteswap_inplace(value.unknown24);
	byteswap_inplace(value.unknown28);
	byteswap_inplace(value.unknown2C);
	byteswap_inplace(value.group_tag);
	byteswap_inplace(value.group_version);
	byteswap_inplace(value.crc32);
	byteswap_inplace(value.blam);
}
