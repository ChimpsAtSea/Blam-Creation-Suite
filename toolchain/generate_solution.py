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

import gn
gn.set_gn_path(gn_path)
targets = gn.get_target_list("solution/windows-release-x86")
#print(targets)

index = 4
path = gn.system_path(bcs_root_dir, targets[index].directory)
#print("bcs_root_dir", bcs_root_dir)
#print("targets[index].directory", targets[index].directory)
#print("path", path)
#print("targets[index]", targets[index])

desc = gn.get_description(f'solution/windows-release-x86/', targets[index])
print("desc", desc)



# Helpers
def EnsureExists(path):
    try:
        os.makedirs(path)
    except OSError:
        pass

def WriteLinesToFile(lines, file_name):
    EnsureExists(os.path.dirname(file_name))
    with open(file_name, "w") as f:
        f.writelines(lines)

def ExtractIdg(proj_file_name):
    result = []
    with open(proj_file_name) as proj_file:
        lines = iter(proj_file)
        for p_line in lines:
            if "<ItemDefinitionGroup" in p_line:
                while not "</ItemDefinitionGroup" in p_line:
                    result.append(p_line)
                    p_line = next(lines)
                result.append(p_line)
    return result

def ExtractExec(proj_file_name, task_name):
    result = []
    with open(proj_file_name) as proj_file:
        lines = iter(proj_file)
        for p_line in lines:
            if f"<Target Name=\"{task_name}\"" in p_line:
                while not "</Target" in p_line:
                    if "<Exec" in p_line:
                        result.append(p_line)
                    p_line = next(lines)
    return result

def ExtractCustomBuild(proj_file_name):
    result = []
    with open(proj_file_name) as proj_file:
        lines = iter(proj_file)
        for p_line in lines:
            if f"<ItemGroup" in p_line:
                if not f"ProjectConfigurations" in p_line:
                    p_line = next(lines)
                    while not "</ItemGroup" in p_line:
                        result.append(p_line)
                        p_line = next(lines)
    return result
                
# [ (name, solution_name, vs_version), ... ]
configs = []
config_name_index = 0
config_solution_name_index = 1
config_vs_version_index = 2
config_operating_system_index = 3
config_configuration_index = 4
config_architecture_index = 5
config_vs_configuration_index = 6
config_vs_operating_system_and_platform_index = 7
config_vs_platform_index = 8

operating_systems = list()
configurations = list()
architectures = list()

def GetVSVersion(solution_file):
    with open(solution_file) as f:
        f.readline()
        comment = f.readline().strip()
        return comment[-4:]

# Find all directories that can be used as configs (and record if they have VS
# files present)
for root, dirs, files in os.walk("solution"):
    for out_dir in dirs:
        gn_file = os.path.join("solution", out_dir, "build.ninja.d")
        if os.path.exists(gn_file):
            solutions = glob.glob(os.path.join("solution", out_dir, "*.sln"))
            for solution in solutions:
                vs_version = GetVSVersion(solution)
                triplet = out_dir.split("-")
                operating_system = triplet[0]
                configuration = triplet[1]
                architecture = triplet[2]
                
                vs_platform = "x64"
                vs_operating_system_and_platform = "Windows x64"
                if operating_system == "windows":
                    if architecture == "x86":
                        vs_platform = "Win32"
                        vs_operating_system_and_platform = "Windows x86"
                    elif architecture == "x64":
                        vs_platform = "x64"
                        vs_operating_system_and_platform = "Windows x64"
                    elif architecture == "arm":
                        vs_platform = "ARM"
                        vs_operating_system_and_platform = "Windows ARM"
                    elif architecture == "arm64":
                        vs_platform = "ARM64"
                        vs_operating_system_and_platform = "Windows ARM64"
                elif operating_system == "linux":
                    if architecture == "x86":
                        vs_platform = "Win32"
                        vs_operating_system_and_platform = "Linux x86"
                    elif architecture == "x64":
                        vs_platform = "x64"
                        vs_operating_system_and_platform = "Linux x64"
                elif operating_system == "webassembly":
                    if architecture == "wasm32":
                        vs_platform = "Win32"
                        vs_operating_system_and_platform = "WebAssembly WASM32"
                    elif architecture == "wasm64":
                        vs_platform = "x64"
                        vs_operating_system_and_platform = "WebAssembly WASM64"
                    
                vs_configuration = "Debug"
                if configuration == "debug":
                    vs_configuration = "Debug"
                elif configuration == "test":
                    vs_configuration = "Test"
                elif configuration == "release":
                    vs_configuration = "Release"
                    
                operating_systems.append(operating_system)
                configurations.append(configuration)
                architectures.append(architecture)
                config = (out_dir, os.path.basename(solution), vs_version, operating_system, configuration, architecture, vs_configuration, vs_operating_system_and_platform, vs_platform)
                configs.append(config)
    break

