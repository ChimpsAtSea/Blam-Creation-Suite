import uuid
import re
import gn
import html
import os
from util import pretty_print_dict
from hashlib import md5

bcs_root_dir = os.environ['BCS_ROOT']
env_gn_dir = os.environ['GN_DIR']
gn_path = os.path.join(env_gn_dir, "gn")
env_ninja_dir = os.environ['NINJA_DIR']
ninja_path = os.path.join(env_ninja_dir, "ninja")

ewdk_dir = os.environ['EWDK_DIR']
ewdk_python_tools_dir = os.path.join(ewdk_dir, "Program Files/Microsoft Visual Studio/2022/BuildTools/MSBuild/Microsoft/VisualStudio/v17.0/Python Tools")
ewdk_python_tools_targets = os.path.join(ewdk_python_tools_dir, "Microsoft.PythonTools.targets")
bcs_root = os.environ['BCS_ROOT']
custom_python_tools_targets = os.path.join(bcs_root, "solution", "PythonTools.targets")

class TargetSettings:
    target_os : str = None
    target_config : str = None
    target_cpu : str = None
    fs_triplet : str = None
    vs_platform : str = None
    vs_configuration : str = None
    gn_output_root : str = None

    def __init__(self, target_os, target_config, target_cpu, vs_platform, vs_configuration, gn_solution_dir):
        self.target_os = target_os
        self.target_config = target_config
        self.target_cpu = target_cpu
        self.fs_triplet = f'{target_os}-{target_config}-{target_cpu}'
        self.vs_platform = vs_platform
        self.vs_configuration = vs_configuration
        self.gn_output_root = os.path.join(gn_solution_dir, self.fs_triplet)

class OSPlatformConfiguration:
    target_os : str = None
    target_config : str = None
    target_cpu : str = None
    fs_triplet : str = None
    vs_platform : str = None
    vs_configuration : str = None
    vs_triplet : str = None
    output_root : str = None

    def __init__(self, target_os, target_config, target_cpu, fs_triplet, vs_platform, vs_configuration, output_root):
        self.target_os = target_os
        self.target_config = target_config
        self.target_cpu = target_cpu
        #self.fs_triplet = f'{self.os}-{self.platform}-{self.cpu}'
        self.fs_triplet = fs_triplet
        self.vs_platform = vs_platform
        self.vs_configuration = vs_configuration
        self.vs_triplet = f'{self.vs_configuration}|{self.vs_platform}'
        self.output_root = output_root

    def __repr__(self):
        return pretty_print_dict(self.__dict__)
    
    def __eq__(self, other):
        if isinstance(other, OSPlatformConfiguration):
            other : OSPlatformConfiguration
            return self.os == other.os and \
                self.config == other.config and \
                self.cpu == other.cpu and \
                self.fs_triplet == other.fs_triplet and \
                self.vs_platform == other.vs_platform and \
                self.vs_configuration == other.vs_configuration and \
                self.vs_triplet == other.vs_triplet
        return False

class DescriptionAndOSPlatformConfiguration:
    osplatformconfig : OSPlatformConfiguration = None
    description : gn.Description = None

    def __init__(self, description, osplatformconfig):
        self.description = description
        self.osplatformconfig = osplatformconfig

    def __eq__(self, other):
        if isinstance(other, DescriptionAndOSPlatformConfiguration):
            other : DescriptionAndOSPlatformConfiguration
            return self.description == other.description and \
                self.osplatformconfig == other.osplatformconfig
        return False

