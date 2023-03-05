import os
import sys
import time
import asyncio

command_line = {
    "BCS_ROOT": str(),
    "BCS_THIRD_PARTY": str(),
    "GN_DIR": str(),
    "NINJA_DIR": str(),
    "PYTHON_DIR": str(),
    "EWDK_DIR": str(),
    "target_os": str(),
    "target_config": str(),
    "target_link_config": str(),
    "target_cpu": str(),
    "default": list[str]()
}

arguments = sys.argv[1:]
key = None
for i, arg in enumerate(arguments):
    if arg.startswith("--"):
        key = arg[2:]
        if key in command_line:
            assignment_types = [ list[str], str ]
            if type(command_line[key]) == bool:
                command_line[key] = True
            elif type(command_line[key]) in assignment_types:
                pass
            else:
                raise Exception(f"Unhandled key type", type(command_line[key]))
        else:
            raise Exception(f"Unknown command line option {arg}")
    elif key is not None:
        if type(command_line[key]) == list[str]:
            command_line[key].append(arg)
        if type(command_line[key]) == str:
            command_line[key] = arg
            key = None
        else:
            raise Exception(f"Unknown command line option {key} = {arg}", type(command_line[key]))
    elif "default" in command_line:
        command_line["default"].append(arg)

def get_environment(variable : str):
    if variable in os.environ:
        return os.environ[variable]
    if variable in command_line:
        return command_line[variable]

bcs_root_dir = get_environment('BCS_ROOT')
bcs_third_party_dir = get_environment('BCS_THIRD_PARTY')
env_gn_dir = get_environment('GN_DIR')
gn_path = os.path.join(env_gn_dir, "gn")
env_ninja_dir = get_environment('NINJA_DIR')
ninja_path = os.path.join(env_ninja_dir, "ninja")
env_python_dir = get_environment('PYTHON_DIR')
python_path = os.path.join(env_python_dir, "python")
ewdk_dir = get_environment('EWDK_DIR')
msys2_dir = get_environment('MSYS2_DIR')


#print("bcs_root_dir", bcs_root_dir)
#print("bcs_third_party_dir", bcs_third_party_dir)
#print("env_gn_dir", env_gn_dir)
#print("gn_path", gn_path)
#print("env_ninja_dir", env_ninja_dir)
#print("ninja_path", ninja_path)
#print("env_python_dir", env_python_dir)
#print("python_path", python_path)

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
        msg = "{func} took {time} ms to complete its execution."
        print(msg.format(func = func.__name__,time = runtime * 1000))
        return value
    return function_timer

def timer_func_async(func):
    async def function_timer(*args, **kwargs):
        start = time.time()
        value = await func(*args, **kwargs)
        end = time.time()
        runtime = end - start
        msg = "{func} took {time} ms to complete its execution."
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
    