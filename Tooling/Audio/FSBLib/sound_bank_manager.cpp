#include "fsblib-private-pch.h"

e_sound_bank_version c_sound_bank_manager::get_sound_bank_version(char* sound_bank_memory, size_t sound_bank_size)
{
	if (sound_bank_size > sizeof(e_sound_bank_version))
	{
		e_sound_bank_version sound_bank_version = static_cast<e_sound_bank_version>(_byteswap_ulong(*reinterpret_cast<unsigned long*>(sound_bank_memory)));
		switch (sound_bank_version)
		{
		case _sound_bank_version_fsb1:
		case _sound_bank_version_fsb2:
		case _sound_bank_version_fsb3:
		case _sound_bank_version_fsb4:
		case _sound_bank_version_fsb5:
			return sound_bank_version;
		}
	}
	return _sound_bank_version_unsupported;
}

c_sound_bank_manager::c_sound_bank_manager(char* sound_bank_memory, size_t sound_bank_size) : 
	sound_bank_memory(sound_bank_memory),
	sound_bank_size(sound_bank_size)
{
	


}


