#pragma once

class c_texture
{
public:
	virtual ~c_texture();

	virtual unsigned int get_num_layers() const = 0;
	virtual unsigned int get_num_mips() const = 0;
	virtual unsigned int get_width(unsigned int mip) const = 0;
	virtual unsigned int get_height(unsigned int mip) const = 0;
	virtual unsigned int get_depth(unsigned int mip) const = 0;
	virtual BCS_RESULT get_layer_data(unsigned int layer, unsigned int mip, const char*& pixel_data, size_t& pixel_data_size) = 0;
	virtual BCS_RESULT resize(unsigned int width, unsigned int height, unsigned int depth) = 0;
	virtual BCS_RESULT convert_to_graphics_data_format(e_graphics_data_format graphics_data_format) = 0;
	virtual BCS_RESULT generate_mips(unsigned int num_mips = UINT_MAX) = 0;
	virtual BCS_RESULT get_graphics_data_format(e_graphics_data_format& graphics_data_format) const = 0;
};

BCS_DEBUG_API BCS_RESULT texture_load_from_file(const wchar_t* file_path, c_texture*& texture);
BCS_DEBUG_API BCS_RESULT texture_destroy(c_texture* texture);
