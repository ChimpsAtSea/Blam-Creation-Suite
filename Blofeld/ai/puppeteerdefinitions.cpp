#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(PuppetShowsBlock, MAXIMUM_PERFORMANCES_PER_SCENARIO)
{
	{ _field_string_id, "name^" },
	{ _field_string_id, "designerZone" },
	{ _field_struct, "manual bsp flags*" },
	{ _field_byte_flags, "flags" },
	{ _field_pad, "pad", 3 },
	{ _field_string, "icsPoint0" },
	{ _field_string, "icsPoint1" },
	{ _field_string, "icsPoint2" },
	{ _field_string, "icsPoint3" },
	{ _field_long_integer, "lastActionId" },
	{ _field_block, "puppets", &PuppetBlock_block },
	{ _field_block, "puppetHeaders", &PuppetHeaderBlock_block },
	{ _field_block, "actions", &PuppetActionHeaderBlock_block },
	{ _field_block, "subActions", &PuppetSubActionHeaderBlock_block },
	{ _field_block, "animations", &PuppetAnimationBlock_block },
	{ _field_block, "paths", &PuppetPathBlock_block },
	{ _field_block, "points", &PuppetPointBlock_block },
	{ _field_block, "branches", &PuppetBranchBlock_block },
	{ _field_block, "scripts", &PuppetScriptBlock_block },
	{ _field_block, "comments", &CommentsBlock_block },
	{ _field_terminator },
};

TAG_BLOCK(PuppetBlock, MAX_PUPPETS_PER_SHOW)
{
	{ _field_struct, "header" },
	{ _field_block, "actions", &PuppetActionBlock_block },
	{ _field_block, "subActions", &PuppetSubActionBlock_block },
	{ _field_block, "subTracks", &SubTracksBlock_block },
	{ _field_long_string, "comment" },
	{ _field_long_string, "startScript" },
	{ _field_long_string, "endScript" },
	{ _field_short_integer, "height" },
	{ _field_byte_flags, "editorFlags!*" },
	{ _field_pad, "pad", 1 },
	{ _field_terminator },
};

TAG_BLOCK(PuppetActionBlock, MAX_ACTIONS_PER_PUPPET)
{
	{ _field_struct, "header" },
	{ _field_struct, "animation" },
	{ _field_struct, "path" },
	{ _field_long_string, "comment" },
	{ _field_long_string, "animCondition" },
	{ _field_dword_integer, "color" },
	{ _field_byte_flags, "editorFlags!*" },
	{ _field_pad, "pad", 3 },
	{ _field_long_integer, "startFrame*" },
	{ _field_long_integer, "endFrame*" },
	{ _field_long_integer, "blendFrame*" },
	{ _field_long_integer, "startPixel*" },
	{ _field_long_integer, "endPixel*" },
	{ _field_long_integer, "blendPixel*" },
	{ _field_long_integer, "blendInDrag*" },
	{ _field_long_integer, "lengthDrag*" },
	{ _field_terminator },
};

TAG_BLOCK(PuppetSubActionBlock, MAX_SUB_ACTIONS_PER_PUPPET)
{
	{ _field_struct, "header" },
	{ _field_struct, "point" },
	{ _field_struct, "branch" },
	{ _field_struct, "script" },
	{ _field_long_string, "comment" },
	{ _field_long_string, "startCondition" },
	{ _field_long_string, "endCondition" },
	{ _field_long_string, "scriptText" },
	{ _field_block, "branchConditions", &PuppetScriptTextBlock_block },
	{ _field_dword_integer, "color" },
	{ _field_byte_integer, "subTrack" },
	{ _field_byte_flags, "editorFlags!*" },
	{ _field_pad, "pad", 2 },
	{ _field_long_integer, "startFrame*" },
	{ _field_long_integer, "endFrame*" },
	{ _field_long_integer, "startPixel*" },
	{ _field_long_integer, "endPixel*" },
	{ _field_long_integer, "subTrackDrag*" },
	{ _field_long_integer, "startOffsetDrag*" },
	{ _field_long_integer, "endOffsetDrag*" },
	{ _field_terminator },
};

TAG_BLOCK(PuppetScriptTextBlock, MAX_BRANCHES_PER_SUB_ACTION)
{
	{ _field_long_string, "scriptText" },
	{ _field_terminator },
};

TAG_BLOCK(SubTracksBlock, MAX_SUB_TRACKS)
{
	{ _field_string_id, "name^" },
	{ _field_terminator },
};

