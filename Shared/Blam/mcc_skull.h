#pragma once

enum e_mcc_skull : uint32_t
{
	_mcc_skull_anger,
	_mcc_skull_assassins,
	_mcc_skull_bandanna,
	_mcc_skull_black_eye,
	_mcc_skull_blind,
	_mcc_skull_bonded_pair,
	_mcc_skull_boom,
	_mcc_skull_catch,
	_mcc_skull_cowbell,
	_mcc_skull_envy,
	_mcc_skull_eye_patch,
	_mcc_skull_famine,
	_mcc_skull_feather,
	_mcc_skull_fog,
	_mcc_skull_foreign,
	_mcc_skull_ghost,
	_mcc_skull_grunt_birthday_party,
	_mcc_skull_grunt_funeral,
	_mcc_skull_iron,
	_mcc_skull_iwhbyd,
	_mcc_skull_jacked,
	_mcc_skull_malfunction,
	_mcc_skull_masterblaster,
	_mcc_skull_mythic,
	_mcc_skull_pinata,
	_mcc_skull_prophet_birthday_party,
	_mcc_skull_recession,
	_mcc_skull_scarab,
	_mcc_skull_so_angry,
	_mcc_skull_sputnik,
	_mcc_skull_streaking,
	_mcc_skull_swarm,
	_mcc_skull_thats_just_wrong,
	_mcc_skull_they_come_back,
	_mcc_skull_thunderstorm,
	_mcc_skull_tilt,
	_mcc_skull_tough_luck,
	k_number_of_skulls,
	_mcc_skull_none = ~0u
};

constexpr const char* mcc_skull_to_string(e_mcc_skull skull)
{
	switch (skull)
	{
		case _mcc_skull_anger:						return "_mcc_skull_anger";
		case _mcc_skull_assassins:					return "_mcc_skull_assassins";
		case _mcc_skull_bandanna:					return "_mcc_skull_bandanna";
		case _mcc_skull_black_eye:					return "_mcc_skull_black_eye";
		case _mcc_skull_blind:						return "_mcc_skull_blind";
		case _mcc_skull_bonded_pair:				return "_mcc_skull_bonded_pair";
		case _mcc_skull_boom:						return "_mcc_skull_boom";
		case _mcc_skull_catch:						return "_mcc_skull_catch";
		case _mcc_skull_cowbell:					return "_mcc_skull_cowbell";
		case _mcc_skull_envy:						return "_mcc_skull_envy";
		case _mcc_skull_eye_patch:					return "_mcc_skull_eye_patch";
		case _mcc_skull_famine:						return "_mcc_skull_famine";
		case _mcc_skull_feather:					return "_mcc_skull_feather";
		case _mcc_skull_fog:						return "_mcc_skull_fog";
		case _mcc_skull_foreign:					return "_mcc_skull_foreign";
		case _mcc_skull_ghost:						return "_mcc_skull_ghost";
		case _mcc_skull_grunt_birthday_party:		return "_mcc_skull_grunt_birthday_party";
		case _mcc_skull_grunt_funeral:				return "_mcc_skull_grunt_funeral";
		case _mcc_skull_iron:						return "_mcc_skull_iron";
		case _mcc_skull_iwhbyd:						return "_mcc_skull_iwhbyd";
		case _mcc_skull_jacked:						return "_mcc_skull_jacked";
		case _mcc_skull_malfunction:				return "_mcc_skull_malfunction";
		case _mcc_skull_masterblaster:				return "_mcc_skull_masterblaster";
		case _mcc_skull_mythic:						return "_mcc_skull_mythic";
		case _mcc_skull_pinata:						return "_mcc_skull_pinata";
		case _mcc_skull_prophet_birthday_party:		return "_mcc_skull_prophet_birthday_party";
		case _mcc_skull_recession:					return "_mcc_skull_recession";
		case _mcc_skull_scarab:						return "_mcc_skull_scarab";
		case _mcc_skull_so_angry:					return "_mcc_skull_so_angry";
		case _mcc_skull_sputnik:					return "_mcc_skull_sputnik";
		case _mcc_skull_streaking:					return "_mcc_skull_streaking";
		case _mcc_skull_swarm:						return "_mcc_skull_swarm";
		case _mcc_skull_thats_just_wrong:			return "_mcc_skull_thats_just_wrong";
		case _mcc_skull_they_come_back:				return "_mcc_skull_they_come_back";
		case _mcc_skull_thunderstorm:				return "_mcc_skull_thunderstorm";
		case _mcc_skull_tilt:						return "_mcc_skull_tilt";
		case _mcc_skull_tough_luck:					return "_mcc_skull_tough_luck";
		case _mcc_skull_none:						return "_mcc_skull_none";
	}
	return nullptr;
}

static inline e_mcc_skull string_to_mcc_skull(const char* skull_string)
{
	for (underlying(e_mcc_skull) current_skull = 0; current_skull < k_number_of_skulls; current_skull++)
	{
		const char* current_mcc_skull_string = mcc_skull_to_string(static_cast<e_mcc_skull>(current_skull));

		if (strcmp(current_mcc_skull_string, skull_string) == 0)
		{
			return static_cast<e_mcc_skull>(current_skull);
		}
	}
	return _mcc_skull_none;
}
