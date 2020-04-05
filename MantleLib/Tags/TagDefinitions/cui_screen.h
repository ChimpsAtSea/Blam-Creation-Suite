#pragma once

struct nicename("cui_screen") tag_group('cusc') s_cui_screen_definition
{
	struct nicename("Templates") s_templates_definition
	{
		TagReference nicename("Template") template_reference;
	};

	struct nicename("Definitions") s_definitions_definition
	{
		string_id nicename("Import Name") import_name;
		string_id nicename("Export Name") export_name;
		string_id nicename("Logic Group") logic_group;
		int16_t __unknown0;
		int16_t nicename("Template Index") template_index;
	};

	struct nicename("Component Table") s_component_table_definition
	{
		string_id nicename("Component Name") component_name;
		int16_t nicename("Definition Index") definition_index;
		int16_t __unknown0;
	};

	struct nicename("UI") s_ui_definition
	{
		struct nicename("Components") s_components_definition
		{
			struct nicename("Integers") s_integers_definition
			{
				string_id nicename("Property") property;
				int32_t nicename("Value") value;
			};

			struct nicename("Floats") s_floats_definition
			{
				string_id nicename("Property") property;
				float nicename("Value") value;
			};

			struct nicename("String ID") s_string_id_definition
			{
				string_id nicename("Property") property;
				string_id nicename("String") string;
			};

			struct nicename("Resources") s_resources_definition
			{
				string_id nicename("Property") property;
				TagReference nicename("Resource") resource_reference;
			};

			struct nicename("Text") s_text_definition
			{
				string_id nicename("Property") property;
				char nicename("Text") text[256];
			};

			struct nicename("Colors") s_colors_definition
			{
				string_id nicename("Property") property;
				colorf nicename("Color") color;
			};

			string_id nicename("Component Name") component_name;
			s_tag_block_definition<s_integers_definition> nicename("Integers") integers_block;
			s_tag_block_definition<s_floats_definition> nicename("Floats") floats_block;
			s_tag_block_definition<s_string_id_definition> nicename("String ID") string_id_block;
			s_tag_block_definition<s_resources_definition> nicename("Resources") resources_block;
			s_tag_block_definition<s_text_definition> nicename("Text") text_block;
			s_tag_block_definition<s_colors_definition> nicename("Colors") colors_block;
		};

		struct nicename("Animations") s_animations_definition
		{
			struct nicename("Component") s_component_definition
			{
				struct nicename("Standard Animations") s_standard_animations_definition
				{
					struct nicename("Values") s_values_definition
					{
						int32_t nicename("Frame") frame;
						float nicename("Value") value;
						DataReference nicename("Data") data_data_reference;
					};

					string_id nicename("Property") property;
					int16_t __unknown0;
					int8_t __unknown1;
					int8_t __unknown2;
					int32_t nicename("Frame Count") frame_count;
					s_tag_block_definition<s_values_definition> nicename("Values") values_block;
				};

				struct nicename("Color Animations") s_color_animations_definition
				{
					struct nicename("Values") s_values1_definition
					{
						int32_t nicename("Frame") frame;
						colorf nicename("Color") color;
						DataReference nicename("Data") data_data_reference;
					};

					string_id nicename("Property") property;
					int16_t __unknown0;
					int8_t __unknown1;
					int8_t __unknown2;
					int32_t nicename("Frame Count") frame_count;
					s_tag_block_definition<s_values1_definition> nicename("Values") values_block;
				};

				string_id nicename("Name") name;
				int32_t nicename("Frame Count") frame_count;
				s_tag_block_definition<s_standard_animations_definition> nicename("Standard Animations") standard_animations_block;
				s_tag_block_definition<s_color_animations_definition> nicename("Color Animations") color_animations_block;
			};

			string_id nicename("Name") name;
			s_tag_block_definition<s_component_definition> nicename("Component") component_block;
		};

		string_id nicename("Resolution") resolution;
		string_id nicename("Theme") theme;
		s_tag_block_definition<s_components_definition> nicename("Components") components_block;
		s_tag_block_definition<s_animations_definition> nicename("Animations") animations_block;
	};

	struct nicename("Logic") s_logic_definition
	{
		int16_t nicename("Flags") flags;
		int16_t nicename("Flags") flags1;
		string_id nicename("Input Component") input_component;
		string_id nicename("Input Property") input_property;
		string_id nicename("Output Component") output_component;
		string_id nicename("Ouput Property") ouput_property;
	};

	struct nicename("Defaults?") s_defaults_definition
	{
		string_id __unknown0;
		string_id __unknown1;
		int8_t __unknown2;
		int8_t __unknown3;
		int8_t __unknown4;
		int8_t __unknown5;
		int32_t __unknown6;
	};

	struct nicename("Static Data Table") s_static_data_table_definition
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

