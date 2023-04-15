import os
import sys
import time
import asyncio
import platform
import fnmatch
from typing import Union

command_line = {
    #Environment Round Trip
    #TODO: Investigate nuking as many of these as possible
    'bcs_root_dir': str(),
    'bcs_third_party_dir': str(),
    'bcs_toolchain_dir': str(),
    'bcs_llvm_dir': str(),
    'bcs_llvm_bin_dir': str(),
    'bcs_llvm_src_dir': str(),
    'bcs_gn_dir': str(),
    'bcs_ninja_dir': str(),
    'bcs_python_dir': str(),
    'bcs_cmake_dir': str(),
    'bcs_ewdk_dir': str(),
    'bcs_7z_dir': str(),
    'bcs_yasm_dir': str(),
    'bcs_download_cache_dir': str(),
    'bcs_winpix3_dir': str(),

    'build-gn': bool(),

    #BCS Platform Targets
    'windows': platform.system() == 'Windows',
    'linux': platform.system() == 'Linux',
    'webassembly': bool(),
    'all': bool(),
    'profile': bool(),

    #GN Round Trip Variables
    'target_os': str(),
    'target_config': str(),
    'target_link_config': str(),
    'target_cpu': str(),

    #GN Variables
    'target_gen_dir': str(),
    'target_out_dir': str(),
    'root_gen_dir': str(),
    'root_build_dir': str(),
    'root_out_dir': str(),
    'target_src_dir': str(),

    #DXC Variables
    'dxc_passthrough': str(),

    #Engine Platform Build
    'engine': str(),
    'platform': str(),
    'build': str(),

    #Commandlet Variables
    'default': list[str](),
    'inputs': list[str](),
    'outputs': list[str](),
    'output': str(),
    'target': str(),
    'sources': list[str](),
    'output-subdirectory': str()
}

arguments = sys.argv[1:]
key = None
for i, arg in enumerate(arguments):
    if arg.startswith('--'):
        key = arg[2:]
        if key in command_line:
            assignment_types = [ list, str ]
            if type(command_line[key]) == bool:
                command_line[key] = True
            elif type(command_line[key]) in assignment_types:
                pass
            else:
                raise Exception(f'Unhandled key type', type(command_line[key]))
        else:
            raise Exception(f'Unknown command line option {arg}')
    elif key is not None:
        if type(command_line[key]) == list:
            command_line[key].append(arg)
        elif type(command_line[key]) == str:
            command_line[key] = arg
            key = None
        else:
            raise Exception(f'Unknown command line option {key} = {arg}', type(command_line[key]))
    elif 'default' in command_line:
        command_line['default'].append(arg)

def get_environment(variable : str):
    if variable in os.environ:
        return os.environ[variable]
    if variable in command_line:
        return command_line[variable]
    return ''

bcs_root_dir = get_environment('bcs_root_dir')
bcs_third_party_dir = get_environment('bcs_third_party_dir')
bcs_toolchain_dir = get_environment('bcs_toolchain_dir')
bcs_llvm_dir = get_environment('bcs_llvm_dir')
bcs_llvm_bin_dir = get_environment('bcs_llvm_bin_dir')
bcs_llvm_src_dir = get_environment('bcs_llvm_src_dir')
bcs_gn_dir = get_environment('bcs_gn_dir')
bcs_ninja_dir = get_environment('bcs_ninja_dir')
bcs_python_dir = get_environment('bcs_python_dir')
bcs_ewdk_dir = get_environment('bcs_ewdk_dir')
bcs_msys2_dir = get_environment('bcs_msys2_dir')
bcs_cmake_dir = get_environment('bcs_cmake_dir')
bcs_7z_dir = get_environment('bcs_7z_dir')
bcs_yasm_dir = get_environment('bcs_yasm_dir')
bcs_download_cache_dir = get_environment('bcs_download_cache_dir')
bcs_winpix3_dir = get_environment('bcs_winpix3_dir')

target_os = get_environment('target_os')
target_config = get_environment('target_config')
target_link_config = get_environment('target_link_config')
target_cpu = get_environment('target_cpu')

target_src_dir = get_environment('target_src_dir')
target_gen_dir = get_environment('target_gen_dir')
target_out_dir = get_environment('target_out_dir')
root_out_dir = get_environment('root_out_dir')
root_gen_dir = get_environment('root_gen_dir')
root_build_dir = get_environment('root_build_dir')

