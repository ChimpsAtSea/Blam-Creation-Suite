#pragma once

#include <cseries/cseries.h>
#include <memory/static_arrays.h>
#include <tag_files/tag_groups.h>

/* ---------- constants */

constexpr int k_maximum_number_of_campaign_metagame_buckets = 1;

/* ---------- types */

enum e_campaign_metagame_bucket_flags
{
    _campaign_metagame_bucket_only_counts_with_riders_bit,
    k_number_of_campaign_metagame_bucket_flags
};

enum e_campaign_metagame_bucket_type
{
    _campaign_metagame_bucket_type_brute,
    _campaign_metagame_bucket_type_grunt,
    _campaign_metagame_bucket_type_jackal,
    _campaign_metagame_bucket_type_skirmisher,
    _campaign_metagame_bucket_type_marine,
    _campaign_metagame_bucket_type_spartan,
    _campaign_metagame_bucket_type_bugger,
    _campaign_metagame_bucket_type_hunter,
    _campaign_metagame_bucket_type_flood_infection,
    _campaign_metagame_bucket_type_flood_carrier,
    _campaign_metagame_bucket_type_flood_combat,
    _campaign_metagame_bucket_type_flood_pure,
    _campaign_metagame_bucket_type_sentinel,
    _campaign_metagame_bucket_type_elite,
    _campaign_metagame_bucket_type_engineer,
    _campaign_metagame_bucket_type_mule,
    _campaign_metagame_bucket_type_turret,
    _campaign_metagame_bucket_type_mongoose,
    _campaign_metagame_bucket_type_warthog,
    _campaign_metagame_bucket_type_scorpion,
    _campaign_metagame_bucket_type_hornet,
    _campaign_metagame_bucket_type_pelican,
    _campaign_metagame_bucket_type_revenant,
    _campaign_metagame_bucket_type_seraph,
    _campaign_metagame_bucket_type_shade,
    _campaign_metagame_bucket_type_watchtower,
    _campaign_metagame_bucket_type_ghost,
    _campaign_metagame_bucket_type_chopper,
    _campaign_metagame_bucket_type_mauler,
    _campaign_metagame_bucket_type_wraith,
    _campaign_metagame_bucket_type_banshee,
    _campaign_metagame_bucket_type_phantom,
    _campaign_metagame_bucket_type_scarab,
    _campaign_metagame_bucket_type_guntower,
    _campaign_metagame_bucket_type_tuning_fork,
    _campaign_metagame_bucket_type_broadsword,
    _campaign_metagame_bucket_type_mammoth,
    _campaign_metagame_bucket_type_lich,
    _campaign_metagame_bucket_type_mantis,
    _campaign_metagame_bucket_type_wasp,
    _campaign_metagame_bucket_type_phaeton,
    _campaign_metagame_bucket_type_bishop,
    _campaign_metagame_bucket_type_knight,
    _campaign_metagame_bucket_type_pawn,
    _campaign_metagame_bucket_type_soldier,
    _campaign_metagame_bucket_type_packmaster,
    _campaign_metagame_bucket_type_cavalier,
    k_number_of_campaign_metagame_bucket_types
};

enum e_campaign_metagame_bucket_class
{
    _campaign_metagame_bucket_class_infantry,
    _campaign_metagame_bucket_class_leader,
    _campaign_metagame_bucket_class_hero,
    _campaign_metagame_bucket_class_specialist,
    _campaign_metagame_bucket_class_light_vehicle,
    _campaign_metagame_bucket_class_heavy_vehicle,
    _campaign_metagame_bucket_class_giant_vehicle,
    _campaign_metagame_bucket_class_standard_vehicle,
    k_number_of_campaign_metagame_bucket_classes
};

struct s_campaign_metagame_bucket
{
    c_flags<e_campaign_metagame_bucket_flags, byte> flags;
    c_enum<e_campaign_metagame_bucket_type, char> type;
    c_enum<e_campaign_metagame_bucket_class, char> _class;
    char : 8;
    short point_count;
    short : 16;
};
static_assert(sizeof(s_campaign_metagame_bucket) == 0x8);
