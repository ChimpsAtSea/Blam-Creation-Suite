#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK_FROM_STRUCT(PuppetPathPointBlock, MAX_POINTS_PER_PATH, PuppetPathPointStruct_struct_definition );

	V5_TAG_BLOCK(PuppetActionBlock, MAX_ACTIONS_PER_PUPPET)
	{
		{ _field_legacy, _field_struct, "header", &PuppetActionHeaderStruct_struct_definition },
		{ _field_legacy, _field_struct, "animation", &PuppetActionAnimationStruct_struct_definition },
		{ _field_legacy, _field_struct, "path", &PuppetActionPathStruct_struct_definition },
		{ _field_legacy, _field_long_string, "comment" },
		{ _field_legacy, _field_long_string, "animCondition" },
		{ _field_legacy, _field_dword_integer, "color" },
		{ _field_legacy, _field_byte_flags, "editorFlags!*", &PuppetEditorFlagsDefinition },
		{ _field_legacy, _field_pad, "pad", 3 },
		{ _field_legacy, _field_long_integer, "startFrame*" },
		{ _field_legacy, _field_long_integer, "endFrame*" },
		{ _field_legacy, _field_long_integer, "blendFrame*" },
		{ _field_legacy, _field_long_integer, "startPixel*" },
		{ _field_legacy, _field_long_integer, "endPixel*" },
		{ _field_legacy, _field_long_integer, "blendPixel*" },
		{ _field_legacy, _field_long_integer, "blendInDrag*" },
		{ _field_legacy, _field_long_integer, "lengthDrag*" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(PuppetSubActionBranchElementBlock, MAX_BRANCHES_PER_SUB_ACTION)
	{
		{ _field_legacy, _field_long_integer, "targetAction" },
		{ _field_legacy, _field_string_id, "conditionScriptName" },
		{ _field_legacy, _field_long_integer, "condition~" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(PuppetScriptTextBlock, MAX_BRANCHES_PER_SUB_ACTION)
	{
		{ _field_legacy, _field_long_string, "scriptText" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(PuppetSubActionBlock, MAX_SUB_ACTIONS_PER_PUPPET)
	{
		{ _field_legacy, _field_struct, "header", &PuppetSubActionHeaderStruct_struct_definition },
		{ _field_legacy, _field_struct, "point", &PuppetSubActionPointStruct_struct_definition },
		{ _field_legacy, _field_struct, "branch", &PuppetSubActionBranchStruct_struct_definition },
		{ _field_legacy, _field_struct, "script", &PuppetSubActionScriptStruct_struct_definition },
		{ _field_legacy, _field_long_string, "comment" },
		{ _field_legacy, _field_long_string, "startCondition" },
		{ _field_legacy, _field_long_string, "endCondition" },
		{ _field_legacy, _field_long_string, "scriptText" },
		{ _field_legacy, _field_block, "branchConditions", &PuppetScriptTextBlock_block },
		{ _field_legacy, _field_dword_integer, "color" },
		{ _field_legacy, _field_byte_integer, "subTrack" },
		{ _field_legacy, _field_byte_flags, "editorFlags!*", &PuppetEditorFlagsDefinition },
		{ _field_legacy, _field_pad, "pad", 2 },
		{ _field_legacy, _field_long_integer, "startFrame*" },
		{ _field_legacy, _field_long_integer, "endFrame*" },
		{ _field_legacy, _field_long_integer, "startPixel*" },
		{ _field_legacy, _field_long_integer, "endPixel*" },
		{ _field_legacy, _field_long_integer, "subTrackDrag*" },
		{ _field_legacy, _field_long_integer, "startOffsetDrag*" },
		{ _field_legacy, _field_long_integer, "endOffsetDrag*" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(SubTracksBlock, MAX_SUB_TRACKS)
	{
		{ _field_legacy, _field_string_id, "name^" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(PuppetBlock, MAX_PUPPETS_PER_SHOW)
	{
		{ _field_legacy, _field_struct, "header", &PuppetHeaderStruct_struct_definition },
		{ _field_legacy, _field_block, "actions", &PuppetActionBlock_block },
		{ _field_legacy, _field_block, "subActions", &PuppetSubActionBlock_block },
		{ _field_legacy, _field_block, "subTracks", &SubTracksBlock_block },
		{ _field_legacy, _field_long_string, "comment" },
		{ _field_legacy, _field_long_string, "startScript" },
		{ _field_legacy, _field_long_string, "endScript" },
		{ _field_legacy, _field_short_integer, "height" },
		{ _field_legacy, _field_byte_flags, "editorFlags!*", &PuppetEditorFlagsDefinition },
		{ _field_legacy, _field_pad, "pad", 1 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(PuppetHeaderBlock, MAX_PUPPETS_PER_SHOW, PuppetHeaderStruct_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(PuppetActionHeaderBlock, MAX_ACTIONS_PER_SHOW, PuppetActionHeaderStruct_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(PuppetSubActionHeaderBlock, MAX_SUB_ACTIONS_PER_SHOW, PuppetSubActionHeaderStruct_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(PuppetAnimationBlock, MAX_ACTIONS_PER_SHOW, PuppetActionAnimationStruct_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(PuppetPathBlock, MAX_ACTIONS_PER_SHOW, PuppetActionPathStruct_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(PuppetPointBlock, MAX_SUB_ACTIONS_PER_SHOW, PuppetSubActionPointStruct_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(PuppetBranchBlock, MAX_SUB_ACTIONS_PER_SHOW, PuppetSubActionBranchStruct_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(PuppetScriptBlock, MAX_SUB_ACTIONS_PER_SHOW, PuppetSubActionScriptStruct_struct_definition );

	V5_TAG_BLOCK(CommentsBlock, 65536)
	{
		{ _field_legacy, _field_char_integer, "char" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(PuppetShowsBlock, MAXIMUM_PERFORMANCES_PER_SCENARIO)
	{
		{ _field_legacy, _field_string_id, "name^" },
		{ _field_legacy, _field_string_id, "designerZone" },
		{ _field_legacy, _field_struct, "manual bsp flags*", &manualBspFlagsReferences_struct_definition },
		{ _field_legacy, _field_byte_flags, "flags", &PuppetShowFlagsDefinition },
		{ _field_legacy, _field_pad, "pad", 3 },
		{ _field_legacy, _field_string, "icsPoint0" },
		{ _field_legacy, _field_string, "icsPoint1" },
		{ _field_legacy, _field_string, "icsPoint2" },
		{ _field_legacy, _field_string, "icsPoint3" },
		{ _field_legacy, _field_long_integer, "lastActionId" },
		{ _field_legacy, _field_block, "puppets", &PuppetBlock_block },
		{ _field_legacy, _field_block, "puppetHeaders", &PuppetHeaderBlock_block },
		{ _field_legacy, _field_block, "actions", &PuppetActionHeaderBlock_block },
		{ _field_legacy, _field_block, "subActions", &PuppetSubActionHeaderBlock_block },
		{ _field_legacy, _field_block, "animations", &PuppetAnimationBlock_block },
		{ _field_legacy, _field_block, "paths", &PuppetPathBlock_block },
		{ _field_legacy, _field_block, "points", &PuppetPointBlock_block },
		{ _field_legacy, _field_block, "branches", &PuppetBranchBlock_block },
		{ _field_legacy, _field_block, "scripts", &PuppetScriptBlock_block },
		{ _field_legacy, _field_block, "comments", &CommentsBlock_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(PuppetHeaderStruct)
	{
		{ _field_legacy, _field_byte_flags, "flags", &PuppetFlagsDefinition },
		{ _field_legacy, _field_char_enum, "indexType~", &PuppetIndexTypeEnum },
		{ _field_legacy, _field_pad, "pad", 2 },
		{ _field_legacy, _field_string_id, "name" },
		{ _field_legacy, _field_tag_reference, "type", &PuppetHeaderStruct_type_reference },
		{ _field_legacy, _field_string_id, "objectName" },
		{ _field_legacy, _field_long_integer, "index~" },
		{ _field_legacy, _field_struct, "position", &PuppetPathPointStruct_struct_definition },
		{ _field_legacy, _field_string_id, "startScriptName" },
		{ _field_legacy, _field_string_id, "endScriptName" },
		{ _field_legacy, _field_short_integer, "startScript~" },
		{ _field_legacy, _field_short_integer, "endScript~" },
		{ _field_legacy, _field_short_integer, "firstAction" },
		{ _field_legacy, _field_short_integer, "actionCount" },
		{ _field_legacy, _field_short_integer, "firstSubAction" },
		{ _field_legacy, _field_short_integer, "subActionCount" },
		{ _field_legacy, _field_tag_reference, "additionalAnimations", &model_animation_graph_reference$3 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(PuppetPathPointStruct)
	{
		{ _field_legacy, _field_char_enum, "type", &PuppetPathPointTypeEnum },
		{ _field_legacy, _field_byte_flags, "flags", &PuppetPathPointFlagsDefinition },
		{ _field_legacy, _field_char_enum, "indexType~", &PuppetIndexTypeEnum },
		{ _field_legacy, _field_pad, "pad", 1 },
		{ _field_legacy, _field_string_id, "objectName" },
		{ _field_legacy, _field_long_integer, "index~" },
		{ _field_legacy, _field_string_id, "marker" },
		{ _field_legacy, _field_real_point_3d, "pos" },
		{ _field_legacy, _field_real_euler_angles_3d, "rot" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(PuppetActionHeaderStruct)
	{
		{ _field_legacy, _field_string_id, "name" },
		{ _field_legacy, _field_long_integer, "id" },
		{ _field_legacy, _field_long_integer, "blendIn" },
		{ _field_legacy, _field_long_integer, "length" },
		{ _field_legacy, _field_long_integer, "comment" },
		{ _field_legacy, _field_char_enum, "blendType", &PuppetActionBlendTypeEnum },
		{ _field_legacy, _field_char_enum, "type", &PuppetActionTypeEnum },
		{ _field_legacy, _field_short_integer, "dataIndex" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(PuppetActionAnimationStruct)
	{
		{ _field_legacy, _field_string_id, "name" },
		{ _field_legacy, _field_struct, "position", &PuppetPathPointStruct_struct_definition },
		{ _field_legacy, _field_byte_flags, "flags", &PuppetAnimationFlagsDefinition },
		{ _field_legacy, _field_char_enum, "posType", &AnimPositionTypeEnum },
		{ _field_legacy, _field_pad, "pad", 2 },
		{ _field_legacy, _field_long_integer, "startFrame" },
		{ _field_legacy, _field_long_integer, "endFrame" },
		{ _field_legacy, _field_long_integer, "repeatCount" },
		{ _field_legacy, _field_real, "scale" },
		{ _field_legacy, _field_string_id, "conditionScriptName" },
		{ _field_legacy, _field_long_integer, "condition~" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(PuppetActionPathStruct)
	{
		{ _field_legacy, _field_real, "throttle" },
		{ _field_legacy, _field_block, "points", &PuppetPathPointBlock_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(PuppetSubActionHeaderStruct)
	{
		{ _field_legacy, _field_char_enum, "type", &PuppetSubActionTypeEnum },
		{ _field_legacy, _field_char_enum, "startType", &SubActionTimeTypeEnum },
		{ _field_legacy, _field_char_enum, "endType", &SubActionTimeTypeEnum },
		{ _field_legacy, _field_pad, "pad1", 1 },
		{ _field_legacy, _field_long_integer, "startAction" },
		{ _field_legacy, _field_long_integer, "startOffset" },
		{ _field_legacy, _field_string_id, "startConditionScriptName" },
		{ _field_legacy, _field_string_id, "endConditionScriptName" },
		{ _field_legacy, _field_short_integer, "startCondition~" },
		{ _field_legacy, _field_short_integer, "endCondition~" },
		{ _field_legacy, _field_long_integer, "endAction" },
		{ _field_legacy, _field_long_integer, "endOffset" },
		{ _field_legacy, _field_long_integer, "comment" },
		{ _field_legacy, _field_short_integer, "dataIndex" },
		{ _field_legacy, _field_pad, "pad2", 2 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(PuppetSubActionPointStruct)
	{
		{ _field_legacy, _field_struct, "point", &PuppetPathPointStruct_struct_definition },
		{ _field_legacy, _field_tag_reference, "asset", &PuppetSubActionPointStruct_asset_reference },
		{ _field_legacy, _field_byte_flags, "flags", &SubActionPointFlagsDefinition },
		{ _field_legacy, _field_pad, "pad", 3 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(PuppetSubActionBranchStruct)
	{
		{ _field_legacy, _field_block, "elements", &PuppetSubActionBranchElementBlock_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(PuppetSubActionScriptStruct)
	{
		{ _field_legacy, _field_string_id, "scriptName" },
		{ _field_legacy, _field_long_integer, "script~" },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(PuppetIndexTypeEnum)
	{
		"Name",
		"AI",
		"Global",
		"Puppet",
		"Point Set",
		"Flag"
	};
	STRING_LIST(PuppetIndexTypeEnum, PuppetIndexTypeEnum_strings, _countof(PuppetIndexTypeEnum_strings));

	STRINGS(PuppetActionTypeEnum)
	{
		"Animation",
		"Path"
	};
	STRING_LIST(PuppetActionTypeEnum, PuppetActionTypeEnum_strings, _countof(PuppetActionTypeEnum_strings));

	STRINGS(PuppetActionBlendTypeEnum)
	{
		"Linear",
		"Smooth"
	};
	STRING_LIST(PuppetActionBlendTypeEnum, PuppetActionBlendTypeEnum_strings, _countof(PuppetActionBlendTypeEnum_strings));

	STRINGS(PuppetSubActionTypeEnum)
	{
		"Look At",
		"Face",
		"Shoot At",
		"Overlay",
		"Effect",
		"Sound",
		"Looping Sound",
		"Dialogue",
		"Branch",
		"Script"
	};
	STRING_LIST(PuppetSubActionTypeEnum, PuppetSubActionTypeEnum_strings, _countof(PuppetSubActionTypeEnum_strings));

	STRINGS(SubActionTimeTypeEnum)
	{
		"Offset From Start",
		"Offset From End",
		"Condition"
	};
	STRING_LIST(SubActionTimeTypeEnum, SubActionTimeTypeEnum_strings, _countof(SubActionTimeTypeEnum_strings));

	STRINGS(PuppetPathPointTypeEnum)
	{
		"Current",
		"Object",
		"Point Set",
		"Flag",
		"Custom"
	};
	STRING_LIST(PuppetPathPointTypeEnum, PuppetPathPointTypeEnum_strings, _countof(PuppetPathPointTypeEnum_strings));

	STRINGS(AnimPositionTypeEnum)
	{
		"Teleport",
		"Attach",
		"Free"
	};
	STRING_LIST(AnimPositionTypeEnum, AnimPositionTypeEnum_strings, _countof(AnimPositionTypeEnum_strings));

	STRINGS(PuppetPathPointFlagsDefinition)
	{
		"Has Rotation",
		"Don\'t Stop"
	};
	STRING_LIST(PuppetPathPointFlagsDefinition, PuppetPathPointFlagsDefinition_strings, _countof(PuppetPathPointFlagsDefinition_strings));

	STRINGS(PuppetFlagsDefinition)
	{
		"Optional",
		"Player",
		"Force Position",
		"Create If Missing",
		"Destroy When Finished",
		"Abort On Damage",
		"Abort On Alert",
		"Abort Show"
	};
	STRING_LIST(PuppetFlagsDefinition, PuppetFlagsDefinition_strings, _countof(PuppetFlagsDefinition_strings));

	STRINGS(PuppetShowFlagsDefinition)
	{
		"Coop ICS",
		"Immediate ICS"
	};
	STRING_LIST(PuppetShowFlagsDefinition, PuppetShowFlagsDefinition_strings, _countof(PuppetShowFlagsDefinition_strings));

	STRINGS(PuppetAnimationFlagsDefinition)
	{
		"Looping",
		"Reverse",
		"Reset Object Position",
		"ICS",
		"ICS Reset Camera",
		"Additional"
	};
	STRING_LIST(PuppetAnimationFlagsDefinition, PuppetAnimationFlagsDefinition_strings, _countof(PuppetAnimationFlagsDefinition_strings));

	STRINGS(SubActionPointFlagsDefinition)
	{
		"Looping Effect",
		"Attached Effect"
	};
	STRING_LIST(SubActionPointFlagsDefinition, SubActionPointFlagsDefinition_strings, _countof(SubActionPointFlagsDefinition_strings));

	STRINGS(PuppetEditorFlagsDefinition)
	{
		"Muted",
		"Expanded"
	};
	STRING_LIST(PuppetEditorFlagsDefinition, PuppetEditorFlagsDefinition_strings, _countof(PuppetEditorFlagsDefinition_strings));

} // namespace blofeld

