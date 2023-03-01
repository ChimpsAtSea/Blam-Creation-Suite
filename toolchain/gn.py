import os
import subprocess
import json
from util import pretty_print_dict

bcs_root_dir = os.environ['BCS_ROOT']
env_gn_dir = os.environ['GN_DIR']
gn_path = os.path.join(env_gn_dir, "gn")
env_ninja_dir = os.environ['NINJA_DIR']
ninja_path = os.path.join(env_ninja_dir, "ninja")

class Target:
    directory : str = None
    buildfile : str = None
    name : str = None
    target : str = None
    userdata = None

    def __init__(self, target, userdata):
        self.userdata = userdata
        self.target = target

        if target == "*":
            self.directory = "//"
            self.name = "all_build"
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
    custom_target_type : str = ""
    userdata = None
    project_folder : list[str] = []

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


        if len(data):
            print("WARN: GN Description contains unparsed data")
            print(data)

        if 'custom_target_type' in self.metadata:
            custom_target_type_metadata_list = self.metadata['custom_target_type']
            if len(custom_target_type_metadata_list) == 1:
                self.custom_target_type = custom_target_type_metadata_list[0]
        else:
            self.custom_target_type = self.type

        if 'project_folder' in self.metadata:
            project_folder_metadata_list = self.metadata['project_folder']
            if len(project_folder_metadata_list) == 1:
                self.project_folder = list(filter(None, project_folder_metadata_list[0].split("/")))
        else:
            self.project_folder = list(filter(None, self.target.directory.split("/")))

    def __repr__(self):
        return pretty_print_dict(self.__dict__)

def system_path(project_root : str, path : str):
    if path.startswith("//"):
        return os.path.join(project_root, path[2:])
    else:
        return path

def get_target_list(target_directory: str, userdata = None) -> list[Target]:
    global gn_path
    command = f'{gn_path} ls \"{target_directory}\"'
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
        print(command)
        print(stdout)
        raise("get_target_list failed")

def get_description(output_directory: str, target: Target, userdata = None) -> Description:
    global gn_path

    command = f'{gn_path} desc --format=json \"{output_directory}\" \"{target.target}\"'
    process = subprocess.run(command, shell=True, stdout=subprocess.PIPE)
    if not process.returncode:
        if target.target == "*":
            description = Description(target, {}, userdata)
            return description
        else:
            stdout = process.stdout.decode('utf-8')
            data = json.loads(stdout)
            description = Description(target, data[target.target], userdata)
            return description
    raise Exception("Unsupported target", target.name) 