class Project:
    name : str = None
    namespace : str = None
    guid : uuid.UUID = None
    targets : list[gn.Target] = []
    descriptions : list[DescriptionAndOSPlatformConfiguration] = []
    solution = None

    def __init__(self, name, solution):
        digest = md5(bytes(f"project-{name}", "utf-8"), usedforsecurity=False).digest()

        self.name = name
        self.namespace = re.sub(r'[^0-9a-zA-Z]+', '', name)
        self.guid = uuid.UUID(bytes=digest[:16], version=3)
        self.targets = list[gn.Target]()
        self.descriptions = list[DescriptionAndOSPlatformConfiguration]()
        self.solution = solution

    def __repr__(self):
        return pretty_print_dict(self.__dict__)
    
    def get_aggregate_sources(self):
        sources = set[str]()
        for description_and_osplatformconfig in self.descriptions:
            osplatformconfig = description_and_osplatformconfig.osplatformconfig
            description = description_and_osplatformconfig.description
            target = description.target
            for source in description.sources:
                sources.add(source)
        sources = sorted(sources)
        return sources
    
    def get_aggregate_inputs(self):
        inputs = set[str]()
        for description_and_osplatformconfig in self.descriptions:
            osplatformconfig = description_and_osplatformconfig.osplatformconfig
            description = description_and_osplatformconfig.description
            target = description.target
            for input in description.inputs:
                inputs.add(input)
        inputs = sorted(inputs)
        return inputs

    def get_project_type(self):
        if len(self.descriptions):
            custom_target_type = self.descriptions[0].description.custom_target_type
            return custom_target_type
        return None

    def get_type_guid(self):
        cpp_type_guid = "8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942"
        python_type_guid = "888888A0-9F3D-457C-B088-3A5042F75D52"
        
        project_type = self.get_project_type()
        if project_type == "python_library":
            return python_type_guid

        return cpp_type_guid

    def get_guid(self):
        return str(self.guid).upper()

    def get_project_filepath(self):
        project_extension = "vcxproj"
        description = self.descriptions[0].description
        if description.custom_target_type == "python_library":
            project_extension = "pyproj"
        #print(description.custom_target_type)
        project_filepath = os.path.join(os.path.dirname(self.solution.filepath), f'{description.target.name}.{project_extension}')
        return project_filepath
    
class Folder:
    name : str = None
    namespace : str = None
    folders : list = None
    projects : list[Project] = None
    filepath : str = None
    parent = None

    def __init__(self, name, parent):
        name : str

        self.folders = list[Folder]()
        self.projects = list[Project]()
        self.parent = parent
        if parent == None:
            digest = md5(bytes(f"folder-{name}", "utf-8"), usedforsecurity=False).digest()
        else:
            digest = md5(bytes(f"{self.parent.name}folder-{name}", "utf-8"), usedforsecurity=False).digest()

        self.name = name
        self.namespace = re.sub(r'[^0-9a-zA-Z]+', '', name)
        self.guid = uuid.UUID(bytes=digest[:16], version=3)

    def __repr__(self):
        return pretty_print_dict(self.__dict__)

    def get_project(self, target_name):
        for project in self.projects:
            if project.name == target_name:
                return project

    def get_folder(self, folder_name):
        for folder in self.folders:
            folder : Folder
            if folder.name == folder_name:
                return folder

    def get_folder_or_create(self, folder_name):
        for folder in self.folders:
            folder : Folder
            if folder.name == folder_name:
                return folder
        folder = Folder(folder_name, self)
        self.folders.append(folder)
        #print(f"Creating folder parent:{self.name} child:{folder.name}", len(self.folders))
        #for _folder in self.folders:
        #    print(f" child:{_folder.name}")
        return folder

    def get_type_guid(self):
        return "2150E333-8FDC-42A3-9474-1A3956D46DE8"

    def get_guid(self):
        return str(self.guid).upper()

class Solution(Folder):
    osplatformconfigs : list[OSPlatformConfiguration] = []

    def __init__(self, name, filepath):
        super().__init__(name, None)
        self.filepath = filepath

    def __repr__(self):
        object = {
            "name": self.name,
            "folders": self.folders,
            "projects": self.projects,
        }
        return pretty_print_dict(object)

    def get_project_or_create(self, target_name):
        for project in self.projects:
            if project.name == target_name:
                return project
        project = Project(target_name, self)
        self.projects.append(project)
        return project

def write_file_if_changed(file_path, lines):
    new_content = "\n".join(lines)
    try:
        with open(file_path, 'r') as existing_file:
            current_content = existing_file.read()
            if current_content == new_content:
                return False
    except FileNotFoundError:
        pass

    with open(file_path, 'w') as new_file:
        new_file.write(new_content)
        return True

def write_folder_projects(parent_folder : Folder, lines : list[str]):
    for child_folder in parent_folder.folders:
        type_guid = child_folder.get_type_guid()
        guid = child_folder.get_guid()
        lines.append(f'Project("{{{type_guid}}}") = "{child_folder.name}", "{child_folder.name}", "{{{guid}}}"')
        lines.append(f'EndProject')
    for child_folder in parent_folder.folders:
        write_folder_projects(child_folder, lines)

