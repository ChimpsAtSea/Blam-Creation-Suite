#pragma once

/* ---------- types */

namespace infinite
{
	struct s_module_block_entry
	{
		//unsigned long long checksum;			// Murmur3_x64_128 hash of the uncompressed block data(the upper 64 bits are discarded)
		unsigned long compressed_offset;		// The offset of this block relative to the start of the file's compressed data.
		unsigned long compressed_size;			// The size of the compressed data.
		unsigned long uncompressed_offset;		// The offset of the block's uncompressed data in the uncompressed file.
		unsigned long uncompressed_size;		// The size of the block's data after it is uncompressed.
		bool compressed;						// true if the block data is compressed using ZLib, false if it should just be read verbatim
		//long padding1C;							// (Padding)
	};
	static_assert(sizeof(s_module_block_entry) == 0x14);

	struct s_module_resource_entry
	{
		unsigned long data;
	};
	static_assert(sizeof(s_module_resource_entry) == 0x4);

	enum e_module_file_flags
	{
		_module_file_flag_compressed, // The file uses compression.
		_module_file_flag_has_blocks, // The blockCount and firstBlockIndex fields are valid.If this is not set, then the file only has one block which can be inferred from the fields in the struct.
		_module_file_flag_raw_file, // The file is not split into header / tag data / resource sections and should be read in its entirety.
		_module_file_flag_unknown_bit3,
		_module_file_flag_unknown_bit4,
		_module_file_flag_unknown_bit5,
		_module_file_flag_unknown_bit6,
		_module_file_flag_unknown_bit7,
		k_num_module_file_flags
	};
	using c_module_file_flags = c_flags<e_module_file_flags, unsigned char, k_num_module_file_flags>;

	struct s_module_file_entry
	{
		long name_offset;								// Offset of the filename in the filename data
		long parent_file_index;							// Used with resources to point back to the parent file. - 1 = none
		short resource_count;							// Number of resources this file owns
		short block_count;								// The number of blocks that make up the file.Only valid if the HasBlocks flag is set(see below).
		long firstResource_index;						// Index of the first resource in the module's resource list that this file owns (see the Resource List section below).
		long first_block_index;							//The index of the first block in the file.Only valid if the HasBlocks flag is set(see below).
		long group_tag;									// If the file is a tag, this holds the group tag of the file(e.g.bipd).
		unsigned long data_offset;						// The offset of the first block in the file, relative to the start of the data area in the module.This area follows the block list.
		unsigned char unknown0; // is data offset a packed integer of 48 bits?
		unsigned char unknown1; // is data offset a packed integer of 48 bits?
		unsigned char data_file_index;
		unsigned char unknown_index;

		unsigned long total_compressed_size;			// The total size of compressed data.
		unsigned long total_uncompressed_size;			// The total size of the data after it is uncompressed.If this is 0, then the file is empty.
		//long global_tag_id;							// The global tag ID(-1 if not a tag).
		long long asset_id;								// The asset ID(-1 if not a tag).
		unsigned long long asset_checksum64;			// Murmur3_x64_128 hash of(what appears to be) the original file that this file was built from. This is not always the same thing as the file stored in the module. Only verified if the HasBlocks flag is not set.
		long asset_checksum32;							// Lower 32bits of 64bit hash
		unsigned long uncompressed_header_data_size;	// The size of the file's uncompressed header.
		unsigned long uncompressed_tag_data_size;		// The size of the file's uncompressed tag data.
		unsigned long uncompressed_resource_data_size;	// The size of the file's uncompressed resource data.
		long unknown_data_size;

		unsigned char header_data_alignment;			// Power of 2 to align the header buffer to(e.g. 4 = align to a multiple of 16 bytes).
		unsigned char tag_data_alignment;				// Power of 2 to align the tag data buffer to.
		unsigned char resource_data_alignment;			// Power of 2 to align the resource data buffer to.
		unsigned char unknown_data_alignment;

		unsigned char unknown_count50;
		unsigned char unknown_count51;
		c_module_file_flags flags;						// See "File Entry Flags" below.

		long padding54;
	};
	static_assert(sizeof(s_module_file_entry) == 0x58);

	struct s_module_file_header
	{																// forge objects rtx new		// mainmenu rtx new
		tag header_signature; // k_cache_header_signature			// 6D 6F 68 64					//6D 6F 68 64 
		long file_version;											// 30 00 00 00 					//30 00 00 00 
		long long module_id;										// 65 76 5B 8A 					//F2 2A 69 8E
																	// 61 38 34 76 					//77 D4 64 65
		long num_files;												// A6 8D 00 00 					//A1 01 00 00 
		long unknown14;												// FF FF FF FF 					//FF FF FF FF 
		long num_loaded_tags;										// 00 00 00 00 					//00 00 00 00
		long unknown20;												// FF FF FF FF					//FF FF FF FF
		long first_resource_index;									// 65 1A 00 00 					//9B 01 00 00
		long string_table_length;									// 7E 43 58 00 					//2F BE 00 00
		long num_resources;											// 41 73 00 00 					//06 00 00 00
		long num_file_blocks;										// E9 A2 00 00 					//40 03 00 00
		long long build_version;									// 7C FE 1E 98 					//7C FE 1E 98
																	// 45 22 8E DC 					//45 22 8E DC
		long total_data_size;										// 00 F0 BF A1 					//00 00 00 00
		long unknown3C;												// 00 00 00 00 					//00 00 00 00
		long unknown40;												// 02 00 00 00 					//02 00 00 00
		long unknown44;												// 00 00 00 00 					//00 00 00 00
	};
	static_assert(sizeof(s_module_file_header) == 0x48);
}
