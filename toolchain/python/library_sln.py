import uuid
import re
import html
import os
import library_gn as gn
import library_util as util
from library_util import pretty_print_dict
from library_util import timer_func
from hashlib import md5

class TargetSettings:
    target_os : str = None
    target_config : str = None
    target_link_config : str = None
    target_profile_config : bool = None
    target_cpu : str = None
    fs_triplet : str = None
    vs_platform : str = None
    vs_configuration : str = None
    vs_link_configuration : str = None
    gn_output_root : str = None

    def __init__(self, target_os, target_config, target_link_config, target_profile_config, target_cpu, vs_platform, vs_configuration, vs_link_configuration, gn_solution_dir):
        self.target_os = target_os
        self.target_config = target_config
        self.target_link_config = target_link_config
        self.target_profile_config = target_profile_config
        self.target_cpu = target_cpu
        self.fs_triplet = f'{target_os}-{target_config}-{target_cpu}-{target_link_config}'
        if self.target_profile_config:
            self.fs_triplet += "-profile"
        self.vs_platform = vs_platform
        self.vs_configuration = vs_configuration
        self.vs_link_configuration = vs_link_configuration
        self.gn_output_root = os.path.join(gn_solution_dir, self.fs_triplet)

class OSPlatformConfiguration:
    target_os : str = None
    target_config : str = None
    target_cpu : str = None
    fs_triplet : str = None
    vs_platform : str = None
    vs_configuration : str = None
    vs_link_configuration : str = None
    vs_triplet : str = None
    output_root : str = None

    def __init__(self, target_os, target_config, target_cpu, fs_triplet, vs_platform, vs_configuration, vs_link_configuration, output_root):
        self.target_os = target_os
        self.target_config = target_config
        self.target_cpu = target_cpu
        #self.fs_triplet = f'{self.os}-{self.platform}-{self.cpu}'
        self.fs_triplet = fs_triplet
        self.vs_platform = vs_platform
        self.vs_configuration = vs_configuration
        self.vs_link_configuration = vs_link_configuration
        self.vs_triplet = f'{self.vs_configuration}|{self.vs_platform} {self.vs_link_configuration}'
        self.output_root = output_root

    def __repr__(self):
        return pretty_print_dict(self.__dict__)
    
    def __eq__(self, other):
        if isinstance(other, OSPlatformConfiguration):
            other : OSPlatformConfiguration
            return self.target_os == other.target_os and \
                self.target_config == other.target_config and \
                self.target_cpu == other.target_cpu and \
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

    def get_project_filters_filepath(self):
        return self.get_project_filepath() + ".filters"
    
    def get_description(self, osplatformconfig):
        for description in self.descriptions:
            if description.osplatformconfig == osplatformconfig:
                return description.description
            
    def is_hidden(self):
        for description in self.descriptions:
            return description.description.hidden
        return False
            
    def is_nobuild(self):
        for description in self.descriptions:
            return description.description.nobuild
        return False
    
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

    def get_project_by_name(self, target_name):
        for project in self.projects:
            if project.name == target_name:
                return project
            
    def get_project_by_target(self, target):
        for project in self.projects:
            if project.descriptions[0].description.target.target == target:
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
        write_all_deps = project.get_project_type() == "python_library"
        if write_all_build == is_all_build:
            project_filepath = project.get_project_filepath()
            type_guid = project.get_type_guid()
            guid = project.get_guid()

            #print(project.name, len(project.descriptions))
            lines.append(f'Project("{{{type_guid}}}") = "{project.descriptions[0].description.target.name}", "{os.path.basename(project_filepath)}", "{{{guid}}}"')
            if write_all_deps:
                for dependency in project.descriptions[0].description.deps:
                    #print(project.descriptions[0].description.deps)
                    dependency_project = solution.get_project_by_target(dependency)
                    guid = dependency_project.get_guid()
                    lines.append(f'\tProjectSection(ProjectDependencies) = postProject')
                    lines.append(f'\t\t{{{guid}}} = {{{guid}}}')
                    lines.append(f'\tEndProjectSection')
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

    solution_filepath = os.path.join(util.bcs_root_dir, solution.filepath)
    os.makedirs(os.path.dirname(solution_filepath), exist_ok=True)
    if util.write_file_if_changed(solution_filepath, lines):
        print(solution_filepath, "changed")

