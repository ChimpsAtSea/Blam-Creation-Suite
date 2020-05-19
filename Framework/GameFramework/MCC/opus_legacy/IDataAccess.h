#pragma once

#ifdef __INTELLISENSE__

/*
	IDataAccess Revision 2 : Build 1035
*/
class __IDataAccess;
class IDataAccess
{
public:
	virtual void Free();
	virtual IMapVariant* MapVariantCreateFromFile(char*, size_t);
	virtual IMapVariant* MapVariantCreateFromMapID(INT32);
	virtual IMapVariant* MapVariantCreateDefault(char*);
	virtual IGameVariant* GameVariantCreateFromFile(char*, size_t);
	virtual IGameVariant* GameVariantCreateDefault(char*);
	virtual bool LoadMapFromVariants(IGameVariant*, IMapVariant*);
	virtual ISaveFilmMetadata* SaveFilmMetadataCreateFromFile(char*, size_t);

private:
	void* m_HeapAllocation;
	void* function1;
	void* m_HeapAllocationSize;
	void* function3;

public:
	// #INTELLISENSE
	IDataAccess(__IDataAccess& data_access, e_build build);
};

#else

enum IDataAccessVirtualFunctionIndex
{
	__data_access_virtual_function_map_variant_create_from_file,
	__data_access_virtual_function_mapvariant_create_from_map_id,
	__data_access_virtual_function_mapvariant_create_default,
	__data_access_virtual_function_gamevariant_create_from_file,
	__data_access_virtual_function_gamevariant_create_default,
	__data_access_virtual_function_loadmap_from_variants,
	__data_access_virtual_function_save_film_metadata_create_from_file,
	__data_access_virtual_function_free,
};

inline uint32_t get_data_access_virtual_function_index(e_build build, IDataAccessVirtualFunctionIndex data_access_virtual_function_index)
{
	enum IDataAccessV1VirtualFunctionIndex
	{
		__data_access_v1_virtual_function_map_variant_create_from_file,
		__data_access_v1_virtual_function_mapvariant_create_from_map_id,
		__data_access_v1_virtual_function_mapvariant_create_default,
		__data_access_v1_virtual_function_gamevariant_create_from_file,
		__data_access_v1_virtual_function_gamevariant_create_default,
		__data_access_v1_virtual_function_loadmap_from_variants,
		__data_access_v1_virtual_function_save_film_metadata_create_from_file,
		__data_access_v1_virtual_function_free,
	};

	enum IDataAccessV2VirtualFunctionIndex
	{
		__data_access_v2_virtual_function_free,
		__data_access_v2_virtual_function_map_variant_create_from_file,
		__data_access_v2_virtual_function_mapvariant_create_from_map_id,
		__data_access_v2_virtual_function_mapvariant_create_default,
		__data_access_v2_virtual_function_gamevariant_create_from_file,
		__data_access_v2_virtual_function_gamevariant_create_default,
		__data_access_v2_virtual_function_loadmap_from_variants,
		__data_access_v2_virtual_function_save_film_metadata_create_from_file,
	};

	if (build <= _build_mcc_1_1035_0_0)
	{
		// version 1
		switch (data_access_virtual_function_index)
		{
		case __data_access_virtual_function_map_variant_create_from_file:					return __data_access_v1_virtual_function_map_variant_create_from_file;
		case __data_access_virtual_function_mapvariant_create_from_map_id:					return __data_access_v1_virtual_function_mapvariant_create_from_map_id;
		case __data_access_virtual_function_mapvariant_create_default:						return __data_access_v1_virtual_function_mapvariant_create_default;
		case __data_access_virtual_function_gamevariant_create_from_file:					return __data_access_v1_virtual_function_gamevariant_create_from_file;
		case __data_access_virtual_function_gamevariant_create_default:						return __data_access_v1_virtual_function_gamevariant_create_default;
		case __data_access_virtual_function_loadmap_from_variants:							return __data_access_v1_virtual_function_loadmap_from_variants;
		case __data_access_virtual_function_save_film_metadata_create_from_file:			return __data_access_v1_virtual_function_save_film_metadata_create_from_file;
		case __data_access_virtual_function_free:											return __data_access_v1_virtual_function_free;
		}
	}
	else
	{
		// version 2
		switch (data_access_virtual_function_index)
		{
		case __data_access_virtual_function_map_variant_create_from_file:					return __data_access_v2_virtual_function_map_variant_create_from_file;
		case __data_access_virtual_function_mapvariant_create_from_map_id:					return __data_access_v2_virtual_function_mapvariant_create_from_map_id;
		case __data_access_virtual_function_mapvariant_create_default:						return __data_access_v2_virtual_function_mapvariant_create_default;
		case __data_access_virtual_function_gamevariant_create_from_file:					return __data_access_v2_virtual_function_gamevariant_create_from_file;
		case __data_access_virtual_function_gamevariant_create_default:						return __data_access_v2_virtual_function_gamevariant_create_default;
		case __data_access_virtual_function_loadmap_from_variants:							return __data_access_v2_virtual_function_loadmap_from_variants;
		case __data_access_virtual_function_save_film_metadata_create_from_file:			return __data_access_v2_virtual_function_save_film_metadata_create_from_file;
		case __data_access_virtual_function_free:											return __data_access_v2_virtual_function_free;
		}
	}
	throw;
}

class IDataAccess;

class __IDataAccess // raw data
{
	friend class IDataAccess;
private:
	void** __vfptr;
	void* m_HeapAllocation;
	void* function1;
	void* m_HeapAllocationSize;
	void* function3;
};

