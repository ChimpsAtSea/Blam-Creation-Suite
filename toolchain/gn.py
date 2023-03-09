import os
import sys
import subprocess
import json
import asyncio
import inspect
import pathlib
import util
from util import pretty_print_dict
from util import timer_func

class Target:
    directory : str = None
    buildfile : str = None
    buildfiles : list[str] = None
    name : str = None
    target : str = None
    userdata = None

    def __init__(self, target, userdata):
        self.userdata = userdata
        self.target = target

        self.buildfiles = []

        if target == "*":
            self.directory = "//"
            self.name = "all_build"
            
            self.buildfiles.append("//.gn")
            self.buildfiles.append("//setup.bat")

        else:
            # Split the string by the ':' character
            parts = target.split(':')

            self.directory = parts[0]

            # Strip any leading or trailing whitespace from the name
            self.name = parts[1]
            self.name = self.name.strip()

        # Get the buildfile and name by slicing the parts list
        self.buildfile = "/".join([self.directory, "BUILD.gn"])
        if self.buildfile.startswith("///"):
            self.buildfile = self.buildfile[1:]

        self.buildfiles.append(self.buildfile)

    def __repr__(self):
        return pretty_print_dict(self.__dict__)

class Description:
    target : Target = None
    allow_circular_includes_from : list[str] = []
    cflags : list[str] = []
    cflags_c : list[str] = []
    cflags_cc : list[str] = []
    check_includes : bool = True
    configs : list[str] = []
    defines : list[str] = []
    deps : list[str] = []
    externs : list[str] = []
    include_dirs : list[str] = []
    framework_dirs : list[str] = []
    inputs : list[str] = []
    ldflags : list[str] = []
    lib_dirs : list[str] = []
    libs : list[str] = []
    metadata : list[str] = {}
    outputs : list[str] = []
    public : str = "*"
    public_configs : list[str] = []
    sources : list[str] = []
    testonly : bool = False
    toolchain : str = []
    type : str = "static_library"
    visibility : str = "*"
    userdata = None
    args : list[str] = []
    script : str = ""

    # Metadata
    custom_target_type : str = ""
    project_folder : list[str] = []
    hidden : bool = False

    def _pop_variable(self, data, name, default):
        if name in data:
            new = data[name]
            del data[name]
            return new
        else:
            return default

    def __init__(self, target, data, userdata):
        target : str

        self.target = target
        self.userdata = userdata

        self.allow_circular_includes_from = self._pop_variable(data, 'allow_circular_includes_from', self.allow_circular_includes_from)
        self.cflags = self._pop_variable(data, 'cflags', self.cflags)
        self.cflags_c = self._pop_variable(data, 'cflags_c', self.cflags_c)
        self.cflags_cc = self._pop_variable(data, 'cflags_cc', self.cflags_cc)
        self.check_includes = self._pop_variable(data, 'check_includes', self.check_includes)
        self.configs = self._pop_variable(data, 'configs', self.configs)
        self.defines = self._pop_variable(data, 'defines', self.defines)
        self.deps = self._pop_variable(data, 'deps', self.deps)
        self.externs = self._pop_variable(data, 'externs', self.externs)
        self.include_dirs = self._pop_variable(data, 'include_dirs', self.include_dirs)
        self.framework_dirs = self._pop_variable(data, 'framework_dirs', self.framework_dirs)
        self.inputs = self._pop_variable(data, 'inputs', self.inputs)
        self.ldflags = self._pop_variable(data, 'ldflags', self.ldflags)
        self.lib_dirs = self._pop_variable(data, 'lib_dirs', self.lib_dirs)
        self.libs = self._pop_variable(data, 'libs', self.libs)
        self.metadata = self._pop_variable(data, 'metadata', self.metadata)
        self.outputs = self._pop_variable(data, 'outputs', self.outputs)
        self.public = self._pop_variable(data, 'public', self.public)
        self.public_configs = self._pop_variable(data, 'public_configs', self.public_configs)
        self.sources = self._pop_variable(data, 'sources', self.sources)
        self.testonly = self._pop_variable(data, 'testonly', self.testonly)
        self.toolchain = self._pop_variable(data, 'toolchain', self.toolchain)
        self.type = self._pop_variable(data, 'type', self.type)
        self.visibility = self._pop_variable(data, 'visibility', self.visibility)
        self.args = self._pop_variable(data, 'args', self.args)
        self.script = self._pop_variable(data, 'script', self.script)


        if len(data):
            print("WARN: GN Description contains unparsed data")
            print(data)

        if 'custom_target_type' in self.metadata:
            custom_target_type_metadata_list = self.metadata['custom_target_type']
            if len(custom_target_type_metadata_list) == 1:
                self.custom_target_type = custom_target_type_metadata_list[0]
        else:
            self.custom_target_type = self.type

        if 'include_dirs' in self.metadata:
            self.include_dirs = self.metadata['include_dirs']

        if 'project_folder' in self.metadata:
            project_folder_metadata_list = self.metadata['project_folder']
            if len(project_folder_metadata_list) == 1:
                self.project_folder = list(filter(None, project_folder_metadata_list[0].split("/")))
        else:
            self.project_folder = list(filter(None, self.target.directory.split("/")))

        if 'hidden' in self.metadata:
            self.hidden = self.metadata['hidden'][0]

    def __repr__(self):
        return pretty_print_dict(self.__dict__)