def write_python_project_file(lines : list[str], project : Project, file : str):
    project_filepath = project.get_project_filepath()
    file_absolute_path = gn.system_path(util.bcs_root_dir, file)
    solution_absolute_path = os.path.join(util.bcs_root_dir, project_filepath)
    solution_absolute_directory = os.path.dirname(solution_absolute_path)
    file_relative_path = os.path.relpath(file_absolute_path, solution_absolute_directory)
    file_relative_path_split = os.path.splitext(file_relative_path)
    file_extension = "" if len(file_relative_path_split) <= 1 else file_relative_path_split[1]
    source_extensions = [ ".py" ]
    #ninja_extensions = [ ".gn" ]

    if file_extension in source_extensions:
        lines.append(f'    <Compile Include="{html.escape(file_relative_path)}" />')
    else:
        lines.append(f'    <None Include="{html.escape(file_relative_path)}" />')

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
            input_absolute_path = gn.system_path(util.bcs_root_dir, input)
            solution_absolute_path = os.path.join(util.bcs_root_dir, project_filepath)
            solution_absolute_directory = os.path.dirname(solution_absolute_path)
            input_relative_path = os.path.relpath(input_absolute_path, solution_absolute_directory)
            lines.append(f'    <StartupFile>{html.escape(input_relative_path)}</StartupFile>')
            break
    lines.append("    <WorkingDirectory>$(SolutionDir)windows-$(Configuration.tolower())-x64-shared\\bin\\</WorkingDirectory>")
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

    for file in project.get_aggregate_inputs():
        write_python_project_file(lines, project, file)
    for file in project.descriptions[0].description.target.buildfiles:
        write_project_file(lines, project, file)
    if project.descriptions[0].description.script:
        write_project_file(lines, project, project.descriptions[0].description.script)
    lines.append(f'  </ItemGroup>')
    lines.append(f'  <Import Project="$(MSBuildExtensionsPath32)\\Microsoft\\VisualStudio\\v$(VisualStudioVersion)\\Python Tools\\Microsoft.PythonTools.targets" />')
    lines.append('  <Target Name="CoreCompile" />')
    lines.append('</Project>')
    
    project_filepath = os.path.join(util.bcs_root_dir, project_filepath)
    os.makedirs(os.path.dirname(project_filepath), exist_ok=True)
    if util.write_file_if_changed(project_filepath, lines):
        print(project_filepath, "changed")

def write_project_file(lines : list[str], project : Project, file : str):
    project_filepath = project.get_project_filepath()
    file_absolute_path = gn.system_path(util.bcs_root_dir, file)
    solution_absolute_path = os.path.join(util.bcs_root_dir, project_filepath)
    solution_absolute_directory = os.path.dirname(solution_absolute_path)
    file_relative_path = os.path.relpath(file_absolute_path, solution_absolute_directory)
    file_relative_path_split = os.path.splitext(file_relative_path)
    file_extension = "" if len(file_relative_path_split) <= 1 else file_relative_path_split[1]
    header_extensions = [ ".h", ".hh" ]
    source_extensions = [ ".c", ".cc", ".cpp", ".cxx" ]

    if file_extension in header_extensions:
        lines.append(f'    <ClInclude Include="{html.escape(file_relative_path)}" />')
    elif file_extension in source_extensions:
        lines.append(f'    <ClCompile Include="{html.escape(file_relative_path)}" />')
    else:
        lines.append(f'    <None Include="{html.escape(file_relative_path)}" />')