def write_nested_projects(parent_folder : Folder, lines : list[str]):
    parent_guid = parent_folder.get_guid()

    for child_folder in parent_folder.folders:
        child_folder : Folder
        child_guid = child_folder.get_guid()
        lines.append(f'\t\t{{{child_guid}}} = {{{parent_guid}}}')

    for child_project in parent_folder.projects:
        child_guid = child_project.get_guid()
        lines.append(f'\t\t{{{child_guid}}} = {{{parent_guid}}}')

    for child_folder in parent_folder.folders:
        write_nested_projects(child_folder, lines)

def write_solution_projects(lines : list[str], solution : Solution, write_all_build : bool):
    for project in solution.projects:
        is_all_build = project.name == "all_build"
        if write_all_build == is_all_build:
            project_filepath = project.get_project_filepath()
            type_guid = project.get_type_guid()
            guid = project.get_guid()

            #print(project.name, len(project.descriptions))
            lines.append(f'Project("{{{type_guid}}}") = "{project.descriptions[0].description.target.name}", "{os.path.basename(project_filepath)}", "{{{guid}}}"')
            lines.append(f'EndProject')

def write_solution(output_directory: str, solution : Solution):
    output_directory : str
    lines = list[str]()

    lines.append(f'Microsoft Visual Studio Solution File, Format Version 12.00')
    lines.append(f'# Visual Studio Version 17')
    #lines.append(f'VisualStudioVersion = 17.4.33205.214')
    #lines.append(f'MinimumVisualStudioVersion = 10.0.40219.1')
    write_solution_projects(lines, solution, False)
    write_solution_projects(lines, solution, True)
    write_folder_projects(solution, lines)
    lines.append(f'Global')
    lines.append(f'\tGlobalSection(SolutionConfigurationPlatforms) = preSolution')
    for osplatformconfig in solution.osplatformconfigs:
        lines.append(f'\t\t{osplatformconfig.vs_triplet} = {osplatformconfig.vs_triplet}')
    lines.append(f'\tEndGlobalSection')
    lines.append(f'\tGlobalSection(ProjectConfigurationPlatforms) = postSolution')
    for osplatformconfig in solution.osplatformconfigs:
        for project in solution.projects:
            project_guid = project.get_guid()
            type = project.get_project_type()
            if type == "python_library":
                if osplatformconfig.target_config == "release":
                    vs_triplet = f'Release|Any CPU'
                else:
                    vs_triplet = f'Debug|Any CPU'
                lines.append(f'\t\t{{{project_guid}}}.{osplatformconfig.vs_triplet}.ActiveCfg = {vs_triplet}')
                #lines.append(f'\t\t{{{project_guid}}}.{osplatformconfig.vs_triplet}.Build.0 = {vs_triplet}')
            else:
                lines.append(f'\t\t{{{project_guid}}}.{osplatformconfig.vs_triplet}.ActiveCfg = {osplatformconfig.vs_triplet}')
                lines.append(f'\t\t{{{project_guid}}}.{osplatformconfig.vs_triplet}.Build.0 = {osplatformconfig.vs_triplet}')
    lines.append(f'\tEndGlobalSection')
    lines.append(f'\tGlobalSection(SolutionProperties) = preSolution')
    lines.append(f'\t\tHideSolutionNode = FALSE')
    lines.append(f'\tEndGlobalSection')
    lines.append(f'\tGlobalSection(NestedProjects) = preSolution')
    for folder in solution.folders:
        write_nested_projects(folder, lines)
    lines.append(f'\tEndGlobalSection')
    #lines.append(f'\tGlobalSection(ExtensibilityGlobals) = postSolution')
    #lines.append('\t\tSolutionGuid = {EC5AA000-0A54-4352-965F-7033B55E412D}')
    #lines.append(f'\tEndGlobalSection')
    lines.append(f'EndGlobal')

    os.makedirs(os.path.dirname(solution.filepath), exist_ok=True)
    if write_file_if_changed(solution.filepath, lines):
        print(solution.filepath, "changed")

