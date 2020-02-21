#pragma once

enum e_skull : uint32_t
{
	_skull_anger,
	_skull_assassins,
	_skull_bandanna,
	_skull_black_eye,
	_skull_blind,
	_skull_bonded_pair,
	_skull_boom,
	_skull_catch,
	_skull_cowbell,
	_skull_envy,
	_skull_eye_patch,
	_skull_famine,
	_skull_feather,
	_skull_fog,
	_skull_foreign,
	_skull_ghost,
	_skull_grunt_birthday_party,
	_skull_grunt_funeral,
	_skull_iron,
	_skull_iwhbyd,
	_skull_jacked,
	_skull_malfunction,
	_skull_masterblaster,
	_skull_mythic,
	_skull_pinata,
	_skull_prophet_birthday_party,
	_skull_recession,
	_skull_scarab,
	_skull_so_angry,
	_skull_sputnik,
	_skull_streaking,
	_skull_swarm,
	_skull_thats_just_wrong,
	_skull_they_come_back,
	_skull_thunderstorm,
	_skull_tilt,
	_skull_tough_luck,
	k_number_of_skulls,
	_skull_none = ~0u
};

static constexpr const char* skull_to_string(e_skull skull)
{
	switch (skull)
	{
		case _skull_anger:						return "_skull_anger";
		case _skull_assassins:					return "_skull_assassins";
		case _skull_bandanna:					return "_skull_bandanna";
		case _skull_black_eye:					return "_skull_black_eye";
		case _skull_blind:						return "_skull_blind";
		case _skull_bonded_pair:				return "_skull_bonded_pair";
		case _skull_boom:						return "_skull_boom";
		case _skull_catch:						return "_skull_catch";
		case _skull_cowbell:					return "_skull_cowbell";
		case _skull_envy:						return "_skull_envy";
		case _skull_eye_patch:					return "_skull_eye_patch";
		case _skull_famine:						return "_skull_famine";
		case _skull_feather:					return "_skull_feather";
		case _skull_fog:						return "_skull_fog";
		case _skull_foreign:					return "_skull_foreign";
		case _skull_ghost:						return "_skull_ghost";
		case _skull_grunt_birthday_party:		return "_skull_grunt_birthday_party";
		case _skull_grunt_funeral:				return "_skull_grunt_funeral";
		case _skull_iron:						return "_skull_iron";
		case _skull_iwhbyd:						return "_skull_iwhbyd";
		case _skull_jacked:						return "_skull_jacked";
		case _skull_malfunction:				return "_skull_malfunction";
		case _skull_masterblaster:				return "_skull_masterblaster";
		case _skull_mythic:						return "_skull_mythic";
		case _skull_pinata:						return "_skull_pinata";
		case _skull_prophet_birthday_party:		return "_skull_prophet_birthday_party";
		case _skull_recession:					return "_skull_recession";
		case _skull_scarab:						return "_skull_scarab";
		case _skull_so_angry:					return "_skull_so_angry";
		case _skull_sputnik:					return "_skull_sputnik";
		case _skull_streaking:					return "_skull_streaking";
		case _skull_swarm:						return "_skull_swarm";
		case _skull_thats_just_wrong:			return "_skull_thats_just_wrong";
		case _skull_they_come_back:				return "_skull_they_come_back";
		case _skull_thunderstorm:				return "_skull_thunderstorm";
		case _skull_tilt:						return "_skull_tilt";
		case _skull_tough_luck:					return "_skull_tough_luck";
		case _skull_none:						return "_skull_none";
	}
	return nullptr;
}

static inline e_skull string_to_skull(const char* skull_string)
{
	for (underlying(e_skull) current_skull = 0; current_skull < k_number_of_skulls; current_skull++)
	{
		const char* current_skull_string = skull_to_string(static_cast<e_skull>(current_skull));

		if (strcmp(current_skull_string, skull_string) == 0)
		{
			return static_cast<e_skull>(current_skull);
		}
	}
	return _skull_none;
}
