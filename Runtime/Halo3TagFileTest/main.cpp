#include "halo3tagfiletest-private-pch.h"

#ifdef _DEBUG
static constexpr const char window_title[] = "Halo 3 Tag File Test Debug";
#else
static constexpr const char window_title[] = "Halo 3 Tag File Test";
#endif

static c_window* window;
static c_render_context* window_render_context;
static c_mandrill_user_interface* mandrill_user_interface;

static float4 graphics_background_color = { 0.16f, 0.10f, 0.16f, 1.0f };
static float4 window_background_color = { 0.130f, 0.141f, 0.167f, 1.0f };


#include <HighLevel/high_level_halo3/highlevel-halo3-public-pch.h>

class c_tag_file_high_level_transplant
{
public:
	class c_chunk
	{
	public:
		c_tag_file_high_level_transplant& high_level_transplant;
		unsigned long const literal;
		unsigned long const version;
		unsigned long const size;
		unsigned long const depth;
		c_chunk* const parent;
		std::vector<c_chunk*> children;
		char* const chunk_header_data;
		char* chunk_data_start;
		char* const chunk_data_end;
		char short_name[5];

		c_chunk(c_tag_file_high_level_transplant& high_level_transplant, char* chunk_header_data, c_chunk* parent, bool parse_children) :
			high_level_transplant(high_level_transplant),
			literal(*reinterpret_cast<unsigned long*>(chunk_header_data)),
			version(*reinterpret_cast<unsigned long*>(chunk_header_data + 4)),
			size(*reinterpret_cast<unsigned long*>(chunk_header_data + 8)),
			depth(parent ? parent->depth + 1 : 0),
			parent(parent),
			children(),
			chunk_header_data(chunk_header_data),
			chunk_data_start(chunk_header_data + 12),
			chunk_data_end(chunk_data_start + size),
			short_name{ chunk_header_data[3],chunk_header_data[2],chunk_header_data[1],chunk_header_data[0],0 }
		{
			log();

			if (parse_children)
			{
				this->parse_children();
			}
		}

		void log_pad()
		{
			for (unsigned long i = 0; i < depth; i++)
			{
				printf("  ");
			}
		}

		void log()
		{
			log_pad();
			log_impl();

			for (c_chunk* child : children)
			{
				child->log();
			}
		}

		static c_chunk* create_data_chunk(c_tag_file_high_level_transplant& high_level_transplant, char* data, c_chunk* parent);

		void parse_children()
		{
			for (char* data_position = chunk_data_start; data_position < chunk_data_end;)
			{
				c_chunk* chunk = create_data_chunk(high_level_transplant, data_position, this);
				data_position = chunk->chunk_data_end;
				children.push_back(chunk);
			}
		}

		virtual void log_impl()
		{
			printf("%.4s\n", short_name);
		}

		c_chunk* find_first_chunk(unsigned long type)
		{
			for (c_chunk* chunk : children)
			{
				if (chunk->literal == type)
				{
					return chunk;
				}
				c_chunk* child_search_result = chunk->find_first_chunk(type);
				if (child_search_result)
				{
					return child_search_result;
				}
			}
			return nullptr;
		}

		c_chunk* get_chunk(unsigned long index)
		{
			return children[index];
		}

		template<typename t_chunk>
		t_chunk* find_first_chunk()
		{
			return static_cast<t_chunk*>(find_first_chunk(t_chunk::type));
		}

		inline unsigned long get_child_count() const { return static_cast<unsigned long>(children.size()); }

		template<typename t_chunk>
		t_chunk* get_chunk(unsigned long index)
		{
			return static_cast<t_chunk*>(get_chunk(index));
		}
	};
	template<unsigned long _type, bool _parse_children = true>
	class c_typed_chunk : public c_chunk
	{
	public:
		static constexpr unsigned long type = _type;