TAG_BLOCK(PuppetHeaderBlock, MAX_PUPPETS_PER_SHOW)
{
	{ _field_byte_flags, "flags" },
	{ _field_char_enum, "indexType~" },
	{ _field_pad, "pad", 2 },
	{ _field_string_id, "name" },
	{ _field_tag_reference, "type" },
	{ _field_string_id, "objectName" },
	{ _field_long_integer, "index~" },
	{ _field_struct, "position" },
	{ _field_string_id, "startScriptName" },
	{ _field_string_id, "endScriptName" },
	{ _field_short_integer, "startScript~" },
	{ _field_short_integer, "endScript~" },
	{ _field_short_integer, "firstAction" },
	{ _field_short_integer, "actionCount" },
	{ _field_short_integer, "firstSubAction" },
	{ _field_short_integer, "subActionCount" },
	{ _field_tag_reference, "additionalAnimations" },
	{ _field_terminator },
};

TAG_BLOCK(PuppetActionHeaderBlock, MAX_ACTIONS_PER_SHOW)
{
	{ _field_string_id, "name" },
	{ _field_long_integer, "id" },
	{ _field_long_integer, "blendIn" },
	{ _field_long_integer, "length" },
	{ _field_long_integer, "comment" },
	{ _field_char_enum, "blendType" },
	{ _field_char_enum, "type" },
	{ _field_short_integer, "dataIndex" },
	{ _field_terminator },
};

TAG_BLOCK(PuppetSubActionHeaderBlock, MAX_SUB_ACTIONS_PER_SHOW)
{
	{ _field_char_enum, "type" },
	{ _field_char_enum, "startType" },
	{ _field_char_enum, "endType" },
	{ _field_pad, "pad1", 1 },
	{ _field_long_integer, "startAction" },
	{ _field_long_integer, "startOffset" },
	{ _field_string_id, "startConditionScriptName" },
	{ _field_string_id, "endConditionScriptName" },
	{ _field_short_integer, "startCondition~" },
	{ _field_short_integer, "endCondition~" },
	{ _field_long_integer, "endAction" },
	{ _field_long_integer, "endOffset" },
	{ _field_long_integer, "comment" },
	{ _field_short_integer, "dataIndex" },
	{ _field_pad, "pad2", 2 },
	{ _field_terminator },
};

TAG_BLOCK(PuppetAnimationBlock, MAX_ACTIONS_PER_SHOW)
{
	{ _field_string_id, "name" },
	{ _field_struct, "position" },
	{ _field_byte_flags, "flags" },
	{ _field_char_enum, "posType" },
	{ _field_pad, "pad", 2 },
	{ _field_long_integer, "startFrame" },
	{ _field_long_integer, "endFrame" },
	{ _field_long_integer, "repeatCount" },
	{ _field_real, "scale" },
	{ _field_string_id, "conditionScriptName" },
	{ _field_long_integer, "condition~" },
	{ _field_terminator },
};

TAG_BLOCK(PuppetPathBlock, MAX_ACTIONS_PER_SHOW)
{
	{ _field_real, "throttle" },
	{ _field_block, "points", &PuppetPathPointBlock_block },
	{ _field_terminator },
};

TAG_BLOCK(PuppetPathPointBlock, MAX_POINTS_PER_PATH)
{
	{ _field_char_enum, "type" },
	{ _field_byte_flags, "flags" },
	{ _field_char_enum, "indexType~" },
	{ _field_pad, "pad", 1 },
	{ _field_string_id, "objectName" },
	{ _field_long_integer, "index~" },
	{ _field_string_id, "marker" },
	{ _field_real_point_3d, "pos" },
	{ _field_real_euler_angles_3d, "rot" },
	{ _field_terminator },
};

TAG_BLOCK(PuppetPointBlock, MAX_SUB_ACTIONS_PER_SHOW)
{
	{ _field_struct, "point" },
	{ _field_tag_reference, "asset" },
	{ _field_byte_flags, "flags" },
	{ _field_pad, "pad", 3 },
	{ _field_terminator },
};

TAG_BLOCK(PuppetBranchBlock, MAX_SUB_ACTIONS_PER_SHOW)
{
	{ _field_block, "elements", &PuppetSubActionBranchElementBlock_block },
	{ _field_terminator },
};

TAG_BLOCK(PuppetSubActionBranchElementBlock, MAX_BRANCHES_PER_SUB_ACTION)
{
	{ _field_long_integer, "targetAction" },
	{ _field_string_id, "conditionScriptName" },
	{ _field_long_integer, "condition~" },
	{ _field_terminator },
};

TAG_BLOCK(PuppetScriptBlock, MAX_SUB_ACTIONS_PER_SHOW)
{
	{ _field_string_id, "scriptName" },
	{ _field_long_integer, "script~" },
	{ _field_terminator },
};

TAG_BLOCK(CommentsBlock, 65536)
{
	{ _field_char_integer, "char" },
	{ _field_terminator },
};

} // namespace blofeld

