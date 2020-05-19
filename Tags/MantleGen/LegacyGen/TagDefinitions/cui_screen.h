#pragma once

struct nicename("cui_screen") tag_group('cusc') s_cui_screen_definition_legacy
{
	struct nicename("Templates") s_templates_definition_legacy
	{
		s_tag_reference_legacy nicename("Template") template_reference;
	};

	struct nicename("Definitions") s_definitions_definition_legacy
	{
		string_id_legacy nicename("Import Name") import_name;
		string_id_legacy nicename("Export Name") export_name;
		string_id_legacy nicename("Logic Group") logic_group;
		int16_t __unknown0;
		int16_t nicename("Template Index") template_index;
	};

	struct nicename("Component Table") s_component_table_definition_legacy
	{
		string_id_legacy nicename("Component Name") component_name;
		int16_t nicename("Definition Index") definition_index;
		int16_t __unknown0;
	};

	struct nicename("UI") s_ui_definition_legacy
	{
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

			struct nicename("String ID") s_string_id_definition_legacy
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

			string_id_legacy nicename("Component Name") component_name;
			s_tag_block_legacy<s_integers_definition_legacy> nicename("Integers") integers_block;
			s_tag_block_legacy<s_floats_definition_legacy> nicename("Floats") floats_block;
			s_tag_block_legacy<s_string_id_definition_legacy> nicename("String ID") string_id_block;
			s_tag_block_legacy<s_resources_definition_legacy> nicename("Resources") resources_block;
			s_tag_block_legacy<s_text_definition_legacy> nicename("Text") text_block;
			s_tag_block_legacy<s_colors_definition_legacy> nicename("Colors") colors_block;
		};

		struct nicename("Animations") s_animations_definition_legacy
		{
			struct nicename("Component") s_component_definition_legacy
			{
				struct nicename("Standard Animations") s_standard_animations_definition_legacy
				{
					struct nicename("Values") s_values_definition_legacy
					{
						int32_t nicename("Frame") frame;
						float nicename("Value") value;
						s_data_reference_legacy nicename("Data") data_data_reference;
					};

					string_id_legacy nicename("Property") property;
					int16_t __unknown0;
					int8_t __unknown1;
					int8_t __unknown2;
					int32_t nicename("Frame Count") frame_count;
					s_tag_block_legacy<s_values_definition_legacy> nicename("Values") values_block;
				};

				struct nicename("Color Animations") s_color_animations_definition_legacy
				{
					struct nicename("Values") s_values1_definition_legacy
					{
						int32_t nicename("Frame") frame;
						s_colorf_legacy nicename("Color") color;
						s_data_reference_legacy nicename("Data") data_data_reference;
					};

					string_id_legacy nicename("Property") property;
					int16_t __unknown0;
					int8_t __unknown1;
					int8_t __unknown2;
					int32_t nicename("Frame Count") frame_count;
					s_tag_block_legacy<s_values1_definition_legacy> nicename("Values") values_block;
				};

				string_id_legacy nicename("Name") name;
				int32_t nicename("Frame Count") frame_count;
				s_tag_block_legacy<s_standard_animations_definition_legacy> nicename("Standard Animations") standard_animations_block;
				s_tag_block_legacy<s_color_animations_definition_legacy> nicename("Color Animations") color_animations_block;
			};

			string_id_legacy nicename("Name") name;
			s_tag_block_legacy<s_component_definition_legacy> nicename("Component") component_block;
		};

