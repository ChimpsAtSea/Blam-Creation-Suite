#pragma once

class IVariantAccessorBase
{
public:
	virtual void Free() = 0;
	virtual LPCWSTR GetName() = 0;
	virtual LPCWSTR GetDescription() = 0;
	virtual LPCWSTR SetName(LPCWSTR) = 0;
	virtual LPCWSTR SetDescription(LPCWSTR) = 0;
	virtual void Function5() = 0;
	virtual void Function6() = 0;
	virtual void Function7() = 0;
	virtual bool CreateFileFromBuffer(LPVOID, size_t *) = 0;
};