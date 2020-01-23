#pragma once

struct nicename("Render Method Definition") group('rmdf') s_render_method_definition_definition
{
	struct s_unknown_0_block_definition;
	struct s_unknown_1_block_definition;
	struct s_unknown_2_block_definition;

	TagReference __unknown_reference; 
	s_tag_block_definition<s_unknown_0_block_definition> __unknown_0_block; 
	s_tag_block_definition<s_unknown_1_block_definition> __unknown_1_block; 
	s_tag_block_definition<s_unknown_2_block_definition> __unknown_2_block; 
	TagReference __unknown2_reference; 
	TagReference __unknown3_reference; 
	Undefined32 __unknown4; 
	Undefined32 __unknown5; 
	char nicename("Name") name[256];

	struct s_unknown_0_block_definition
	{
		struct s_unknown_1_block_definition;

		string_id __unknown; 
		s_tag_block_definition<s_unknown_1_block_definition> __unknown_1_block; 
		string_id __unknown2; 
		string_id __unknown3; 

		struct s_unknown_1_block_definition
		{
			string_id __unknown; 
			TagReference __unknown2_reference; 
			string_id __unknown3; 
			string_id __unknown4; 
		};
	};

	struct s_unknown_1_block_definition
	{
		struct s_unknown_2_block_definition;

		Undefined32 __unknown; 
		s_tag_block_definition<s_unknown_2_block_definition> __unknown_2_block; 

		struct s_unknown_2_block_definition
		{
			struct s_unknown_3_block_definition;
			struct s_unknown_4_block_definition;

			Undefined32 __unknown; 
			s_tag_block_definition<s_unknown_3_block_definition> __unknown_3_block; 
			s_tag_block_definition<s_unknown_4_block_definition> __unknown_4_block; 

			struct s_unknown_3_block_definition
			{
				Undefined32 __unknown; 
			};

			struct s_unknown_4_block_definition
			{
				Undefined32 __unknown; 
			};
		};
	};

	struct s_unknown_2_block_definition
	{
		Undefined32 __unknown; 
	};
};