bcs_is_host_windows = platform.system() == 'Windows'
bcs_is_host_linux = platform.system() == 'Linux'

build_all = command_line['all']
build_windows = build_all or command_line['windows']
build_linux = build_all or command_line['linux']
build_webassembly = build_all or command_line['webassembly']
build_profile = command_line['profile']

inputs = command_line['inputs']
sources = command_line['sources']
outputs = command_line['outputs']
output_subdirectory = command_line['output-subdirectory']

bcs_executable_suffix = ''
if bcs_is_host_windows:
    bcs_executable_suffix = '.exe'
elif platform.system() == 'Linux':
    bcs_executable_suffix = ''
else:
    print('Unknown operating system')

def get_gn():
    if not bcs_gn_dir:
        raise Exception('bcs_gn_dir not set')
    return os.path.join(bcs_gn_dir, f'gn{bcs_executable_suffix}')

def get_ninja():
    if not bcs_ninja_dir:
        raise Exception('bcs_ninja_dir not set')
    return os.path.join(bcs_ninja_dir, f'ninja{bcs_executable_suffix}')

def get_python():
    if not bcs_python_dir:
        raise Exception('bcs_python_dir not set')
    return os.path.join(bcs_python_dir, f'python{bcs_executable_suffix}')

def get_cmake():
    if not bcs_cmake_dir:
        raise Exception('bcs_cmake_dir not set')
    return os.path.join(bcs_cmake_dir, f'cmake{bcs_executable_suffix}')

def get_7z():
    if not bcs_7z_dir:
        raise Exception('bcs_7z_dir not set')
    return os.path.join(bcs_7z_dir, f'7z{bcs_executable_suffix}')


#print('target_gen_dir', target_gen_dir)
#print('target_out_dir', target_out_dir)
#print('root_gen_dir', root_gen_dir)
#print('root_build_dir', root_build_dir)

#print('bcs_root_dir', bcs_root_dir)
#print('bcs_third_party_dir', bcs_third_party_dir)
#print('bcs_gn_dir', bcs_gn_dir)
#print('bcs_ninja_dir', bcs_ninja_dir)
#print('bcs_python_dir', bcs_python_dir)
#print('bcs_ewdk_dir', bcs_ewdk_dir)
#print('bcs_msys2_dir', bcs_msys2_dir)
#print('bcs_cmake_dir', bcs_cmake_dir)
#print('bcs_7z_dir', bcs_7z_dir)

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

def timer_func(func):
    def function_timer(*args, **kwargs):
        start = time.time()
        value = func(*args, **kwargs)
        end = time.time()
        runtime = end - start
        msg = '{func} {time}ms'
        print(msg.format(func = func.__name__,time = runtime * 1000))
        return value
    return function_timer

def execute_async_task(function, result_count = 0):
    loop = asyncio.get_event_loop()
    if result_count:
        result_wrapper = []
        for index in range(result_count):
            result_wrapper.append(None)
        loop.run_until_complete(function(result_wrapper))
        return result_wrapper
    else:
        loop.run_until_complete(function())

def async_start():
    loop = asyncio.new_event_loop()
    asyncio.set_event_loop(loop)

def async_end():
    loop = asyncio.get_event_loop()
    try:
        loop.run_until_complete(loop.shutdown_asyncgens())
    finally:
        loop.close()

def write_file_if_changed(file_path, lines):
    new_content = '\n'.join(lines)
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

def filesystem_get_files_recursive(dir_path : str, file_types : list[str] = []) -> list[str]:
    files = []
    #if not os.path.isabs(dir_path):
    #    dir_path = os.path.abspath(dir_path)
    if file_types:
        for root, dirnames, filenames in os.walk(dir_path):
            for file_type in file_types:
                for filename in fnmatch.filter(filenames, file_type):
                    files.append(os.path.join(root, filename))
    else:
        for root, dirnames, filenames in os.walk(dir_path):
            for filename in filenames:
                files.append(os.path.join(root, filename))

    return files

def filesystem_rebase(paths : Union[str, list[str]], base : str):
    if isinstance(paths, str):
        return os.path.relpath(paths, base)
    else:
        rel_paths = []
        for path in paths:
            rel_paths.append(os.path.relpath(path, base))
        return rel_paths

def filesystem_rebase_root(paths : Union[str, list[str]]):
    return filesystem_rebase(paths, bcs_root_dir)
