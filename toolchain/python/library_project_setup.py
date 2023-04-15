from __future__ import print_function
import os
import sys
from shutil import copyfile
import asyncio

sys.path.append(os.path.realpath(os.path.dirname(__file__))) # Allow Local Imports

from library_util import execute_async_task
from library_util import timer_func

import library_gn as gn
import library_sln as sln
import library_util as util

# -----
# Define Tag Definition Configurations
# -----
from library_bcs import Engine
from library_bcs import Platform
from library_bcs import Build
from library_bcs import EnginePlatformBuild

halo1_pc64_config = EnginePlatformBuild(Engine.engine_type_halo1, Platform.platform_type_pc_64bit, Build.build_guerilla)
stubbs_pc64_config = EnginePlatformBuild(Engine.engine_type_stubbs, Platform.platform_type_pc_64bit, Build.build_cache_release)
halo2_pc64_config = EnginePlatformBuild(Engine.engine_type_halo2, Platform.platform_type_pc_64bit, Build.build_guerilla)
halo3_pc64_config = EnginePlatformBuild(Engine.engine_type_halo3, Platform.platform_type_pc_64bit, Build.build_guerilla)
halo3odst_pc64_config = EnginePlatformBuild(Engine.engine_type_halo3odst, Platform.platform_type_pc_64bit, Build.build_guerilla)
eldorado_pc32_config = EnginePlatformBuild(Engine.engine_type_eldorado, Platform.platform_type_pc_32bit, Build.build_eldorado_1_106708_cert_ms23)
haloreach_xbox360_config = EnginePlatformBuild(Engine.engine_type_haloreach, Platform.platform_type_xbox_360, Build.build_tag_test)
haloreach_pc64_config = EnginePlatformBuild(Engine.engine_type_haloreach, Platform.platform_type_pc_64bit, Build.build_sapien)
halo4_xbox360_config = EnginePlatformBuild(Engine.engine_type_halo4, Platform.platform_type_xbox_360, Build.build_tag_test)
halo4_pc64_config = EnginePlatformBuild(Engine.engine_type_halo4, Platform.platform_type_pc_64bit, Build.build_sapien)
groundhog_pc64_config = EnginePlatformBuild(Engine.engine_type_groundhog, Platform.platform_type_pc_64bit, Build.build_sapien)
halo5_pc64_config = EnginePlatformBuild(Engine.engine_type_halo5, Platform.platform_type_pc_64bit, Build.build_cache_release)
haloinfinite_pc64_config = EnginePlatformBuild(Engine.engine_type_haloinfinite, Platform.platform_type_pc_64bit, Build.build_cache_release)

tag_configurations = [
    halo1_pc64_config,
    stubbs_pc64_config,
    halo2_pc64_config,
    halo3_pc64_config,
    halo3odst_pc64_config,
    eldorado_pc32_config,
    haloreach_xbox360_config,
    haloreach_pc64_config,
    halo4_xbox360_config,
    halo4_pc64_config,
    groundhog_pc64_config,
    halo5_pc64_config,
    haloinfinite_pc64_config ]

tag_configuration_triplets = []
for tag_configuration in tag_configurations:
    tag_configuration_triplets.append(f'{tag_configuration.engine.namespace}-{tag_configuration.platform.namespace}-{tag_configuration.build.namespace}')

tag_configuration_triplets_concat = ';'.join(tag_configuration_triplets)


# -----
# Setup the GN Build Base Environment
# -----

def gn_setup_build_environment():
    with open('.gn', 'w') as f:
        lines = []

        lines += ['# The location of the build configuration file.']
        lines += ['buildconfig = "//toolchain/BUILDCONFIG.gn"']
        lines += [f'script_executable = "{os.getcwd()}/thirdparty/python-3.11.1/python.exe"']
        lines += ['ninja_required_version="1.12.0"']
        lines += ['export_compile_commands=["*"]']

        f.writelines("\n".join(lines))

# -----
# Setup the GN Build Projects
# -----

def vs_os_get_pretty_name(target_os : str):
    lookup = {
        'windows': 'Windows',
        'linux': 'Linux',
        'webassembly': 'Webassembly',
    }
    if target_os in lookup:
        return lookup[target_os]
    return target_os

