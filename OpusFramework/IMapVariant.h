#pragma once

struct s_map_variant
{
	char data[55724];
};

struct IMapVariant;
struct /*VFT*/ IMapVariant_vtbl
{
	void(__fastcall* Free)(IMapVariant*);
	__int64(__fastcall* GetMCCMapId)(IMapVariant*);
	bool(__fastcall* Member01)(IMapVariant*);
	BYTE* (__fastcall* Member02)(IMapVariant*);
	BYTE* (__fastcall* Member03)(IMapVariant*);
	__int64(__fastcall* Member04)(IMapVariant*, wchar_t*);
	__int64(__fastcall* Member05)(IMapVariant*, wchar_t*);
	BYTE* (__fastcall* Member06)(IMapVariant*, struct s_unknown*);
	bool(__fastcall* Member07)(IMapVariant*, struct s_unknown*);
	bool(__fastcall* Member08)(IMapVariant*, struct s_unknown*);
	bool(__fastcall* Member09)(IMapVariant*, struct content_item_map_variant*, size_t*);
};
struct IMapVariant
{
	IMapVariant_vtbl* __vftable /*VFT*/;
	s_map_variant MapVariant;
	BYTE data[29484];
};

