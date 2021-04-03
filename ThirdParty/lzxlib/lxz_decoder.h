#pragma once

class c_lxz_decoder
{
public:
	c_lxz_decoder(unsigned short window_bits);
	c_lxz_decoder(const c_lxz_decoder&) = delete;
	c_lxz_decoder& operator=(const c_lxz_decoder&) = delete;
	~c_lxz_decoder();
	void decompress(
		const unsigned char* const compressed_buffer,
		unsigned long const compressed_buffer_length,
		unsigned char* uncompressed_buffer,
		const unsigned long uncompressed_buffer_length);

private:
	static constexpr unsigned short k_min_match = 2;
	static constexpr unsigned short k_max_match = 257;
	static constexpr unsigned short k_num_chars = 256;
	static constexpr unsigned short k_pre_tree_num_elements = 20;
	static constexpr unsigned short k_aligned_num_elements = 8;
	static constexpr unsigned short k_num_primary_lengths = 7;
	static constexpr unsigned short k_num_secondary_lengths = 249;

	static constexpr unsigned short k_pre_tree_max_symbols = k_pre_tree_num_elements;
	static constexpr unsigned short m_main_tree_max_symbols = k_num_chars + 50 * 8;
	static constexpr unsigned short k_length_max_symbols = k_num_secondary_lengths + 1;
	static constexpr unsigned short k_aligned_max_symbols = k_aligned_num_elements;

	static constexpr unsigned char k_pre_tree_bits = 6;
	static constexpr unsigned char k_main_tree_bits = 12;
	static constexpr unsigned char k_length_table_bits = 12;
	static constexpr unsigned char k_aligned_table_bits = 7;

	void make_decode_table(unsigned short num_symbols, unsigned char num_bits, unsigned char* length, unsigned short* table);
	void read_lengths(unsigned char* lens, unsigned long first, unsigned long last);
	unsigned long read_huffman_symbols(const unsigned short* table, const unsigned char* lengths, unsigned long num_symbols, unsigned char num_bits);

	static long const position_base_minus2[];
	static unsigned char const extra_bits[];
	//unsigned long position_base[51];
	//unsigned char extra_bits[52];

	enum class e_block_type : unsigned char
	{
		_lxz_block_type_invalid,
		_lxz_block_type_verbatim,
		_lxz_block_type_aligned,
		_lxz_block_type_uncompressed,
	};

	unsigned char* window;
	unsigned long window_size;
	unsigned long window_posn;

	unsigned long R0;
	unsigned long R1;
	unsigned long R2;
	unsigned short main_elements; // number of main tree elements
	bool header_read; // have we started decoding at all yet?
	e_block_type block_type; // type of this block
	unsigned long block_length; // uncompressed length of this block
	unsigned long block_remaining; // uncompressed bytes still left to decode

	void init_bits(const unsigned char* input_buffer);
	void ensure_bits(unsigned char bits);
	unsigned long peek_bits(unsigned char bits) const;
	void remove_bits(unsigned char bits);
	unsigned long read_bits(unsigned char bits);

	unsigned long bit_buffer_buffer;
	unsigned char bit_buffer_bits_left;
	unsigned long bit_buffer_input_position;
	const unsigned char* bit_buffer_input_buffer;

	unsigned char MAINTREE_len[m_main_tree_max_symbols];
	unsigned char LENGTH_len[k_length_max_symbols];
	unsigned char ALIGNED_len[k_aligned_max_symbols];
	unsigned short PRETREE_table[(1 << k_pre_tree_bits) + (k_pre_tree_max_symbols * 2)];
	unsigned short MAINTREE_table[(1 << k_main_tree_bits) + (m_main_tree_max_symbols * 2)];
	unsigned short LENGTH_table[(1 << k_length_table_bits) + (k_length_max_symbols * 2)];
	unsigned short ALIGNED_table[(1 << k_aligned_table_bits) + (k_aligned_max_symbols * 2)];
};