def write_cpp_project(solution : Solution, project : Project):
    lines = list[str]()

    lines.append(f'<?xml version="1.0" encoding="utf-8"?>')
    lines.append(f'<Project DefaultTargets="Build" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">')
    lines.append(f'  <ItemGroup Label="ProjectConfigurations">')
    for osplatformconfig in solution.osplatformconfigs:
        osplatformconfig : OSPlatformConfiguration
        lines.append(f'    <ProjectConfiguration Include="{osplatformconfig.vs_triplet}">')
        lines.append(f'      <Configuration>{osplatformconfig.vs_configuration}</Configuration>')
        lines.append(f'      <Platform>{osplatformconfig.vs_platform} {osplatformconfig.vs_link_configuration}</Platform>')
        lines.append(f'    </ProjectConfiguration>')
    lines.append(f'  </ItemGroup>')
    lines.append(f'  <PropertyGroup Label="Globals">')
    #lines.append(f'    <VCProjectVersion>17.0</VCProjectVersion>')
    lines.append(f'    <ProjectGuid>{{{str(project.guid).upper()}}}</ProjectGuid>')
    lines.append(f'    <Keyword>Win32Proj</Keyword>')
    lines.append(f'  </PropertyGroup>')
    lines.append(f'  <Import Project="Cpp.Default.props" />')
    lines.append(f'  <PropertyGroup Label="Configuration">')
    lines.append(f'    <CharacterSet>Unicode</CharacterSet>')
    lines.append(f'    <ConfigurationType>Makefile</ConfigurationType>')
    lines.append(f'    <PlatformToolset>v143</PlatformToolset>')
    lines.append(f'  </PropertyGroup>')
    lines.append(f'  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.props" />')
    lines.append(f'  <ImportGroup Label="ExtensionSettings" />')
    lines.append(f'  <ImportGroup Label="Shared" />')
    lines.append(f'  <ImportGroup Label="PropertySheets">')
    lines.append(f'    <Import Condition="exists(\'$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props\')" Label="LocalAppDataPlatform" Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" />')
    lines.append(f'  </ImportGroup>')
    lines.append(f'  <PropertyGroup Label="UserMacros" />')

    for osplatformconfig in solution.osplatformconfigs:
        osplatformconfig : OSPlatformConfiguration

        description = project.get_description(osplatformconfig)

        if description != None:

            output_file = ""
            if len(description.outputs):
                output_file = description.outputs[0]

            output_directory = gn.system_path(util.bcs_root_dir, osplatformconfig.output_root)
            ninja = util.get_ninja()
            build_command = f'"{ninja}" -winmutex Global\BlamCreationSuite -d explain -C "{output_directory}"'
            rebuild_command = f'"{ninja}" -winmutex Global\BlamCreationSuite -d explain -C "{output_directory}"'
            clean_command = f'"{ninja}" -winmutex Global\BlamCreationSuite -d explain -C "{output_directory}" -tclean'
            for output in description.outputs:
                build_command += f' "{os.path.relpath(output, osplatformconfig.output_root)}"'
                rebuild_command += f' "{os.path.relpath(output, osplatformconfig.output_root)}"'
                clean_command += f' "{os.path.relpath(output, osplatformconfig.output_root)}"'
            if project.name == "all_build":
                rebuild_command = ""

            if project.is_nobuild():
                build_command = "rem"
                rebuild_command = "rem"
                clean_command = "rem"
            elif len(project.descriptions[0].description.outputs) == 0 and project.name != "all_build":
                project_type = project.get_project_type()
                print(f"Warning: Project {project.name} of type {project_type} has no outputs but is marked for build")


            preprocessor_definitions = description.defines
            include_search_path = []
            forced_includes = []
            assembly_search_path = []
            forced_using_assemblies = []
            additional_options = [ "/std:c++20" ]
            include_path = [ description.target.directory ]
            external_include_path = description.include_dirs

            # deduplicate
            include_path = list(dict.fromkeys(include_path))
            external_include_path = list(dict.fromkeys(external_include_path))

            output_file = gn.system_path(util.bcs_root_dir, output_file)
            for i, include in enumerate(include_search_path):
                include_search_path[i] = gn.system_path(util.bcs_root_dir, include)
            for i, include in enumerate(include_path):
                include_path[i] = gn.system_path(util.bcs_root_dir, include)
            for i, include in enumerate(external_include_path):
                external_include_path[i] = gn.system_path(util.bcs_root_dir, include)
        else:
            output_file = ""
            build_command = "rem"
            rebuild_command = "rem"
            clean_command = "rem"
            preprocessor_definitions = []
            additional_options = []
            include_path = []
            external_include_path = []
        lines.append(f'  <PropertyGroup Condition="\'$(Configuration)|$(Platform)\'==\'{osplatformconfig.vs_triplet}\'">')
        lines.append(f'    <NMakeOutput>{output_file}</NMakeOutput>')
        lines.append(f'    <NMakePreprocessorDefinitions>{";".join(preprocessor_definitions + ["$(NMakePreprocessorDefinitions)"])}</NMakePreprocessorDefinitions>')
        lines.append(f'    <NMakeBuildCommandLine>{build_command}</NMakeBuildCommandLine>')
        lines.append(f'    <NMakeReBuildCommandLine>{rebuild_command}</NMakeReBuildCommandLine>')
        lines.append(f'    <NMakeCleanCommandLine>{clean_command}</NMakeCleanCommandLine>')
        #lines.append(f'    <NMakeIncludeSearchPath>{";".join(include_search_path + ["$(NMakeIncludeSearchPath)"])}</NMakeIncludeSearchPath>')
        #lines.append(f'    <NMakeForcedIncludes>{";".join(forced_includes + ["$(NMakeForcedIncludes)"])}</NMakeForcedIncludes>')
        #lines.append(f'    <NMakeAssemblySearchPath>{";".join(assembly_search_path + ["$(NMakeAssemblySearchPath)"])}</NMakeAssemblySearchPath>')
        #lines.append(f'    <NMakeForcedUsingAssemblies>{";".join(forced_using_assemblies + ["$(NMakeForcedUsingAssemblies)"])}</NMakeForcedUsingAssemblies>')
        lines.append(f'    <AdditionalOptions>{" ".join(additional_options)}</AdditionalOptions>')
        lines.append(f'    <IncludePath>{";".join(include_path)}</IncludePath>')
        lines.append(f'    <ExternalIncludePath>{";".join(external_include_path)}</ExternalIncludePath>')
        lines.append(f'  </PropertyGroup>')

    for description_and_osplatformconfig in project.descriptions:
        osplatformconfig = description_and_osplatformconfig.osplatformconfig
        description = description_and_osplatformconfig.description
        target = description.target
        lines.append(f'  <!-- {osplatformconfig.vs_triplet} Sources -->')
        lines.append(f'  <ItemGroup Condition="\'$(Configuration)|$(Platform)\'==\'{osplatformconfig.vs_triplet}\'">')
        for source in description.sources:
            write_project_file(lines, project, source)
        for input in description.inputs:
            if input.lower().endswith(('.natvis', '.py')):
                write_project_file(lines, project, input)
        write_project_file(lines, project, description.target.buildfile)
        if project.descriptions[0].description.script:
            write_project_file(lines, project, project.descriptions[0].description.script)
        lines.append(f'  </ItemGroup>')
    lines.append(f'  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.targets" />')
    lines.append(f'  <ImportGroup Label="ExtensionTargets" />')
    lines.append(f'</Project>')

    project_filepath = project.get_project_filepath()
    project_filepath = os.path.join(util.bcs_root_dir, project_filepath)
    os.makedirs(os.path.dirname(project_filepath), exist_ok=True)
    if util.write_file_if_changed(project_filepath, lines):
        print(project_filepath, "changed")


