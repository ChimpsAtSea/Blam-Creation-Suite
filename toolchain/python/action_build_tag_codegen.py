import os
import sys
sys.path.append(os.path.realpath(os.path.dirname(__file__))) # Allow Local Imports
import library_util as util
import subprocess
import shlex
from library_bcs import Engine
from library_bcs import Platform
from library_bcs import Build
from library_bcs import EnginePlatformBuild

inputs = util.command_line['inputs']
sources = util.command_line['sources']
outputs = util.command_line['outputs']
output = util.command_line['output']
target_gen_dir = util.command_line['target_gen_dir']
root_out_dir = util.command_line['root_out_dir']
root_gen_dir = util.command_line['root_gen_dir']
root_build_dir = util.command_line['root_build_dir']
engine_namespace = util.command_line['engine']
platform_namespace = util.command_line['platform']
build_namespace = util.command_line['build']

engine = Engine.get_by_namespace(engine_namespace)
platform = Platform.get_by_namespace(platform_namespace)
build = Build.try_get_by_namespace(build_namespace)
engineplatformbuild = EnginePlatformBuild(engine, platform, build)

tagcodegen = os.path.join(root_out_dir, "bin", "tagcodegentool.exe")

public_header = os.path.join(output, f'{engine_namespace}-{platform_namespace}-public-pch.h')
with open(public_header, 'w') as public_header_file:
    lines = []

    lines.append('#pragma once')
    lines.append('')
    lines.append(f'#include "{engine_namespace}-{platform_namespace}-enum.h"')
    lines.append(f'#include "{engine_namespace}-{platform_namespace}.h"')
    lines.append(f'#include "{engine_namespace}-{platform_namespace}-highlevel.h"')
    lines.append('')

    public_header_file.writelines('\n'.join(lines))

private_header = os.path.join(output, f'{engine_namespace}-{platform_namespace}-private-pch.h')
with open(private_header, 'w') as private_header_file:
    lines = []

    lines.append('#pragma once')
    lines.append('')
    lines.append('#include <platform/platform-public-pch.h>')
    lines.append('#include <templatelibrary/templatelibrary-public-pch.h>')
    lines.append('#include <shared/blam/blamlib-public-pch.h>')
    lines.append('#include <tagframework/tagframework-public-pch.h>')
    lines.append('#include <tagdefinitions/tagdefinitions-public-pch.h>')
    lines.append('#include <tagreflection/tagreflection-public-pch.h>')
    lines.append('')
    lines.append(f'#include <tagdefinitions/{engine_namespace}_{platform_namespace}_{build_namespace}/{engine_namespace}tagdefinitions-public-pch.h>')
    lines.append('')
    lines.append('#include <platform\platform-exports-pch.h>')
    lines.append('')
    lines.append(f'#include "{engine_namespace}-{platform_namespace}-public-pch.h"')
    lines.append('')

    private_header_file.writelines('\n'.join(lines))

command = [
    tagcodegen, 
    f'-type:all', 
    f'-engine:{engine_namespace}', 
    f'-platform:{platform_namespace}', 
    f'-build:{build_namespace}', 
    f'-globalindex:1', 
    f'-output:{output}']
process = subprocess.Popen(command)
process.wait()
