#pragma once

class c_directxtex_texture :
	public c_texture
{
public:
	c_directxtex_texture();
	c_directxtex_texture(const wchar_t* file_path);
	virtual ~c_directxtex_texture();

	virtual unsigned int get_num_layers() const override;
	virtual unsigned int get_num_mips() const override;
	virtual unsigned int get_width(unsigned int mip) const override;
	virtual unsigned int get_height(unsigned int mip) const override;
	virtual unsigned int get_depth(unsigned int mip) const override;
	virtual BCS_RESULT get_layer_data(unsigned int layer, unsigned int mip, const char*& pixel_data, size_t& pixel_data_size) override;
	virtual BCS_RESULT resize(unsigned int width, unsigned int height, unsigned int depth) override;
	virtual BCS_RESULT convert_to_graphics_data_format(e_graphics_data_format graphics_data_format) override;
	virtual BCS_RESULT generate_mips(unsigned int num_mips = UINT_MAX) override;
	virtual BCS_RESULT get_graphics_data_format(e_graphics_data_format& graphics_data_format) const override;

protected:
	DEBUG_ONLY(const wchar_t* file_path);
	const DirectX::ScratchImage* scratch_image;
};