		c_typed_chunk(c_tag_file_high_level_transplant& high_level_transplant, char* chunk_header_data, c_chunk* parent, bool parse_children = _parse_children) :
			c_chunk(high_level_transplant, chunk_header_data, parent, parse_children)
		{

		}
	};
	class c_tag_header_chunk : public c_typed_chunk<'tag!'>
	{
	public:
		c_tag_header_chunk(c_tag_file_high_level_transplant& high_level_transplant, char* chunk_header_data, c_chunk* parent) :
			c_typed_chunk(high_level_transplant, chunk_header_data, parent, true)
		{
			debug_point;
			high_level_transplant.root_chunk = this;
		}
	};
	struct s_tag_group_layout_header
	{
		unsigned long unknown;
		char guid[16];
		unsigned long unknown14;
		unsigned long tag_group_block_index;
		unsigned long string_data_size;
		unsigned long string_offset_count;
		unsigned long string_list_count;
		unsigned long custom_block_index_search_names_count;
		unsigned long data_definition_name_count;
		unsigned long array_definition_count;
		unsigned long tag_field_type_count;
		unsigned long field_count;
		unsigned long block_definition_count;
		unsigned long struct_definition_count;
		unsigned long resource_definition_count;
		unsigned long interop_definition_count;
	};
	static_assert(sizeof(s_tag_group_layout_header) == 0x4C);
	class c_tag_group_layout_chunk : public c_typed_chunk<'blay'>
	{
	public:
		s_tag_group_layout_header* tag_group_layout_header;
		c_tag_group_layout_chunk(c_tag_file_high_level_transplant& high_level_transplant, char* chunk_header_data, c_chunk* parent) :
			c_typed_chunk(high_level_transplant, chunk_header_data, parent, false),
			tag_group_layout_header(reinterpret_cast<s_tag_group_layout_header*>(chunk_data_start))
		{
			debug_point;
			chunk_data_start += sizeof(s_tag_group_layout_header);

			parse_children();
			high_level_transplant.tag_group_layout_chunk = this;
		}
	};
	class c_tag_layout_v3_chunk : public c_typed_chunk<'tgly'>
	{
	public:
		c_tag_layout_v3_chunk(c_tag_file_high_level_transplant& high_level_transplant, char* chunk_header_data, c_chunk* parent) :
			c_typed_chunk(high_level_transplant, chunk_header_data, parent, true)
		{
			debug_point;
		}
	};
	class c_string_data_chunk : public c_typed_chunk<'str*'>
	{
	public:
		c_string_data_chunk(c_tag_file_high_level_transplant& high_level_transplant, char* chunk_header_data, c_chunk* parent) :
			c_typed_chunk(high_level_transplant, chunk_header_data, parent, false)
		{
			debug_point;
			high_level_transplant.string_data_chunk = this;
		}
		virtual void log_impl() override
		{
			printf("%.4s size:%08X\n", short_name, size);
			unsigned long offset = 0;
			for (char* current_position = chunk_data_start; current_position < chunk_data_end; current_position++)
			{
				intptr_t offset = current_position - chunk_data_start;
				log_pad(); printf("\t0x%zX\t%s\n", offset, current_position);
				current_position += strlen(current_position);
			}
		}
	};
	class c_string_offsets_chunk : public c_typed_chunk<'sz+x'>
	{
	public:
		unsigned long* const offsets;
		unsigned long const entry_count;
		c_string_offsets_chunk(c_tag_file_high_level_transplant& high_level_transplant, char* chunk_header_data, c_chunk* parent) :
			c_typed_chunk(high_level_transplant, chunk_header_data, parent, false),
			offsets(reinterpret_cast<unsigned long*>(chunk_data_start)),
			entry_count(size / sizeof(*offsets))
		{
			debug_point;
		}
		virtual void log_impl() override
		{
			c_string_data_chunk* string_data_chunk = parent->find_first_chunk<c_string_data_chunk>();
			ASSERT(string_data_chunk != nullptr);

			printf("%.4s count:0x%08X\n", short_name, entry_count);
			for (unsigned long index = 0; index < entry_count; index++)
			{
				unsigned long offset = offsets[index];
				char* string = string_data_chunk->chunk_data_start + offset;
				log_pad(); printf("\t0x%08X\t0x%08X\t%s\n", index, offset, string);
			}
		}
	};

	class c_custom_block_index_search_names_chunk : public c_typed_chunk<'csbn'>
	{
	public:
		unsigned long* const offsets;
		unsigned long const entry_count;
		c_custom_block_index_search_names_chunk(c_tag_file_high_level_transplant& high_level_transplant, char* chunk_header_data, c_chunk* parent) :
			c_typed_chunk(high_level_transplant, chunk_header_data, parent, false),
			offsets(reinterpret_cast<unsigned long*>(chunk_data_start)),
			entry_count(size / sizeof(*offsets))
		{
			debug_point;
		}
		void log_impl() override
		{
			c_string_data_chunk* string_data_chunk = parent->find_first_chunk<c_string_data_chunk>();
			ASSERT(string_data_chunk != nullptr);
			printf("%.4s count:0x%08X\n", short_name, entry_count);
			for (unsigned long index = 0; index < entry_count; index++)
			{
				unsigned long offset = offsets[index];
				char* string = string_data_chunk->chunk_data_start + offset;
				log_pad(); printf("\t0x%08X\t0x%08X\t%s\n", index, offset, string);
			}
		}
	};
	struct s_string_list_entry
	{
		unsigned long name_string_offset;
		unsigned long string_offset_count;
		unsigned long string_offset_start_index;
	};
	class c_string_lists_chunk : public c_typed_chunk<'sz[]'>
	{
	public:
		s_string_list_entry* const entries;
		unsigned long const entry_count;