def write_python_project(solution : Solution, project : Project):
    project_filepath = project.get_project_filepath()

    lines = []
    
    lines.append('<Project DefaultTargets="Build" xmlns="http://schemas.microsoft.com/developer/msbuild/2003" ToolsVersion="4.0">')
    lines.append('  <PropertyGroup>')
    lines.append('    <Configuration Condition="\'$(Configuration)\'==\'\'">Debug</Configuration>')
    lines.append('    <SchemaVersion>2.0</SchemaVersion>')
    lines.append(f'    <ProjectGuid>{str(project.guid)}</ProjectGuid>')
    lines.append('    <ProjectHome>.</ProjectHome>')
    for input in project.get_aggregate_inputs():
        if "main.py" in input:
            input_absolute_path = gn.system_path(bcs_root_dir, input)
            solution_absolute_path = os.path.join(bcs_root_dir, project_filepath)
            solution_absolute_directory = os.path.dirname(solution_absolute_path)
            input_relative_path = os.path.relpath(input_absolute_path, solution_absolute_directory)
            lines.append(f'    <StartupFile>{html.escape(input_relative_path)}</StartupFile>')
            break
    lines.append("    <WorkingDirectory>$(SolutionDir)windows-$(Configuration.tolower())-x64\\bin\\</WorkingDirectory>")
    lines.append('    <OutputPath>.</OutputPath>')
    lines.append('    <Name>Mandrill Python</Name>')
    lines.append('    <RootNamespace>MandrillPython</RootNamespace>')
    lines.append('    <LaunchProvider>Standard Python launcher</LaunchProvider>')
    lines.append('    <EnableNativeCodeDebugging>True</EnableNativeCodeDebugging>')
    lines.append('    <DebugSymbols>true</DebugSymbols>')
    lines.append('    <EnableUnmanagedDebugging>true</EnableUnmanagedDebugging>')
    lines.append('  </PropertyGroup>')
    lines.append(f'  <!-- Python Sources -->')
    lines.append(f'  <ItemGroup>')

    for input in project.get_aggregate_inputs():
        input_absolute_path = gn.system_path(bcs_root_dir, input)
        solution_absolute_path = os.path.join(bcs_root_dir, project_filepath)
        solution_absolute_directory = os.path.dirname(solution_absolute_path)
        input_relative_path = os.path.relpath(input_absolute_path, solution_absolute_directory)
        lines.append(f'    <Compile Include="{html.escape(input_relative_path)}" />')
    lines.append(f'  </ItemGroup>')
    #lines.append(f'  <Import Project="{custom_python_tools_targets}" />')
    lines.append(f'  <Import Project="$(MSBuildExtensionsPath32)\\Microsoft\\VisualStudio\\v$(VisualStudioVersion)\\Python Tools\\Microsoft.PythonTools.targets" />')
    lines.append('  <Target Name="CoreCompile" />')
    lines.append('</Project>')
    
    os.makedirs(os.path.dirname(project_filepath), exist_ok=True)
    if write_file_if_changed(project_filepath, lines):
        print(project_filepath, "changed")

