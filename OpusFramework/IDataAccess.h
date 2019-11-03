#pragma once

struct IDataAccess;
struct IDataAccess_vtbl
{
	void(__fastcall* Free)(IDataAccess*);

	IMapVariant* (__fastcall* MapVariantCreateFromFile)(IDataAccess*, /*struct content_item_map_variant **/char*, size_t);
	IMapVariant* (__fastcall* MapVariantCreateFromMapId)(IDataAccess*, __int64);
	IMapVariant* (__fastcall* MapVariantCreateDefault)(IDataAccess*, /*struct s_map_variant**/char *);

	IGameVariant* (__fastcall* GameVariantCreateFromFile)(IDataAccess*, /*struct content_item_game_variant **/char*, size_t);
	IGameVariant* (__fastcall* GameVariantCreateDefault)(IDataAccess*, __int64);

	bool(__fastcall* Member05)(IDataAccess*, struct s_unknown*, void*); // load map?

	ISaveFilmMetadata* (__fastcall* SaveFilmMetadataCreateFromFile)(IDataAccess*, /*struct content_item_film_description **/char*, size_t);
};

struct IDataAccess
{
	IDataAccess_vtbl* __vftable /*VFT*/;
	void* c_heap_allocation;
	void* function1;
	void* c_heap_allocation_size;
	void* function3;

	IMapVariant* MapVariantCreateFromMapId(__int64 map_id)
	{
		return __vftable->MapVariantCreateFromMapId(this, map_id);
	}

	IMapVariant* MapVariantCreateFromFile(char *content_item_map_variant, size_t file_length)
	{
		return __vftable->MapVariantCreateFromFile(this, content_item_map_variant, file_length);
	}
	IGameVariant* GameVariantCreateFromFile(char *content_item_game_variant, size_t file_length)
	{
		return __vftable->GameVariantCreateFromFile(this, content_item_game_variant, file_length);
	}
	ISaveFilmMetadata* SaveFilmMetadataCreateFromFile(char *content_item_film_description, size_t file_length)
	{
		return __vftable->SaveFilmMetadataCreateFromFile(this, content_item_film_description, file_length);
	}
};