		c_string_lists_chunk(c_tag_file_high_level_transplant& high_level_transplant, char* chunk_header_data, c_chunk* parent) :
			c_typed_chunk(high_level_transplant, chunk_header_data, parent, false),
			entries(reinterpret_cast<s_string_list_entry*>(chunk_data_start)),
			entry_count(size / sizeof(*entries))
		{
			debug_point;
		}
		virtual void log_impl() override
		{
			c_string_data_chunk* string_data_chunk = parent->find_first_chunk<c_string_data_chunk>();
			ASSERT(string_data_chunk != nullptr);
			printf("%.4s count:0x%08X\n", short_name, entry_count);

			for (unsigned long index = 0; index < entry_count; index++)
			{
				s_string_list_entry& entry = entries[index];
				char* name = string_data_chunk->chunk_data_start + entry.name_string_offset;
				log_pad(); printf(
					"\t0x%08X\tstring_offset_start_index:0x%08X\tstring_offset_start_index:0x%08X\t'%s'\n",
					index,
					entry.string_offset_count,
					entry.string_offset_start_index,
					name);
				debug_point;
			}
		}
	};
	class c_data_definition_name_chunk : public c_typed_chunk<'dtnm'>
	{
	public:
		unsigned long* const offsets;
		unsigned long const entry_count;
		c_data_definition_name_chunk(c_tag_file_high_level_transplant& high_level_transplant, char* chunk_header_data, c_chunk* parent) :
			c_typed_chunk(high_level_transplant, chunk_header_data, parent, false),
			offsets(reinterpret_cast<unsigned long*>(chunk_data_start)),
			entry_count(size / sizeof(*offsets))
		{
			debug_point;
			high_level_transplant.data_definition_name_chunk = this;
		}
		void log_impl() override
		{
			c_string_data_chunk* string_data_chunk = parent->find_first_chunk<c_string_data_chunk>();
			ASSERT(string_data_chunk != nullptr);

			printf("%.4s count:0x%08X\n", short_name, entry_count);
			for (unsigned long index = 0; index < entry_count; index++)
			{
				unsigned long offset = offsets[index];
				char* string = string_data_chunk->chunk_data_start + offset;
				log_pad(); printf("\t0x%08X\t0x%08X\t%s\n", index, offset, string);
			}
		}
	};
	struct s_array_entry
	{
		uint32_t name_string_offset;
		uint32_t count;
		uint32_t structure_index;
	};
	class c_array_definitions_chunk : public c_typed_chunk<'arr!'>
	{
	public:
		s_array_entry* const entries;
		unsigned long const entry_count;