			string_id nicename("Property Name") property_name;
			e_property_kind nicename("Property Kind") property_kind;
			int16_t __unknown0;
		};

		struct nicename("Components") s_components1_definition
		{
			struct nicename("Integers") s_integers1_definition
			{
				string_id nicename("Property") property;
				int32_t nicename("Value") value;
			};

			struct nicename("Floats") s_floats1_definition
			{
				string_id nicename("Property") property;
				float nicename("Value") value;
			};

			struct nicename("String IDs") s_string_ids_definition
			{
				string_id nicename("Property") property;
				string_id nicename("String") string;
			};

			struct nicename("Resources") s_resources1_definition
			{
				string_id nicename("Property") property;
				TagReference nicename("Resource") resource_reference;
			};

			struct nicename("Text") s_text1_definition
			{
				string_id nicename("Property") property;
				char nicename("Text") text[256];
			};

			struct nicename("Colors") s_colors1_definition
			{
				string_id nicename("Property") property;
				colorf nicename("Color") color;
			};

			s_tag_block_definition<s_integers1_definition> nicename("Integers") integers_block;
			s_tag_block_definition<s_floats1_definition> nicename("Floats") floats_block;
			s_tag_block_definition<s_string_ids_definition> nicename("String IDs") string_ids_block;
			s_tag_block_definition<s_resources1_definition> nicename("Resources") resources_block;
			s_tag_block_definition<s_text1_definition> nicename("Text") text_block;
			s_tag_block_definition<s_colors1_definition> nicename("Colors") colors_block;
		};

		string_id nicename("Name") name;
		int32_t __unknown0;
		s_tag_block_definition<s_property_pool_definition> nicename("Property Pool") property_pool_block;
		s_tag_block_definition<s_components1_definition> nicename("Components") components_block;
	};

	struct nicename("Expressions") s_expressions_definition
	{
		struct nicename("Expression Makeup") s_expression_makeup_definition
		{
			enum nicename("Kind") e_kind : uint8_t
			{
				/*nicename("Operator")*/ _kind_$operator = 1ui8,
				/*nicename("Variable")*/ _kind_variable = 2ui8,
				/*nicename("Value")*/ _kind_value = 3ui8,
			};

			enum nicename("Operator") e_$operator : uint8_t
			{
				/*nicename("addition/none")*/ _$operator_addition_none = 1ui8,
				/*nicename("subtraction")*/ _$operator_subtraction = 2ui8,
				/*nicename("multiplication")*/ _$operator_multiplication = 3ui8,
				/*nicename("division")*/ _$operator_division = 4ui8,
				/*nicename("unary subtraction")*/ _$operator_unary_subtraction = 5ui8,
				/*nicename("not")*/ _$operator_not = 6ui8,
				/*nicename("less than")*/ _$operator_less_than = 7ui8,
				/*nicename("less than or equal to")*/ _$operator_less_than_or_equal_to = 8ui8,
				/*nicename("greater than")*/ _$operator_greater_than = 9ui8,
				/*nicename("greater than or equal to")*/ _$operator_greater_than_or_equal_to = 10ui8,
				/*nicename("equal to")*/ _$operator_equal_to = 11ui8,
				/*nicename("not equal to")*/ _$operator_not_equal_to = 12ui8,
				/*nicename("logical and")*/ _$operator_logical_and = 13ui8,
				/*nicename("logical or")*/ _$operator_logical_or = 14ui8,
			};

			enum nicename("Variable") e_variable : uint8_t
			{
				/*nicename("a/none")*/ _variable_a_none = 1ui8,
				/*nicename("b")*/ _variable_b = 2ui8,
				/*nicename("c")*/ _variable_c = 3ui8,
				/*nicename("d")*/ _variable_d = 4ui8,
				/*nicename("e")*/ _variable_e = 5ui8,
				/*nicename("f")*/ _variable_f = 6ui8,
				/*nicename("g")*/ _variable_g = 7ui8,
				/*nicename("h")*/ _variable_h = 8ui8,
				/*nicename("i")*/ _variable_i = 9ui8,
				/*nicename("j")*/ _variable_j = 10ui8,
				/*nicename("k")*/ _variable_k = 11ui8,
				/*nicename("l")*/ _variable_l = 12ui8,
				/*nicename("m")*/ _variable_m = 13ui8,
				/*nicename("n")*/ _variable_n = 14ui8,
				/*nicename("o")*/ _variable_o = 15ui8,
				/*nicename("p")*/ _variable_p = 16ui8,
				/*nicename("q")*/ _variable_q = 17ui8,
				/*nicename("r")*/ _variable_r = 18ui8,
				/*nicename("s")*/ _variable_s = 19ui8,
				/*nicename("t")*/ _variable_t = 20ui8,
				/*nicename("u")*/ _variable_u = 21ui8,
				/*nicename("v")*/ _variable_v = 22ui8,
				/*nicename("w")*/ _variable_w = 23ui8,
				/*nicename("x")*/ _variable_x = 24ui8,
				/*nicename("y")*/ _variable_y = 25ui8,
				/*nicename("z")*/ _variable_z = 26ui8,
			};

			e_kind nicename("Kind") kind;
			e_$operator nicename("Operator") $operator;
			e_variable nicename("Variable") variable;
			int8_t __unknown0;
			Undefined32 nicename("Value") value;
			Undefined32 __unknown1;
		};

		string_id nicename("Name") name;
		char nicename("Compiled Expression Reference") compiled_expression_reference[256];
		s_tag_block_definition<s_expression_makeup_definition> nicename("Expression Makeup") expression_makeup_block;
	};

	TagReference nicename("String Reference") string_reference_reference;
	s_tag_block_definition<s_templates_definition> nicename("Templates") templates_block;
	s_tag_block_definition<s_definitions_definition> nicename("Definitions") definitions_block;
	s_tag_block_definition<s_component_table_definition> nicename("Component Table") component_table_block;
	s_tag_block_definition<s_ui_definition> nicename("UI") ui_block;
	int32_t __unknown0;
	int32_t __unknown1;
	int32_t __unknown2;
	s_tag_block_definition<s_logic_definition> nicename("Logic") logic_block;
	s_tag_block_definition<s_defaults_definition> nicename("Defaults?") defaults_block;
	s_tag_block_definition<s_static_data_table_definition> nicename("Static Data Table") static_data_table_block;
	s_tag_block_definition<s_expressions_definition> nicename("Expressions") expressions_block;
};