operating_systems = set(operating_systems)
configurations = set(configurations)
architectures = set(architectures)

print(operating_systems)
print(configurations)
print(architectures)
            
# Every project has a GUID that encodes the type. We only care about C++.
cpp_type_guid = "8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942"
python_type_guid = "888888A0-9F3D-457C-B088-3A5042F75D52"

# Work around MSBuild limitations by always using a fixed arch.
hard_coded_arch = "x64"

# name -> [ (config, pathToProject, GUID, arch), ... ]
all_projects = {}
project_pattern = (r'Project\("\{' + cpp_type_guid +
                   r'\}"\) = "([^"]*)", "([^"]*)", "\{([^\}]*)\}"')

# We need something to work with. Typically, this will fail if no GN folders
# have IDE files
if len(configs) == 0:
    print("ERROR: At least one GN directory must have been built with --ide=vs")
    sys.exit()

# Filter out configs which don't match the name and vs version of the first.
solution_name = configs[0][config_solution_name_index]
output_solution_name = "blamcreationsuite.sln"
vs_version = configs[0][config_vs_version_index]

project_config_name_index = 0
project_config_unknown1_index = 1
project_config_guid_index = 2
project_config_vs_configuration_index = 3
project_config_vs_operating_system_and_platform_index = 4
project_config_vs_platform_index = 5

for config in configs:
    if config[config_solution_name_index] != solution_name or config[config_vs_version_index] != vs_version:
        continue

    sln_lines = iter(open(os.path.join("solution", config[config_name_index], config[config_solution_name_index])))
    for sln_line in sln_lines:
        match_obj = re.match(project_pattern, sln_line)
        if match_obj:
            proj_name = match_obj.group(1)
            proj_config = (config[config_name_index], match_obj.group(2), match_obj.group(3), config[config_vs_configuration_index], config[config_vs_operating_system_and_platform_index], config[config_vs_platform_index])
            if proj_name not in all_projects:
                all_projects[proj_name] = []
            all_projects[proj_name].append(proj_config)

# We need something to work with. Typically, this will fail if no GN folders
# have IDE files
if len(all_projects) == 0:
    print("ERROR: At least one GN directory must have been built with --ide=vs")
    sys.exit()

mandrill_python_guid = "0F701F52-48C0-4F1F-AFCD-C63D5CC91EEF";
mandrill_python_stub = "mandrill_python_stub";

def GetVSProjectGUID(target_proj_name):
    for proj_name, proj_configs in all_projects.items():
        if proj_name == target_proj_name:
            guid = proj_configs[0][project_config_guid_index]
            return guid
               
mandrill_python_stub_guid = GetVSProjectGUID(mandrill_python_stub)
print("mandrill_python_stub_guid", mandrill_python_stub_guid)

# Create a new solution. We arbitrarily use the first config as the GUID source
# (but we need to match that behavior later, when we copy/generate the project
# files).
new_sln_lines = []
new_sln_lines.append(
    'Microsoft Visual Studio Solution File, Format Version 12.00\n')
new_sln_lines.append('# Visual Studio ' + vs_version + '\n')
for proj_name, proj_configs in all_projects.items():
    new_sln_lines.append(f'Project("{{{cpp_type_guid}}}") = "{proj_name}", "{proj_configs[0][project_config_unknown1_index]}", "{{{proj_configs[0][project_config_guid_index]}}}"\n')
    new_sln_lines.append('EndProject\n')

new_sln_lines.append(f'Project("{{{python_type_guid}}}") = "Mandrill Python", "obj/mandrill_python.pyproj", "{{{mandrill_python_guid}}}"\n')
new_sln_lines.append(f'\tProjectSection(ProjectDependencies) = postProject\n')
new_sln_lines.append(f'\t\t{{{mandrill_python_stub_guid}}} = {{{mandrill_python_stub_guid}}}\n')
new_sln_lines.append(f'\tEndProjectSection\n')
new_sln_lines.append(f'EndProject\n')
    
new_sln_lines.append('Global\n')
new_sln_lines.append(
    '\tGlobalSection(SolutionConfigurationPlatforms) = preSolution\n')
for config in configs:
    match = config[config_vs_configuration_index] + '|' + config[config_vs_operating_system_and_platform_index]
    new_sln_lines.append('\t\t' + match + ' = ' + match + '\n')
