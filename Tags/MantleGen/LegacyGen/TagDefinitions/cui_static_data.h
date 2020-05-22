#pragma once

struct nicename("cui_static_data") tag_group('cust') s_cui_static_data_definition_legacy
{
	struct nicename("Property Pool") s_property_pool_definition_legacy
	{
		enum nicename("Property Kind") e_property_kind : uint16_t
		{
			/*nicename("Boolean Integer")*/ _property_kind_boolean_integer = 0ui16,
			/*nicename("Integer")*/ _property_kind_integer = 1ui16,
			/*nicename("Float")*/ _property_kind_float = 2ui16,
			/*nicename("Ascii")*/ _property_kind_ascii = 3ui16,
			/*nicename("Widget")*/ _property_kind_widget = 4ui16,
			/*nicename("Resource")*/ _property_kind_resource = 5ui16,
			/*nicename("String ID")*/ _property_kind_string_id = 6ui16,
			/*nicename("Color")*/ _property_kind_color = 7ui16,
		};

		string_id_legacy nicename("Property Name") property_name;
		e_property_kind nicename("Property Kind") property_kind;
		int16_t __unknown0;
	};

	struct nicename("Components") s_components_definition_legacy
	{
		struct nicename("Integers") s_integers_definition_legacy
		{
			string_id_legacy nicename("Property") property;
			int32_t nicename("Value") value;
		};

		struct nicename("Floats") s_floats_definition_legacy
		{
			string_id_legacy nicename("Property") property;
			float nicename("Value") value;
		};

		struct nicename("String IDs") s_string_ids_definition_legacy
		{
			string_id_legacy nicename("Property") property;
			string_id_legacy nicename("String") string;
		};

		struct nicename("Resources") s_resources_definition_legacy
		{
			string_id_legacy nicename("Property") property;
			s_tag_reference_legacy nicename("Resource") resource_reference;
		};

		struct nicename("Text") s_text_definition_legacy
		{
			string_id_legacy nicename("Property") property;
			char nicename("Text") text[256];
		};

		struct nicename("Colors") s_colors_definition_legacy
		{
			string_id_legacy nicename("Property") property;
			s_colorf_legacy nicename("Color") color;
		};

		s_tag_block_legacy<s_integers_definition_legacy> nicename("Integers") integers_block;
		s_tag_block_legacy<s_floats_definition_legacy> nicename("Floats") floats_block;
		s_tag_block_legacy<s_string_ids_definition_legacy> nicename("String IDs") string_ids_block;
		s_tag_block_legacy<s_resources_definition_legacy> nicename("Resources") resources_block;
		s_tag_block_legacy<s_text_definition_legacy> nicename("Text") text_block;
		s_tag_block_legacy<s_colors_definition_legacy> nicename("Colors") colors_block;
	};

	s_tag_block_legacy<s_property_pool_definition_legacy> nicename("Property Pool") property_pool_block;
	s_tag_block_legacy<s_components_definition_legacy> nicename("Components") components_block;
};