def write_cpp_project(solution : Solution, project : Project):
    lines = []

    project_filepath = project.get_project_filepath()

    lines.append(f'<?xml version="1.0" encoding="utf-8"?>')
    lines.append(f'<Project DefaultTargets="Build" ToolsVersion="17.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">')
    lines.append(f'  <ItemGroup Label="ProjectConfigurations">')
    for osplatformconfig in solution.osplatformconfigs:
        osplatformconfig : OSPlatformConfiguration
        lines.append(f'    <ProjectConfiguration Include="{osplatformconfig.vs_triplet}">')
        lines.append(f'      <Configuration>{osplatformconfig.vs_configuration}</Configuration>')
        lines.append(f'      <Platform>{osplatformconfig.vs_platform}</Platform>')
        lines.append(f'    </ProjectConfiguration>')
    lines.append(f'  </ItemGroup>')
    lines.append(f'  <PropertyGroup Label="Globals">')
    lines.append(f'    <ProjectGuid>{{{str(project.guid).upper()}}}</ProjectGuid>')
    lines.append(f'    <Keyword>Win32Proj</Keyword>')
    lines.append(f'    <RootNamespace>{project.namespace}</RootNamespace>')
    lines.append(f'    <IgnoreWarnCompileDuplicatedFilename>true</IgnoreWarnCompileDuplicatedFilename>')
    lines.append(f'    <PreferredToolArchitecture>x64</PreferredToolArchitecture>')
    lines.append(f'    <WindowsTargetPlatformVersion>10</WindowsTargetPlatformVersion>')
    lines.append(f'  </PropertyGroup>')
    lines.append(f'  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.Default.props" />')
    lines.append(f'  <PropertyGroup Label="Configuration">')
    lines.append(f'    <CharacterSet>Unicode</CharacterSet>')
    lines.append(f'    <ConfigurationType>Application</ConfigurationType>')
    lines.append(f'  </PropertyGroup>')
    lines.append(f'  <PropertyGroup Label="Locals"> ')
    lines.append(f'    <PlatformToolset>v143</PlatformToolset>')
    lines.append(f'  </PropertyGroup>')
    lines.append(f'  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.props" />')
    lines.append(f'  <Import Project="$(VCTargetsPath)\BuildCustomizations\masm.props" />')
    lines.append(f'  <ImportGroup Label="ExtensionSettings" />')
    lines.append(f'  <ImportGroup Label="PropertySheets">')
    lines.append(f'    <Import Condition="exists(\'$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props\')" Label="LocalAppDataPlatform" Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" />')
    lines.append(f'  </ImportGroup>')
    lines.append(f'  <PropertyGroup Label="UserMacros" />')
    lines.append(f'  <PropertyGroup>')
    #lines.append(f'    <OutDir>$(SolutionDir)</OutDir>')
    lines.append(f'    <OutDir>$(SolutionDir)$(Platform.split(" ")[0].toLower())-$(Configuration.ToLower())-$(Platform.split(" ")[1].toLower())\</OutDir>')
    lines.append(f'    <TargetName>$(ProjectName)</TargetName>')
    lines.append(f'  </PropertyGroup>')

    for description_and_osplatformconfig in project.descriptions:
        osplatformconfig = description_and_osplatformconfig.osplatformconfig
        description = description_and_osplatformconfig.description
        target = description.target
        if len(description.outputs):
            #for output in description.outputs:
            output = description.outputs[0]

            lines.append(f'  <PropertyGroup Condition="\'$(Configuration)|$(Platform)\'==\'{osplatformconfig.vs_triplet}\'">')
            lines.append(f'    <TargetPath>$(OutDir)/{os.path.relpath(output, osplatformconfig.output_root)}</TargetPath>')
            lines.append(f'  </PropertyGroup>')

    #lines.append(f'    <TargetPath>$(OutDir)/bin/bcs_executable.wasm</TargetPath>')
    for description_and_osplatformconfig in project.descriptions:
        osplatformconfig = description_and_osplatformconfig.osplatformconfig
        description = description_and_osplatformconfig.description
        target = description.target
        lines.append(f'  <ItemDefinitionGroup Condition="\'$(Configuration)|$(Platform)\'==\'{osplatformconfig.vs_triplet}\'">')
        lines.append(f'    <ClCompile>')
        lines.append(f'      <AdditionalIncludeDirectories>{repr(";".join(description.include_dirs))[1:-1]}</AdditionalIncludeDirectories>')
        lines.append(f'      <AdditionalOptions>{repr(" ".join(description.cflags + description.cflags_c + description.cflags_cc))[1:-1]}</AdditionalOptions>')
        lines.append(f'      <CompileAsWinRT>false</CompileAsWinRT>')
        lines.append(f'      <DebugInformationFormat>ProgramDatabase</DebugInformationFormat>')
        lines.append(f'      <PrecompiledHeader>NotUsing</PrecompiledHeader>')
        lines.append(f'      <PreprocessorDefinitions>{repr(";".join(description.defines))[1:-1]}</PreprocessorDefinitions>')
        lines.append(f'    </ClCompile>')
        lines.append(f'    <Link />')
        lines.append(f'  </ItemDefinitionGroup>')
        lines.append(f'  <!-- {osplatformconfig.vs_triplet} Sources -->')
        lines.append(f'  <ItemGroup Condition="\'$(Configuration)|$(Platform)\'==\'{osplatformconfig.vs_triplet}\'">')
        for source in description.sources:
            source_absolute_path = gn.system_path(bcs_root_dir, source)
            solution_absolute_path = os.path.join(bcs_root_dir, project_filepath)
            solution_absolute_directory = os.path.dirname(solution_absolute_path)
            source_relative_path = os.path.relpath(source_absolute_path, solution_absolute_directory)
            lines.append(f'    <None Include="{html.escape(source_relative_path)}" />')
            #lines.append(f'    <CustomBuild Include="../../../bcs/bcs_executable.cpp">')
            #lines.append(f'      <Command>call "{ninja_path}" -C $(OutDir)  obj/bcs_executable.bcs_executable.o</Command>')
            #lines.append(f'      <Outputs>$(OutDir)obj/bcs_executable.bcs_executable.o</Outputs>')
            #lines.append(f'    </CustomBuild>')
        lines.append(f'  </ItemGroup>')
    #lines.append(f'  <!-- Aggregate Sources -->')
    #lines.append(f'  <ItemGroup>')
    #for source in project.get_aggregate_sources():
    #    source_absolute_path = gn.system_path(bcs_root_dir, source)
    #    solution_absolute_path = os.path.join(bcs_root_dir, project_filepath);
    #    solution_absolute_directory = os.path.dirname(solution_absolute_path)
    #    source_relative_path = os.path.relpath(source_absolute_path, solution_absolute_directory)
    #    lines.append(f'    <None Include="{html.escape(source_relative_path)}" />')
    #lines.append(f'  </ItemGroup>')
    lines.append(f'  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.targets" />')
    lines.append(f'  <Import Project="$(VCTargetsPath)\BuildCustomizations\masm.targets" />')
    lines.append(f'  <ImportGroup Label="ExtensionTargets" />')

    lines.append(f'  <Target Name="Build">')
    for description_and_osplatformconfig in project.descriptions:
        osplatformconfig = description_and_osplatformconfig.osplatformconfig
        description = description_and_osplatformconfig.description
        target = description.target
        if len(description.outputs) or target.target == "*":
            build_command = f'call "{ninja_path}" -C "$(OutDir)\\"'
            for output in description.outputs:
                build_command += f' "{os.path.relpath(output, osplatformconfig.output_root)}"'
            lines.append(f'    <Exec Command="{html.escape(build_command)}"  Condition="\'$(Configuration)|$(Platform)\'==\'{osplatformconfig.vs_triplet}\'" />')
    lines.append(f'  </Target>')

    lines.append(f'  <Target Name="Clean">')
    for description_and_osplatformconfig in project.descriptions:
        osplatformconfig = description_and_osplatformconfig.osplatformconfig
        description = description_and_osplatformconfig.description
        target = description.target
        if len(description.outputs) or target.target == "*":
            clean_command = f'call "{ninja_path}" -C "$(OutDir)\\" -tclean'
            for output in description.outputs:
                clean_command += f' "{os.path.relpath(output, osplatformconfig.output_root)}"'
            lines.append(f'    <Exec Command="{html.escape(clean_command)}"  Condition="\'$(Configuration)|$(Platform)\'==\'{osplatformconfig.vs_triplet}\'" />')
    lines.append(f'  </Target>')

    #for description_and_osplatformconfig in project.descriptions:
    #    osplatformconfig = description_and_osplatformconfig.osplatformconfig
    #    description = description_and_osplatformconfig.description
    #    target = description.target
    #    if len(description.outputs):
    #        lines.append(f'  <Target Name="Build" Condition="\'$(Configuration)|$(Platform)\'==\'{osplatformconfig.vs_triplet}\'">')
    #        build_command = f'call "{ninja_path}" -C "$(OutDir)"'
    #        for output in description.outputs:
    #            build_command += f' "{os.path.relpath(output, osplatformconfig.output_root)}"'
    #        lines.append(f'    <Exec Command="{html.escape(build_command)}" />')
    #        lines.append(f'  </Target>')
    #        lines.append(f'  <Target Name="Clean" Condition="\'$(Configuration)|$(Platform)\'==\'{osplatformconfig.vs_triplet}\'">')
    #        clean_command = f'call "{ninja_path}" -C "$(OutDir)"'
    #        for output in description.outputs:
    #            clean_command += f' "{os.path.relpath(output, osplatformconfig.output_root)}"'
    #        lines.append(f'    <Exec Command="{html.escape(clean_command)}" />')
    #        lines.append(f'  </Target>')
    lines.append(f'</Project>')

    project_filepath = project.get_project_filepath()
    os.makedirs(os.path.dirname(project_filepath), exist_ok=True)
    if write_file_if_changed(project_filepath, lines):
        print(project_filepath, "changed")

def write_project(solution : Solution, project : Project):
        project_type = project.get_project_type()
        if project_type == "python_library":
            write_python_project(solution, project)
        else:
            write_cpp_project(solution, project)
