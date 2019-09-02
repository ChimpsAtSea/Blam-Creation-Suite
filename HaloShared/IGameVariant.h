#pragma once

struct c_game_engine_variant;
struct __declspec(align(8)) c_game_engine_variant_vtbl
{
	__int64(__fastcall* Member00)(c_game_engine_variant*);
	void* Member01;
	void(__fastcall* Member02)(c_game_engine_variant*);
	__int64(__fastcall* Member03)(c_game_engine_variant*);
	void* Member04;
	void* Member05;
	void* Member06;
	void* Member07;
	void* Member08;
	void* Member09;
	void* Member10;
	void* Member11;
	void(__fastcall* initialize_for_new_map)(c_game_engine_variant*, __int64, c_game_engine_variant**);
	void* Member13;
	void* Member14;
	__int64(__fastcall* Member15)(c_game_engine_variant*);
	void* Member16;
	__int64(__fastcall* Member17)(c_game_engine_variant*, _QWORD, _QWORD);
	void* Member18;
	void* Member19;
	void* Member20;
	void* Member21;
	unsigned __int8(__fastcall* Member22)(c_game_engine_variant*, __int64, __int64*, unsigned __int64);
};

struct c_game_engine_variant
{
	c_game_engine_variant_vtbl* __vftable /*VFT*/;
	BYTE data[64504];
};

struct s_game_variant
{
	DWORD game_engine_index;
	c_game_engine_variant game_engine_variant;
};

struct IGameVariant;
struct /*VFT*/ IGameVariant_vtbl
{
	BYTE* (__fastcall* Member00)(IGameVariant*);
	BYTE* (__fastcall* Member01)(IGameVariant*);
	__int64(__fastcall* Member02)(IGameVariant*, wchar_t*);
	__int64(__fastcall* Member03)(IGameVariant*, wchar_t*);
	BYTE* (__fastcall* Member04)(IGameVariant*);
	__int64(__fastcall* Member05)(IGameVariant*);
	__int64(__fastcall* Member06)(IGameVariant*, struct s_unknown*);
	bool(__fastcall* IsSandboxVariant)(IGameVariant*);
	char(__fastcall* Member08)(IGameVariant*);
	__int64(__fastcall* Member09)(IGameVariant*);
	IGameVariant* (__fastcall* Create)(IGameVariant*);
	__int64(__fastcall* Member11)(IGameVariant*, struct s_unknown*, struct s_unknown*);
	__int64(__fastcall* Member12)(IGameVariant*, struct s_unknown*, struct s_unknown*);
	bool(__fastcall* Member13)(IGameVariant*, struct s_unknown*, struct s_unknown*);
	bool(__fastcall* Member14)(IGameVariant*, struct s_unknown*, struct s_unknown*);
	bool(__fastcall* Member15)(IGameVariant*, struct s_unknown*, struct s_unknown*);
	bool(__fastcall* Member16)(IGameVariant*, struct s_unknown*);
	bool(__fastcall* Member17)(IGameVariant*, struct s_unknown*);
	bool(__fastcall* Member18)(IGameVariant*, struct content_item_game_variant*, size_t*);
	void(__fastcall* Free)(IGameVariant*);
};
struct IGameVariant
{
	IGameVariant_vtbl* __vftable /*VFT*/;
	s_game_variant GameVariant;
	BYTE data[22060];
};

