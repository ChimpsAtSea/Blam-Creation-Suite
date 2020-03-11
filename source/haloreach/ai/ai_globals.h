#pragma once

#include <cseries/cseries.h>
#include <tag_files/tag_groups.h>

/* ---------- constants */

constexpr tag k_ai_globals_group_tag = 'aigl';

/* ---------- types */

struct s_ai_globals_squad_template_definition
{
	// TODO
};

struct s_ai_globals_performance_template_definition
{
	// TODO
};

struct s_squad_template_iterator
{
	// TODO
};

struct s_performance_template_iterator
{
	// TODO
};

struct s_ai_globals_data
{
	// TODO
};

struct s_ai_globals_definition
{
	// TODO
};

/* ---------- globals */

extern s_tag_group g_ai_globals_group;

/* ---------- prototypes/AI_GLOBALS.CPP */

void ai_globals_initialize();
void ai_globals_initialize_for_new_map();
void ai_globals_dispose();
void ai_globals_update();

bool ai_globals_dialogue_enabled();

long ai_globals_get_formation_index(s_ai_globals_data *, int, long);

void ai_globals_squad_template_iterator_new(s_ai_globals_data *, s_squad_template_iterator *);
s_ai_globals_squad_template_definition *ai_globals_squad_template_iterator_next(s_squad_template_iterator *);

long ai_globals_get_squad_template_index(s_ai_globals_data *, long);

void ai_globals_performance_template_iterator_new(s_ai_globals_data *, s_performance_template_iterator *);
s_ai_globals_performance_template_definition *ai_globals_performance_template_iterator_next(s_performance_template_iterator *);

long ai_globals_get_performance_template_index(s_ai_globals_data *, long);

void ai_globals_resolve_references(s_ai_globals_data *);
