#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(hologramLightingGlobalsBlock, 1)
{
	{ _field_custom, "HOLOGRAM FUNCTIONS" },
	{ _field_string_id, "Intensity" },
	{ _field_custom },
	{ _field_custom, "KEY LIGHT FUNCTIONS" },
	{ _field_struct, "Key Light Functions" },
	{ _field_custom },
	{ _field_custom, "FILL LIGHT FUNCTIONS" },
	{ _field_struct, "Fill Light Functions" },
	{ _field_custom },
	{ _field_custom, "RIM LIGHT FUNCTIONS" },
	{ _field_struct, "Rim Light Functions" },
	{ _field_custom },
	{ _field_terminator },
};

TAG_BLOCK(hologramLightingBlock, 1)
{
	{ _field_custom, "HOLOGRAM" },
	{ _field_custom, "Intensity" },
	{ _field_real, "Intensity" },
	{ _field_real, "Intensity Input!" },
	{ _field_char_enum, "Transparency Mode" },
	{ _field_pad, "PADDING1", 3 },
	{ _field_custom },
	{ _field_custom, "KEY LIGHT" },
	{ _field_struct, "Key Light" },
	{ _field_custom },
	{ _field_custom, "FILL LIGHT" },
	{ _field_struct, "Fill Light" },
	{ _field_custom },
	{ _field_custom, "RIM LIGHT" },
	{ _field_struct, "Rim Light" },
	{ _field_custom },
	{ _field_terminator },
};

} // namespace blofeld

