#pragma once

#pragma pack(push, 1)

noreflection struct color24
{
	unsigned char data[3];
};

noreflection struct color32
{
	unsigned char data[4];
};

noreflection struct colorf
{
	float data[4];
};

#pragma pack(pop)