		string_id_legacy nicename("Resolution") resolution;
		string_id_legacy nicename("Theme") theme;
		s_tag_block_legacy<s_components_definition_legacy> nicename("Components") components_block;
		s_tag_block_legacy<s_animations_definition_legacy> nicename("Animations") animations_block;
	};

	struct nicename("Logic") s_logic_definition_legacy
	{
		int16_t nicename("Flags") flags;
		int16_t nicename("Flags") flags1;
		string_id_legacy nicename("Input Component") input_component;
		string_id_legacy nicename("Input Property") input_property;
		string_id_legacy nicename("Output Component") output_component;
		string_id_legacy nicename("Ouput Property") ouput_property;
	};

	struct nicename("Defaults?") s_defaults_definition_legacy
	{
		string_id_legacy __unknown0;
		string_id_legacy __unknown1;
		int8_t __unknown2;
		int8_t __unknown3;
		int8_t __unknown4;
		int8_t __unknown5;
		int32_t __unknown6;
	};

	struct nicename("Static Data Table") s_static_data_table_definition_legacy
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

		struct nicename("Components") s_components1_definition_legacy
		{
			struct nicename("Integers") s_integers1_definition_legacy
			{
				string_id_legacy nicename("Property") property;
				int32_t nicename("Value") value;
			};

			struct nicename("Floats") s_floats1_definition_legacy
			{
				string_id_legacy nicename("Property") property;
				float nicename("Value") value;
			};

			struct nicename("String IDs") s_string_ids_definition_legacy
			{
				string_id_legacy nicename("Property") property;
				string_id_legacy nicename("String") string;
			};

			struct nicename("Resources") s_resources1_definition_legacy
			{
				string_id_legacy nicename("Property") property;
				s_tag_reference_legacy nicename("Resource") resource_reference;
			};

			struct nicename("Text") s_text1_definition_legacy
			{
				string_id_legacy nicename("Property") property;
				char nicename("Text") text[256];
			};

			struct nicename("Colors") s_colors1_definition_legacy
			{
				string_id_legacy nicename("Property") property;
				s_colorf_legacy nicename("Color") color;
			};

			s_tag_block_legacy<s_integers1_definition_legacy> nicename("Integers") integers_block;
			s_tag_block_legacy<s_floats1_definition_legacy> nicename("Floats") floats_block;
			s_tag_block_legacy<s_string_ids_definition_legacy> nicename("String IDs") string_ids_block;
			s_tag_block_legacy<s_resources1_definition_legacy> nicename("Resources") resources_block;
			s_tag_block_legacy<s_text1_definition_legacy> nicename("Text") text_block;
			s_tag_block_legacy<s_colors1_definition_legacy> nicename("Colors") colors_block;
		};

		string_id_legacy nicename("Name") name;
		int32_t __unknown0;
		s_tag_block_legacy<s_property_pool_definition_legacy> nicename("Property Pool") property_pool_block;
		s_tag_block_legacy<s_components1_definition_legacy> nicename("Components") components_block;
	};

	struct nicename("Expressions") s_expressions_definition_legacy
	{
		struct nicename("Expression Makeup") s_expression_makeup_definition_legacy
		{
			enum nicename("Kind") e_kind : uint8_t
			{
				/*nicename("Operator")*/ _kind_$operator = 0ui8,
				/*nicename("Variable")*/ _kind_variable = 1ui8,
				/*nicename("Value")*/ _kind_value = 2ui8,
			};

			enum nicename("Operator") e_$operator : uint8_t
			{
				/*nicename("addition/none")*/ _$operator_addition_none = 0ui8,
				/*nicename("subtraction")*/ _$operator_subtraction = 1ui8,
				/*nicename("multiplication")*/ _$operator_multiplication = 2ui8,
				/*nicename("division")*/ _$operator_division = 3ui8,
				/*nicename("unary subtraction")*/ _$operator_unary_subtraction = 4ui8,
				/*nicename("not")*/ _$operator_not = 5ui8,
				/*nicename("less than")*/ _$operator_less_than = 6ui8,
				/*nicename("less than or equal to")*/ _$operator_less_than_or_equal_to = 7ui8,
				/*nicename("greater than")*/ _$operator_greater_than = 8ui8,
				/*nicename("greater than or equal to")*/ _$operator_greater_than_or_equal_to = 9ui8,
				/*nicename("equal to")*/ _$operator_equal_to = 10ui8,
				/*nicename("not equal to")*/ _$operator_not_equal_to = 11ui8,
				/*nicename("logical and")*/ _$operator_logical_and = 12ui8,
				/*nicename("logical or")*/ _$operator_logical_or = 13ui8,
			};

			enum nicename("Variable") e_variable : uint8_t
			{
				/*nicename("a/none")*/ _variable_a_none = 0ui8,
				/*nicename("b")*/ _variable_b = 1ui8,
				/*nicename("c")*/ _variable_c = 2ui8,
				/*nicename("d")*/ _variable_d = 3ui8,
				/*nicename("e")*/ _variable_e = 4ui8,
				/*nicename("f")*/ _variable_f = 5ui8,
				/*nicename("g")*/ _variable_g = 6ui8,
				/*nicename("h")*/ _variable_h = 7ui8,
				/*nicename("i")*/ _variable_i = 8ui8,
				/*nicename("j")*/ _variable_j = 9ui8,
				/*nicename("k")*/ _variable_k = 10ui8,
				/*nicename("l")*/ _variable_l = 11ui8,
				/*nicename("m")*/ _variable_m = 12ui8,
				/*nicename("n")*/ _variable_n = 13ui8,
				/*nicename("o")*/ _variable_o = 14ui8,
				/*nicename("p")*/ _variable_p = 15ui8,
				/*nicename("q")*/ _variable_q = 16ui8,
				/*nicename("r")*/ _variable_r = 17ui8,
				/*nicename("s")*/ _variable_s = 18ui8,
				/*nicename("t")*/ _variable_t = 19ui8,
				/*nicename("u")*/ _variable_u = 20ui8,
				/*nicename("v")*/ _variable_v = 21ui8,
				/*nicename("w")*/ _variable_w = 22ui8,
				/*nicename("x")*/ _variable_x = 23ui8,
				/*nicename("y")*/ _variable_y = 24ui8,
				/*nicename("z")*/ _variable_z = 25ui8,
			};

			e_kind nicename("Kind") kind;
			e_$operator nicename("Operator") $operator;
			e_variable nicename("Variable") variable;
			int8_t __unknown0;
			s_undefined32_legacy nicename("Value") value;
			s_undefined32_legacy __unknown1;
		};

		string_id_legacy nicename("Name") name;
		char nicename("Compiled Expression Reference") compiled_expression_reference[256];
		s_tag_block_legacy<s_expression_makeup_definition_legacy> nicename("Expression Makeup") expression_makeup_block;
	};

	s_tag_reference_legacy nicename("String Reference") string_reference_reference;
	s_tag_block_legacy<s_templates_definition_legacy> nicename("Templates") templates_block;
	s_tag_block_legacy<s_definitions_definition_legacy> nicename("Definitions") definitions_block;
	s_tag_block_legacy<s_component_table_definition_legacy> nicename("Component Table") component_table_block;
	s_tag_block_legacy<s_ui_definition_legacy> nicename("UI") ui_block;
	int32_t __unknown0;
	int32_t __unknown1;
	int32_t __unknown2;
	s_tag_block_legacy<s_logic_definition_legacy> nicename("Logic") logic_block;
	s_tag_block_legacy<s_defaults_definition_legacy> nicename("Defaults?") defaults_block;
	s_tag_block_legacy<s_static_data_table_definition_legacy> nicename("Static Data Table") static_data_table_block;
	s_tag_block_legacy<s_expressions_definition_legacy> nicename("Expressions") expressions_block;
};