		c_array_definitions_chunk(c_tag_file_high_level_transplant& high_level_transplant, char* chunk_header_data, c_chunk* parent) :
			c_typed_chunk(high_level_transplant, chunk_header_data, parent, false),
			entries(reinterpret_cast<s_array_entry*>(chunk_data_start)),
			entry_count(size / sizeof(*entries))
		{
			debug_point;
			high_level_transplant.array_definitions_chunk = this;
		}
		void log_impl() override
		{
			c_string_data_chunk* string_data_chunk = parent->find_first_chunk<c_string_data_chunk>();
			ASSERT(string_data_chunk != nullptr);

			printf("%.4s count:0x%08X\n", short_name, entry_count);
			for (unsigned long index = 0; index < entry_count; index++)
			{
				s_array_entry entry = entries[index];
				char* string = string_data_chunk->chunk_data_start + entry.name_string_offset;
				log_pad(); printf("\t0x%08X\tcount:0x%08X structure_index:0x%08X %s\n", index, entry.count, entry.structure_index, string);
			}
		}
	};
	struct s_tag_field_type_entry
	{
		uint32_t name_string_offset;
		uint32_t size;
		uint32_t metadata;
	};
	class c_tag_field_types_chunk : public c_typed_chunk<'tgft'>
	{
	public:
		s_tag_field_type_entry* const entries;
		unsigned long const entry_count;
		c_tag_field_types_chunk(c_tag_file_high_level_transplant& high_level_transplant, char* chunk_header_data, c_chunk* parent) :
			c_typed_chunk(high_level_transplant, chunk_header_data, parent, false),
			entries(reinterpret_cast<s_tag_field_type_entry*>(chunk_data_start)),
			entry_count(size / sizeof(*entries))
		{
			debug_point;
			high_level_transplant.tag_field_types_chunk = this;
		}
		virtual void log_impl() override
		{
			c_string_data_chunk* string_data_chunk = parent->find_first_chunk<c_string_data_chunk>();
			ASSERT(string_data_chunk != nullptr);
			printf("%.4s count:0x%08X\n", short_name, entry_count);
			for (unsigned long index = 0; index < entry_count; index++)
			{
				s_tag_field_type_entry entry = entries[index];
				char* _typename = string_data_chunk->chunk_data_start + entry.name_string_offset;
				log_pad(); printf("\t0x%08X\tsize:0x%08X metadata:0x%08X %s\n", index, entry.size, entry.metadata, _typename);
			}
		}
	};
	struct s_field_entry
	{
		unsigned long name_string_offset;
		unsigned long tag_field_type_index;
		unsigned long metadata;
	};
	class s_fields_chunk : public c_typed_chunk<'gras'>
	{
	public:
		s_field_entry* const entries;
		unsigned long const entry_count;
		s_fields_chunk(c_tag_file_high_level_transplant& high_level_transplant, char* chunk_header_data, c_chunk* parent) :
			c_typed_chunk(high_level_transplant, chunk_header_data, parent, false),
			entries(reinterpret_cast<s_field_entry*>(chunk_data_start)),
			entry_count(size / sizeof(*entries))
		{
			debug_point;
			high_level_transplant.fields_chunk = this;
		}
		virtual void log_impl() override
		{
			c_string_data_chunk* string_data_chunk = parent->find_first_chunk<c_string_data_chunk>();
			ASSERT(string_data_chunk != nullptr);
			printf("%.4s count:0x%08X\n", short_name, entry_count);
			for (unsigned long index = 0; index < entry_count; index++)
			{
				s_field_entry entry = entries[index];
				char* name = string_data_chunk->chunk_data_start + entry.name_string_offset;
				log_pad(); printf("\t0x%08X\ttag_field_type_index:0x%08X\tmetadata:0x%08X\t'%s'\n", index, entry.tag_field_type_index, entry.metadata, name);
			}
		}
	};
	struct s_block_definition_entry
	{
		uint32_t name_string_offset;
		uint32_t max_count;
		uint32_t structure_entry_index;
	};
	class c_block_definitions_chunk : public c_typed_chunk<'blv2'>
	{
	public:
		s_block_definition_entry* const entries;
		unsigned long const entry_count;
		c_block_definitions_chunk(c_tag_file_high_level_transplant& high_level_transplant, char* chunk_header_data, c_chunk* parent) :
			c_typed_chunk(high_level_transplant, chunk_header_data, parent, false),
			entries(reinterpret_cast<s_block_definition_entry*>(chunk_data_start)),
			entry_count(size / sizeof(*entries))
		{
			debug_point;
			high_level_transplant.block_definitions_chunk = this;
		}
		virtual void log_impl() override
		{
			c_string_data_chunk* string_data_chunk = parent->find_first_chunk<c_string_data_chunk>();
			ASSERT(string_data_chunk != nullptr);
			printf("%.4s count:0x%08X\n", short_name, entry_count);
			for (unsigned long index = 0; index < entry_count; index++)
			{
				s_block_definition_entry entry = entries[index];
				char* name = string_data_chunk->chunk_data_start + entry.name_string_offset;
				log_pad(); printf("\t0x%08X\tmax_count:0x%08X\tstructure_entry_index:0x%08X\t%s\n", index, entry.max_count, entry.structure_entry_index, name);
			}
		}
	};
	struct s_resource_definition_entry
	{
		uint32_t name_string_offset;
		uint32_t unknown;
		uint32_t structure_entry_index;
	};
	class c_resource_definitions_chunk : public c_typed_chunk<'rcv2'>
	{
	public:
		s_resource_definition_entry* const entries;
		unsigned long const entry_count;
		c_resource_definitions_chunk(c_tag_file_high_level_transplant& high_level_transplant, char* chunk_header_data, c_chunk* parent) :
			c_typed_chunk(high_level_transplant, chunk_header_data, parent, false),
			entries(reinterpret_cast<s_resource_definition_entry*>(chunk_data_start)),
			entry_count(size / sizeof(*entries))
		{
			debug_point;
		}
		void log_impl() override
		{
			c_string_data_chunk* string_data_chunk = parent->find_first_chunk<c_string_data_chunk>();
			ASSERT(string_data_chunk != nullptr);
			printf("%.4s count:0x%08X\n", short_name, entry_count);
			for (unsigned long index = 0; index < entry_count; index++)
			{
				s_resource_definition_entry entry = entries[index];
				char* string = string_data_chunk->chunk_data_start + entry.name_string_offset;
				log_pad(); printf("\t0x%08X\tunknown:0x%08X structure_entry_index:0x%08X %s\n", index, entry.unknown, entry.structure_entry_index, string);
			}
		}
	};
	struct s_interop_definition_entry
	{
		uint32_t name_string_offset;
		uint32_t structure_entry_index;
		blofeld::s_tag_persistent_identifier persistent_identifier;
	};
	class c_interop_definitions_chunk : public c_typed_chunk<']==['>
	{
	public:
		s_interop_definition_entry* const entries;
		unsigned long const entry_count;

