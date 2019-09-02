#pragma once

struct ISaveFilmMetadata;
struct /*VFT*/ ISaveFilmMetadata_vtbl
{
	__int64(__fastcall* Member00)(ISaveFilmMetadata*);
	__int64(__fastcall* Member01)(ISaveFilmMetadata*);
	__int64(__fastcall* GetMapId)(ISaveFilmMetadata*);
	BYTE* (__fastcall* Member03)(ISaveFilmMetadata*);
	BYTE* (__fastcall* Member04)(ISaveFilmMetadata*);
	BYTE* (__fastcall* Member05)(ISaveFilmMetadata*);
	void(__fastcall* Free)(ISaveFilmMetadata*);
};
struct ISaveFilmMetadata
{
	ISaveFilmMetadata_vtbl* __vftable /*VFT*/;
	BYTE data[128936];
};
