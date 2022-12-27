import os
import subprocess
import re
import ast

gn_path = "gn"


def pretty_print_dict(
        input_dictionary,
        indent=1,
        depth=0
):
    # Bool flag to add comma's after first item in dict.
    needs_comma = False
    # String for any dict will start with a '{'
    return_string = '\t' * depth + '{\n'
    # Iterate over keys and values, building the full string out.
    for key, value in input_dictionary.items():
        # Start with key. If key follows a previous item, add comma.
        if needs_comma:
            return_string = return_string + ',\n' + '\t' * (depth + 1) + str(key) + ': '
        else:
            return_string = return_string + '\t' * (depth + 1) + str(key) + ': '
        # If the value is a dict, recursively call function.
        if isinstance(value, dict):
            return_string = return_string + '\n' + pretty_print_dict(value, depth=depth+2)
        else:
            return_string = return_string + '\t' * indent + str(value).replace('\n', '\n' + '\t' * (depth + 1))
        # After first line, flip bool to True to make sure commas make it.
        needs_comma = True
    # Complete the dict with a '}'
    return_string = return_string + '\n' + '\t' * depth + '}'
    # Return dict string.
    return return_string

class Target:

    directory : str = None
    buildfile : str = None
    name : str = None
    target : str = None

    def __init__(self, target):
        # Split the string by the ':' character
        parts = target.split(':')

        self.directory = parts[0]

        # Get the buildfile and name by slicing the parts list
        self.buildfile = "/".join([self.directory, "BUILD.gn"])

        # Strip any leading or trailing whitespace from the name
        self.name = parts[1]
        self.name = self.name.strip()

        self.name = self.name

        self.target = target

    def __repr__(self):
        object = {
            "directory": self.directory,
            "buildfile": self.buildfile,
            "name": self.name,
            "target": self.target,
        }
        return pretty_print_dict(object)

def set_gn_path(path: str):
    global gn_path
    gn_path = path

def system_path(project_root : str, path : str):
    if path.startswith("//"):
        return os.path.join(project_root, path[2:])
    else:
        return path

def get_target_list(target_directory: str) -> list[Target]:
    global gn_path
    process = subprocess.run(f'{gn_path} ls \"{target_directory}\"', shell=True, stdout=subprocess.PIPE)
    stdout = process.stdout.decode('utf-8')
    lines = stdout.strip().split('\n')
    
    targets = []

    for line in lines:
        target = Target(line)
        targets.append(target)

    return targets