		c_interop_definitions_chunk(c_tag_file_high_level_transplant& high_level_transplant, char* chunk_header_data, c_chunk* parent) :
			c_typed_chunk(high_level_transplant, chunk_header_data, parent, false),
			entries(reinterpret_cast<s_interop_definition_entry*>(chunk_data_start)),
			entry_count(size / sizeof(*entries))
		{
			debug_point;
		}
		void log_impl() override
		{
			c_string_data_chunk* string_data_chunk = parent->find_first_chunk<c_string_data_chunk>();
			ASSERT(string_data_chunk != nullptr);

			printf("%.4s count:0x%08X\n", short_name, entry_count);
			for (unsigned long index = 0; index < entry_count; index++)
			{
				s_interop_definition_entry& entry = entries[index];
				char* string = string_data_chunk->chunk_data_start + entry.name_string_offset;
				log_pad(); printf(
					"\t0x%08X\t[0x%08X, 0x%08X, 0x%08X, 0x%08X]\tstructure_entry_index:0x%08X %s\n",
					index,
					entry.persistent_identifier.identifier_part_0,
					entry.persistent_identifier.identifier_part_1,
					entry.persistent_identifier.identifier_part_2,
					entry.persistent_identifier.identifier_part_3,
					entry.structure_entry_index,
					string);
				debug_point;
			}
		}
	};
	struct s_struct_definition_entry
	{
		blofeld::s_tag_persistent_identifier persistent_identifier;
		unsigned long name_string_offset;
		unsigned long fields_start_index;
	};
	class c_structure_definitions_chunk : public c_typed_chunk<'stv2'>
	{
	public:
		s_struct_definition_entry* const entries;
		unsigned long const entry_count;
		c_structure_definitions_chunk(c_tag_file_high_level_transplant& high_level_transplant, char* chunk_header_data, c_chunk* parent) :
			c_typed_chunk(high_level_transplant, chunk_header_data, parent, false),
			entries(reinterpret_cast<s_struct_definition_entry*>(chunk_data_start)),
			entry_count(size / sizeof(*entries))
		{
			debug_point;
			high_level_transplant.structure_definitions_chunk = this;
		}
		virtual void log_impl() override
		{
			c_string_data_chunk* string_data_chunk = parent->find_first_chunk<c_string_data_chunk>();
			ASSERT(string_data_chunk != nullptr);

			printf("%.4s count:0x%08X\n", short_name, entry_count);
			for (unsigned long index = 0; index < entry_count; index++)
			{
				s_struct_definition_entry& entry = entries[index];
				char* string = string_data_chunk->chunk_data_start + entry.name_string_offset;
				log_pad(); printf(
					"\t0x%08X\t[0x%08X, 0x%08X, 0x%08X, 0x%08X]\tfields_start_index:0x%08X %s\n",
					index,
					entry.persistent_identifier.identifier_part_0,
					entry.persistent_identifier.identifier_part_1,
					entry.persistent_identifier.identifier_part_2,
					entry.persistent_identifier.identifier_part_3,
					entry.fields_start_index,
					string);
				debug_point;
			}
		}
	};
	class c_binary_data_chunk_chunk : public c_typed_chunk<'bdat'>
	{
	public:
		c_binary_data_chunk_chunk(c_tag_file_high_level_transplant& high_level_transplant, char* chunk_header_data, c_chunk* parent) :
			c_typed_chunk(high_level_transplant, chunk_header_data, parent, false)
		{
			debug_point;
			high_level_transplant.binary_data_chunk = this;
		}
	};
	struct s_tag_block_chunk_header
	{
		unsigned long count;
		unsigned long struct_index;
	};
	class c_tag_block_chunk : public c_typed_chunk<'tgbl'>
	{
	public:
		s_tag_block_chunk_header tag_block_chunk_header;
		unsigned long struct_size;
		unsigned long data_size;