new_sln_lines.append('\tEndGlobalSection\n')
new_sln_lines.append(
    '\tGlobalSection(ProjectConfigurationPlatforms) = postSolution\n')
    
for proj_name, proj_configs in all_projects.items():
    proj_guid = proj_configs[0][project_config_guid_index]
    for config in configs:
        match = config[config_vs_configuration_index] + '|' + config[config_vs_operating_system_and_platform_index]
        new_sln_lines.append('\t\t{' + proj_guid + '}.' + match +
                           '.ActiveCfg = ' + match + '\n')
        new_sln_lines.append('\t\t{' + proj_guid + '}.' + match +
                           '.Build.0 = ' + match + '\n')
                           
for config in configs:
    match = config[config_vs_configuration_index] + '|' + config[config_vs_operating_system_and_platform_index]
    config_name = "Debug"
    if config[config_vs_configuration_index] == "Release":
        config_name = "Release"
    new_sln_lines.append(f"\t\t{{{mandrill_python_guid}}}.{match}.ActiveCfg = {config_name}|Any CPU\n")
    new_sln_lines.append(f"\t\t{{{mandrill_python_guid}}}.{match}.Build.0 = {config_name}|Any CPU\n")
    
new_sln_lines.append('\tEndGlobalSection\n')
new_sln_lines.append('\tGlobalSection(SolutionProperties) = preSolution\n')
new_sln_lines.append('\t\tHideSolutionNode = FALSE\n')
new_sln_lines.append('\tEndGlobalSection\n')
new_sln_lines.append('\tGlobalSection(NestedProjects) = preSolution\n')
new_sln_lines.append('\tEndGlobalSection\n')
new_sln_lines.append('EndGlobal\n')

# Write solution file
WriteLinesToFile(new_sln_lines, 'solution/' + output_solution_name)

idg_hdr = "  <ItemDefinitionGroup Condition=\"'$(Configuration)|$(Platform)'=='"

configuration_template = """    <ProjectConfiguration Include="{config}|{platform}">
      <Configuration>{config}</Configuration>
      <Platform>{platform}</Platform>
    </ProjectConfiguration>
"""

def FormatProjectConfig(config):
    return configuration_template.format(
        config = config[config_vs_configuration_index], platform = config[config_vs_operating_system_and_platform_index])

