import uuid
import re
import gn
import html
import os
from util import pretty_print_dict

bcs_root_dir = os.environ['BCS_ROOT']
env_gn_dir = os.environ['GN_DIR']
gn_path = os.path.join(env_gn_dir, "gn")
env_ninja_dir = os.environ['NINJA_DIR']
ninja_path = os.path.join(env_ninja_dir, "ninja")

class OSPlatformConfiguration:
    os : str = None
    config : str = None
    cpu : str = None
    fs_triplet : str = None
    vs_platform : str = None
    vs_configuration : str = None
    vs_triplet : str = None
    output_root : str = None

    def __init__(self, os, platform, cpu, fs_triplet, vs_platform, vs_configuration, output_root):
        self.os = os
        self.platform = platform
        self.cpu = cpu
        #self.fs_triplet = f'{self.os}-{self.platform}-{self.cpu}'
        self.fs_triplet = fs_triplet
        self.vs_platform = vs_platform
        self.vs_configuration = vs_configuration
        self.vs_triplet = f'{self.vs_platform}|{self.vs_configuration}'
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
    filepath : str = None

    def __init__(self, name, filepath):
        self.name = name
        self.filepath = filepath

        self.namespace = string = re.sub(r'[^0-9a-zA-Z]+', '', name)

        from hashlib import md5
        digest = md5(bytes(name, "utf-8"), usedforsecurity=False).digest()
        self.guid = uuid.UUID(bytes=digest[:16], version=3)

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
        return sources

    def get_project_guid(self):
        return str(self.guid).upper()

    def get_project_type(self):
        if len(self.descriptions):
            custom_target_type = self.descriptions[0].description.custom_target_type
            return custom_target_type
        return None

    def get_project_type_guid(self):
        cpp_type_guid = "8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942"
        python_type_guid = "888888A0-9F3D-457C-B088-3A5042F75D52"
        
        project_type = self.get_project_type()
        if project_type == "python_project":
            return python_type_guid

        return cpp_type_guid
    
class Folder:
    name : str = None
    namespace : str = None
    folders : list = []
    projects : list[Project] = []
    filepath : str = None

    def __init__(self, name):
        name : str
        self.name = name
        self.namespace = string = re.sub(r'[^0-9a-zA-Z]+', '', name)

    def __repr__(self):
        return pretty_print_dict(self.__dict__)

class Solution(Folder):
    osplatformconfigs : list[OSPlatformConfiguration] = []
    projects : list[Project] = []

    def __init__(self, name, filepath):
        super().__init__(name)
        self.filepath = filepath

    def __repr__(self):
        object = {
            "name": self.name,
            "folders": self.folders,
            "projects": self.projects,
        }
        return pretty_print_dict(object)

def write_solution(output_directory: str, solution : Solution):
    output_directory : str
    lines = []

    lines.append(f'Microsoft Visual Studio Solution File, Format Version 12.00\n')
    lines.append(f'# Visual Studio Version 17\n')
    lines.append(f'VisualStudioVersion = 17.4.33205.214\n')
    lines.append(f'MinimumVisualStudioVersion = 10.0.40219.1\n')
    for project in solution.projects:
        type_guid = project.get_project_type_guid()
        project_guid = project.get_project_guid()
        lines.append(f'Project("{{{type_guid}}}") = "testproject", "testproject.vcxproj", "{{{project_guid}}}"\n')
    lines.append(f'EndProject\n')
    lines.append(f'Global\n')
    lines.append(f'\tGlobalSection(SolutionConfigurationPlatforms) = preSolution\n')
    lines.append(f'\t\tRelease|Windows x86 = Release|Windows x86\n')
    lines.append(f'\tEndGlobalSection\n')
    lines.append(f'\tGlobalSection(ProjectConfigurationPlatforms) = postSolution\n')
    for project in solution.projects:
        project_guid = project.get_project_guid()
        type = project.get_project_type()
        if type == "python_project":
            lines.append(f'\t\t{{{project_guid}}}.Release|Windows x86.ActiveCfg = Release|Windows x86\n')
            lines.append(f'\t\t{{{project_guid}}}.Release|Windows x86.Build.0 = Release|Windows x86\n')
        else:
            lines.append(f'\t\t{{{project_guid}}}.Release|Windows x86.ActiveCfg = Release|Windows x86\n')
            lines.append(f'\t\t{{{project_guid}}}.Release|Windows x86.Build.0 = Release|Windows x86\n')
    lines.append(f'\tEndGlobalSection\n')
    lines.append(f'\tGlobalSection(SolutionProperties) = preSolution\n')
    lines.append(f'\t\tHideSolutionNode = FALSE\n')
    lines.append(f'\tEndGlobalSection\n')
    lines.append(f'\tGlobalSection(ExtensibilityGlobals) = postSolution\n')
    lines.append('\t\tSolutionGuid = {EC5AA000-0A54-4352-965F-7033B55E412D}\n')
    lines.append(f'\tEndGlobalSection\n')
    lines.append(f'EndGlobal\n')

    with open(solution.filepath, "w") as project_file:
        project_file.write("\n".join(lines))