def system_path(project_root : str, path : str):
    if path.startswith("//"):
        return os.path.join(project_root, path[2:])
    else:
        return path

def patch_build_configuration_files(target_os: str, target_config: str, target_link_config: str, target_cpu: str):
    target_directory = os.path.join(util.bcs_root_dir, f'solution/{target_os}-{target_config}-{target_cpu}-{target_link_config}')
    build_ninja_filepath = os.path.join(target_directory, "build.ninja")
    build_ninja_d_filepath = os.path.join(target_directory, "build.ninja.d")
    build_ninja_stamp_filepath = os.path.join(target_directory, "build.ninja.stamp")

    build_ninja_d_lines = list[str]()
    with open(build_ninja_d_filepath) as build_ninja_d_file:
        build_ninja_d_iterator = iter(build_ninja_d_file)
        for line in build_ninja_d_iterator:
            build_ninja_d_lines.append(line.rstrip())
    
    for index, line in enumerate(build_ninja_d_lines):
        [filename, args] = line.split(":", 1)
        if filename == "build.ninja.stamp":
            regenerate_command = f'{filename}:{args}'
    
            extra_watch_files = [ 
                "setup.bat", 
                "toolchain/generate_solution.py",
                "toolchain/gn.py",
                "toolchain/project_setup.py",
                "toolchain/regenerate_solution.py",
                "toolchain/sln.py",
                "toolchain/util.py",
                ]
        
            for extra_watch_file in extra_watch_files:
                extra_watch_file_relpath = os.path.relpath(os.path.join(util.bcs_root_dir, extra_watch_file), target_directory)
                extra_watch_file_relpath = extra_watch_file_relpath.replace('\\', '/')
                regenerate_command += f' {extra_watch_file_relpath}'
    
            build_ninja_d_lines[index] = regenerate_command
    
    with open(build_ninja_d_filepath, "w") as build_ninja_d_file:
        build_ninja_d_file.writelines("\n".join(build_ninja_d_lines))



    build_ninja_lines = list[str]()
    with open(build_ninja_filepath) as build_ninja_file:
        build_ninja_iterator = iter(build_ninja_file)
        for line in build_ninja_iterator:
            build_ninja_lines.append(line.rstrip())
        
    if len(build_ninja_lines) == 0 or "#BCS" not in build_ninja_lines[0]:

        build_ninja_lines.insert(0, "#BCS")

        build_ninja_iterator = iter(build_ninja_lines)
        skip_lines = 0
        for index, line in enumerate(build_ninja_lines):
            if skip_lines:
                skip_lines -= 1
                continue
            if "rule gn" in line:
                skip_lines = 1
                [command_name, command] = build_ninja_lines[index + 1].split(" = ", 1)
                if command_name != "  command":
                    raise Exception(f"Unexpected command name {command_name.strip()} expected 'command'")
                #build_ninja_lines[index + 1] = f'{command_name} = {command}'

                bcs_root_dir_arg = util.bcs_root_dir.rstrip("\\/")
                bcs_third_party_dir_arg = util.bcs_third_party_dir.rstrip("\\/")
                env_7z_dir_arg = util.bcs_7z_dir.rstrip("\\/")
                env_bcs_ewdk_dir_arg = util.bcs_ewdk_dir.rstrip("\\/")
                env_gn_dir_arg = util.bcs_gn_dir.rstrip("\\/")
                env_ninja_dir_arg = util.bcs_ninja_dir.rstrip("\\/")
                env_python_dir_arg = util.bcs_python_dir.rstrip("\\/")

                configuration_args = f'--target_os "{target_os}" --target_config "{target_config}" --target_link_config "{target_link_config}" --target_cpu "{target_cpu}"'
                environment_args = f'--bcs_root_dir "{bcs_root_dir_arg}" --bcs_third_party_dir "{bcs_third_party_dir_arg}" --bcs_7z_dir "{env_7z_dir_arg}" --bcs_ewdk_dir "{env_bcs_ewdk_dir_arg}" --bcs_gn_dir "{env_gn_dir_arg}" --bcs_ninja_dir "{env_ninja_dir_arg}" --bcs_python_dir "{env_python_dir_arg}"'
                build_ninja_lines[index + 1] = f'#{build_ninja_lines[index + 1]}\n{command_name} = "{util.get_python()}" "{os.path.join(util.bcs_root_dir, "toolchain/regenerate_solution.py")}" {configuration_args} {environment_args}'

    if util.write_file_if_changed(build_ninja_filepath, build_ninja_lines + [""]):
        #print(build_ninja_filepath, "changed")
        pass

    #pathlib.Path(build_ninja_filepath).touch()
    #pathlib.Path(build_ninja_d_filepath).touch()
    pathlib.Path(build_ninja_stamp_filepath).touch()

