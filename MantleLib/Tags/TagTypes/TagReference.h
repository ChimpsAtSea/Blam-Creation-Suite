#pragma once

class noreflection TagReference
{
public:
	e_tag_group tagGroupName;
	uint32_t nameLength;
	uint32_t nameOffset;
	uint16_t index;
	uint16_t datum;
};
