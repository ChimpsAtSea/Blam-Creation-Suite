#pragma once

class ISaveFilmMetadata
{
public:
	virtual void free() = 0;
	virtual INT32 Function1() = 0;
	virtual UINT32 Function2() = 0;
	virtual INT32 GetID() = 0;
	virtual INT64 GetAuthorXuid() = 0;
	virtual LPCWSTR GetName() = 0;
	virtual LPCWSTR GetDescription() = 0;

	char data[128936];
};