def write_project(solution : Solution, project : Project, ninja_path : str):
    lines = []

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
    lines.append(f'    <OutDir>$(SolutionDir)</OutDir>')
    lines.append(f'    <TargetName>$(ProjectName)</TargetName>')
    lines.append(f'    <TargetPath>$(OutDir)/bin/bcs_executable.wasm</TargetPath>')
    lines.append(f'  </PropertyGroup>')
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
            solution_absolute_path = os.path.join(bcs_root_dir, project.filepath);
            solution_absolute_directory = os.path.dirname(solution_absolute_path)
            source_relative_path = os.path.relpath(source_absolute_path, solution_absolute_directory)
            lines.append(f'    <None Include="{html.escape(source_relative_path)}" />')
            #lines.append(f'    <CustomBuild Include="../../../bcs/bcs_executable.cpp">')
            #lines.append(f'      <Command>call "{ninja_path}" -C $(OutDir)  obj/bcs_executable.bcs_executable.o</Command>')
            #lines.append(f'      <Outputs>$(OutDir)obj/bcs_executable.bcs_executable.o</Outputs>')
            #lines.append(f'    </CustomBuild>')
        lines.append(f'  </ItemGroup>')
    lines.append(f'  <!-- Aggregate Sources -->')
    lines.append(f'  <ItemGroup>')
    for source in project.get_aggregate_sources():
        source_absolute_path = gn.system_path(bcs_root_dir, source)
        solution_absolute_path = os.path.join(bcs_root_dir, project.filepath);
        solution_absolute_directory = os.path.dirname(solution_absolute_path)
        source_relative_path = os.path.relpath(source_absolute_path, solution_absolute_directory)
        lines.append(f'    <None Include="{html.escape(source_relative_path)}" />')
    lines.append(f'  </ItemGroup>')
    lines.append(f'  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.targets" />')
    lines.append(f'  <Import Project="$(VCTargetsPath)\BuildCustomizations\masm.targets" />')
    lines.append(f'  <ImportGroup Label="ExtensionTargets" />')
    for description_and_osplatformconfig in project.descriptions:
        osplatformconfig = description_and_osplatformconfig.osplatformconfig
        description = description_and_osplatformconfig.description
        target = description.target
        if len(description.outputs):
            lines.append(f'  <Target Name="Build" Condition="\'$(Configuration)|$(Platform)\'==\'{osplatformconfig.vs_triplet}\'">')
            build_command = f'call "{ninja_path}" -C "$(OutDir)"'
            for output in description.outputs:
                build_command += f' "{os.path.relpath(output, osplatformconfig.output_root)}"'
            lines.append(f'    <Exec Command="{html.escape(build_command)}" />')
            lines.append(f'  </Target>')
            lines.append(f'  <Target Name="Clean" Condition="\'$(Configuration)|$(Platform)\'==\'{osplatformconfig.vs_triplet}\'">')
            clean_command = f'call "{ninja_path}" -C "$(OutDir)"'
            for output in description.outputs:
                clean_command += f' "{os.path.relpath(output, osplatformconfig.output_root)}"'
            lines.append(f'    <Exec Command="{html.escape(clean_command)}" />')
            lines.append(f'  </Target>')
    lines.append(f'</Project>')

    with open(project.filepath, "w") as project_file:
        project_file.write("\n".join(lines))

