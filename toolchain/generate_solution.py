from __future__ import print_function

import os
import glob
import re
import sys
from shutil import copyfile
import subprocess

# Allow Local Imports
sys.path.append(os.path.realpath(os.path.dirname(__file__)))

bcs_root_dir = os.environ['BCS_ROOT']
env_gn_dir = os.environ['GN_DIR']
gn_path = os.path.join(env_gn_dir, "gn")
env_ninja_dir = os.environ['NINJA_DIR']
ninja_path = os.path.join(env_ninja_dir, "ninja")

import gn
import sln

gn_solution_dir='//solution'

def vs_os_get_pretty_name(target_os : str):
    lookup = {
        "windows": "Windows",
        "win": "Windows",
        "linux": "Linux",
        "webassembly": "Webassembly",
        "wasm": "Webassembly",
    }
    if target_os in lookup:
        return lookup[target_os]
    return target_os

def vs_cpu_get_pretty_name(target_cpu : str):
    lookup = {
        "x86": "x86",
        "x64": "x64",
        "arm": "Arm",
        "arm64": "Arm64",
        "wasm": "wasm32",
        "wasm32": "wasm32",
        "wasm64": "wasm64",
    }
    if target_cpu in lookup:
        return lookup[target_cpu]
    return target_cpu

def vs_configuration_get_pretty_name(target_config : str):
    lookup = {
        "debug": "Debug",
        "test": "Test",
        "release": "Release",
    }
    if target_config in lookup:
        return lookup[target_config]
    return target_config

def get_target_os_cpus(target_os : str):
    key = vs_os_get_pretty_name(target_os)
    lookup = {
        "Windows": [ "x86", "x64", "arm", "arm64" ],
        "Linux": [ "x86", "x64"] ,
        "Webassembly": [ 
            "wasm32", 
            #"wasm64"
        ]
    }
    if key in lookup:
        return lookup[key]
    else:
        print(target_os, key)
        raise("Invalid target_os")

global_targets = list[sln.TargetSettings]()
for target_os in [ "windows", "linux", "webassembly" ]:
    for target_config in [ "debug", "test", "release" ]:
        for target_cpu in get_target_os_cpus(target_os):
            global_targets.append(sln.TargetSettings(
                target_os=target_os,
                target_config=target_config,
                target_cpu=target_cpu,
                vs_platform=f'{vs_os_get_pretty_name(target_os)} {vs_cpu_get_pretty_name(target_cpu)}',
                vs_configuration=vs_configuration_get_pretty_name(target_config),
                gn_solution_dir=gn_solution_dir
            ))

solution = sln.Solution('Blam Creation Suite', 'solution/blamcreationsuite.sln')

for target_settings in global_targets:
    osplatformconfig = sln.OSPlatformConfiguration(
        target_settings.target_os, 
        target_settings.target_config, 
        target_settings.target_cpu, 
        target_settings.fs_triplet, 
        target_settings.vs_platform, 
        target_settings.vs_configuration,
        target_settings.gn_output_root)
    solution.osplatformconfigs.append(osplatformconfig)

    targets = gn.get_target_list(target_settings.gn_output_root)

    for target in targets:
        path = gn.system_path(bcs_root_dir, target.directory)
        
        description = gn.get_description(target_settings.gn_output_root, target)
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

for project in solution.projects:
    sln.write_project(solution, project)
sln.write_solution("solution/", solution)

thirdparty = os.getenv("BCS_THIRD_PARTY", "thirdparty")
src_microsoft_cpp_default_properties_path = os.path.join(thirdparty, "EWDK_ni_release_svc_prod1_22621_220804-1759/Program Files/Microsoft Visual Studio/2022/BuildTools/MSBuild/Microsoft/VC/v170/Microsoft.Cpp.Default.props")
dst_microsoft_cpp_default_properties_path = os.path.join("solution", "Cpp.Default.props")
with open(src_microsoft_cpp_default_properties_path) as src_prop_file:
    prop_lines = iter(src_prop_file)

    new_prop_lines = []
    for line in prop_lines:
        if "<_RelativePlatformFolder" in line:
            #for osplatformconfig in solution.osplatformconfigs:
                #new_prop_lines.append(f"    <_RelativePlatformFolder Condition=\"$(Platform)=='{osplatformconfig.vs_triplet}'\">$(_RelativeApplicationTypeRevisionFolder)Platforms\{osplatformconfig.vs_triplet}\</_RelativePlatformFolder>\n")
            #new_prop_lines.append(f"    <_RelativePlatformFolder Condition=\"$(_RelativePlatformFolder)==''\">$(_RelativeApplicationTypeRevisionFolder)Platforms\$(Platform)\</_RelativePlatformFolder>\n")
            new_prop_lines.append(f"    <_RelativePlatformFolder Condition=\"$(_RelativePlatformFolder)==''\">$(_RelativeApplicationTypeRevisionFolder)Platforms\\x64\\</_RelativePlatformFolder>\n")
        else:
            new_prop_lines.append(line)
    prop_lines = new_prop_lines

    with open(dst_microsoft_cpp_default_properties_path, "w") as new_prop:
        new_prop.writelines(prop_lines)
        
ewdk_dir = os.environ['EWDK_DIR']
ewdk_python_tools_dir = os.path.join(ewdk_dir, "Program Files/Microsoft Visual Studio/2022/BuildTools/MSBuild/Microsoft/VisualStudio/v17.0/Python Tools")
ewdk_python_tools_targets = os.path.join(ewdk_python_tools_dir, "Microsoft.PythonTools.targets")
bcs_root = os.environ['BCS_ROOT']
custom_python_tools_targets = os.path.join(bcs_root, "solution", "PythonTools.targets")

with open(ewdk_python_tools_targets) as ewdk_python_tools_targets_file:
    ewdk_python_tools_targets_lines = iter(ewdk_python_tools_targets_file)
    with open(custom_python_tools_targets, "w") as custom_python_tools_targets_file:
        custom_python_tools_targets_lines = []
        
        for line in ewdk_python_tools_targets_lines:
            if "<Target Name=\"ResolveStartupModule\"" in line:
                leading_whitespace = line[:len(line) - len(line.lstrip())]
                code = line[len(line) - len(line.lstrip()):]
                custom_python_tools_targets_lines.append(f"{leading_whitespace}<!--{code}")
                line = next(ewdk_python_tools_targets_lines)
                while not "</Target>" in line:
                    custom_python_tools_targets_lines.append(line)
                    line = next(ewdk_python_tools_targets_lines)
                
                leading_whitespace = line[:len(line) - len(line.lstrip())]
                code = line[len(line) - len(line.lstrip()):]
                trailing_whitespace = code[len(code.rstrip()):]
                code = code[:len(code.rstrip())]
                custom_python_tools_targets_lines.append(f"{leading_whitespace}{code}-->{trailing_whitespace}")
            else:
                custom_python_tools_targets_lines.append(line)
        
        custom_python_tools_targets_file.writelines(custom_python_tools_targets_lines)
