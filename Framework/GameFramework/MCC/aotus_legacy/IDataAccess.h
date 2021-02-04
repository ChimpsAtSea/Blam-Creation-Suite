#pragma once

#ifdef __INTELLISENSE__

/*
	IDataAccess Revision 2 : Build 1035
*/
class __IDataAccess;
class IDataAccess
{
public:
	virtual void free();
	virtual IMapVariant* map_variant_create_from_file(char*, size_t);
	virtual IMapVariant* map_variant_create_from_map_id(INT32);
	virtual IMapVariant* map_variant_create_default(char*);
	virtual IGameVariant* game_variant_create_from_file(char*, size_t);
	virtual IGameVariant* game_variant_create_default(char*);
	virtual bool load_map_from_variants(IGameVariant*, IMapVariant*);
	virtual ISaveFilmMetadata* save_film_metadata_create_from_file(char*, size_t);

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
	__data_access_virtual_function_map_variant_create_from_map_id,
	__data_access_virtual_function_map_variant_create_default,
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
		__data_access_v1_virtual_function_map_variant_create_from_map_id,
		__data_access_v1_virtual_function_map_variant_create_default,
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
		__data_access_v2_virtual_function_map_variant_create_from_map_id,
		__data_access_v2_virtual_function_map_variant_create_default,
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
		case __data_access_virtual_function_map_variant_create_from_map_id:					return __data_access_v1_virtual_function_map_variant_create_from_map_id;
		case __data_access_virtual_function_map_variant_create_default:						return __data_access_v1_virtual_function_map_variant_create_default;
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
		case __data_access_virtual_function_map_variant_create_from_map_id:					return __data_access_v2_virtual_function_map_variant_create_from_map_id;
		case __data_access_virtual_function_map_variant_create_default:						return __data_access_v2_virtual_function_map_variant_create_default;
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
		uint32_t map_variant_create_from_map_id_index = get_data_access_virtual_function_index(build, __data_access_virtual_function_map_variant_create_from_map_id);
		uint32_t map_variant_create_default_index = get_data_access_virtual_function_index(build, __data_access_virtual_function_map_variant_create_default);
		uint32_t gamevariant_create_from_file_index = get_data_access_virtual_function_index(build, __data_access_virtual_function_gamevariant_create_from_file);
		uint32_t gamevariant_create_default_index = get_data_access_virtual_function_index(build, __data_access_virtual_function_gamevariant_create_default);
		uint32_t loadmap_from_variants_index = get_data_access_virtual_function_index(build, __data_access_virtual_function_loadmap_from_variants);
		uint32_t save_film_metadata_create_from_file_index = get_data_access_virtual_function_index(build, __data_access_virtual_function_save_film_metadata_create_from_file);
		uint32_t free_virtual_function_index = get_data_access_virtual_function_index(build, __data_access_virtual_function_free);

		_map_variant_create_from_file = static_cast<decltype(_map_variant_create_from_file)>(data_access.__vfptr[map_variant_create_from_file_index]);
		_map_variant_create_from_map_id = static_cast<decltype(_map_variant_create_from_map_id)>(data_access.__vfptr[map_variant_create_from_map_id_index]);
		_map_variant_create_default = static_cast<decltype(_map_variant_create_default)>(data_access.__vfptr[map_variant_create_default_index]);
		_game_variant_create_from_file = static_cast<decltype(_game_variant_create_from_file)>(data_access.__vfptr[gamevariant_create_from_file_index]);
		_game_variant_create_default = static_cast<decltype(_game_variant_create_default)>(data_access.__vfptr[gamevariant_create_default_index]);
		_load_map_from_variants = static_cast<decltype(_load_map_from_variants)>(data_access.__vfptr[loadmap_from_variants_index]);
		_save_film_metadata_create_from_file = static_cast<decltype(_save_film_metadata_create_from_file)>(data_access.__vfptr[save_film_metadata_create_from_file_index]);
		_free = static_cast<decltype(_free)>(data_access.__vfptr[free_virtual_function_index]);

		DEBUG_ASSERT(_free != nullptr);
		DEBUG_ASSERT(_map_variant_create_from_file != nullptr);
		DEBUG_ASSERT(_map_variant_create_from_map_id != nullptr);
		DEBUG_ASSERT(_map_variant_create_default != nullptr);
		DEBUG_ASSERT(_game_variant_create_from_file != nullptr);
		DEBUG_ASSERT(_game_variant_create_default != nullptr);
		DEBUG_ASSERT(_load_map_from_variants != nullptr);
		DEBUG_ASSERT(_save_film_metadata_create_from_file != nullptr);
	}

	~IDataAccess()
	{

	}

	typedef void freeFunc(__IDataAccess*);
	typedef IMapVariant* map_variant_create_from_fileFunc(__IDataAccess*, char*, size_t);
	typedef IMapVariant* map_variant_create_from_map_idFunc(__IDataAccess*, INT32);
	typedef IMapVariant* map_variant_create_defaultFunc(__IDataAccess*, char*);
	typedef IGameVariant* game_variant_create_from_fileFunc(__IDataAccess*, char*, size_t);
	typedef IGameVariant* game_variant_create_defaultFunc(__IDataAccess*, char*);
	typedef bool load_map_from_variantsFunc(__IDataAccess*, IGameVariant*, IMapVariant*);
	typedef ISaveFilmMetadata* save_film_metadata_create_from_fileFunc(__IDataAccess*, char*, size_t);

	void free() { _free(&data_access); }
	IMapVariant* map_variant_create_from_file(char* buffer, size_t size) { return _map_variant_create_from_file(&data_access, buffer, size); }
	IMapVariant* map_variant_create_from_map_id(INT32 map_id) { return _map_variant_create_from_map_id(&data_access, map_id); }
	IMapVariant* map_variant_create_default(char* buffer) { return _map_variant_create_default(&data_access, buffer); }
	IGameVariant* game_variant_create_from_file(char* buffer, size_t size) { return _game_variant_create_from_file(&data_access, buffer, size); }
	IGameVariant* game_variant_create_default(char* buffer) { return _game_variant_create_default(&data_access, buffer); }
	bool load_map_from_variants(IGameVariant* game_variant, IMapVariant* map_variant) { return _load_map_from_variants(&data_access, game_variant, map_variant); }
	ISaveFilmMetadata* save_film_metadata_create_from_file(char* buffer, size_t size) { return _save_film_metadata_create_from_file(&data_access, buffer, size); }

	__IDataAccess& data_access;
	e_build build;
	freeFunc* _free;
	map_variant_create_from_fileFunc* _map_variant_create_from_file;
	map_variant_create_from_map_idFunc* _map_variant_create_from_map_id;
	map_variant_create_defaultFunc* _map_variant_create_default;
	game_variant_create_from_fileFunc* _game_variant_create_from_file;
	game_variant_create_defaultFunc* _game_variant_create_default;
	load_map_from_variantsFunc* _load_map_from_variants;
	save_film_metadata_create_from_fileFunc* _save_film_metadata_create_from_file;
};

#endif
