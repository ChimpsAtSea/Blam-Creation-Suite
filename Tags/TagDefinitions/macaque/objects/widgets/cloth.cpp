#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		cloth_group,
		CLOTH_TAG,
		nullptr,
		INVALID_TAG,
		cloth_block );

	TAG_BLOCK_FROM_STRUCT(
		cloth_block,
		"cloth_block",
		1,
		cloth_struct_definition);

	#define COLLISION_SPHERE_BLOCK_ID { 0x1168CFD4, 0x1EEC4C7A, 0x85A5FF51, 0x40ABCDAF }
	TAG_BLOCK(
		collision_sphere_block,
		"collision_sphere_block",
		k_maximum_collision_spheres_per_cloth,
		"s_cloth_collision_sphere",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		COLLISION_SPHERE_BLOCK_ID)
	{
		{ _field_string_id, "object marker name" },
		{ _field_real, "radius" },
		{ _field_terminator }
	};

	#define CLOTH_VERTICES_BLOCK_ID { 0x9CBFA025, 0xB3394521, 0xBC81E2FD, 0xF791ED55 }
	TAG_BLOCK(
		cloth_vertices_block,
		"cloth_vertices_block",
		k_maximum_vertices_per_cloth,
		"cloth_vertex_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CLOTH_VERTICES_BLOCK_ID)
	{
		{ _field_real_point_3d, "initial position", FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_2d, "uv", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define CLOTH_INDICES_BLOCK_ID { 0x37D025EE, 0xD2D24235, 0xA99B29D1, 0x0BEACCDC }
	TAG_BLOCK(
		cloth_indices_block,
		"cloth_indices_block",
		k_maximum_indices_per_cloth,
		"cloth_index_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CLOTH_INDICES_BLOCK_ID)
	{
		{ _field_short_integer, "index", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define CLOTH_LINKS_BLOCK_ID { 0x2A08CAD4, 0x1EE64F76, 0x85A6FF91, 0x40E35AAF }
	TAG_BLOCK(
		cloth_links_block,
		"cloth_links_block",
		k_maximum_links_per_cloth,
		"cloth_link_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CLOTH_LINKS_BLOCK_ID)
	{
		{ _field_real, "default_distance", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "index1", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "index2", FIELD_FLAG_READ_ONLY },
		FIELD_PAD("vmx_pad", nullptr, 4),
		{ _field_terminator }
	};

	#define CLOTH_STRUCT_DEFINITION_ID { 0x6007B323, 0x1677454C, 0x86B19DA1, 0xCAEC6D8B }
	TAG_STRUCT(
		cloth_struct_definition,
		"cloth_struct_definition",
		"cloth_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CLOTH_STRUCT_DEFINITION_ID)
	{
		{ _field_long_flags, "flags", &cloth_flags },
		{ _field_string_id, "marker attachment name" },
		{ _field_string_id, "secondary axis attachment name" },
		{ _field_tag_reference, "Shader", &global_shader_reference },
		FIELD_EXPLANATION("Default cloth vertices", nullptr, "if not importing from a render model, type a grid size"),
		{ _field_short_integer, "grid x dimension" },
		{ _field_short_integer, "grid y dimension" },
		{ _field_real, "grid spacing x" },
		{ _field_real, "grid spacing y" },
		{ _field_block, "collision spheres", &collision_sphere_block },
		FIELD_EXPLANATION("Cloth Properties", nullptr, ""),
		{ _field_struct, "properties", &cloth_properties },
		FIELD_EXPLANATION("Import or grid data", nullptr, ""),
		{ _field_block, "vertices", &cloth_vertices_block },
		{ _field_block, "indices", &cloth_indices_block },
		{ _field_block, "strip indices", &cloth_indices_block },
		{ _field_block, "links", &cloth_links_block },
		{ _field_terminator }
	};

	#define CLOTH_PROPERTIES_ID { 0x3654721A, 0x8FDB4A6D, 0x833E911B, 0x06E30928 }
	TAG_STRUCT(
		cloth_properties,
		"cloth_properties",
		"cloth_properties",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CLOTH_PROPERTIES_ID)
	{
		{ _field_enum, "Integration type", &cloth_integration_enum },
		{ _field_short_integer, "Number iterations", "[1-8] sug 1" },
		{ _field_real, "weight", "[-10.0 - 10.0] sug 1.0" },
		{ _field_real, "drag", "[0.0 - 0.5] sug 0.07" },
		{ _field_real, "wind_scale", "[0.0 - 3.0] sug 1.0" },
		{ _field_real, "wind_flappiness_scale", "[0.0 - 1.0] sug 0.75" },
		{ _field_real, "longest_rod", "[1.0 - 10.0] sug 3.5" },
		FIELD_PAD("WXLH", nullptr, 24),
		{ _field_terminator }
	};

	STRINGS(cloth_flags)
	{
		"Doesn\'t use wind",
		"Uses grid attach top"
	};
	STRING_LIST(cloth_flags, cloth_flags_strings, _countof(cloth_flags_strings));

	STRINGS(cloth_integration_enum)
	{
		"verlet"
	};
	STRING_LIST(cloth_integration_enum, cloth_integration_enum_strings, _countof(cloth_integration_enum_strings));

	TAG_REFERENCE(global_shader_reference, MATERIAL_TAG);

} // namespace macaque

} // namespace blofeld