def vs_cpu_get_pretty_name(target_cpu : str):
    lookup = {
        'x86': 'x86',
        'x64': 'x64',
        'arm': 'Arm',
        'arm64': 'Arm64',
        'wasm32': 'wasm32',
        'wasm64': 'wasm64',
    }
    if target_cpu in lookup:
        return lookup[target_cpu]
    return target_cpu

def vs_configuration_get_pretty_name(target_config : str):
    lookup = {
        'debug': 'Debug',
        'test': 'Test',
        'release': 'Release',
    }
    if target_config in lookup:
        return lookup[target_config]
    return target_config

def vs_link_configuration_get_pretty_name(target_link_config : str):
    lookup = {
        'static': 'Static',
        'shared': 'Dynamic',
        'staticprofile': 'Static Profile',
        'sharedprofile': 'Dynamic Profile',
    }
    if target_link_config in lookup:
        return lookup[target_link_config]
    return target_link_config

def get_target_os_cpus(target_os : str):
    key = vs_os_get_pretty_name(target_os)
    lookup = {
        'Windows': [
            'x86',
            'x64',
            #"arm",
            'arm64',
        ],
        'Linux': [ 
            'x86',
            'x64',
        ] ,
        'Webassembly': [
            'wasm32',
            #'wasm64',
        ]
    }
    if key in lookup:
        return lookup[key]
    else:
        print(target_os, key)
        raise("Invalid target_os")

gn_operating_systems = []
if util.build_windows:
    gn_operating_systems.append('windows')
if util.build_linux:
    gn_operating_systems.append('linux')
if util.build_webassembly:
    gn_operating_systems.append('webassembly')

gn_configurations = [ 'debug', 'test', 'release' ]
gn_link_configurations = [ 'static', 'shared' ]
gn_profile_configurations = [ False ]
if util.build_profile:
    gn_profile_configurations += [ True ]

def get_num_configurations():
    num_configurations = 0
    for target_os in gn_operating_systems:
        for target_config in gn_configurations:
            for target_link_config in gn_link_configurations:
                for target_profile_config in gn_profile_configurations:
                    for target_cpu in get_target_os_cpus(target_os):
                        num_configurations += 1
    return num_configurations

@timer_func
def gn_generate_project_configurations():
    async def gn_generate_project_configurations_async():
        futures = []
        for target_os in gn_operating_systems:
            for target_config in gn_configurations:
                for target_link_config in gn_link_configurations:
                    for target_profile_config in gn_profile_configurations:
                        for target_cpu in get_target_os_cpus(target_os):
                            futures.append(gn.generate_build_configuration_files_async(target_os, target_config, target_link_config, target_cpu, tag_configuration_triplets_concat, False))
        await asyncio.gather(*futures)
    return execute_async_task(gn_generate_project_configurations_async)

def parse_global_targets_list(gn_solution_dir : str):
    global_targets = list[sln.TargetSettings]()
    for target_os in gn_operating_systems:
        for target_config in gn_configurations:
            for target_link_config in gn_link_configurations:
                for target_profile_config in gn_profile_configurations:
                    for target_cpu in get_target_os_cpus(target_os):
                        global_targets.append(sln.TargetSettings(
                            target_os=target_os,
                            target_config=target_config,
                            target_link_config=target_link_config,
                            target_profile_config=target_profile_config,
                            target_cpu=target_cpu,
                            vs_platform=f'{vs_os_get_pretty_name(target_os)} {vs_cpu_get_pretty_name(target_cpu)}',
                            vs_configuration=vs_configuration_get_pretty_name(target_config),
                            vs_link_configuration=vs_link_configuration_get_pretty_name(target_link_config),
                            gn_solution_dir=gn_solution_dir ))
    return global_targets

#@timer_func
def read_all_targets_and_descriptions(global_targets : list[sln.TargetSettings]):
    async def read_all_targets_and_descriptions_async(result_wrapper):
        description_futures = []
        for target_settings in global_targets:
            #description_futures.append(gn.get_descriptions_async(target_settings.gn_output_root))
            description_futures.append(gn.get_descriptions(target_settings.gn_output_root))

        target_futures = []
        for target_settings in global_targets:
            target_futures.append(gn.get_target_list_async(target_settings.gn_output_root))

        result_wrapper[0] = description_futures
        #result_wrapper[0] = await asyncio.gather(*description_futures)
        result_wrapper[1] = await asyncio.gather(*target_futures)
    return execute_async_task(read_all_targets_and_descriptions_async, 2)