# Now, bring over the project files
for proj_name, proj_configs in all_projects.items():
    # Paths to project and filter file in src and dst locations
    src_proj_path = os.path.join("solution", proj_configs[0][project_config_name_index], proj_configs[0][project_config_unknown1_index])
    dst_proj_path = os.path.join("solution", proj_configs[0][project_config_unknown1_index])
    src_filter_path = src_proj_path + ".filters"
    dst_filter_path = dst_proj_path + ".filters"

    # Copy the filter file unmodified
    EnsureExists(os.path.dirname(dst_proj_path))
    copyfile(src_filter_path, dst_filter_path)

    preferred_tool_arch = None
    config_arch = {}

    # Bring over the project file, modified with extra configs
    with open(src_proj_path) as src_proj_file:
        proj_lines = iter(src_proj_file)
        
        new_proj_lines = []
        for line in proj_lines:
            if "<ItemDefinitionGroup" in line:
                # This is a large group that contains many settings. We need to
                # replicate it, with conditions so it varies per configuration.
                idg_lines = []
                while not "</ItemDefinitionGroup" in line:
                    idg_lines.append(line)
                    line = next(proj_lines)
                idg_lines.append(line)
                for proj_config in proj_configs:
                    config_idg_lines = ExtractIdg(
                        os.path.join("solution", proj_config[project_config_name_index], proj_config[project_config_unknown1_index]))
                    match = proj_config[project_config_vs_configuration_index] + '|' + proj_config[project_config_vs_operating_system_and_platform_index]
                    new_proj_lines.append(idg_hdr + match + "'\">\n")
                    for idg_line in config_idg_lines[1:]:
                        new_proj_lines.append(idg_line)
            elif "ProjectConfigurations" in line:
                new_proj_lines.append(line)
                next(proj_lines)
                next(proj_lines)
                next(proj_lines)
                next(proj_lines)
                for config in configs:
                    new_proj_lines.append(FormatProjectConfig(config))

                

            elif "<OutDir" in line:
                # new_proj_lines.append(line.replace(proj_configs[0][project_config_vs_configuration_index], "$(Configuration)"))
                new_proj_lines.append("    <OutDir>$(SolutionDir)$(Platform.split(\" \")[0].toLower())-$(Configuration.ToLower())-$(Platform.split(\" \")[1].toLower())\\</OutDir>\n")
            elif "<PreferredToolArchitecture" in line:
                new_proj_lines.append("    <PreferredToolArchitecture>" +
                                      "x64"
                                      "</PreferredToolArchitecture>\n")
            elif "<Target Name=" in line:
                new_proj_lines.append(line)
                
                target_name = re.findall(r'Name="(.+?)"', line)[0]
                line = next(proj_lines)
                
                old_exec_lines = []
                while not "</Target" in line:
                    old_exec_lines.append(line)
                    line = next(proj_lines)
                    
                for proj_config in proj_configs:
                    match = proj_config[project_config_vs_configuration_index] + '|' + proj_config[project_config_vs_operating_system_and_platform_index]
                    target_exec_lines = ExtractExec(
                        os.path.join("solution", proj_config[project_config_name_index], proj_config[project_config_unknown1_index]),
                        target_name)
                    for target_exec_line in target_exec_lines:
                        if " />" in target_exec_line:
                            offset = target_exec_line.find(" />")
                        else:
                            offset = target_exec_line.find(">")
                        target_exec_line_condition = target_exec_line[:offset] + f" Condition=\"'$(Configuration)|$(Platform)'=='{match}'\"" + target_exec_line[offset:]
                        new_proj_lines.append(target_exec_line_condition)
                        
                new_proj_lines.append(line)
            elif "<ItemGroup" in line and not "<ItemGroup />" in line:
                new_proj_lines.append(line)
                
                a = line
                line = next(proj_lines)
                if not "<ProjectConfiguration" in line:
                    #contains build items
                    b = line
                    
                    old_custom_build_lines = []
                    while not "</ItemGroup" in line:
                        old_custom_build_lines.append(line)
                        line = next(proj_lines)
                        
                    for proj_config in proj_configs:
                        match = proj_config[project_config_vs_configuration_index] + '|' + proj_config[project_config_vs_operating_system_and_platform_index]
                        target_custom_build_lines = ExtractCustomBuild(
                            os.path.join("solution", proj_config[project_config_name_index], proj_config[project_config_unknown1_index]))
                        for target_custom_build_line in target_custom_build_lines:
                            use_condition = 0
                            if "<CustomBuild" in target_custom_build_line:
                                use_condition = 1
                            if "<None" in target_custom_build_line:
                                use_condition = 1
                            
                            if use_condition:
                                if " />" in target_custom_build_line:
                                    offset = target_custom_build_line.find(" />")
                                else:
                                    offset = target_custom_build_line.find(">")
                                target_custom_build_line_condition = target_custom_build_line[:offset] + f" Condition=\"'$(Configuration)|$(Platform)'=='{match}'\"" + target_custom_build_line[offset:]
                                new_proj_lines.append(target_custom_build_line_condition)
                            else:
                                new_proj_lines.append(target_custom_build_line)
                    
                    new_proj_lines.append(line)
            elif "$(VCTargetsPath)\Microsoft.Cpp.Default.props" in line:
                new_proj_lines.append(line.replace("$(VCTargetsPath)\Microsoft.Cpp.Default.props", "$(SolutionDir)\Cpp.Default.props"))
            else:
                new_proj_lines.append(line)
        proj_lines = new_proj_lines
        
        new_proj_lines = []
        for line in proj_lines:
            if "../../../" in line:
                new_proj_lines.append(line.replace("../../../", "../../"))
            elif "-C $(OutDir)" in line:
                new_proj_lines.append(line.replace("-C $(OutDir)", "-C &quot;$(OutDir)\&quot;"))
            else:
                new_proj_lines.append(line)
        proj_lines = new_proj_lines
        
        with open(dst_proj_path, "w") as new_proj:
            new_proj.writelines(proj_lines)

thirdparty = os.getenv("BCS_THIRD_PARTY", "thirdparty")
src_microsoft_cpp_default_properties_path = os.path.join(thirdparty, "EWDK_ni_release_svc_prod1_22621_220804-1759/Program Files/Microsoft Visual Studio/2022/BuildTools/MSBuild/Microsoft/VC/v170/Microsoft.Cpp.Default.props")
dst_microsoft_cpp_default_properties_path = os.path.join("solution", "Cpp.Default.props")
with open(src_microsoft_cpp_default_properties_path) as src_prop_file:
    prop_lines = iter(src_prop_file)

    new_prop_lines = []
    for line in prop_lines:
        if "<_RelativePlatformFolder" in line:
            for proj_config in proj_configs:
                new_prop_lines.append(f"    <_RelativePlatformFolder Condition=\"$(Platform)=='{proj_config[project_config_vs_operating_system_and_platform_index]}'\">$(_RelativeApplicationTypeRevisionFolder)Platforms\{proj_config[project_config_vs_platform_index]}\</_RelativePlatformFolder>\n")
            new_prop_lines.append(f"    <_RelativePlatformFolder Condition=\"$(_RelativePlatformFolder)==''\">$(_RelativeApplicationTypeRevisionFolder)Platforms\$(Platform)\</_RelativePlatformFolder>\n")
        else:
            new_prop_lines.append(line)
    prop_lines = new_prop_lines

    with open(dst_microsoft_cpp_default_properties_path, "w") as new_prop:
        new_prop.writelines(prop_lines)


