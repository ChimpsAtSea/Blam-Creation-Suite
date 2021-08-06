#include <tagdefinitions-private-pch.h>

#include "tag_groups.halo1.inl"
#include "tag_groups.stubbs.inl"
#include "tag_groups.halo2.inl"
#include "tag_groups.halo3.inl"
#include "tag_groups.halo3odst.inl"
#include "tag_groups.eldorado.inl"
#include "tag_groups.haloreach.inl"
#include "tag_groups.halo4.inl"
#include "tag_groups.gen3_xbox360.inl"
#include "tag_groups.groundhog.inl"
#include "tag_groups.infinite.inl"

namespace blofeld
{
	const s_tag_group* tag_groups_not_set[] = { nullptr };
	const s_tag_group* tag_groups_mcc[] = { nullptr };
	const s_tag_group* tag_groups_halo5[] = { nullptr };

	const s_tag_group** tag_groups[k_number_of_engine_types] =
	{
		tag_groups_not_set, // _engine_type_not_set
		tag_groups_mcc, // _engine_type_mcc
		tag_groups_halo1, // _engine_type_halo1
		tag_groups_stubbs, // _engine_type_stubbs
		tag_groups_halo2, // _engine_type_halo2
		tag_groups_halo3, // _engine_type_halo3
		tag_groups_halo3odst, // _engine_type_halo3odst
		tag_groups_eldorado, // _engine_type_eldorado
		tag_groups_haloreach, // _engine_type_haloreach
		tag_groups_halo4, // _engine_type_halo4
		tag_groups_gen3_xbox360, // _engine_type_gen3_xbox360
		tag_groups_groundhog, // _engine_type_groundhog
		tag_groups_halo5, // _engine_type_halo5
		tag_groups_infinite, // _engine_type_infinite
	};
	static_assert(k_number_of_engine_types == 14); // update this if changed

} // namespace blofeld

