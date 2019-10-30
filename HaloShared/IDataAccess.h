#pragma once

struct IDataAccess;
struct IDataAccess_vtbl
{
	void(__fastcall* Free)(IDataAccess*);
	struct IMapVariant* (__fastcall* CreateMapVariantFromFile)(IDataAccess*, /*struct content_item_map_variant **/char*, size_t);
	struct IMapVariant* (__fastcall* CreateMapVariantFromMCCMapId)(IDataAccess*, __int64);
	struct IMapVariant* (__fastcall* CreateMapVariant)(IDataAccess*, struct s_map_variant*);
	struct IGameVariant* (__fastcall* CreateGameVariantFromFile)(IDataAccess*, /*struct content_item_game_variant **/char*, size_t);
	struct IGameVariant* (__fastcall* CreateGameVariant)(IDataAccess*, struct s_game_variant*);
	bool(__fastcall* Member05)(IDataAccess*, struct s_unknown*, void*);
	struct ISaveFilmMetadata* (__fastcall* CreateSaveFilmMetadataFromFile)(IDataAccess*, /*struct content_item_film_description **/char*, size_t);
};

struct IDataAccess
{
	IDataAccess_vtbl* __vftable /*VFT*/;
	void* c_heap_allocation;
	void* function1;
	void* c_heap_allocation_size;
	void* function3;

	__int64 CreateMapVariantFromFile(char* content_item_map_variant, size_t file_length)
	{
		return (__int64)__vftable->CreateMapVariantFromFile(this, content_item_map_variant, file_length);
	}
	__int64 CreateGameVariantFromFile(char* content_item_game_variant, size_t file_length)
	{
		return (__int64)__vftable->CreateGameVariantFromFile(this, content_item_game_variant, file_length);
	}
};
