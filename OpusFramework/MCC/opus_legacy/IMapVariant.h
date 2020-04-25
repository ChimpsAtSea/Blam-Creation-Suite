#pragma once

struct s_map_variant
{
	char data[55724];
};

class IMapVariant : public IVariantAccessorBase
{
public:
	virtual INT32 GetID() = 0;
	virtual bool Function10() = 0;
	virtual bool Function11() = 0;
	virtual bool Function12() = 0;

	union
	{
		s_map_variant MapVariant;
		char variant_buffer[0xE800];
	};
};