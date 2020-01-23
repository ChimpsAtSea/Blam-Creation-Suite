#pragma once

struct nicename("Breakable Surface") group('bsdt') s_breakable_surface_definition
{
	Unknown32 __unknown; 
	Unknown32 __unknown2; 
	Unknown32 __unknown3; 
	Unknown32 __unknown4; 
	Unknown32 __unknown5; 
	Unknown32 __unknown6; 
	TagReference nicename("Effect") effect_reference; 
	TagReference nicename("Sound") sound_reference; 
	Unknown32 __unknown7; 
	Unknown32 __unknown8; 
	Unknown32 __unknown9; 
	Unknown32 __unknown10; 
	TagReference nicename("Crack Bitmap") crack_bitmap_reference; 
	TagReference nicename("Hole Bitmap") hole_bitmap_reference; 
};
