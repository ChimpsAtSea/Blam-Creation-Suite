#include "fsbdump-private-pch.h"

c_fsb_validate::c_fsb_validate() 
{ 
	c_console::register_command("validatefsb", this);
}
c_fsb_validate::~c_fsb_validate() 
{ 
	c_console::unregister_command("validatefsb");
}

bool c_fsb_validate::execute_command(const std::vector<std::string>& arguments)
{
	if (!arguments.empty() && !arguments.front().compare("validatefsb"))
	{
		if (arguments.size() == 2)
		{
			write_line_verbose(arguments[1].c_str());

			size_t file_size;
			char* file_data;
			{
				wchar_t filepath_buffer[MAX_PATH + 1]{};
				_swprintf(filepath_buffer, L"%S", arguments[1].c_str());
				file_data = FileSystemReadToMemory(filepath_buffer, &file_size);
			}

			if (file_data == nullptr)
			{
				c_console::set_text_color(_console_color_error);
				write_line_verbose("Failed to open Fmod Sound Bank file");
				c_console::set_text_color(_console_color_info);
				return true;
			}

			if (file_size == 0)
			{
				c_console::set_text_color(_console_color_error);
				write_line_verbose("Failed to open Fmod Sound Bank file size was 0");
				c_console::set_text_color(_console_color_info);
				return true;
			}

			e_sound_bank_version sound_bank_version = c_sound_bank_manager::get_sound_bank_version(file_data, file_size);
			if (sound_bank_version == _sound_bank_version_unsupported)
			{
				c_console::set_text_color(_console_color_error);
				write_line_verbose("Unrecognized Fmod Sound Bank file format");
				c_console::set_text_color(_console_color_info);
				return true;
			}

			c_console::set_text_color(_console_color_info);
			char sound_bank_version_str_buffer[sizeof(unsigned long) + 1]{};
			*reinterpret_cast<unsigned long*>(sound_bank_version_str_buffer) = _byteswap_ulong(sound_bank_version);
			write_line_verbose("Fmod Sound Bank file version: '%s'", sound_bank_version_str_buffer);

			delete file_data;
		}
		else return false;
	}
	return true;
}

std::string c_fsb_validate::get_command_info(const std::string& topic) const
{
	return
		"Determines if a Fmod Sound Bank file is valid\n"
		"Usage: fsbvalidate <filepath>";
}