class Description:

    target : Target = None
    type : str = ""
    custom_target_type : str = ""
    toolchain : str = []
    visibility : str = "*"
    metadata : list[str] = {}
    testonly : bool = False
    check_includes : bool = True
    allow_circular_includes_from : list[str] = []
    sources : list[str] = []
    public : bool = True
    configs : list[str] = []
    outputs : list[str] = []
    cflags : list[str] = []
    cflags_c : list[str] = []
    cflags_cc : list[str] = []
    defines : list[str] = []
    include_dirs : list[str] = []
    ldflags : list[str] = []
    #Direct : str = None
    libs : list[str] = []
    lib_dirs : list[str] = []
    externs : list[str] = []

    def __init__(self, target, lines):
        target : str
        lines : list(str)

        # Initialize the object as a dictionary
        dictionary = {}
        
        # Iterate over the lines and parse the key-value pairs
        current_key = None
        lines_iterator = iter(lines)
        for line in lines_iterator:
            line : str
            if line.startswith(' '):
                # This line is a value for the current key
                dictionary[current_key].append(line.strip())
            else:
                if line.startswith('Target '):
                    parts = [ 'target', line.removeprefix('Target ') ]
                else:
                    # This line is a new key
                    parts = line.split(':')
                key = parts[0].strip()
                if key == 'metadata':
                    metadata_lines = []
                    line = next(lines_iterator)
                    metadata_lines.append(line)
                    line = next(lines_iterator)
                    if not len(line.strip()):
                        value = {}
                        line = next(lines_iterator)
                    else:
                        while len(line.strip()):
                            metadata_lines.append(line)
                            line = next(lines_iterator)
                        metadata_string = '\n'.join(metadata_lines)
                        metadata_quoted = re.sub(r'(\s*)(\w+)(\s*=)', r'\1"\2"\3', metadata_string)
                        metadata_python = metadata_quoted.replace('\" = ', "\": ")
                        #print(metadata_lines)
                        #print(metadata_string)
                        #print(metadata_quoted)
                        #print(metadata_python)
                        metadata = ast.literal_eval(metadata_python)
                        #print(metadata)
                        value = metadata

                elif len(key):
                    key = key.split().pop(0)
                    value = parts[1].strip() if len(parts) > 1 else []
                dictionary[key] = value
                current_key = key

        target = target
        type = dictionary['type']
        toolchain = dictionary['toolchain']

        self.target = target
        self.type = type
        self.custom_target_type = type
        self.toolchain = toolchain

        visibility_lines = dictionary['visibility']
        if len(visibility_lines):
            self.visibility = visibility_lines.pop(0)

        metadata = dictionary['metadata']
        if len(metadata_lines):
            self.metadata = metadata

            if 'custom_target_type' in metadata:
                self.custom_target_type = metadata['custom_target_type'].pop(0)

        testonly_lines = dictionary['testonly']
        if len(testonly_lines):
            self.testonly = testonly_lines.pop(0) == 'true'

        check_includes_lines = dictionary['check_includes']
        if len(check_includes_lines):
            self.check_includes = check_includes_lines.pop(0) == 'true'
        
        allow_circular_includes_from_lines = dictionary['allow_circular_includes_from']
        if len(allow_circular_includes_from_lines):
            self.allow_circular_includes_from = allow_circular_includes_from_lines.pop(0)

        if 'sources' in dictionary:
            sources_lines = dictionary['sources']
            if len(sources_lines):
                self.sources = sources_lines

        public_lines = dictionary['public']
        if len(public_lines):
            self.public = public_lines.pop(0) == '[All headers listed in the sources are public.]'

        configs_lines = dictionary['configs']
        if len(configs_lines):
            self.configs = configs_lines

        if 'outputs' in dictionary:
            outputs_lines = dictionary['outputs']
            if len(outputs_lines):
                self.outputs = outputs_lines

        cflags_lines = dictionary['cflags']
        if len(cflags_lines):
            self.cflags = cflags_lines

        cflags_c_lines = dictionary['cflags_c']
        if len(cflags_c_lines):
            self.cflags_c = cflags_c_lines

        cflags_cc_lines = dictionary['cflags_cc']
        if len(cflags_cc_lines):
            self.cflags_cc = cflags_cc_lines

        defines_lines = dictionary['defines']
        if len(defines_lines):
            self.defines = defines_lines

        include_dirs_lines = dictionary['include_dirs']
        if len(include_dirs_lines):
            self.include_dirs = include_dirs_lines

        if 'ldflags' in dictionary:
            ldflags_lines = dictionary['ldflags']
            if len(ldflags_lines):
                self.ldflags = ldflags_lines

        #Direct_lines = dictionary['Direct']
        #if len(Direct_lines):
        #    self.Direct = Direct_lines.pop(0)

        if 'libs' in dictionary:
            libs_lines = dictionary['libs']
            if len(libs_lines):
                self.libs = libs_lines

        if 'lib_dirs' in dictionary:
            lib_dirs_lines = dictionary['lib_dirs']
            if len(lib_dirs_lines):
                self.lib_dirs = lib_dirs_lines

        externs_lines = dictionary['externs']
        if len(externs_lines):
            self.externs = externs_lines

    def __repr__(self):
        object = {
            'target': self.target,
            'type': self.type,
            'custom_target_type': self.custom_target_type,
            'toolchain': self.toolchain,
            'visibility': self.visibility,
            'metadata': self.metadata,
            'testonly': self.testonly,
            'check_includes': self.check_includes,
            'allow_circular_includes_from': self.allow_circular_includes_from,
            'sources': self.sources,
            'public': self.public,
            'configs': self.configs,
            'outputs': self.outputs,
            'cflags': self.cflags,
            'cflags_c': self.cflags_c,
            'cflags_cc': self.cflags_cc,
            'defines': self.defines,
            'include_dirs': self.include_dirs,
            'ldflags': self.ldflags,
            #'Direct': self.Direct,
            'libs': self.libs,
            'lib_dirs': self.lib_dirs,
            'externs': self.externs,
        }
        return pretty_print_dict(object)

def get_description(output_directory: str, target: Target) -> Description:
    global gn_path
    process = subprocess.run(f'{gn_path} desc \"{output_directory}\" \"{target.target}\"', shell=True, stdout=subprocess.PIPE)
    stdout = process.stdout.decode('utf-8')
    #print(stdout)
    lines = stdout.strip().split('\n')
    
    target = Description(target, lines)
    return target