		c_tag_block_chunk(c_tag_file_high_level_transplant& high_level_transplant, char* chunk_header_data, c_chunk* parent) :
			c_typed_chunk(high_level_transplant, chunk_header_data, parent, false)
		{
			tag_block_chunk_header = *reinterpret_cast<s_tag_block_chunk_header*>(chunk_data_start);
			chunk_data_start += sizeof(s_tag_block_chunk_header);

			auto struct_entry = high_level_transplant.structure_definitions_chunk->entries + tag_block_chunk_header.struct_index;
			char* struct_name = high_level_transplant.string_data_chunk->chunk_data_start + struct_entry->name_string_offset;

			if (strcmp(struct_name, "vehicle_group") == 0)
			{
				debug_point;
			}

			// #TODO: calculate this size based off the info in the chunks and compare
			struct_size = high_level_transplant.calculate_structure_size_by_index(tag_block_chunk_header.struct_index);
			data_size = struct_size * tag_block_chunk_header.count;

			chunk_data_start += data_size;



			parse_children();
		}
		virtual void log_impl() override
		{
			printf("%.4s data_size:0x%08X\n", short_name, data_size);

			auto struct_entry = high_level_transplant.structure_definitions_chunk->entries + tag_block_chunk_header.struct_index;
			char* struct_name = high_level_transplant.string_data_chunk->chunk_data_start + struct_entry->name_string_offset;

			for (unsigned long index = 0; index < tag_block_chunk_header.count; index++)
			{
				log_pad(); printf(
					"\t0x%08X\t%s\n",
					index,
					struct_name);
				debug_point;
			}
		}
	};
	class c_tag_struct_chunk : public c_typed_chunk<'tgst'>
	{
	public:
		c_tag_struct_chunk(c_tag_file_high_level_transplant& high_level_transplant, char* chunk_header_data, c_chunk* parent) :
			c_typed_chunk(high_level_transplant, chunk_header_data, parent, true)
		{
			debug_point;
		}
	};
	class c_tag_string_id_chunk : public c_typed_chunk<'tgsi'>
	{
	public:
		char* string;
		c_tag_string_id_chunk(c_tag_file_high_level_transplant& high_level_transplant, char* chunk_header_data, c_chunk* parent) :
			c_typed_chunk(high_level_transplant, chunk_header_data, parent, false),
			string()
		{
			intptr_t string_length = chunk_data_end - chunk_data_start;
			string = new char[string_length  + 1];
			memcpy(string, chunk_data_start, string_length);
			string[string_length] = 0;

			debug_point;
		}
		~c_tag_string_id_chunk()
		{
			delete[] string;
		}
	};
	class c_tag_reference_chunk : public c_typed_chunk<'tgrf'>
	{
	public:
		tag group_tag;
		char* tag_filepath_without_extension;
		c_tag_reference_chunk(c_tag_file_high_level_transplant& high_level_transplant, char* chunk_header_data, c_chunk* parent) :
			c_typed_chunk(high_level_transplant, chunk_header_data, parent, false),
			group_tag(blofeld::INVALID_TAG),
			tag_filepath_without_extension()
		{
			intptr_t data_length = chunk_data_end - chunk_data_start;
			if (data_length >= 4)
			{
				intptr_t string_length = data_length - 4;
				group_tag = *reinterpret_cast<tag*>(chunk_data_start);
				tag_filepath_without_extension = new char[string_length  + 1];
				memcpy(tag_filepath_without_extension, chunk_data_start + sizeof(tag), string_length);
				tag_filepath_without_extension[string_length] = 0;
			}
			debug_point;
		}
		~c_tag_reference_chunk()
		{
			delete[] tag_filepath_without_extension;
		}
	};
	using c_aggregate_definitions_chunk = c_typed_chunk<'agro'>;
	void* tag_file_data;
	unsigned long long tag_file_data_size;

	struct s_tag_file_header
	{
		unsigned long unknown0;
		unsigned long unknown4;
		unsigned long unknown8;
		unsigned long unknownC;
		unsigned long unknown10;
		unsigned long unknown14;
		unsigned long unknown18;
		unsigned long unknown1C;

		unsigned long unknown20;
		unsigned long unknown24; // 1
		unsigned long unknown28; // 1
		unsigned long unknown2C; // ULONG_MAX

		tag group_tag;
		unsigned long group_version; // 2
		unsigned long crc32; // hash?
		unsigned long blam; // 'BLAM'

	};

	s_tag_file_header* header_data;
	s_engine_platform_build engine_platform_build;
	c_chunk* root_chunk;
	c_tag_group_layout_chunk* tag_group_layout_chunk;
	c_string_data_chunk* string_data_chunk;
	c_array_definitions_chunk* array_definitions_chunk;
	c_data_definition_name_chunk* data_definition_name_chunk;
	c_block_definitions_chunk* block_definitions_chunk;
	c_tag_field_types_chunk* tag_field_types_chunk;
	s_fields_chunk* fields_chunk;
	c_structure_definitions_chunk* structure_definitions_chunk;
	c_binary_data_chunk_chunk* binary_data_chunk;

	const blofeld::s_tag_group* blofeld_tag_group;
	const blofeld::s_tag_block_definition* blofeld_tag_block_definition;
	const blofeld::s_tag_struct_definition* blofeld_tag_group_struct_definition;

	unsigned long calculate_structure_size_by_entry(const s_struct_definition_entry& structure_entry)
	{
		unsigned long structure_size = 0;
		for (unsigned long field_index = structure_entry.fields_start_index;; field_index++)
		{
			s_field_entry& field_entry = fields_chunk->entries[field_index];
			s_tag_field_type_entry& tag_field_type = tag_field_types_chunk->entries[field_entry.tag_field_type_index];

			const char* type_string = string_data_chunk->chunk_data_start + tag_field_type.name_string_offset;
			const char* name_string = string_data_chunk->chunk_data_start + field_entry.name_string_offset;

			blofeld::e_field field_type;
			BCS_RESULT rs = blofeld::tag_field_type_to_field(type_string, field_type);
			ASSERT(BCS_SUCCEEDED(rs));

			if (field_type == blofeld::_field_terminator)
			{
				break;
			}

			unsigned long field_size = tag_field_type.size;

			//if (tag_field_type.metadata)
			{
				switch (field_type)
				{
				case blofeld::_field_struct:
				{
					unsigned long structure_size = calculate_structure_size_by_index(field_entry.metadata);
					field_size = structure_size;
				}
				break;
				case blofeld::_field_array:
				{
					s_array_entry& array_entry = array_definitions_chunk->entries[field_entry.metadata];
					unsigned long array_structure_size = calculate_structure_size_by_index(array_entry.structure_index);
					unsigned long array_size = array_structure_size * array_entry.count;
					field_size = array_size;
				}
				break;
				case blofeld::_field_pad:
				{
					unsigned long pad_size = field_entry.metadata;
					field_size = pad_size;
				}
				break;
				//default:
				//	throw;
				}
			}


			structure_size += field_size;

			//console_write_line("0x%08lX 0x%08lX %s %s", field_size, structure_size, type_string, name_string);

			debug_point;
		}
		return structure_size;
	}