def write_project_filter_file(lines : list[str], project : Project, file : str):
    project_filepath = project.get_project_filepath()
    file_absolute_path = gn.system_path(util.bcs_root_dir, file)
    solution_absolute_path = os.path.join(util.bcs_root_dir, project_filepath)
    solution_absolute_directory = os.path.dirname(solution_absolute_path)
    file_relative_path = os.path.relpath(file_absolute_path, solution_absolute_directory)
    file_relative_path_split = os.path.splitext(file_relative_path)
    file_extension = "" if len(file_relative_path_split) <= 1 else file_relative_path_split[1]
    header_extensions = [ ".h", ".hh", ".hpp", ".hxx", ".h++", ".hm", ".inl", ".inc", ".ipp", ".xsd", ".hlsli" ]
    source_extensions = [ ".cpp", ".c", ".cc", ".cxx", ".c++", ".cppm", ".ixx", ".def", ".odl", ".idl", ".hpj", ".bat", ".asm", ".asmx", ".hlsl" ]
    #ninja_extensions = [ ".gn" ]

    if file_extension in header_extensions:
        lines.append(f'    <ClInclude Include="{html.escape(file_relative_path)}">')
        lines.append('      <Filter>Header Files</Filter>')
        lines.append('    </ClInclude>')
    elif file_extension in source_extensions:
        lines.append(f'    <ClCompile Include="{html.escape(file_relative_path)}">')
        lines.append('      <Filter>Source Files</Filter>')
        lines.append('    </ClCompile>')
    #elif file_extension in ninja_extensions:
    #    lines.append(f'    <None Include="{html.escape(file_relative_path)}">')
    #    lines.append('      <Filter>GN Files</Filter>')
    #    lines.append('    </None>')
    else:
        pass

