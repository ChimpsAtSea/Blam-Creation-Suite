#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define PUPPETSHOWSBLOCK_ID { 0x9562EFA6, 0xC5864192, 0x80EB546F, 0x8BF6C569 }
	TAG_BLOCK(
		PuppetShowsBlock_block,
		"PuppetShowsBlock",
		MAXIMUM_PERFORMANCES_PER_SCENARIO,
		"PuppetShow",
		PUPPETSHOWSBLOCK_ID)
	{
		{ _field_string_id, "name^" },
		{ _field_string_id, "designerZone" },
		{ _field_struct, "manual bsp flags*", &manualBspFlagsReferences },
		{ _field_byte_flags, "flags", &PuppetShowFlagsDefinition },
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
		{ _field_terminator }
	};

	#define PUPPETBLOCK_ID { 0xCF621B18, 0xAB9F429E, 0xBBB7E1AF, 0x81A270C5 }
	TAG_BLOCK(
		PuppetBlock_block,
		"PuppetBlock",
		MAX_PUPPETS_PER_SHOW,
		"Puppet",
		PUPPETBLOCK_ID)
	{
		{ _field_struct, "header", &PuppetHeaderStruct },
		{ _field_block, "actions", &PuppetActionBlock_block },
		{ _field_block, "subActions", &PuppetSubActionBlock_block },
		{ _field_block, "subTracks", &SubTracksBlock_block },
		{ _field_long_string, "comment" },
		{ _field_long_string, "startScript" },
		{ _field_long_string, "endScript" },
		{ _field_short_integer, "height" },
		{ _field_byte_flags, "editorFlags!*", &PuppetEditorFlagsDefinition },
		{ _field_pad, "pad", 1 },
		{ _field_terminator }
	};

	#define PUPPETACTIONBLOCK_ID { 0x93A734EC, 0xF65F4437, 0x8BF9E4FE, 0xD8806C4B }
	TAG_BLOCK(
		PuppetActionBlock_block,
		"PuppetActionBlock",
		MAX_ACTIONS_PER_PUPPET,
		"PuppetAction",
		PUPPETACTIONBLOCK_ID)
	{
		{ _field_struct, "header", &PuppetActionHeaderStruct },
		{ _field_struct, "animation", &PuppetActionAnimationStruct },
		{ _field_struct, "path", &PuppetActionPathStruct },
		{ _field_long_string, "comment" },
		{ _field_long_string, "animCondition" },
		{ _field_dword_integer, "color" },
		{ _field_byte_flags, "editorFlags!*", &PuppetEditorFlagsDefinition },
		{ _field_pad, "pad", 3 },
		{ _field_long_integer, "startFrame*" },
		{ _field_long_integer, "endFrame*" },
		{ _field_long_integer, "blendFrame*" },
		{ _field_long_integer, "startPixel*" },
		{ _field_long_integer, "endPixel*" },
		{ _field_long_integer, "blendPixel*" },
		{ _field_long_integer, "blendInDrag*" },
		{ _field_long_integer, "lengthDrag*" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		PuppetPathPointBlock_block,
		"PuppetPathPointBlock",
		MAX_POINTS_PER_PATH,
		PuppetPathPointStruct);

	#define PUPPETSUBACTIONBLOCK_ID { 0x3BE78714, 0xC7934182, 0xBE95FF53, 0xF480FB09 }
	TAG_BLOCK(
		PuppetSubActionBlock_block,
		"PuppetSubActionBlock",
		MAX_SUB_ACTIONS_PER_PUPPET,
		"PuppetSubAction",
		PUPPETSUBACTIONBLOCK_ID)
	{
		{ _field_struct, "header", &PuppetSubActionHeaderStruct },
		{ _field_struct, "point", &PuppetSubActionPointStruct },
		{ _field_struct, "branch", &PuppetSubActionBranchStruct },
		{ _field_struct, "script", &PuppetSubActionScriptStruct },
		{ _field_long_string, "comment" },
		{ _field_long_string, "startCondition" },
		{ _field_long_string, "endCondition" },
		{ _field_long_string, "scriptText" },
		{ _field_block, "branchConditions", &PuppetScriptTextBlock_block },
		{ _field_dword_integer, "color" },
		{ _field_byte_integer, "subTrack" },
		{ _field_byte_flags, "editorFlags!*", &PuppetEditorFlagsDefinition },
		{ _field_pad, "pad", 2 },
		{ _field_long_integer, "startFrame*" },
		{ _field_long_integer, "endFrame*" },
		{ _field_long_integer, "startPixel*" },
		{ _field_long_integer, "endPixel*" },
		{ _field_long_integer, "subTrackDrag*" },
		{ _field_long_integer, "startOffsetDrag*" },
		{ _field_long_integer, "endOffsetDrag*" },
		{ _field_terminator }
	};

	#define PUPPETSUBACTIONBRANCHELEMENTBLOCK_ID { 0x70F50344, 0x451E4F1D, 0x94DBF6FD, 0x3C9FB3D8 }
	TAG_BLOCK(
		PuppetSubActionBranchElementBlock_block,
		"PuppetSubActionBranchElementBlock",
		MAX_BRANCHES_PER_SUB_ACTION,
		"PuppetSubActionBranchElement",
		PUPPETSUBACTIONBRANCHELEMENTBLOCK_ID)
	{
		{ _field_long_integer, "targetAction" },
		{ _field_string_id, "conditionScriptName" },
		{ _field_long_integer, "condition~" },
		{ _field_terminator }
	};

	#define PUPPETSCRIPTTEXTBLOCK_ID { 0x4AD570DA, 0x6D0A485F, 0xB0FF6BB8, 0xF9175535 }
	TAG_BLOCK(
		PuppetScriptTextBlock_block,
		"PuppetScriptTextBlock",
		MAX_BRANCHES_PER_SUB_ACTION,
		"PuppetScript",
		PUPPETSCRIPTTEXTBLOCK_ID)
	{
		{ _field_long_string, "scriptText" },
		{ _field_terminator }
	};

	#define SUBTRACKSBLOCK_ID { 0xF9329491, 0xB5DC4B17, 0x907B46B1, 0x9065CF79 }
	TAG_BLOCK(
		SubTracksBlock_block,
		"SubTracksBlock",
		MAX_SUB_TRACKS,
		"string_id",
		SUBTRACKSBLOCK_ID)
	{
		{ _field_string_id, "name^" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		PuppetHeaderBlock_block,
		"PuppetHeaderBlock",
		MAX_PUPPETS_PER_SHOW,
		PuppetHeaderStruct);

	TAG_BLOCK_FROM_STRUCT(
		PuppetActionHeaderBlock_block,
		"PuppetActionHeaderBlock",
		MAX_ACTIONS_PER_SHOW,
		PuppetActionHeaderStruct);

	TAG_BLOCK_FROM_STRUCT(
		PuppetSubActionHeaderBlock_block,
		"PuppetSubActionHeaderBlock",
		MAX_SUB_ACTIONS_PER_SHOW,
		PuppetSubActionHeaderStruct);

	TAG_BLOCK_FROM_STRUCT(
		PuppetAnimationBlock_block,
		"PuppetAnimationBlock",
		MAX_ACTIONS_PER_SHOW,
		PuppetActionAnimationStruct);

	TAG_BLOCK_FROM_STRUCT(
		PuppetPathBlock_block,
		"PuppetPathBlock",
		MAX_ACTIONS_PER_SHOW,
		PuppetActionPathStruct);

	TAG_BLOCK_FROM_STRUCT(
		PuppetPointBlock_block,
		"PuppetPointBlock",
		MAX_SUB_ACTIONS_PER_SHOW,
		PuppetSubActionPointStruct);

	TAG_BLOCK_FROM_STRUCT(
		PuppetBranchBlock_block,
		"PuppetBranchBlock",
		MAX_SUB_ACTIONS_PER_SHOW,
		PuppetSubActionBranchStruct);

	TAG_BLOCK_FROM_STRUCT(
		PuppetScriptBlock_block,
		"PuppetScriptBlock",
		MAX_SUB_ACTIONS_PER_SHOW,
		PuppetSubActionScriptStruct);

	#define COMMENTSBLOCK_ID { 0x947B5984, 0x2C6C4B19, 0x8087CA46, 0x21DD6749 }
	TAG_BLOCK(
		CommentsBlock_block,
		"CommentsBlock",
		65536,
		"CommentsBlock",
		COMMENTSBLOCK_ID)
	{
		{ _field_char_integer, "char" },
		{ _field_terminator }
	};

	#define PUPPETHEADERSTRUCT_ID { 0xC023483C, 0x3B97483F, 0x83E7754E, 0x39F683AC }
	TAG_STRUCT(
		PuppetHeaderStruct,
		"PuppetHeaderStruct",
		"PuppetHeader",
		PUPPETHEADERSTRUCT_ID)
	{
		{ _field_byte_flags, "flags", &PuppetFlagsDefinition },
		{ _field_char_enum, "indexType~", &PuppetIndexTypeEnum },
		{ _field_pad, "pad", 2 },
		{ _field_string_id, "name" },
		{ _field_tag_reference, "type", &PuppetHeaderStruct_type_reference },
		{ _field_string_id, "objectName" },
		{ _field_long_integer, "index~" },
		{ _field_struct, "position", &PuppetPathPointStruct },
		{ _field_string_id, "startScriptName" },
		{ _field_string_id, "endScriptName" },
		{ _field_short_integer, "startScript~" },
		{ _field_short_integer, "endScript~" },
		{ _field_short_integer, "firstAction" },
		{ _field_short_integer, "actionCount" },
		{ _field_short_integer, "firstSubAction" },
		{ _field_short_integer, "subActionCount" },
		{ _field_tag_reference, "additionalAnimations", &model_animation_graph_reference$3 },
		{ _field_terminator }
	};

	#define PUPPETPATHPOINTSTRUCT_ID { 0x0AC79CA3, 0x908646D8, 0x98358F46, 0xAA2AEE0F }
	TAG_STRUCT(
		PuppetPathPointStruct,
		"PuppetPathPointStruct",
		"PuppetPathPoint",
		PUPPETPATHPOINTSTRUCT_ID)
	{
		{ _field_char_enum, "type", &PuppetPathPointTypeEnum },
		{ _field_byte_flags, "flags", &PuppetPathPointFlagsDefinition },
		{ _field_char_enum, "indexType~", &PuppetIndexTypeEnum },
		{ _field_pad, "pad", 1 },
		{ _field_string_id, "objectName" },
		{ _field_long_integer, "index~" },
		{ _field_string_id, "marker" },
		{ _field_real_point_3d, "pos" },
		{ _field_real_euler_angles_3d, "rot" },
		{ _field_terminator }
	};

	#define PUPPETACTIONHEADERSTRUCT_ID { 0xFA200369, 0xBB6D48F8, 0x9B156C53, 0x5A91C58B }
	TAG_STRUCT(
		PuppetActionHeaderStruct,
		"PuppetActionHeaderStruct",
		"PuppetActionHeader",
		PUPPETACTIONHEADERSTRUCT_ID)
	{
		{ _field_string_id, "name" },
		{ _field_long_integer, "id" },
		{ _field_long_integer, "blendIn" },
		{ _field_long_integer, "length" },
		{ _field_long_integer, "comment" },
		{ _field_char_enum, "blendType", &PuppetActionBlendTypeEnum },
		{ _field_char_enum, "type", &PuppetActionTypeEnum },
		{ _field_short_integer, "dataIndex" },
		{ _field_terminator }
	};

	#define PUPPETACTIONANIMATIONSTRUCT_ID { 0x5982A171, 0x1CD747BF, 0x990B8738, 0x4F5013E6 }
	TAG_STRUCT(
		PuppetActionAnimationStruct,
		"PuppetActionAnimationStruct",
		"PuppetActionAnimation",
		PUPPETACTIONANIMATIONSTRUCT_ID)
	{
		{ _field_string_id, "name" },
		{ _field_struct, "position", &PuppetPathPointStruct },
		{ _field_byte_flags, "flags", &PuppetAnimationFlagsDefinition },
		{ _field_char_enum, "posType", &AnimPositionTypeEnum },
		{ _field_pad, "pad", 2 },
		{ _field_long_integer, "startFrame" },
		{ _field_long_integer, "endFrame" },
		{ _field_long_integer, "repeatCount" },
		{ _field_real, "scale" },
		{ _field_string_id, "conditionScriptName" },
		{ _field_long_integer, "condition~" },
		{ _field_terminator }
	};

	#define PUPPETACTIONPATHSTRUCT_ID { 0x7BEF7478, 0x58614EB4, 0x9EFA2425, 0xEFBCD9DA }
	TAG_STRUCT(
		PuppetActionPathStruct,
		"PuppetActionPathStruct",
		"PuppetActionPath",
		PUPPETACTIONPATHSTRUCT_ID)
	{
		{ _field_real, "throttle" },
		{ _field_block, "points", &PuppetPathPointBlock_block },
		{ _field_terminator }
	};

	#define PUPPETSUBACTIONHEADERSTRUCT_ID { 0x939C4DED, 0x98064334, 0xB0808526, 0xE32FC69E }
	TAG_STRUCT(
		PuppetSubActionHeaderStruct,
		"PuppetSubActionHeaderStruct",
		"PuppetSubActionHeader",
		PUPPETSUBACTIONHEADERSTRUCT_ID)
	{
		{ _field_char_enum, "type", &PuppetSubActionTypeEnum },
		{ _field_char_enum, "startType", &SubActionTimeTypeEnum },
		{ _field_char_enum, "endType", &SubActionTimeTypeEnum },
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
		{ _field_terminator }
	};

	#define PUPPETSUBACTIONPOINTSTRUCT_ID { 0x584F4F7A, 0x49054FE7, 0x8D7EA9C1, 0xE034E98F }
	TAG_STRUCT(
		PuppetSubActionPointStruct,
		"PuppetSubActionPointStruct",
		"PuppetSubActionPoint",
		PUPPETSUBACTIONPOINTSTRUCT_ID)
	{
		{ _field_struct, "point", &PuppetPathPointStruct },
		{ _field_tag_reference, "asset", &PuppetSubActionPointStruct_asset_reference },
		{ _field_byte_flags, "flags", &SubActionPointFlagsDefinition },
		{ _field_pad, "pad", 3 },
		{ _field_terminator }
	};

	#define PUPPETSUBACTIONBRANCHSTRUCT_ID { 0x726B629A, 0x429D4389, 0x90127AED, 0x78D58747 }
	TAG_STRUCT(
		PuppetSubActionBranchStruct,
		"PuppetSubActionBranchStruct",
		"PuppetSubActionBranch",
		PUPPETSUBACTIONBRANCHSTRUCT_ID)
	{
		{ _field_block, "elements", &PuppetSubActionBranchElementBlock_block },
		{ _field_terminator }
	};

	#define PUPPETSUBACTIONSCRIPTSTRUCT_ID { 0x9481F465, 0xC8D546E8, 0x94DAE439, 0xC1BBE1C9 }
	TAG_STRUCT(
		PuppetSubActionScriptStruct,
		"PuppetSubActionScriptStruct",
		"PuppetSubActionScript",
		PUPPETSUBACTIONSCRIPTSTRUCT_ID)
	{
		{ _field_string_id, "scriptName" },
		{ _field_long_integer, "script~" },
		{ _field_terminator }
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

} // namespace macaque

} // namespace blofeld