# -----
# Setup the Visual Studio Projects
# -----

@timer_func
def setup_solution_project_structure(solution : sln.Solution, global_targets : list[sln.TargetSettings]):

    [all_target_descriptions, all_targets] = read_all_targets_and_descriptions(global_targets)
    all_target_descriptions : list[gn.Description]
    all_targets : list[list[gn.Target]]

    for index, target_settings in enumerate(global_targets):
        osplatformconfig = sln.OSPlatformConfiguration(
            target_settings.target_os, 
            target_settings.target_config, 
            target_settings.target_cpu, 
            target_settings.fs_triplet, 
            target_settings.vs_platform, 
            target_settings.vs_configuration,
            target_settings.vs_link_configuration,
            target_settings.gn_output_root)
        solution.osplatformconfigs.append(osplatformconfig)

        #targets = gn.get_target_list(target_settings.gn_output_root)
        #target_descriptions = gn.get_descriptions(target_settings.gn_output_root)

        targets = all_targets[index]
        target_descriptions = all_target_descriptions[index]

        for target in targets:
            #description = gn.get_description(target_settings.gn_output_root, target)

            if target.target == "*":
                description = gn.Description(target, {}, None)
            else:
                if target.target not in target_descriptions:
                    raise Exception(f'Unsupported target {target.target}')
                description = gn.Description(target, target_descriptions[target.target], None)

            description_and_osplatformconfig = sln.DescriptionAndOSPlatformConfiguration(description, osplatformconfig)

            project = solution.get_project_or_create(target.name)
            project.descriptions.append(description_and_osplatformconfig)

            #print(project.name, description.custom_target_type)

    def enqueue_folders(project : sln.Project, parent_folder : sln.Folder):
        description_and_osplatformconfig = project.descriptions[0]
        project_folder = description_and_osplatformconfig.description.project_folder
        if len(project_folder):
            for child_folder_name in project_folder:
                folder = parent_folder.get_folder_or_create(child_folder_name)
                #print(parent_folder.name, folder.name, len(parent_folder.folders))
                parent_folder = folder
            parent_folder.projects.append(project)

    for project in solution.projects:
        enqueue_folders(project, solution)

def sln_setup_cpp_default_properties_file():
    src_microsoft_cpp_default_properties_path = os.path.join(util.bcs_ewdk_dir, 'Program Files/Microsoft Visual Studio/2022/BuildTools/MSBuild/Microsoft/VC/v170/Microsoft.Cpp.Default.props')
    dst_microsoft_cpp_default_properties_path = os.path.join('solution', 'Cpp.Default.props')
    with open(src_microsoft_cpp_default_properties_path) as src_prop_file:
        prop_lines = iter(src_prop_file)

        new_prop_lines = []
        for line in prop_lines:
            if '<_RelativePlatformFolder' in line:
                #for osplatformconfig in solution.osplatformconfigs:
                    #new_prop_lines.append(f'    <_RelativePlatformFolder Condition="$(Platform)=='{osplatformconfig.vs_triplet}'">$(_RelativeApplicationTypeRevisionFolder)Platforms\{osplatformconfig.vs_triplet}\</_RelativePlatformFolder>\n')
                #new_prop_lines.append(f'    <_RelativePlatformFolder Condition="$(_RelativePlatformFolder)==\'\'">$(_RelativeApplicationTypeRevisionFolder)Platforms\$(Platform)\</_RelativePlatformFolder>\n')
                new_prop_lines.append(f'    <_RelativePlatformFolder Condition="$(_RelativePlatformFolder)==\'\'">$(_RelativeApplicationTypeRevisionFolder)Platforms\\x64\\</_RelativePlatformFolder>\n')
            else:
                new_prop_lines.append(line)
        prop_lines = new_prop_lines

        with open(dst_microsoft_cpp_default_properties_path, "w") as new_prop:
            new_prop.writelines(prop_lines)
