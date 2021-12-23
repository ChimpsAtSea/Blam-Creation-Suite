#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <Platform\platform-public-pch.h>
#include <TemplateLibrary\templatelibrary-public-pch.h>
#include <Shared\Blam\blamlib-public-pch.h>
#include <SymbolsLib\symbolslib-public-pch.h>
#include <TagDefinitions\tagdefinitions-public-pch.h>

#include <TagDefinitions/slipspace/tag_groups.infinite_flight1.inl>
#include <TagDefinitions/slipspace/tag_groups.infinite_flight2.inl>
#include <TagDefinitions/slipspace/tag_groups.infinite_release.inl>

static BCS_RESULT tag_defintions_validate()
{
	std::map<const blofeld::s_tag_field*, uint64_t> warnings_tracking;

	bool failed_validation = false;
	//failed_validation |= blofeld::validate_gen3_definitions(&warnings_tracking);
	//failed_validation |= blofeld::validate_halo4_xbox360_definitions(&warnings_tracking);
	//failed_validation |= blofeld::validate_all_definitions(&warnings_tracking);
	failed_validation |= definition_migration(
		blofeld::tag_groups_infinite_flight1,
		blofeld::tag_groups[_engine_type_infinite],
		{ _engine_type_infinite, _platform_type_pc_64bit, _build_infinite_FLT002INT_199229_21_07_20_0001 });
	failed_validation |= definition_migration(
		blofeld::tag_groups_infinite_flight2,
		blofeld::tag_groups[_engine_type_infinite],
		{ _engine_type_infinite, _platform_type_pc_64bit, _build_infinite_HIFLTA_202700_21_09_06_0001 });
	failed_validation |= definition_migration(
		blofeld::tag_groups_infinite_release,
		blofeld::tag_groups[_engine_type_infinite],
		{ _engine_type_infinite, _platform_type_pc_64bit, _build_infinite_HIREL_209048_21_12_09_1546 });

	static bool const fatal_validation = BCS_SUCCEEDED(command_line_has_argument("fatal-validation"));
	if (failed_validation && fatal_validation)
	{
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}

int main()
{
	SetThreadErrorMode(SEM_NOGPFAULTERRORBOX, NULL);
	SetErrorMode(SEM_NOGPFAULTERRORBOX);
	
	BCS_FAIL_RETURN(register_process_module_by_pointer(main));
	void* process_module;
	BCS_FAIL_RETURN(get_process_module(process_module));
	BCS_FAIL_RETURN(init_command_line());
	BCS_FAIL_RETURN(init_console());


	BCS_RESULT rs = tag_defintions_validate();

	BCS_FAIL_RETURN(deinit_console());
	BCS_FAIL_RETURN(deinit_command_line());
	
	return rs;
}
