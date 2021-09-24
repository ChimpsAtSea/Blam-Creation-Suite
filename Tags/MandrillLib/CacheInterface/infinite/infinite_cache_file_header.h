#pragma once

/* ---------- types */

namespace infinite
{
	struct s_module_block_entry
	{
		//unsigned long long checksum;			// Murmur3_x64_128 hash of the uncompressed block data(the upper 64 bits are discarded)
		unsigned long read_offset;				// The offset of this block relative to the start of the file's compressed data.
		unsigned long compressed_size;			// The size of the compressed data.
		unsigned long write_offset;		// The offset of the block's uncompressed data in the uncompressed file.
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

	struct s_module_file_packed_data_offset
	{
		unsigned long long data_offset : 48; // If the file is a tag, this holds the group tag of the file(e.g.bipd).
		unsigned long long data_file_index : 8; // The offset of the first block in the file, relative to the start of the data area in the module.This area follows the block list.
		unsigned long long unknown_index : 8;
	};
	static_assert(sizeof(s_module_file_packed_data_offset) == 0x8);

	struct s_module_file_entry_48
	{
		unsigned long name_offset;						// Offset of the filename in the filename data
		long parent_file_index;							// Used with resources to point back to the parent file. - 1 = none
		unsigned short resource_count;					// Number of resources this file owns
		unsigned short block_count;						// The number of blocks that make up the file.Only valid if the HasBlocks flag is set(see below).
		unsigned long first_resource_index;				// Index of the first resource in the module's resource list that this file owns (see the Resource List section below).
		unsigned long first_block_index;				//The index of the first block in the file.Only valid if the HasBlocks flag is set(see below).
		tag group_tag;									
		s_module_file_packed_data_offset packed_data_offset;

		unsigned long compressed_size;					// The total size of compressed data.
		unsigned long uncompressed_size;				// The total size of the data after it is uncompressed.If this is 0, then the file is empty.
		long long asset_id;								// The asset ID(-1 if not a tag).
		long long global_tag_id64;						// Murmur3_x64_128 hash of(what appears to be) the original file that this file was built from. This is not always the same thing as the file stored in the module. Only verified if the HasBlocks flag is not set.
		long global_tag_id;							// Lower 32bits of 64bit hash
		unsigned long header_data_size;					// The size of the file's uncompressed header.
		unsigned long tag_data_size;					// The size of the file's uncompressed tag data.
		unsigned long resource_data_size;				// The size of the file's uncompressed resource data.
		unsigned long unknown_data_size;		

		unsigned char header_data_alignment;			// Power of 2 to align the header buffer to(e.g. 4 = align to a multiple of 16 bytes).
		unsigned char tag_data_alignment;				// Power of 2 to align the tag data buffer to.
		unsigned char resource_data_alignment;			// Power of 2 to align the resource data buffer to.
		unsigned char unknown_data_alignment;

		unsigned char unknown_count50;
		unsigned char unknown_count51;
		c_module_file_flags flags;						// See "File Entry Flags" below.

		long padding54;
	};
	static_assert(sizeof(s_module_file_entry_48) == 0x58);

	struct s_module_file_entry_51
	{
		unsigned long unknown0;									// 02 00 00 00 0x00000002			00 00 00 00 0x00000000			00 00 00 00 0x00000000   
		unsigned long unknown4;									// 00 00 00 00 0x00000000			00 00 00 00 0x00000000			00 00 00 00 0x00000000 

		//unsigned long unknown8;								// 00 05 00 00			05 03 02 00			05 03 02 00 
		unsigned char unknown8;
		unsigned char resource_count;
		unsigned char block_count;
		unsigned char unknownB;

		unsigned long first_block_index;						// 00 00 00 00 0x00000000		00 00 00 00 0x00000000		02 00 00 00 0x00000002
		unsigned long first_resource_index;						// 00 00 00 00 0x00000000		00 00 00 00 0x00000000		00 00 00 00 0x00000000
		tag group_tag;											// FF FF FF FF 0xFFFFFFFF		67 66 63 77 0x77636667		69 77 69 75 0x75697769
		s_module_file_packed_data_offset packed_data_offset;	// 00 00 00 00 0x00000000		00 80 01 00 0x00018000		00 90 01 00 0x00019000
																// 00 00 00 00 0x00000000		00 00 00 5D 0x5D000000		00 00 00 64 0x64000000
																// 00 00 00 00 0x00000000		00 00 00 5D 0x5D000000		00 00 00 64 0x64000000
		unsigned long compressed_size;							// 33 77 01 00 0x00017733		14 02 00 00 0x00000214		E3 01 00 00 0x000001E3
		unsigned long uncompressed_size;						// F3 71 05 00 0x000571F3		F6 03 00 00 0x000003F6		8B 02 00 00 0x0000028B
		unsigned long global_tag_id;							// FF FF FF FF 0xFFFFFFFF		5C 64 AE 90 0x90AE645C		5A F0 00 95 0x9500F05A
		unsigned long header_data_size;							// 00 00 00 00 0x00000000		86 02 00 00 0x00000286		C7 01 00 00 0x000001C7
		unsigned long tag_data_size;							// 00 00 00 00 0x00000000		70 01 00 00 0x00000170		C4 00 00 00 0x000000C4
		unsigned long resource_data_size;						// 00 00 00 00 0x00000000		00 00 00 00 0x00000000		00 00 00 00 0x00000000
		unsigned long unknown_data_size;						// 00 00 00 00 0x00000000		00 00 00 00 0x00000000		00 00 00 00 0x00000000

		//unsigned long unknown3C;								// 00 00 00 00 0x00000000		00 02 00 00 0x00000200		00 02 00 00 0x00000200
		unsigned char header_data_alignment;					// Power of 2 to align the header buffer to(e.g. 4 = align to a multiple of 16 bytes).
		unsigned char tag_data_alignment;						// Power of 2 to align the tag data buffer to.
		unsigned char resource_data_alignment;					// Power of 2 to align the resource data buffer to.
		unsigned char unknown_data_alignment;

		unsigned long name_offset;								// 00 00 00 00 0x00000000		14 00 00 00 0x00000014		6F 00 00 00 0x0000006F
		long parent_file_index;									// FF FF FF FF 0xFFFFFFFF		FF FF FF FF 0xFFFFFFFF		FF FF FF FF 0xFFFFFFFF
		long long asset_id;										// 35 D0 49 1E 0x1E49D035		3B 20 C0 02 0x02C0203B		72 3D 3B 38 0x383B3D72
																// 7B 5B CF 6F 0x6FCF5B7B		C4 BC A8 E3 0xE3A8BCC4		10 30 72 48 0x48723010
		long long global_tag_id64;								// FF FF FF FF 0xFFFFFFFF		5C 64 AE 90 0x90AE645C		5A F0 00 95 0x9500F05A
																// FF FF FF FF 0xFFFFFFFF		8C F4 DA 5A 0x5ADAF48C		1B 77 A6 C1 0xC1A6771B
	};
	static_assert(sizeof(s_module_file_entry_51) == 0x58);

	struct s_module_file_header_base
	{
		tag header_signature; // k_cache_header_signature			
		long file_version;
	};

	struct s_module_file_header :
		public s_module_file_header_base
	{
		long long module_id;

		long num_files;
		long unknown14;
		long num_loaded_tags;
		long unknown20;
		long first_resource_index;
		long string_table_length;
		long num_resources;
		long num_file_blocks;
		long long build_version;

		long total_data_size;
		long unknown3C;
		long unknown40;
		long unknown44;
	};
	static_assert(sizeof(s_module_file_header) == 0x48);
}
