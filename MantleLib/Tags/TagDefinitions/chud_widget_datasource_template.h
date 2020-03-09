#pragma once

struct nicename("chud_widget_datasource_template") group('wdst') s_chud_widget_datasource_template_definition
{
	struct nicename("Datasource") s_datasource_definition
	{
		struct nicename("Unknown 6") s_unknown_6_definition
		{
			float __unknown0;
			float __unknown1;
			float __unknown2;
			float __unknown3;
		};

		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		int8_t __unknown3;
		int16_t __unknown4;
		int16_t __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		Undefined32 __unknown8;
		s_tag_block_definition<s_unknown_6_definition> nicename("Unknown 6") unknown_6_block;
	};

	s_tag_block_definition<s_datasource_definition> nicename("Datasource") datasource_block;
};

