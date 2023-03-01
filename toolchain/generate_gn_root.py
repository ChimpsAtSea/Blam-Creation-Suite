import os

with open(".gn", "w") as f:
    lines = []

    lines += ["# The location of the build configuration file."]
    lines += ["buildconfig = \"//toolchain/BUILDCONFIG.gn\""]
    lines += [f"script_executable = \"{os.getcwd()}/thirdparty/python-3.11.1/python.exe\""]

    f.writelines("\n".join(lines))
