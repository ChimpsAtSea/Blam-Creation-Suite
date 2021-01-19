#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		style_sheet_list_group,
		STYLE_SHEET_LIST_TAG,
		nullptr,
		INVALID_TAG,
		style_sheet_list_block );

	TAG_BLOCK_FROM_STRUCT(
		style_sheet_list_block,
		"style_sheet_list_block",
		1,
		style_sheet_list_struct_definition);

	#define USERINTERFACESTYLESHEETLANGUAGESBLOCK_ID { 0xB9A0F180, 0xC79A4D66, 0xAEE61E30, 0x3F3DCC4F }
	TAG_BLOCK(
		UserInterfaceStyleSheetLanguagesBlock_block,
		"UserInterfaceStyleSheetLanguagesBlock",
		k_language_count,
		"UserInterfaceStyleSheets",
		USERINTERFACESTYLESHEETLANGUAGESBLOCK_ID)
	{
		{ _field_long_enum, "language^", &style_sheet_language_enum_definition },
		{ _field_block, "font style sheets", &UserInterfaceStyleSheetsFontBlock_block },
		{ _field_block, "visual style sheets", &UserInterfaceStyleSheetsVisualBlock_block },
		{ _field_terminator }
	};

	#define USERINTERFACESTYLESHEETSFONTBLOCK_ID { 0xB11128E6, 0x68214537, 0xA8E93260, 0x4E69F10F }
	TAG_BLOCK(
		UserInterfaceStyleSheetsFontBlock_block,
		"UserInterfaceStyleSheetsFontBlock",
		k_maximumNumberOfStyleSheets,
		"StyleFontData",
		USERINTERFACESTYLESHEETSFONTBLOCK_ID)
	{
		{ _field_string_id, "style sheet name^" },
		{ _field_block, "font id", &UserInterfaceStyleSheetFontIdBlock_block },
		{ _field_block, "text case", &UserInterfaceStyleSheetTextCaseBlock_block },
		{ _field_block, "justification", &UserInterfaceStyleSheetJustificationBlock_block },
		{ _field_block, "alignment", &UserInterfaceStyleSheetAlignmentBlock_block },
		{ _field_block, "scale", &UserInterfaceStyleSheetScaleBlock_block },
		{ _field_block, "fixed height", &UserInterfaceStyleSheetFixedHeightBlock_block },
		{ _field_terminator }
	};

	#define USERINTERFACESTYLESHEETFONTIDBLOCK_ID { 0x5BE81BA7, 0x18004680, 0xA65EB74C, 0x4E929FBD }
	TAG_BLOCK(
		UserInterfaceStyleSheetFontIdBlock_block,
		"UserInterfaceStyleSheetFontIdBlock",
		1,
		"FontId",
		USERINTERFACESTYLESHEETFONTIDBLOCK_ID)
	{
		{ _field_long_enum, "font id", &global_font_id_enum_definition },
		{ _field_terminator }
	};

	#define USERINTERFACESTYLESHEETTEXTCASEBLOCK_ID { 0xB05F2549, 0x82BB4259, 0x8F19D0C0, 0x516F62B1 }
	TAG_BLOCK(
		UserInterfaceStyleSheetTextCaseBlock_block,
		"UserInterfaceStyleSheetTextCaseBlock",
		1,
		"TextCase",
		USERINTERFACESTYLESHEETTEXTCASEBLOCK_ID)
	{
		{ _field_long_enum, "text case", &text_case_enum },
		{ _field_terminator }
	};

	#define USERINTERFACESTYLESHEETJUSTIFICATIONBLOCK_ID { 0x7A8DC166, 0x65D643A1, 0xB0736299, 0xEDDA2DF0 }
	TAG_BLOCK(
		UserInterfaceStyleSheetJustificationBlock_block,
		"UserInterfaceStyleSheetJustificationBlock",
		1,
		"TextJustification",
		USERINTERFACESTYLESHEETJUSTIFICATIONBLOCK_ID)
	{
		{ _field_long_enum, "justification", &justification_enum },
		{ _field_terminator }
	};

	#define USERINTERFACESTYLESHEETALIGNMENTBLOCK_ID { 0x4B81A801, 0x5BCB44F2, 0x85CE1AFF, 0x52B2B89C }
	TAG_BLOCK(
		UserInterfaceStyleSheetAlignmentBlock_block,
		"UserInterfaceStyleSheetAlignmentBlock",
		1,
		"TextAlignment",
		USERINTERFACESTYLESHEETALIGNMENTBLOCK_ID)
	{
		{ _field_long_enum, "alignment", &alignment_enum },
		{ _field_terminator }
	};

	#define USERINTERFACESTYLESHEETSCALEBLOCK_ID { 0xC5F63A73, 0xD27A4AB9, 0x98FA924C, 0xED24C942 }
	TAG_BLOCK(
		UserInterfaceStyleSheetScaleBlock_block,
		"UserInterfaceStyleSheetScaleBlock",
		1,
		"float",
		USERINTERFACESTYLESHEETSCALEBLOCK_ID)
	{
		{ _field_real, "value" },
		{ _field_terminator }
	};

	#define USERINTERFACESTYLESHEETFIXEDHEIGHTBLOCK_ID { 0x84C93CAC, 0x83CD4CCC, 0x998C57E3, 0xBF18BC0B }
	TAG_BLOCK(
		UserInterfaceStyleSheetFixedHeightBlock_block,
		"UserInterfaceStyleSheetFixedHeightBlock",
		1,
		"float",
		USERINTERFACESTYLESHEETFIXEDHEIGHTBLOCK_ID)
	{
		{ _field_real, "height" },
		{ _field_terminator }
	};

	#define USERINTERFACESTYLESHEETSVISUALBLOCK_ID { 0x47874FB6, 0x2A7B457C, 0xACFAFE1A, 0xBCCC9980 }
	TAG_BLOCK(
		UserInterfaceStyleSheetsVisualBlock_block,
		"UserInterfaceStyleSheetsVisualBlock",
		k_maximumNumberOfStyleSheets,
		"StyleVisualData",
		USERINTERFACESTYLESHEETSVISUALBLOCK_ID)
	{
		{ _field_string_id, "style sheet name^" },
		{ _field_block, "drop shadow style", &UserInterfaceStyleSheetDropShadowStyleBlock_block },
		{ _field_block, "text color", &UserInterfaceStyleSheetColorBlock_block },
		{ _field_block, "drop shadow color", &UserInterfaceStyleSheetColorBlock_block },
		{ _field_string_id, "gradient name" },
		{ _field_string_id, "dropshadow name" },
		{ _field_string_id, "outer glow name" },
		{ _field_terminator }
	};

	#define USERINTERFACESTYLESHEETDROPSHADOWSTYLEBLOCK_ID { 0xD10ED3B2, 0x6C5D4A22, 0x85467B00, 0x716A2FEC }
	TAG_BLOCK(
		UserInterfaceStyleSheetDropShadowStyleBlock_block,
		"UserInterfaceStyleSheetDropShadowStyleBlock",
		1,
		"TextDropShadowStyle",
		USERINTERFACESTYLESHEETDROPSHADOWSTYLEBLOCK_ID)
	{
		{ _field_long_enum, "drop shadow style", &drop_shadow_style_enum },
		{ _field_terminator }
	};

	#define USERINTERFACESTYLESHEETCOLORBLOCK_ID { 0x5FAF93B6, 0x5AF943A6, 0xA7655CBE, 0xF33914E7 }
	TAG_BLOCK(
		UserInterfaceStyleSheetColorBlock_block,
		"UserInterfaceStyleSheetColorBlock",
		1,
		"real_argb_color",
		USERINTERFACESTYLESHEETCOLORBLOCK_ID)
	{
		{ _field_real_argb_color, "color" },
		{ _field_terminator }
	};

	#define USERINTERFACESTYLESHEETGRADIENTBLOCK_ID { 0x1AC5DF38, 0x6EA64B1C, 0xAA35ED88, 0x791D8F42 }
	TAG_BLOCK(
		UserInterfaceStyleSheetGradientBlock_block,
		"UserInterfaceStyleSheetGradientBlock",
		32,
		"UserInterfaceStyleGradient",
		USERINTERFACESTYLESHEETGRADIENTBLOCK_ID)
	{
		{ _field_string_id, "gradient name^" },
		{ _field_real_argb_color, "color1" },
		{ _field_real_argb_color, "color2" },
		{ _field_real_argb_color, "color3" },
		{ _field_real_argb_color, "color4" },
		{ _field_real, "angle" },
		{ _field_real, "scale" },
		{ _field_real_vector_2d, "offset" },
		{ _field_long_integer, "number of colors" },
		{ _field_long_enum, "gradient shape", &gradient_shape_enum },
		{ _field_terminator }
	};

	#define USERINTERFACESTYLESHEETDROPSHADOWBLOCK_ID { 0xDA87E841, 0x04AF40A3, 0xA13AC821, 0xA28E40C4 }
	TAG_BLOCK(
		UserInterfaceStyleSheetDropshadowBlock_block,
		"UserInterfaceStyleSheetDropshadowBlock",
		32,
		"UserInterfaceStyleDropshadow",
		USERINTERFACESTYLESHEETDROPSHADOWBLOCK_ID)
	{
		{ _field_string_id, "dropshadow name^" },
		{ _field_real_argb_color, "color" },
		{ _field_real, "angle" },
		{ _field_real, "distance" },
		{ _field_real, "spread" },
		{ _field_real, "size" },
		{ _field_terminator }
	};

	#define USERINTERFACESTYLESHEETOUTERGLOWBLOCK_ID { 0xC337C467, 0x110E4346, 0x8C3AECD1, 0x9D9D6605 }
	TAG_BLOCK(
		UserInterfaceStyleSheetOuterGlowBlock_block,
		"UserInterfaceStyleSheetOuterGlowBlock",
		32,
		"UserInterfaceStyleOuterGlow",
		USERINTERFACESTYLESHEETOUTERGLOWBLOCK_ID)
	{
		{ _field_string_id, "outer glow name^" },
		{ _field_real_argb_color, "color" },
		{ _field_real, "spread" },
		{ _field_real, "size" },
		{ _field_terminator }
	};

	#define STYLE_SHEET_LIST_STRUCT_DEFINITION_ID { 0xC59ED09C, 0xE2CC4A35, 0xA7C67CF6, 0xBD5B6B99 }
	TAG_STRUCT(
		style_sheet_list_struct_definition,
		"style_sheet_list_struct_definition",
		"UserInterfaceStyleSheetLanguages",
		STYLE_SHEET_LIST_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "style sheet languages", &UserInterfaceStyleSheetLanguagesBlock_block },
		{ _field_block, "gradients", &UserInterfaceStyleSheetGradientBlock_block },
		{ _field_block, "dropshadows", &UserInterfaceStyleSheetDropshadowBlock_block },
		{ _field_block, "outer glows", &UserInterfaceStyleSheetOuterGlowBlock_block },
		{ _field_terminator }
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

} // namespace macaque

} // namespace blofeld

