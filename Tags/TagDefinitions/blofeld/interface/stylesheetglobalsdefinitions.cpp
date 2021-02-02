#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(style_sheet_list, STYLE_SHEET_LIST_TAG, style_sheet_list_block_block );

	V5_TAG_BLOCK(UserInterfaceStyleSheetFontIdBlock, 1)
	{
		{ _field_legacy, _field_long_enum, "font id", &global_font_id_enum_definition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(UserInterfaceStyleSheetTextCaseBlock, 1)
	{
		{ _field_legacy, _field_long_enum, "text case", &text_case_enum },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(UserInterfaceStyleSheetJustificationBlock, 1)
	{
		{ _field_legacy, _field_long_enum, "justification", &justification_enum },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(UserInterfaceStyleSheetAlignmentBlock, 1)
	{
		{ _field_legacy, _field_long_enum, "alignment", &alignment_enum },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(UserInterfaceStyleSheetScaleBlock, 1)
	{
		{ _field_legacy, _field_real, "value" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(UserInterfaceStyleSheetFixedHeightBlock, 1)
	{
		{ _field_legacy, _field_real, "height" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(UserInterfaceStyleSheetsFontBlock, k_maximumNumberOfStyleSheets)
	{
		{ _field_legacy, _field_string_id, "style sheet name^" },
		{ _field_legacy, _field_block, "font id", &UserInterfaceStyleSheetFontIdBlock_block },
		{ _field_legacy, _field_block, "text case", &UserInterfaceStyleSheetTextCaseBlock_block },
		{ _field_legacy, _field_block, "justification", &UserInterfaceStyleSheetJustificationBlock_block },
		{ _field_legacy, _field_block, "alignment", &UserInterfaceStyleSheetAlignmentBlock_block },
		{ _field_legacy, _field_block, "scale", &UserInterfaceStyleSheetScaleBlock_block },
		{ _field_legacy, _field_block, "fixed height", &UserInterfaceStyleSheetFixedHeightBlock_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(UserInterfaceStyleSheetDropShadowStyleBlock, 1)
	{
		{ _field_legacy, _field_long_enum, "drop shadow style", &drop_shadow_style_enum },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(UserInterfaceStyleSheetColorBlock, 1)
	{
		{ _field_legacy, _field_real_argb_color, "color" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(UserInterfaceStyleSheetsVisualBlock, k_maximumNumberOfStyleSheets)
	{
		{ _field_legacy, _field_string_id, "style sheet name^" },
		{ _field_legacy, _field_block, "drop shadow style", &UserInterfaceStyleSheetDropShadowStyleBlock_block },
		{ _field_legacy, _field_block, "text color", &UserInterfaceStyleSheetColorBlock_block },
		{ _field_legacy, _field_block, "drop shadow color", &UserInterfaceStyleSheetColorBlock_block },
		{ _field_legacy, _field_string_id, "gradient name" },
		{ _field_legacy, _field_string_id, "dropshadow name" },
		{ _field_legacy, _field_string_id, "outer glow name" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(UserInterfaceStyleSheetLanguagesBlock, k_language_count)
	{
		{ _field_legacy, _field_long_enum, "language^", &style_sheet_language_enum_definition },
		{ _field_legacy, _field_block, "font style sheets", &UserInterfaceStyleSheetsFontBlock_block },
		{ _field_legacy, _field_block, "visual style sheets", &UserInterfaceStyleSheetsVisualBlock_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(UserInterfaceStyleSheetGradientBlock, 32)
	{
		{ _field_legacy, _field_string_id, "gradient name^" },
		{ _field_legacy, _field_real_argb_color, "color1" },
		{ _field_legacy, _field_real_argb_color, "color2" },
		{ _field_legacy, _field_real_argb_color, "color3" },
		{ _field_legacy, _field_real_argb_color, "color4" },
		{ _field_legacy, _field_real, "angle" },
		{ _field_legacy, _field_real, "scale" },
		{ _field_legacy, _field_real_vector_2d, "offset" },
		{ _field_legacy, _field_long_integer, "number of colors" },
		{ _field_legacy, _field_long_enum, "gradient shape", &gradient_shape_enum },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(UserInterfaceStyleSheetDropshadowBlock, 32)
	{
		{ _field_legacy, _field_string_id, "dropshadow name^" },
		{ _field_legacy, _field_real_argb_color, "color" },
		{ _field_legacy, _field_real, "angle" },
		{ _field_legacy, _field_real, "distance" },
		{ _field_legacy, _field_real, "spread" },
		{ _field_legacy, _field_real, "size" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(UserInterfaceStyleSheetOuterGlowBlock, 32)
	{
		{ _field_legacy, _field_string_id, "outer glow name^" },
		{ _field_legacy, _field_real_argb_color, "color" },
		{ _field_legacy, _field_real, "spread" },
		{ _field_legacy, _field_real, "size" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(style_sheet_list_block, 1, style_sheet_list_struct_definition_struct_definition );

	V5_TAG_STRUCT(style_sheet_list_struct_definition)
	{
		{ _field_legacy, _field_block, "style sheet languages", &UserInterfaceStyleSheetLanguagesBlock_block },
		{ _field_legacy, _field_block, "gradients", &UserInterfaceStyleSheetGradientBlock_block },
		{ _field_legacy, _field_block, "dropshadows", &UserInterfaceStyleSheetDropshadowBlock_block },
		{ _field_legacy, _field_block, "outer glows", &UserInterfaceStyleSheetOuterGlowBlock_block },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(text_case_enum)
	{
		"normal",
		"uppercase",
		"lowercase"
	};
	STRING_LIST(text_case_enum, text_case_enum_strings, _countof(text_case_enum_strings));

	STRINGS(justification_enum)
	{
		"left",
		"right",
		"center"
	};
	STRING_LIST(justification_enum, justification_enum_strings, _countof(justification_enum_strings));

	STRINGS(alignment_enum)
	{
		"top",
		"bottom",
		"center"
	};
	STRING_LIST(alignment_enum, alignment_enum_strings, _countof(alignment_enum_strings));

	STRINGS(drop_shadow_style_enum)
	{
		"none",
		"drop",
		"outline"
	};
	STRING_LIST(drop_shadow_style_enum, drop_shadow_style_enum_strings, _countof(drop_shadow_style_enum_strings));

	STRINGS(style_sheet_language_enum_definition)
	{
		"english",
		"japanese",
		"german",
		"french",
		"spanish",
		"mexican spanish",
		"italian",
		"korean",
		"chinese-traditional",
		"chinese-simplified",
		"portuguese",
		"polish",
		"russian",
		"danish",
		"finnish",
		"dutch",
		"norwegian"
	};
	STRING_LIST(style_sheet_language_enum_definition, style_sheet_language_enum_definition_strings, _countof(style_sheet_language_enum_definition_strings));

	STRINGS(gradient_shape_enum)
	{
		"linear",
		"circular",
		"diamond",
		"square"
	};
	STRING_LIST(gradient_shape_enum, gradient_shape_enum_strings, _countof(gradient_shape_enum_strings));

	TAG_REFERENCE(style_sheets_global_reference, STYLE_SHEET_LIST_TAG);

} // namespace blofeld

