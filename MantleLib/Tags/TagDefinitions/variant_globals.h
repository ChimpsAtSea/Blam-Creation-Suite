#pragma once

struct nicename("variant_globals") group('vtgl') s_variant_globals_definition
{
	struct nicename("Map Variants") s_map_variants_definition
	{
		DataReference nicename("Raw Header") raw_header_data_reference;
		DataReference nicename("Raw MVAR") raw_mvar_data_reference;
		char nicename("File Name") file_name[256];
	};

	struct nicename("Megalo Variants") s_megalo_variants_definition
	{
		DataReference nicename("Raw Header") raw_header_data_reference;
		DataReference nicename("Raw MPVR") raw_mpvr_data_reference;
		char nicename("File Name") file_name[256];
	};

	/* Map Variants : Raw Header is the initial bytes of the MVAR chunk starting at x24 up to the end of the description (shift right 16 bits to read description) and the 00 00 terminator after it.
	   Raw MVAR is the entire MVAR chunk starting x24 in. The chunk size for the MVAR is used for the size of the dataref and is found at x20 in MVAR, just before the start of the data. */
	s_tag_block_definition<s_map_variants_definition> nicename("Map Variants") map_variants1_block;
	/* Megalo Variants : Raw Header is the initial bytes of the MPVR chunk starting at x30 and a half (remove first half of byte at x30) up to the end of the description (shift right 16 bits to read description) and the 00 80 terminator after it, plus one more byte.
	   Raw MPVR is the entire MVAR chunk starting x28 and a half (remove first half of byte at x28). The chunk size for the MVAR is used for the size of the dataref and is found at x24 in MVAR, just before the start of the data, minus 1. */
	s_tag_block_definition<s_megalo_variants_definition> nicename("Megalo Variants") megalo_variants1_block;
};