gn_dir = os.environ['GN_DIR']
gn = os.path.join(gn_dir, "gn")
mandrill_python_stub_query = subprocess.run(f'{gn} desc solution/windows-release-x86/ //:mandrill_python_stub', shell=True, stdout=subprocess.PIPE).stdout.decode('utf-8')
mandrill_python_stub_lines = mandrill_python_stub_query.strip().split('\n')

# Initialize the object as a dictionary
mandrill_python_stub = {}

# Iterate over the lines and parse the key-value pairs
current_key = None
for line in mandrill_python_stub_lines:
  if line.startswith(' '):
    # This line is a value for the current key
    mandrill_python_stub[current_key].append(line.strip())
  else:
    # This line is a new key
    parts = line.split(':')
    key = parts[0].strip()
    value = parts[1].strip() if len(parts) > 1 else []
    mandrill_python_stub[key] = value
    current_key = key

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
    

dst_mandrill_python_project_path = os.path.join("solution", "obj", "mandrill_python.pyproj")
with open(dst_mandrill_python_project_path, "w") as mandrill_python_project_file:
    mandrill_python_project_lines = []
    
    mandrill_python_project_lines.append('<Project DefaultTargets="Build" xmlns="http://schemas.microsoft.com/developer/msbuild/2003" ToolsVersion="4.0">\n')
    mandrill_python_project_lines.append('  <PropertyGroup>\n')
    mandrill_python_project_lines.append('    <Configuration Condition="\'$(Configuration)\'==\'\'">Debug</Configuration>\n')
    mandrill_python_project_lines.append('    <Configuration>Debug2</Configuration>\n')
    mandrill_python_project_lines.append('    <SchemaVersion>2.0</SchemaVersion>\n')
    mandrill_python_project_lines.append(f'    <ProjectGuid>{mandrill_python_guid}</ProjectGuid>\n')
    mandrill_python_project_lines.append('    <ProjectHome>.</ProjectHome>\n')
    for input in mandrill_python_stub["inputs"]:
        if "main.py" in input:
            mandrill_python_project_lines.append(f'    <StartupFile>../../{input[2:]}</StartupFile>\n')
    mandrill_python_project_lines.append("    <WorkingDirectory>$(SolutionDir)windows-$(Configuration)-x64\\bin\\</WorkingDirectory>\n")
    mandrill_python_project_lines.append('    <OutputPath>.</OutputPath>\n')
    mandrill_python_project_lines.append('    <Name>Mandrill Python</Name>\n')
    mandrill_python_project_lines.append('    <RootNamespace>MandrillPython</RootNamespace>\n')
    mandrill_python_project_lines.append('    <LaunchProvider>Standard Python launcher</LaunchProvider>\n')
    mandrill_python_project_lines.append('    <EnableNativeCodeDebugging>True</EnableNativeCodeDebugging>\n')
    mandrill_python_project_lines.append('    <EnableUnmanagedDebugging>true</EnableUnmanagedDebugging>\n')
    mandrill_python_project_lines.append('    <DebugSymbols>true</DebugSymbols>\n')
    mandrill_python_project_lines.append('  </PropertyGroup>\n')
    mandrill_python_project_lines.append('  <ItemGroup>\n')
    for input in mandrill_python_stub["inputs"]:
        mandrill_python_project_lines.append(f'    <Compile Include="../../{input[2:]}" />\n')
    mandrill_python_project_lines.append('  </ItemGroup>\n')
    mandrill_python_project_lines.append(f'  <Import Project="{custom_python_tools_targets}" />\n')
    mandrill_python_project_lines.append('  <Target Name="CoreCompile" />\n')
    mandrill_python_project_lines.append('</Project>\n')
    
    mandrill_python_project_file.writelines(mandrill_python_project_lines)
    
print('Wrote meta solution to solution/' + output_solution_name)
