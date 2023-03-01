import sys

command_line = {
    "outputs": str(),
    "sources": str(),
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

with open("output.txt", "w") as f:
    f.write(str(command_line))