	unsigned long calculate_structure_size_by_index(unsigned long structure_index)
	{
		ASSERT(structure_index < structure_definitions_chunk->entry_count);
		return calculate_structure_size_by_entry(structure_definitions_chunk->entries[structure_index]);
	}

	c_tag_file_high_level_transplant(const char* filepath)
	{
		BCS_FAIL_THROW(filesystem_read_file_to_memory(filepath, tag_file_data, tag_file_data_size));
		header_data = (s_tag_file_header*)tag_file_data;
		ASSERT(header_data->blam == 'BLAM');

		engine_platform_build = { _engine_type_halo3 };
		blofeld_tag_group = blofeld::get_group_tag_by_group_tag(engine_platform_build.engine_type, header_data->group_tag);
		ASSERT(blofeld_tag_group != nullptr);
		blofeld_tag_block_definition = &blofeld_tag_group->block_definition;
		blofeld_tag_group_struct_definition = &blofeld_tag_block_definition->struct_definition;
		h_object* high_level = h_object::create_high_level_object(*blofeld_tag_group_struct_definition, engine_platform_build);
		ASSERT(high_level);

		char* chunk_data = reinterpret_cast<char*>(header_data + 1);
		root_chunk = c_tag_file_high_level_transplant::c_chunk::create_data_chunk(*this, chunk_data, nullptr);
		tag_group_layout_chunk;

		root_chunk->log();

		binary_data_chunk->parse_children();

		const s_block_definition_entry* root_block_definition_entry = block_definitions_chunk->entries + tag_group_layout_chunk->tag_group_layout_header->tag_group_block_index;
		const char* root_block_definition_name = string_data_chunk->chunk_data_start + root_block_definition_entry->name_string_offset;
		ASSERT(strcmp(root_block_definition_name, blofeld_tag_block_definition->name) == 0); // sanity check
		const s_struct_definition_entry* root_structure_definition_entry = structure_definitions_chunk->entries + root_block_definition_entry->structure_entry_index;
		ASSERT(root_structure_definition_entry->persistent_identifier == blofeld_tag_group->block_definition.struct_definition.persistent_identifier); // sanity check
		const char* root_struct_definition_name = string_data_chunk->chunk_data_start + root_structure_definition_entry->name_string_offset;
		//ASSERT(strcmp(root_struct_definition_name, blofeld_tag_group_struct_definition->name) == 0); // sanity check

		read_tag_block(
			binary_data_chunk->chunk_data_start,
			*root_block_definition_entry,
			*root_structure_definition_entry,
			blofeld_tag_group->block_definition,
			*blofeld_tag_group_struct_definition);

		debug_point;
	}

	void read_tag_block(
		const void* tag_block_start,
		//h_block& high_level_block,
		const s_block_definition_entry& block_entry,
		const s_struct_definition_entry& structure_entry,
		const blofeld::s_tag_block_definition& blofeld_block_definition,
		const blofeld::s_tag_struct_definition& blofeld_struct_definition)
	{
		const char* tag_block_position = static_cast<const char*>(tag_block_start);
#define READ(type) *reinterpret_cast<const type*>(tag_block_position); tag_block_position += sizeof(type)

		unsigned long tag_block_magic = READ(unsigned long);
		unsigned long unknown = READ(unsigned long);
		unsigned long tag_block_data_size = READ(unsigned long);

		for (const blofeld::s_tag_field* field = blofeld_struct_definition.fields; field->field_type != blofeld::_field_terminator; field++)
		{
			//const char* field_str = field_to_tag_field_type(field->field_type);
			//unsigned long field_data_size = get_field_type_data_size(field->field_type);
			//
			//console_write_line("'%s' size:%lu", field_str, field_data_size);
			//
			//if (field_data_size > 0)
			//{
			//	for (unsigned long i = 0; i < field_data_size; i++)
			//	{
			//		unsigned long value = READ(unsigned char);
			//		console_write("%02X ", value);
			//	}
			//	console_write_line("");
			//}
			//
			//debug_point;
		}

		debug_point;

	}

	~c_tag_file_high_level_transplant()
	{

	}
};