#@timer_func
def generate_build_configuration_files(target_os: str, target_config: str, target_link_config: str, target_cpu: str, regenerate : bool):
    if not util.bcs_third_party_dir:
        raise Exception("bcs_third_party_dir missing")
    if not util.bcs_7z_dir:
        raise Exception("bcs_7z_dir missing")
    if not util.bcs_ewdk_dir:
        raise Exception("bcs_ewdk_dir missing")
    
    gn_args_string = f'bcs_third_party_dir="{util.bcs_third_party_dir}" bcs_7z_dir="{util.bcs_7z_dir}" bcs_ewdk_dir="{util.bcs_ewdk_dir}" target_os="{target_os}" target_config="{target_config}" target_link_config="{target_link_config}" target_cpu="{target_cpu}"'
    gn_args_formatted = gn_args_string.replace('"', '"""')
    target_directory = os.path.join(util.bcs_root_dir, f'solution/{target_os}-{target_config}-{target_cpu}-{target_link_config}')

    gn = util.get_gn()
    ninja = util.get_ninja()
    args = [gn]
    if regenerate:
        args.append(f'--regeneration')
    args.append(f'--ninja-executable="{ninja}"')
    args.append(f'--args="{gn_args_formatted}"')
    args.append(f'gen')
    args.append(f'"{target_directory}"')
    command = " ".join(args)

    process = subprocess.run(command, shell=True, stdout=subprocess.PIPE)
    stdout = process.stdout
    if not process.returncode:
        pass
    else:
        print(f'Command failed {inspect.currentframe().f_code.co_name}:', command)
        sys.stdout.buffer.write(stdout)
        raise Exception(stdout.decode('utf-8'))
    
    patch_build_configuration_files(target_os, target_config, target_link_config, target_cpu)

#@timer_func
async def generate_build_configuration_files_async(target_os: str, target_config: str, target_link_config: str, target_cpu: str, regenerate : bool):
    if not util.bcs_third_party_dir:
        raise Exception("bcs_third_party_dir missing")
    if not util.bcs_7z_dir:
        raise Exception("bcs_7z_dir missing")
    if not util.bcs_ewdk_dir:
        raise Exception("bcs_ewdk_dir missing")
    
    command = None
    process = None
    try:
        gn_args_string = f'bcs_third_party_dir="{util.bcs_third_party_dir}" bcs_7z_dir="{util.bcs_7z_dir}" bcs_ewdk_dir="{util.bcs_ewdk_dir}" target_os="{target_os}" target_config="{target_config}" target_link_config="{target_link_config}" target_cpu="{target_cpu}"'
        gn_args_formatted = gn_args_string.replace('"', '"""')
        target_directory = os.path.join(util.bcs_root_dir, f'solution/{target_os}-{target_config}-{target_cpu}-{target_link_config}')
    
        gn = util.get_gn()
        ninja = util.get_ninja()
        args = [gn]
        if regenerate:
            args.append(f'--regeneration')
        args.append(f'--ninja-executable="{ninja}"')
        args.append(f'--args="{gn_args_formatted}"')
        args.append(f'gen')
        args.append(f'"{target_directory}"')
        command = " ".join(args)
    
        # Run the subprocess asynchronously and wait for the result
        process = await asyncio.create_subprocess_shell(command, stdout=asyncio.subprocess.PIPE)
        await process.wait()
        stdout = await process.stdout.read()
    
        if not process.returncode:
            pass
        else:
            print(f'Command failed {inspect.currentframe().f_code.co_name}:', command)
            sys.stdout.buffer.write(stdout)
            raise Exception(stdout.decode('utf-8'))
        
        patch_build_configuration_files(target_os, target_config, target_link_config, target_cpu)
    except Exception as e:
        print(f'Command failed {inspect.currentframe().f_code.co_name}:', command)
        raise e
    
    if process.returncode:
        print(f'Command failed {inspect.currentframe().f_code.co_name}:', command)
        sys.stdout.buffer.write(stdout)
        raise Exception(stdout.decode('utf-8'))


