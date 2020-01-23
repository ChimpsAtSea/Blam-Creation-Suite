#pragma once

struct nicename("Sound Global Propagation") group('sgp!') s_sound_global_propagation_definition
{
	TagReference nicename("Underwater Environment") underwater_environment_reference; 
	TagReference nicename("Underwater Loop") underwater_loop_reference; 
	Undefined32 __unknown; 
	Undefined32 __unknown2; 
	TagReference nicename("Enter Underater") enter_underater_reference; 
	TagReference nicename("Exit Underwater") exit_underwater_reference; 
};
