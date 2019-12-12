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
	char data[64504];
};

enum e_game_engine_type : DWORD
{
	_game_engine_type_none,
	_game_engine_type_sandbox,
	_game_engine_type_megalo,
	_game_engine_type_campaign,
	_game_engine_type_survival,
	k_number_of_game_engine_types
};

#pragma pack(push, 1)
struct s_game_variant
{
	e_game_engine_type game_engine_index;
	c_game_engine_variant game_engine_variant;
};
#pragma pack(pop)

class IGameVariant : public IVariantAccessorBase
{
public:
	virtual bool Function9() = 0;
	virtual INT32 GetID() = 0;
	virtual bool Function11() = 0;
	virtual UINT8 Function12() = 0;
	virtual UINT32 Function13() = 0;
	virtual IGameVariant *Reset() = 0;
	virtual INT32 Function15(LPVOID, LPVOID) = 0;
	virtual UINT32 Function16(LPVOID, LPVOID) = 0;
	virtual bool Function17(LPVOID, LPVOID) = 0;
	virtual bool Function18(LPVOID, LPVOID) = 0;
	virtual bool Function19(LPVOID, LPVOID) = 0;
	virtual INT32 Function20() = 0;
	virtual bool Function21(INT32) = 0;

	s_game_variant GameVariant;
	BYTE data[22060];
};