c_tag_file_high_level_transplant::c_chunk* c_tag_file_high_level_transplant::c_chunk::create_data_chunk(c_tag_file_high_level_transplant& high_level_transplant, char* data, c_chunk* parent)
{
	char literal_string[5] = { data[3], data[2], data[1], data[0], 0 };
	unsigned long& literal = *reinterpret_cast<unsigned long*>(data);

	switch (literal)
	{
	case c_tag_header_chunk::type: return new c_tag_header_chunk(high_level_transplant, data, parent);
	case c_tag_group_layout_chunk::type: return new c_tag_group_layout_chunk(high_level_transplant, data, parent);
	case c_tag_layout_v3_chunk::type: return new c_tag_layout_v3_chunk(high_level_transplant, data, parent);
	case c_string_data_chunk::type: return new c_string_data_chunk(high_level_transplant, data, parent);
	case c_string_offsets_chunk::type: return new c_string_offsets_chunk(high_level_transplant, data, parent);
	case c_string_lists_chunk::type: return new c_string_lists_chunk(high_level_transplant, data, parent);
	case c_custom_block_index_search_names_chunk::type: return new c_custom_block_index_search_names_chunk(high_level_transplant, data, parent);
	case c_data_definition_name_chunk::type: return new c_data_definition_name_chunk(high_level_transplant, data, parent);
	case c_array_definitions_chunk::type: return new c_array_definitions_chunk(high_level_transplant, data, parent);
	case c_tag_field_types_chunk::type: return new c_tag_field_types_chunk(high_level_transplant, data, parent);
	case s_fields_chunk::type: return new s_fields_chunk(high_level_transplant, data, parent);
	case c_block_definitions_chunk::type: return new c_block_definitions_chunk(high_level_transplant, data, parent);
	case c_resource_definitions_chunk::type: return new c_resource_definitions_chunk(high_level_transplant, data, parent);
	case c_interop_definitions_chunk::type: return new c_interop_definitions_chunk(high_level_transplant, data, parent);
	case c_structure_definitions_chunk::type: return new c_structure_definitions_chunk(high_level_transplant, data, parent);
	case c_binary_data_chunk_chunk::type: return new c_binary_data_chunk_chunk(high_level_transplant, data, parent);
	case c_tag_block_chunk::type: return new c_tag_block_chunk(high_level_transplant, data, parent);
	case c_tag_struct_chunk::type: return new c_tag_struct_chunk(high_level_transplant, data, parent);
	case c_tag_string_id_chunk::type: return new c_tag_string_id_chunk(high_level_transplant, data, parent);
	case c_tag_reference_chunk::type: return new c_tag_reference_chunk(high_level_transplant, data, parent);
		
	}

	return nullptr;
}

int main()
{
	const wchar_t* launch_filepath_command_line_argument = nullptr; // #TODO: implement this with the command line API

	BCS_FAIL_RETURN(register_process_module_by_pointer(main));
	BCS_RESULT rs0 = init_command_line();
	BCS_RESULT rs1 = init_console();
	if (BCS_SUCCEEDED(rs1)) rs1 = BCS_SUCCEEDED(command_line_has_argument("console")) ? alloc_console("Halo 3 Tag File Test Console") : BCS_S_OK;
	//BCS_RESULT rs2 = window_create(window_title, "halo3tagfiletest", _window_icon_mandrill, ULONG_MAX, ULONG_MAX, window_background_color, window);
	//BCS_RESULT rs3 = render_context_window_create(*window, graphics_background_color, window_render_context);

	//mandrill_user_interface = new c_mandrill_user_interface(
	//	*window_render_context,
	//	false, 
	//	launch_filepath_command_line_argument);

	//window_render_context->render();

	//delete mandrill_user_interface;

	//const char* filepath = R"(B:\H3EK\tags\ui\hud\hud_messages.multilingual_unicode_string_list)";
	//filepath = R"(B:\H3EK\tags\tag3.performance_throttles)";
	const char* filepath = R"(B:\H3EK\tags\objects\vehicles\warthog\warthog.vehicle)";
	//filepath = R"(B:\H3EK\tags\objects\vehicles\warthog\bitmaps\antenna.bitmap)";
	//filepath = R"(B:\H3EK\tags\sound\weapons\impacts_riccs\bullet_flyby_short.sound)";
	//blofeld::halo3::h_multilingual_unicode_string_list_struct_definition unicode_string_list;
	//auto& x = unicode_string_list.get_blofeld_struct_definition();
	c_tag_file_high_level_transplant high_level_transplant = c_tag_file_high_level_transplant(filepath);

	//if (BCS_SUCCEEDED(rs3)) rs3 = render_context_destroy(window_render_context);
	//if (BCS_SUCCEEDED(rs2)) rs2 = window_destroy(window);
	if (BCS_SUCCEEDED(rs1)) rs1 = deinit_console();
	if (BCS_SUCCEEDED(rs0)) rs0 = deinit_command_line();

	//BCS_FAIL_RETURN(rs3);
	//BCS_FAIL_RETURN(rs2);
	BCS_FAIL_RETURN(rs1);
	BCS_FAIL_RETURN(rs0);

	return 0;
}