class IDataAccess
{
public:
	IDataAccess(__IDataAccess& data_access, e_build build) :
		data_access(data_access),
		build(build)
	{
		REFERENCE_ASSERT(data_access);

		uint32_t map_variant_create_from_file_index = get_data_access_virtual_function_index(build, __data_access_virtual_function_map_variant_create_from_file);
		uint32_t mapvariant_create_from_map_id_index = get_data_access_virtual_function_index(build, __data_access_virtual_function_mapvariant_create_from_map_id);
		uint32_t mapvariant_create_default_index = get_data_access_virtual_function_index(build, __data_access_virtual_function_mapvariant_create_default);
		uint32_t gamevariant_create_from_file_index = get_data_access_virtual_function_index(build, __data_access_virtual_function_gamevariant_create_from_file);
		uint32_t gamevariant_create_default_index = get_data_access_virtual_function_index(build, __data_access_virtual_function_gamevariant_create_default);
		uint32_t loadmap_from_variants_index = get_data_access_virtual_function_index(build, __data_access_virtual_function_loadmap_from_variants);
		uint32_t save_film_metadata_create_from_file_index = get_data_access_virtual_function_index(build, __data_access_virtual_function_save_film_metadata_create_from_file);
		uint32_t free_virtual_function_index = get_data_access_virtual_function_index(build, __data_access_virtual_function_free);

		_MapVariantCreateFromFile = static_cast<decltype(_MapVariantCreateFromFile)>(data_access.__vfptr[map_variant_create_from_file_index]);
		_MapVariantCreateFromMapID = static_cast<decltype(_MapVariantCreateFromMapID)>(data_access.__vfptr[mapvariant_create_from_map_id_index]);
		_MapVariantCreateDefault = static_cast<decltype(_MapVariantCreateDefault)>(data_access.__vfptr[mapvariant_create_default_index]);
		_GameVariantCreateFromFile = static_cast<decltype(_GameVariantCreateFromFile)>(data_access.__vfptr[gamevariant_create_from_file_index]);
		_GameVariantCreateDefault = static_cast<decltype(_GameVariantCreateDefault)>(data_access.__vfptr[gamevariant_create_default_index]);
		_LoadMapFromVariants = static_cast<decltype(_LoadMapFromVariants)>(data_access.__vfptr[loadmap_from_variants_index]);
		_SaveFilmMetadataCreateFromFile = static_cast<decltype(_SaveFilmMetadataCreateFromFile)>(data_access.__vfptr[save_film_metadata_create_from_file_index]);
		_Free = static_cast<decltype(_Free)>(data_access.__vfptr[free_virtual_function_index]);

		DEBUG_ASSERT(_Free != nullptr);
		DEBUG_ASSERT(_MapVariantCreateFromFile != nullptr);
		DEBUG_ASSERT(_MapVariantCreateFromMapID != nullptr);
		DEBUG_ASSERT(_MapVariantCreateDefault != nullptr);
		DEBUG_ASSERT(_GameVariantCreateFromFile != nullptr);
		DEBUG_ASSERT(_GameVariantCreateDefault != nullptr);
		DEBUG_ASSERT(_LoadMapFromVariants != nullptr);
		DEBUG_ASSERT(_SaveFilmMetadataCreateFromFile != nullptr);
	}

	~IDataAccess()
	{

	}

	typedef void FreeFunc(__IDataAccess*);
	typedef IMapVariant* MapVariantCreateFromFileFunc(__IDataAccess*, char*, size_t);
	typedef IMapVariant* MapVariantCreateFromMapIDFunc(__IDataAccess*, INT32);
	typedef IMapVariant* MapVariantCreateDefaultFunc(__IDataAccess*, char*);
	typedef IGameVariant* GameVariantCreateFromFileFunc(__IDataAccess*, char*, size_t);
	typedef IGameVariant* GameVariantCreateDefaultFunc(__IDataAccess*, char*);
	typedef bool LoadMapFromVariantsFunc(__IDataAccess*, IGameVariant*, IMapVariant*);
	typedef ISaveFilmMetadata* SaveFilmMetadataCreateFromFileFunc(__IDataAccess*, char*, size_t);

	void Free() { _Free(&data_access); }
	IMapVariant* MapVariantCreateFromFile(char* buffer, size_t size) { return _MapVariantCreateFromFile(&data_access, buffer, size); }
	IMapVariant* MapVariantCreateFromMapID(INT32 map_id) { return _MapVariantCreateFromMapID(&data_access, map_id); }
	IMapVariant* MapVariantCreateDefault(char* buffer) { return _MapVariantCreateDefault(&data_access, buffer); }
	IGameVariant* GameVariantCreateFromFile(char* buffer, size_t size) { return _GameVariantCreateFromFile(&data_access, buffer, size); }
	IGameVariant* GameVariantCreateDefault(char* buffer) { return _GameVariantCreateDefault(&data_access, buffer); }
	bool LoadMapFromVariants(IGameVariant* game_variant, IMapVariant* map_variant) { return _LoadMapFromVariants(&data_access, game_variant, map_variant); }
	ISaveFilmMetadata* SaveFilmMetadataCreateFromFile(char* buffer, size_t size) { return _SaveFilmMetadataCreateFromFile(&data_access, buffer, size); }

	__IDataAccess& data_access;
	e_build build;
	FreeFunc* _Free;
	MapVariantCreateFromFileFunc* _MapVariantCreateFromFile;
	MapVariantCreateFromMapIDFunc* _MapVariantCreateFromMapID;
	MapVariantCreateDefaultFunc* _MapVariantCreateDefault;
	GameVariantCreateFromFileFunc* _GameVariantCreateFromFile;
	GameVariantCreateDefaultFunc* _GameVariantCreateDefault;
	LoadMapFromVariantsFunc* _LoadMapFromVariants;
	SaveFilmMetadataCreateFromFileFunc* _SaveFilmMetadataCreateFromFile;
};

#endif
