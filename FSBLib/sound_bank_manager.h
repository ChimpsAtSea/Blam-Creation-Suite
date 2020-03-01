#pragma once

enum e_sound_bank_version : uint32_t
{
	_sound_bank_version_unsupported,
	_sound_bank_version_fsb1 = 'FSB1',
	_sound_bank_version_fsb2 = 'FSB2',
	_sound_bank_version_fsb3 = 'FSB3',
	_sound_bank_version_fsb4 = 'FSB4',
	_sound_bank_version_fsb5 = 'FSB5',
};

class c_sound_bank_manager
{
public:
	c_sound_bank_manager(char* sound_bank_memory, size_t sound_bank_size);
	static e_sound_bank_version get_sound_bank_version(char* sound_bank_memory, size_t sound_bank_size);

private:
	char* sound_bank_memory;
	size_t sound_bank_size;
};

