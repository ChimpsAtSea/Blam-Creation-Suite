#pragma once

class c_halo3odst_cache_file :
	public c_gen3_cache_file
{
	friend c_cache_file;
protected:
	c_halo3odst_cache_file(const std::wstring& map_filepath);
	virtual ~c_halo3odst_cache_file();

public:
	virtual bool save_map() final;
	virtual uint64_t get_base_virtual_address() const final;
	virtual uint64_t convert_page_offset(uint32_t page_offset) const final;

protected:
	halo3odst::s_cache_file_header& halo3odst_cache_file_header;
	halo3odst::s_cache_file_tags_header* halo3odst_cache_file_tags_header;
};
