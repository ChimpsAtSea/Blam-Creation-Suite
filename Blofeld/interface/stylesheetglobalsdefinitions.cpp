#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(UserInterfaceStyleSheetLanguagesBlock, k_language_count)
{
	{ _field_long_enum, "language^" },
	{ _field_block, "font style sheets", &UserInterfaceStyleSheetsFontBlock_block },
	{ _field_block, "visual style sheets", &UserInterfaceStyleSheetsVisualBlock_block },
	{ _field_terminator },
};

TAG_BLOCK(UserInterfaceStyleSheetsFontBlock, k_maximumNumberOfStyleSheets)
{
	{ _field_string_id, "style sheet name^" },
	{ _field_block, "font id", &UserInterfaceStyleSheetFontIdBlock_block },
	{ _field_block, "text case", &UserInterfaceStyleSheetTextCaseBlock_block },
	{ _field_block, "justification", &UserInterfaceStyleSheetJustificationBlock_block },
	{ _field_block, "alignment", &UserInterfaceStyleSheetAlignmentBlock_block },
	{ _field_block, "scale", &UserInterfaceStyleSheetScaleBlock_block },
	{ _field_block, "fixed height", &UserInterfaceStyleSheetFixedHeightBlock_block },
	{ _field_terminator },
};

TAG_BLOCK(UserInterfaceStyleSheetFontIdBlock, 1)
{
	{ _field_long_enum, "font id" },
	{ _field_terminator },
};

TAG_BLOCK(UserInterfaceStyleSheetTextCaseBlock, 1)
{
	{ _field_long_enum, "text case" },
	{ _field_terminator },
};

TAG_BLOCK(UserInterfaceStyleSheetJustificationBlock, 1)
{
	{ _field_long_enum, "justification" },
	{ _field_terminator },
};

TAG_BLOCK(UserInterfaceStyleSheetAlignmentBlock, 1)
{
	{ _field_long_enum, "alignment" },
	{ _field_terminator },
};

TAG_BLOCK(UserInterfaceStyleSheetScaleBlock, 1)
{
	{ _field_real, "value" },
	{ _field_terminator },
};

TAG_BLOCK(UserInterfaceStyleSheetFixedHeightBlock, 1)
{
	{ _field_real, "height" },
	{ _field_terminator },
};

TAG_BLOCK(UserInterfaceStyleSheetsVisualBlock, k_maximumNumberOfStyleSheets)
{
	{ _field_string_id, "style sheet name^" },
	{ _field_block, "drop shadow style", &UserInterfaceStyleSheetDropShadowStyleBlock_block },
	{ _field_block, "text color", &UserInterfaceStyleSheetColorBlock_block },
	{ _field_block, "drop shadow color", &UserInterfaceStyleSheetColorBlock_block },
	{ _field_string_id, "gradient name" },
	{ _field_string_id, "dropshadow name" },
	{ _field_string_id, "outer glow name" },
	{ _field_terminator },
};

TAG_BLOCK(UserInterfaceStyleSheetDropShadowStyleBlock, 1)
{
	{ _field_long_enum, "drop shadow style" },
	{ _field_terminator },
};

TAG_BLOCK(UserInterfaceStyleSheetColorBlock, 1)
{
	{ _field_real_argb_color, "color" },
	{ _field_terminator },
};

TAG_BLOCK(UserInterfaceStyleSheetGradientBlock, 32)
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
	{ _field_long_enum, "gradient shape" },
	{ _field_terminator },
};

TAG_BLOCK(UserInterfaceStyleSheetDropshadowBlock, 32)
{
	{ _field_string_id, "dropshadow name^" },
	{ _field_real_argb_color, "color" },
	{ _field_real, "angle" },
	{ _field_real, "distance" },
	{ _field_real, "spread" },
	{ _field_real, "size" },
	{ _field_terminator },
};

TAG_BLOCK(UserInterfaceStyleSheetOuterGlowBlock, 32)
{
	{ _field_string_id, "outer glow name^" },
	{ _field_real_argb_color, "color" },
	{ _field_real, "spread" },
	{ _field_real, "size" },
	{ _field_terminator },
};

TAG_GROUP(style_sheet_list, STYLE_SHEET_LIST_TAG)
{
	{ _field_block, "style sheet languages", &UserInterfaceStyleSheetLanguagesBlock_block },
	{ _field_block, "gradients", &UserInterfaceStyleSheetGradientBlock_block },
	{ _field_block, "dropshadows", &UserInterfaceStyleSheetDropshadowBlock_block },
	{ _field_block, "outer glows", &UserInterfaceStyleSheetOuterGlowBlock_block },
	{ _field_terminator },
};

} // namespace blofeld