def write_cpp_project_filters(solution : Solution, project : Project):
    lines = []
    lines.append('<?xml version="1.0" encoding="utf-8"?>')
    lines.append('<Project ToolsVersion="4.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">')
    lines.append('  <ItemGroup>')
    lines.append('    <Filter Include="Source Files">')
    lines.append('      <UniqueIdentifier>{4FC737F1-C7A5-4376-A066-2A32D752A2FF}</UniqueIdentifier>')
    lines.append('      <Extensions>cpp;c;cc;cxx;c++;cppm;ixx;def;odl;idl;hpj;bat;asm;asmx;hlsl</Extensions>')
    lines.append('    </Filter>')
    lines.append('    <Filter Include="Header Files">')
    lines.append('      <UniqueIdentifier>{93995380-89BD-4b04-88EB-625FBE52EBFB}</UniqueIdentifier>')
    lines.append('      <Extensions>h;hh;hpp;hxx;h++;hm;inl;inc;ipp;xsd;hlsli</Extensions>')
    lines.append('    </Filter>')
    #lines.append('    <Filter Include="Resource Files">')
    #lines.append('      <UniqueIdentifier>{67DA6AB6-F800-4c08-8B7A-83BB121AAD01}</UniqueIdentifier>')
    #lines.append('      <Extensions>rc;ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe;resx;tiff;tif;png;wav;mfcribbon-ms</Extensions>')
    #lines.append('    </Filter>')
    #lines.append('    <Filter Include="GN Files">')
    #lines.append('      <UniqueIdentifier>{72BEE122-9B76-43F4-8B36-6A559410D4A4}</UniqueIdentifier>')
    #lines.append('      <Extensions>gn</Extensions>')
    #lines.append('    </Filter>')
    lines.append('  </ItemGroup>')
    for description_and_osplatformconfig in project.descriptions:
        osplatformconfig = description_and_osplatformconfig.osplatformconfig
        description = description_and_osplatformconfig.description
        lines.append(f'  <!-- {osplatformconfig.vs_triplet} Sources -->')
        lines.append(f'  <ItemGroup Condition="\'$(Configuration)|$(Platform)\'==\'{osplatformconfig.vs_triplet}\'">')
        for source in description.sources:
            write_project_filter_file(lines, project, source)
        write_project_filter_file(lines, project, description.target.buildfile)
        lines.append(f'  </ItemGroup>')
    lines.append('</Project>')

    project_filters_filepath = project.get_project_filters_filepath()
    project_filters_filepath = os.path.join(util.bcs_root_dir, project_filters_filepath)
    os.makedirs(os.path.dirname(project_filters_filepath), exist_ok=True)
    if util.write_file_if_changed(project_filters_filepath, lines):
        print(project_filters_filepath, "changed")

def write_project(solution : Solution, project : Project):
        project_type = project.get_project_type()
        if project_type == "python_library":
            write_python_project(solution, project)
        else:
            write_cpp_project(solution, project)
            write_cpp_project_filters(solution, project)