#@timer_func
def get_target_list(target_directory: str, userdata = None) -> list[Target]:
    gn = util.get_gn()
    command = f'{gn} ls \"{target_directory}\"'
    process = subprocess.run(command, shell=True, stdout=subprocess.PIPE)
    stdout = process.stdout.decode('utf-8')
    if not process.returncode:
        lines = stdout.strip().split('\n')
        
        targets = []

        all_target_created = False
        for line in lines:
            if line == "//:all_build":
                target = Target("*", userdata)
                all_target_created = True
            else:
                target = Target(line, userdata)
            targets.append(target)

        if len(lines) > 0 and not all_target_created:
            print("all_build not found. creating default.")
            target = Target("*", userdata)
            targets.insert(0, target)

        return targets
    else:
        print(f'Command failed {inspect.currentframe().f_code.co_name}:', command)
        raise Exception(stdout)

#@timer_func
async def get_target_list_async(target_directory: str, userdata = None) -> list[Target]:
    gn = util.get_gn()
    command = f'{gn} ls \"{target_directory}\"'
    
    # Run the subprocess asynchronously and wait for the result
    process = await asyncio.create_subprocess_shell(command, stdout=asyncio.subprocess.PIPE)
    await process.wait()
    stdout = await process.stdout.read()
    stdout = stdout.decode('utf-8')
    
    if process.returncode == 0:
        lines = stdout.strip().split('\n')
        targets = []

        all_target_created = False
        for line in lines:
            if line == "//:all_build":
                target = Target("*", userdata)
                all_target_created = True
            else:
                target = Target(line, userdata)
            targets.append(target)

        if len(lines) > 0 and not all_target_created:
            print("all_build not found. creating default.")
            target = Target("*", userdata)
            targets.insert(0, target)

        return targets
    else:
        print(f'Command failed {inspect.currentframe().f_code.co_name}:', command)
        raise Exception(stdout)

@timer_func
def get_descriptions(output_directory: str) -> dict:
    gn = util.get_gn()
    command = f'{gn} desc --format=json \"{output_directory}\" \"*\"'
    process = subprocess.run(command, shell=True, stdout=subprocess.PIPE)
    stdout = process.stdout.decode('utf-8')
    if not process.returncode:
        try:
            data = json.loads(stdout)
        except Exception as e:
            print(stdout)
            raise e
        return data
    print(f'Command failed {inspect.currentframe().f_code.co_name}:', command)
    raise Exception(stdout)

async def get_descriptions_async(output_directory: str) -> dict:
    gn = util.get_gn()
    command = f'{gn} desc --format=json \"{output_directory}\" \"*\"'
    process = None
    stdout = None
    try:
        process = await asyncio.create_subprocess_shell(command, stdout=asyncio.subprocess.PIPE)
        await process.wait()
        stdout = await process.stdout.read()
        stdout = stdout.decode('utf-8')
        if not process.returncode:
            try:
                data = json.loads(stdout)
            except Exception as e:
                print(stdout)
                raise e
            return data
    except Exception as e:
        print(f'Command failed {inspect.currentframe().f_code.co_name}:', command)
        raise e
    finally:
        if process.returncode:
            print(f'Command failed {inspect.currentframe().f_code.co_name}:', command)
            raise Exception(stdout)

@timer_func
def get_description(output_directory: str, target: Target) -> dict:
    gn = util.get_gn()
    command = f'{gn} desc --format=json \"{output_directory}\" \"{target.target}\"'
    process = subprocess.run(command, shell=True, stdout=subprocess.PIPE)
    stdout = process.stdout.decode('utf-8')
    if not process.returncode:
        try:
            data = json.loads(stdout)
        except Exception as e:
            print(stdout)
            raise e
        return data
    print(f'Command failed {inspect.currentframe().f_code.co_name}:', command)
    raise Exception(stdout) 
