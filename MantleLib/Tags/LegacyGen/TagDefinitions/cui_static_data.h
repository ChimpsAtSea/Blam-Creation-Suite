#pragma once

struct nicename("cui_static_data") tag_group('cust') s_cui_static_data_definition
{
	struct nicename("Property Pool") s_property_pool_definition
	{
		enum nicename("Property Kind") e_property_kind : uint16_t
		{
			/*nicename("Boolean Integer")*/ _property_kind_boolean_integer = 1ui16,
			/*nicename("Integer")*/ _property_kind_integer = 2ui16,
			/*nicename("Float")*/ _property_kind_float = 3ui16,
			/*nicename("Ascii")*/ _property_kind_ascii = 4ui16,
			/*nicename("Widget")*/ _property_kind_widget = 5ui16,
			/*nicename("Resource")*/ _property_kind_resource = 6ui16,
			/*nicename("String ID")*/ _property_kind_string_id = 7ui16,
			/*nicename("Color")*/ _property_kind_color = 8ui16,
		};

		DEPRECATED_string_id nicename("Property Name") property_name;
		e_property_kind nicename("Property Kind") property_kind;
		int16_t __unknown0;
	};

	struct nicename("Components") s_components_definition
	{
		struct nicename("Integers") s_integers_definition
		{
			DEPRECATED_string_id nicename("Property") property;
			int32_t nicename("Value") value;
		};

		struct nicename("Floats") s_floats_definition
		{
			DEPRECATED_string_id nicename("Property") property;
			float nicename("Value") value;
		};

		struct nicename("String IDs") s_string_ids_definition
		{
			DEPRECATED_string_id nicename("Property") property;
			DEPRECATED_string_id nicename("String") string;
		};

		struct nicename("Resources") s_resources_definition
		{
			DEPRECATED_string_id nicename("Property") property;
			TagReference nicename("Resource") resource_reference;
		};

		struct nicename("Text") s_text_definition
		{
			DEPRECATED_string_id nicename("Property") property;
			char nicename("Text") text[256];
		};

		struct nicename("Colors") s_colors_definition
		{
			DEPRECATED_string_id nicename("Property") property;
			colorf nicename("Color") color;
		};

		s_tag_block_definition<s_integers_definition> nicename("Integers") integers_block;
		s_tag_block_definition<s_floats_definition> nicename("Floats") floats_block;
		s_tag_block_definition<s_string_ids_definition> nicename("String IDs") string_ids_block;
		s_tag_block_definition<s_resources_definition> nicename("Resources") resources_block;
		s_tag_block_definition<s_text_definition> nicename("Text") text_block;
		s_tag_block_definition<s_colors_definition> nicename("Colors") colors_block;
	};

	s_tag_block_definition<s_property_pool_definition> nicename("Property Pool") property_pool_block;
	s_tag_block_definition<s_components_definition> nicename("Components") components_block;
};

