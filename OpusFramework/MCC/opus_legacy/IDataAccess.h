#pragma once

class IDataAccess
{
public:
	virtual void Free() = 0;
	virtual IMapVariant *MapVariantCreateFromFile(char *, size_t) = 0;
	virtual IMapVariant *MapVariantCreateFromMapID(INT32) = 0;
	virtual IMapVariant *MapVariantCreateDefault(char *) = 0;
	virtual IGameVariant *GameVariantCreateFromFile(char *, size_t) = 0;
	virtual IGameVariant *GameVariantCreateDefault(char *) = 0;
	virtual bool LoadMapFromVariants(IGameVariant *, IMapVariant *) = 0;
	virtual ISaveFilmMetadata *SaveFilmMetadataCreateFromFile(char *, size_t) = 0;

private:
	void *m_HeapAllocation;
	void *function1;
	void *m_HeapAllocationSize;
	void *function3;
};